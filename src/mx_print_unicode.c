#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c){
    char utf8Buffer[5];
    int bytesWritten = 0;

    if (c <= 0x7F) {
        utf8Buffer[0] = (char)c;
        bytesWritten = 1;
    } else if (c <= 0x7FF) {
        utf8Buffer[0] = (char)(0xC0 | ((c >> 6) & 0x1F));
        utf8Buffer[1] = (char)(0x80 | (c & 0x3F));
        bytesWritten = 2;
    } else if (c <= 0xFFFF) {
        utf8Buffer[0] = (char)(0xE0 | ((c >> 12) & 0x0F));
        utf8Buffer[1] = (char)(0x80 | ((c >> 6) & 0x3F));
        utf8Buffer[2] = (char)(0x80 | (c & 0x3F));
        bytesWritten = 3;
    } else if (c <= 0x10FFFF) {
        utf8Buffer[0] = (char)(0xF0 | ((c >> 18) & 0x07));
        utf8Buffer[1] = (char)(0x80 | ((c >> 12) & 0x3F));
        utf8Buffer[2] = (char)(0x80 | ((c >> 6) & 0x3F));
        utf8Buffer[3] = (char)(0x80 | (c & 0x3F));
        bytesWritten = 4;
    }

    write(STDOUT_FILENO, utf8Buffer, bytesWritten);
    return;
}

