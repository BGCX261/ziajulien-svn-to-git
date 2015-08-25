#include "ResponseStream.h"

ResponseStream::ResponseStream(void)
{
}

ResponseStream::ResponseStream(std::stringstream* t)
{
	temp << t->str().c_str();
}

ResponseStream::ResponseStream(std::stringstream t)
{
}

ResponseStream::~ResponseStream(void)
{
}

size_t              ResponseStream::read(char* buff, size_t size)
{
	size_t before;
	before = temp.str().length();
	if (before < size)
		size = before;
	temp.read(buff,(std::streamsize)size);
	return size;

}

/**
*  Return the underlying (std::iostream) stream
*  that is used for the content
*  @return the underlaying stream
*/
std::iostream&      ResponseStream::getContent()
{

	return temp;
}

/**
*  Returns wheter we are a the end of the stream or not
*  @return stream position status
*/
bool                ResponseStream::completed() const
{
	return true;
}

/**
*  Returns the value of the good method of the underlying stream
*  @return whether the stream is good for i/o operations or not
*/
bool                ResponseStream::good() const
{
	return true;
}

/**
*  Returns the size of the stream (the number of caracters that you can read)
*  @return the size empof the stream
*/ 
size_t              ResponseStream::getSize() const
{
	return temp.str().length();
}