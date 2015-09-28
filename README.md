**Description**  
An application which can encrypt any file with a password and make a self-extracting binary for unlocking it.

**Working**  
The self-extracting (SFX) binary created by this application consists of two parts -:
 - *The extraction executable* - The actual self-extracting executable which is responsible for extracting and decrypting the message.
 - *Encrypted message and other metadata* - The encrypted message and other information required for its extraction, appended at the end of the extraction executable.

The extraction executable contains the logic to read itself and determine where the encrypted message is located.  
Hence, when the SFX binary is executed, it asks the user for the decryption key, reads the encrypted message from itself, decrypts it and writes the deciphered message to an output file.  
Since, we cannot use the extraction executable to append the data to itself ( we cannot edit any file while it is being executed ), we need to delegate this responsibility to another executable.  

But how to make an executable know the location of any data appended to it by another executable??  
One solution is to append the size of the extraction executable at the end of the message, so that the SFX binary knows the location where the extraction executable ends and the message part starts.  

But then again, how will we determine where does the message end and the size description start??  
We could pre-allocate some fixed number of bytes for the size description to accomplish this.
This number should be enough to represent the maximum file-size possible on a given platform.  
In this application, `sizeof(std::streampos)` is used for this purpose.  

The executable *`sfx`* is the extraction executable, and the encryption message is appended to this executable.  
Another executable *`locker`* is used for reading the plaintext, encrypting it, and appending the encrypted message to *`sfx`*.  

![Image 1](https://raw.githubusercontent.com/Anmol-Singh-Jaggi/File-Locker/master/screenshots/1_SFX%20without%20anything%20appended.png)  
*The SFX binary without anything appended*  

![Image 2](https://raw.githubusercontent.com/Anmol-Singh-Jaggi/File-Locker/master/screenshots/2_Message%2835%20bytes%29%20appended%20to%20SFX.png)  
*A message of length 35 bytes appended to the SFX binary*  

![Image 3](https://raw.githubusercontent.com/Anmol-Singh-Jaggi/File-Locker/master/screenshots/3_Size%2816%20bytes%29%20appended%20to%20message.png)  
*The size of the extraction executable appended to message*  
*The size of `std::streampos` on this platform is 16 bytes*  

**Requirements**
 - GNU C++ compiler
 - GNU make

**Installation**
 - Execute `./INSTALL`

**Usage**
 - After installation, there should be 2 executables in *`bin`* - *`sfx`* and *`locker`*.
 - *`sfx`* is the self-extracting executable which is loaded by *`locker`* dynamically and hence, should not be executed directly.
 - To append the message to *`sfx`*, execute `bin/locker`.  
It needs the following command-line arguments to execute, given in the specified order -:  
    - *`plaintext_path`* - The path to the file containing the message to encrypt
    - *`key`* - An integer to be used as the key for the encryption algorithm ( in this case, a simple substitution cipher )
    - *`output_path`* - The path to the file in which the new self-extracting executable with the appended message will be created  

 - The SFX executable should have been generated at *`output_path`* as provided in the above step. Execute this SFX binary.  
It needs the following command-line arguments to execute, given in the specified order -:  
    - *`key`* - The key to be used for decryption ( in this case, same as the one provided during encryption )
    - *`output_path`* - The path to the file where the decrypted message will be written
 - A script containing a sample of the execution steps has been provided in the 'run' script. Type `./run` to execute it.

**TODO**
 - Simplify the makefile.
 - Add support for conserving the name of the input file.
 - Add support for locking folders.
 - Add testing code.
