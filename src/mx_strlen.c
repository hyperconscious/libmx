int mx_strlen(const char* s){
    int count = 0;
    char at = s[0];

    while(at != '\0'){
        at = s[++count];
    }

    return count;
}
