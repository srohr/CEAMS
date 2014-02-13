#include <fstream>
#include <string>
#include <iostream>
#include "sqlite3.h"
#include "DBIO.h"
#include <stdio.h>
#include "Alignment.h"
#include <cmath>


using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   string s = "";
  /* for(i=0; i<argc; i++)
   {
	cout << i << endl;
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	  cout << s << endl;
	 
   }*/
   cout << argv[0] << endl << argv[1] << endl;
   printf("\n");
   return 0;
}

Alignment ParseLineAlignment(string);
Class ParseClass(string);



int main()
{
	/*string filename = "Alignments.csv";
	ifstream infile;
	Alignment A;
	string line;*/
	const string dbNameString = "CEAMS.db3";	
	const char* dbName = dbNameString.c_str();
	char *zErrMsg = 0;
	sqlite3 *db; //DB object, used to manipulate DB.
	int rc = sqlite3_open(dbName, &db); //Connect to DB.

	/*cout << "Opening: " << filename << endl;
	infile.open(filename);

	if(!infile)
	{
		cout << "Failed to open file." << endl;
	}
	else
	{
		cout << "File open." << endl;
		while(getline(infile, line))
		{

			/*if(AddToCEAMS(ParseLineAlignment(line)))
				cout << "Alignment added." << endl;
			else
				cout << "Alignment not added." << endl;*/
		//}
	//}*/

	

	cout << "Will now attempt tp return data from DB." << endl;

		

	string query = "SELECT * FROM `Alignment`;";// `AlignmentDescription` FROM `Alignment` WHERE `AlignmentName` = 'Lawful Good';";
	if (sqlite3_exec(db, query.c_str(), callback, 0, &zErrMsg) == SQLITE_OK)
		cout << "Success?" << endl;
	else
		cout << "Failure?" <<endl;
		
	cin.ignore();
	return 0;
}

Alignment ParseLineAlignment(string s)
{
	string aName = "",
		aDes = "";
	
	int lcv = 0;

	while (s[lcv] != ',')
	{
		aName += s[lcv];
		lcv++;
	}
	lcv++;
	while (lcv < s.length())
	{
		aDes += s[lcv];
		lcv++;
	}

	Alignment a;
	a.SetAlignment(aName);
	a.SetDescription(aDes);
	return a;
}