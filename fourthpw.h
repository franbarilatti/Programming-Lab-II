#ifndef FOURTHPW_H_INCLUDED
#define FOURTHPW_H_INCLUDED

// Structs //
typedef struct{
    int value;
    struct node * next;
} Node;


// Void Functions //
void practiceFourMenu();
void chargueFile();
void showList(Node * list);

// Int Functions //

// Node Functions //
Node * sortAdd(Node * list,Node * newNode);
Node * addAtLast(Node * list, Node * newNode);
Node * searchLastNode(Node * list);
Node * addAtFirst(Node * list, Node * newNode);
Node * createNode(int value);
Node * inicList();
Node * chargeListAtFileAtLast(Node * list,char fileName[]);
Node * chargeListAtFileSorted(Node * list,char fileName[]);

// Bool Functions //

#endif // FOURTHPW_H_INCLUDED
