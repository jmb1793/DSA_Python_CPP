#include <iostream>
// Abstract Data Types, Templates, and Interfacing
// Practicing Classes with Animals

using namespace std;

class Animal
{
protected:
    string m_name;

public:
    // Constructor for Animal Class
    Animal(string name) : m_name(name){}

    // Interface for derived classes
    virtual string MakeSound() = 0;

    // Method for accessing m_name property
    string GetName()
    {
        return m_name;
    }
};

// New class Dog derived from Animal
class Dog : public Animal
{
public:
    // Forward the constructor arguments
    Dog(string name) : Animal(name) {}

    // Copy assignment operator overloading
    void operator = (const Dog &D)
    {
         m_name = D.m_name;
    }

    // here we implement the interface
    string MakeSound() override
    {
        return "bark-bark!";
    }
};

// New Class Cat derived from Animal
class Cat : public Animal
{
public:
    // Forward the constructor arguments
    Cat(string name) : Animal(name) {}

    // Copy assignment operator overloading
    void operator = (const Cat &C)
    {
         m_name = C.m_name;
    }

    // here we implement the interface
    string MakeSound() override
    {
        return "meow-meow!";
    }

};

// Define a function template with symbol T
// Function is now generic and can utilize different objects/classes
// The passed down generic type needs to have the methods within the function 
template<typename T>
void GetNameAndMakeSound(T& theAnimal)
{
    cout << theAnimal.GetName() << " goes ";
    cout << theAnimal.MakeSound() << endl;
}

// Define a class template with symbol T
// Class is now generic and can utilize different objects/classes
// The passed down generic type needs to have the methods within the template
template <typename T>
class AnimalTemplate
{
private:
    T m_animal;

public:
    AnimalTemplate(T animal) : m_animal(animal) {}

    void GetNameAndMakeSound()
    {
        cout << m_animal.GetName() << " goes ";
        cout << m_animal.MakeSound() << endl;
    }
};

int main()
{
    Dog dog = Dog("Pug");
    AnimalTemplate<Dog> dogTemplate(dog);
    dogTemplate.GetNameAndMakeSound();

    Cat cat = Cat("Siberian");
    AnimalTemplate<Cat> catTemplate(cat);
    catTemplate.GetNameAndMakeSound();

    return 0;
}