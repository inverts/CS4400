#define RESET   "\033[0m"
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */

void print_good(char * string) {
    printf("%s %s %s", BOLDGREEN, string, RESET);
}
