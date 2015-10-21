#ifndef LOCK_H_INCLUDED
#define LOCK_H_INCLUDED

#include <string>

// Generates the final SFX binary with the encrypted message and the size of the raw SFX binary appended to it
// rawSfxPath = Path to the raw SFX binary ( without anything appended to it )
// plainTextPath = Path to the file containing the plaintext to encrypt
// key = The encryption key
// appendedSfxPath = Path where the final SFX binary ( with the encrypted message and size appended ) should be created
void AppendToSfx( const std::string& rawSfxPath, const std::string& plainTextPath, const std::string& key, const std::string& appendedSfxPath );
#endif // LOCK_H_INCLUDED
