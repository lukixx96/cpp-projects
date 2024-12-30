
#include "unions.h"

// Print the size of a union in memory
void printUnionSize() {
    BasicUnion u;
    std::cout << "Size of BasicUnion: " << sizeof( u ) << " bytes" << std::endl; // Displays the union's size
}

// Demonstrate access to union members
void demonstrateAccess() {
    BasicUnion u;
    u.intValue = 42; // Set integer value
    std::cout << "Set intValue to 42" << std::endl;
    std::cout << "Access intValue: " << u.intValue << std::endl;

    u.floatValue = 3.14f; // Overwrites the memory
    std::cout << "Set floatValue to 3.14" << std::endl;
    std::cout << "Access floatValue: " << u.floatValue << std::endl;

    strcpy( u.charArray, "Hello, union!" ); // Overwrites the memory
    std::cout << "Set charArray to \"Hello, union!\"" << std::endl;
    std::cout << "Access charArray: " << u.charArray << std::endl;
}

// Pass union by value
void passUnionByValue( BasicUnion u ) {
    std::cout << "Inside passUnionByValue: intValue = " << u.intValue << std::endl;
}

// Pass union by reference
void passUnionByReference( BasicUnion& u ) {
    std::cout << "Inside passUnionByReference: intValue = " << u.intValue << std::endl;
    u.intValue = 100; // Modify the value
}

// Pass union by pointer
void passUnionByPointer( BasicUnion* u ) {
    std::cout << "Inside passUnionByPointer: intValue = " << u->intValue << std::endl;
    u->intValue = 200; // Modify the value
}

// Demonstrate compiler error (commented by default)
void demonstrateUndefinedBehavior() {
    // Uncomment the following lines to force a compiler error:

    BasicUnion u;
    u.intValue = 42;
    u.floatValue = 3.14f; // Modifying multiple members at the same time is not allowed
    std::cout << "Of BasicUnion u: intValue = " << u.intValue << ", floatValue = " << u.floatValue << "\n";
}

// Demonstrate anonymous unions
void demonstrateAnonymousUnion() {
    struct {
        union {
            int intValue;
            float floatValue;
            char charArray[ 20 ];
        };
    } anon;

    anon.intValue = 55; // Direct access without a member name
    std::cout << "Anonymous union intValue: " << anon.intValue << std::endl;

    anon.floatValue = 6.28f; // Overwrites memory
    std::cout << "Anonymous union floatValue: " << anon.floatValue << std::endl;
}

// Demonstrate union-like class with anonymous union
class UnionLikeClass {
    public:
        UnionLikeClass() : intValue( 0 ) {} // Constructor initializes intValue
        ~UnionLikeClass() {} // Destructor

        void setIntValue( int val ) { intValue = val; }
        void setFloatValue( float val ) { floatValue = val; }
        void printValues() const {
            std::cout << "intValue: " << intValue << ", floatValue: " << floatValue << std::endl;
        }

    private:
        union {
            int intValue;
            float floatValue;
        }; // Anonymous union inside the class
};

void demonstrateUnionLikeClass() {
    UnionLikeClass u;
    u.setIntValue( 99 );
    u.printValues(); // intValue is 99, floatValue might be undefined (shared memory not managed)
    // won't give compiler error but the value is undefined
}
