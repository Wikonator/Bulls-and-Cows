/* header for a class resolving the player choosing word length
	Contains a list of all available words the player can resolve to start guessing
	Note the getter method returns a pointer
*/

#pragma once

#include <string>

using FString = std::string;
using int32 = int;

class FHiddenWords {
	
public:
	FHiddenWords(); 	// a constructor
	~FHiddenWords();
	FString getterSelectedWord() const;
	FString getWordFromDictionary(int32 respo);

private:
	struct Dictionary {

		FString Three = "asp";
		FString Four = "corn";
		FString Five = "lower";
		FString Six = "carpet";
		FString Seven = "miracle";
		FString Eight = "machined";
		FString Nine = "brimstone";

	};
	
	FString SelectedHiddenWord;
	FString *PointerToHiddenWord;
};
