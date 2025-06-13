#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

int main() {
    std::cout << "--- 1. Polymorphism and Virtual Functions Test ---\n"
              << std::endl;
    {
        const Animal *meta = new Animal();
        const Animal *j = new Dog();
        const Animal *i = new Cat();

        std::cout << "\nDog's type: " << j->getType() << std::endl;
        std::cout << "Cat's type: " << i->getType() << std::endl;

        std::cout << "\nCalling makeSound():" << std::endl;
        i->makeSound();    // Should call Cat's makeSound
        j->makeSound();    // Should call Dog's makeSound
        meta->makeSound(); // Should call Animal's makeSound

        std::cout << "\n--- Destruction in order: Cat -> Dog -> Animal ---\n"
                  << std::endl;
        delete i;
        delete j;
        delete meta;
    }

    std::cout
        << "\n--- 2. Testing the 'Wrong' Implementation (without virtual) ---\n"
        << std::endl;
    {
        const WrongAnimal *wrong = new WrongCat();

        std::cout << "\nWrongCat's type: " << wrong->getType() << std::endl;

        std::cout << "\nCalling makeSound() on WrongAnimal pointer:"
                  << std::endl;
        wrong->makeSound();

        std::cout
            << "\n--- Proving WrongCat's function works on its own type ---\n"
            << std::endl;
        WrongCat realWrongCat;
        realWrongCat.makeSound();

        std::cout << "\n--- Destruction ---\n" << std::endl;
        delete wrong;
    }

    std::cout << "\n--- 4. Copy and Assignment Test ---\n" << std::endl;
    {
        Dog dog1;
        Dog dog2;

        std::cout << "\n--- Assigning dog1 to dog2 ---\n" << std::endl;
        dog2 = dog1;

        std::cout << "\n--- Creating dog3 from dog1 ---\n" << std::endl;
        Dog dog3(dog1);

        std::cout << "\n--- Destruction ---\n" << std::endl;
    }
    return 0;
}
