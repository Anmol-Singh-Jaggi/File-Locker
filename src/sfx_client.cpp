#include <iostream>
#include <string>
#include "sfx.h"
#include "common.h"
using namespace std;

int main( int argc, char* argv[] )
{
	try
	{
		if ( argc < 3 )
		{
			cout << "Usage : " << argv[0] << " <encryption key> <message_output_path>\n";
			return -1;
		}
		const string appendedSfxPath = argv[0];
		const string key = argv[1];
		const string messageOutputPath = argv[2];

		ExtractMessage( appendedSfxPath, key, messageOutputPath );
	}
	catch ( const exception& ex )
	{
		cerr << ex.what() << endl;
		return -1;
	}
}

