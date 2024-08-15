#include <iostream>
#include <string>
#include "include.h"

int main(int argc, char *argv[]) {

    bool binaryMode = false;
    std::string filename;

    // Check if the -b option is present
    if (argc == 3 && std::string(argv[1]) == "-b") {
        binaryMode = true;
        filename = argv[2];
    } else if (argc == 2) {
        filename = argv[1];
    } else {
        std::cerr << "Not correct arguments, please provide: " << argv[0] << " [-b] <filename>\n";
        return 1;
    }

    std::ifstream file(filename, std::ios::binary); // Open the file for binary reading
    if (!file) {
        std::cerr << "Error opening file\n";
        return 1;
    }

    // Determine which mode was chosen
    if (binaryMode) {
        printFileInBinary(file); // Call binary printing function
    } else {
        printFileInHex(file); // Call hexadecimal printing function
    }

    file.close(); // Close the file when done

    return 0;
}
