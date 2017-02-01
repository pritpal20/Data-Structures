#include "link_list.h" 
#include <stdlib.h>
#include <time.h>
#include <time.h>
#include <typeinfo>
using std::cin;

int main()
{
	srand(time(NULL));
	LinkList<int> *l1 = new LinkList<int>;
	LinkList<int>::iterator it = l1->Front();

	for(int i = 1 ; i <= 10 ; i++)
	{
		l1->PushBack(i*10);
	
	}
	l1->ListPrint();
	//l1->PrintReverse();

	cout << "Enter option " << endl ;
	char option = 'a';

	while(option != 'q')
	{
		cout << "i for insert , d for delete , .. " << endl;

		cin >> option ;
		switch(option)
		{
			case 'i' :
			{
				int temp = rand()%100;
				cout << "inserting .... " << temp << endl; 
				l1->PushBack(temp);
				l1->ListPrint();
			}
			break;
			case 'D' :
			{
				int pos = rand()%l1->GetLength();
				l1->PopBack();
				l1->Print();
				break;
			}
			case 'd' :
			{	
				try
				{
					if(l1->GetLength() == 0 )      
						throw "divide by zero error ";
						int pos = rand()%l1->GetLength();

					cout << "Deleting .. List List1[" << pos <<"] = "  << l1->Print(pos) <<  endl;	
					l1->Remove(pos);
			 		l1->ListPrint();
				}
				catch(const char *error)
				{
					cout << "Exception : " << error << endl;
				}
				catch(...)
				{
					cout << " caught exception : " << endl;
				}
			}
			break;
			case 'p' : 
				l1->Print();
				break;
			 case 'l' :
                                l1->ListPrint();
                                break;

			case 'P' :
			{
				int pos ;
				cin >> pos;
				cout << " The Element at " << pos << " is " << l1->Print(pos) << endl;
                                l1->Print();
				break;
			}
			case 'c' :
                                system("clear");
				break;
			case 'q' :
                                system("clear");
                        	break;
			default : 
				cout << "Invalid option selected " << endl;

		}
	}	
	return 0;
}
