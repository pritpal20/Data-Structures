#include "configure.h"

configure::configure()
{
	memset(filename,'\0',sizeof(filename));
	std::cout << "Default constructor " << std::endl;
}
	
configure::configure(char* file)
{
	memset(filename,'\0',sizeof(filename));
	std::cout <<"Parametarized constructor " << std::endl;
	strcpy(filename,file);
}

char* configure::getfilename()
{
	return filename;
}

void configure::readiniFile()
{
	std::ifstream infile(filename);
	
	std::string line;
	std::string tagname;
	std::string str;
	while(getline(infile,line))
	{
		if(line[0] == '[')
		{
			//std::cout << line <<" size is "<<strlen(line.c_str())<< std::endl;
			str = trimEnds(line);
			//std::cout << "tags ="<< str << std::endl;
			tagname = str;
			map1 *field= new map1();
			tagpair.insert(std::pair<std::string,map1*>(str,field));
		}
		else
		{
			//std::cout << "tag name is " <<str<< "   ....\n";
			map2::iterator it = tagpair.find(tagname);
			map1 *field = it->second;
			
			std::istringstream buf(line);
			std::istream_iterator<std::string> beg(buf), end;
			std::vector<std::string> tokens(beg, end); // done!

			for(int i= 0; i < tokens.size();i++)
			{
				//std::cout << '"' << tokens[i] << '"' << '\n';
				field->insert(std::pair<std::string,std::string>(tokens[i],tokens[i+1]));
				i++;
			}
		}
	}
	
	printMap();
}

std::string configure::trimEnds(std::string tagname)
{
	
	return tagname.substr(1,strlen(tagname.c_str())-2);
}

void configure::printMap()
{
	
	map2::iterator it2;
	map1::iterator it1;
	
	std::cout << "Map contains:\n";
	
	for (it2=tagpair.begin(); it2!=tagpair.end(); ++it2)
	{
		std::cout<< " => "  << it2->first << '\n';
		map1 *fieldmap = it2->second;
		for(it1=fieldmap->begin(); it1!=fieldmap->end(); ++it1)
			std::cout << it1->first << " => " << it1->second << '\n';
		
	}
}

std::string configure::getFieldValue(std::string tagname,std::string fieldname)
{
	map2::iterator it2 = tagpair.find(tagname);
	if(it2 == tagpair.end())
		return "NULL";
	
	map1 *fieldvaluemap = it2->second;
	
	map1::iterator it1 = fieldvaluemap->find(fieldname);
	
	if(it1 == fieldvaluemap->end())
		return "NULL";
	
	return it1->second;
}

bool configure::IsfileExist()
{
  struct stat   buffer;
   if(stat (filename, &buffer) == 0)
   {
	   return SUCCESS;
   }
   return FAIL;
}

bool configure::checkfile()
{
	if( IsfileExist())
	{
		std::cout << "config file "<<filename <<" doesnt exists \n" ;
		return FAIL;
	}
	std::string line ;
	std::ifstream infile(filename);
	
	while(getline(infile,line))
	{
		if( line.empty()) continue;
		int end = strlen(line.c_str());
		if( (line[0] =='[' && line[end -1] != ']') || (line[end-1] ==']' && line[0] != '[') )
		{
			std::cout << "reached here "<<line<<"  size is "<<end<<"\n";
			std::cout << line[0] <<"" <<line[end -1] <<"\n";
			return FAIL;
		}
		
		if(line[0] !='[' )
		{
			//std::cout << "tag name is " <<str<< "   ....\n";
			std::istringstream buf(line);
			std::istream_iterator<std::string> beg(buf), end;
			std::vector<std::string> tokens(beg, end); // done!
			if(tokens.size() != 2 )
			{
				std::cout << "REached here : " <<line << " \n";
				return FAIL;
			}
		}
	}
	
	return SUCCESS;
}

configure::~configure()
{
	std::cout << "Destructor called " << std::endl;
}
