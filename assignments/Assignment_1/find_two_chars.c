int find_two_chars (char * sub, char first, char second) {
    int reverseorder = 0;
    if (*sub == '\0')
        return 2;
    while (*(sub+1) != '\0') {
        if (*sub == first && *(sub+1) == second)
            return 0;
        else if (*sub == second && *(sub+1) == first)
            reverseorder = 1;
        sub++;
    }
    return (reverseorder == 1) ? 1 : 2;
}