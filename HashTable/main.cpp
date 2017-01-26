#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "HashTable.h"

using namespace std;

int main(int argc,char* argv[])
{
	HashTable *hashtable = new HashTable(10);
	
	hashtable->AddItem("Kohli","RCB");
    hashtable->AddItem("Rohit","MI");
    hashtable->AddItem("Gautam","KKR");
    hashtable->AddItem("Dhoni","Pune");
    hashtable->AddItem("Raina","GL");
    hashtable->AddItem("Jaddu","GL");
    hashtable->AddItem("Rahane","Pune");
    hashtable->AddItem("Ashwin","Pune");
    hashtable->AddItem("Bumraah","MI");
    hashtable->AddItem("Nehra","SRH");
    hashtable->AddItem("Yuvraaj","SRH");
    hashtable->AddItem("Dhawan","SRH");
    hashtable->AddItem("Yuvraaj","SRH");
    hashtable->AddItem("Yuvraaj","SRH");
    hashtable->AddItem("Bhuvi","SRH");
	
	hashtable->Print();
	
	string name = "";
	
	while(name != "*")
	{
		name ="";
		cout << "Search : " << name ;
		cin >> name ;
		cout << hashtable->Search(name) << endl;;
	}
	
	return 0;
}
