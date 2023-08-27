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
#include "display.h"

/*--------------------------------------------------------------------------*/
/*--- local macros and defines                                           ---*/
/*--------------------------------------------------------------------------*/
#define DISPLAY_MENU_TEMPLATE_NO_ROWS           15u
#define DISPLAY_MENU_TEMPLATE_NO_COLUMNS        45u

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
    printf("####################");
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
    char template[DISPLAY_MENU_TEMPLATE_NO_ROWS][DISPLAY_MENU_TEMPLATE_NO_COLUMNS];

    uint8_t noRows = 0u;
    uint8_t noColumns = 0u;

    FILE *fTemplate;
    fTemplate = fopen("templates/menu_template", "r");

    if(fTemplate == NULL)
        goto EXIT;
    
    while( (template[noRows][noColumns] = fgetc(fTemplate)) != EOF )
    {
        printf("%c", template[noRows][noColumns]);
    
        if(template[noRows][noColumns] == '\n')
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

EXIT:
    printf("Error handling display_init function!\n");
    return false; 
}
