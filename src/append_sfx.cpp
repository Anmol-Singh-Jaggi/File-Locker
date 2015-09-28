#include "append_sfx.h"
#include "common.h"
#include "common_template.cpp"
#include "encrypt.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void AppendToSfx( const string& rawSfxPath, const string& plainTextPath, const string& key, const string& appendedSfxPath )
{
	// Open the output file where the appended SFX will be stored
	ofstream appendedSfxFile( appendedSfxPath, ios::binary );
	CheckFileStream( appendedSfxFile, appendedSfxPath );

	vector<unsigned char> buffer;

	// Open the raw SFX
	ifstream rawSfxFile( rawSfxPath, ios::binary );
	CheckFileStream( rawSfxFile, rawSfxPath );
	// Read it into a buffer
	FileToVector( rawSfxFile, buffer );
	// Write the buffer to the output file
	VectorToFile( buffer, appendedSfxFile );

	// Open the plaintext file
	ifstream plainTextFile( plainTextPath, ios::binary );
	CheckFileStream( plainTextFile, plainTextPath );
	// Read it into a buffer
	FileToVector( plainTextFile, buffer );
	// Encrypt it
	Encrypt( buffer, key );
	// Write the buffer containing the encrypted text to the output file
	VectorToFile( buffer, appendedSfxFile );

	const streampos rawSfxSize = GetFileSize( rawSfxPath );
	// Write the size of raw SFX to the output file
	vector<streampos> rawSfxSizeVec( 1, rawSfxSize );
	VectorToFile( rawSfxSizeVec, appendedSfxFile );

}
