#include <iostream>

class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a generic shape" << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a square" << std::endl;
    }
};

int main() {
    Shape* shape1;
    
    if(true)
    {
        shape1 = new Circle();
    }
    else
    {
        shape1 = new Square();
    }

    shape1->draw(); // Outputs: "Drawing a circle"

    delete shape1;

    return 0;
}