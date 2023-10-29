/*****************************************************************************
 * \brief display.c         Code for handling the temrinal output
 * Type file: source code
 * 
 * \author Vasile Baltei
 ****************************************************************************/

/*--------------------------------------------------------------------------*/
/*--- includes                                                           ---*/
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "display.h"

/*--------------------------------------------------------------------------*/
/*--- local macros and defines                                           ---*/
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*--- local data types                                                   ---*/
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*--- local header functions                                             ---*/
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*--- local static variables                                             ---*/
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*--- global variables                                                   ---*/
/*--------------------------------------------------------------------------*/
char display_template[DISPLAY_MENU_TEMPLATE_NO_ROWS][DISPLAY_MENU_TEMPLATE_NO_COLUMNS];

/*--------------------------------------------------------------------------*/
/*--- local functions                                                    ---*/
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*--- global functions                                                   ---*/
/*--------------------------------------------------------------------------*/

/*****************************************************************************
 * \brief display_menu          Function which display the main menu of game
 *
 * \param [in]          none
 * \param [in,out]      none
 * \param [out]         none

 * \return              none
 ****************************************************************************/
void display_menu(void)
{
    display_clear();
    for(uint8_t indexRow = 0; indexRow<DISPLAY_MENU_TEMPLATE_NO_ROWS; indexRow++)
        for (uint8_t indexColumn = 0; indexColumn< DISPLAY_MENU_TEMPLATE_NO_COLUMNS; indexColumn++)
            printf("%c", display_template[indexRow][indexColumn]);
}

/*****************************************************************************
 * \brief display_init          Reads the template file and load the menu buffer
 *
 * \param [in]          none
 * \param [in,out]      none
 * \param [out]         none

 * \return              bool
                        true -> The file was readed successfully and the buffer was loaded
                        false -> Errors encountered handling the input file
 ****************************************************************************/
bool display_init(void)
{
    uint8_t noRows = 0u;
    uint8_t noColumns = 0u;

    FILE *fTemplate;
    fTemplate = fopen("templates/menu_template", "r");

    if(fTemplate == NULL)
    {
        printf("Error! Input file doesn't exist!");
        return false;
    }
    
    while( (display_template[noRows][noColumns] = fgetc(fTemplate)) != EOF )
    {
        if(display_template[noRows][noColumns] == '\n')
        {
            noRows++;
            noColumns=0u;
        }
        else
            noColumns++;
    }

    fclose(fTemplate);
    printf("\n\n");

    return true;
}

/*****************************************************************************
 * \brief display_clear          Clear the output of terminal
 *
 * \param [in]          none
 * \param [in,out]      none
 * \param [out]         none

 * \return              none
 ****************************************************************************/
void display_clear(void)
{
#if defined LINUX_ENV
    system("clear");
#elif defined WINDOWS_ENV
    system("cls");
#endif /* defined LINUX_ENV */
}
