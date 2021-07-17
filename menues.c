#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "primertp.h"
#include "menues.h"
#include "secondpw.h"
#include "thirdpw.h"
#include "fourthpw.h"


void generalPracticeMenu()
{
    int opt;
    int exit = 0;
    while(exit == 0)
    {
        system("cls");
        printf("\n============== Lab of Programming Practice Menu ==============");
        printf("\n[1]-Practice I\n[2]-Practice II\n[3]-Practice III\n[4]-Practice IV\n[5]-Practice V\n[6]-Practice VI\n[7]-Practice VII\n[8]-Practice VIII\n[9]-Practice IX\n[10]-Practice X\n[0]- Exit\n\n Select one option and press Enter: ");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            practiceOneMenu();
            break;
        case 2:
            practiceTwoMenu();
            break;
        case 3:
            practiceThreeMenu();
            break;
        case 4:
            practiceFourMenu();
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 0:
            exit++;
            break;
        default:
            printf("Incorrect Option");

        }
    }
}
