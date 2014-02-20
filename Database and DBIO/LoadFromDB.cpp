#include "DBIO.h"
#include <iostream>
#include <time.h>
#include <vector>
#pragma once

using namespace std;

int main()
{
	clock_t t1, t2;

	vector<Alignment> *al_V;
	vector<Armor> *ar_V;
	vector<Character> *ch_V;
	vector<Class> *cl_V;
	vector<Feat> *fe_V;
	vector<Item> *it_V;
	vector<Race> *ra_V;
	//vector<Religion> *re_V;
	vector<Skill> *sk_V;
	vector<Spell> *sp_V;
	vector<Weapon> *we_V;


	t1 = clock();

	al_V = LoadAlignments();
	ar_V = LoadArmors();
	ch_V = LoadCharacters();
	cl_V = LoadClasses();
	fe_V = LoadFeats();
	it_V = LoadItems();
	ra_V = LoadRaces();
	//re_V = LoadReligions();
	sk_V = LoadSkills();
	sp_V = LoadSpells();
	we_V = LoadWeapons();
	
	t2 = clock();
	cout << "To load: " << (double)(t2 - t1)/CLOCKS_PER_SEC << "s" << endl;
	
	if (al_V == NULL)
		cout << "Alignment bad" << endl;
	if (ar_V == NULL)
		cout << "Armor bad" << endl;
	if (ch_V == NULL)
		cout << "Character bad" << endl;
	if (cl_V == NULL)
		cout << "Class bad" << endl;
	if (fe_V == NULL)
		cout << "Feat bad" << endl;
	if (it_V == NULL)
		cout << "Item bad" << endl;
	if (ra_V == NULL)
		cout << "Race bad" << endl;
	//if (re_V == NULL)
		//cout << "Religion bad" << endl;
	if (sk_V == NULL)
		cout << "Skill bad" << endl;
	if (sp_V == NULL)
		cout << "Spell bad" << endl;
	if (we_V == NULL)
		cout << "Weapon bad" << endl;
		
	

	t1 = clock();

	vector<Character>::iterator itr = ch_V->begin();
	while (itr != ch_V->end())
	{
		itr->CompleteClasses(*cl_V);
		itr->CompleteFeats(*fe_V);
		itr->CompleteOwned(*it_V, *ar_V, *we_V);
		itr->CompleteSkills(*sk_V);
		itr->CompleteSpells(*sp_V);
		itr++;
	
	}

	vector<Class>::iterator itr2 = cl_V->begin();
	while (itr2 != cl_V->end())
	{
		itr2->CompleteSpellsCanLearn(*sp_V);
		itr2++;
	}

	vector<Feat>::iterator itr3 = fe_V->begin();
	while (itr3 != fe_V->end())
	{
		itr3->CompletePrereqs(*fe_V);
		itr3++;
	}

	t2 = clock();

	cout << "To complete: " << (double)(t2 - t1)/CLOCKS_PER_SEC << "s" << endl;

	cin.ignore();
	return 0;

	
}