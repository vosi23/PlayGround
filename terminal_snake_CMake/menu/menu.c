/*****************************************************************************
 * \brief menu.c         Code for handling the menu content
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

#ifdef WINDOWS_ENV
#include <conio.h>
#endif /* ifdef WINDOWS_ENV */

#ifdef LINUX_ENV
#include <termios.h>
#include <unistd.h>
#endif /* ifdef LINUX_ENV */

#include "../display/display.h"

/*--------------------------------------------------------------------------*/
/*--- local macros and defines                                           ---*/
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*--- local data types                                                   ---*/
/*--------------------------------------------------------------------------*/
typedef enum menu_displayOptions_t
{
    eStart    = 0u,
    eOptions  = 1u,
    eCredits  = 2u,
    eExit     = 3u,
}menu_displayOptions_t;

typedef struct menu_displayArrow_t
{
    uint8_t row_pos;
    uint8_t column_pos;
}menu_displayArrow_t;

/*--------------------------------------------------------------------------*/
/*--- local header functions                                             ---*/
/*--------------------------------------------------------------------------*/
static void menu_updateDisplayTemplate(menu_displayOptions_t option);
static inline void menu_revertTemplateWithDefault(void);

/*--------------------------------------------------------------------------*/
/*--- local static variables                                             ---*/
/*--------------------------------------------------------------------------*/
/* Copy of default display template */
static char menu_defaultDisplayTemplate[DISPLAY_MENU_TEMPLATE_NO_ROWS][DISPLAY_MENU_TEMPLATE_NO_COLUMNS];
/* Variable which contains the row and column position for each option in game from template */
static const menu_displayArrow_t menu_displayArrows[4u] = 
{
    {
        10u, 27u,
    },
    {
        11u, 24u,
    },
    {
        12u, 24u,
    },
    {
        13u, 21u,
    },
};

/*--------------------------------------------------------------------------*/
/*--- global variables                                                   ---*/
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*--- local functions                                                    ---*/
/*--------------------------------------------------------------------------*/

/*****************************************************************************
 * \brief menu_updateDisplayTemplate         Update the current selected "option" with '<' symbol
 *
 * \param [in]          none
 * \param [in,out]      none
 * \param [out]         none

 * \return              none
 ****************************************************************************/
static void menu_updateDisplayTemplate(menu_displayOptions_t option)
{
    menu_revertTemplateWithDefault();

    display_template[menu_displayArrows[option].row_pos][menu_displayArrows[option].column_pos] = '<';
}

/*****************************************************************************
 * \brief menu_revertTemplateWithDefault        Helper function which reverts to the original template
 *
 * \param [in]          none
 * \param [in,out]      none
 * \param [out]         none

 * \return              none
 ****************************************************************************/
static inline void menu_revertTemplateWithDefault(void)
{
    /* Revert to the display template firstly in order to avoid multiple sybmols of '<' */
    for(uint8_t indexRow = 0; indexRow<DISPLAY_MENU_TEMPLATE_NO_ROWS; indexRow++)
        for (uint8_t indexColumn = 0; indexColumn< DISPLAY_MENU_TEMPLATE_NO_COLUMNS; indexColumn++)
            display_template[indexRow][indexColumn] = menu_defaultDisplayTemplate[indexRow][indexColumn];
}

/*--------------------------------------------------------------------------*/
/*--- global functions                                                   ---*/
/*--------------------------------------------------------------------------*/

/*****************************************************************************
 * \brief menu_init        Init function of menu
 *
 * \param [in]          none
 * \param [in,out]      none
 * \param [out]         none

 * \return              bool
                        True -> Init function done successfully
                        False -> Init function returned with error
 ****************************************************************************/
bool menu_init(void)
{
    /* Copy default template in another char table */
    for(uint8_t indexRow = 0; indexRow<DISPLAY_MENU_TEMPLATE_NO_ROWS; indexRow++)
        for (uint8_t indexColumn = 0; indexColumn< DISPLAY_MENU_TEMPLATE_NO_COLUMNS; indexColumn++)
            menu_defaultDisplayTemplate[indexRow][indexColumn] = display_template[indexRow][indexColumn];
    
    return true;
}

/*****************************************************************************
 * \brief menu_init        Functionality of menu
 *
 * \param [in]          none
 * \param [in,out]      none
 * \param [out]         none

 * \return              none
 ****************************************************************************/
void menu_mode(void)
{
    char inputKey;
    menu_displayOptions_t currentOption = eStart;

    menu_updateDisplayTemplate(currentOption);
    display_menu();

#ifdef LINUX_ENV
    /* Linux terminal attributes */
    struct termios orig_termios;
    struct termios new_termios;
    /* Get current terminal attributes */
    tcgetattr(STDIN_FILENO, &orig_termios);
    /* Make a copy of the original attributes */
    new_termios = orig_termios;
    /* Disable canonical mode and echo */
    new_termios.c_lflag &= ~(ICANON | ECHO);
    /* Apply the new terminal attributes */
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
#endif /* ifdef LINUX_ENV */

    do
    {
#if defined WINDOWS_ENV
        if (_kbhit())
        {
            /* Check if a key has been pressed */
            inputKey = _getch();
#elif defined LINUX_ENV
            inputKey = getchar();
#endif /* defined WINDOWS_ENV */

            switch(inputKey)
            {
                case 'w':
                    if (currentOption == eStart)
                        continue;
                    currentOption--;
                    menu_updateDisplayTemplate(currentOption);
                    break;
                case 'a':
                    break;
                case 's':
                    if (currentOption == eExit)
                        continue;
                    currentOption++;
                    menu_updateDisplayTemplate(currentOption);
                    break;
                case 'd':
                    break;
                case 'q':
                    goto EXIT;
                    break;
#if defined WINDOWS_ENV
                case 13: /* Enter */
#elif defined LINUX_ENV
                case 'f':
#endif /* defined WINDOWS_ENV */
                    switch(currentOption)
                    {
                        case eExit:
                            goto EXIT;
                            break;
                        default:
                            /* TODO: replace the code example */
                            display_clear();
                            printf("\t\tWorks!!\n\n");
                            getchar();
                            break;
                    }
                    break;
                default:
                    continue;
            }
            display_menu();
#ifdef WINDOWS_ENV
        }
#endif /* ifdef WINDOWS_ENV */

    }while(true);

EXIT:
    display_clear();
#ifdef LINUX_ENV
    /* Restore original terminal attributes */
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
#endif /* ifdef LINUX_ENV */

}
