#include <string>
#include <iostream>
#include "fHiddenWords.h"

using FString = std::string;


FHiddenWords::FHiddenWords() {
	
	return;
};


FHiddenWords::~FHiddenWords() {

	return;
}

FString FHiddenWords::getterSelectedWord() {

	return *PointerToHiddenWord;
};




FString FHiddenWords::getWordFromDictionary(int32 respo) {
	Dictionary List;

	switch (respo) {
	case 0 || 1 || 2 :
		return "factory";
		break; //TODO eror handling
	case 3 : 
		
		SelectedHiddenWord = List.Three;
		PointerToHiddenWord = &SelectedHiddenWord;
		return *PointerToHiddenWord;
		break;
	case 4 :
		SelectedHiddenWord = List.Four;
		PointerToHiddenWord = &SelectedHiddenWord;
		return *PointerToHiddenWord;
		break;
	case 5 :
		SelectedHiddenWord = List.Five;
		PointerToHiddenWord = &SelectedHiddenWord;
		return *PointerToHiddenWord;
		break;
	case 6 :
		SelectedHiddenWord = List.Six;
		PointerToHiddenWord = &SelectedHiddenWord;
		return *PointerToHiddenWord;
		break;
	case 7 :
		SelectedHiddenWord = List.Seven;
		PointerToHiddenWord = &SelectedHiddenWord;
		return *PointerToHiddenWord;
		break;
	case 8 :
		SelectedHiddenWord = List.Eight;
		PointerToHiddenWord = &SelectedHiddenWord;
		return *PointerToHiddenWord;
		break;
	default : 
		return "nope";
	};
	return FString("nieco");
}


