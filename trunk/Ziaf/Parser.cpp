#include "Parser.h"
#include "stdlib.h"
Parser::Parser()
{
}
Parser::~Parser()
{
}
void Parser::firstline(std::string ligne, IHttpRequest* req)
{
	int count2 = 0;
	std::string nono[10];
	std::string urisepare[2];
	std::istringstream iss(ligne);

	while ( std::getline( iss, nono[count2] , ' ' ) )
		count2++;

	count2 = 0;
	std::istringstream isss(nono[1]);
	while ( std::getline( isss, urisepare[count2] , '?' ) )
		count2++;

	req->setCommand(nono[0]);
	req->setUri(urisepare[0]);
	std::cout << nono[2].find("\r") << std::endl;
	req->setProtocol(nono[2].substr(0,nono[2].find("\r")));
	if (count2 >= 1)
		req->setUriQuery(urisepare[1]);

}
void Parser::separe(zAPI::IHttpRequest *req, std::string ligne)
{
	int count2 = 0;
	std::string nono[10];

	std::istringstream iss(ligne);
	count2 = 0;
	while ( std::getline( iss, nono[count2] , ':' ) )
	{
		count2++;
	}
	for (int i=0; i<nono[0].length()  ; ++i)
	{
		nono[0][i] = tolower(nono[0][i]);
	}
	nono[1] = nono[1].substr(nono[1].find_first_of(' ')+1,nono[1].length());
	req->setParam(nono[0], &nono[1]);
}
void Parser::parse(zAPI::IHttpRequest *req, std::string file)
{
	std::string ligne;
	std::string nono[10];
	int count;
	int count2 = 0;
	std::string query = "";
	int verif = 0;
	count = 0;
	int line = 0;
	while (count < file.length() )
	{
		if (file[count] == '\n' && file[count + 1] != '\n' && line >= 0)
		{

			if (line == 0)
			{
				Parser::firstline(ligne, req);	
				++line;
				ligne = "";
			}
			else
			{
				Parser::separe(req, ligne);
				ligne = "";
			}
		}
		else if (file[count] == '\n'   && file[count + 1] == '\n')
		{
			//line = -1000;
			Parser::separe(req, ligne);
			ligne = "";
			++count;
		}
		else
			ligne = ligne + file[count];
		++count;
	}
	std::stringstream temp;
	temp << ligne;
	std::cout << temp.str().c_str() << std::endl;
	req->setBodyStream(new ResponseStream(&temp));	
}
