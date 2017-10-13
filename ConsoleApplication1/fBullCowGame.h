/*	header for the class that stores all the assets in one particular game
	contains a counter for letter hits, the word being guessed and checking for player guess validity
*/

#pragma once
#include <string>
#include "fHiddenWords.h"

	// make syntax Unreal friendly

using FString = std::string;
using int32 = int;

// all values intialized to 0

struct FBullCowCount {
	
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {

	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
	Invalid_characters,
	Already_Tried
};


class FBullCowGame {
public:
	FBullCowGame(); //constructor

	void Reset(); 
	void ChangeMyHiddenWord(FString WordFromList);
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	EGuessStatus  CheckGuessValidity(FString) const; 
	bool IsGameWon() const; 
	FBullCowCount SubmitValidGuess(FString TheGuess);


private:
	// see constructor for intialization
	int32 MyCurrentTry;
	int32 MyCurrentGuess;
	bool bGameIsWon;
	FString MyHiddenWord;
	FString TheGuess;
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};
