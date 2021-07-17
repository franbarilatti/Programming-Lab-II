#ifndef PRIMERTP_H_INCLUDED
#define PRIMERTP_H_INCLUDED


// Void Functions //
void practiceOneMenu();
void initializeArray(int arr[],int volume);
void showIntArray(int arr[],int valids);
void invertCharArray(char arr[],int valids);
void showCharArray(char arr[],int valids);
void chargeMatrixRandom(int row, int column,int matrix[row][column]);
void chargeMonthsArray(int matrix[12][31],int arr[]);
void showMatrix(int row, int column, int matrix[row][column]);
void changeValueByPointer(int * a, int * b);
void selectionSort(int arr[],int valids);

// Int Functions //
int chargeIntArray(int arr[],int volume);
int chargueIntArrayRandom(int arr[],int volume);
int arraySize(int arr[],int valids);
int sumArray(int arr[],int valids);
int chargeCharArray(char arr[],int volume);
int decimalValueToArray(int arr[],int valids);
int maxValueToArray(int arr[],int valids,int pos);
int mostPrecipitationDay(int month,int matrix[month][31]);
int minorPosition(int arr[],int valids, int pos);
int mixArrays(int arrA[], int arrB[], int arrDest[], int validsA, int validsB);

// Float Functions //

float arrayPromedy(int valids, int sum);

// Bool Functions //
int palindromeString(char arr[],int valids);


#endif // PRIMERTP_H_INCLUDED
