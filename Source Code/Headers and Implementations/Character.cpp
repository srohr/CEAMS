#include <vector>
#include <string>
#include "Character.h"
#include "ddmath.h"

#pragma once;

using namespace std;

Character::Character(Class c, Race r, vector<Character> chars)
{
	ID = chars.size(); //Should cause this char's ID to be next int. 

	charClasses.push_back(c);
	race = r.GetRaceName();

	charisma = 0 + r.GetCharismaMod();
	constitution = 0 + r.GetConstitutionMod();
	dexterity = 0 + r.GetDexterityMod();
	intelligence = 0 + r.GetIntelligenceMod();
	strength = 0 + r.GetDexterityMod();
	wisdom = 0 + r.GetWisdomMod();

	level = 1;
	totalExp = 0;
	
	availableSkillPoints = GetPoints(c.GetFirstLevelUpPoints(), intelligence);

	totalSkillPoints = availableSkillPoints;

	gold = Roll(c.GetStartingGold());

	chars.push_back(*this);
}

void Character::LevelUp()
{
	int x = GetPoints(charClasses.begin()->GetLevelUpPoints(), intelligence);
	availableSkillPoints += x;
	totalSkillPoints += x;
}

void Character::CompleteOwned(vector<Item> it, vector<Armor> ar, vector<Weapon> we)
{
	int i = 0, j = 0; //Iterators for each vector
	bool done = false; //Flag
	int maxSize;

	if (it.size() > ar.size())
	{
		if (it.size() > we.size())
			maxSize = it.size();
		else
			maxSize = we.size();
	}
	else
	{
		if (ar.size() > we.size())
			maxSize = ar.size();
		else
			maxSize = we.size();
	}

	while (i < GetOwned().size())
	{
		done = false; 
		j = 0; 

		while (j < maxSize) 
		{
			if (GetOwned()[i].type == "Armor" && GetOwned()[i].armor.GetName() == ar[j].GetName()) 
			{
				GetOwned()[i].armor = ar[j]; 
				done = true;
			}
			else if (GetOwned()[i].type == "Item" && GetOwned()[i].item.GetName() == it[j].GetName())
			{
				GetOwned()[i].item = it[j];
				done = true;
			}
			else if (GetOwned()[i].type == "Weapon" && GetOwned()[i].weapon.GetName() == we[j].GetName())
			{
				GetOwned()[i].weapon = we[j];
				done = true;
			}
			else
				j++;
		}

		i++;
	}
}

void Character::CompleteFeats(vector<Feat> v)
{
	int i = 0, j = 0; //Iterators for each vector
	bool done = false; //Flag
	while (i < GetCharFeats().size())
	{
		done = false; //Reset flag for new feat in char items vector.
		j = 0; //Reset itr2
		while (!done && j < v.size()) 
		{
			if (GetCharFeats()[i].GetName() == v[j].GetName()) //Find match by name
			{
				GetCharFeats()[i] = v[j]; //Flesh out data for that feat.
				done = true;
			}
			else 
				j++;
		}

		i++;
	}
}

void Character::CompleteSkills(vector<Skill> v)
{
	int i = 0, j = 0; //Iterators for each vector
	bool done = false; //Flag
	while (i < GetCharSkills().size())
	{
		done = false; //Reset flag for new item in char skills vector.
		j = 0; //Reset itr2
		while (!done && j < v.size()) 
		{
			if (GetCharSkills()[i].skill.GetName() == v[j].GetName()) //Find match by name
			{
				GetCharSkills()[i].skill = v[j]; //Flesh out data for that skill.
				done = true;
			}
			else 
				j++;
		}

		i++;
	}	
}

void Character::CompleteSpells(vector<Spell> v)
{
	int i = 0, j = 0; //Iterators for each vector
	bool done = false; //Flag
	while (i < GetCharSpells().size())
	{
		done = false; //Reset flag for new spell in char items vector.
		j = 0; //Reset itr2
		while (!done && j < v.size()) 
		{
			if (GetCharSpells()[i].GetName() == v[j].GetName()) //Find match by name
			{
				GetCharSpells()[i] = v[j]; //Flesh out data for that spell.
				done = true;
			}
			else 
				j++;
		}

		i++;
	}
}

void Character::CompleteClasses(vector<Class> v)
{
	int i = 0, j = 0; //Iterators for each vector
	bool done = false; //Flag
	while (i < GetCharClasses().size())
	{
		done = false; //Reset flag for new item in char items vector.
		j = 0; //Reset itr2
		while (!done && j < v.size()) 
		{
			if (GetCharClasses()[i].GetName() == v[j].GetName()) //Find match by name
			{
				GetCharClasses()[i] = v[j]; //Flesh out data for that item.
				done = true;
			}
			else 
				j++;
		}

		i++;
	}
}