#include <iostream>
#include <string>
#include <vector>
/*
class Cat {
private:
    std::string name;
public:
    Cat(const std::string& n) name(n){}
    const std::string& GetName() const {
        return name;
    }
    std::string Voice() const {
        return "Meow";
    }
};

class Dog {
private:
    std::string name;
public:
    Dog(const std::string& n) name(n){}
    const std::string& GetName() const {
        return name;
    }
    std::string Voice() const {
        return "Woof";
    }
};
*/
/*
enum class AnimalType {
    Cat,
    Dog
};
class Animal {
private:
    AnimalType type;
    std::string name;
public:
    Animal(AnimalType t, const std::string& n):
    type(t),name(n){}
    const std::string& GetName() const {
        return name;
    }
    std::string Voice() const {
        switch(type) {
            case AnimalType::Cat:
                return"Meow";
            case AnimalType::Dog:
                return"Woof";
            default:
                return "unknown creature";
        }
    }
};*/
template<typename T>
void Process(const T& creature) {
    std::cout<<creature.GetName()<<"\n";
}/*
int main() {
    Animal c(AnimalType::Cat, "Tom");
    Animal d(AnimalType::Dog, "Shrek");
} */


class Animal {
protected:
    std::string name;
public:
    Animal(const std::string& n): name(n){}
    const std::string& GetName() const {
        return name;
    }
    virtual std::string Voice() const=0;
    virtual ~Animal(){}

    // virtual std::string Voice() const {
    //     return"Genetic voice";
    // }
};
class Cat: public Animal {
public:
    Cat(const std::string& n): Animal(n){}
    std::string Voice() const override{
        return "Meow";
    }
};
    class Dog: public Animal{
public:
    Dog(const std::string& n): Animal(n){}
    std::string Voice() const override{
        return "Woof";
    }
};
/*class Shepherd: public Dog {
public:
    Shepherd(const std::string& n): Dog(n){}
    std::string Voice() const override final{
    };
};*/
int main() {
    std::vector<Animal*> zoo;
  //  Cat c("Tom");
  //  Dog d("Shrek");
    zoo.push_back(new Cat("Tom"));
    zoo.push_back(new Dog("Shrek"));
    Process(*zoo[0]);
    Process(*zoo[1]);
    for(Animal* animal: zoo) {
        delete animal;
    }
}