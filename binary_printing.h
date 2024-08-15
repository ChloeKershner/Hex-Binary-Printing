//
// Created by Chloe Kershner on 2/14/24.
//

#ifndef A1_BINARY_PRINTING_H
#define A1_BINARY_PRINTING_H
#include <fstream>

// Constants for binary printing
const int BINARY_BYTES_PER_LINE = 6;
const int BINARY_BYTES_PER_OCTET = 8;

// Function declaration
void printFileInBinary(std::ifstream& file);

#endif //A1_BINARY_PRINTING_H
