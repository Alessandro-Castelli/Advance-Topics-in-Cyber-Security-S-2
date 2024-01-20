/*
 * AES-128 Encryption in CBC Mode - Main File
 */
#include "stdint.h"
#include "masked_combined.h"
#include "rand.h"
//#include "elmo-funcs.h"

// Fixed 16 Byte Key:
uint8_t key[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// Initializing lfsr 
unsigned int rngSeed1 = 0; // Framework for embedded testing: get_rand();
unsigned int rngSeed2 = 0;// Framework for embedded testing: get_rand();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(void) {

    init_lfsrs(rngSeed1, rngSeed2);
    uint8_t ciphertext[16];
    uint8_t plaintext[16];

    //Frame work for side channel testing: execute an encryption 1000 times
    //for(int number_of_encryption=0; number_of_encryption < 1000 ;number_of_encryption++){
    // Generating a random plaintext 
        for(int i=0; i < 16; i++){
            plaintext[i]= getRand();
        }
        Encrypt(ciphertext, plaintext, key);         
   // }
    
}