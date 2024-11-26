
#include <iostream>
#include "header.h"
#include "globs.h"
#include <ctime>

//per aspettare 3 secondi
#include <thread>
#include <chrono>
//

using namespace std;

void func1( int );
void func2( );

void use_static( void );
void use_static_2( void );

int xtglb = 29; //ocazz pure lui

enum class Color2{
    cyan = 2, magenta, yellow
};

int& reffun( int );
 
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

    reffun( 2 );        // stampa q=17*i=2 -> 34
    reffun( 3 ) = 4;    // stampa q=17*i=3 -> 51 e poi aggiorna q (static) al valore 4 grazie alla ref to static
    reffun( 3 );        // stampa q=4*i=3 -> 12
    

    clock_t runtime;
    runtime = clock();
    cout << "[ clock() ] main() execution: " << runtime << endl;
    std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
    runtime = clock();
    cout << "[ clock() ] main() execution afer 1 sec: " << runtime << endl;

    time_t sys_time;
    sys_time = time( &sys_time );
    cout << "[ time() ] Seconds elapsed from 1/1/1970 till now: " << sys_time << endl;

    char *date_string;
    date_string = ctime( &sys_time );
    cout << "[ ctime() ] Formatted data: " << date_string; //alla fine della strina c'è \n e \0

    std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
    time_t sys_time_2;
    sys_time_2 = time( &sys_time_2 );
    tm *time_struct;
    time_struct = localtime( &sys_time_2 );
    cout << "[ localtime() ] Structured local time (2nd sys_time): " << endl << "\t"
        << time_struct->tm_wday << " " 
        << time_struct->tm_year << " "
        << time_struct->tm_mon << " "
        << time_struct->tm_mday << " "
        << time_struct->tm_hour << " " 
        << time_struct->tm_min << " "
        << time_struct->tm_sec << " "
        << time_struct->tm_yday << " "
        << time_struct->tm_isdst << endl;

    char *date_string_2;
    date_string_2 = asctime( time_struct );
    cout << "[ asctime() ] Formatted data: " << date_string_2; //alla fine della stringa c'è \n e \0
    // NON SI PASSA UNA STRUCT PUNT CON & MA SOLO CON L'HANDLER.

    tm *utc_time;
    utc_time = gmtime( &sys_time_2 );
    cout << "[ gmtime() ] Structured UTC time (2nd sys_time):" << endl << "\t"
        << utc_time->tm_wday << " " 
        << utc_time->tm_year << " "
        << utc_time->tm_mon << " "
        << utc_time->tm_mday << " "
        << utc_time->tm_hour << " " 
        << utc_time->tm_min << " "
        << utc_time->tm_sec << " "
        << utc_time->tm_yday << " "
        << utc_time->tm_isdst << endl; 

    time_t utc_time_calendar;
    utc_time_calendar = mktime( utc_time );
    cout << "[ mktime() ] Calendar-time eqv of UTC struct: " << utc_time_calendar << endl;

    double elapsed;
    elapsed = difftime( sys_time_2, sys_time );
    cout << "[ difftime() ] Time interval (supposed 2sec): " << elapsed << endl;

    /* size_t strftime(char *buffer, size_t maxSize, const char *format, const struct tm *timeptr);

        buffer: dove verrà salvata la stringa formattata.
        maxSize: dimensione massima del buffer.
        format: stringa di specifica del formato (es. %Y-%m-%d).
        timeptr: puntatore alla struttura tm da formattare.

        return:
        Numero di caratteri scritti (escluso il terminatore \0).
        0 se il buffer  è troppo piccolo.

        Formati principali:
        Data:
        %Y: anno (es. 2024)
        %m: mese (01-12)
        %d: giorno (01-31)
        Ora:
        %H: ore (00-23)
        %M: minuti (00-59)
        %S: secondi (00-59)
        Combinazioni:
        %F: data completa (YYYY-MM-DD)
        %T: orario completo (HH:MM:SS)   */
 
    time_t now = time( NULL );
    struct tm *timeInfo = localtime( &now );
    char buffer[100];
    strftime( buffer, sizeof( buffer ), "%Y/%m/%d %H:%M:%S", timeInfo );
    cout << "[ strftime() ] Orario formattato: " << buffer << endl; 
    strftime( buffer, sizeof( buffer ), "%F %T", timeInfo );   
    cout << "[ strftime() ] Orario formattato (%F e %T): " << buffer << endl;
    
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

int& reffun( int i ){

    static int q = 17;
    cout << "Sofia ha detto: " << q*i << endl;

    //int local_var
    //return local_var // compiler error
    return q; 

}