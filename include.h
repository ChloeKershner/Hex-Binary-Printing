

#ifndef A1_INCLUDE_H
#define A1_INCLUDE_H
#include <fstream>
const int HEX_BYTES_PER_LINE = 8;
const int HEX_BYTES_PER_PAIR = 2;
const int BINARY_BYTES_PER_LINE = 6;
const int BINARY_BYTES_PER_OCTET = 8;

void printFileInBinary(std::ifstream& file);

void printFileInHex(std::ifstream& file);

#endif //A1_INCLUDE_H
