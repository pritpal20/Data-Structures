#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>


using std::cout ;
using std::endl;
using std::cin;

using namespace std;




int main(int argc,char *argv[])
{
	std::vector<int> v1;
	cout << "size of vector is " << v1.size() <<  endl;
	cout << "capacity  of vector is " << v1.capacity() <<  endl;
	
	int N = atoi(argv[1]);
	
	for(int i = 0 ; i < N ; i++ )
	{
		int temp = rand() % 100;
		cout << "Inserting ... " << temp << endl;
		v1.push_back(temp);
	}
	
	cout << "size of vector is " << v1.size() <<  endl;
	cout << "capacity  of vector is " << v1.capacity() <<  endl;
	
	vector<int>::iterator it = v1.begin();
	int i = 0;
	// for(vector<int>::iterator it = v1.begin() ; it != v1.end() ; it++ )
	// {
		// cout << "v1[" << i << "] = " << *it << endl;
		// i++;
	// }
	return 0;	
}