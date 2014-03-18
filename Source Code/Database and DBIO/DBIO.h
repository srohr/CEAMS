#include "Character.h"
#include "Feat.h"
#include "Item.h"
#include "Skill.h"
#include "Religion.h"
#include "Race.h"
#include "Spell.h"
#include "Class.h"
#include "sqlite3.h"
#pragma once

using namespace std;

struct learnedBy
{
	string c,
		s;
	int l;
};

struct DBLS
{
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

	bool loadedOkay;
};

DBLS DBLoad();



bool AddToCEAMS (Spell);
bool RemoveFromCEAMS (Spell);
vector<Spell>* LoadSpells();

bool AddToCEAMS (Race);
bool RemoveFromCEAMS (Race);
vector<Race>* LoadRaces();

bool AddToCEAMS (Class);
bool RemoveFromCEAMS (Class);
vector<Class>* LoadClasses();

bool AddToCEAMS (Feat);
bool RemoveFromCEAMS (Feat);
vector<Feat>* LoadFeats();

bool AddToCEAMS (Item);
bool RemoveFromCEAMS (Item);
vector<Item>* LoadItems();

bool AddToCEAMS (Weapon);
bool RemoveFromCEAMS (Weapon);
vector<Weapon>* LoadWeapons();

bool AddToCEAMS (Armor);
bool RemoveFromCEAMS (Armor);
vector<Armor>* LoadArmors();

bool AddToCEAMS (Skill);
bool RemoveFromCEAMS (Skill);
vector<Skill>* LoadSkills();

bool AddToCEAMS (Alignment);
bool RemoveFromCEAMS (Alignment);
vector<Alignment>* LoadAlignments();

bool AddToCEAMS(Race);
bool RemoveFromCEAMS(Race);
vector<Race>* LoadRaces();

bool AddToCEAMS(Religion);
bool RemoveFromCEAMS(Religion);
vector<Religion>* LoadReligions();

bool AddToCEAMS(Character);
bool RemoveFromCeams(Character);
bool Save(Character);
vector<Character>* LoadCharacters();

bool AddToCEAMS(learnedBy);

/*
vector<Spell>* LoadSpells();
vector<Spell>* LoadSpells(string);

vector<Race>* LoadRaces();
vector<Race>* LoadRaces(string);

vector<Class>* LoadClasses();
vector<Class>* LoadClasses(string);

vector<Feat>* LoadFeats();
vector<Feat>* LoadFeats(string);

vector<Item>* LoadItems();
vector<Item>* LoadItems(string);

vector<Weapon>* LoadWeapons();
vector<Weapon>* LoadWeapons(string);

vector<Armor>* LoadArmors();
vector<Armor>* LoadArmors(string);

vector<Skill>* LoadSkills();
vector<Skill>* LoadSkills(string);

vector<Character>* LoadCharacters();
vector<Character>* LoadCharacters(string);
*/




