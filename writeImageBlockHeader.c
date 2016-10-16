#include "GIFencoder.h"

#include <stdio.h>
#include <math.h>
#include <stdint.h>

void writeImageBlockHeader(imageStruct* image, FILE* file) {
    /*
    1 byte (0x2c)
    2 bytes "Image left position"
    2 bytes "Image Top position"
    2 bytes "Image width"
    2 bytes "Image height"
    1 byte  - LCTF
            - Interlace flag
            - Sort flag
            - Reserved
            - Reserved
            - Size of local color table
            - Size of local color table
            - Size of local color table
    n bytes "Local color table"
    1 byte "Minimum code size"
    ...
    1 byte (0x00)
    */
    
    int n, sort_flag, interlace_flag, res;
    int left = 0, top = 0;
    
    interlace_flag = 0;
    sort_flag = 0;
    res = 0;
    n = 0;
    
    fprintf(file, "%c", (char)(0x2c));
    fprintf(file, "%c", (char)(left & 0xFF));
    fprintf(file, "%c", (char)((left >> 8) & 0xFF));
    fprintf(file, "%c", (char)(top & 0xFF));
    fprintf(file, "%c", (char)((top >> 8) & 0xFF));
    fprintf(file, "%c", (char)(image->width & 0xFF));
    fprintf(file, "%c", (char)(image->width >> 8) & 0xFF);
    fprintf(file, "%c", (char)(image->height & 0xFF));
    fprintf(file, "%c", (char)(image->height >> 8) & 0xFF);
    fprintf(file, "%c", (char)(0 << 7 | interlace_flag << 6 | sort_flag << 5 | res << 4 | n));
    fprintf(file, "%c", (char)(image->minCodeSize & 0xFF));
}    
