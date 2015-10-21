#ifndef ENCRYPT_H_INCLUDED
#define ENCRYPT_H_INCLUDED

#include <vector>
#include <string>

// Encrypts the input text using a key
void Encrypt( std::vector<unsigned char>& plainText, const std::string& key );

#endif // ENCRYPT_H_INCLUDED
