#include <iostream>
#define LINUX

using namespace std;

//Abstract base product. It defines a template
//common to all products. Client will interact
//with Widget template.
class Widget
{
	public:
		virtual void draw() = 0;
};

//Product 1
class LinuxButton : public Widget
{
	public:
		void draw(){
			cout << "LinuxButton\n";
		}
};

class LinuxMenu : public Widget
{
	public:
		void draw(){
			cout << "LinuxMenu\n";
		}
};

//Product 2
class WindowsButton : public Widget
{
	public:
		void draw(){
			cout << "WindowsButton\n";
		}
};

class WindowsMenu : public Widget
{
	public:
		void draw(){
			cout << "WindowsMenu\n";
		}
};

// Abstract Factory defines methods
// to create all objects of all related products
class Factory
{
	public:
		virtual Widget* createButton() = 0;
		virtual Widget* createMenu()   = 0;
};

// Create product of all kind and
// return them as abstract
class LinuxFactory : public Factory
{
	public:
		Widget* createButton(){
			return new LinuxButton;
		}

		Widget* createMenu(){
			return new LinuxMenu;
		}
};

class WindowsFactory : public Factory
{
	public:
		Widget* createButton(){
			return new WindowsButton;
		}

		Widget* createMenu(){
			return new WindowsMenu;
		}
};

class Client
{
	private:
		Factory* factory = nullptr;

	public:
		Client(Factory *factory_obj) : factory(factory_obj) {}

	void draw(){

		Widget* w = factory->createButton();
		w->draw();

		display_window_one();
		display_window_two();
	}

	void display_window_one()
	{
		Widget* w[] = {
			factory->createButton(),
			factory->createMenu()
		};

		w[0]->draw();
		w[1]->draw();
	}

	void display_window_two()
	{
		Widget* w[] = {
			factory->createMenu(),
			factory->createButton()
		};

		w[0]->draw();
		w[1]->draw();
	}
};


// no if else is needed only
// once create a factory.
int main()
{
	Factory* factory = nullptr;
	#ifdef LINUX
		factory = new LinuxFactory();
	#else // Windows
		factory = new WindowsFactory();
	#endif

		Client* c = new Client(factory);
		c->draw();

	return 0;
}
