#include <string>
#include <vector>
#include "Spell.h"
#pragma once

using namespace std;

struct LearnsSpells
{
	string className;
	Spell s;
	int level;
};

struct feature{
	string featureName,
		featureDescription;
};

struct baseSave{
	int level,
		fortificationSave,
		reflexSave,
		willSave;
	string baseAttack,
		special;
};

class Class
{
public:
	string GetName()								{return name;}
	void SetName(string s)							{name = s;}
	string GetDescription()							{return description;}
	void SetDescription(string s)					{description = s;}
	int GetCharismaMod()							{return charismaMod;}
	void SetCharismaMod(int i)						{charismaMod = i;}
	int GetConstitutionMod()						{return constitutionMod;}
	void SetConstitutionMod(int i)					{constitutionMod = i;}
	int GetDexterityMod()							{return dexterityMod;}
	void SetDexterityMod(int i)						{dexterityMod = i;}
	int GetIntelligenceMod()						{return intelligenceMod;}
	void SetIntelligenceMod(int i)					{intelligenceMod = i;}
	int GetStrengthMod()							{return strengthMod;}
	void SetStrengthMod(int i)						{strengthMod = i;}
	int GetWisdomMod()								{return wisdomMod;}
	void SetWisdomMod(int i)						{wisdomMod = i;}
	string GetStartingGold()						{return startingGold;}
	void SetStartingGold(string i)					{startingGold = i;}
	string GetHitDie()								{return hitDie;}
	void SetHitDie(string s)						{hitDie = s;}
	vector<baseSave> GetBaseSaves()					{return baseSaves;}
	void SetBaseSaves(vector<baseSave> v)			{baseSaves = v;}
	vector<feature> GetFeatures()					{return features;}
	void SetFeatures(vector<feature> v)				{features = v;}
	void AddFeature(feature f)						{features.push_back(f);}
	//vector<Character> GetStartingPackages()		{return startingPackages;}
	//void SetStartingPackages(vector<Character> v)	{startingPackages = v;}
	string GetReccomendedAlignments()				{return reccomendedAlignments;}
	void SetReccomendedAlignments(string v)			{reccomendedAlignments = v;}
	vector<LearnsSpells> GetSpellsCanLearn()		{return spellsCanLearn;}
	void SetSpellsCanLearn(vector<LearnsSpells> v)	{spellsCanLearn = v;}

	void CompleteSpellsCanLearn(vector<Spell>);

private:
	string name;
	string description;
	int charismaMod,
		constitutionMod,
		dexterityMod,
		intelligenceMod, 
		strengthMod,
		wisdomMod;
	string startingGold,
		hitDie;
	vector<feature> features; 
	//vector<Character> startingPackages;
	string reccomendedAlignments;
	vector<baseSave> baseSaves;
	vector<LearnsSpells> spellsCanLearn;
};

