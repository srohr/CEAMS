#include "Character.h"
#include "Feat.h"
#include "Item.h"
#include "Skill.h"
#include "Spell.h"
#include "DBIO.h"
#include "sqlite3.h"
#include "Race.h"
#include "Religion.h"
#include "Alignment.h"
#include "Class.h"
#include <iostream>
#include <vector>
#pragma once

using namespace std;

const string dbNameString = "CEAMS.db3";	
const char* dbName = dbNameString.c_str();
char *zErrMsg = 0;
sqlite3 *db; //DB object, used to manipulate DB.
int rc = sqlite3_open(dbName, &db); //Connect to DB.

//This comment serves no purpose other than to alter the file.

vector<Spell> spells_V; //Global vectors to store values. 
vector<Skill> skills_V;
vector<Class> classes_V;
vector<Race> races_V;
vector<Item> items_V;
vector<Armor> armors_V;
vector<Weapon> weapons_V;
vector<Feat> feats_V;
vector<Character> characters_V;
vector<Alignment> alignments_V;
vector<Religion> religions_V;

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

static int callback_spell(void *NotUsed, int argc, char **argv, char **azColName){
	Spell s;

	s.SetName(argv[0]);				
	s.SetType(argv[1]);			
	s.SetSavingThrow(argv[2]);		
	s.SetSpellResistance(argv[3]);	
	s.SetEffect(argv[4]);				
	s.SetComponenets(argv[5]);
	s.SetCastingTime(argv[6]);
	s.SetRange(argv[7]);
	s.SetTarget(argv[8]);
	s.SetDuration(argv[9]);
	s.SetDescription(argv[10]);
		
	spells_V.push_back(s);
	return 0;
}

static int callback_skill(void *NotUsed, int argc, char **argv, char **azColName){
	Skill s;
	
	s.SetName(argv[0]);					
	s.SetAction(argv[1]);
	s.SetKeyAbility(argv[2]);
	s.SetCheck(argv[3]);
	s.SetSynergy(argv[4]);
	s.SetUntrained(argv[5]);
	s.SetTryAgain(argv[6]);
	s.SetRestriction(argv[7]);
	s.SetArmorCheck(argv[8]);
	
	if(argv[9] == "TRUE")
		s.SetTrainedOnly(true);
	else
		s.SetTrainedOnly(false);

	s.SetSpecial(argv[10]);
	s.SetDescription(argv[11]);

	skills_V.push_back(s);

	return 0;
}

static int callback_alignment(void *NotUsed, int argc, char **argv, char **azColName){
	Alignment a;

	a.SetAlignment(argv[0]);
	a.SetDescription(argv[1]);

	alignments_V.push_back(a);

	return 0;
}

static int callback_races(void *NotUsed, int argc, char **argv, char **azColName){
	Race r;

	r.SetRaceName(argv[0]);
	r.SetPhysic(argv[1]);
	r.SetReccomendedClass(argv[2]);
	r.SetSize(argv[3]);
	r.SetSpeed(argv[4]);

	r.SetCharismaMod(stoi(argv[5]));
	r.SetConstitutionMod(stoi(argv[6]));
	r.SetDexterityMod(stoi(argv[7]));
	r.SetIntelligenceMod(stoi(argv[8]));
	r.SetStrengthMod(stoi(argv[9]));
	r.SetWisdomMod(stoi(argv[10]));

	races_V.push_back(r);
	return 0;
}

static int callback_raceLanguages(void *NotUsed, int argc, char **argv, char **azColName){

	int lcv = 0;
	bool found = false;
	string s;

	while (!found && lcv < races_V.size())
	{
		if (races_V[lcv].GetRaceName() == argv[0])
			found = true;
		else
			lcv++;
	}
	if(found)
	{
		s = argv[1];
		races_V[lcv].GetLanguages().push_back(s);
	}
	return 0;
}

static int callback_raceTraits(void *NotUsed, int argc, char **argv, char **azColName){

	int lcv = 0;
	bool found = false;
	string s;

	while (!found && lcv < races_V.size())
	{
		if (races_V[lcv].GetRaceName() == argv[0])
			found = true;
		else
			lcv++;
	}
	if(found)
	{
		s = argv[1];
		races_V[lcv].GetRacialTraits().push_back(s);
	}
	return 0;
}

static int callback_character(void *NotUsed, int argc, char **argv, char **azColName){
	Character c;

	c.SetID_DO_NOT_USE(stoi(argv[0]));
	c.SetName(argv[1]);
	c.SetRace(argv[2]);
	c.SetAlignment(argv[3]);
	c.SetReligion(argv[4]);
	c.SetGold(stoi(argv[5]));
	c.SetArmorClass(argv[6]);
	c.SetSavingThrow(argv[7]);
	c.SetAttackBonus(stoi(argv[8]));
	c.SetMaxHealth(stoi(argv[9]));
	c.SetHealth(stoi(argv[9]));
	c.SetInitiative(stoi(argv[10]));
	c.SetAvailableSkillPoints(stoi(argv[11]));
	c.SetTotalSkillPoints(stoi(argv[12]));
	c.SetBio(argv[13]);
	
	characters_V.push_back(c);
	return 0;
}

static int callback_class(void *NotUsed, int argc, char **argv, char **azColName){
	Class c;

	c.SetName(argv[0]);
	c.SetReccomendedAlignments(argv[1]);
	c.SetStartingGold(argv[2]);
	c.SetHitDie(argv[3]);
	c.SetDescription(argv[4]);
	c.SetFirstLevelUpPoints(argv[5]);
	c.SetLevelUpPoints(argv[6]);

	classes_V.push_back(c);
	return 0;
}

static int callback_charClasses(void *NotUsed, int argc, char **argv, char **azColName){

	int lcv = 0;
	bool found = false;
	Class c;

	while (!found && lcv < characters_V.size())
	{
		if (characters_V[lcv].GetID() == stoi(argv[0]))
			found = true;
		else
			lcv++;
	}
	if(found)
	{
		c.SetName(argv[1]);
		characters_V[lcv].GetCharClasses().push_back(c);
	}
	return 0;
}

static int callback_charSpells(void *NotUsed, int argc, char **argv, char **azColName){

	int lcv = 0;
	bool found = false;
	Spell s;

	while (!found && lcv < characters_V.size())
	{
		if (characters_V[lcv].GetID() == stoi(argv[0]))
			found = true;
		else
			lcv++;
	}
	if(found)
	{
		s.SetName(argv[1]);
		characters_V[lcv].GetCharSpells().push_back(s);
	}
	return 0;
}

static int callback_charOwned(void *NotUsed, int argc, char **argv, char **azColName){

	int lcv = 0;
	bool found = false;
	owns o;

	while (!found && lcv < characters_V.size())
	{
		if (characters_V[lcv].GetID() == stoi(argv[0]))
			found = true;
		else
			lcv++;
	}
	if(found)
	{
		o.type == argv[1];

		if (argv[1] == "Item")
			o.item.SetName(argv[2]);
		else if (argv[1] == "Armor")
			o.armor.SetName(argv[2]);
		else if (argv[1] == "Weapon")
			o.weapon.SetName(argv[2]);
		
		characters_V[lcv].GetOwned().push_back(o);
	}
	return 0;
}

static int callback_charSkills(void *NotUsed, int argc, char **argv, char **azColName){

	int lcv = 0;
	bool found = false;
	SkillStruct* s;

	while (!found && lcv < characters_V.size())
	{
		if (characters_V[lcv].GetID() == stoi(argv[0]))
			found = true;
		else
			lcv++;
	}
	if(found)
	{
		s = new SkillStruct;
		s->skill.SetName(argv[1]);
		s->rank = stoi(argv[2]);
		characters_V[lcv].GetCharSkills().push_back(*s);
	}
	return 0;
}

static int callback_charFeats(void *NotUsed, int argc, char **argv, char **azColName){

	int lcv = 0;
	bool found = false;
	Feat f;

	while (!found && lcv < characters_V.size())
	{
		if (characters_V[lcv].GetID() == stoi(argv[0]))
			found = true;
		else
			lcv++;
	}
	if(found)
	{
		f.SetName(argv[1]);
		characters_V[lcv].GetCharFeats().push_back(f);
	}
	return 0;
}

static int callback_charAbilityScore(void *NotUsed, int argc, char **argv, char **azColName){

	int lcv = 0;
	bool found = false;
	

	while (!found && lcv < characters_V.size())
	{
		if (characters_V[lcv].GetID() == stoi(argv[0]))
			found = true;
		else
			lcv++;
	}
	if(found)
	{
		characters_V[lcv].SetConstitution(stoi(argv[1]));
		characters_V[lcv].SetCharisma(stoi(argv[2]));
		characters_V[lcv].SetDexterity(stoi(argv[3]));
		characters_V[lcv].SetIntelligence(stoi(argv[4]));
		characters_V[lcv].SetStrength(stoi(argv[5]));
		characters_V[lcv].SetWisdom(stoi(argv[6]));
	}
	return 0;
}

static int callback_charCosmetics(void *NotUsed, int argc, char **argv, char **azColName){

	int lcv = 0;
	bool found = false;
	

	while (!found && lcv < characters_V.size())
	{
		if (characters_V[lcv].GetID() == stoi(argv[0]))
			found = true;
		else
			lcv++;
	}
	if(found)
	{
		characters_V[lcv].SetGender(argv[1]);
		characters_V[lcv].SetAge(stoi(argv[2]));
		characters_V[lcv].SetHeight(argv[3]);
		characters_V[lcv].SetCosmetics(argv[4]);
	}
	return 0;
}

static int callback_classFeatures(void *NotUsed, int argc, char **argv, char **azColName){

	int lcv = 0;
	bool found = false;

	while (!found && lcv < classes_V.size())
	{
		if (classes_V[lcv].GetName() == argv[0])
			found = true;
		else
			lcv++;
	}
	if(found)
	{
		feature f;
		f.featureName = argv[1];
		f.featureDescription = argv[2];
		
		classes_V[lcv].GetFeatures().push_back(f);

	}
	return 0;
}

bool CheckMatch(int lcv, string s)
{
	if (classes_V[lcv].GetName() == "Sorcerer"	&&	s == "Sor"			)	return true;
	if (classes_V[lcv].GetName() == "Wizard"	&&	s == "Wiz"			)	return true;
	if (classes_V[lcv].GetName() == "Ranger"	&&	s == "Rgr"			)	return true;
	if (classes_V[lcv].GetName() == "Bard"		&&	s == "Brd"			)	return true;
	if (classes_V[lcv].GetName() == "Druid"		&&	s == "Drd"			)	return true;
	if (classes_V[lcv].GetName() == "Paladin"	&&	s == "Pal"			)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Clr"			)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Air"			)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Animal"		)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Chaos"		)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Death"		)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Destruction"	)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Earth"		)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Evil"			)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Fire"			)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Good"			)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Healing"		)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Knowledge"	)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Law"			)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Luck"			)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Magic"		)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Plant"		)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Protection"	)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Strength"		)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Sun"			)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Travel"		)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Trickery"		)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "War"			)	return true;
	if (classes_V[lcv].GetName() == "Cleric"	&&	s == "Water"		)	return true;
	if (classes_V[lcv].GetName() == s)										return true;

	return false;

}

static int callback_classLearnsSpells(void *NotUsed, int argc, char **argv, char **azColName){

	int lcv = 0;
	bool found = false;
	LearnsSpells l;
	string s;

	while (!found && lcv < classes_V.size())
	{
		s = argv[1];
		if (CheckMatch(lcv, s))
			found = true;
		else
			lcv++;
	}
	if(found)
	{
		//l = new LearnsSpells;
		l.className = argv[1];
		l.s.SetName(argv[0]);
		l.level = stoi(argv[2]);
		
		classes_V[lcv].AddSpellCanLearn(l);

	}
	return 0;
}

static int callback_classBaseSaves(void *NotUsed, int argc, char **argv, char **azColName){

	int lcv = 0;
	bool found = false;
	baseSave b;

	while (!found && lcv < classes_V.size())
	{
		if (classes_V[lcv].GetName() == argv[0])
			found = true;
		else
			lcv++;
	}
	if(found)
	{
		b.level = stoi(argv[1]);
		b.baseAttack = argv[2];
		b.fortificationSave = stoi(argv[3]);
		b.reflexSave = stoi(argv[4]);
		b.willSave = stoi(argv[5]);
		b.special = argv[6];
		

	}
	return 0;
}



static int callback_feat(void *NotUsed, int argc, char **argv, char **azColName){
	Feat f;

	f.SetName(argv[0]);
	f.SetType(argv[1]);
	f.SetBenefit(argv[2]);
	f.SetNormal(argv[3]);
	f.SetSpecial(argv[4]);
	f.SetDescription(argv[5]);

	feats_V.push_back(f);
	return 0;
}

static int callback_featPrereqs(void *NotUsed, int argc, char **argv, char **azColName){

	int lcv = 0;
	bool found = false;
	Feat f;

	while (!found && lcv < feats_V.size())
	{
		if (feats_V[lcv].GetName() == argv[0])
			found = true;
		else
			lcv++;
	}
	if(found)
	{
		f.SetName(argv[1]);
		feats_V[lcv].GetPrereqs().push_back(f);

	}
	return 0;
}

static int callback_items(void *NotUsed, int argc, char **argv, char **azColName){
	Item i;

	i.SetName(argv[0]);
	i.SetCost(argv[1]);
	i.SetWeight(argv[2]);
	i.SetDescription(argv[3]);
	i.SetType(argv[4]);

	items_V.push_back(i);
	return 0;
}

static int callback_armors(void *NotUsed, int argc, char **argv, char **azColName){
	Armor a;
	
	a.SetName(argv[0]);
	a.SetType(argv[1]);
	a.SetCost(argv[2]);
	a.SetWeight(argv[3]);
	a.SetSpeedHuman(argv[4]);
	a.SetSpeedDwarf(argv[5]);
	a.SetMaxDexBonus(argv[6]);
	a.SetArmorCheckPenalty(argv[7]);
	a.SetArcaneSpellFailure(argv[8]);
	a.SetArmorBonus(argv[9]);
	a.SetDon(argv[10]);
	a.SetDonHastely(argv[11]);
	a.SetRemove(argv[12]);
	a.SetDescription(argv[13]);

	armors_V.push_back(a);
	return 0;
}

static int callback_weapons(void *NotUsed, int argc, char **argv, char **azColName){
	Weapon w;

	w.SetName(argv[0]);
	w.SetCost(argv[1]);
	w.SetWeight(argv[2]);
	w.SetWeaponType(argv[3]);
	w.SetProficiency(argv[4]);
	w.SetRange(argv[5]);
	w.SetHands(argv[6]);
	w.SetSize(argv[7]);
	w.SetCritical(argv[8]);
	w.SetDamage(argv[9]);
	w.SetDescription(argv[10]);

	weapons_V.push_back(w);
	return 0;
}

static int callback_religions(void *NotUsed, int argc, char **argv, char **azColName){
	Religion r;

	r.SetDietyName(argv[0]);
	r.SetDescription(argv[1]);
	r.SetSuggestedAlignment(argv[2]);

	religions_V.push_back(r);
	return 0;
}

/*
static int callback_alignment(void *NotUsed, int argc, char **argv, char **azColName){
	alignments_V[loc].SetAlignment(argv[0]);
	alignments_V[loc].SetDescription(argv[1]);

	loc++;
	return 0;
}*/

/*
Below is the format for executing sql statements in sqlite. 

int sqlite3_exec(
	sqlite3*,                                  An open database 
	const char *sql,                           SQL to be evaluated 
	int (*callback)(void*,int,char**,char**),  Callback function 
	void *,                                    1st argument to callback 
	char **errmsg                              Error msg written here 

	Success returns SQLITE_OK. Fail returns any number of other errors detailed at:
	http://www.sqlite.org/c_interface.html#sqlite_exec
);*/

vector<Spell>* LoadSpells()
{
	vector<Spell> *ptr = &spells_V; //Make ptr point @ the global vector to use.

	//Empty the vector of any contents.
	while (!spells_V.empty())
		spells_V.pop_back();

	string query_s = "SELECT * FROM `Spells`;";
	if (sqlite3_exec(db, query_s.c_str(), callback_spell, 0, &zErrMsg) == SQLITE_OK)
		return ptr;
	else 
		return NULL;

}

vector<Character>* LoadCharacter()
{
	vector<Character> *ptr = &characters_V; //Make ptr point @ the global vector to use.

	//Empty the vector of any contents.
	while (!characters_V.empty())
		characters_V.pop_back();

	string query_s = "SELECT * FROM `Character`;";
	if (sqlite3_exec(db, query_s.c_str(), callback_character, 0, &zErrMsg) == SQLITE_OK){
		query_s = "SELECT * FROM `Character_Class`;";
		if (sqlite3_exec(db, query_s.c_str(), callback_charClasses, 0, &zErrMsg) == SQLITE_OK){
			query_s = "SELECT * FROM `Character_Feats`;";
			if (sqlite3_exec(db, query_s.c_str(), callback_charFeats, 0, &zErrMsg) == SQLITE_OK){
				query_s = "SELECT * FROM `Character_Skills`;";
				if (sqlite3_exec(db, query_s.c_str(), callback_charSkills, 0, &zErrMsg) == SQLITE_OK){
					query_s = "SELECT * FROM `Character_Spells`;";
					if (sqlite3_exec(db, query_s.c_str(), callback_charSpells, 0, &zErrMsg) == SQLITE_OK){
						query_s = "SELECT * FROM `Cosmetics`;";
						if (sqlite3_exec(db, query_s.c_str(), callback_charCosmetics, 0, &zErrMsg) == SQLITE_OK){
							query_s = "SELECT * FROM `Owned`;";
							if (sqlite3_exec(db, query_s.c_str(), callback_charOwned, 0, &zErrMsg) == SQLITE_OK){
								query_s = "SELECT * FROM `AbilityScore`;";
								if (sqlite3_exec(db, query_s.c_str(), callback_charAbilityScore, 0, &zErrMsg) == SQLITE_OK)
									return ptr;
	}}}}}}}
	return NULL;
}

vector<Class>* LoadClasses()
{
	vector<Class> *ptr = &classes_V;

	while(!classes_V.empty())
		classes_V.pop_back();

	string query_s = "SELECT * FROM `Class`;";
	if (sqlite3_exec(db, query_s.c_str(), callback_class, 0, &zErrMsg) == SQLITE_OK){
		query_s = "SELECT * FROM `ClassFeatures`;";
		if (sqlite3_exec(db, query_s.c_str(), callback_classFeatures, 0, &zErrMsg) == SQLITE_OK){
			query_s = "SELECT * FROM `Spell_Learned_At`;";
			if (sqlite3_exec(db, query_s.c_str(), callback_classLearnsSpells, 0, &zErrMsg) == SQLITE_OK)
				return ptr;
		}}

	return NULL;

}

vector<Feat>* LoadFeats()
{
	vector<Feat> *ptr = &feats_V;

	while(!feats_V.empty())
		feats_V.pop_back();

	string query_s = "SELECT * FROM `Feats`;";
	if (sqlite3_exec(db, query_s.c_str(), callback_feat, 0, &zErrMsg) == SQLITE_OK){
		query_s = "SELECT * FROM `FeatPrerequisite`;";
		if (sqlite3_exec(db, query_s.c_str(), callback_featPrereqs, 0, &zErrMsg) == SQLITE_OK)
			return ptr;
	}

	return NULL;
}

vector<Item>* LoadItems()
{
	vector<Item> *ptr = &items_V;

	while(!items_V.empty())
		items_V.pop_back();

	string query_s = "SELECT * FROM `Items`;";
	if (sqlite3_exec(db, query_s.c_str(), callback_items, 0, &zErrMsg) == SQLITE_OK)
		return ptr;

	return NULL;
}

vector<Weapon>* LoadWeapons()
{
	vector<Weapon> *ptr = &weapons_V;

	while(!weapons_V.empty())
		weapons_V.pop_back();

	string query_s = "SELECT * FROM `Weapons`;";
	if (sqlite3_exec(db, query_s.c_str(), callback_weapons, 0, &zErrMsg) == SQLITE_OK)
		return ptr;

	return NULL;
}

vector<Armor>* LoadArmors()
{
	vector<Armor> *ptr = &armors_V;

	while(!armors_V.empty())
		armors_V.pop_back();

	string query_s = "SELECT * FROM `Armor`;";
	if (sqlite3_exec(db, query_s.c_str(), callback_armors, 0, &zErrMsg) == SQLITE_OK)
		return ptr;

	return NULL;
}


vector<Alignment>* LoadAlignments()
{
	vector<Alignment> *ptr = &alignments_V;
	while(!alignments_V.empty())
		alignments_V.pop_back();

	string query_s = "SELECT * FROM `Alignment`;";
	if (sqlite3_exec(db, query_s.c_str(), callback_alignment, 0, &zErrMsg) == SQLITE_OK)
		return ptr;

	return NULL;
}


vector<Character>* LoadCharacters()
{
	vector<Character> *ptr = &characters_V;

	while(!characters_V.empty())
		characters_V.pop_back();

	string query_s = "SELECT * FROM `Character`;";
	if (sqlite3_exec(db, query_s.c_str(), callback_character, 0, &zErrMsg) == SQLITE_OK)
		return ptr;

	return NULL;
}

vector<Race>* LoadRaces()
{
	vector<Race> *ptr = &races_V;

	while(!races_V.empty())
		races_V.pop_back();

	string query_s = "SELECT * FROM `Race`;";
	if (sqlite3_exec(db, query_s.c_str(), callback_races, 0, &zErrMsg) == SQLITE_OK){
		query_s = "SELECT * From `RaceLanguages`;";
		if (sqlite3_exec(db, query_s.c_str(), callback_raceLanguages, 0, &zErrMsg) == SQLITE_OK)
			return ptr;			
	}

	return NULL;
}

vector<Religion>* LoadReligions()
{
	vector<Religion> *ptr = &religions_V;

	while(!religions_V.empty())
		religions_V.pop_back();

	string query_s = "SELECT * FROM `Religion`;";
	if (sqlite3_exec(db, query_s.c_str(), callback_religions, 0, &zErrMsg) == SQLITE_OK)
			return ptr;			

	return NULL;
}

vector<Skill>* LoadSkills()
{
	vector<Skill> *ptr = &skills_V;

	while(!skills_V.empty())
		skills_V.pop_back();

	string query_s = "SELECT * FROM `Skills`;";
	if (sqlite3_exec(db, query_s.c_str(), callback_skill, 0, &zErrMsg) == SQLITE_OK)
			return ptr;			

	return NULL;
}

bool AddToCEAMS (Spell s)
{
	//Forming SQL statement.
	string query_s = "INSERT INTO `Spells` (`SpellName`,  `SpellType`,";
	query_s += " `SavingThrow`, `SpellResistance`, `Effect`, `Components`,";
	query_s += " `CastingTime`, `Range`, `Target`, `Duration`, `Description`) VALUES ('";

	query_s += s.GetName();				query_s += "', '";
	query_s += s.GetType();				query_s += "', '";
	query_s += s.GetSavingThrow();		query_s += "', '";
	query_s += s.GetSpellResistance();	query_s += "', '";
	query_s += s.GetEffect();			query_s += "', '";
	query_s += s.GetComponents();		query_s += "', '";
	query_s += s.GetCastingTime();		query_s += "', '";
	query_s += s.GetRange();			query_s += "', '";
	query_s += s.GetTarget();			query_s += "', '";
	query_s += s.GetDuration();			query_s += "', '";
	query_s += s.GetDescription();		query_s += "');";
	//SQL statement formed.

	if (rc == SQLITE_OK) //Check connection status.
	{
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) == 0)
			return true;
	}
	else
		cout << "ERR: Problem connecting to Database." << endl;
	
	return false;
}

bool RemoveFromCEAMS (Spell s)
{
	string query_s = "DELETE FROM `Spells` WHERE (`SpellName` = '";
	query_s += s.GetName();			query_s += "' AND `SpellType = '";
	query_s += s.GetType();			query_s += "');";

	if (rc == SQLITE_OK) //Check connection status.
	{	
		return true;

	}
	else
		cout << "ERR: Problem connecting to Database." << endl;
	
	return false;
}



bool AddToCEAMS (Race r)
{
	string query_s = "INSERT INTO `Race` (`RaceName`, `Physic`, `RecomendedClass`, `Size`, `Speed`, `ChaMod`, `ConMod`, `DexMod`, `IntMod`, `StrMod`, `WisMod`) VALUES ('";
	query_s += r.GetRaceName();			query_s += "', '";
	query_s += r.GetPhysic();			query_s += "', '";
	query_s += r.GetReccomendedClass();	query_s += "', '";
	query_s += r.GetSize();				query_s += "', '";
	query_s += r.GetSpeed();			query_s += "');";



	if (rc == SQLITE_OK) //Check connection status.
	{
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;

		vector<string>::iterator itr = r.GetLanguages().begin();
		int i = 0;

		while (itr != r.GetLanguages().end()){
			query_s = "INSERT INTO `RaceLanguages` (`Race`, `RaceLanguage`) VALUES ('";
			query_s += r.GetRaceName();			query_s += "', '";
			query_s += r.GetLanguages()[i];		query_s += "');";
			if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
				return false;
			itr++; i++;
		}

		itr = r.GetRacialTraits().begin();
		i = 0;

		while (itr != r.GetRacialTraits().end()){
			query_s = "INSERT INTO `RacialTraits` (`Race`, `Trait`) VALUES ('";
			query_s += r.GetRaceName();			query_s += "', '";
			query_s += r.GetRacialTraits()[i];	query_s += "');";
			if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
				return false;
			itr++; i++;
		}
		return true;
	}
	else
		cout << "ERR: Problem connecting to Database." << endl;

	return false;

}

bool RemoveFromCEAMS (Race r)
{
	string query_s = "DELETE FROM `Race` WHERE `RaceName` = '";
	query_s += r.GetRaceName(); query_s += "';";

	if (rc == SQLITE_OK) //Check connection status.
	{
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		query_s = "DELETE FROM `RacialTraits` WHERE `Race` = '";
		query_s += r.GetRaceName(); query_s += "';";
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		query_s = "DELETE FROM `RaceLanguages` WHERE `Race` = '";
		query_s += r.GetRaceName(); query_s += "';";
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		return true;
	}
	else
		cout << "ERR: Problem connecting to Database." << endl;
		
	return false;
	
}

bool AddToCEAMS(learnedBy l)
{
	string sql_s = "INSERT INTO `Spell_Learned_At` (`SpellName`, `ClassName`, `Level`) VALUES ('";
	sql_s += l.s;			sql_s += "', '";
	sql_s += l.c;			sql_s += "', '";
	sql_s += l.l + '0';		sql_s += "');";
			
	if (sqlite3_exec(db, sql_s.c_str(), callback, 0, &zErrMsg) == SQLITE_OK)
		return true;
	else
		return false;
}

bool AddToCEAMS (Class c)
{
	string query_s = "INSERT INTO `Class` (`ClassName`, `Alignment`, `StartingGold`, `HitDie`, `ClassDescription`, `FirstLevelUpPoints`, `LevelUpPoints`) ";
	query_s += "VALUES ('";
	query_s += c.GetName();						query_s += "', '";
	query_s += c.GetReccomendedAlignments();	query_s += "', '";
	query_s += c.GetStartingGold();				query_s += "', '";
	query_s += c.GetHitDie();					query_s += "', '";
	query_s += c.GetDescription();				query_s += "', '";
	query_s += c.GetFirstLevelUpPoints();		query_s += "', '";
	query_s += c.GetLevelUpPoints();			query_s += "');";

	if (rc == SQLITE_OK) //Check connection status.
	{
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		query_s = "INSERT INTO `ClassFeatures` (`DDClass`, `ClassFeature`, `Description`) VALUES ('";
		query_s += c.GetName();								query_s += "', '";
		query_s += c.GetFeatures()[0].featureName;			query_s += "', '";
		query_s += c.GetFeatures()[0].featureDescription;	query_s += "');";
		int i = 0, j = 0;  //NOT DONE!
		
		i++; j++;
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;

		while (j < c.GetFeatures().size()){
			query_s = "INSERT INTO `ClassFeatures` (`DDClass`, `ClassFeature`, `Description`) VALUES ('";
			query_s += c.GetName();								query_s += "', '";
			query_s += c.GetFeatures()[j].featureName;			query_s += "', '";
			query_s += c.GetFeatures()[j].featureDescription;	query_s += "');";
			i++; j++;
			if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
				return false;
			}
		
		i = 0;
		do{
			query_s = "INSERT INTO `Spell_Learned_At` (`SpellName`, `ClassName`, `Level`) VALUES ('";
			query_s += c.GetSpellsCanLearn()[i].s.GetName();	query_s += "', '";
			query_s += c.GetName();								query_s += "', '";
			query_s += c.GetSpellsCanLearn()[i].level;			query_s += "');";	
			i++;
			if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
				return false;
		}
		while (i < c.GetSpellsCanLearn().size());

		return true;
	}
	else
		cout << "ERR: Problem connecting to Database." << endl;
	
	return false;	
}

bool RemoveFromCEAMS (Class c)
{
	string query_s = "DELETE FROM `Class` WHERE `ClassName` = '";
	query_s += c.GetName();		query_s += "';";

	if (rc == SQLITE_OK) //Check connection status.
	{
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		query_s = "DELETE FROM `ClassFeature` WHERE `DDClass` = '";
		query_s += c.GetName();	query_s += "';";
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		query_s = "DELETE FROM `Spell_Learned_At` WHERE (`ClassName` = '";
		query_s += c.GetName();		query_s += "');";
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		return true;
	}
	else
		cout << "ERR: Problem connecting to Database." << endl;
	
	return false;	
}

bool AddToCEAMS (Feat f)
{
	string query_s = "INSERT INTO `Feats` (`FeatName`, `FeatType`, `Benefit`, `Normal`, `Special`, `FeatDescription`) VALUES ('";
	query_s += f.GetName();			query_s += "', '";
	query_s += f.GetType();			query_s += "', '";
	query_s += f.GetBenefit();		query_s += "', '";
	query_s += f.GetNormal();		query_s += "', '";
	query_s += f.GetSpecial();		query_s += "', '";
	query_s += f.GetDescripton();	query_s += "');";

	if (rc == SQLITE_OK) //Check connection status.
	{
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		query_s = "INSERT INTO `FeatPrerequisite` (`FeatName`, `FeatPrequisite`) VALUES ('";
		query_s += f.GetName();					query_s += "', '";
		int i = 0; vector<Feat>::iterator itr = f.GetPrereqs().begin();
		query_s += f.GetPrereqs()[i].GetName();	query_s += "');";
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		i++; itr++;

		while (itr != f.GetPrereqs().end()){
			query_s = "INSERT INTO `FeatPrerequisite` (`FeatName`, `FeatPrequisite`) VALUES ('";
			query_s += f.GetName();					query_s += "', '";
			query_s += f.GetPrereqs()[i].GetName();	query_s += "');";
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
				return false;
			i++; itr++;
		}
		return true;
	}
	else
		cout << "ERR: Problem connecting to Database." << endl;
		
	return false;
}

bool RemoveFromCEAMS (Feat f)
{
	string query_s = "DELETE FROM `Feats` WHERE `FeatName` = '";
	query_s += f.GetName();		query_s += "';";
	if (rc == SQLITE_OK) //Check connection status.
	{
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		query_s = "DELETE FROM `FeatPrerequisite` WHERE `FeatName` = '";
		query_s += f.GetName();	query_s += "';";
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		return true;
	}
	else
		cout << "ERR: Problem connecting to Database." << endl;
		
	return false;
}

bool AddToCEAMS (Item i)
{
	string query_s = "INSERT INTO `Items` (`ItemName`, `ItemCost`, `ItemWeight`, `ItemDescription`, `ItemType`) VALUES ('";
	query_s += i.GetName();			query_s += "', '";
	query_s += i.GetCost();			query_s += "', '";
	query_s += i.GetWeight();		query_s += "', '";
	query_s += i.GetDescription();	query_s += "', ";	
	query_s += i.GetType();			query_s += "');";

	if (rc == SQLITE_OK) //Check connection status.
	{
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		return true;
	}
	else
	{
		cout << "ERR: Problem connecting to Database." << endl;
		return false;
	}
}

bool RemoveFromCEAMS (Item i)
{
	string query_s = "DELETE FROM `Items` WHERE `ItemName` = '";
	query_s += i.GetName();			query_s += "';";
	if (rc == SQLITE_OK) //Check connection status.
	{
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		return true;
	}
	else
		cout << "ERR: Problem connecting to Database." << endl;
		
	return false;
}

bool AddToCEAMS (Weapon w)
{
	string query_s = "INSERT INTO `Weapons` (`WeaponName`, `WeaponCost`, `WeaponWeight`, `WeaponType`, `Proficiency`, `Range`, `Hands`, `Size`, `Critical`, `Damage`, `WeaponDescription`) VALUES ('";
	query_s += w.GetName();				query_s += "', '";
	query_s += w.GetCost();				query_s += "', '";
	query_s += w.GetWeight();			query_s += "', '";
	query_s += w.GetWeaponType();		query_s += "', '";
	query_s += w.GetProficiency();		query_s += "', '";
	query_s += w.GetRange();			query_s += "', '";
	query_s += w.GetHands();			query_s += "', '";
	query_s += w.GetSize();				query_s += "', '";
	query_s += w.GetCritical();			query_s += "', '";
	query_s += w.GetDamage();			query_s += "', '";
	query_s += w.GetDescription();		query_s += "');";

	if (rc == SQLITE_OK) //Check connection status.
	{
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		return true;
	}
	else
		cout << "ERR: Problem connecting to Database." << endl;
		
	return false;
}

bool RemoveFromCEAMS (Weapon w)
{
	string query_s = "DELETE FROM `Weapons` WHERE `WeaponName` = '";
	query_s += w.GetName();				query_s += "';";
	if (rc == SQLITE_OK) //Check connection status.
	{
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		return true;
	}
	else
		cout << "ERR: Problem connecting to Database." << endl;
		
	return false;
}

bool AddToCEAMS (Armor a)
{
	string query_s = "INSERT INTO `Armor` (`ArmorName`, `ArmorType`, `ArmorCost`, `ArmorWeight`, `SpeedHuman`, `SpeedDwarf`, `MaxDexterityBonus`, `ArmorCheckPenalty`, `ArcaneSpellFailure`, `ArmorBonus`, `Don`, `DonHastely`, `Remove`, `ArmorDescription`) VALUES ('";
	query_s += a.GetName();						query_s += "', '";
	query_s += a.GetType();						query_s += "', '";
	query_s += a.GetCost();						query_s += "', '";
	query_s += a.GetWeight();					query_s += "', '";
	query_s += a.GetSpeedHuman();				query_s += "', '";
	query_s += a.GetSpeedDwarf();				query_s += "', '";
	query_s += a.GetMaxDexBonus();				query_s += "', '";
	query_s += a.GetArmorCheckPenalty();		query_s += "', '";
	query_s += a.GetArcaneSpellFailure();		query_s += "', '";
	query_s += a.GetArmorBonus();				query_s += "', '";
	query_s += a.GetDon();						query_s += "', '";
	query_s += a.GetDonHastely();				query_s += "', '";
	query_s += a.GetRemove();					query_s += "', '";
	query_s += a.GetDescription();				query_s += "');";

	if (rc == SQLITE_OK) //Check connection status.
	{
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		return true;
	}
	else
		cout << "ERR: Problem connecting to Database." << endl;
		
	return false;
}

bool RemoveFromCEAMS (Armor a)
{
	string query_s = "DELETE FROM `Armor` WHERE `ArmorName` = '";
	query_s += a.GetName();						query_s += "', '";
	if (rc == SQLITE_OK) //Check connection status.
	{
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		return true;
	}
	else
		cout << "ERR: Problem connecting to Database." << endl;
		
	return false;
}

bool AddToCEAMS (Skill s)
{
	string query_s = "INSERT INTO `Skills` (`SkillName`, `Action`, `KeyAbility`, `Check`, `Synergy`, `Untrained`, `TryAgain`, `Restriction`, `ArmorCheck`, `TrainedOnly`, `Special`, `Description`) VALUES ('";
	query_s += s.GetName();					query_s += "', '";
	query_s += s.GetAction();				query_s += "', '";
	query_s += s.GetKeyAbility();			query_s += "', '";
	query_s += s.GetCheck();				query_s += "', '";
	query_s += s.GetSynergy();				query_s += "', '";
	query_s += s.GetUntrained();			query_s += "', '";
	query_s += s.GetRestriction();			query_s += "', '";
	query_s += s.GetArmorCheck();			query_s += "', '";
	query_s += s.GetTrainedOnly();			query_s += "', '";
	query_s += s.GetSpecial();				query_s += "', '";
	query_s += s.GetDescription();			query_s += "');";

	if (rc == SQLITE_OK) //Check connection status.
	{
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		return true;
	}
	else
		cout << "ERR: Problem connecting to Database." << endl;
		
	return false;
}

bool RemoveFromCEAMS (Skill s)
{
	string query_s = "DELETE FROM `Skills` WHERE `SkillName` = '";
	query_s += s.GetName();					query_s += "';";
	if (rc == SQLITE_OK) //Check connection status.
	{
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		return true;
	}
	else
		cout << "ERR: Problem connecting to Database." << endl;
	
	return false;	
}

bool AddToCEAMS (Alignment a)
{
	sqlite3 *db; //DB object, used to manipulate DB.
	int rc = sqlite3_open(dbName, &db); //Connect to DB.
	char **errmsg; //Will contain any error messages.
	void *ptr;

	string query_s = "INSERT INTO `Alignment` (`AlignmentName`, `AlignmentDescription`) VALUES ('";
	query_s += a.GetAlignment();			query_s += "', '";
	query_s += a.GetDescription();			query_s += "');";

	if (rc == SQLITE_OK) //Check connection status.
	{
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		return true;
	}
	else
		cout << "ERR: Problem connecting to Database." << endl;
		
	return false;
}

bool RemoveFromCEAMS(Alignment a)
{
	string query_s = "DELETE FROM `Alignment` WHERE `AlignmentName` = '";
	query_s += a.GetAlignment();			query_s += "';";
	if (rc == SQLITE_OK) //Check connection status.
	{
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		return true;
	}
	else
		cout << "ERR: Problem connecting to Database." << endl;
		
	return false;
}

bool AddToCEAMS(Character c)
{
	string query_s = "INSERT INTO `Character` (`CharacterID`, `CharacterName`, `Race`, `Alignment`, `Religion`, `Gold`, `ArmorClass`, `SavingThrow`, `AttackBonus`, `HitPoints`, `Initiative`, `AvailableSkillPoints`, `TotalSkillPoints`, `Level`, `TotalExp`) VALUES ('";
	query_s += c.GetID();							query_s += "', '";
	query_s += c.GetName();							query_s += "', '";
	query_s += c.GetRace();						query_s += "', '";
	query_s += c.GetAlignment();					query_s += "', '";
	query_s += c.GetReligion();						query_s += "', '";
	query_s += c.GetGold();							query_s += "', '";
	query_s += c.GetArmorClass();					query_s += "', '";
	query_s += c.GetSavingThrow();					query_s += "', '";
	query_s += c.GetAttackBonus();					query_s += "', '";
	query_s += c.GetHealth();						query_s += "', '";
	query_s += c.GetInitiative();					query_s += "', '";
	query_s += c.GetAvailableSkillPoints();			query_s += "', '";
	query_s += c.GetTotalSkillPoints();				query_s += "', '";
	query_s += c.GetLevel();						query_s += "', '";
	query_s += c.GetTotalExp();						
	
	query_s += "');";

	if (rc == SQLITE_OK) //Check connection status.
	{
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;
		query_s = "INSERT INTO `AbilityScore` (`CharacterID`, `Constitution`, `Charisma`, `Dexterity`, `Intelligence`, `Strength`, `Wisdom`) VALUES ('";
		query_s += c.GetID();				query_s += "', '";
		query_s += c.GetConstitution();		query_s += "', '";
		query_s += c.GetCharisma();			query_s += "', '";
		query_s += c.GetDexterity();		query_s += "', '";
		query_s += c.GetIntelligence();		query_s += "', '";
		query_s += c.GetStrength();			query_s += "', '";
		query_s += c.GetWisdom();			query_s += "');";
		if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
			return false;

		vector<Class>::iterator itr = c.GetCharClasses().begin();
		int i = 0;
		query_s = "INSERT INTO `Character_Class` (`Character_CharacterID`, `Class_ClassName`) VALUES ('";
		query_s += c.GetID();						query_s += "', '";
		query_s += c.GetCharClasses()[i].GetName();	query_s += "');";
		itr++; i++;
		
		while (itr != c.GetCharClasses().end())
		{
			if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
				return false;
			query_s = "INSERT INTO `Character_Class` (`Character_CharacterID`, `Class_ClassName`) VALUES ('";
			query_s += c.GetID();						query_s += "', '";
			query_s += c.GetCharClasses()[i].GetName();	query_s += "');";
			itr++; i++;
		}

		vector<Feat>::iterator itr2 = c.GetCharFeats().begin();
		i = 0;
		query_s = "INSERT INTO `Character_Feats` (`Character_CharacterID`, `Feats_FeatName`) VALUES ('";
		query_s += c.GetID();						query_s += "', '";
		query_s += c.GetCharFeats()[i].GetName();	query_s += "');";
		itr2++; i++;
		
		while (itr2 != c.GetCharFeats().end())
		{
			if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
				return false;
			query_s = "INSERT INTO `Character_Feats` (`Character_CharacterID`, `Feats_FeatName`) VALUES ('";
			query_s += c.GetID();						query_s += "', '";
			query_s += c.GetCharFeats()[i].GetName();	query_s += "');";
			itr2++; i++;
		}

		vector<SkillStruct>::iterator itr3 = c.GetCharSkills().begin();
		i = 0;
		query_s = "INSERT INTO `Character_Skills` (`Character_CharacterID`, `Rank`, `Skills_SkillName`) VALUES ('";
		query_s += c.GetID();						query_s += "', '";
		query_s += c.GetCharSkills()[i].rank;		query_s += "', '";
		query_s += c.GetCharSkills()[i].skill.GetName();	query_s += "');";
		itr3++; i++;
		
		while (itr3 != c.GetCharSkills().end())
		{
			if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
				return false;
			query_s = "INSERT INTO `Character_Skills` (`Character_CharacterID`, `Rank`, `Skills_SkillName`) VALUES ('";
			query_s += c.GetID();						query_s += "', '";
			query_s += c.GetCharSkills()[i].rank;		query_s += "', '";
			query_s += c.GetCharSkills()[i].skill.GetName();	query_s += "');";
			itr3++; i++;
		
		}

		vector<Spell>::iterator itr4 = c.GetCharSpells().begin();
		i = 0;
		query_s = "INSERT INTO `Character_Spells` (`Character_CharacterID`, `Spells_SpellName`) VALUES ('";
		query_s += c.GetID();						query_s += "', '";
		query_s += c.GetCharSpells()[i].GetName();	query_s += "');";
		itr4++; i++;
		
		while (itr4 != c.GetCharSpells().end())
		{
			if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
				return false;
			query_s = "INSERT INTO `Character_Spells` (`Character_CharacterID`, `Spells_SpellName`) VALUES ('";
			query_s += c.GetID();						query_s += "', '";
			query_s += c.GetCharSpells()[i].GetName();	query_s += "');";
			itr4++; i++;
		
		}
		return true;

		vector<owns>::iterator itr5 = c.GetOwned().begin();
		i = 0;
		query_s = "INSERT INTO `Owned` (`Character_CharacterID`, `OwnedType`, `OwnedName`) VALUES ('";
		query_s += c.GetID();						query_s += "', '";
		query_s += c.GetOwned()[i].type;			query_s += "', '";
		if (c.GetOwned()[i].type == "Armor")
			query_s += c.GetOwned()[i].armor.GetName();
		else if (c.GetOwned()[i].type == "Item")
			query_s += c.GetOwned()[i].item.GetName();
		else if (c.GetOwned()[i].type == "Weapon")
			query_s += c.GetOwned()[i].weapon.GetName();
		
		query_s += "');";
		itr5++; i++;
		
		while (itr5 != c.GetOwned().end())
		{
			if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
				return false;
			query_s = "INSERT INTO `Owned` (`Character_CharacterID`, `OwnedType`, `OwnedName`) VALUES ('";
			query_s += c.GetID();						query_s += "', '";
			query_s += c.GetOwned()[i].type;			query_s += "', '";
			if (c.GetOwned()[i].type == "Armor")
				query_s += c.GetOwned()[i].armor.GetName();
			else if (c.GetOwned()[i].type == "Item")
				query_s += c.GetOwned()[i].item.GetName();
			else if (c.GetOwned()[i].type == "Weapon")
				query_s += c.GetOwned()[i].weapon.GetName();
		
			query_s += "');";
			itr5++; i++;
		
		}
	}
	else
		cout << "ERR: Problem connecting to Database." << endl;
		
	return false;
}

bool RemoveFromCEAMS(Character c)
{
	if (rc != SQLITE_OK)
		return false;

	string query_s = "DELETE FROM `Character` WHERE `CharacterID` = '";
	query_s += c.GetID();	query_s += "');";
	if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
		return false;

	query_s = "DELETE FROM `AbilityScore` WHERE `CharacterID` = '";
	query_s = c.GetID();	query_s += "');";
	if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
		return false;

	query_s = "DELETE FROM `Character_Class` WHERE `CharacterID` = '";
	query_s = c.GetID();	query_s += "');";
	if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
		return false;

	query_s = "DELETE FROM `Owned` WHERE `CharacterID` = '";
	query_s = c.GetID();	query_s += "');";
	if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
		return false;

	query_s = "DELETE FROM `Character_Feats` WHERE `CharacterID` = '";
	query_s = c.GetID();	query_s += "');";
	if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
		return false;

	query_s = "DELETE FROM `Character_Skills` WHERE `CharacterID` = '";
	query_s = c.GetID();	query_s += "');";
	if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
		return false;

	query_s = "DELETE FROM `Character_Spells` WHERE `CharacterID` = '";
	query_s = c.GetID();	query_s += "');";
	if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
		return false;

	return true;
}

bool Save(Character c)
{
	if (RemoveFromCEAMS(c))
		if(AddToCEAMS(c))
			return true;

	return false;
}


/* Format for retrieving data without callback fn.
typedef struct sqlite_vm sqlite_vm;

int sqlite_compile(
  sqlite *db,              The open database 
  const char *zSql,        SQL statement to be compiled
  const char **pzTail,     OUT: uncompiled tail of zSql 
  sqlite_vm **ppVm,        OUT: the virtual machine to execute zSql 
  char **pzErrmsg          OUT: Error message. 
);

int sqlite_step(
  sqlite_vm *pVm,          The virtual machine to execute 
  int *pN,                 OUT: Number of columns in result 
  const char ***pazValue,  OUT: Column data 
  const char ***pazColName OUT: Column names and datatypes 
);

int sqlite_finalize(
  sqlite_vm *pVm,          The virtual machine to be finalized 
  char **pzErrMsg          OUT: Error message 
);*/
/*

vector<Spell>* LoadSpells()
{
	string query_s = "SELECT * FROM `Spells`";
	vector<Spell>* ret = NULL;
	sqlite3_stmt *statement;
	 
	if (sqlite3_exec(db, query_s.c_str(), callback, 0, &zErrMsg) != SQLITE_OK)
		return ret;
	else 
	{
		

	}
}*/

DBLS DBLoad()
{
	//clock_t t1, t2;
	
	DBLS LS;
	LS.loadedOkay = true;
	//t1 = clock();

	LS.alignment_V = LoadAlignments();
	LS.armor_V = LoadArmors();
	LS.character_V = LoadCharacters();
	LS.class_V = LoadClasses();
	LS.feat_V = LoadFeats();
	LS.item_V = LoadItems();
	LS.race_V = LoadRaces();
	//LS.religion_V = LoadReligions();
	LS.skill_V = LoadSkills();
	LS.spell_V = LoadSpells();
	LS.weapon_V = LoadWeapons();

	if (LS.alignment_V == NULL)
		LS.loadedOkay = false;
	if (LS.armor_V == NULL)
		LS.loadedOkay = false;
	if (LS.character_V == NULL)
		LS.loadedOkay = false;
	if (LS.class_V == NULL)
		LS.loadedOkay = false;
	if (LS.feat_V == NULL)
		LS.loadedOkay = false;
	if (LS.item_V == NULL)
		LS.loadedOkay = false;
	if (LS.race_V == NULL)
		LS.loadedOkay = false;
	if (LS.skill_V == NULL)
		LS.loadedOkay = false;
	if (LS.spell_V == NULL)
		LS.loadedOkay = false;
	if (LS.weapon_V == NULL)
		LS.loadedOkay = false;

	if (LS.loadedOkay)
	{
		vector<Character>::iterator itr = LS.character_V->begin();
		while (itr != LS.character_V->end())
		{
			itr->CompleteClasses(*LS.class_V);
			itr->CompleteFeats(*LS.feat_V);
			itr->CompleteOwned(*LS.item_V, *LS.armor_V, *LS.weapon_V);
			itr->CompleteSkills(*LS.skill_V);
			itr->CompleteSpells(*LS.spell_V);
			itr++;
		}

		vector<Class>::iterator itr2 = LS.class_V->begin();
		while (itr2 != LS.class_V->end())
		{
			itr2->CompleteSpellsCanLearn(*LS.spell_V);
			itr2++;
		}

		vector<Feat>::iterator itr3 = LS.feat_V->begin();
		while (itr3 != LS.feat_V->end())
		{
			itr3->CompletePrereqs(*LS.feat_V);
			itr3++;
		}
	}
	
	return LS;	
}