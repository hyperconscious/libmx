#include "../inc/libmx.h"

char *mx_realloc(char *ptr, size_t size){
    if(size == 0){
        if(ptr)
            free(ptr);
        return NULL;
    }

    void *new_ptr = malloc(size);

    if(!new_ptr){
        return NULL;
    }

    if(ptr){
        size_t old_size = mx_strlen(ptr);
        size_t copy_size = old_size < size ? old_size : size;
        mx_memcpy(new_ptr, ptr, copy_size);
        free(ptr);
    }
    return new_ptr;
}

