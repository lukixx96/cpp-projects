
#ifndef STRUCTS_H
#define STRUCTS_H



// Define the struct Register
struct Register {
    std::string name;
    int age;
};

// Function prototypes
void processByValue( Register person );
void processByPointer( Register* person );
void processByReference( Register& person );

// Define a struct with private data and a member function
struct PrivateStruct {
    private:
        int privateValue;

    public:
        PrivateStruct( int value ) : privateValue( value ) {}
        int getValue() const { return privateValue; }
        void setValue( int value ) { privateValue = value; }
};

// Derived struct inheriting from PrivateStruct
struct DerivedStruct : public PrivateStruct {

    DerivedStruct( int value ) : PrivateStruct( value ) {}
    void displayValue() {
        std::cout << "Derived value: " << getValue() << std::endl;
    }
    
};

// Derived struct inheriting from PrivateStruct with a mutable member
struct MutableStruct : public PrivateStruct {

    private:
        mutable int mutableValue;

    public:
        int count = 0;
        MutableStruct( int pvalue, int mvalue ) : PrivateStruct( pvalue ) {
            mutableValue = mvalue; 
        }
        int getMutableValue() const { return mutableValue; }
        void setMutableValue( int mvalue ) { mutableValue = mvalue; }
        void displayValue() const {
            std::cout << "Derived value: " << getValue() << std::endl;
        }
        void displayAllValue() const {
            // count++; // uncommentig generated compile error because members are said to be read-only in this method
            std::cout << "Derived value: " << getValue() << ", Mutable value: " << getMutableValue() << std::endl;
        }
        void mutateValue() const; 

};


#endif    