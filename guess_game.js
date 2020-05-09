//  Guessing a word game
var common_words = ["Jurassic Park", "Limitations", "Spiderman", "Batman", "Antman", "Mission Mangal", "Kites", "Dangal"]

//Function to select a random word from the given array of words
var grabRandomWord = function(array) {
    return array[Math.floor(Math.random() * array.length)];
}

var readline = require('readline');
var log = console.log;
var word = grabRandomWord(common_words);
var flag = 0;
const gussed_word = [];
var success = 0;
var word_array = [];

// This function is being used for converting the string to an array
var convert_word_to_array = function() {
    for (i = 0; i < word.length; i++) {

        word_array[i] = word[i];

    }
}

// This function is being used for intilizing guessed string and array as well counts number of letters in the string excluding the white space.
var convert_string_to_array = function() {
    for (i = 0; i < word.length; i++) {
        if (word[i] == " ")
            gussed_word[i] = ' ';
        else {
            success = success + 1;
            gussed_word[i] = '-';
        }
    }
}
// Intilizing the gussed_word array with equal amount of dashes for letters in the given word even space is considered as dash.

convert_string_to_array();
convert_word_to_array();

// Intilizing an interface for reading a line from the console.
var rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});


//This a function that converts an array of character into a string without commas.The function returns a string.
var convert_array_to_string = function() {
    var r_string = "";
    for (i = 0; i < gussed_word.length; i++)
        r_string += gussed_word[i];
    return r_string;
}

// The string which stores hint for startiing the game.
var start_hint = convert_array_to_string();
log("\n *****************Guess the word letter by letter***************************");
log("\n", start_hint);

// Function guess_game is being called recursly multiple times till the user does a write guessing
var guess_game = function() {
    rl.question('\n ? Guess a letter: ', function(answer) {
        if (word_array.indexOf(answer.toLowerCase()) > -1) {
            success = success - 1; // Remaining number of letters to guess

            gussed_word[word_array.indexOf(answer.toLowerCase())] = answer[0];
            word_array[word_array.indexOf(answer.toLowerCase())] = '-';

            var success_guess = convert_array_to_string();
            if (word.toLowerCase() === success_guess.toLowerCase())
                flag = 1;

            log("\n", ' \x1b[32m', ' Correct !!', "\x1b[0m");
            log(success_guess.toLowerCase());
        } else if (word_array.indexOf(answer.toUpperCase()) > -1) {
            success = success - 1; // Remaining number of letters to guess

            gussed_word[word_array.indexOf(answer.toUpperCase())] = answer[0];
            word_array[word_array.indexOf(answer.toUpperCase())] = '-';

            var success_guess = convert_array_to_string();
            if (word.toUpperCase() === success_guess.toUpperCase())
                flag = 1;

            log("\n", ' \x1b[32m', ' Correct !!', "\x1b[0m");
            log(success_guess.toLowerCase());
        } else {
            log("\n", "\x1b[31m", "Incorrect !!", "\x1b[0m");
            log("\n ", "\x1b[31m", success + " Guess remaining.,..", "\x1b[0m");
        }

        if (flag == 0)
            guess_game(); //Calling this function again to ask for a new guess.
        else
            return rl.close();
    });
};

guess_game(); //we have to actually start our recursion somehow
