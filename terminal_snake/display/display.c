#include <stdio.h>
#include <stdint.h>
#include "display.h"


#define DISPLAY_MENU_TEMPLATE_NO_ROWS           15u
#define DISPLAY_MENU_TEMPLATE_NO_COLUMNS        45u


char template[DISPLAY_MENU_TEMPLATE_NO_ROWS][DISPLAY_MENU_TEMPLATE_NO_COLUMNS];

void display_menu(void)
{
    printf("####################");
}

bool display_init(void)
{
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
