#ifndef FEAT_H
#define FEAT_H

#include <string>
#include <vector>

using namespace std;

class Feat
{
public:
    string GetName()				{return name;}
    void SetName(string s)			{name = s;}
    string GetType()				{return type;}
    void SetType(string s)			{type = s;}
    vector<Feat> GetPrereqs()		{return prereqs;}
    void SetPrereqs(vector<Feat> v)	{prereqs = v;}
    string GetBenefit()				{return benefit;}
    void SetBenefit(string s)		{benefit = s;}
    string GetNormal()				{return normal;}
    void SetNormal(string s)		{normal = s;}
    string GetSpecial()				{return special;}
    void SetSpecial(string s)		{special = s;}
    string GetDescripton()			{return description;}
    void SetDescription(string s)	{description = s;}

    void CompletePrereqs(vector<Feat>);

private:
    string name,
        type;
    vector<Feat> prereqs;
    string benefit;
    string normal;
    string special;
    string description;
};

#endif // FEAT_H
