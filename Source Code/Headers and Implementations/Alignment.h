#include <string>
#pragma once

using namespace std;

class Alignment 
{
public:
	Alignment()						{alignment = "NULL"; description = "NULL";}
	string GetAlignment()			{return alignment;}
	void SetAlignment(string s)		{alignment = s;}
	string GetDescription()			{return description;}
	void SetDescription(string s)	{description = s;}

private:
	string alignment;
	string description;
};
