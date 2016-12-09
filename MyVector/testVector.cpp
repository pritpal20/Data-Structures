#include <iostream>
#include "my_vector.h"

#include <time.h>


using std::cout ;
using std::endl;
using std::cin;


int main(int argc,char *argv[])
{
	//vector<int> v1 = new v1(12);
	
	if(argc < 2 )
	{
		cout << "Usage ./a.out args1 " << endl;
		exit(1);
	}
	
	int N = atoi(argv[1]);
	vector<int> v1;
	
	srand(time(NULL));
	
	cout << "size of vector v1 is " << v1.size() <<  endl;
	cout << "capacity  of vector v1 is " << v1.Capacity() <<  endl;

	for(int i = 0 ; i < N ; i++)
	{
		int temp = rand()%100;
		cout << "Inserting element " << i+1 <<" ... " << temp << endl;
		v1.push_back(temp);
	}
	
	for(int i = 0 ; i < v1.size() ; i++)
	{
		cout << "vector v1[" << i << "] = " << v1[i] << endl;
	}
	
	v1 = v1;
	
	cout << "size of vector v1 is " << v1.size() <<  endl;
	cout << "capacity  of vector v1 is " << v1.Capacity() <<  endl;

	return 0;
}
