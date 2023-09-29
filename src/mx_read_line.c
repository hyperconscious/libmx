#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd){
    if (fd < 0 || !lineptr) {
        return -2; 
    }

    ssize_t read_bytes = 0;
    size_t line_len = 0;
    char *line = mx_strnew(buf_size);
    char c;

    while (1) {
        if (read(fd, &c, 1) != 1) {
            if (read_bytes == 0) {
                return -1; 
            }
            break;
        }

        if (c == delim) {
            break;
        }

        if (line_len + 1 >= buf_size) {
            buf_size *= 2;
            char *temp = mx_realloc(line, buf_size);
            if (!temp) {
                free(line);
                return -2; 
            }
            line = temp;
        }

        line[line_len++] = c;
        read_bytes++;
    }

    if (line_len == 0) {
        if (!line) {
            line = mx_strnew(1); 
            if (!line) {
                return -2; 
            }
        }
        line[0] = '\0';
    } else {
        line[line_len] = '\0';
    }

    *lineptr = line;
    return read_bytes;
}

