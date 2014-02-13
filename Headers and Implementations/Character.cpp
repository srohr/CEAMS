#include <vector>
#include <string>
#include "Character.h"

using namespace std;

void Character::CompleteItems(vector<Item> v)
{
	int i = 0, j = 0; //Iterators for each vector
	bool done = false; //Flag
	while (i < GetItems().size())
	{
		done = false; //Reset flag for new item in char items vector.
		j = 0; //Reset itr2
		while (!done && j < v.size()) 
		{
			if (GetItems()[i].GetName() == v[j].GetName()) //Find match by name
			{
				GetItems()[i] = v[j]; //Flesh out data for that item.
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
			if (GetCharSkills()[i].GetName() == v[j].GetName()) //Find match by name
			{
				GetCharSkills()[i] = v[j]; //Flesh out data for that skill.
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