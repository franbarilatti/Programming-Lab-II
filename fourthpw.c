#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "fourthpw.h"
#define FILE_NAME "values.bin"

void practiceFourMenu()
{
    int opt, exit = 0;
    while(exit == 0)
    {
        system("cls");
        printf("\n============== Practice IV ==============");
        printf("\n[1]-Exercise 1\n[2]-Exercise 2\n[3]-Exercise 3\n[4]-Exercise 4\n[5]-Exercise 5\n[6]-Exercise 6\n[7]-Exercise 7\n[8]-Exercise 8\n[9]-Exercise 9\n[10]-Exercise 10\n[0]- Exit\n\n Select one option and press Enter: ");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            system("cls");
            char
            Node * list = inicList();
            list = chargeListAtFileAtLast(list,fileName);
            showList(list);
            printf("\n\n");
            system("pause");
            break;
        case 2:
            system("cls");
            list = inicList();
            list = chargeListAtFileSorted(list,fileName);
            showList(list);
            printf("\n\n");
            system("pause");
            break;
        case 3:
            system("cls");

            printf("\n\n");
            system("pause");
            break;
        case 4:
            system("cls");

            printf("\n\n");
            system("pause");
            break;
        case 5:
            system("cls");

            system("pause");
            break;
        case 6:
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

///////////////////////  Functional Functions ///////////////////////

Node * inicList(){
    return NULL;
}

Node * createNode(int value){
    Node * aux = (Node*) malloc(sizeof(Node));
    aux -> value = value;
    aux -> next = NULL;
    return aux;
}

Node * addAtFirst(Node * list, Node * newNode){
    if(list == NULL){
        list = newNode;
    }else{
        newNode -> next = list;
        list = newNode;
    }
    return list;
}

Node * searchLastNode(Node * list){
    Node * aux = list;
    while(aux -> next != NULL){
        aux = aux -> next;
    }
    return aux;
}


Node * addAtLast(Node * list, Node * newNode){
    if(list == NULL){
        list = newNode;
    }else{
        Node * last = searchLastNode(list);
        last -> next = newNode;
    }
    return list;
}

Node * sortAdd(Node * list,Node * newNode){
    if(list == NULL){
        list = newNode;
    }else if(list -> value > newNode -> value){
        list = addAtFirst(list,newNode);
    }else{
        Node * next = list -> next;
        Node * previous = list;
        while(next != NULL && newNode -> value > next -> value){
            previous = next;
            next = next -> next;
        }
        newNode -> next = next;
        previous -> next = newNode;
    }
    return list;
}

void chargueFile(){
    srand(time(NULL));
    int index = 0, value;
    FILE * file = fopen("values.bin","wb");
    if(!file){
        printf("\nERROR");
    }else{
        while(index != 10){
            value = rand()%100;
            fwrite(&value,sizeof(int),1,file);
            index++;
        }
        printf("\nSUCCESS");
        fclose(file);
    }
}

void showList(Node * list){
    Node * aux = list;
    while(aux -> next != NULL){
        printf("[%d]-",aux -> value);
        aux = aux -> next;
    }
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise One ///////////////////////

Node * chargeListAtFileAtLast(Node * list,char fileName[]){
    FILE * file = fopen(fileName,"rb");
    int value;
    Node * newNode = inicList();
    if(!file){
        printf("\nERROR");
    }else{
        while(fread(&value,sizeof(int),1,file) > 0){
            newNode = createNode(value);
            list = addAtLast(list,newNode);
        }
        fclose(file);
    }
    return list;
}


///////////////////////////////////////////////////////////////////////////////

///////////////////////  Exercise One ///////////////////////

Node * chargeListAtFileSorted(Node * list,char fileName[]){
    FILE * file = fopen(fileName,"rb");
    int value;
    Node * newNode = inicList();
    if(!file){
        printf("\nERROR");
    }else{
        while(fread(&value,sizeof(int),1,file) > 0){
            newNode = createNode(value);
            list = sortAdd(list,newNode);
        }
        fclose(file);
    }
    return list;
}
