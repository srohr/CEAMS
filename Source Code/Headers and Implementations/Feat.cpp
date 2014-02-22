#include "Feat.h"
#pragma once;

using namespace std;

void Feat::CompletePrereqs(vector<Feat> v)
{
	int i = 0, j = 0; //Iterators for each vector
	bool done = false; //Flag
	while (i < GetPrereqs().size())
	{
		done = false; //Reset flag for new feat in char items vector.
		j = 0; //Reset itr2
		while (!done && j < v.size()) 
		{
			if (GetPrereqs()[i].GetName() == v[j].GetName()) //Find match by name
			{
				GetPrereqs()[i] = v[j]; //Flesh out data for that feat.
				done = true;
			}
			else 
				j++;
		}

		i++;
	}
}