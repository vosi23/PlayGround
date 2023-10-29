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
#define DISPLAY_MENU_TEMPLATE_NO_ROWS                                      16u
#define DISPLAY_MENU_TEMPLATE_NO_COLUMNS                                   45u

/*--------------------------------------------------------------------------*/
/*--- local data types                                                   ---*/
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*--- local header functions                                             ---*/
/*--------------------------------------------------------------------------*/
static void display_menu(void);

/*--------------------------------------------------------------------------*/
/*--- local static variables                                             ---*/
/*--------------------------------------------------------------------------*/
static char display_template[DISPLAY_MENU_TEMPLATE_NO_ROWS][DISPLAY_MENU_TEMPLATE_NO_COLUMNS];

/*--------------------------------------------------------------------------*/
/*--- global variables                                                   ---*/
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*--- local functions                                                    ---*/
/*--------------------------------------------------------------------------*/

/*****************************************************************************
 * \brief display_menu          Function which display the main menu of game
 *
 * \param [in]          none
 * \param [in,out]      none
 * \param [out]         none

 * \return              none
 ****************************************************************************/
static void display_menu(void)
{
    for(uint8_t indexRow = 0; indexRow<DISPLAY_MENU_TEMPLATE_NO_ROWS; indexRow++)
        for (uint8_t indexColumn = 0; indexColumn< DISPLAY_MENU_TEMPLATE_NO_COLUMNS; indexColumn++)
            printf("%c", display_template[indexRow][indexColumn]);
}

/*--------------------------------------------------------------------------*/
/*--- global functions                                                   ---*/
/*--------------------------------------------------------------------------*/

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
        exit(0);
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
    display_menu();     /* TODO: move function call location */
    return true;
}
