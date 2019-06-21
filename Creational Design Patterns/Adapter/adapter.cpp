#include <iostream>
#include <memory>

typedef int Coordinate;
typedef int Dimension;  

class Rectangle{
public:
	virtual void draw() = 0;
};

class LegacyRectangle
{
public:
	LegacyRectangle(Coordinate x1, Coordinate y1, Coordinate x2, Coordinate y2):
	_x1{x1}, _y1{y1}, _x2{x2}, _y2{y2} {}

	void oldDraw(){
		std::cout << "Dimensions converted into new Coordinates: x1, y1, x2, y2: " 
		<< _x1 << " " << _y1 << " " << _x2 << " " << _y2 << "\n\n"; 
	}

private:
	Coordinate _x1;
	Coordinate _y1;
	Coordinate _x2;
	Coordinate _y2;
};

class RectangleAdapter : public Rectangle, public LegacyRectangle
{
public:
	RectangleAdapter(Coordinate x, Coordinate y, Dimension w, Dimension h):
	LegacyRectangle(x, y, x+w, y+h){

		std::cout << "\nCoordinates x and y : " << x << " " << y << "\n";
		std::cout << "Dimension w and h : " << w << " " << h << "\n\n";
	}

	void draw(){
		std::cout << "Adapter acting between old and new Rectangle classes\n\n";
		oldDraw();
	}
};

int main()
{
	//Rectangle *r = new RectangleAdapter(120, 200, 60, 40);
	std::unique_ptr<RectangleAdapter> obj(new RectangleAdapter(10, 20, 30, 40));
	obj->draw();
}
