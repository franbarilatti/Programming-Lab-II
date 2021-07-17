#ifndef SECONDPW_H_INCLUDED
#define SECONDPW_H_INCLUDED

// Structs //
typedef struct {
      char name[30];
      char genere;
      int age;
}Person;

typedef struct{
     int values[100];
     int limitPos; //posición de nuevo tope, lugar en donde se almacenará el nuevo valor
}Stack;

typedef struct {
  int tuition;
  char name[30];
} Student;

typedef struct {
  int code;
  char signaruteName[20];
} Signature;

typedef struct {
  int tuition;
  int code;
  int note;
} Note;


// Void Functions //
void showPersonArray(Person pArr[],int valids);
void showPerson(Person p);
void practiceTwoMenu();
void selectionSortPersonArray(Person pArr[], int valids);
void inicStack(Stack *s);
void push(Stack *s,int value);
void showStack(Stack *s);
void copyStack(Stack*a, Stack*b);
void chargeStack(Stack *s);
void selectionSortStack(Stack *s);
void insertion(int arr[],int valids, int value);
void insertionSortArray(int arr[],int valids);
void eliminateElement(int arr[],int valids, int value);
void chargeSignatureArray(Signature arr[]);

// Int Functions //
int chargePersonArray(Person pArr[],int dimension);
int genereAccount(Person pArr[],int valids,char genere);
int generateNewPersonArrayByGenere(Person pArrOrigin[],Person *pArrDestiny,int validsA,char genere);
int minorPositionPersonArray(Person pArr[],int valids, int pos);
int pop(Stack *s);
int top(Stack *s);
int isEmpty(Stack *s);
int chargeNotesArray(Note nArr[],int dimension,Signature sgArr[],int sgValids,Student stArr[],int stValids);
int validateCode(int code, Signature arr[],int valids);
int validateTuition(int tuition, Student arr[],int valids);
int chargeStudentArray(Student arr[],int dimension);

// Person Functions //
Person setPerson(char name[],char genere,int age);

// Stack Functions //

Stack mixStacks(Stack a, Stack b);

// Student Functions //
Student chargeStudentInfo();


#endif // SECONDPW_H_INCLUDED
