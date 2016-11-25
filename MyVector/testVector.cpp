#include <iostream>
#include "my_vector.h"
#include <stdlib.h>
#include <time.h>


using std::cout ;
using std::endl;
using std::cin;


int main(int argc,char *argv[])
{
	//vector<int> v1 = new v1(12);
	vector<int> v1;	

	srand(time(NULL));

	for(int i = 0 ; i < v1.size() ; i++)
	{
		int temp = rand()%100;
		cout << "Inserting element " << i+1 <<" ... " << temp << endl;
		v1.push_back(temp);
	
	}
	
	vector<int> v2(5);
	for(int i = 0 ; i < v2.size() ; i++ )
	{
		cout << "vector v2[" << i << "] = " << v2[i] << endl;

	}

	return 0;
}
