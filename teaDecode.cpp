#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstddef>
#include <vector>
#include <map>
#include <array>
#include <stdio.h>
#include <string.h>

using namespace std;

void decipherTea (unsigned int* v, unsigned int* w, unsigned int* k) 
{
    register unsigned int v0=v[0], v1=v[1], i, sum=0xC6EF3720;		// set up
    register unsigned int delta=0x9E3779B9;							// a key schedule constant
    register unsigned int k0=k[0], k1=k[1], k2=k[2], k3=k[3];		// cache key
    
    for(i=0; i<32; i++) 		
	{																// basic cycle start
        v1 -= ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
        v0 -= ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        sum -= delta;
    }																// end cycle
    
    w[0]=v0; w[1]=v1;
}

void TeaDecode (const std::string& str, const std::string& key, std::string* out)
{
    unsigned int v[2];
    unsigned int w[2];
    unsigned int k[4];
    unsigned int keybuffer [ 4 ];

    // Clear buffers
    memset ( v, 0, sizeof(v) );
    memset ( w, 0, sizeof(w) );
    memset ( k, 0, sizeof(k) );
    memset ( keybuffer, 0, sizeof(keybuffer) );
    out->clear ();

    // Count the number of passes that we need
    int numBlocks = str.length() / 4;
    int numPasses = numBlocks - 1;

    if ( numPasses <= 0 )
        return;

    // Process the key
    int len = key.length ();
    if ( len > 16 )
        len = 16;
    memcpy ( keybuffer, key.c_str(), len );
    for ( int i = 0; i < 4; ++i )
        k[i] = keybuffer[i];

    // Create a temporary buffer to store the result
    unsigned char* buffer = new unsigned char [ numPasses * 4 + 4 ];
    memset ( buffer, 0, numPasses * 4 + 4 );

    // Decode it!
    const char* p = str.c_str();
    v[1] = *(unsigned int*)&p[numPasses * 4];
    for ( int i = 0; i < numPasses; ++i )
    {
        v[0] = *(unsigned int*)&p[(numPasses-i-1)*4];
        decipherTea ( &v[0], &w[0], &k[0] );
        *(unsigned int*)&buffer[(numPasses-i-1)*4] = w[0];
        v[1] = w[1];
    }

    out->assign ( (char *)buffer, numPasses*4 );
    delete [] buffer;
}

int main(void)
{
	printf("--Tea Decryptor--\n\n");
	// Streams
	ifstream fileIn;
	ofstream fileOut;
	// Data system
	string f1,f2,f3;
	string *fileName = &f1; // File Name
	string *key = &f2; // Key 
	string *data = &f3; // Data 
	string *name = new string;
	// Key input
	printf("Enter the key\n>");
	getline(cin,*key);
	// Name system
	printf("Please enter the name of the file you want to open\n>");
	getline(cin,*fileName);
	// Input System
    fileIn.open(*fileName, ios::in | ios::binary);
    string str((istreambuf_iterator<char>(fileIn)), istreambuf_iterator<char>()); 
    fileIn.close();
	printf("File Was Loaded!\n");
	// Tea System
	string outdata;
	TeaDecode(str, f2, &outdata);
	str = "0";
	// Write Data
	printf("Please enter the name of the output file\n>");
	getline(cin,*fileName);
	fileOut.open(*fileName, ios::out | ios::binary);
    fileOut.write(outdata.c_str(), outdata.size());
	printf("Done! Decryption Successful!\n");
}
