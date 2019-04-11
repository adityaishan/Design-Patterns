// Definition: The Liskov Substitution Principle 
//             is a concept in Object Oriented Programming that states:

//             Functions that use pointers or references to base 
//             classes must be able to use objects of derived classes 
//              without knowing it.

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Rectangle
{
  protected:
    int width, height;
  public:
    Rectangle(int width, int height) : width(width), height(height) {}

      int  getWidth() const { return width; }
      
      virtual void setWidth(const int width) { this->width = width; }
      
      int  getHeight() const { return height; }
      
      virtual void setHeight(const int height) { this->height = height; } 

      int area() const { return width * height; }
};

class Square : public Rectangle
{
  public:
    Square(int size) : Rectangle(size, size) {}

      void setWidth(int width) override {
        this->width = this->height = width;
      }

      void setHeight(int height) override {
        this->height = this->width = height;
      }
};

void process(Rectangle& r)
{
  int w = r.getWidth();
  r.setHeight(10);

  cout << "expected area = " << (w*10)
       << ", got " << r.area() << "\n"; 
}
int main()
{
  Rectangle r(3,4);
  process(r);
    
    Square sq(5);
    process(sq); 
  return 0;
}
