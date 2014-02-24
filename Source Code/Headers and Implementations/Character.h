#include <string>
#include "Alignment.h"
#include "Race.h"
#include <vector>
#include "Item.h"
#include "Class.h"
#include "Feat.h"
#include "Skill.h"
#include "Spell.h"
#pragma once

using namespace std;

struct owns{
	string type;
	Item item;
	Weapon weapon;
	Armor armor;
};

struct SkillStruct
{
	int rank;
	Skill skill;
};

class Character
{
public:
	Character(Class, Race);

	int GetID()								{return ID;}
	void SetID_DO_NOT_USE(int i)			{ID = i;}
	bool GetIsStartingPackage()				{return isStartingPackage;}
	void SetIsStartingPackage(bool b)		{isStartingPackage = b;}
	string GetName()						{return name;}
	void SetName(string s)					{name = s;}
	string GetRace()						{return race;}
	void SetRace(string r)					{race = r;}
	string GetAlignment()					{return alignment;}
	void SetAlignment(string a)				{alignment = a;}
	string GetReligion()					{return religion;}
	void SetReligion (string s)				{religion = s;}
	vector<owns> GetOwned()					{return owned;}
	void SetOwned(vector<owns> v)			{owned = v;}
	double GetGold()						{return gold;}
	void SetGold(double i)					{gold = i;}
	int GetMaxHealth()						{return maxHealth;}
	void SetMaxHealth(int i)				{maxHealth = i;}
	int GetHealth()							{return health;}
	void SetHealth(int i)					{health = i;}
	string GetArmorClass()					{return armorClass;}
	void SetArmorClass(string s)			{armorClass = s;}
	string GetSavingThrow()					{return savingThrow;}
	void SetSavingThrow(string s)			{savingThrow = s;}
	int GetAttackBonus()					{return attackBonus;}
	void SetAttackBonus(int i)				{attackBonus = i;}
	int GetInitiative()						{return initiative;}
	void SetInitiative(int i)				{initiative = i;}
	int GetTotalSkillPoints()				{return totalSkillPoints;}
	void SetTotalSkillPoints(int i)			{totalSkillPoints = i;}
	int GetAvailableSkillPoints()			{return availableSkillPoints;}
	void SetAvailableSkillPoints(int i)		{availableSkillPoints = i;}
	string GetGender()						{return gender;}
	void SetGender(string s)				{gender = s;}
	string GetCosmetics()					{return cosmetics;}
	void SetCosmetics(string v)				{cosmetics = v;}
	int GetAge()							{return age;}
	void SetAge(int i)						{age = i;}
	string GetHeight()						{return height;}
	void SetHeight(string i)				{height = i;}
	int GetCharisma()						{return charisma;}
	void SetCharisma(int i)					{charisma = i;}
	int GetConstitution()					{return constitution;}
	void SetConstitution(int i)				{constitution = i;}
	int GetDexterity()						{return dexterity;}
	void SetDexterity(int i)				{dexterity = i;}
	int GetIntelligence()					{return intelligence;}
	void SetIntelligence(int i)				{intelligence = i;}
	int GetStrength()						{return strength;}
	void SetStrength(int i)					{strength = i;}
	int GetWisdom()							{return wisdom;}
	void SetWisdom(int i)					{wisdom = i;}

	vector<Class> GetCharClasses()			{return charClasses;}
	void SetCharClasses(vector<Class> v)	{charClasses = v;}
	vector<Feat> GetCharFeats()				{return charFeats;}
	void SetCharFeats(vector<Feat> v)		{charFeats = v;}
	vector<SkillStruct> GetCharSkills()			{return charSkills;}
	void SetCharSkills(vector<SkillStruct> v)		{charSkills = v;}
	vector<Spell> GetCharSpells()			{return charSpells;}
	void SetCharSpells(vector<Spell> v)		{charSpells = v;}
	string GetBio()							{return bio;}
	void SetBio(string s)					{bio = s;}

	void CompleteOwned(vector<Item>, vector<Armor>, vector<Weapon>);
	void CompleteFeats(vector<Feat>);
	void CompleteSkills(vector<Skill>);
	void CompleteSpells(vector<Spell>);
	void CompleteClasses(vector<Class>);
	
	int GetLevel()							{return level;}
	void SetLevel(int i)					{level = i;}
	int GetTotalExp()						{return totalExp;}
	void SetTotalExp(int i)					{totalExp = i;}

	void LevelUp();



private:
	bool isStartingPackage;
	string name;
	string race;
	string alignment;
	string religion;
	string bio;
	vector<owns> owned;

	vector<Class> charClasses;
	vector<Feat> charFeats;
	vector<SkillStruct> charSkills;
	vector<Spell> charSpells;

	int level, 
		totalExp;

	double gold;
	int maxHealth,
		health;
	string armorClass;
	string savingThrow;
	int attackBonus;
	int initiative;
	int totalSkillPoints,
		availableSkillPoints;
	string gender;
	string cosmetics;
	int age;
	string height;
	int charisma,
		constitution,
		dexterity,
		intelligence, 
		strength,
		wisdom;

	int ID;
};




