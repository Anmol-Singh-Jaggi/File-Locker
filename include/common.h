#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <fstream>
#include <string>

// Checks if the file stream is OK or not
void CheckFileStream( const std::ios& fileStream, const std::string& filePath );

// Returns the size of a file in bytes
std::streampos GetFileSize( const std::string& filePath );

// Converts a string to int
int ToInt( const std::string& str );

#endif // COMMON_H_INCLUDED

