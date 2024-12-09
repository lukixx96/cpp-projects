
#include <iostream>
#include <string>
#include "header.h"

using namespace std;

void string_procedure(){

    std::cout << "********************* STRING PROCEDURE *********************" << std::endl;
              
    string str1 = "Hello";
    string str2 = "World";
    string str3 = str1 + str2; // strcat() + strcpy()
    int len3 = str1.size();
    std::cout << "str1: " << str1 << ";"  
        << "\nstr2: " << str2 << ";"
        << "\nstr3 = " << str3 << " ( length = " << len3 << " )" << std::endl;
    
    // accessing string for reading
    for( char c : str3 ){
        if( c == 'o' ){
            std::cout << "Looping through range-based for in reading (by value): Char 'o' found" << std::endl;
            break; // stopping to first occurence 
        }
    }
    // accessing string for writing
    int l2u = -32;
    for ( char &c : str3 ){
        if( c > 'a' ) c += l2u; // converting lower to upper case
        // 1. compiler implicitly casts chars into ints and then casts back to char when assigning into "c"
        // 2. since each element of str3 is to be accessed and modified, c must be a reference (an alias) otherwise
        // c would be just a copy that would be destroyed at the end of the for block
    }
    std::cout << "Looping through range-based for in writing (by reference): modded str3: " << str3 << std::endl;
    // anyhow, both in reading or writing, strings can be accessed through [] operator like an array
    str3[ 4 ] = 'o';
    std::cout << "modded str3: " << str3 << std::endl;
    str3[ 4 ] = 'O';

    // testing only peculiar methods: the obvious are ignored
    // ignored: length(), size(), swap(), 

    // resize()
    str1.resize( 4 ); // cuts to the size you chose, if the input size is bigger string size it does nothing
    std::cout << "resized str1: " << str1 << std::endl;
    // find() [returns 'npos' if not found]
    std::cout << "str3 = \"" << str3 << "\" -> ";
    size_t firstO = str3.find( 'O' );
    size_t secondO = str3.find( 'O', firstO + 1 ); 
    if( firstO != str3.npos ) std::cout << "First occurrence of 'O': " << firstO;
    else std::cout << "First occurrence of 'O': <NONE>";
    if( secondO != str3.npos ) std::cout << ", Second occurrence of 'O': " << secondO << std::endl;
    else std::cout << ", Second occurrence of 'O': <NONE>" << std::endl;
    string srcStr = "ci sono cinque esercizi da fare";
    const string strToFind = "ci";
    const char *strToFind2 = "ci";
    int cont = 0;
    int *occurrences = new int[ srcStr.length() ];
    for( int i = 0; i < srcStr.length(); i++ ) occurrences[ i ] = -1; // because found >= 0 always
    int found = srcStr.find( strToFind );
    std::cout << "srcStr = \"" << srcStr << "\" -> "; 
    if( found == string::npos ) std::cout << "\"" << strToFind << "\" not found in srcStr" << std::endl;
    else{
        do{
            occurrences[ cont++ ] = found;
            found = srcStr.find( strToFind, found + strToFind.length() );
        } while( found != str3.npos );
        std::cout << cont << " occurrences of \"" << strToFind << "\" found at ";
        for( int i = 0; i < cont; i++ ){
            if( i == cont - 1 ) std::cout << occurrences[ i ];
            else std::cout << occurrences[ i ] << " ";
        }
    }
    std::cout << std::endl;

    str1.push_back('!');
    std::cout << "str1 after push_back('!'): " << str1 << std::endl;

    str1.pop_back(); str1.pop_back();
    std::cout << "str1 after 2 times pop_back(): " << str1 << std::endl;

    str2.clear();
    std::cout << "str2 after clear(): \"" << str2 << "\" (empty: " << std::boolalpha << str2.empty() << ")" << std::endl;

    str3.replace(0, 5, "Hi"); // Replace "Hello" with "Hi"
    std::cout << "str3 after replace(0, 5, \"Hi\"): " << str3 << std::endl;

    string substring = str3.substr(0, 2); // Extract first two characters
    std::cout << "Substring of str3 (0, 2): \"" << substring << "\"" << std::endl;

    string str4 = "HiWorld";
    int comparison = str3.compare(str4);
    std::cout << "Comparing str3 (\"" << str3 << "\") with str4 (\"" << str4 << "\"): ";
    if (comparison == 0) std::cout << "Equal" << std::endl;
    else if (comparison < 0) std::cout << "str3 < str4" << std::endl;
    else std::cout << "str3 > str4" << std::endl;

    str3.erase(2, 3); // Erase 3 characters starting from index 2
    std::cout << "str3 after erase(2, 3): " << str3 << std::endl;

    //for the input
    // basic cin >> for no-space strings:
    std::cin >> str1;
    std::cout << "str1 = " << str1 << std::endl;
    // getline( inputstream, string ) to include spaces
    std::getline( std::cin, str1 ); // this is needed to handle the 'enter' key pressed during 'cin>>'
    std::getline( std::cin, str1 );
    std::cout << "str1 = " << str1 << std::endl;
    
    std::cout << "************************************************************\n\n" << std::endl;

}