#include "sfx.h"
#include "common.h"
#include "decrypt.h"
#include "common_template.cpp"
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

void ExtractMessage( const string& appendedSfxPath, const string& key, const string& messageOutputPath )
{
	// Open the appended SFX
	ifstream appendedSfxFile( appendedSfxPath, ios::binary );
	CheckFileStream( appendedSfxFile, appendedSfxPath );

	vector<streampos> rawSfxSizeVec;
	// Read the raw SFX size from the appended SFX
	FileToVector( appendedSfxFile, rawSfxSizeVec, GetFileSize( appendedSfxPath ) - streampos( sizeof( streampos ) ) );
	const streampos rawSfxSize = rawSfxSizeVec[0];

	vector<unsigned char> buffer;
	// Read the message from the appended SFX into the buffer
	FileToVector( appendedSfxFile, buffer, rawSfxSize, streampos( sizeof( streampos ) ) );

	// Decrypt the message
	Decrypt( buffer, key );

	// Open the message output file
	ofstream messageOutputFile( messageOutputPath, ios::binary );
	CheckFileStream( messageOutputFile, messageOutputPath );

	// Write the decryped message to the output file
	VectorToFile( buffer, messageOutputFile );
}
