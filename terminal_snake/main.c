#include <stdint.h>
#include "main.h"
#include "display/display.h"

/* TODO: REMOVE IT */
#include "stdio.h"
/* TODO: REMOVE IT */

bool main_initGame(void);

uint8_t main(void)
{
    bool init_status = false;

    init_status = main_initGame();

    return 0u;
}

/* TODO: GDB!!!!!!! */

bool main_initGame(void)
{
    bool result = true;

    result &= display_init();

    return result;
}
