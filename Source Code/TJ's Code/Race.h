#include <string>
#include <vector>
#pragma once

using namespace std;

class Race
{
public:
	string GetRaceName()							{return raceName;}
	void SetRaceName(string s)						{raceName = s;}
	vector<string> GetLanguages()					{return languages;}
	void SetLanguages(vector<string> v)				{languages = v;}
	string GetPhysic()								{return physic;}
	void SetPhysic(string s)						{physic = s;}
	string GetSize()								{return size;}
	void SetSize(string s)							{size = s;}
	string GetSpeed()								{return speed;}
	void SetSpeed(string s)							{speed = s;}
	string GetReccomendedClass()					{return reccomendedClass;}
	void SetReccomendedClass(string v)				{reccomendedClass = v;}
	vector<string> GetRacialTraits()				{return racialTraits;}
	void SetRacialTraits(vector<string> v)			{racialTraits = v;}
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

private:
	string raceName;
	vector<string> languages;
	string physic;
	string speed;
	string size;
	string reccomendedClass; 
	vector<string> racialTraits;  
	int charismaMod,
		constitutionMod,
		dexterityMod,
		intelligenceMod, 
		strengthMod,
		wisdomMod;
};