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
	int GetCost()							{return cost;}
	void SetCost(int i)						{cost = i;}
	int GetWeight()							{return weight;}
	void SetWeight(int i)					{weight = i;}
	void SetType(string s)					{type = s;}
	string GetType()						{return type;}
private:
	string name,
		description,
		type;
	int cost,
		weight;

};

class Armor : public Item
{
public:
	int GetSpeedHuman()						{return speedHuman;}
	void SetSpeedHuman(int i)				{speedHuman = i;}
	int GetSpeedDwarf()						{return speedDwarf;}
	void SetSpeedDwarf(int i)				{speedDwarf = i;}
	int GetMaxDexBonus()					{return maxDexBonus;}
	void SetMaxDexBonus(int i)				{maxDexBonus = i;}
	double GetArcaneSpellFailure()			{return arcaneSpellFailure;}
	void SetArcaneSpellFailure(double d)	{arcaneSpellFailure = d;}
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
	string GetType()						{return type;}
	void SetType(string s)					{type = s;}
	
private:
	int speedHuman,
		speedDwarf,
		maxDexBonus;
	double arcaneSpellFailure;

	string armorCheckPenalty,
		armorBonus,
		don,
		donHastely,
		remove,
		type;
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