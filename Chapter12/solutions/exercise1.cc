/*
  Exercise: Object Oriented Programming
  Author: Jesús - 2020
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

// Absrtact class Animal
class Animal {

    // Private attributes are only accesible form inside the class
    private:
        // Atributes of the animal class
        std::string name;
        double height;
        double weight;
        // Static variable. Share the same value for all objects
        static int numOfAnimals;

    // Public fields/methods are ccesible from outside the class
    public:
        std::string GetName(){return name;}
        void SetName(std::string name){this->name = name;}
        double GetHeight(){return height;}
        void SetHeight(double height){this->height = height;}
        double GetWeight(){return weight;}
        void SetWeight(double weight){this->weight = weight;}
        // Set all atributes together. (Order matters!)
        void SetAll(std::string, double, double);
    
        // Constructor. Called automathically each time an object is created. Tip: same name as the class
        Animal(std::string, double, double);
        // Overloaded constructor. Handle cases where no information is passed
        Animal();
        // De-constructor. Called authomatically when an object is deleted
        ~Animal();
        // Static Method. Can only acces static fields
        static int GetNumOfAnimals(){return numOfAnimals;}
        // Method to overwrite.
        void PrintAtributes();
};

// Definition of the methods of the class Animal

// Refer to the class fields and methods by using the comand ::
int Animal::numOfAnimals = 0;
void Animal::SetAll(std::string name, double height, double weight)
{
    this->name = name;
    this->weight = weight;
    this->height = height;
    Animal::numOfAnimals++;
}
    
// Constructor
Animal::Animal(std::string name, double height, double weight)
{
    this->name = name;
    this->weight = weight;
    this->height = height;
    Animal::numOfAnimals++;
}

// Constructor to handle the default, when no atributes are passed to the class
Animal::Animal()
{
    this->name = "Null";
    this->weight = 0;
    this->height = 0;
    Animal::numOfAnimals++;
}

// De-constructor
Animal::~Animal()
{
    cout << "Animal " << this -> name << " destroyed" << endl;
}

// Print out method
void Animal::PrintAtributes()
{
    cout << this -> name << " is " << this -> height << " cm tall and " << this -> weight << " kg in weight" << endl;
}

// Inherited class from Animal
class Cat : public Animal
{
    private:
        // New private atributes, in addition to the ones already in Animal
        std::string sound  = "Miau";
    public:
        // New private methods, in addition to the ones already in Animal
        void MakeSound()
        {  
            cout << "The cat " << this -> GetName() << " says " << this -> sound << endl;
        }
        // Constructor, specific to our cat
        Cat(std::string name, double height, double weight, std::string sound);
        // Deconstructor. Call automathically the Animal constructor
        Cat(): Animal(){};
        void PrintAtributes();
};

// Constructor. Have the constructor in Animal, initialize all this with :
Cat::Cat(std::string name, double height, double weight, std::string sound) : 
    Animal(name, height, weight){this -> sound = sound;}
    
// Print out method
void Cat::PrintAtributes()
{
    cout << this -> GetName() << " is " << this -> GetHeight() << " cm tall and " << this -> GetWeight() 
        << " kg in weight and says " << this -> sound << endl;
}

// Main method
int main() {

    cout << "Chapter 12. Part I" << endl;

    // Define a new animal fred, who whill have the default values
    Animal Fred;
    Fred.PrintAtributes();

    Fred.SetHeight(165);
    Fred. SetWeight(70);
    Fred.SetName("Fred");
    Fred.PrintAtributes();

    Animal Tom("Tom",170,80);
    Tom.PrintAtributes();

    Cat Syd("Syd", 50, 5, "Miaaaau");
    Syd.PrintAtributes();

    cout << "Number of Animals " << Animal::GetNumOfAnimals() << endl;

    return 0;

} 