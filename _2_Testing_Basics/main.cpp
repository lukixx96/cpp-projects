
#include <iostream>
#include "header.h"
#include "globs.h"
#include <ctime>

using namespace std;

void func1( int );
void func2( );

void use_static( void );
void use_static_2( void );

int xtglb = 29; //ocazz pure lui

enum class Color2{
    cyan = 2, magenta, yellow
};
 
int main() {

    /* cout << sizeof( int ) << " " 
        << sizeof( unsigned int ) << " "
        << sizeof( long ) << " "
        << sizeof( unsigned long long ) << " "
        << sizeof( short ) << " "
        << sizeof( unsigned short ) 
        << endl;

    int a = -2;
    unsigned int b = -1;
    long c = -1;
    unsigned long d = -1;
    short e = -1;
    unsigned short f = -1; 

        cout << a << " " 
        << b << " "
        << c << " "
        << d << " "
        << e << " "
        << f 
        << endl;

    cout << sizeof( float ) << " " 
        << sizeof( double ) << " "
        << sizeof( long double ) << " "
        << endl;

    float g = 210;
        g = 3.14;
    cout << g << endl;
        g = 31443335E-7;
    cout << g << endl;
    long double h = 0;
        h = 31443335E-7L;
    cout << h << endl;

    int binary = 0b0010;
    int octal = 02;
    cout << ( binary == octal ) << endl; //testing v14
 */

    char s1 = 0b01000000;
    char s2 = '@';
    int s3 = s2;
    cout << ( int )s1 << " " << ( s1 == s2 ) << " " << s3 << endl; //char eqv litterals

    char a = 'H';
    char b = 'E';
    char c = 'Y';
    char d = '\n'; //enter new line
    char e = '\t'; //tab to enter space 
    cout << a << b << c << d << a << b << c << e << a << b << c <<endl;

    bool flag;
    flag=1;//this is true
    bool flag1=true;

    cout << flag << " " << flag1 << endl;

/*     int dim = 10;
    int vec[dim];
    for( int i = 0; i < dim; i++ ){
        vec[ i ] = i;
        cout << vec[ i ] << endl;
    } */    //ESEMPIO DI CATTIVA PROGRAMMAZIONE

    int shm = 2;

    func1( 1 );
    func2();    //even though shm masks global extern shm, the 'shm' func1 and func2 refer is the external global

    cout << shm << " " << endl; //::shm won't work: once global scope is masked you cannot access directly to ex glob anynore

    int prova;
    cout << prova << endl; //monnezza

    prova = 3;
    /* int *restrict pointer = &prova; //teoricamente se provo ad accedere con un altro puntatore dovrebbe essere contro l'intenzione
                                    // del programmatore
    cout << pointer << " " << *pointer << " " << &pointer << endl; */ //non funziona perchè il compilatore non implementa restrict

    int count = 10;
    while( count-- ){
        use_static();
    }
    cout << endl;
    count = 10;
    while( count-- ){
        use_static_2();
    }    
    cout << endl;
    // static local variables with same identifier in different functions are not shared!!
    // static is persistent for a single function throughout every call but not shared with other functions

    /* glb = 29; //ocazz
    cout << "main chiama: glb = " << glb << endl;
    //fglob();
    cout << "main chiama: glb = " << glb << endl;  */

    //OSS1: non posso avere una global (nè extern nè static) in un header incluso da più sorgenti altrimenti ho multiple
    // definition error.
    // SOL1. VARIABILE CONDIVISA: dichiararla extern nell'header (quindi in tutti i sorgenti che lo includono) e definirla in 1 solo
    // SOL2. VARIABILE NON-CONDIVISA: dichiarata/definita static nell'header, sarà globale per un singolo file ma non per tutti.

    cout << "main chiama: xtglb = " << xtglb << endl;
    xglob();
    cout << "main dopo xglob chiama: xtglb = " << xtglb << endl;

    stglb += 18;
    cout << "main chiama: stglb = " << stglb << endl;
    sglob();
    cout << "main dopo sglob chiama: stglb = " << stglb << endl;

    srand( ( unsigned ) time( NULL ) );
    int j = rand();
    cout << "rng: " << j << endl;

    enum Day {
        mon, tue, wed, thu = 5, fri, sat = 9, sun
    };
    Day day = fri;
    int value1 = day;
    cout << "Unscoped enum: " << day << " " << value1 << endl;

    enum class Color{
        red, green, blue
    };
    Color myColor = Color::red;
    //Color myColor2 = red; // è errore: devo accedere a 'red' con SRO
    int value2 = static_cast< int >( myColor );
    //int value2 = myColor; // è errore: non posso convertire implicitamente
    cout << "Scoped enum: " << value2 << endl;
    // cout << myColor << " " << endl; genera problemi: non so se dovuto al fatto che l'enum non sia globale i.q.c.

    Color2 myColor2 = Color2::cyan;
    // cout << "Global scoped enum: " << myColor2 << endl; non corretto anche con enum globale
    cout << "Global scoped enum: " << static_cast< int >( myColor2 ) << endl;

    return 0;

}

void use_static( void ){

    static int count = 5;
    count--;
    cout << count << " ";

}

void use_static_2( void ){

    static int count = 5;
    count++;
    cout << count << " ";

}