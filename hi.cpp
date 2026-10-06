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
std::string getCharBackground();
std::string getCharSpecies();
std::tuple<charAbilityScore, charProficiency> getBackgroundProficiencies(charAbilityScore, charProficiency, std::string charbackground);
charProficiency getClassProficiencies(charProficiency, std::string charClass);
std::tuple<charAbilityScore> getAbilityScore(charAbilityScore);

void printCharSheet(std::string charName, std::string charSpecies, std::string charClass, std::string charbackground, charAbilityScore, charProficiency, int hitDie);


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

    std::string charbackground = getCharBackground();

    std::string charSpecies = getCharSpecies();

    std::tie(abilityScore) = getAbilityScore(abilityScore);

    std::tie(abilityScore, proficiency) = getBackgroundProficiencies(abilityScore, proficiency, charbackground);

    proficiency = getClassProficiencies(proficiency, charClass);

    std::cout << "****************************************************************\n";

    printCharSheet(charName, charSpecies, charClass, charbackground, abilityScore, proficiency, hitDie);

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

std::string getCharBackground(){
    int charbackgroundChoice;
    std::string charbackground;
    do{
        std::cout << "Select your characters background:\n"
                << "Type 1 for aberrant heir.\n"
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
                << "Type 12 for house agent\n"
                << "Type 13 for house cannith heir\n"
                << "Type 14 for house deneith heir\n"
                << "Type 15 for house ghallanda heir\n"
                << "Type 16 for house jorasco heir\n"
                << "Type 17 for house kundarak heir\n"
                << "Type 18 for house lyrandar heir\n"
                << "Type 19 for house medani heir\n"
                << "Type 20 for house orein heir\n"
                << "Type 21 for house phiarlan heir\n"
                << "Type 22 for house sivis heir\n"
                << "Type 23 for house tharashk heir\n"
                << "Type 24 for house thuranni heir\n"
                << "Type 25 for house vadalis heir\n"
                << "Type 26 for house inqisitive\n"
                << "Type 27 for merchant.\n"
                << "Type 28 for noble.\n"
                << "Type 29 for sage.\n"
                << "Type 30 for sailor.\n"
                << "Type 31 for scribe.\n"
                << "Type 32 for soldier.\n"
                << "Type 33 for wayfarer.\n";
        std::cin >> charbackgroundChoice;
        switch(charbackgroundChoice){
            case 1: charbackground = "Aberrant Heir"; break;
            case 2: charbackground = "Acolyte"; break;
            case 3: charbackground = "Archaeologist"; break;
            case 4: charbackground = "Artisan"; break;
            case 5: charbackground = "Charlatan"; break;
            case 6: charbackground = "Criminal"; break;
            case 7: charbackground = "Entertainer"; break;
            case 8: charbackground = "Farmer"; break;
            case 9: charbackground = "Guard"; break;
            case 10: charbackground = "Guide"; break;
            case 11: charbackground = "Hermit"; break;
            case 12: charbackground = "House Agent"; break;
            case 13: charbackground = "House Cannith Heir"; break;
            case 14: charbackground = "House Deneith Heir"; break;
            case 15: charbackground = "House Ghallanda Heir"; break;
            case 16: charbackground = "House Jorasco Heir"; break;
            case 17: charbackground = "House Kundarak Heir"; break;
            case 18: charbackground = "House Lyrandar Heir"; break;
            case 19: charbackground = "House Medani Heir"; break;
            case 20: charbackground = "House Orein Heir"; break;
            case 21: charbackground = "House Phiarlan Heir"; break;
            case 22: charbackground = "House Sivis Heir"; break;
            case 23: charbackground = "House Tharashk Heir"; break;
            case 24: charbackground = "House Thuranni Heir"; break;
            case 25: charbackground = "House Vadalis Heir"; break;
            case 26: charbackground = "Inquisitive"; break;
            case 27: charbackground = "Merchant"; break;
            case 28: charbackground = "Noble"; break;
            case 29: charbackground = "Sage"; break; 
            case 30: charbackground = "Sailor"; break;
            case 31: charbackground = "Scribe"; break;
            case 32: charbackground = "Soldier"; break;
            case 33: charbackground = "Wayfarer"; break;
            default: std::cout << "----------That is not a valid answer.----------\n"; break;
        }
    }while(charbackgroundChoice < 1 || charbackgroundChoice > 33);
    std::cout << "--------------------------------\n";
    return charbackground;
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
            case 2: charSpecies = "Changling"; break;
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
    std::cout << "------------Ability Scores------------\n";
    do{
        std::cout << BLUE << "You have " << pointBuyPoints << " points to spend.\n"
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
    
std::tuple<charAbilityScore, charProficiency> getBackgroundProficiencies(charAbilityScore abilityScore, charProficiency proficiency, std::string charbackground){
    if(charbackground == "Entertainer" || charbackground == "House Lyrandar Heir" || charbackground == "House Orien Heir" || charbackground == "Sailor"){proficiency.acrobatics = true;}
    if(charbackground == "House Kundarak Heir" || charbackground == "Sage"){proficiency.arcana = true;}
    if(charbackground == "Farmer" || charbackground == "House Vadalis Heir" || charbackground == "Merchant"){proficiency.animalHandling = true;}
    if(charbackground == "Guard" || charbackground == "House Orien Heir" || charbackground == "Soldier"){proficiency.athletics = true;}
    if(charbackground == "Charlatan" || charbackground == "House Phiarlan Heir"){proficiency.deception = true;}
    if(charbackground == "Aberrant Heir" || charbackground == "Arcaeologist" || charbackground == "House Sivis Heir" || charbackground == "Noble" || charbackground == "Sage"){proficiency.history= true;}
    if(charbackground == "Acolyte" || charbackground == "House Deneith Heir" || charbackground == "House Ghallanda Heir" || charbackground == "House Medani Heir" || charbackground == "Inquisitive" || charbackground == "Wayfarer"){proficiency.insight= true;}
    if(charbackground == "Aberrant Heir" || charbackground == "Soldier"){proficiency.intimidation= true;}
    if(charbackground == "Artisan" || charbackground == "House Agent" || charbackground == "House Cannith Heir" || charbackground == "House Kundarak Heir" || charbackground == "House Medani Heir" || charbackground == "Inquisitive" || charbackground == "Scribe"){proficiency.investigation= true;}
    if(charbackground == "Hermit" || charbackground == "House Jorasco Heir"){proficiency.medicine = true;}
    if(charbackground == "Farmer" || charbackground == "House Lyrandar Heir" || charbackground == "House Vadalis Heir"){proficiency.nature = true;}
    if(charbackground == "Guard" || charbackground == "House Deneith Heir" || charbackground == "House Sivis Heir" || charbackground == "House Tharashk Heir" || charbackground == "Sailor" || charbackground == "Scribe"){proficiency.perception = true;}
    if(charbackground == "Entertainer" || charbackground == "House Thuranni Heir"){proficiency.performance = true;}
    if(charbackground == "Artisan" || charbackground == "House Agent" || charbackground == "House Ghallanda Heir" || charbackground == "Merchant" || charbackground == "Noble"){proficiency.persuasion = true;}
    if(charbackground == "Acolyte" || charbackground == "Hermit"){proficiency.religion = true;}
    if(charbackground == "Charlatan" || charbackground == "Criminal" || charbackground == "House Cannith Heir"){proficiency.sleightOfHand = true;}
    if(charbackground == "Criminal" || charbackground == "Guide" || charbackground == "House Jorasco Heir" || charbackground == "House Phiarlan Heir" || charbackground == "House Thuranni Heir" || charbackground == "Wayfarer"){proficiency.stealth = true;}
    if(charbackground == "Acolyte" || charbackground == "Guide" || charbackground == "House Tharashk Heir"){proficiency.survival = true;}

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
        if((charbackground == "Aberrant Heir" || charbackground == "Artisan" || charbackground == "Entertainer" || charbackground == "Farmer" || charbackground == "Guard" || charbackground == "House Agent" || charbackground == "House Cannith Heir" || charbackground == "House Deneith Heir" || charbackground == "House Kundarak Heir" || charbackground == "House Lyrandar Heir" || charbackground == "Noble" || charbackground == "Sailor" || charbackground == "Soldier") && numOfStrIncreases < 2){std::cout << "Type 1 for strength.\n";}
        if((charbackground == "Archaeologist" || charbackground == "Artisan" || charbackground == "Charlatan" || charbackground == "Criminal" || charbackground == "Entertainer" || charbackground == "Guide" || charbackground == "House Cannith Heir" || charbackground == "House Ghallanda Heir" || charbackground == "House Jorasco Heir" || charbackground == "House Lyrandar Heir" || charbackground == "House Medani Heir" || charbackground == "House Orien Heir" || charbackground == "House Phiarlan Heir" || charbackground == "House Thuranni Heir" || charbackground == "Sailor" || charbackground == "Scribe" || charbackground == "Soldier" || charbackground == "Wayfarer") && numOfDexIncreases < 2){std::cout << "Type 2 for dexterity.\n";}
        if((charbackground == "Aberrant Heir" || charbackground == "Charlatan" || charbackground == "Criminal" || charbackground == "Farmer" || charbackground == "Guide" || charbackground == "Hermit" || charbackground == "House Deneith Heir" || charbackground == "House Jorasco Heir" || charbackground == "House Kundarak Heir" || charbackground == "House Orien Heir" || charbackground == "House Tharashk Heir" || charbackground == "House Vadalis Heir" || charbackground == "Inquisitive" || charbackground == "Merchant" || charbackground == "Sage" || charbackground == "Soldier") && numOfConIncreases < 2){std::cout << "Type 3 for constitution.\n";}
        if((charbackground == "Acolyte" || charbackground == "Archaeologist" || charbackground == "Farmer" || charbackground == "Guard" || charbackground == "Guide" || charbackground == "Hermit" || charbackground == "House Deneith Heir" || charbackground == "House Ghallanda Heir" || charbackground == "House Jorasco Heir" || charbackground == "House Medani Heir" || charbackground == "House Phiarlan Heir" || charbackground == "House Sivis Heir" || charbackground == "House Tharashk Heir" || charbackground == "House Vadalis Heir" || charbackground == "Sage" || charbackground == "Sailor" || charbackground == "Scribe" || charbackground == "Wayfarer") && numOfWisIncreases < 2){std::cout << "Type 4 for wisdom.\n";}
        if((charbackground == "Acolyte" || charbackground == "Archaeologist" || charbackground == "House Agent" || charbackground == "Artisan" || charbackground == "Criminal" || charbackground == "Guard" || charbackground == "House Agent" || charbackground == "House Cannith Heir" || charbackground == "House Kundarak Heir" || charbackground == "House Medani Heir" || charbackground == "House Orien Heir" || charbackground == "House Sivis Heir" || charbackground == "House Tharashk Heir" || charbackground == "House Thuranni Heir" || charbackground == "Inquisitive" || charbackground == "Merchant" || charbackground == "Noble" || charbackground == "Sage" || charbackground == "Scribe") && numOfIntIncreases < 2){std::cout << "Type 5 for intelligence.\n";}
        if((charbackground == "Aberrant Heir" || charbackground == "Acolyte" || charbackground == "Charlatan" || charbackground == "Entertainer" || charbackground == "Hermit" || charbackground == "House Agent" || charbackground == "House Ghallanda Heir" || charbackground == "House Lyrandar Heir" || charbackground == "House Phiarlan Heir" || charbackground == "House Sivis Heir" || charbackground == "House Thuranni Heir" || charbackground == "House Vadalis Heir" || charbackground == "Inquisitive" || charbackground == "Merchant" || charbackground == "Noble" || charbackground == "Wayfarer") && numOfChaIncreases < 2){std::cout << "Type 6 for charisma.\n";}

        std::cin >> abilityScoreInceaseChoice;
        switch(abilityScoreInceaseChoice){
            case 1: if((charbackground == "Aberrant Heir" || charbackground == "Artisan" || charbackground == "Entertainer" || charbackground == "Farmer" || charbackground == "Guard" || charbackground == "House Agent" || charbackground == "House Cannith Heir" || charbackground == "House Deneith Heir" || charbackground == "House Kundarak Heir" || charbackground == "House Lyrandar Heir" || charbackground == "Noble" || charbackground == "Sailor" || charbackground == "Soldier") && numOfStrIncreases < 2){numOfStrIncreases++; abilityScoreInceaseTimes++;} break;
            case 2: if((charbackground == "Archaeologist" || charbackground == "Artisan" || charbackground == "Charlatan" || charbackground == "Criminal" || charbackground == "Entertainer" || charbackground == "Guide" || charbackground == "House Cannith Heir" || charbackground == "House Ghallanda Heir" || charbackground == "House Jorasco Heir" || charbackground == "House Lyrandar Heir" || charbackground == "House Medani Heir" || charbackground == "House Orien Heir" || charbackground == "House Phiarlan Heir" || charbackground == "House Thuranni Heir" || charbackground == "Sailor" || charbackground == "Scribe" || charbackground == "Soldier" || charbackground == "Wayfarer") && numOfDexIncreases < 2){numOfDexIncreases++; abilityScoreInceaseTimes++;} break;
            case 3: if((charbackground == "Aberrant Heir" || charbackground == "Charlatan" || charbackground == "Criminal" || charbackground == "Farmer" || charbackground == "Guide" || charbackground == "Hermit" || charbackground == "House Deneith Heir" || charbackground == "House Jorasco Heir" || charbackground == "House Kundarak Heir" || charbackground == "House Orien Heir" || charbackground == "House Tharashk Heir" || charbackground == "House Vadalis Heir" || charbackground == "Inquisitive" || charbackground == "Merchant" || charbackground == "Sage" || charbackground == "Soldier") && numOfConIncreases < 2){numOfConIncreases++; abilityScoreInceaseTimes++;} break;
            case 4: if((charbackground == "Acolyte" || charbackground == "Archaeologist" || charbackground == "Farmer" || charbackground == "Guard" || charbackground == "Guide" || charbackground == "Hermit" || charbackground == "House Deneith Heir" || charbackground == "House Ghallanda Heir" || charbackground == "House Jorasco Heir" || charbackground == "House Medani Heir" || charbackground == "House Phiarlan Heir" || charbackground == "House Sivis Heir" || charbackground == "House Tharashk Heir" || charbackground == "House Vadalis Heir" || charbackground == "Sage" || charbackground == "Sailor" || charbackground == "Scribe" || charbackground == "Wayfarer") && numOfWisIncreases < 2){numOfWisIncreases++; abilityScoreInceaseTimes++;} break;
            case 5: if((charbackground == "Acolyte" || charbackground == "Archaeologist" || charbackground == "House Agent" || charbackground == "Artisan" || charbackground == "Criminal" || charbackground == "Guard" || charbackground == "House Agent" || charbackground == "House Cannith Heir" || charbackground == "House Kundarak Heir" || charbackground == "House Medani Heir" || charbackground == "House Orien Heir" || charbackground == "House Sivis Heir" || charbackground == "House Tharashk Heir" || charbackground == "House Thuranni Heir" || charbackground == "Inquisitive" || charbackground == "Merchant" || charbackground == "Noble" || charbackground == "Sage" || charbackground == "Scribe") && numOfIntIncreases < 2){numOfIntIncreases++; abilityScoreInceaseTimes++;} break;
            case 6: if((charbackground == "Aberrant Heir" || charbackground == "Acolyte" || charbackground == "Charlatan" || charbackground == "Entertainer" || charbackground == "Hermit" || charbackground == "House Agent" || charbackground == "House Ghallanda Heir" || charbackground == "House Lyrandar Heir" || charbackground == "House Phiarlan Heir" || charbackground == "House Sivis Heir" || charbackground == "House Thuranni Heir" || charbackground == "House Vadalis Heir" || charbackground == "Inquisitive" || charbackground == "Merchant" || charbackground == "Noble" || charbackground == "Wayfarer") && numOfChaIncreases < 2){numOfChaIncreases++; abilityScoreInceaseTimes++;} break;
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

void printCharSheet(std::string charName, std::string charSpecies, std::string charClass, std::string charbackground, charAbilityScore abilityScore, charProficiency proficiency, int hitDie){
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

    int armorClass = 10 + dexAbilityModifier;

    int hitPointMax = hitDie + conAbilityModifier;

    int charSpeed = 30;
    if(charSpecies == "Goliath"){charSpeed = 35;}

    std::string charSize = "Medium";
    if(charSpecies == "Aasimar" || charSpecies == "Human" || charSpecies == "Tiefling"){
        int sizeChoice = 0;
        do{
            std::cout << "Select your character's size:\n"
                    << "Type 1 for medium.\n"
                    << "Type 2 for small.\n";
            std::cin >> sizeChoice;
            switch(sizeChoice){
                case 1: charSize = "Medium"; break;
                case 2: charSize = "Small"; break;
                default: std::cout << "----------That is not a valid answer.----------\n"; continue; break;
            }
        }while(sizeChoice < 1 || sizeChoice > 2);
    }
    if(charSpecies == "Gnome" || charSpecies == "Halfling"){charSize = "Small";}

    int passivePerception = 10 + wisAbilityModifier;
    if(proficiency.perception){passivePerception + 2;}

    std::cout << "------------------------------------------------------------\n"
              << "| Name: " << charName << "\n"
              << "| Background: " << charbackground << "\n"
              << "| Class: " << charClass << "\n"
              << "| Species: " << charSpecies << "\n"
              << "|-----------------------------------------------------------\n"
              << "| Level: 1\n"
              << "|-----------------------------------------------------------\n"
              << "| Armor Class: " << armorClass << "\n"
              << "|-----------------------------------------------------------\n"
              << "| Hit Point Max: " << hitPointMax << "\n"
              << "| Hit Dice Max: 1d" << hitDie << "\n"
              << "|-----------------------------------------------------------\n"
              << "| Initiative: " << std::showpos << dexAbilityModifier << std::noshowpos << "\n"
              << "|-----------------------------------------------------------\n"
              << "| Speed: " << charSpeed << "ft\n"
              << "|-----------------------------------------------------------\n"
              << "| Size: " << charSize << "\n"
              << "|-----------------------------------------------------------\n"
              << "| Passive Perception: " << passivePerception << "\n"
              << "|-----------------------------------------------------------\n"
              << "| Proficiency Bonus: +2\n"
              << "|-----------------------------------------------------------\n"
              << "| Strength\n" 
              << "| Modifier: " << std::showpos << strAbilityModifier << std::noshowpos <<"\n"
              << "| Score: " << abilityScore.strength << "\n" << std::showpos;
              if(proficiency.strength){std::cout << "| [x] Saving Throw: " << strAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Saving Throw: " << strAbilityModifier << "\n";}
              if(proficiency.athletics){std::cout << "| [x] Athletics: " << strAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Athletics: " << strAbilityModifier << "\n";}
              std:: cout << "|-----------------------------------------------------------\n"
              << BLUE <<"| Dexterity\n" << RESET
              << "| Modifier: " << dexAbilityModifier << std::noshowpos << "\n"
              << "| Score: " << abilityScore.dexterity << "\n" << std::showpos;
              if(proficiency.dexterity){std::cout << "| [x] Saving Throw: " << dexAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Saving Throw: " << dexAbilityModifier << "\n";}
              if(proficiency.acrobatics){std::cout << "| [x] Acrobatics: " << dexAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Acrobatics: " << dexAbilityModifier << "\n";}
              if(proficiency.sleightOfHand){std::cout << "| [x] Sleight of Hand: " << dexAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Sleight of Hand: " << dexAbilityModifier << "\n";}
              if(proficiency.stealth){std::cout << "| [x] Stealth: " << dexAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Stealth: " << dexAbilityModifier << "\n";}
              std:: cout << "|-----------------------------------------------------------\n"
              << BLUE << "| Constitution\n" << RESET
              << "| Modifier: " << conAbilityModifier << std::noshowpos << "\n"
              << "| Score: " << abilityScore.constitution << "\n" << std::showpos;
              if(proficiency.constitution){std::cout << "| [x] Saving Throw: " << conAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Saving Throw: " << conAbilityModifier << "\n";}
             std:: cout  << "|-----------------------------------------------------------\n"
              << BLUE << "| Intelligence\n" << RESET
              << "| Modifier: " << intAbilityModifier << std::noshowpos << "\n"
              << "| Score: " << abilityScore.intelligence << "\n" << std::showpos;
              if(proficiency.intelligence){std::cout << "| [x] Saving Throw: " << intAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Saving Throw: " << intAbilityModifier << "\n";}
              if(proficiency.arcana){std::cout << "| [x] Arcana: " << intAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Arcana: " << intAbilityModifier << "\n";}
              if(proficiency.history){std::cout << "| [x] History: " << intAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] History: " << intAbilityModifier << "\n";}
              if(proficiency.investigation){std::cout << "| [x] Investigation: " << intAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Investigation: " << intAbilityModifier << "\n";}
              if(proficiency.nature){std::cout << "| [x] Nature: " << intAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Nature: " << intAbilityModifier << "\n";}
              if(proficiency.religion){std::cout << "| [x] Religion: " << intAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Religion: " << intAbilityModifier << "\n";}
              std:: cout << "|-----------------------------------------------------------\n"
              << BLUE << "| Wisdom\n" << RESET
              << "| Modifier: " << wisAbilityModifier << std::noshowpos << "\n"
              << "| Score: " << abilityScore.wisdom << "\n" << std::showpos;
              if(proficiency.wisdom){std::cout << "| [x] Saving Throw: " << wisAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Saving Throw: " << wisAbilityModifier << "\n";}
              if(proficiency.animalHandling){std::cout << "| [x] Animal Handling: " << wisAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Animal Handling: " << wisAbilityModifier << "\n";}
              if(proficiency.insight){std::cout << "| [x] Insight: " << wisAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Insight: " << wisAbilityModifier << "\n";}
              if(proficiency.medicine){std::cout << "| [x] Medicine: " << wisAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Medicine: " << wisAbilityModifier << "\n";}
              if(proficiency.perception){std::cout << "| [x] Perception: " << wisAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Perception: " << wisAbilityModifier << "\n";}
              if(proficiency.survival){std::cout << "| [x] Survival: " << wisAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Survival: " << wisAbilityModifier << "\n";}
              std:: cout << "|-----------------------------------------------------------\n"
              << BLUE << "| Charisma\n" << RESET
              << "| Modifier: " << chaAbilityModifier << std::noshowpos << "\n"
              << "| Score: " << abilityScore.charisma << "\n" << std::showpos;
              if(proficiency.charisma){std::cout << "| [x] Saving Throw: " << chaAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Saving Throw: " << chaAbilityModifier << "\n";}
              if(proficiency.deception){std::cout << "| [x] Deception: " << chaAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Deception: " << chaAbilityModifier << "\n";}
              if(proficiency.intimidation){std::cout << "| [x] Intimidation: " << chaAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Intimidation: " << chaAbilityModifier << "\n";}
              if(proficiency.performance){std::cout << "| [x] Performance: " << chaAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Performance: " << chaAbilityModifier << "\n";}
              if(proficiency.persuasion){std::cout << "| [x] Persuasion: " << chaAbilityModifier + 2 << "\n";}else{std::cout << "| [ ] Persuasion: " << chaAbilityModifier << "\n";}
              std::cout << "|-----------------------------------------------------------\n";
}