

#include "include.h"
#include <iomanip>

void printFileInHex(std::ifstream& file) {
    const int BYTES_PER_LINE = 16;
    const int ADDRESS_WIDTH = 8;

    int address = 0;
    char byte;
    char hexBuffer[BYTES_PER_LINE];

    while (file.get(byte)) {
        std::printf("%0*X: ", ADDRESS_WIDTH, address);

        for (int i = 0; i < BYTES_PER_LINE; ++i) {
            if (file) {
                hexBuffer[i] = byte;
                std::printf("%02X", static_cast<unsigned char>(byte));
            } else {
                std::printf("  ");
                hexBuffer[i] = 0;
            }
            if (i % 2 == 1) {
                std::printf(" ");
            }
            if (i != BYTES_PER_LINE - 1){
                if (!file.get(byte))
                    break;
            }
        }

        std::printf(" ");
        for (int i = 0; i < BYTES_PER_LINE; ++i) {
            if (hexBuffer[i] != '\0') {
                std::printf("%c", std::isprint(hexBuffer[i]) ? hexBuffer[i] : '.');
                hexBuffer[i] = '\0';
            }
        }

        std::printf("\n");

        address += BYTES_PER_LINE;
    }
}
