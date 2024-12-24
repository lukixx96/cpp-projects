
#ifndef TEST_H 
#define TEST_H

static int globalVar = 10;

int& printGlobalVar();
int *ptrGlobalVar(); 

int overloads( int );
int overloads( double );
int overloads( int, int );
int overloads( int, double );
int overloads( double, int );
// float overloads( int ); -> // this not possible
float overloads( float );

#endif