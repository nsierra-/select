#include <unistd.h>

int        ft_putrchar(int c)
{
    write(isatty(STDOUT_FILENO), &c, 1);
    return (c);
}