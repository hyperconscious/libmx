#include "../inc/libmx.h"

char *mx_file_to_str(const char *file){
    if(file == NULL)
        return NULL;
    int len = 0;
    char c;
    int i = 0;
    int count = 0;

    int r_file = open(file, O_RDONLY);
    if (r_file < 0) return NULL;
    while(read(r_file, &c, 1)) count++;
    close(r_file);
    char *str = mx_strnew(len);
    r_file = open(file, O_RDONLY);
    if(r_file < 0) return NULL;
    while(read(r_file, &c, 1)){
        str[i++] = c;
    }
    close(r_file);
    return str;
}

