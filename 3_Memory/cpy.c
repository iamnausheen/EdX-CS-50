#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;          // unsigned integer of byte 8 , uint8_t is now called as BYTE

int main(int argc, char* argv[])
{
    FILE* src = fopen(argv[1], "rb");        // read binary mode
    FILE* dst = fopen(argv[2], "wb");

    BYTE b;

    while (fread(&b, sizeof(b), 1, src) != 0)         // until bytes left to read
    {
        fwrite(&b, sizeof(b), 1, dst);
    }
}
