# TEA_Implementation_cpp

This project was made for educational purposes but can serve practical ones too. 
You can use the algorithm to encrypt and decrypt (important) text.

## A few words about symmetric cryptography

- Symmetric encryption is a type of encryption where only one (secret) key is used to both encrypt and decrypt (electronic) information. 
The entities communicating via symmetric encryption must exchange the key so that it can be used in the decryption process.
- So, symmetric cryptography encodes a message via transformations using a secret key known only to the sender and receiver. 
The original message can be viewed by going through reversing these transformations using the same pre-shared key. 
The process of obfuscating the original text is called encryption, while the reverse process is called decryption. 
There are many standards of the type(AES, DES e.t.c.). One of them based upon the Fiestel cipher structure is the Tiny Encryption Algorithm (TEA).
 
## What is TEA (Tiny Encryption Algorithm)

In cryptography, the Tiny Encryption Algorithm (TEA) is a block cipher notable for its simplicity of description and implementation, 
designed by David Wheeler and Roger Needham of the Cambridge Computer Laboratory. It is asymmetric block cipher, based upon the Fiestel cipher structure
Learn more: https://en.wikipedia.org/wiki/Tiny_Encryption_Algorithm

## How to use

- teaEncode.cpp is used to encrypt a file and teaDecode.cpp is used to decrypt it. You can of course see the implementation and change it as you see fit.
- 2 executable files (for Windows OS) with the same name are provided if you want to use TEA without compilation. By default in plaintext.txt there is the initial
plaintext. In encrypted.txt, the text after the encryption is generated and in decrypted.txt the text after decryption is generated, but you can use another filenames.
It is asked while you run the executables.

## Copyright and License

[![License](http://img.shields.io/:license-mit-blue.svg?style=flat-square)](http://badges.mit-license.org)

- **[MIT license](http://opensource.org/licenses/mit-license.php)**
- Copyright 2020 © <a href="https://github.com/NasosG" target="_blank">NasosG</a>.

## Copyright claims

The TEA algorithm wasn't designed by me, but by David Wheeler and Roger Needham of the Cambridge Computer Laboratory. No claim by me & those who use this project!!<br>
I just made an implementation of the algorithm for educational purposes.

**Thanks for reading**    
