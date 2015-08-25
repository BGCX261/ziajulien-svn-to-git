#include "Parsing.h"
#include "tinyxml.h"

using namespace std;

Parsing::Parsing(void)
{
}

Parsing::~Parsing(void)
{
}

string Parsing::check(string entry)
{
	temp::iterator it;
	
	for (it = mapper.begin (); it != mapper.end (); ++it)
	{
		std::string key = (*it).first;
		string number = (*it).second;

		if (strcmp(key.c_str(), entry.c_str()) == 0)
		{
			return(number);
		}
	}


	return "Erreur";
}

map<string,string> Parsing::getParser()
{
	temp::iterator it;

	for (it = mapper.begin (); it != mapper.end (); ++it)
	{
		std::string key = (*it).first;


		string number = (*it).second;
	}
	return mapper;
}

void	Parsing::clearMap()
{

	mapper.clear();
}

void Parsing::parser(string fichier)
{
titre = "";
ligne = "";
separation = ":";

int count2;

count2 = 0;
count = 0;
swap = 0;
string nono[10];

while (count < fichier.length() )
{

	if (fichier[count] == '\n' && fichier[count + 1] != '\n')
	{
		if (swap == 0)
		{
		istringstream	iss(ligne);
		
		while ( std::getline( iss, nono[count2] , ' ' ) )
			{
				
				count2++;
			}
		
for (int i=0; i<nono[0].length()  ; ++i)
{
  nono[0][i] = std::tolower(nono[0][i], std::locale());
}
		mapper[nono[0]] = nono[1];
		mapper["Protocole"] = nono[2];
		swap = 1;
		ligne = "";
		}
		else if (swap == 1)
		{
			count2 = 0;
			istringstream iss(ligne);
			while ( std::getline( iss, nono[count2] , ':' ) )
			{
				
				count2++;
			}


			for (int i=0; i<nono[0].length()  ; ++i)
				{
					nono[0][i] = std::tolower(nono[0][i], std::locale());
				}
			mapper[nono[0]] = nono[1].substr(nono[1].find_first_of(' ')+1,nono[1].length());
			ligne = "";
		}
		
	}
	else if (fichier[count] == '\n' && fichier[count + 1] == '\n')
	{
		istringstream iss(ligne);
		count2 = 0;
			while ( std::getline( iss, nono[count2] , ':' ) )
			{
				count2++;
			}

			for (int i=0; i<nono[0].length()  ; ++i)
{
  nono[0][i] = std::tolower(nono[0][i], std::locale());
}
			mapper[nono[0]] = nono[1].substr(nono[1].find_first_of(' ')+1,nono[1].length());
			ligne = "";	
			count++;
			swap = 2;
	}
	else if (swap == 2)
	{
		if (fichier[count] != 13)
			if(fichier[count] == 32)
		ligne = ligne + fichier[count];
	}
	else
	{
		if (fichier[count] != 13)
		ligne = ligne + fichier[count];
	}
	count++;
}



mapper["body"] = ligne;

	temp::iterator it;

	for (it = mapper.begin (); it != mapper.end (); ++it)
	{
		std::string key = (*it).first;


		string number = (*it).second;
		cout << key << endl;
	}
	
}