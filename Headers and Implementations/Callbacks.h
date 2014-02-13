#include "DBIO.h"
#include <string>
#pragma once;

using namespace std;

static int callback_spell(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++)
   {
		
      //printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	  /*string s;
	  s = argv[i];
	  cout << s << endl;*/
		

   }
   return 0;
}