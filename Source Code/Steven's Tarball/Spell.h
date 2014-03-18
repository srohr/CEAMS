#include <string>
#include <vector>
#pragma once

using namespace std;


class Spell
{
public:
	string GetName()						{return name;}
	void SetName(string s)					{name = s;}
	string GetType()						{return type;}
	void SetType (string s)					{type = s;}
	string GetSavingThrow()					{return savingThrow;}
	void SetSavingThrow(string s)			{savingThrow = s;}
	string GetSpellResistance()				{return spellResistance;}
	void SetSpellResistance(string s)		{spellResistance = s;}
	string GetEffect()						{return effect;}
	void SetEffect(string s)				{effect = s;}
	string GetCastingTime()					{return castingTime;}
	void SetCastingTime(string s)			{castingTime = s;}
	string GetRange()						{return range;}
	void SetRange(string s)					{range = s;}
	string GetTarget()						{return target;}
	void SetTarget(string s)				{target = s;}
	string GetDuration()					{return duration;}
	void SetDuration(string s)				{duration = s;}
	string GetDescription()					{return description;}
	void SetDescription(string s)			{description = s;}
	string GetComponents()					{return components;}
	void SetComponenets(string s)			{components = s;}
	


private:
	string name,
		type,
		savingThrow,
		spellResistance,
		effect,
		castingTime,
		range,
		target,
		duration,
		description,
		
		components; 

};	
