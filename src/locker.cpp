#include <iostream>
#include <string>
#include "append_sfx.h"
using namespace std;

int main( int argc, char* argv[] )
{
	try
	{
		if ( argc < 4 )
		{
			cout << "Usage : " << argv[0] << " <plain_text_path> <key> <output_path>\n";
			return -1;
		}
		const string rawSfxPath = "bin/sfx";
		const string plainTextPath = argv[1];
		const string key = argv[2];
		const string appendedSfxPath = argv[3];

		AppendToSfx( rawSfxPath, plainTextPath, key, appendedSfxPath );
	}
	catch ( const exception& ex )
	{
		cerr << ex.what() << endl;
		return -1;
	}
}
