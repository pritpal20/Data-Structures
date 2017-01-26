#include "HashTable.h"

HashTable::HashTable(int num)
{
	this->num = num ;
	
	Hash = new item[num];
	
	for(int i =0;i < num ; i++ )
	{
		Hash[i].Table = new itemNode;
		Hash[i].Table->name = "empty";
		Hash[i].Table->team = "empty";
	}
}


int HashTable::Hashing(const string key)
{
	int sum = 0;
	for(int i =0 ; i< key.length() ; i++ )
	{
		sum+=(int)key[i];
	}
	return sum % num;
}

void HashTable::Print()
{
	for(int i =0;i < num ; i++ )
	{
		cout << "Index : " << i << endl;
		cout << "Player name : "<< Hash[i].Table->name << endl;
		cout << "Team : " << Hash[i].Table->team << endl;
		cout << "===========================" << endl;
	}
}

void HashTable::AddItem(string key,string value)
{
	//tolower(key);
	int index = Hashing(key);
	
	if(Hash[index].Table->name == "empty")
	{
		Hash[index].Table->name = key;
		Hash[index].Table->team = value;
		cout<<key<<" is added at index "<<index<<endl;
		return;
	}
	else 
	{
		itemNode *current = Hash[index].Table;
		 //current = Hash2[index];
		
		while(current->next != NULL && current->name != key)
			current = current->next;
			
		if(current->next == NULL && current->name != key)
        {
            current->next = new itemNode;
            current->next->name = key;
            current->next->team = value;
            current->next->next = NULL;
            cout<<key<<" is added at index "<<index<<endl;
        }
        else
        {
            current->team = value;
            cout<<key<<" is updated at index "<<index<<endl;
        }
	}	
}

string HashTable::Search(string key)
{
	int index = Hashing(key);
	
	itemNode *current = Hash[index].Table;
	
	while(current)
	{
		if(current->name == key)
			break;
		current = current->next;
	}
	if(current == NULL)
		return "Not Found";
	else
		return current->team;
}


