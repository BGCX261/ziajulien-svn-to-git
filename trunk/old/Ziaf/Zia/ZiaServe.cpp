#include "ZiaServe.h"
#include <iterator>
#include <map>

ZiaServe::ZiaServe(int p): serveur(p)
{
}

ZiaServe::ZiaServe()
{
}


ZiaServe::~ZiaServe(void)
{

}

std::string ZiaServe::do_client()
{
	Requette *temp = do_execute(getParse()->getParser());
	std::string rep = temp->GetReponse();
	delete temp;
	return rep;
}