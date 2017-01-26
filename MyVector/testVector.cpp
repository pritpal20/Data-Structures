#include <iostream>
#include "my_vector.h"
#include <utility>
#include <unistd.h>

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
	vector<int> v1(10,0);
	
	srand(time(NULL));
	
	cout << "v1 size = " << v1.size() <<  endl;
	cout << "v1 capacity = " << v1.capacity() <<  endl;

	for(int i = 0 ; i < N ; i++)
	{
		int temp = rand()%100;
		cout << "Inserting element " << i+1 <<" ... " << temp << endl;
		v1.push_back(temp);
	}
	int i = 0;
	for(auto f: v1)
	{
		printf("v1[%d] = %d\n",i,f);
		i++;
	}
		
	cout << "size of vector v1 is " << v1.size() <<  endl;
	cout << "capacity  of vector v1 is " << v1.capacity() <<  endl;
	
	puts("testing reverse iterator ...\n");
	vector<int>::iterator it ;
	
	for( it = v1.rbegin(); it != v1.rend(); it++)
	{
		cout << "v1  = "  << *it << endl;
		sleep(1);
	}

	return 0;
}
