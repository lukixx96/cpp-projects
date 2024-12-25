
#ifndef TEST2_H
#define TEST2_H

class Shape {
    public:
        virtual void draw() const; //virtual makes basePointer dynamically bind the function to derived objects' body
};

class Circle : public Shape {
    public:
        void draw() const override;
};

class Square : public Shape {
    public:
        void draw() const override;
};

#endif