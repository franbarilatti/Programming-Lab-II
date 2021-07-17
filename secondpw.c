#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "secondpw.h"
#include "primertp.h"

void practiceTwoMenu()
{
    int opt, exit = 0;
    while(exit == 0)
    {
        system("cls");
        printf("\n============== Practice II ==============");
        printf("\n[1]-Exercise 1\n[2]-Exercise 2\n[3]-Exercise 3\n[4]-Exercise 4\n[5]-Exercise 5\n[6]-Exercise 6\n[7]-Exercise 7\n[8]-Exercise 8\n[9]-Exercise 9\n[10]-Exercise 10\n[0]- Exit\n\n Select one option and press Enter: ");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            system("cls");
            Person pArrOrigin[5];
            Person *pArrDestiny = NULL;
            int validsA = chargePersonArray(pArrOrigin,5);
            char genere;
            printf("\n=============== Origin Array ===============\n");
            showPersonArray(pArrOrigin,validsA);
            printf("\n\n Ingress the find genere: ");
            scanf("%c",&genere);
            int validsB = generateNewPersonArrayByGenere(pArrOrigin,pArrDestiny,validsA,genere);
            printf("\n\n=============== Destiny Array ===============\n");
            showPersonArray(pArrDestiny,validsB);
            system("pause");
            break;
        case 2:
            system("cls");
            validsA = chargePersonArray(pArrOrigin,5);
            printf("\n=============== Unsorted Array ===============\n");
            showPersonArray(pArrOrigin,validsA);
            selectionSortPersonArray(pArrOrigin,validsA);
            printf("\n=============== Sorted Array ===============\n");
            showPersonArray(pArrOrigin,validsA);
            system("pause");
            break;
        case 3:
            system("cls");
            int value;
            Stack stackyA, stackyB;
            inicStack(&stackyA);
            inicStack(&stackyB);
            printf("\nIngress one element to the Stack: ");
            scanf("%d",&value);
            push(&stackyA,value);
            printf("\nIngress one element to the Stack: ");
            scanf("%d",&value);
            push(&stackyA,value);
            printf("\nIngress one element to the Stack: ");
            scanf("%d",&value);
            push(&stackyA,value);
            showStack(&stackyA);
            printf("Stacky A top: %d",top(&stackyA));
            printf("\n\n");
            push(&stackyB,pop(&stackyA));
            push(&stackyB,pop(&stackyA));
            showStack(&stackyB);
            system("pause");
            break;
        case 4:
            system("cls");
            chargeStack(&stackyA);
            showStack(&stackyA);
            chargeStack(&stackyB);
            showStack(&stackyB);
            Stack stackyC;
            inicStack(&stackyC);
            stackyC = mixStacks(stackyA,stackyB);
            showStack(&stackyC);
            system("pause");
            break;
        case 5:
            system("cls");
            int arr[5];
            validsA = chargeIntArray(arr,5);
            printf("\nOrigin Array:\n\n");
            showIntArray(arr,validsA);
            printf("\nAdd a element into the Array: ");
            scanf("%d",&value);
            insertion(arr,validsA-1,value);
            printf("\nArray whit new element:\n\n");
            showIntArray(arr,validsA);
            printf("\n\n");
            system("pause");
            break;
        case 6:
            system("cls");
            validsA = chargeIntArray(arr,5);
            printf("\nOrigin Array\n\n");
            showIntArray(arr,validsA);
            insertionSortArray(arr,validsA);
            printf("\nSorted Array\n\n");
            showIntArray(arr,validsA);
            printf("\n\n");
            system("pause");
            system("pause");
            break;
        case 7:
            system("cls");
            validsA = chargeIntArray(arr,5);
            printf("\nOrigin Array:\n\n");
            showIntArray(arr,validsA);
            printf("\nEliminate a element to the Array: ");
            scanf("%d",&value);
            insertion(arr,validsA-1,value);
            printf("\nArray whitout the element:\n\n");
            showIntArray(arr,validsA);
            printf("\n\n");
            system("pause");
            break;
        case 8:
            system("cls");

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

Person setPerson(char name[],char genere,int age)
{
    Person p;
    strcpy(p.name,name);
    p.genere = genere;
    p.age = age;
    return p;
}

int chargePersonArray(Person pArr[],int dimension)
{
    int index = 0, age;
    char esc, genere;
    char name[30];
    Person p;
    while(esc != 27 && index < dimension)
    {
        printf("\nName: ");
        fflush(stdin);
        gets(name);
        printf("\nGenere m/f: ");
        fflush(stdin);
        scanf("%c",&genere);
        printf("\nAge: ");
        scanf("%d",&age);
        p = setPerson(name,genere,age);
        pArr[index] = p;
        printf("\n\nPress any key for continue or ESC for exit: ");
        fflush(stdin);
        esc = getch();
        index++;
        if(index == dimension-1)
        {
            printf("\n\nRemains one slot in the array");
        }
    }
    return index;
}

int genereAccount(Person pArr[],int valids,char genere)
{
    int index, count;
    for(index = 0; index < valids; index++)
    {
        if(pArr[index].genere == genere)
        {
            count++;
        }
    }
    return count;
}

int generateNewPersonArrayByGenere(Person pArrOrigin[],Person *pArrDestiny,int validsA,char genere)
{
    int indexA, indexB = 0;
    int count = genereAccount(pArrOrigin,validsA,genere);
    pArrDestiny = (Person*) malloc(count * sizeof(Person));
    for(indexA = 0; indexA < validsA; indexA++)
    {
        if(pArrOrigin[indexA].genere == genere)
        {
            printf("\n%d",indexB);
            pArrDestiny[indexB] = pArrOrigin[indexA];
            indexB++;
        }
    }
    return indexB;
}

void showPerson(Person p)
{
    printf("\nPerson{");
    printf("\nName: %s",p.name);
    printf("\nGenere: %c",p.genere);
    printf("\nAge: %d",p.age);
    printf("\n}\n");
}

void showPersonArray(Person pArr[],int valids)
{
    int index;
    for(index = 0; index < valids; index++)
    {
        showPerson(pArr[index]);
    }
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise Two ///////////////////////


int minorPositionPersonArray(Person pArr[],int valids, int pos){
    int index = pos+1, minPos = pos;
    Person minor = pArr[pos];
    while(index < valids){
        if(minor.age > pArr[index].age){
            minor = pArr[index];
            minPos = index;
        }
        index++;
    }
    return minPos;
}

void selectionSortPersonArray(Person pArr[], int valids){
    int minPos, index;
    Person aux;
    for(index = 0; index < valids; index++){
        minPos = minorPositionPersonArray(pArr,valids,index);
        aux = pArr[minPos];
        pArr[minPos] = pArr[index];
        pArr[index] = aux;
    }
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise Three ///////////////////////


void inicStack(Stack *s){
    s ->limitPos = 0;
}

void push(Stack *s,int value){
    int index = s->limitPos;
    s -> values[index] = value;
    s -> limitPos++;
}

int pop(Stack *s){
    int value = s -> values[s ->limitPos - 1];
    s -> limitPos--;
    return value;
}

int top(Stack *s){
    int value = s ->values[s -> limitPos-1];
    return value;
}

int isEmpty(Stack *s){
    return(s ->limitPos == 0);
}

void showStack(Stack *s){
    int index;
    printf("\n================== Stack ==================\n");
    for(index = 0; index < s -> limitPos; index++){
        printf("[%d] ",s -> values[index]);
    }
}


///////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise Four ///////////////////////

void copyStack(Stack*a, Stack*b){
    Stack aux;
    inicStack(&aux);
    while(!isEmpty(b)){
        push(&aux,pop(b));
        push(a,pop(&aux));
    }
}

void selectionSortStack(Stack *s){
    Stack aux, sorted, minor;
    inicStack(&aux);
    inicStack(&sorted);
    inicStack(&minor);
    push(&aux,pop(s));
    while(!isEmpty(s)){
        push(&minor,pop(s));
        if(top(&minor) > top(s)){
            push(&aux,top(&minor));
            push(&minor,pop(s));
        }
        else{
            push(&aux,pop(s));
        }
        push(&sorted,pop(&minor));
    }

    copyStack(s,&sorted);
}

Stack mixStacks(Stack a, Stack b){
    Stack destiny;
    inicStack(&destiny);
    while(!isEmpty(&a) || !isEmpty(&b)){
        push(&destiny,pop(&a));
        push(&destiny,pop(&b));
    }
    selectionSortStack(&destiny);

    return destiny;
}

void chargeStack(Stack *s){
    int value;
    char quit;
    while(quit != 27){
        printf("\nPut a number into the Stack: ");
        scanf("%d",&value);
        push(s,value);
        printf("\n\nPress any key for continue or ESC for exit: ");
        fflush(stdin);
        quit = getch();
    }
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise Five ///////////////////////


void insertion(int arr[],int valids, int value){
    int index;
    for(index = valids; index >= 0 && value < arr[index];index--){
        arr[index + 1] = arr[index];
    }
    arr[index + 1] = value;
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise Six ///////////////////////

void insertionSortArray(int arr[],int valids){
    int index;
    for(index = 0;index < valids - 1;index++){
        insertion(arr,index,arr[index+1]);
    }
}


///////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise Seven ///////////////////////

void eliminateElement(int arr[],int valids, int value){
    int index;
    for(index = 0; index < valids; index++){
        if(arr[index] == value){
            arr[index] = arr[index +1];
        }
    }
}


///////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise Eight ///////////////////////

/*Student chargeStudentInfo(){
    Student st;
    int tuition;
    char name[30];
    printf("\nName: ");
    gets(name);
    strcpy(st.name,name);
    st.tuition = rand()%100+1
    return st;
}


void chargeSignatureArray(Signature arr[]){
    arr[0].signaruteName = "Programing Lab";
    arr[0].code = 1;
    arr[1].signaruteName = "Math";
    arr[1].code = 2;
    arr[2].signaruteName = "Data Base";
    arr[2].code = 3;
    arr[3].signaruteName = "Business Organization";
    arr[3].code = 4;
    arr[4].signaruteName = "Statistic";
    arr[4].code = 5;
}

int chargeStudentArray(Student arr[],int dimension){
    int index = 0;
    char quit;
    Student aux;
    while(quit != 27 && index < dimension){
        aux = chargeStudentInfo();
        arr[index] = aux;
        printf("\n\nPress any key for continue or ESC for exit: ");
        fflush(stdin);
        esc = getch();
        index++;
    }

    return index;
}

int validateTuition(int tuition, Student arr[],int valids){
    int index, flag = 0;
    for(index = 0; index < valids; index++){
        if(arr[index].tuition == tuition)
            flag = 1;
    }
    return flag;
}

int validateCode(int code, Signature arr[],int valids){
    int index, flag = 0;
    for(index = 0; index < valids; index++){
        if(arr[index].code == code)
            flag = 1;
    }
    return flag;
}

int chargeNotesArray(Note nArr[],int dimension,Signature sgArr[],int sgValids,Student stArr[],int stValids){
    int index = 0, tuition, code, note, flag;
    char quit;
    Note aux;
    while(quit != 27 && index < dimension){
        printf("ingress Tuition: ");
        scanf("%d",&tuition);
        flag = validateTuition(tuition,stArr,stValids);
        if(flag == 1){
            aux.tuition = tuition;
            printf("ingress Code: ");
            scanf("%d",&code);
            flag = validateCode(code,sgArr,sgValids);
            if(flag == 1){
                aux.code = code;
                printf("ingress Note: ");
                scanf("%d",&note);
                aux.note = note;
                arr[index] = aux;
                index++;
            }
            else{
                printf("\n\nThe code doesn't exist\n\n");
            }
        }
        else{
            printf("\n\nThe tuition doesn't exist\n\n");
        }
        printf("\n\nPress any key for continue or ESC for exit: ");
        fflush(stdin);
        esc = getch();
    }

    return index;
}*/

