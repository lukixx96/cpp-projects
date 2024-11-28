#include <iostream>

// Definizione di un enum
enum class Color { 
    Red, 
    Green, 
    Blue, 
    Unknown 
};

// Classe con funzione di conversione a enum
class Light {
public:
    explicit Light(int code) : code_(code) {}

    // Funzione di conversione implicita a Color
    operator Color() const {
        switch (code_) {
            case 1: return Color::Red;
            case 2: return Color::Green;
            case 3: return Color::Blue;
            default: return Color::Unknown;
        }
    }

    // Funzione di conversione implicita a int (non si possono avere 2 funz di conv impl verso lo stesso tipo)
    /* operator int() const { 
        return code_;
    } */
    // Se aggiungo l'altra conversione implicita ottengo l'errore di compilazione:
    // "candidate conversions include 'Light::operator int() const' and 'Light::operator Color() const'"

private:
    int code_;
};

int main() {

    // switch case obs
    std::cout << "Testing switch case with Class with unique implicit conversion to int/enum method" << std::endl;
    Light light(2); 
    switch (light) {  // Conversione implicita da Light a Color
        case Color::Red:
            std::cout << "Red light\n";
            break; 
        case Color::Green:
            std::cout << "Green light\n";
            // No break
        case Color::Blue:
            std::cout << "Blue light or continued from Green\n";
            break;
        default:
            std::cout << "Unknown light\n";
            break;
    }

    // foreach
    std::cout << "\nTesting foreach" << std::endl;
    char word[ ] = { 'H', 'e' ,'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0' };
    for( char c : word ) std::cout << c; // c <--eqv--> word[i]
    std::cout << std::endl; 
    // for( every element of that type :(in) array of elements of that type  )

    // break and continue
    std::cout << "\nTesting break and continue:" << std::endl;
    // expected output is integer number from 10 to 15 and 23
    int a = 10;
    do {
        if( a > 15 && a < 23 ) {
            a++; // skipping the loop: counter must always be updated 
            continue;
        }
        std::cout << "\tvalue of a: " << a << std::endl;
        if( a == 23 ) break; // terminate the loop
        a++;
    } while( a < 25 );

    // goto
    std::cout << "\nTesting goto (good usage exemple)" << std::endl;
    for( int i = 0; i < 10; i++ ){
        int j = 0;
        while( i < 8 && j < 10 ){
            for( int k = 0; k < 20; k+=2 ){
                std::cout << "(i,j,k) = (" << i << "," << j << "," << k  << ")" << std::endl;
                if( i == 5 && j == 3 && k == 12) goto STOP;
            }
            j++;
        }
    }
    STOP: std::cout << "total break" << std::endl;
    // a labelled instruction is exectued regardless of being targeted by a goto

    return 0;
    
}
