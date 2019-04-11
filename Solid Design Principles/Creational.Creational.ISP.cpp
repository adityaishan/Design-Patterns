// The Interface Segregation Principle (ISP): 
// Clients should not be forced to depend upon interfaces that they do not use.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SomeButtonController
{
    public:
        virtual void onButtonDown(SomeButton* button) = 0;
        virtual void onButtonUp(SomeButton* button)   = 0;
};

class SomeButton 
{
    private:
        SomeButtonController* _controller;
    
    public:
        void setController(SomeButtonController* controller);
};

class SomeWindowController
{
    public:
        virtual void onWindowOpen(SomeWindow* window)  = 0;
        virtual void onWindowClose(SomeWindow* window) = 0;
        virtual void onWindowMoved(SomeWindow* window) = 0;
};

class SomeWindow
{
    private:
        SomeWindowController* _controller;
    
    public:
        void setController(SomeWindowController* controller);
};

class SomeController : public SomeButtonController, public SomeWindowController
{
    private:
        SomeWindow* _window;
        SomeButton* _okButton;
        SomeButton* _cancelButton;
    
    public:
        void onButtonDown(SomeButton* button);
        void onButtonUp(SomeButton* button);
        void onWindowOpen(SomeWindow* window);
        void onWindowClose(SomeWindow* window);
        void onWindowMoved(SomeWindow* window);
};

int main()
{

    return 0;
}
