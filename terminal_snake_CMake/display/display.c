/*****************************************************************************
 * \brief display.c         Code for handling the temrinal output
 * Type file: source code
 * 
 * \author Vasile Baltei
 ****************************************************************************/

/****************************************************************************/
/*                    Includes                                              */
/****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "display.h"

/****************************************************************************/
/*                    Local macros and defines                              */
/****************************************************************************/

/****************************************************************************/
/*                    Local data types                                      */
/****************************************************************************/

/****************************************************************************/
/*                    Local header functions                                */
/****************************************************************************/

/****************************************************************************/
/*                    Local static variables                                */
/****************************************************************************/

/****************************************************************************/
/*                    Global variables                                      */
/****************************************************************************/
char display_menuTemplate[DISPLAY_MENU_TEMPLATE_NO_ROWS][DISPLAY_MENU_TEMPLATE_NO_COLUMNS];
char display_creditsTemplate[DISPLAY_CREDITS_TEMPLATE_NO_ROWS][DISPLAY_CREDITS_TEMPLATE_NO_COLUMNS];

/****************************************************************************/
/*                    Local functions                                       */
/****************************************************************************/

/****************************************************************************/
/*                    Global functions                                      */
/****************************************************************************/

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
            printf("%c", display_menuTemplate[indexRow][indexColumn]);
}

/*****************************************************************************
 * \brief display_credits          Function which display the credits
 *
 * \param [in]          none
 * \param [in,out]      none
 * \param [out]         none

 * \return              none
 ****************************************************************************/
void display_credits(void)
{
    display_clear();
    for(uint8_t indexRow = 0; indexRow<DISPLAY_CREDITS_TEMPLATE_NO_ROWS; indexRow++)
        for (uint8_t indexColumn = 0; indexColumn< DISPLAY_CREDITS_TEMPLATE_NO_COLUMNS; indexColumn++)
            printf("%c", display_creditsTemplate[indexRow][indexColumn]);
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
        printf("Error! Input files can't be found!");
        return false;
    }
    
    while( (display_menuTemplate[noRows][noColumns] = fgetc(fTemplate)) != EOF )
    {
        if(display_menuTemplate[noRows][noColumns] == '\n')
        {
            noRows++;
            noColumns=0u;
        }
        else
            noColumns++;
    }

    fclose(fTemplate);

    noRows = noColumns = 0u;

    FILE *fCreditsTemplate;
    fCreditsTemplate = fopen("templates/credits_template", "r");

    /* TODO: Create a function for duplicate code */
    if(fCreditsTemplate == NULL)
    {
        printf("Error! Input files can't be found!");
        return false;
    }
    
    while( (display_creditsTemplate[noRows][noColumns] = fgetc(fCreditsTemplate)) != EOF )
    {
        if(display_creditsTemplate[noRows][noColumns] == '\n')
        {
            noRows++;
            noColumns=0u;
        }
        else
            noColumns++;
    }

    fclose(fCreditsTemplate);

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
