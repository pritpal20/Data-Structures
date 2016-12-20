#include "stack.h"
#include <iostream>

int main()
{
	stack<int> s1;
	
	for(int i = 0 ; i < 10 ; i++)
	{
		int temp = rand() % 100;
		printf("inserting ... %d \n",temp);
		s1.push(temp);
	}
	
	while(!s1.empty())
	{
		printf("size of stack is %d\n",s1.size());
		int temp = s1.top();
		printf("removing ... %d \n",temp);
		s1.pop();
	}
	return 0;
}