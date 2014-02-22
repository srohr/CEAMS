#include <string>
#pragma once

using namespace std;

class Religion
{
public:
	string GetDietyName()					{return dietyName;}
	string GetDescription()					{return description;}
	string GetSuggestedAlignment()			{return suggestedAlignment;}
	void SetDietyName(string d)				{dietyName = d;}
	void SetDescription(string s)			{description = s;}
	void SetSuggestedAlignment(string s)	{suggestedAlignment = s;}

private:
	string dietyName,
		description,
		suggestedAlignment;
};