/*****************************************************************************
 * \brief main.c         Main file
 * Type file: source code
 * 
 * \author Vasile Baltei
 ****************************************************************************/

/****************************************************************************/
/*                    Includes                                              */
/****************************************************************************/
#include <stdint.h>
#include "main.h"
#include "display/display.h"
#include "menu/menu.h"

/****************************************************************************/
/*                    Local macros and defines                              */
/****************************************************************************/

/****************************************************************************/
/*                    Local data types                                      */
/****************************************************************************/

/****************************************************************************/
/*                    local header functions                                */
/****************************************************************************/
int main(void);              /* W: 'main' is normally a non-static function */
static bool main_initGame(void);

/****************************************************************************/
/*                    Local static variables                                */
/****************************************************************************/

/****************************************************************************/
/*                    Global variables                                      */
/****************************************************************************/

/****************************************************************************/
/*                    Local functions                                       */
/****************************************************************************/

/*****************************************************************************
 * \brief main          Startup function
 *
 * \param [in]          none
 * \param [in,out]      none
 * \param [out]         none

 * \return              int         Returns the exit code of the program
 ****************************************************************************/
int main(void)
{
    bool init_status = false;

    init_status = main_initGame();
    if(init_status == false)
        /* main_initGame returned false which results to errors during init phase */
        return 1;   /* Program didn't executed properly */

    menu_mode();

    return 0;
}

/*****************************************************************************
 * \brief main_initGame      Funciton which call all init functions, it's called until the application starts
 *
 * \param [in]               none
 * \param [in,out]           none
 * \param [out]              none

 * \return                   bool
                             true -> All init functions returned successfully
                             false -> Errors encountered in one or more init functions
 ****************************************************************************/
static bool main_initGame(void)
{
    bool result = false;

    result = display_init() && menu_init();

    return result;
}

/****************************************************************************/
/*                    Global functions                                      */
/****************************************************************************/
