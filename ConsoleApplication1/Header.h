#pragma once

#include <string>
#include "fBullCowGame.h"
#include "fHiddenWords.h"

void playTheGame();
void printIntro();
void printGameSummary();
void WordLengthSelection();
bool askToPlayAgain();
FBullCowGame BCGame; // instance of a new game
FBullCowGame *PointerToBullCowGame; // does what it says, I assign it in fun: printGameSummary
FHiddenWords HiddenWords;