#include <string>
#pragma once

using namespace std;

class Item
{
public:
	string GetName()						{return name;}
	void SetName(string s)					{name = s;}
	string GetDescription()					{return description;}
	void SetDescription(string s)			{description = s;}
    string GetCost()						{return cost;}
	void SetCost(string i)					{cost = i;}
	string GetWeight()						{return weight;}
	void SetWeight(string i)				{weight = i;}
	void SetType(string s)					{type = s;}
	string GetType()						{return type;}
private:
	string name,
		description,
		type;
	string cost,
		weight;

};

class Armor : public Item
{
public:
	string GetSpeedHuman()					{return speedHuman;}
	void SetSpeedHuman(string i)			{speedHuman = i;}
	string GetSpeedDwarf()					{return speedDwarf;}
	void SetSpeedDwarf(string i)			{speedDwarf = i;}
	string GetMaxDexBonus()					{return maxDexBonus;}
	void SetMaxDexBonus(string i)			{maxDexBonus = i;}
	string GetArcaneSpellFailure()			{return arcaneSpellFailure;}
	void SetArcaneSpellFailure(string d)	{arcaneSpellFailure = d;}
	string GetArmorCheckPenalty()			{return armorCheckPenalty;}
	void SetArmorCheckPenalty(string s)		{armorCheckPenalty = s;}
	string GetArmorBonus()					{return armorBonus;}
	void SetArmorBonus(string s)			{armorBonus = s;}
	string GetDon()							{return don;}
	void SetDon(string s)					{don = s;}
	string GetDonHastely()					{return donHastely;}
	void SetDonHastely(string s)			{donHastely = s;}
	string GetRemove()						{return remove;}
	void SetRemove(string s)				{remove = s;}

	
private:
	string speedHuman,
		speedDwarf,
		maxDexBonus;
	string arcaneSpellFailure;

	string armorCheckPenalty,
		armorBonus,
		don,
		donHastely,
		remove;

};

class Weapon : public Item
{
public:
	string GetWeaponType()					{return weaponType;}
	void SetWeaponType(string s)			{weaponType = s;}
	string GetProficiency()					{return proficiency;}
	void SetProficiency(string s)			{proficiency = s;}
	string GetRange()						{return range;}
	void SetRange(string s)					{range = s;}
	string GetSize()						{return size;}
	void SetSize(string s)					{size = s;}
	string GetCritical()					{return critical;}
	void SetCritical(string s)				{critical = s;}
	string GetDamage()						{return damage;}
	void SetDamage(string s)				{damage = s;}
	string GetSpecial()						{return special;}
	void SetSpecial(string s)				{special = s;}
	string GetHands()						{return hands;}
	void SetHands(string s)					{hands = s;}

	



private:
	string weaponType;

	string proficiency,
		range,
		size,
		critical,
		damage,
		special,
		hands;
};
