#ifndef _Parsing_
#define _Parsing_
#include <iostream>
#include <sstream>
#include <iterator>
#include <map>
#include <string>
#include <locale>
using namespace std;
class Parsing
{
private :
	typedef std::map<string,string> temp;
	typedef std::map<string,string> temp2;

string fichier ;
string titre;
string ligne;
string separation;
string uncarac;
temp mapper;
//temp2 Xmlparsing;
int  count;
int swap;
int compt;
int espace;
string ligne2;
public:
	Parsing(void);
	string check(string entry);
	std::map<string,string> getParser();
	std::map<string,string> getXML();
	void parser(string);
	void	clearMap();
	~Parsing(void);
};

#endif