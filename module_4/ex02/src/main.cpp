#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    std::cout << "--- Testing Abstract Class Properties ---" << std::endl;

    // Animal test_animal;
    // Animal* meta_ptr = new Animal();

    std::cout << "\n--- Testing Polymorphism ---" << std::endl;
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    std::cout << std::endl;

    std::cout << "The " << dog->getType() << " says: ";
    dog->makeSound();

    std::cout << "The " << cat->getType() << " says: ";
    cat->makeSound();

    std::cout << std::endl;

    delete dog;
    delete cat;

    std::cout << "\n--- Tests finished. ---" << std::endl;
    return 0;
}
