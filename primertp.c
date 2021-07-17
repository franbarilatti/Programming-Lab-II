#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "primertp.h"

void practiceOneMenu()
{
    int opt, exit = 0;
    while(exit == 0)
    {
        system("cls");
        printf("\n============== Practice I ==============");
        printf("\n[1]-Exercise 1\n[2]-Exercise 2\n[3]-Exercise 3\n[4]-Exercise 4\n[5]-Exercise 5\n[6]-Exercise 6\n[7]-Exercise 7\n[8]-Exercise 8\n[9]-Exercise 9\n[10]-Exercise 10\n[0]- Exit\n\n Select one option and press Enter: ");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            system("cls");
            int dimension;
            printf("\nIngress the dimension to the array: ");
            scanf("%d",&dimension);
            int *array = (int*) malloc(dimension * sizeof(int));
            initializeArray(array,dimension);
            float promedy = arrayPromedy(chargeIntArray(array,dimension),sumArray(array,dimension));
            printf("\n=========== ARRAY ===========\n");
            showIntArray(array,dimension);
            printf("\n\nThe array promedy is = %.2f",promedy);
            printf("\n\n");
            system("pause");
            break;
        case 2:
            system("cls");
            char arrayCh[10];
            int valids = chargeCharArray(arrayCh,10);
            showCharArray(arrayCh,valids);
            invertCharArray(arrayCh,valids);
            printf("\n=====================\n");
            showCharArray(arrayCh,valids);
            printf("\n\n");
            system("pause");
            break;
        case 3:
            system("cls");
            printf("\nIngress the dimension to the array: ");
            scanf("%d",&dimension);
            array = (int*) malloc(dimension * sizeof(int));
            valids = chargeIntArray(array, dimension);
            printf("\n=========== ARRAY ===========\n");
            showIntArray(array,valids);
            printf("\n\nThe array decimal form is = %d",decimalValueToArray(array,valids));
            printf("\n\n");
            system("pause");
            break;
        case 4:
            system("cls");
            printf("\nIngress the dimension to the array: ");
            scanf("%d",&dimension);
            array = (int*) malloc(dimension * sizeof(int));
            valids = chargeIntArray(array, dimension);
            printf("\n=========== ARRAY ===========\n");
            showIntArray(array,valids);
            printf("\n\nThe array decimal form is = %d",maxValueToArray(array,valids,0));
            printf("\n\n");
            system("pause");
            break;
        case 5:
            system("cls");
            int matrix[12][31];
            chargeMatrixRandom(12,31,matrix);
            printf("\n========= Matrix =========\n\n" );
            showMatrix(12,31,matrix);
            int month;
            printf("\nIngress the number of the serched Month: ");
            scanf("%d",&month);
            int precipitation = mostPrecipitationDay(month,matrix);
            printf("\nThe most precipitation day of the month %d is: %d\n\n",month,precipitation);
            chargeMonthsArray(matrix,array);
            printf("\n========= Months Array =========\n\n" );
            showIntArray(array,12);
            system("pause");
            break;
        case 6:
            system("cls");
            valids = chargeCharArray(arrayCh,10);
            showCharArray(arrayCh,valids);
            int flag = palindromeString(arrayCh,valids);
            if(flag == 1)
            {
                printf("\n\nThe String is palindrome\n\n");
            }
            else
            {
                printf("\n\nThe String isn't palindrome\n\n");
            }
            system("pause");
            break;
        case 7:
            system("cls");
            int a, b;
            printf("\nIngres the value to A: ");
            scanf("%d",&a);
            printf("\nIngres the value to B: ");
            scanf("%d",&b);
            printf("\n\nA = %d",a);
            printf("\nB = %d",b);
            changeValueByPointer(&a,&b);
            printf("\n\nNow whit values changed: \n\n");
            printf("A = %d",a);
            printf("\nB = %d\n\n",b);
            system("pause");
            break;
        case 8:
            system("cls");
            int arrA[10], arrB[10], arrDest[30],validsA, validsB;
            validsA = chargueIntArrayRandom(arrA,10);
            printf("\n\n====================== FIRST ARRAY ======================\n");
            showIntArray(arrA,validsA);
            validsB = chargueIntArrayRandom(arrB,10);
            printf("\n\n====================== SECOND ARRAY ======================\n");
            showIntArray(arrB,validsB);
            int validsDest = mixArrays(arrA,arrB,arrDest,validsA,validsB);
            printf("\n\n====================== DESTINY ARRAY ======================\n");
            showIntArray(arrDest,validsDest);
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

void initializeArray(int arr[],int volume)
{
    int index;
    for(index = 0; index<volume; index++)
    {
        arr[index] = -1;
    }
}

int chargeIntArray(int arr[],int volume)
{
    int number;
    int index = 0;
    char proced;
    while(proced != 27 && index<volume)
    {
        printf("\n\nSet one number in index %d: ",index);
        scanf("%d",&number);
        arr[index] = number;
        printf("\n\nPress any key for continue or ESC for exit: ");
        fflush(stdin);
        proced = getch();
        index++;
        if(index == volume-1)
        {
            printf("\n\nRemains one slot in the array");
        }
    }
    return index;
}

int chargueIntArrayRandom(int arr[],int volume){
    srand(time(NULL));
    int index, amount;
    printf("\n\nIngres the amount of elements to the array: ");
    scanf("%d",&amount);
    if(amount <= volume){
        for(index = 0; index < amount; index++){
            arr[index] = rand()%20;
        }
    }else{
        printf("\n\nThe amount of elements is bigger than arrayt volume");
    }

    return index;
}

int arraySize(int arr[],int valids)
{
    int index;
    while(index < valids)
    {
        index++;
    }
    return index;
}

int sumArray(int arr[],int valids)
{
    int total = 0;
    int index;
    for(index = 0; index<valids; index++)
    {
        total += arr[index];
    }
    return total;
}

float arrayPromedy(int valids, int sum)
{
    float promedy = (float)sum/valids;
    return promedy;
}

void showIntArray(int arr[],int valids)
{
    int index;
    for(index = 0; index<valids; index++)
    {
        printf(" [%d] ",arr[index]);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise Two ///////////////////////

int chargeCharArray(char arr[],int volume)
{
    char character;
    int index = 0;
    char proced;
    while(proced != 27 && index<volume)
    {
        printf("\n\nSet one char in index %d: ",index);
        fflush(stdin);
        scanf("%c",&character);
        arr[index] = character;
        printf("\n\nPress any key for continue or ESC for exit: ");
        fflush(stdin);
        proced = getch();
        index++;
        if(index == volume-1)
        {
            printf("\n\nRemains one slot in the array");
        }
    }
    return index;
}

void invertCharArray(char arr[],int valids)
{
    int index1, index2;
    char arrayAux[valids];
    for(index1 = valids-1, index2 = 0; index1 >= 0 && index2<valids; index1--, index2++)
    {
        arrayAux[index2] = arr[index1];
    }
    for(index1 = 0; index1<valids; index1++)
    {
        arr[index1] = arrayAux[index1];
    }
}


void showCharArray(char arr[],int valids)
{
    int index;
    for(index = 0; index<valids; index++)
    {
        printf(" [%c] ",arr[index]);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise Three ///////////////////////

int decimalValueToArray(int arr[],int valids)
{
    int unit = 1, index, total = 0, decimal = 0;
    for(index = valids-1; index >= 0; index--)
    {
        decimal = arr[index] * unit;
        total += decimal;
        unit *= 10;
    }
    return total;
}


/////////////////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise Four ///////////////////////


int maxValueToArray(int arr[],int valids,int pos)
{
    int index, max = arr[pos];
    for(index = pos+1; index< valids; index++)
    {
        if(max < arr[index])
        {
            max = arr[index];
        }
    }
    return max;
}



/////////////////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise Five ///////////////////////


void chargeMatrixRandom(int row, int column,int matrix[row][column])
{
    int indexA, indexB;
    srand(time(NULL));
    for(indexA = 0; indexA < row; indexA++)
    {
        for(indexB = 0; indexB < column; indexB++)
        {
            matrix[indexA][indexB] = rand()%100;
        }
    }
}

int mostPrecipitationDay(int month,int matrix[month][31])
{
    int index = 0;
    int great = matrix[month][index];
    for(index = 0; index< 31; index++)
    {
        if(matrix[month][index] > great)
        {
            great = matrix[month][index];
        }
    }

    return great;
}


void chargeMonthsArray(int matrix[12][31],int arr[])
{
    int index, month;
    for(index = 0,month = 0; month < 12; month++,index++)
    {
        arr[index] = mostPrecipitationDay(month,matrix);
    }
}


void showMatrix(int row, int column, int matrix[row][column])
{
    int indexA, indexB;
    for(indexA = 0; indexA < row; indexA++)
    {
        for(indexB = 0; indexB < column; indexB++)
        {
            printf("[%d]",matrix[indexA][indexB]);
        }
        printf("\n");
    }
}

/////////////////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise Six ///////////////////////

int palindromeString(char arr[],int valids)
{
    int indexA = 0, indexB = valids - 1, flag = 0;
    char auxA = arr[indexA], auxB = arr[indexB];
    while(indexA < valids && indexB>=0)
    {
        if(auxA == auxB)
        {
            indexA++;
            indexB--;
            auxA = arr[indexA];
            auxB = arr[indexB];
            flag = 1;
        }
        else
        {
            flag = 0;
            indexA = valids;
            indexB = -1;
        }
    }
    return flag;
}


/////////////////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise Seven ///////////////////////

void changeValueByPointer(int * a, int * b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}


/////////////////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise Eight ///////////////////////

int minorPosition(int arr[],int valids, int pos)
{
    int index = pos + 1, minor = arr[pos], minPos = pos;
    while(index < valids)
    {
        if(minor > arr[index])
        {
            minor = arr[index];
            minPos = index;
        }
        index++;
    }
    return minPos;
}


void selectionSort(int arr[],int valids){
    int minorPos, index, aux;
    for(index = 0; index < valids-1; index++){
        minorPos = minorPosition(arr,valids,index);
        aux = arr[minorPos];
        arr[minorPos] = arr[index];
        arr[index] = aux;
    }
}


int mixArrays(int arrA[], int arrB[], int arrDest[], int validsA, int validsB){
    int indexA = 0, indexB = 0, indexDest = 0;
    while(indexA<validsA)
    {
        arrDest[indexDest]=arrA[indexA];
        indexA++;
        indexDest++;
    }
    while(indexB<validsB)
    {
        arrDest[indexDest]=arrB[indexB];
        indexB++;
        indexDest++;
    }

    selectionSort(arrDest,indexDest);

    return indexDest;
}




