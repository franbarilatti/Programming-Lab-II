#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "thirdpw.h"

void practiceThreeMenu()
{
    int opt, exit = 0;
    while(exit == 0)
    {
        system("cls");
        printf("\n============== Practice III ==============");
        printf("\n[1]-Exercise 1\n[2]-Exercise 2\n[3]-Exercise 3\n[4]-Exercise 4\n[5]-Exercise 5\n[6]-Exercise 6\n[7]-Exercise 7\n[8]-Exercise 8\n[9]-Exercise 9\n[10]-Exercise 10\n[0]- Exit\n\n Select one option and press Enter: ");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            system("cls");
            int num, result, pow, total;
            int arr4[5] = {2,2,2,2,2};
            printf("\nIngress one number: ");
            scanf("%d",&num);
            result = recursiveFactorial(num);
            printf("The factorial of %d is: %d\n\n",num,result);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("\nIngress one number: ");
            scanf("%d",&num);
            printf("\nIngress the power: ");
            scanf("%d",&pow);
            result = recursivePow(num,pow);
            printf("\n\n%d to the power %d is: %d\n\n",num,pow,result);
            system("pause");
            break;
        case 3:
            system("cls");
            int arr[5] = {3,4,2,4,3};
            showArrayRecursive(arr,4,0);
            printf("\n\n");
            system("pause");
            break;
        case 4:
            system("cls");
            int arr2[5] = {3,4,2,6,3};
            reverseShowArrayRecursive(arr2,4);
            printf("\n\n");
            system("pause");
            break;
        case 5:
            system("cls");
            int arr3[5] = {3,4,2,3,3};
            int flag = isPalindromeRecursive(arr3,4,0);
            if(flag == 1){
                printf("\nIs palindrome\n\n");
            }else{
                printf("\nIsn't palindrome\n\n");
            }
            system("pause");
            break;
        case 6:
            total = recursiveArrayPlus(arr4,4);
            system("cls");

            system("pause");
            break;
        case 7:
            system("cls");

            system("pause");
            break;
        case 8:
            system("cls");

            printf("\n\n");
            system("pause");
            break;
        case 9:
            break;
        case 10:
            break;
        case 0:
            exit++;
            break;
        default:
            printf("\nIncorrect Option");

        }
    }
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise One ///////////////////////

int recursiveFactorial(int num){
    if(num == 0){
        num = 1;
    }
    else{
        num*=recursiveFactorial(num-1);
    }
    return num;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise Two ///////////////////////

int recursivePow(int num,int pow){
    if(pow == 0){
        num = 1;
    }
    else{
        num *= recursivePow(num,pow-1);
    }
    return num;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise Three ///////////////////////

void showArrayRecursive(int arr[],int valids,int index){
    if(valids == -1){
        printf("\nEnd of array");
    }else{
        printf("[%d]-",arr[index]);
        showArrayRecursive(arr,valids-1,index+1);
    }
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise Four ///////////////////////

void reverseShowArrayRecursive(int arr[],int valids){
    if(valids == -1){
        printf("\nEnd of array");
    }else{
        printf("[%d]-",arr[valids]);
        reverseShowArrayRecursive(arr,valids-1);
    }
}


///////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise Five ///////////////////////

int isPalindromeRecursive(int arr[],int valids,int index){
    int flag = 0;
    if(valids == -1){
        flag = 0;
    }else{
        if(arr[index] == arr[valids]){
            flag = 1;
            isPalindromeRecursive(arr,valids-1,index+1);
        }else{
            valids = 0;
        }
    }
    return flag;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise Six ///////////////////////


int recursiveArrayPlus(int array[],int valids){
    int total = 0;
    if(valids == -1){
        printf("\nThe total plus of array is: %d",total);
    }else{
        total += recursiveArrayPlus(array,valids-1);
    }
    return total;
}


