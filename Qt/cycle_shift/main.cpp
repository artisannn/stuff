#include <iostream>
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

using namespace std;

// Привет, KR!
void stringcopy(const char * in, char * out)
{
    while(*out++ = *in++) ;
}

void str_reverse(char * start, char * end)
{
    printf("reverse between %c and %c: %s\n",*start,*end, start);
    while (start < end)
    {
        char t = *start;
        *start = *end;
        *end = t;
        start++;
        end--;
    }
}

void c_shift(char * str, int n)
{
    char * end = str+strlen(str)-1;
    str_reverse(str, str + n-1);
    str_reverse(str+n, end);
    str_reverse(str, end);
}

int main()
{

    char * str = strdup("Hello!");
    printf("%s\n", str);

    c_shift(str , 2);
    printf("%s\n", str);

    return 0;
}
