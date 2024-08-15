//
// Created by Chloe Kershner on 2/14/24.
//

#include "include.h"
#include <cctype>
void printFileInBinary(std::ifstream& file) {

    // Variables for tracking address and bytes read
    int address = 0;
    char byte;
    // Buffer for characters to print
    char charBuffer[BINARY_BYTES_PER_LINE];

    // Read the file byte by byte
    while (file.get(byte)) {
        // Print address
        std::printf("%08X: ", address);

        // Print binary representation of each byte
        for (int i = 0; i < BINARY_BYTES_PER_LINE; ++i) {
            for (int j = BINARY_BYTES_PER_OCTET - 1; j >= 0; --j) {
                std::printf("%d", (byte >> j) & 1); // Print each bit
            }
            charBuffer[i] = byte;
            std::printf(" ");
            if (i != BINARY_BYTES_PER_LINE - 1){
                if (!file.get(byte)) // Read next byte
                    break;
            }
        }


        // Print characters corresponding to bytes
        for (int i = 0; i < BINARY_BYTES_PER_LINE; ++i) {
            if (charBuffer[i] != '\0') {
                std::printf("%c", std::isprint(charBuffer[i]) ? charBuffer[i] : '.');
                charBuffer[i] = '\0';
            }
        }
        std::printf("\n");

        // Update address
        address += BINARY_BYTES_PER_LINE;
    }
}
