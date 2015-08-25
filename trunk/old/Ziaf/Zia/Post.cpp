#include "Post.h"

Post::Post(void)
{
}

Post::~Post(void)
{
}

std::string Post::GetReponse()
{
	return this->_Reponse;
}

std::string Post::GetType()
{
	return this->_Type;
}