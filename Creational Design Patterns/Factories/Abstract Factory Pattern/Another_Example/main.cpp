#include <iostream>
#define LINUX

using namespace std;

//Abtract base product template
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

//here Client directly uses products class
//which check the product type before its use

//Problem : nested if-else statement can be solved using abstract factory pattern
class Client
{
	private:
		Widget* w = nullptr;

	public:
		void draw(){
			#ifdef LINUX
				w = new LinuxButton();

			#else
				w = new WindowsButton();
			#endif

			w->draw();
			display_window_one();
			display_window_two();
		}

		void display_window_one(){
			#ifdef LINUX
				Widget* w[] = {
					new LinuxButton,
					new LinuxMenu
				};
			#else //Windows
				Widget* w[] = {
					new WindowsButton,
					new WindowsMenu
				};
			#endif
				w[0]->draw();
				w[1]->draw();
		}

		void display_window_two(){
			#ifdef LINUX
				Widget* w[] = {
					new LinuxMenu,
					new LinuxButton
				};
			#else //Windows
				Widget* w[] = {
					new WindowsMenu,
					new WindowsButton
				};
			#endif
				w[0]->draw();
				w[1]->draw();
		}
};

int main()
{
	Client *obj = new Client();
	obj->draw();

	return 0;
}
