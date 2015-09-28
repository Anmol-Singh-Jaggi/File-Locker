#ifndef COMMON_TEMPLATE_CPP_INCLUDED
#define COMMON_TEMPLATE_CPP_INCLUDED

#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// Writes the contents of a vector to a file, starting from vec[start]
template<typename T>
void VectorToFile( const vector<T>& vec, ofstream& file, const size_t& start = 0 )
{
	file.write( reinterpret_cast<const char*>( &vec[start] ), ( vec.size() - start )*sizeof( T ) );
}

// Reads the contents of a file into a vector,
// skipping the first 'start' bytes from the beginning of the file
// and the first 'end' bytes from the end of the file
template<typename T>
void FileToVector( ifstream& file, vector<T>& vec, const streampos& start = 0, const streampos& end = 0 )
{
	// First calculate how many bytes to read
	file.seekg( start );
	const streampos first = file.tellg();

	file.seekg( -end, ios::end );
	const streampos last = file.tellg();

	// bufferSize is the total number of bytes to read
	const size_t bufferSize = last - first;

	// Calculate the size of vector required to hold the data from the file
	const size_t vecSize = bufferSize / sizeof( T );
	vec.resize( vecSize );

	file.seekg( start );
	file.read( reinterpret_cast<char*>( &vec[0] ), vec.size() * sizeof( T ) );
}

// Converts an object into a string
template<typename T>
string ToString( const T& obj )
{
	stringstream ss;
	ss << obj;
	return ss.str();
}

#endif // COMMON_TEMPLATE_CPP_INCLUDED
