#include "configure.h"
#include <iostream>
#include <sys/stat.h>

using namespace std;

int exist(char *name)
{
  struct stat   buffer;
  return (stat (name, &buffer) == 0);
}

int main(int argc,char* argv[])
{
	if(argc < 2 )
	{
		cout<<"Usage ./main.bin filename" << endl;
		exit(1);
	}
	
	configure objcfg(argv[1]);
	char* fileName = objcfg.getfilename();
	
	cout << "Config file name is " << fileName << endl;
	
	if( objcfg.checkfile() )
	{
		cout << "checkfile for "<<argv[1] <<" failed" << endl;
		exit(1);
	}
	
	objcfg.readiniFile();
	cout <<"Pritpal name is " <<objcfg.getFieldValue("Pritpal","Name") << "\n";
	
	return 0;
}
