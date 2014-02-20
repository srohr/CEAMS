#include "Class.h"
#include "Spell.h"
#pragma once

using namespace std;


void Class::CompleteSpellsCanLearn(vector<Spell> v)
{
	int i = 0, j = 0; //Iterators for each vector
	bool done = false; //Flag
	
	while (i < spellsCanLearn.size())
	{
		done = false; //Reset flag for new feat in char items vector.
		j = 0; //Reset itr2
		while (!done && j < v.size()) 
		{
			if (spellsCanLearn[i].s.GetName() == v[j].GetName()) //Find match by name
			{
				spellsCanLearn[i].s = v[j]; //Flesh out data for that feat.
				done = true;
			}
			else 
				j++;
		}

		i++;
	}
}