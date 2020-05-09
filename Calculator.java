/***    
								Project-3 Calculator
This is a simple program that simulate the functions of a simple calculator 

Assumptions

 1. "+/-" button is present in calculator is being used simply for interchanging the sign of the value.(This is what i understood from the given document).

*/

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.script.ScriptEngineManager;
import javax.script.ScriptEngine;
import javax.script.ScriptException;
import javax.swing.*;

// Class that has main function. The main function calls calculatorFrame func and set its frame visible
public class Calculator {
	public static void main(String[] args)
	{
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				CalculatorFrame f= new CalculatorFrame();
				f.setVisible(true);
			}	
		}
		);
	}
}

/** This particular class extends the JFrame
*   This class has got a constructor which specifies the frame of the calculator. Calculator is not resizable and it is set to false
*/
class CalculatorFrame extends JFrame
{
	CalculatorFrame()
	{
	  super();
	  setTitle("Calculator");
	  setSize(300,200);
	  setResizable(false);
	  setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	  CalculatorPanel p= new CalculatorPanel();
	  add(p);
	}	
}

/*** Calculator panel class extends the Jpanel and specifies the panel dimensions and buttons in the calculator.
* This class has another class which implements the action performed by each button which is present in the calculator.
*/
class CalculatorPanel extends JPanel implements ActionListener
{
	private JButton [] b;
	private JTextField display;
	int flag= 0;
	public CalculatorPanel()
	{
		setLayout(new BorderLayout(2,2));
		display= new JTextField();
		add(display,BorderLayout.NORTH);
		JPanel bpanel= new JPanel();
		bpanel.setLayout(new GridLayout(5, 4, 5, 5));
		display.setBackground(Color.WHITE);
		
		b= new JButton[20];
		String []k={"1","2","3","4","5","6","7","8","9","0","+","-","/","*","+/-","C","=","."};
		for( int i= 0;i < k.length;i++)
		{   
			b[i]= new JButton(k[i]);
			b[i].setPreferredSize(new Dimension(20, 20));
			b[i].setBackground(Color.WHITE);
			b[i].setForeground(Color.BLACK);
			b[i].setActionCommand(k[i]);
			b[i].addActionListener(new ButtonAction());
		    	bpanel.add(b[i]);
		}
		add(bpanel,BorderLayout.CENTER);

	}

	public void actionPerformed(ActionEvent e) 
	{
		String x= e.getActionCommand();
		display.setText(display.getText() +x);
	}
	String temp,operator,opr;
	class ButtonAction implements ActionListener
	{
	
		public void actionPerformed(ActionEvent e)
		{
		  temp= e.getActionCommand();
		  if(temp == "+" || temp == "-" || temp == "*" || temp == "/")
		  {
			operator= temp;
			opr= display.getText();
			display.setText(display.getText()+temp);
			flag= 0;
                  }  
		  else if(temp == "0" || temp == "1" || temp == "2" || temp == "3" || temp == "4" || temp == "5" || temp == "6" || temp == "7" || temp == "8" || temp == "9" ){
			if(flag == 1)
			{
				display.setText("");
				flag= 0;
			}			 
			display.setText(display.getText()+temp);
		  }
		  else if(temp == "=" )
		  {  
			 flag= 1;
			 opr= display.getText();
			 ScriptEngineManager mgr = new ScriptEngineManager();
    			 ScriptEngine engine = mgr.getEngineByName("JavaScript");
			 try
			 {
			 	display.setText(String.valueOf(engine.eval(opr)));
			 }
		         catch (Exception ex)
			 {
				System.out.println(ex);
                                display.setText("Error");
			 }
			
		 }
		 else if(temp == "C")
		 {
			 display.setText("");
		 }
		 else if(temp == ".")
		 {
			 display.setText(display.getText()+temp);
		 }
		 else if(temp == "+/-")
		 {
			 String d;
			 opr= display.getText();
			 ScriptEngineManager mgr = new ScriptEngineManager();
    			 ScriptEngine engine = mgr.getEngineByName("JavaScript");
			 try
			 {
			   d= String.valueOf(engine.eval(opr));
                           float check_val= Float.parseFloat(d);
			   check_val = (-1) * (check_val);
 			   System.out.println(check_val);
			   d= String.valueOf(check_val);
			   display.setText(d);
			}
			catch (Exception ex)
			{
				System.out.println(ex);
				display.setText("Error");

			}
		 }
	}
		
		
	}
  

}
