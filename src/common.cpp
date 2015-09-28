#include "common.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <stdexcept>
using namespace std;

void CheckFileStream( const ios& fileStream, const string& filePath )
{
	if ( !fileStream )
	{
		const string errorMessage = "Failed to open '" + filePath + "' : " + strerror( errno );
		throw runtime_error( errorMessage );
	}
}

streampos GetFileSize( const string& fileName )
{
	ifstream fin( fileName, ios::in | ios::ate | ios::binary );
	CheckFileStream( fin, fileName );
	return fin.tellg();
}

int ToInt( const string& str )
{
	stringstream ss( str );
	int ret;
	ss >> ret;
	return ret;
}
