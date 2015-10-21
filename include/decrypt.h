#ifndef DECRYPT_H_INCLUDED
#define DECRYPT_H_INCLUDED

#include <vector>
#include <string>

// Decrypts the input text using a key
void Decrypt( std::vector<unsigned char>& cipherText, const std::string& key );

#endif // DECRYPT_H_INCLUDED
