// Before Prototype Pattern
#include <iostream>
#include <memory>
#include <vector>
#include <string>

class Stooge
{
   public:
	 virtual void slap_stick() = 0;
};

class Larry: public Stooge
{
  public:
      void slap_stick()
      {
          std::cout << "Larrt: poke eyes\n";
      }
};

class Moe: public Stooge
{
  public:
      void slap_stick()
      {
          std::cout << "Moe: slap head\n";
      }
};

class Curly: public Stooge
{
  public:
      void slap_stick()
      {
          std::cout << "Curly: suffers\n";
      }
};

int main()
{
	
	std::vector<std::unique_ptr<Stooge>> roles;

	int choice;

	while(true)
	{
		std::cout << "Larry(1) Moe(2) Curly(3) Exit(0): \n";
		std::cin>>choice;

		if(!choice) break;
		else if(choice == 1) roles.push_back(std::make_unique<Larry>());
	  else if(choice == 2) roles.push_back(std::make_unique<Moe>());
	  else if(choice == 3) roles.push_back(std::make_unique<Curly>());
	}

	for(size_t i = 0; i != roles.size(); ++i)
		roles[i]->slap_stick();
    
	return 0;
}
