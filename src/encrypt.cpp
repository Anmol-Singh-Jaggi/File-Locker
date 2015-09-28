#include "encrypt.h"
#include "common.h"
using namespace std;

void Encrypt( vector<unsigned char>& plainText, const string& key )
{
	int keyInt = ToInt( key );
	for ( size_t i = 0; i < plainText.size(); i++ )
	{
		plainText[i] = ( plainText[i] + keyInt ) % 128;
	}
}
