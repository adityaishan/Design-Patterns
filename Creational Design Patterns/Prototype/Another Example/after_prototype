//After Prototype Pattern

/*
A clone() method has been added to the Stooge hierarchy. 
Each derived class implements that method by returning an instance of itself.
A Factory class has been introduced that maintains a suite of "breeder" 
objects (aka prototypes), and knows how to delegate to the correct prototype.
*/

#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Stooge{
public:
    virtual std::unique_ptr<Stooge> clone() = 0;
    virtual void slap_stick() = 0;
};

class Factory{
public:
    static std::unique_ptr<Stooge> make_stooge(int choice);
private:
    static std::unique_ptr<Stooge> s_prototypes[4];
};

class Larry: public Stooge{
public:
    std::unique_ptr<Stooge> clone(){
     return std::make_unique<Larry>();
    }
    
    void slap_stick(){
        std::cout << "Larry: poke eyes\n";
    }
};

class Moe: public Stooge{
public:
    std::unique_ptr<Stooge> clone(){
        return std::make_unique<Moe>();
    }

    void slap_stick(){
        std::cout << "Moe: slaps head\n";
    }
};

class Curly: public Stooge{
public:
    std::unique_ptr<Stooge> clone(){
        return std::make_unique<Curly>();
    }

    void slap_stick(){
        std::cout << "Curly: suffers\n";
    }
};

std::unique_ptr<Stooge> Factory::s_prototypes[] = {
    0,
    std::make_unique<Larry>(),
    std::make_unique<Moe>(),
    std::make_unique<Curly>()
};

std::unique_ptr<Stooge> Factory::make_stooge(int choice){
    return s_prototypes[choice]->clone();
}

int main()
{
    std::vector<std::unique_ptr<Stooge>> roles;
    int choice;

    while(true){
        std::cout << "Larry(1) Moe(2) Curly(3) Exit(0): \n";
        std::cin >> choice;

        if(!choice) break;
        roles.push_back(Factory::make_stooge(choice));
    }

    for(size_t i = 0; i != roles.size(); ++i){
        roles[i]->slap_stick();
    }

	return 0;
}
