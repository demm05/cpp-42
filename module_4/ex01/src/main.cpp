#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

void print_title(const std::string &title) {
    std::cout << "\n\n--- " << title << " ---\n" << std::endl;
}

int main() {
    print_title("Basic leak test");
    {
        const Animal *j = new Dog();
        const Animal *i = new Cat();

        delete j;
        delete i;
    }
    print_title("Array & Polymorphic Deletion Test");
    {
        const int num_animals = 4;
        Animal *animals[num_animals];

        for (int i = 0; i < num_animals / 2; ++i) {
            animals[i] = new Dog();
        }
        for (int i = num_animals / 2; i < num_animals; ++i) {
            animals[i] = new Cat();
        }

        for (int i = 0; i < num_animals; ++i) {
            delete animals[i];
        }
    }
    print_title("Deep Copy & Assignment Test");
    {
        std::cout << "\n*Testing Dog Copy*" << std::endl;
        Dog dog_original;
        dog_original.setIdea(0, "I'm original dog");
        dog_original.setIdea(1, "I'm changed dog");

        Dog dog_copy = dog_original; // Test Copy Constructor
        dog_original.setIdea(1, "I'm not changed dog");

        std::cout << "Original Dog's idea: " << std::endl;
        dog_original.printIdeas();
        std::cout << "Copied Dog's idea: " << std::endl;
        dog_copy.printIdeas();
    }
    {
        std::cout << "\n*Testing Cat Assignment*" << std::endl;
        Cat cat_original;
        cat_original.setIdea(0, "I'm the original Cat");

        Cat cat_assigned;
        cat_assigned = cat_original; // Test Assignment Operator
        cat_original.setIdea(0, "I'm changed Cat");

        std::cout << "Original Cat's idea: " << std::endl;
        cat_original.printIdeas();
        std::cout << "Copied Cat's idea: " << std::endl;
        cat_assigned.printIdeas();
    }
    std::cout << "\n--- End of tests. Check for leaks. ---" << std::endl;
    return 0;
}
