/* This is the console executable, that makes use of the BullCow class
This acts as the view in an MVC patter,
and is responsible for all user interaction.
For game logic see the FBullCowGame class.
*/

#pragma once

#include <iostream>
#include <string>
#include "Header.h"
#include "fBullCowGame.h"
#include "fHiddenWords.h"


// to make syntax Unreal friendly
using FText = std::string;
using int32 = int;


void printIntro() {

	std::cout << "\n\nWelcome to Bulls and Cows, a fun wordgame\n";
	std::cout << std::endl;
	std::cout << "           }   {                    ____   " << std::endl;
	std::cout << "           (o  o)                  (o  O) " << std::endl;
	std::cout << "   /--------\\ /                     \\ /------------\\ " << std::endl;
	std::cout << "  / | BULL  |O                       O|  COW      | \\ " << std::endl;
	std::cout << " *  |-,-----|                         |-------uuuu|  *" << std::endl;
	std::cout << "    ^       ^                         ^           ^ " << std::endl;
	std::cout << std::endl;
	return;
}

void WordLengthSelection() {

	
	FText Response = "";				// get input from the user ,
	std::cout << "How many characters from 3 to 8, do you want your hidden word to have ?: ";
	std::getline(std::cin, Response);
	std::cout << "\n";
	if (Response.length() > 1) {	// check if the input is 1 char long

		std::cout << "You need to give me a single digit number here... -_-" << std::endl;
		return WordLengthSelection();
	}
	else if(!isdigit(Response[0])) {	// check if the input is an int

		std::cout << "You need to give me a single digit number here... -_-" << std::endl;
		return WordLengthSelection();
	}
	else {

		int32 Respo = std::stoi(Response);
		Response = HiddenWords.getWordFromDictionary(Respo);
		return;
	}
}


FText getValidGuess(FText guessParam) {		//loop until user gives a valid guess

	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do  {									// get the guess from the player

		std::cout << "You are on try: " << BCGame.GetCurrentTry() << " of " << BCGame.GetMaxTries();
		std::cout << " What is your guess? :";
		std::getline(std::cin, Guess);


											//check status and return Status
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "This is not an Isogram, senpai. \n\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word, senpai. \n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "You gotta write in all lowercase, senpai. \n\n";
			break;
		case EGuessStatus::Invalid_characters:
			std::cout << "I think those aren't really letters, senpai. \n\n";
			break;
		case EGuessStatus::Already_Tried:
			std::cout << "You already tried this word before, senpai. \n\n";
			break;
		default:
			break;
		};

	} while ( Status != EGuessStatus::OK );
	return Guess;
};

void PrintGameSummary() {
	if (BCGame.IsGameWon()) {
		std::cout << "Oh wow! You have won the Game! \n";
	}
	else {
		std::cout << "Naw! Better luck next time, famski... \n";
	}
};

void playTheGame() {					// plays a single game until completion

	FString  var = HiddenWords.getterSelectedWord();	// actual variable declaration.

	FString  *ip;			// declare a variable that is >> typeof << Pointer 
	ip = &var;			  // store >> address << of var in the Pointer variable
	
	BCGame.Reset();
	BCGame.ChangeMyHiddenWord(*ip);  // pass the pointer to the BCGame as the hidden word
	int32 MaxTries = BCGame.GetMaxTries();
	
	
	
				// loop for a bunch of turns and ask for guesses while the game is NOT won and there are still tries remaining
	while ( !BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries ) {
		FText Guess = getValidGuess("aa"); 
								// Submit valid guess to the game and recieve counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);


		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << "\n\n" ; 
	};

	printGameSummary();
	return;
};

bool askToPlayAgain() {

	std::cout << "Do you want to play again with the same hidden word? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);

	std::cout << std::endl;
	return (Response[0] == 'y' ) || (Response[0] == 'Y');
};

void printGameSummary() {

	PointerToBullCowGame = &BCGame;				// points to address of BCGame

	if (PointerToBullCowGame->IsGameWon()) {
		std::cout << "Oh wow! You have won the Game! \n";
	}
	else {
		std::cout << "Naw! Better luck next time, famski... \n";
	}
};

int main() {				// entry point for the application

	do {
		printIntro();
		WordLengthSelection();
		playTheGame();
	} 
	while (
		askToPlayAgain() == 1
		);
	return 0;			//	exit the app

}
