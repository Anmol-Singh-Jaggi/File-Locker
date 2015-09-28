#ifndef UNLOCK_H_INCLUDED
#define UNLOCK_H_INCLUDED

#include <fstream>
#include <string>

// Extracts the encrypted message to the given path after decrypting it
// appendedSfxPath = Path to the appended SFX (argv[0])
// key = The decryption key
// messageOutputPath = The path where the file containing the extracted message should be created
void ExtractMessage( const std::string& appendedSfxPath, const std::string& key, const std::string& messageOutputPath );

#endif // UNLOCK_H_INCLUDED
