#pragma once

#include <string>

using FString = std::string;
using int32 = int;

class FHiddenWords {
	
public:
	FHiddenWords(); 	// a constructor
	~FHiddenWords();
	FString getterSelectedWord();
	FString getWordFromDictionary(int32 respo);

private:
	struct Dictionary {

		FString Three = "asp";
		FString Four = "corn";
		FString Five = "lower";
		FString Six = "carpet";
		FString Seven = "miracle";
		FString Eight = "machined";

	};
	
	FString SelectedHiddenWord;
	FString *PointerToHiddenWord;
};