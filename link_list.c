

// The following will be accepted as input in the following format: "title:author:price"
// Example Input:	"ProgrammingLanguages:Chen:45"
// Valid title:		String containing alphabetical letters beginning with a capital letter
// Valid author:	String containing alphabetical letters beginning with a capital letter
// Valid price:		A float variable

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#pragma warning(disable: 4996)

// used to create a linked list of containers, each contaning a "book"
struct container {
	struct book *book;
	struct container *next;
}*list=NULL;

// used to hold book information and linked list of "frequently bought together (fbt)"
struct book {
	char title[30];
	char author[30];
	float price;
	struct fbt *fbts;
};

// used to create a linked list of frequently bought together (fbt)
struct fbt {
	struct book *book;
	struct fbt *next;
};


// forward declaration of functions that have already been implemented
void flush();
void branching(char);
void registration(char);


// the following forward declarations are for functions that require implementation
// return type		// name and parameters				
void        	add_book(char*, char*,float);		
struct book*		search_book(char*);					
void				remove_book(char*);					
void	            print_all_books();					

struct container *	buy_book();							
struct container *  setfbt(struct container *);			
void 				display_fbt(struct container*);			

int main()
{
	char ch = 'i';
	printf("Book Information\n\n");

	do
	{
		printf("\n\nPlease enter your selection:\n");
		printf("\ta: add a new book to the list\n");
		printf("\ts: search for a book on the list\n");
		printf("\tr: remove a book from the list\n");
		printf("\tl: print the list of all books\n");
		printf("\tb: buy a book\n");
		printf("\tq: quit\n");
		ch = tolower(getchar());
		flush();
		branching(ch);
	} while (ch != 'q');

	return 0;
}

// consume leftover '\n' characters
void flush()
{
	int c;
	do c = getchar(); while (c != '\n' && c != EOF);
}

// branch to different tasks
void branching(char c)
{

	switch (c)
	{
	case 'a':
	case 's':
	case 'r':
	case 'l':registration(c); break;
	case 'b':{
	    struct container * buy = buy_book();
	    buy = setfbt(buy);
	    display_fbt(buy);
	    break;
	}
	case 'q': break;
	default: printf("Invalid input!\n");
	}
}
//
// This function will determine what info is needed and which function to send that info to.
// It uses values that are returned from some functions to produce the correct ouput.
// There is no implementation needed here, but you should trace the code and know how it works.
// It is always helpful to understand how the code works before implementing new features.

void registration(char c)
{
	if (c == 'a')
	{
		char input[100];
		char *title1,*author1;
		float price1;

		printf("\nPlease enter the book's info in the following format:\n");
		printf("title:author:price\n");
		fgets(input, sizeof(input), stdin);

		// discard '\n' chars attached to input
		input[strlen(input) - 1] = '\0';

		char* title = strtok(input, ":"); // strtok used to parse string
		char * author = strtok(NULL, ":");
		float price = atof(strtok(NULL, ":"));
		
		
		struct book* result = search_book(title);
		
		if (result == NULL)
		{
			add_book(title, author, price);
			printf("\nBook added to list successfully\n\n");
		}
		else
			printf("\nThat book is already on the list\n\n");
	}
	else if (c == 's' || c == 'r' )
	{
		char title[30];

		printf("\nPlease enter the book's title:\n");
		fgets(title, sizeof(title), stdin);

		// discard '\n' chars attached to input
		title[strlen(title) - 1] = '\0';

		struct book* result = search_book(title);

		if (result == NULL)
			printf("\nThat book is not on the list\n\n");
		else if (c == 's'){
			printf("Title: %s\n", result->title);
			printf("Author: %s\n", result->author);
			printf("Price: %.2f\n\n", result->price);
		}
		else
		{
			remove_book(title);
			print_all_books();
			printf("\nBook removed from the list\n\n");
		}
	}
	else 
	{
		print_all_books();
	}
}

// This function should add book to the head of the list of containers.
// The function search_book() is called before calling this function,
// therefore you can assume that the book is not already on the list.
void add_book(char* title, char* author, float price)
{
    struct container *new_container= NULL;    // Intilization of new pointer variable for container
    struct book *new_book= NULL;               // Intilization of new pointer variable for book  
    
    new_container= (struct container *) malloc(sizeof(struct container)); // allocation of memory for container
    new_book= (struct book *) malloc(sizeof(struct book)); // allocation of memory for book
    
    strcpy(new_book->title,title);             //Assigning the contents to all the fields including title, author and price
    strcpy(new_book->author,author);
    new_book->price= price;
    new_book->fbts= NULL;
    
    new_container->book= new_book;          // Assigning new container to new book
    new_container->next= list;              // Adding this new container to top of the list
    list= new_container;
}

// In this function, you are passed the title of a book to find.
// If the book exists on the list, return a pointer to the requested book. If not, return NULL.
// (You must return a pointer to a node in your list.)

struct book* search_book(char* title)
{
    struct container *head= list;       //Creation of duplicate pointer and assigning it to the top of the list
    
    if(head == NULL)
    {
        return NULL;
    }
    else
    {
        while(head != NULL)            //Iterating through list and checking whthr title is same given title, if title is same it returns the book address
        {
            if(strcmp(head->book->title,title) == 0)
                return head->book;
            head= head->next;
        }
    }
}


// In this function, you are passed the title of a book to remove the corresponding book from the list.
// The search function is called before this function so you can assume that the book is on the list.
// You will need to find the book and remove it using proper memory management to ensure no memory leaks.
void remove_book(char* title)
{
    struct container *head= list;
    struct container *prev= NULL;
    if(head == NULL)
        printf("\n There are no books in the list");
    else
    {
        printf("\n The list of books as follows: ");
        while(head != NULL)
        {
            if(strcmp(head->book->title,title) == 0)
            {
                prev->next= head->next;
            }
            prev= head;
            head= head->next;
        }
    }
}

// In this function, you should print the list of available books in the list. 
//If there is no book in the list, you should print "There are no books on this list!"

void print_all_books()
{
    struct container *head= list;
                                
    if(head == NULL)                               //Checking given list is empty or not
        printf("\n There are no books on this list. \n");
    else
        while(head != NULL)                     //Termination condition. Loop will be running till it finds head == NULL. Loop is mainly used for printing
        {
            printf("Book Title: %s \n",head->book->title);
            printf("Book Author: %s \n",head->book->author);
            printf("Book Price: %.2f \n",head->book->price);
            printf("\n\n");
            head= head->next;
        }

}

// In this function, you should return the linked list of books that the user wants to buy. 
// The user should be able to buy as many books as he/she wants until 'n' is pressed.
// The user can buy a book using its title.
// The book that the user is going to buy should be on the main linked list. 

struct container * buy_book()
{
    char ch='i';
    char title[30];
    struct book* result= NULL;
    struct container* book_bought= NULL;
    do
    {
        printf("\n Do you want to buy a book? (y for Yes and n for No): ");
        ch= tolower(getchar());
        flush();
        switch(ch)
        {
            case 'y':{ 
                        printf("\nPlease enter book's title: ");
                        fgets(title, sizeof(title), stdin);
                        title[strlen(title) - 1] = '\0';
                        result= search_book(title);
                        if(result != NULL)
                        {
                            struct container* ptr= (struct container *) malloc(sizeof(struct container));
                            ptr->book= result;
                            ptr->next= book_bought;
                            book_bought= ptr;
                        }
                        else
                            printf("\n No such book is present in the list\n");
                        break;
                    }
            case 'n':break;
            default:printf("\n Invalid Input\n");
                    break;
    }
}while(ch != 'n');
 return book_bought;

}

// When a user buys a book, the frequently bought togther(fbt) linked list should be updated for each book.
// The update in fbt list should be done for each book in the buying list. 
// For simplicity, you do not consider the number of times the books are bought. 

struct container *  setfbt (struct container * in)
{
    struct container *header=in;
    while(header != NULL)
    {
        struct container *prev=in;
        while(prev != NULL)
        {
            if(strcmp(header->book->title,prev->book->title) != 0)
            {
                struct fbt *ptr= (struct fbt*) malloc(sizeof(struct fbt));
                ptr->book= prev->book;
                ptr->next= header->book->fbts;
                header->book->fbts= ptr; 
            }
            prev= prev->next;
        }
        header= header->next;
    }
    return in;
}

// This function prints the list of books for a given container.
// It should both print the details of each book and the fbt for that book.  
// This function is used to print the book list in the buy option. 

void display_fbt(struct container* books)
{
    struct container *head= books;
    if(head == NULL)
        printf("\n There are no books in the list\n");
    else
        while(head != NULL)
        {
            printf("Book Title: %s \n",head->book->title);
            printf("Book Author: %s \n",head->book->author);
            printf("Book Price: %f \n",head->book->price);
            struct fbt *temp= head->book->fbts;
            printf("\n Frequently Bought together book: \n"); 
            while(temp != NULL)
            {
                printf("\n Book Title: %s \n",temp->book->title);
                printf("Book Author: %s \n",temp->book->author);
                printf("Book Price: %.2f\n",temp->book->price);
                temp= temp->next;
            }
            printf("\n");
            head= head->next;
        }
}
