#include <stdio.h>
#include <conio.h>

int main(void)
{
    char ch = 'a';

    do
    {
        ch = getch();

        printf("%c", ch);
    }while(ch != 27);

    return 0;
}
