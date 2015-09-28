#include "decrypt.h"
#include "common.h"
using namespace std;

void Decrypt( vector<unsigned char>& cipherText, const string& key )
{
	int keyInt = ToInt( key );
	for ( size_t i = 0; i < cipherText.size(); i++ )
	{
		cipherText[i] = ( cipherText[i] - keyInt + 128 ) % 128;
	}
}
