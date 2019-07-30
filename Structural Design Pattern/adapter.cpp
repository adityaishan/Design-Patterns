#include <iostream>
#include <memory>
using namespace std;

typedef int Coordinate;
typedef int Dimension;

class Rectangle{
public:
    virtual void draw() = 0;
};

class LegacyRectangle{
public:
    LegacyRectangle(Coordinate x1,
                    Coordinate y1,
                    Coordinate x2,
                    Coordinate y2) : _x1(x1), _y1(y1), _x2(x2), _y2(y2) {} 

    void oldDraw() { } //LegacyRectangle draw method.   
private:
    Coordinate _x1;
    Coordinate _y1;
    Coordinate _x2;
    Coordinate _y2;
};

class RectangleAdapter : public Rectangle, private LegacyRectangle {
public:
    RectangleAdapter(Coordinate x,
                     Coordinate y,
                     Dimension w,
                     Dimension h) : LegacyRectangle(x, y, x+w, y+h) {}
    
    virtual void draw(){ 
        cout << "RectangleAdapter: draw.\n";
        oldDraw();
    }
};

int main()
{
    /*Bad practice to use new keyword even in smart pointers*/
    //std::shared_ptr<Rectangle> obj(new RectangleAdapter(1,2,3,4));
    std::shared_ptr<Rectangle> obj = std::make_shared<RectangleAdapter>(1,2,3,4);
    obj->draw();

    return 0;
}
