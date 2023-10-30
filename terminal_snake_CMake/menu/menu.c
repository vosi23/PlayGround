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
#include <conio.h>
#include "../display/display.h"

/*--------------------------------------------------------------------------*/
/*--- local macros and defines                                           ---*/
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*--- local data types                                                   ---*/
/*--------------------------------------------------------------------------*/
typedef enum display_menu_options_t
{
    eStart    = 0u,
    eOptions  = 1u,
    eCredits  = 2u,
    eExit     = 3u,
}display_menu_options_t;

typedef struct display_menu_arrows_t
{
    uint8_t row_pos;
    uint8_t column_pos;
}display_menu_arrows_t;

/*--------------------------------------------------------------------------*/
/*--- local header functions                                             ---*/
/*--------------------------------------------------------------------------*/
static void Menu_UpdateDisplayTemplate(display_menu_options_t option);
static void Menu_RevertTemplateWithDefault(void);

/*--------------------------------------------------------------------------*/
/*--- local static variables                                             ---*/
/*--------------------------------------------------------------------------*/
static const display_menu_arrows_t display_menu_arrows[4u] = 
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

static char default_display_template[DISPLAY_MENU_TEMPLATE_NO_ROWS][DISPLAY_MENU_TEMPLATE_NO_COLUMNS];

/*--------------------------------------------------------------------------*/
/*--- global variables                                                   ---*/
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*--- local functions                                                    ---*/
/*--------------------------------------------------------------------------*/

/*****************************************************************************
 * \brief Menu_UpdateDisplayTemplate        Reverts to the original template * update the current selected "option" with '<' symbol
 *
 * \param [in]          none
 * \param [in,out]      none
 * \param [out]         none

 * \return              none
 ****************************************************************************/
static void Menu_UpdateDisplayTemplate(display_menu_options_t option)
{
    Menu_RevertTemplateWithDefault();

    display_template[display_menu_arrows[option].row_pos][display_menu_arrows[option].column_pos] = '<';
}

/*****************************************************************************
 * \brief Menu_RevertTemplateWithDefault        Reverts to the original template * update the current selected "option" with '<' symbol
 *
 * \param [in]          none
 * \param [in,out]      none
 * \param [out]         none

 * \return              none
 ****************************************************************************/
static void Menu_RevertTemplateWithDefault(void)
{
    /* Revert to the display template firstly in order to avoid multiple sybmols of '<' */
    for(uint8_t indexRow = 0; indexRow<DISPLAY_MENU_TEMPLATE_NO_ROWS; indexRow++)
        for (uint8_t indexColumn = 0; indexColumn< DISPLAY_MENU_TEMPLATE_NO_COLUMNS; indexColumn++)
            display_template[indexRow][indexColumn] = default_display_template[indexRow][indexColumn];
}

/*--------------------------------------------------------------------------*/
/*--- global functions                                                   ---*/
/*--------------------------------------------------------------------------*/
/* TODO: add brief */
bool menu_init(void)
{
    /* Copy default template in another char table */
    for(uint8_t indexRow = 0; indexRow<DISPLAY_MENU_TEMPLATE_NO_ROWS; indexRow++)
        for (uint8_t indexColumn = 0; indexColumn< DISPLAY_MENU_TEMPLATE_NO_COLUMNS; indexColumn++)
            default_display_template[indexRow][indexColumn] = display_template[indexRow][indexColumn];
    
    return true;
}

/* TODO: add brief */
void menu_mode(void)
{
    char input;
    display_menu_options_t currentOption = eStart;

    Menu_UpdateDisplayTemplate(currentOption);
    display_menu();

#ifdef LINUX_ENV
    struct termios orig_termios;
    struct termios new_termios;
    tcgetattr(STDIN_FILENO, &orig_termios); // Get current terminal attributes
    // Make a copy of the original attributes
    new_termios = orig_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios); // Apply the new terminal attributes
#endif /* ifdef LINUX_ENV */

    do
    {
#if defined WINDOWS_ENV
        if (_kbhit())
        {
            // Check if a key has been pressed
            input = _getch(); // Read a single character
#elif defined LINUX_ENV
            input = getchar(); // Read a single character
#endif /* defined WINDOWS_ENV */

            switch(input)
            {
                case 'w':
                    if (currentOption == eStart)
                        continue;
                    currentOption--;
                    Menu_UpdateDisplayTemplate(currentOption);
                    break;
                case 'a':
                    break;
                case 's':
                    if (currentOption == eExit)
                        continue;
                    currentOption++;
                    Menu_UpdateDisplayTemplate(currentOption);
                    break;
                case 'd':
                    break;
                case 'q':
                    /* TODO: create function which exits from the game in order to duplicate code */
                    display_clear();
                    exit(1);
                    break;
                case 13: /* Enter */
                    switch(currentOption)
                    {
                        case eExit:
                            /* TODO: create function which exits from the game in order to duplicate code */
                            display_clear();
                            exit(1);
                        default:
                            display_clear();
                            printf("\t\tWorks!!\n\n");
                            getch();
                            break;
                    }
                    break;
                default:
                    /* TODO: find the better approach between these two options */
                    // display_clear();
                    // printf("\t\tInvalid option!\n\nPress any button to continue!");
                    // getch();
                    // display_menu();
                    // OR
                    continue;
                    break;
            }
            display_menu();
#ifdef WINDOWS_ENV
        }
#endif /* ifdef WINDOWS_ENV */

    }while(1);

#ifdef LINUX_ENV
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios); // Restore original terminal attributes
#endif /* ifdef LINUX_ENV */

}
