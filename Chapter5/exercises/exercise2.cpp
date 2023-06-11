#include <iostream>

using namespace std;

class Rectangle {

   public:
      // Length of rectangle
      double width;
      // Height of rectangle
      double height;
      // Method computing area
      double area() {return width*height;}
      // Method computing perimeter
      int perimeter() {return 2*(width+height);}
      // Method specifying dimensions
      void set_dimensions (double,double);

};

void Rectangle::set_dimensions (double x, double y) {

  width = x;
  height = y;

}

int main() {

    // Declare Rec1 and Rec2 of type Rectangle
    Rectangle Rec1;
    Rectangle Rec2;

    // Rec1 specification
    //Rec1.height = 5.0;
    //Rec1.width = 6.0;
    Rec1.set_dimensions(5.0,6.0);

    // Rec2 specification
    //Rec2.height = 10.0;
    //Rec2.width = 12.0;
    Rec2.set_dimensions(10.0,12.0);

    // Declare variables
    double area, perimeter;

    // Area, perimeter of Rec1
    area = Rec1.area();
    perimeter = Rec1.perimeter();
    cout << "Rec1 area: " << area << endl;
    cout << "Rec1 perimeter: " << perimeter << endl;

    // Area, perimeter of Rec2
    area = Rec2.area();
    perimeter = Rec2.perimeter();
    cout << "Rec2 area: " << area << endl;
    cout << "Rec2 perimeter: " << perimeter << endl;

    return 0;
}