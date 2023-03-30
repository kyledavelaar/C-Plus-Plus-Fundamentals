#include <iostream>

class Person
{
    public:
        int Age = 20;

};

void ChangePlayerAgeCopy(Person Player)
{
    Player.Age = 55; // PlayerCopy will be unchanged
}

void ChangePlayerAgePointer(Person* Player)
{
    Player->Age = 55;
}

void ChangePlayerAgeReference(Person& Player)
{
    Player.Age = 55;
}


int main()
{
    Person PlayerCopy;
    Person* PlayerPointer = new Person();
    Person PlayerReference;

    std::cout << "PlayerCopy Before " << PlayerCopy.Age << std::endl; // 20
    ChangePlayerAgeCopy(PlayerCopy);
    std::cout << "PlayerCopy After " << PlayerCopy.Age << std::endl << std::endl; // 20

    std::cout << "PlayerPointer Before " << PlayerPointer->Age << std::endl; // 20
    ChangePlayerAgePointer(PlayerPointer);
    std::cout << "PlayerPointer After " << PlayerPointer->Age << std::endl << std::endl; // 55

    std::cout << "PlayerReference Before " << PlayerReference.Age << std::endl;  // 20
    ChangePlayerAgeReference(PlayerReference);
    std::cout << "PlayerReference After " << PlayerReference.Age << std::endl << std::endl; // 55
}