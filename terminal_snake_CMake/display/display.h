/*****************************************************************************
 * \brief display.h         Header file for handling the temrinal output
 * Type file: header file
 * 
 * \author Vasile Baltei
 ****************************************************************************/

#ifndef DISPLAY_H
#define DISPLAY_H

/****************************************************************************/
/*                    Includes                                              */
/****************************************************************************/
#include <stdbool.h>

/****************************************************************************/
/*                    Global macros and defines                             */
/****************************************************************************/
/* TODO: share following defines through another "private" header */
#define DISPLAY_MENU_TEMPLATE_NO_ROWS                                      16u
#define DISPLAY_MENU_TEMPLATE_NO_COLUMNS                                   45u

/****************************************************************************/
/*                    Global data types                                     */
/****************************************************************************/
/* TODO: share following data type through another "private" header  */
extern char display_template[DISPLAY_MENU_TEMPLATE_NO_ROWS][DISPLAY_MENU_TEMPLATE_NO_COLUMNS];

/****************************************************************************/
/*                    Global variables                                      */
/****************************************************************************/

/****************************************************************************/
/*                    Global function headers                               */
/****************************************************************************/
extern bool display_init(void);
extern void display_menu(void);
extern void display_clear(void);

#endif /* DISPLAY_H */
