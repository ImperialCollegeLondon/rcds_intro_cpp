#include <iostream>
using namespace std;

class Rectangle {
   public:
      // Length of rectangle
      double width;
      // Height of rectangle
      double height;
      // Method computing area
      double area() {return width * height;}
      // Method specifying dimensions
      void set_dimensions(double, double);
};

void Rectangle::set_dimensions(double x, double y) {
    width = x;
    height = y;
}

// Square class inherits from Rectangle
class Square : public Rectangle {
   public:
      // Constructor that ensures width and height are equal
      Square(double side) {set_dimensions(side, side);}
};

int main() {

    // Declare Rec1 and Rec2 of type Rectangle
    Rectangle Rec1;
    Rectangle Rec2;
    Square Sq1(4);  // Square with side length 4
    double area;

    // Rectangles specification
    Rec1.set_dimensions(5, 6);
    Rec2.set_dimensions(3, 4);

    // Compute area of Rec1
    area = Rec1.area();
    cout << "Area of Rec1: " << area << endl;

    // Compute area of Rec2
    area = Rec2.area();
    cout << "Area of Rec2: " << area << endl;

    // Compute area of Sq1 (Square)
    area = Sq1.area();
    cout << "Area of Sq1: " << area << endl;

    return 0;
}