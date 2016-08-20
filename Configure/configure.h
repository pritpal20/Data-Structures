#ifndef CONFIGURE_H
#define CONFIGURE_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <map>

#include <sstream>
#include <iterator>
#include <sys/stat.h>

#define FAIL 1
#define SUCCESS 0

typedef std::map<std::string,std::string>  map1;
typedef std::map<std::string,map1*>	map2;

class configure
{
	private :
	
	char filename[100];
	std::vector<char*> iniTags;
	
	map1 fieldvaluepair;
	map2 tagpair;
	
	std::string trimEnds(std::string);
	void printMap();
	
	public : 
	
	//constructors :
	
	configure();
	
	configure(char* file);
	
	char* getfilename();
	
	void readiniFile();
	
	std::string getFieldValue(std::string,std::string);
	
	bool IsfileExist();
	bool checkfile();
	
	//destructor :
	
	~configure();
	
	
	
};

#endif
