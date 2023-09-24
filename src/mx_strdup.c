#include "../inc/libmx.h"

char *mx_strdup(const char *str){
    char *newstr = mx_strnew(mx_strlen(str));
    newstr = mx_strcpy(newstr, str);
    return newstr;
}

