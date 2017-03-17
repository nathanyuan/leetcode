#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

/* requirements
 * strip all white spaces
 * negative and positive integer, - or +
 * disgard or non digital char after the legal int
 * empty string
 * overflow, INT_MAX, INT_MIN
 *
 */

int myAtoi(char *str)
{
    int len = strlen(str);
    if (len < 1)
        return 0;
    int stripped = 0;
    int negative = 0;
    int start = 0;
    long result = 0;
    int i;
    for (i = 0; i < len; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            if (!stripped)
                continue;
        stripped = 1;
        if (!start) {
            start = 1;
            if (str[i] == '-') {
                negative = 1;
                continue;
            }
            else if (str[i] == '+') {
                continue;
            }
            else if (isdigit(str[i])){
                result = (int)(str[i]) - 48;
                continue;
            }
            else {
                return 0;
            }
        }
        if (!isdigit(str[i])) {
            if (negative)
                result = 0 - result;
            return result;
        }
        result = result * 10 + ((int)(str[i]) - 48);
        if (result > INT_MAX) {
            if (negative)
                return INT_MIN;
            return INT_MAX;
        }
    }
    if (negative)
        return (int)(0 - result);
    return (int)(result);
}

int main(int argc, char* argv[])
{
    if (argc != 2)
        return -1;
    int a = string_to_integer("    \t-99999999999999999999999999999999999999");
    printf("%d\n", a); 
    return 0;
}
