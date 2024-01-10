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
/* NO Rows and columns for menu template */
#define DISPLAY_MENU_TEMPLATE_NO_ROWS                                      16u
#define DISPLAY_MENU_TEMPLATE_NO_COLUMNS                                   45u

/* NO Rows and columns for credits template */
#define DISPLAY_CREDITS_TEMPLATE_NO_ROWS                                    8u
#define DISPLAY_CREDITS_TEMPLATE_NO_COLUMNS                                45u

/****************************************************************************/
/*                    Global data types                                     */
/****************************************************************************/
/* TODO: share following data type through another "private" header  */
extern char display_menuTemplate[DISPLAY_MENU_TEMPLATE_NO_ROWS][DISPLAY_MENU_TEMPLATE_NO_COLUMNS];
extern char display_creditsTemplate[DISPLAY_CREDITS_TEMPLATE_NO_ROWS][DISPLAY_CREDITS_TEMPLATE_NO_COLUMNS];

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
