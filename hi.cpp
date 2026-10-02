#include <iostream>
#include <cmath>
#include <tuple>
#include <string>

#define RESET "\033[0m"
#define BLUE "\033[34m"

struct charProficiency {
    bool strength = false;
    bool dexterity = false;
    bool constitution = false;
    bool wisdom = false;
    bool intelligence = false;
    bool charisma = false;

    bool acrobatics = false;
    bool animalHandling = false;
    bool arcana = false;
    bool athletics = false;
    bool deception = false;
    bool history = false;
    bool insight = false;
    bool intimidation = false;
    bool investigation = false;
    bool medicine = false;
    bool nature = false;
    bool perception = false;
    bool performance = false;
    bool persuasion = false;
    bool religion = false;
    bool sleightOfHand = false;
    bool stealth= false;
    bool survival = false;
} proficiency;

struct charAbilityScore {
    int strength = 8;
    int dexterity = 8;
    int constitution = 8;
    int wisdom = 8;
    int intelligence = 8;
    int charisma = 8;
} abilityScore;

std::string getCharName();
std::tuple<std::string, int> getCharClass();
std::string getCharOrigin();
std::string getCharSpecies();
std::tuple<charAbilityScore, charProficiency> getOriginProficiencies(charAbilityScore, charProficiency, std::string charOrigin);
charProficiency getClassProficiencies(charProficiency, std::string charClass);
std::tuple<charAbilityScore> getAbilityScore(charAbilityScore);

void printCharSheet(std::string charName, std::string charSpecies, std::string charClass, std::string charOrigin, charAbilityScore, charProficiency);


int main()
{
    int charAc = 0;
    int charHP = 0;

    std::cout << "************* D&D 5.5e 1st Level Character Creator *************\n"
              << "This has info from the D&D 2024 PHB and Eberron: Forge of the Artificer.\n";

    std::string charName = getCharName();

    std::string charClass = "Unknown";
    int hitDie = 8;
    std::tie(charClass, hitDie) = getCharClass();

    std::string charOrigin = getCharOrigin();

    std::string charSpecies = getCharSpecies();

    std::tie(abilityScore) = getAbilityScore(abilityScore);

    std::tie(abilityScore, proficiency) = getOriginProficiencies(abilityScore, proficiency, charOrigin);

    proficiency = getClassProficiencies(proficiency, charClass);

    std::cout << "****************************************************************\n";

    printCharSheet(charName, charSpecies, charClass, charOrigin, abilityScore, proficiency);

    return 0;
}

std::string getCharName(){
    std::string name;
    std::cout << "What is your character's name?\n";
    std::getline(std::cin, name);
    std::cout << "--------------------------------\n";
    return name;
}

std::tuple<std::string, int> getCharClass(){
    std::string charClass;
    int hitDie = 8;
    int charClassChoice = 1;
    do{
        std::cout << "Select your characters class:\n"
                  << "Type 1 for artificer.\n"
                  << "Type 2 for barbarian.\n"
                  << "Type 3 for bard.\n"
                  << "Type 4 for cleric.\n"
                  << "Type 5 for druid.\n"
                  << "Type 6 for fighter.\n"
                  << "Type 7 for monk.\n"
                  << "Type 8 for paladin.\n"
                  << "Type 9 for ranger.\n"
                  << "Type 10 for rogue.\n"
                  << "Type 11 for sorcerer.\n"
                  << "Type 12 for warlock.\n"
                  << "Type 13 for wizard.\n";
        std::cin >> charClassChoice;
        switch(charClassChoice){
            case 1: charClass = "Artificer"; break;
            case 2: charClass = "Barbarian"; hitDie = 12; break;
            case 3: charClass = "Bard"; break;
            case 4: charClass = "Cleric"; break;
            case 5: charClass = "Druid"; break;
            case 6: charClass = "Fighter"; hitDie = 10;break;
            case 7: charClass = "Monk"; break;
            case 8: charClass = "Paladin"; hitDie = 10; break;
            case 9: charClass = "Ranger"; hitDie = 10; break;
            case 10: charClass = "Rogue"; break;
            case 11: charClass = "Sorcerer"; hitDie = 6; break;
            case 12: charClass = "Warlock"; break; 
            case 13: charClass = "Wizard"; hitDie = 6; break;
            default: std::cout << "----------That is not a valid answer.----------\n"; break;
        }
    }while(charClassChoice < 1 || charClassChoice > 13);
    std::cout << "--------------------------------\n";
    return std::make_tuple(charClass, hitDie);
}

std::string getCharOrigin(){
    int charOriginChoice;
    std::string charOrigin;
    do{
        std::cout << "Select your characters origin:\n"
                << "Type 1 for Aberrant Heir.\n"
                << "Type 2 for acolyte.\n"
                << "Type 3 for Archarologist.\n"
                << "Type 4 for artisan.\n"
                << "Type 5 for charlatan.\n"
                << "Type 6 for criminal.\n"
                << "Type 7 for entertainer.\n"
                << "Type 8 for farmer.\n"
                << "Type 9 for guard.\n"
                << "Type 10 for guide.\n"
                << "Type 11 for hermit.\n"
                << "Type 12 for House Agent\n"
                << "Type 13 for House Cannith Heir\n"
                << "Type 14 for House Deneith Heir\n"
                << "Type 15 for House Ghallanda Heir\n"
                << "Type 16 for House Jorasco Heir\n"
                << "Type 17 for House Kundarak Heir\n"
                << "Type 18 for House Lyrandar Heir\n"
                << "Type 19 for House Medani Heir\n"
                << "Type 20 for House Orein Heir\n"
                << "Type 21 for House Phiarlan Heir\n"
                << "Type 22 for House Sivis Heir\n"
                << "Type 23 for House Tharashk Heir\n"
                << "Type 24 for House Thuranni Heir\n"
                << "Type 25 for House Vadalis Heir\n"
                << "Type 26 for House Inqisitive\n"
                << "Type 27 for merchant.\n"
                << "Type 28 for noble.\n"
                << "Type 29 for sage.\n"
                << "Type 30 for sailor.\n"
                << "Type 31 for scribe.\n"
                << "Type 32 for soldier.\n"
                << "Type 33 for wayfarer.\n";
        std::cin >> charOriginChoice;
        switch(charOriginChoice){
            case 1: charOrigin = "Aberrant Heir"; break;
            case 2: charOrigin = "Acolyte"; break;
            case 3: charOrigin = "Archaeologist"; break;
            case 4: charOrigin = "Artisan"; break;
            case 5: charOrigin = "Charlatan"; break;
            case 6: charOrigin = "Criminal"; break;
            case 7: charOrigin = "Entertainer"; break;
            case 8: charOrigin = "Farmer"; break;
            case 9: charOrigin = "Guard"; break;
            case 10: charOrigin = "Guide"; break;
            case 11: charOrigin = "Hermit"; break;
            case 12: charOrigin = "House Agent"; break;
            case 13: charOrigin = "House Cannith"; break;
            case 14: charOrigin = "House Deneith"; break;
            case 15: charOrigin = "House Ghallanda"; break;
            case 16: charOrigin = "House Jorasco"; break;
            case 17: charOrigin = "House Kundarak"; break;
            case 18: charOrigin = "House Lyrandar"; break;
            case 19: charOrigin = "House Medani"; break;
            case 20: charOrigin = "House Orein"; break;
            case 21: charOrigin = "House Phiarlan"; break;
            case 22: charOrigin = "House Sivis"; break;
            case 23: charOrigin = "House Tharashk"; break;
            case 24: charOrigin = "House Thuranni"; break;
            case 25: charOrigin = "House Vadalis"; break;
            case 26: charOrigin = "Inquisitive"; break;
            case 27: charOrigin = "Merchant"; break;
            case 28: charOrigin = "Noble"; break;
            case 29: charOrigin = "Sage"; break; 
            case 30: charOrigin = "Sailor"; break;
            case 31: charOrigin = "Scribe"; break;
            case 32: charOrigin = "Soldier"; break;
            case 33: charOrigin = "Wayfarer"; break;
            default: std::cout << "----------That is not a valid answer.----------\n"; break;
        }
    }while(charOriginChoice < 1 || charOriginChoice > 33);
    std::cout << "--------------------------------\n";
    return charOrigin;
}

std::string getCharSpecies(){
    int charSpeciesChoice;
    std::string charSpecies;
    do{
        std::cout << "Select your characters species:\n"
                  << "Type 1 for aasimar.\n"
                  << "Type 2 for changling.\n"
                  << "Type 3 for dragonborn.\n"
                  << "Type 4 for dwarf.\n"
                  << "Type 5 for elf.\n"
                  << "Type 6 for gnome.\n"
                  << "Type 7 for goliath.\n"
                  << "Type 8 for halfling.\n"
                  << "Type 9 for human.\n"
                  << "Type 10 for kalashtar.\n"
                  << "Type 11 for khoravar.\n"
                  << "Type 12 for orc.\n"
                  << "Type 13 for shifter.\n"
                  << "Type 14 for tiefling.\n"
                  << "Type 15 for warforged.\n";
        std::cin >> charSpeciesChoice;
        switch(charSpeciesChoice){
            case 1: charSpecies = "Aasimar";  break;
            case 3: charSpecies = "Dragonborn";  break;
            case 4: charSpecies = "Dwarf";  break;
            case 5: charSpecies = "Elf";  break;
            case 6: charSpecies = "Gnome";  break;
            case 7: charSpecies = "Goliath";  break;
            case 8: charSpecies = "Halfling";  break;
            case 9: charSpecies = "Human";  break;
            case 10: charSpecies = "Kalashtar"; break;
            case 11: charSpecies = "Khoravar"; break;
            case 12: charSpecies = "Orc";  break;
            case 13: charSpecies = "Shifter"; break;
            case 14: charSpecies = "Tiefling";  break;
            default: std::cout << "----------That is not a valid answer.----------\n"; break;
        }
    }while(charSpeciesChoice < 1 || charSpeciesChoice > 15);
    std::cout << "--------------------------------\n";
    return charSpecies;
}

std::tuple<charAbilityScore> getAbilityScore(charAbilityScore abilityScore){
    int pointBuyPoints = 27;
    do{
        std::cout << "------------Ability Scores------------\n"
                  << BLUE << "You have " << pointBuyPoints << " points to spend.\n"
                  << RESET << "What ability score would you like to change?\n"
                  << "Type 1 for strength.\n"
                  << "Type 2 for dexterity.\n"
                  << "Type 3 for constitution.\n"
                  << "Type 4 for wisdom.\n"
                  << "Type 5 for intelligence.\n"
                  << "Type 6 for charisma.\n";
        
        int abilityScoreEditing = 0;
        std::cin >> abilityScoreEditing;
        std::string abilityScoreName = "None";
        switch(abilityScoreEditing){
            case 1: abilityScoreName = "Strength"; break;
            case 2: abilityScoreName = "Dexterity"; break;
            case 3: abilityScoreName = "Constitution"; break;
            case 4: abilityScoreName = "Wisdom"; break;
            case 5: abilityScoreName = "Intelligence"; break;
            case 6: abilityScoreName = "Charisma"; break;
            default: std::cout << "----------That is not a valid answer.----------\n"; continue; break;
        }

        std::cout << "-------------------------------------------\n"
                  << "| Ability Score | Ability Modifier | Cost |\n"
                  << "|       8       |         -1       |   0  |\n"
                  << "|       9       |         -1       |   1  |\n"
                  << "|      10       |         +0       |   2  |\n" 
                  << "|      11       |         +0       |   3  |\n"
                  << "|      12       |         +1       |   4  |\n"
                  << "|      13       |         +1       |   5  |\n"
                  << "|      14       |         +2       |   7  |\n"
                  << "|      15       |         +2       |   9  |\n"
                  << "------------------------------------------\n"
                  << "How many points would you like to spend?\n";
        
        int pointBuyInput = 0;
        std::cin >> pointBuyInput;
       if(pointBuyPoints >= pointBuyInput && 0 < pointBuyInput && 6 > pointBuyInput){
            pointBuyPoints -= pointBuyInput;
            if(abilityScoreName == "Strength"){abilityScore.strength = pointBuyInput + 8;}
            if(abilityScoreName == "Dexterity"){abilityScore.dexterity = pointBuyInput + 8;}
            if(abilityScoreName == "Constitution"){abilityScore.constitution = pointBuyInput + 8;}
            if(abilityScoreName == "Wisdom"){abilityScore.wisdom = pointBuyInput + 8;}
            if(abilityScoreName == "Intelligence"){abilityScore.intelligence = pointBuyInput + 8;}
            if(abilityScoreName == "Charisma"){abilityScore.charisma = pointBuyInput + 8;}
        }
        else if(pointBuyPoints >= pointBuyInput && (pointBuyInput == 7 || pointBuyInput == 9)){
            pointBuyPoints -= pointBuyInput;
            if(abilityScoreName == "Strength"){abilityScore.strength = pointBuyInput * 0.5 + 10.5;}
            if(abilityScoreName == "Dexterity"){abilityScore.dexterity = pointBuyInput * 0.5 + 10.5;}
            if(abilityScoreName == "Constitution"){abilityScore.constitution = pointBuyInput * 0.5 + 10.5;}
            if(abilityScoreName == "Wisdom"){abilityScore.wisdom = pointBuyInput * 0.5 + 10.5;}
            if(abilityScoreName == "Intelligence"){abilityScore.intelligence = pointBuyInput * 0.5 + 10.5;}
            if(abilityScoreName == "Charisma"){abilityScore.charisma = pointBuyInput * 0.5 + 10.5;}
        }
        else{std::cout << "----------That is not a valid answer.----------\n";}

    }while(pointBuyPoints > 0);
    std::cout << "--------------------------------\n";
    return std::make_tuple(abilityScore);
}
    
std::tuple<charAbilityScore, charProficiency> getOriginProficiencies(charAbilityScore abilityScore, charProficiency proficiency, std::string charOrigin){
    if(charOrigin == "Entertainer" || charOrigin == "House Lyrandar Heir" || charOrigin == "House Orien Heir" || charOrigin == "Sailor"){proficiency.acrobatics = true;}
    if(charOrigin == "House Kundarak Heir" || charOrigin == "Sage"){proficiency.arcana = true;}
    if(charOrigin == "Farmer" || charOrigin == "House Vadalis Heir" || charOrigin == "Merchant"){proficiency.animalHandling = true;}
    if(charOrigin == "Guard" || charOrigin == "House Orien Heir" || charOrigin == "Soldier"){proficiency.athletics = true;}
    if(charOrigin == "Charlatan" || charOrigin == "House Phiarlan Heir"){proficiency.deception = true;}
    if(charOrigin == "Aberrant Heir" || charOrigin == "Arcaeologist" || charOrigin == "House Sivis Heir" || charOrigin == "Noble" || charOrigin == "Sage"){proficiency.history= true;}
    if(charOrigin == "Acolyte" || charOrigin == "House Deneith Heir" || charOrigin == "House Ghallanda Heir" || charOrigin == "House Medani Heir" || charOrigin == "Inquisitive" || charOrigin == "Wayfarer"){proficiency.insight= true;}
    if(charOrigin == "Aberrant Heir" || charOrigin == "Soldier"){proficiency.intimidation= true;}
    if(charOrigin == "Artisan" || charOrigin == "House Agent" || charOrigin == "House Cannith Heir" || charOrigin == "House Kundarak Heir" || charOrigin == "House Medani Heir" || charOrigin == "Inquisitive" || charOrigin == "Scribe"){proficiency.investigation= true;}
    if(charOrigin == "Hermit" || charOrigin == "House Jorasco Heir"){proficiency.medicine = true;}
    if(charOrigin == "Farmer" || charOrigin == "House Lyrandar Heir" || charOrigin == "House Vadalis Heir"){proficiency.nature = true;}
    if(charOrigin == "Guard" || charOrigin == "House Deneith Heir" || charOrigin == "House Sivis Heir" || charOrigin == "House Tharashk Heir" || charOrigin == "Sailor" || charOrigin == "Scribe"){proficiency.perception = true;}
    if(charOrigin == "Entertainer" || charOrigin == "House Thuranni Heir"){proficiency.performance = true;}
    if(charOrigin == "Artisan" || charOrigin == "House Agent" || charOrigin == "House Ghallanda Heir" || charOrigin == "Merchant" || charOrigin == "Noble"){proficiency.persuasion = true;}
    if(charOrigin == "Acolyte" || charOrigin == "Hermit"){proficiency.religion = true;}
    if(charOrigin == "Charlatan" || charOrigin == "Criminal" || charOrigin == "House Cannith Heir"){proficiency.sleightOfHand = true;}
    if(charOrigin == "Criminal" || charOrigin == "Guide" || charOrigin == "House Jorasco Heir" || charOrigin == "House Phiarlan Heir" || charOrigin == "House Thuranni Heir" || charOrigin == "Wayfarer"){proficiency.stealth = true;}
    if(charOrigin == "Acolyte" || charOrigin == "Guide" || charOrigin == "House Tharashk Heir"){proficiency.survival = true;}

    int abilityScoreInceaseChoice = 0;
    int abilityScoreInceaseTimes = 0;

    int numOfStrIncreases = 0;
    int numOfDexIncreases = 0;
    int numOfConIncreases = 0;
    int numOfWisIncreases = 0;
    int numOfIntIncreases = 0;
    int numOfChaIncreases = 0;
    do{
        std::cout << "What ability score would you like to increase?\n";
        if((charOrigin == "Aberrant Heir" || charOrigin == "Artisan" || charOrigin == "Entertainer" || charOrigin == "Farmer" || charOrigin == "Guard" || charOrigin == "House Agent" || charOrigin == "House Cannith Heir" || charOrigin == "House Deneith Heir" || charOrigin == "House Kundarak Heir" || charOrigin == "House Lyrandar Heir" || charOrigin == "Noble" || charOrigin == "Sailor" || charOrigin == "Soldier") && numOfStrIncreases < 2){std::cout << "Type 1 for strength.\n";}
        if((charOrigin == "Archaeologist" || charOrigin == "Artisan" || charOrigin == "Charlatan" || charOrigin == "Criminal" || charOrigin == "Entertainer" || charOrigin == "Guide" || charOrigin == "House Cannith Heir" || charOrigin == "House Ghallanda Heir" || charOrigin == "House Jorasco Heir" || charOrigin == "House Lyrandar Heir" || charOrigin == "House Medani Heir" || charOrigin == "House Orien Heir" || charOrigin == "House Phiarlan Heir" || charOrigin == "House Thuranni Heir" || charOrigin == "Sailor" || charOrigin == "Scribe" || charOrigin == "Soldier" || charOrigin == "Wayfarer") && numOfDexIncreases < 2){std::cout << "Type 2 for dexterity.\n";}
        if((charOrigin == "Aberrant Heir" || charOrigin == "Charlatan" || charOrigin == "Criminal" || charOrigin == "Farmer" || charOrigin == "Guide" || charOrigin == "Hermit" || charOrigin == "House Deneith Heir" || charOrigin == "House Jorasco Heir" || charOrigin == "House Kundarak Heir" || charOrigin == "House Orien Heir" || charOrigin == "House Tharashk Heir" || charOrigin == "House Vadalis Heir" || charOrigin == "Inquisitive" || charOrigin == "Merchant" || charOrigin == "Sage" || charOrigin == "Soldier") && numOfConIncreases < 2){std::cout << "Type 3 for constitution.\n";}
        if((charOrigin == "Acolyte" || charOrigin == "Archaeologist" || charOrigin == "Farmer" || charOrigin == "Guard" || charOrigin == "Guide" || charOrigin == "Hermit" || charOrigin == "House Deneith Heir" || charOrigin == "House Ghallanda Heir" || charOrigin == "House Jorasco Heir" || charOrigin == "House Medani Heir" || charOrigin == "House Phiarlan Heir" || charOrigin == "House Sivis Heir" || charOrigin == "House Tharashk Heir" || charOrigin == "House Vadalis Heir" || charOrigin == "Sage" || charOrigin == "Sailor" || charOrigin == "Scribe" || charOrigin == "Wayfarer") && numOfWisIncreases < 2){std::cout << "Type 4 for wisdom.\n";}
        if((charOrigin == "Acolyte" || charOrigin == "Archaeologist" || charOrigin == "House Agent" || charOrigin == "Artisan" || charOrigin == "Criminal" || charOrigin == "Guard" || charOrigin == "House Agent" || charOrigin == "House Cannith Heir" || charOrigin == "House Kundarak Heir" || charOrigin == "House Medani Heir" || charOrigin == "House Orien Heir" || charOrigin == "House Sivis Heir" || charOrigin == "House Tharashk Heir" || charOrigin == "House Thuranni Heir" || charOrigin == "Inquisitive" || charOrigin == "Merchant" || charOrigin == "Noble" || charOrigin == "Sage" || charOrigin == "Scribe") && numOfIntIncreases < 2){std::cout << "Type 5 for intelligence.\n";}
        if((charOrigin == "Aberrant Heir" || charOrigin == "Acolyte" || charOrigin == "Charlatan" || charOrigin == "Entertainer" || charOrigin == "Hermit" || charOrigin == "House Agent" || charOrigin == "House Ghallanda Heir" || charOrigin == "House Lyrandar Heir" || charOrigin == "House Phiarlan Heir" || charOrigin == "House Sivis Heir" || charOrigin == "House Thuranni Heir" || charOrigin == "House Vadalis Heir" || charOrigin == "Inquisitive" || charOrigin == "Merchant" || charOrigin == "Noble" || charOrigin == "Wayfarer") && numOfChaIncreases < 2){std::cout << "Type 6 for charisma.\n";}

        std::cin >> abilityScoreInceaseChoice;
        switch(abilityScoreInceaseChoice){
            case 1: if((charOrigin == "Aberrant Heir" || charOrigin == "Artisan" || charOrigin == "Entertainer" || charOrigin == "Farmer" || charOrigin == "Guard" || charOrigin == "House Agent" || charOrigin == "House Cannith Heir" || charOrigin == "House Deneith Heir" || charOrigin == "House Kundarak Heir" || charOrigin == "House Lyrandar Heir" || charOrigin == "Noble" || charOrigin == "Sailor" || charOrigin == "Soldier") && numOfStrIncreases < 2){numOfStrIncreases++; abilityScoreInceaseTimes++;} break;
            case 2: if((charOrigin == "Archaeologist" || charOrigin == "Artisan" || charOrigin == "Charlatan" || charOrigin == "Criminal" || charOrigin == "Entertainer" || charOrigin == "Guide" || charOrigin == "House Cannith Heir" || charOrigin == "House Ghallanda Heir" || charOrigin == "House Jorasco Heir" || charOrigin == "House Lyrandar Heir" || charOrigin == "House Medani Heir" || charOrigin == "House Orien Heir" || charOrigin == "House Phiarlan Heir" || charOrigin == "House Thuranni Heir" || charOrigin == "Sailor" || charOrigin == "Scribe" || charOrigin == "Soldier" || charOrigin == "Wayfarer") && numOfDexIncreases < 2){numOfDexIncreases++; abilityScoreInceaseTimes++;} break;
            case 3: if((charOrigin == "Aberrant Heir" || charOrigin == "Charlatan" || charOrigin == "Criminal" || charOrigin == "Farmer" || charOrigin == "Guide" || charOrigin == "Hermit" || charOrigin == "House Deneith Heir" || charOrigin == "House Jorasco Heir" || charOrigin == "House Kundarak Heir" || charOrigin == "House Orien Heir" || charOrigin == "House Tharashk Heir" || charOrigin == "House Vadalis Heir" || charOrigin == "Inquisitive" || charOrigin == "Merchant" || charOrigin == "Sage" || charOrigin == "Soldier") && numOfConIncreases < 2){numOfConIncreases++; abilityScoreInceaseTimes++;} break;
            case 4: if((charOrigin == "Acolyte" || charOrigin == "Archaeologist" || charOrigin == "Farmer" || charOrigin == "Guard" || charOrigin == "Guide" || charOrigin == "Hermit" || charOrigin == "House Deneith Heir" || charOrigin == "House Ghallanda Heir" || charOrigin == "House Jorasco Heir" || charOrigin == "House Medani Heir" || charOrigin == "House Phiarlan Heir" || charOrigin == "House Sivis Heir" || charOrigin == "House Tharashk Heir" || charOrigin == "House Vadalis Heir" || charOrigin == "Sage" || charOrigin == "Sailor" || charOrigin == "Scribe" || charOrigin == "Wayfarer") && numOfWisIncreases < 2){numOfWisIncreases++; abilityScoreInceaseTimes++;} break;
            case 5: if((charOrigin == "Acolyte" || charOrigin == "Archaeologist" || charOrigin == "House Agent" || charOrigin == "Artisan" || charOrigin == "Criminal" || charOrigin == "Guard" || charOrigin == "House Agent" || charOrigin == "House Cannith Heir" || charOrigin == "House Kundarak Heir" || charOrigin == "House Medani Heir" || charOrigin == "House Orien Heir" || charOrigin == "House Sivis Heir" || charOrigin == "House Tharashk Heir" || charOrigin == "House Thuranni Heir" || charOrigin == "Inquisitive" || charOrigin == "Merchant" || charOrigin == "Noble" || charOrigin == "Sage" || charOrigin == "Scribe") && numOfIntIncreases < 2){numOfIntIncreases++; abilityScoreInceaseTimes++;} break;
            case 6: if((charOrigin == "Aberrant Heir" || charOrigin == "Acolyte" || charOrigin == "Charlatan" || charOrigin == "Entertainer" || charOrigin == "Hermit" || charOrigin == "House Agent" || charOrigin == "House Ghallanda Heir" || charOrigin == "House Lyrandar Heir" || charOrigin == "House Phiarlan Heir" || charOrigin == "House Sivis Heir" || charOrigin == "House Thuranni Heir" || charOrigin == "House Vadalis Heir" || charOrigin == "Inquisitive" || charOrigin == "Merchant" || charOrigin == "Noble" || charOrigin == "Wayfarer") && numOfChaIncreases < 2){numOfChaIncreases++; abilityScoreInceaseTimes++;} break;
            default: std::cout << "----------That is not a valid answer.----------\n"; continue; break;
        }
    }while(abilityScoreInceaseTimes < 3);
    
    abilityScore.strength += numOfStrIncreases; 
    abilityScore.dexterity += numOfDexIncreases;
    abilityScore.constitution += numOfConIncreases;
    abilityScore.wisdom += numOfWisIncreases;
    abilityScore.intelligence += numOfIntIncreases;
    abilityScore.charisma += numOfChaIncreases;

    std::cout << "--------------------------------\n";
    return std::make_tuple(abilityScore, proficiency);
}

charProficiency getClassProficiencies(charProficiency proficiency, std::string charClass){
    if(charClass == "Artificer"){proficiency.constitution = true; proficiency.intelligence = true;}
    if(charClass == "Barbarian"){proficiency.strength = true; proficiency.constitution = true;}
    if(charClass == "Bard"){proficiency.dexterity = true; proficiency.charisma = true;}
    if(charClass == "Cleric"){proficiency.charisma = true; proficiency.wisdom = true;}
    if(charClass == "Druid"){proficiency.intelligence = true; proficiency.wisdom = true;}
    if(charClass == "Fighter"){proficiency.strength = true; proficiency.constitution = true;}
    if(charClass == "Monk"){proficiency.strength = true; proficiency.dexterity = true;}
    if(charClass == "Paladin"){proficiency.wisdom = true; proficiency.charisma = true;}
    if(charClass == "Ranger"){proficiency.dexterity = true; proficiency.wisdom = true;}
    if(charClass == "Rogue"){proficiency.dexterity = true; proficiency.intelligence = true;}
    if(charClass == "Sorcerer"){proficiency.constitution = true; proficiency.charisma = true;}
    if(charClass == "Warlock"){proficiency.wisdom = true; proficiency.charisma = true;}
    if(charClass == "Wizard"){proficiency.intelligence = true; proficiency.wisdom = true;}

    if(charClass == "Bard"){std::cout << "Choose three to be proficient in:\n";}else{std::cout << "Choose two to be proficient in:\n";}

    int classProficienciesInput = 0;
    int classProficienciesInputTimes = 0;
    int numOfClassProficiencies = 2;
    if(charClass == "Bard"){numOfClassProficiencies = 3;}
    do{
        if((charClass == "Bard" || charClass == "Fighter" || charClass == "Monk" || charClass == "Rogue") && !proficiency.acrobatics){std::cout << "Type 1 for acrobatics.\n";}
        if((charClass == "Artificer" || charClass == "Bard" || charClass == "Druid" || charClass == "Sorcerer" || charClass == "Warlock" || charClass == "Wizard") && !proficiency.arcana){std::cout << "Type 2 for arcana.\n";}
        if((charClass == "Barbarian" || charClass == "Bard" || charClass == "Druid" || charClass == "Fighter" || charClass == "Ranger") && !proficiency.animalHandling){std::cout << "Type 3 for animal handling.\n";}
        if((charClass == "Barbarian" ||  charClass == "Bard" || charClass == "Fighter" || charClass == "Monk" || charClass == "Paladin" || charClass == "Ranger" || charClass == "Rogue") && !proficiency.athletics){std::cout << "Type 4 for athletics.\n";}
        if((charClass == "Bard" || charClass == "Rogue" || charClass == "Sorcerer" || charClass == "Warlock") && !proficiency.deception){std::cout << "Type 5 for deception.\n";}
        if((charClass == "Artificer" ||  charClass == "Bard" || charClass == "Cleric" || charClass == "Fighter" || charClass == "Monk" || charClass == "Warlock" || charClass == "Wizard") && !proficiency.history){std::cout << "Type 6 for history.\n";}
        if((charClass == "Bard" || charClass == "Cleric" || charClass == "Druid" || charClass == "Fighter" || charClass == "Monk" || charClass == "Paladin" || charClass == "Ranger" || charClass == "Rogue" || charClass == "Sorcerer" || charClass == "Wizard") && !proficiency.insight){std::cout << "Type 7 for insight.\n";}
        if((charClass == "Barbarian" || charClass == "Bard" || charClass == "Fighter" || charClass == "Paladin" || charClass == "Rogue" || charClass == "Sorcerer" || charClass == "Warlock") && !proficiency.intimidation){std::cout << "Type 8 for intimidation.\n";}
        if((charClass == "Artificer" || charClass == "Bard" || charClass == "Ranger" || charClass == "Rogue" || charClass == "Wizard") && !proficiency.investigation){std::cout << "Type 9 for investigation.\n";}
        if((charClass == "Artificer" || charClass == "Bard" || charClass == "Cleric" || charClass == "Druid" || charClass == "Paladin" || charClass == "Wizard") && !proficiency.medicine){std::cout << "Type 10 for medicine.\n";}
        if((charClass == "Artificer" || charClass == "Barbarian" || charClass == "Druid" || charClass == "Ranger" || charClass == "Warlock" || charClass == "Wizard") && !proficiency.nature){std::cout << "Type 11 for nature.\n";}
        if((charClass == "Artificer" || charClass == "Barbarian" || charClass == "Druid" || charClass == "Fighter" || charClass == "Ranger" || charClass == "Rogue") && !proficiency.perception){std::cout << "Type 12 for perception.\n";}
        if((charClass == "Bard") && !proficiency.performance){std::cout << "Type 13 for performance.\n";}
        if((charClass == "Bard" || charClass == "Cleric" || charClass == "Fighter" || charClass == "Paladin" || charClass == "Rogue" || charClass == "Sorcerer") && !proficiency.persuasion){std::cout << "Type 14 for persuasion.\n";}
        if((charClass == "Bard" || charClass == "Cleric" || charClass == "Druid" || charClass == "Monk" || charClass == "Paladin" || charClass == "Sorcerer" || charClass == "Warlock" || charClass == "Wizard") && !proficiency.religion){std::cout << "Type 15 for religion.\n";}
        if((charClass == "Artificer" || charClass == "Bard" || charClass == "Rogue") && !proficiency.sleightOfHand){std::cout << "Type 16 for sleight of hand.\n";}
        if((charClass == "Bard" || charClass == "Monk" || charClass == "Ranger" || charClass == "Rogue") && !proficiency.stealth){std::cout << "Type 17 for stealth.\n";}
        if((charClass == "Barbarian" || charClass == "Bard" || charClass == "Druid" || charClass == "Fighter" || charClass == "Ranger") && !proficiency.survival){std::cout << "Type 18 for survival.\n";}

        std::cin >> classProficienciesInput;

        switch(classProficienciesInput){
            case 1: if((charClass == "Bard" || charClass == "Fighter" || charClass == "Monk" || charClass == "Rogue") && !proficiency.acrobatics){proficiency.acrobatics = true; classProficienciesInputTimes++;} break;
            case 2: if((charClass == "Artificer" || charClass == "Bard" || charClass == "Druid" || charClass == "Sorcerer" || charClass == "Warlock" || charClass == "Wizard") && !proficiency.arcana){proficiency.arcana = true; classProficienciesInputTimes++;} break;
            case 3: if((charClass == "Barbarian" || charClass == "Bard" || charClass == "Druid" || charClass == "Fighter" || charClass == "Ranger") && !proficiency.animalHandling){proficiency.animalHandling = true; classProficienciesInputTimes++; std::cout << numOfClassProficiencies << classProficienciesInputTimes;} break;
            case 4: if((charClass == "Barbarian" ||  charClass == "Bard" || charClass == "Fighter" || charClass == "Monk" || charClass == "Paladin" || charClass == "Ranger" || charClass == "Rogue") && !proficiency.athletics){proficiency.athletics = true; classProficienciesInputTimes++;} break;
            case 5: if((charClass == "Bard" || charClass == "Rogue" || charClass == "Sorcerer" || charClass == "Warlock") && !proficiency.deception){proficiency.deception = true; classProficienciesInputTimes++;} break;
            case 6: if((charClass == "Artificer" ||  charClass == "Bard" || charClass == "Cleric" || charClass == "Fighter" || charClass == "Monk" || charClass == "Warlock" || charClass == "Wizard") && !proficiency.history){proficiency.history = true; classProficienciesInputTimes++;} break;
            case 7: if((charClass == "Bard" || charClass == "Cleric" || charClass == "Druid" || charClass == "Fighter" || charClass == "Monk" || charClass == "Paladin" || charClass == "Ranger" || charClass == "Rogue" || charClass == "Sorcerer" || charClass == "Wizard") && !proficiency.insight){proficiency.insight = true;} classProficienciesInputTimes++; break;
            case 8: if((charClass == "Barbarian" || charClass == "Bard" || charClass == "Fighter" || charClass == "Paladin" || charClass == "Rogue" || charClass == "Sorcerer" || charClass == "Warlock") && !proficiency.intimidation){proficiency.intimidation = true; classProficienciesInputTimes++;} break;
            case 9: if((charClass == "Artificer" || charClass == "Bard" || charClass == "Ranger" || charClass == "Rogue" || charClass == "Wizard") && !proficiency.investigation){proficiency.investigation = true; classProficienciesInputTimes++;} break;
            case 10: if((charClass == "Artificer" || charClass == "Bard" || charClass == "Cleric" || charClass == "Druid" || charClass == "Paladin" || charClass == "Wizard") && !proficiency.medicine){proficiency.medicine = true; classProficienciesInputTimes++;} break;
            case 11: if((charClass == "Artificer" || charClass == "Barbarian" || charClass == "Druid" || charClass == "Ranger" || charClass == "Warlock" || charClass == "Wizard") && !proficiency.nature){proficiency.nature = true; classProficienciesInputTimes++;} break;
            case 12: if((charClass == "Artificer" || charClass == "Barbarian" || charClass == "Druid" || charClass == "Fighter" || charClass == "Ranger" || charClass == "Rogue") && !proficiency.perception){proficiency.perception = true; classProficienciesInputTimes++;} break;
            case 13: if((charClass == "Bard") && !proficiency.performance){proficiency.performance = true; classProficienciesInputTimes++;} break;
            case 14: if((charClass == "Bard" || charClass == "Cleric" || charClass == "Fighter" || charClass == "Paladin" || charClass == "Rogue" || charClass == "Sorcerer") && !proficiency.persuasion){proficiency.persuasion = true; classProficienciesInputTimes++;} break;
            case 15: if((charClass == "Bard" || charClass == "Cleric" || charClass == "Druid" || charClass == "Monk" || charClass == "Paladin" || charClass == "Sorcerer" || charClass == "Warlock" || charClass == "Wizard") && !proficiency.religion){proficiency.religion = true; classProficienciesInputTimes++;} break;
            case 16: if((charClass == "Artificer" || charClass == "Bard" || charClass == "Rogue") && !proficiency.sleightOfHand){proficiency.sleightOfHand = true; classProficienciesInputTimes++;} break;
            case 17: if((charClass == "Bard" || charClass == "Monk" || charClass == "Ranger" || charClass == "Rogue") && !proficiency.stealth){proficiency.stealth = true; classProficienciesInputTimes++;} break;
            case 18: if((charClass == "Barbarian" || charClass == "Bard" || charClass == "Druid" || charClass == "Fighter" || charClass == "Ranger") && !proficiency.survival){proficiency.survival = true; classProficienciesInputTimes++;} break;
            default: std::cout << "----------That is not a valid answer.----------\n"; continue; break;
        }
    }while(classProficienciesInputTimes < numOfClassProficiencies);

    return proficiency;
}

void printCharSheet(std::string charName, std::string charSpecies, std::string charClass, std::string charOrigin, charAbilityScore abilityScore, charProficiency proficiency){
    int strAbilityModifier = floor((abilityScore.strength - 10.0) / 2.0);
    int dexAbilityModifier = floor((abilityScore.dexterity - 10.0) / 2.0);
    int conAbilityModifier = floor((abilityScore.constitution - 10.0) / 2.0);
    int wisAbilityModifier = floor((abilityScore.wisdom - 10.0) / 2.0);
    int intAbilityModifier = floor((abilityScore.intelligence - 10.0) / 2.0);
    int chaAbilityModifier = floor((abilityScore.charisma - 10.0) / 2.0);

    int strSavingThrow = 0;
    int dexSavingThrow = 0;
    int conSavingThrow = 0;
    int wisSavingThrow = 0;
    int intSavingThrow = 0;
    int chaSavingThrow = 0;
    if(proficiency.strength){strSavingThrow = strAbilityModifier + 2;}else{strSavingThrow = strAbilityModifier;};
    if(proficiency.dexterity){dexSavingThrow = dexAbilityModifier + 2;}else{dexSavingThrow = dexAbilityModifier;};
    if(proficiency.constitution){conSavingThrow = conAbilityModifier + 2;}else{conSavingThrow = conAbilityModifier;};
    if(proficiency.wisdom){wisSavingThrow = wisAbilityModifier + 2;}else{wisSavingThrow = wisAbilityModifier;};
    if(proficiency.intelligence){intSavingThrow = intAbilityModifier + 2;}else{intSavingThrow = intAbilityModifier;};
    if(proficiency.charisma){chaSavingThrow = chaAbilityModifier + 2;}else{chaSavingThrow = chaAbilityModifier;};

    std::cout << "------------------------------------------------------------\n"
              << "| " << charName << "\n"
              << "| CHARACTER NAME\n"
              << "------------------------------------------------------------\n"
              << "| " << charOrigin << "          " << charClass << "\n"
              << "| BACKGROUND         CLASS\n"
              << "------------------------------------------------------------\n"
              << "| " << charSpecies << "\n"
              << "| SPECIES         SUBCLASS\n"
              << "------------------------------------------------------------\n"
              << "| PROFICIENCY BONUS |     | INTELLIGENCE |\n"
              << "| +2                |     | " << std::showpos << intAbilityModifier << std::noshowpos << abilityScore.intelligence << "\n"
              << "---------------------     | Modifier     Score"
              << "------------------------------------------------------------\n"
              << "|     STRENGTH      |     | "; if(proficiency.intelligence){std::cout << "[x] ";}else{std::cout << "[ ] ";} std::cout << strSavingThrow << " Saving Throw";