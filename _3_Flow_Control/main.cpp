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
    char word[ ] = { 'H', 'e' ,'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0' };
    for( char c : word ) std::cout << c; // c <--eqv--> word[i]
    std::cout << std::endl; 
    // for( every element of that type :(in) array of elements of that type  )

    return 0;
    
}
