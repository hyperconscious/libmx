#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle){
    if (!haystack || !needle)
        return NULL;

    int haystack_len = mx_strlen(haystack);
    int needle_len = mx_strlen(needle);

    for (int i = 0; i <= haystack_len - needle_len; ++i) {
        int j;
        for (j = 0; j < needle_len; ++j) {
            if (haystack[i + j] != needle[j])
                break;
        }
        if (j == needle_len) {
            return (char *)(haystack + i);
   /*         char *result = mx_strnew(haystack_len - needle_len);
            if (!result)
                return NULL;
            mx_strncpy(result, haystack + i, haystack_len - needle_len);
            return result;*/
        }
    }

    return NULL;
}

