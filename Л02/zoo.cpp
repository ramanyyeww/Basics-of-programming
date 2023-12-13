#include <iostream>
#include <string>
#include <vector>

class Animal {
public:
    virtual void feed() = 0;
    virtual void sleep() = 0;
    virtual void pet() = 0;
    virtual void makeSound() = 0;
};

class Elephant : public Animal {
public:
   
    void feed() override {
        std::cout << "The elephant is being fed." << std::endl;
    }
    void sleep() override {
        std::cout << "The elephant is sleeping." << std::endl;
    }
    void pet() override {
        std::cout << "The elephant is being petted." << std::endl;
    }
    void makeSound() override {
        std::cout << "The elephant makes a trumpet sound." << std::endl;
    }
};

class Giraffe : public Animal {
public:
    void feed() override {
        std::cout << "The giraffe is being fed." << std::endl;
    }
    void sleep() override {
        std::cout << "The giraffe is sleeping." << std::endl;
    }
    void pet() override {
        std::cout << "The giraffe is being petted." << std::endl;
    }
    void makeSound() override {
        std::cout << "The giraffe makes a gentle humming sound." << std::endl;
    }
};

class Dog : public Animal {
public:
    void feed() override {
        std::cout << "The dog is being fed." << std::endl;
    }
    void sleep() override {
        std::cout << "The dog is sleeping." << std::endl;
    }
    void pet() override {
        std::cout << "The dog is being petted." << std::endl;
    }
    void makeSound() override {
        std::cout << "The dog barks happily." << std::endl;
    }
};

class Zoo {
private:
    std::vector<Animal*> animals;

public:
    void addAnimal(Animal* newAnimal) {
        animals.push_back(newAnimal);
    }

    void feedAllAnimals() {
        for (auto animal : animals) {
            animal->feed();
        }
    }

    void makeAllAnimalsSleep() {
        for (auto animal : animals) {
            animal->sleep();
        }
    }

    void petAllAnimals() {
        for (auto animal : animals) {
            animal->pet();
        }
    }

    void makeAllAnimalsMakeSound() {
        for (auto animal : animals) {
            animal->makeSound();
        }
    }
};

int main() {
    Elephant elephant;
    Giraffe giraffe;
    Dog dog;

    Zoo zoo;
    zoo.addAnimal(&elephant);
    zoo.addAnimal(&giraffe);
    zoo.addAnimal(&dog);

    zoo.feedAllAnimals();
    zoo.makeAllAnimalsMakeSound();
    zoo.petAllAnimals();
    zoo.makeAllAnimalsSleep();

    return 0;
}
