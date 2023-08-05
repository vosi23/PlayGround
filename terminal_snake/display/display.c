#include <stdio.h>
#include "display.h"

void display_menu(void)
{
    printf("####################");
}

bool display_init(void)
{
    /* TODO: CREATE DEFINES EITHER USE MALLOC */
    char template[15][45];
    uint8_t i, j;
    i = j = 0u;

    FILE *fTemplate;
    fTemplate = fopen("templates/menu_template", "r");

    if(fTemplate == NULL)
        goto EXIT;
    
    while( (template[i][j] = fgetc(fTemplate)) != EOF )
    {
        printf("%c", template[i][j]);
    
        if(template[i][j] == '\n')
        {
            i++;
            j=0;
        }
        else
            j++;  
    }
    
    fclose(fTemplate);
    printf("\n\n");
    return true;

EXIT:
    printf("Error handling display_init function!\n");
    return false; 
}
