#include "fBullCowGame.h"
#include "fHiddenWords.h"
#include <map>
#include <string>

#define TMap std::map

using int32 = int;
using FString = std::string;

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; };
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); };
bool FBullCowGame::IsGameWon() const { return bGameIsWon; };

FBullCowGame::FBullCowGame() { Reset(); };


int32 FBullCowGame::GetMaxTries() const { 

	TMap<int32, int32> WordLengthToMaxTries {
		{3, 4}, {4, 6}, {5, 8}, {6, 12}, {7, 15}, {8, 20}
	};
	return WordLengthToMaxTries[MyHiddenWord.length()]; 

};


void FBullCowGame::Reset() {

	
	constexpr int32 MAX_TRIES = 10;
	FString HIDDEN_WORD = "default" ;

	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
	return;
}

void FBullCowGame::ChangeMyHiddenWord(FString WordFromList) {

	//take hidden word and set is as the new HiddenWord
	MyHiddenWord = WordFromList;

};


EGuessStatus FBullCowGame::CheckGuessValidity(FString TheGuess) const {

	if (!FBullCowGame::IsIsogram(TheGuess)) { 	//if the guess isnt an isogram 

		return EGuessStatus::Not_Isogram;
	}
	else if (!FBullCowGame::IsLowercase(TheGuess)) {	//TODO if the guess isnt all lowecase

		return EGuessStatus::Not_Lowercase;
	}
	else if (TheGuess.length() != GetHiddenWordLength()) {	// if the guess length is wrong

		return EGuessStatus::Wrong_Length;
	}
	else {	// otherwise return OK
		return EGuessStatus::OK;
	}
	
	
}

//recieves a valid guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString TheGuess){

	MyCurrentTry++;
	FBullCowCount BullCowCount;		// initialize BullCowCount
	FBullCowCount *PointerToBullCowCount;	// initialize Pointer variable
	PointerToBullCowCount = &BullCowCount; // set pointer to the Address of BullCowCount

	// testing hypthesis = if the pointer is of class FBullCowCount - does it have properties of .Bulls and .Cows  ??



	int32 WordLength = MyHiddenWord.length(); // assuming the same lenght as guess

	//loop thru all letters in the hidden word
	for (int32 i = 0; i < WordLength; i++) {

		for (int32 j = 0; j < WordLength; j++) {

			if (MyHiddenWord[i] == TheGuess[j]) {
				if (i == j) {
					PointerToBullCowCount->Bulls++;  // the -> means it is reffering to the instance it points to
				}										// +1 like to autocomplete for this one
				else {
					PointerToBullCowCount->Cows++;	// increment Cows at BullCowCount at the address that PointerTo is >pointing to<
				}
				
			}
			else {
				// do nothing :)
			}
		}
	}
	  // compare letters against the hidden word
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	} else {
		bGameIsWon = false;
	}
	
	return *PointerToBullCowCount; // return the Pointer to the Address
};

bool FBullCowGame::IsIsogram(FString Input) const {
	
	if (Input.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;
	for (char Letter : Input) { // for all Letters of the word
		
		Letter = tolower(Letter);
		if (LetterSeen[Letter] == true) {
			return false;
		} else {
			LetterSeen[Letter] = true;
		}
	}
};

bool FBullCowGame::IsLowercase(FString Input) const {

	if (Input.length() == 0) { return true; }

	for (auto Letter : Input) {
		
		if ( islower(Letter) ) {
			//DO Nothing
		}
		else {
			return false;
		}
	}
	// loop thru all the letters of the Input
		// check if each letter isLowercase(), 
}
