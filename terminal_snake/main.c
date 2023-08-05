#include <stdint.h>
#include "main.h"
#include "display/display.h"

/* TODO: REMOVE IT */
#include "stdio.h"
/* TODO: REMOVE IT */

/* TODO: Create makefile build env */

void main_initGame(void);

uint8_t main(void)
{
    main_initGame();

    return 0u;
}

void main_initGame(void)
{
    printf("%d\n\n", display_init());
}
