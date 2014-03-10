#include "DBIO.h"
//#include <iostream>
//#include <time.h>
#include <vector>
#pragma once

using namespace std;

struct DBLS
{
	bool noErrors;
	vector<Alignment> *alignment_V;
	vector<Armor> *armor_V;
	vector<Character> *character_V;
	vector<Class> *class_V;
	vector<Feat> *feat_V;
	vector<Item> *item_V;
	vector<Race> *race_V;
	//vector<Religion> *religion_V;
	vector<Skill> *skill_V;
	vector<Spell> *spell_V;
	vector<Weapon> *weapon_V;

};

DBLS DBLoad()
{
	//clock_t t1, t2;

	
	DBLS LS;

	//t1 = clock();

	LS.alignment_V = LoadAlignments();
	LS.armor_V = LoadArmors();
	LS.character_V = LoadCharacters();
	LS.class_V = LoadClasses();
	LS.feat_V = LoadFeats();
	LS.item_V = LoadItems();
	LS.race_V = LoadRaces();
	//LS.religion_V = LoadReligions();
	LS.skill_V = LoadSkills();
	LS.spell_V = LoadSpells();
	LS.weapon_V = LoadWeapons();
	
	//t2 = clock();
	//cout << "To load: " << (double)(t2 - t1)/CLOCKS_PER_SEC << "s" << endl;
	
	LS.noErrors = true;
	
	if (LS.alignment_V == NULL)
		LS.noErrors = false;
	if (LS.armor_V == NULL)
		LS.noErrors = false;
	if (LS.character_V == NULL)
		LS.noErrors = false;
	if (LS.class_V == NULL)
		LS.noErrors = false;
	if (LS.feat_V == NULL)
		LS.noErrors = false;
	if (LS.item_V == NULL)
		LS.noErrors = false;
	if (LS.race_V == NULL)
		LS.noErrors = false;
	if (LS.skill_V == NULL)
		LS.noErrors = false;
	if (LS.spell_V == NULL)
		LS.noErrors = false;
	if (LS.weapon_V == NULL)
		LS.noErrors = false;
	
	//t1 = clock();

	vector<Character>::iterator itr = LS.character_V->begin();
	while (itr != LS.character_V->end())
	{
		itr->CompleteClasses(*LS.class_V);
		itr->CompleteFeats(*LS.feat_V);
		itr->CompleteOwned(*LS.item_V, *LS.armor_V, *LS.weapon_V);
		itr->CompleteSkills(*LS.skill_V);
		itr->CompleteSpells(*LS.spell_V);
		itr++;
	}

	vector<Class>::iterator itr2 = LS.class_V->begin();
	while (itr2 != LS.class_V->end())
	{
		itr2->CompleteSpellsCanLearn(*LS.spell_V);
		itr2++;
	}

	vector<Feat>::iterator itr3 = LS.feat_V->begin();
	while (itr3 != LS.feat_V->end())
	{
		itr3->CompletePrereqs(*LS.feat_V);
		itr3++;
	}

	/*
	t2 = clock();

	cout << "To complete all fields: " << (double)(t2 - t1)/CLOCKS_PER_SEC << "s" << endl << endl;

	cout << "Number of items loaded: " << endl
		<< "Spells: " << LS.spell_V->size() << endl
		<< "Classes: " << LS.class_V->size() << endl
		<< "Feats: " << LS.feat_V->size() << endl
		<< "Skills: " << LS.skill_V->size() << endl
		<< endl
		<< "Per class spells:" << endl;
		
		itr2 = LS.class_V->begin();
		cout << "Barbarian: "	<< itr2->GetSpellsCanLearn().size()		<< endl; itr2++;
		cout << "Bard: "		<< itr2->GetSpellsCanLearn().size()		<< endl; itr2++;
		cout << "Cleric: "		<< itr2->GetSpellsCanLearn().size()		<< endl; itr2++;
		cout << "Druid: "		<< itr2->GetSpellsCanLearn().size()		<< endl; itr2++;
		cout << "Fighter: "		<< itr2->GetSpellsCanLearn().size()		<< endl; itr2++;
		cout << "Monk: "		<< itr2->GetSpellsCanLearn().size()		<< endl; itr2++;
		cout << "Paladin: "		<< itr2->GetSpellsCanLearn().size()		<< endl; itr2++;
		cout << "Ranger: "		<< itr2->GetSpellsCanLearn().size()		<< endl; itr2++;
		cout << "Rogue: "		<< itr2->GetSpellsCanLearn().size()		<< endl; itr2++;
		cout << "Sorcerer: "	<< itr2->GetSpellsCanLearn().size()		<< endl; itr2++;
		cout << "Wizard: "		<< itr2->GetSpellsCanLearn().size()		<< endl; itr2++;

	cin.ignore();*/
	return LS;

	
}