#include <stdio.h>
#include <unistd.h>

int main()
{
    char c;
    char d;
    char e;
    c = 0xe8;
    d = 0xaa;
    e = 0x9e;

    write(1, &c, 1);
    write(1, &d, 1);
    write(1, &e, 1);

    return 0;
}