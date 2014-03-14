#ifndef SKILL_H
#define SKILL_H

#include <string>

using namespace std;

class Skill
{
public:
    string GetName()				{return name;}
    void SetName(string s)			{name = s;}
    string GetAction()				{return action;}
    void SetAction(string s)		{action = s;}
    string GetKeyAbility()			{return keyAbility;}
    void SetKeyAbility(string s)	{keyAbility = s;}
    string GetCheck()				{return check;}
    void SetCheck(string s)			{check = s;}
    string GetSynergy()				{return synergy;}
    void SetSynergy(string s)		{synergy = s;}
    string GetUntrained()			{return untrained;}
    void SetUntrained(string s)		{untrained = s;}
    string GetTryAgain()			{return tryAgain;}
    void SetTryAgain(string s)		{tryAgain = s;}
    string GetRestriction()			{return restriction;}
    void SetRestriction(string s)	{restriction = s;}
    string GetArmorCheck()			{return armorCheck;}
    void SetArmorCheck(string s)	{armorCheck = s;}
    string GetSpecial()				{return special;}
    void SetSpecial(string s)		{special = s;}
    bool GetTrainedOnly()			{return trainedOnly;}
    void SetTrainedOnly(bool b)		{trainedOnly = b;}
    void SetDescription(string s)	{description = s;}
    string GetDescription()			{return description;}
private:
    string name,
        action,
        keyAbility,
        check,
        synergy,
        untrained,
        tryAgain,
        restriction,
        armorCheck,
        special;

    string description;

    bool trainedOnly;
};

#endif // SKILL_H
