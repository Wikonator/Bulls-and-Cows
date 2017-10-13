#pragma once
#include <string>
#include "fHiddenWords.h"

using FString = std::string;
using int32 = int;

//all values intialized to 0

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
	FBullCowGame(); //cunstructor

	void Reset(); //TODO make a more rich return value
	void ChangeMyHiddenWord(FString WordFromList);
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	EGuessStatus  CheckGuessValidity(FString) const; //TODO make a richer return value
	bool IsGameWon() const; //TODO determine a win condition and implement into main
	FBullCowCount SubmitValidGuess(FString TheGuess);


//I'm not even here 0~o
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