#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

enum class PointType { cartesian, polar };

class Point
{
	public:
		double x,y;
		
		Point(const double x, const double y) : x{x}, y{y} {}

		friend std::ostream& operator<<(std::ostream& os, const Point& point)
		{
			os << "x: " << point.x << " y: " << point.y;
			return os;
		}
};

struct PointFactory
{
	static Point NewCartesian(const double x, const double y)
		{
			return {x, y};
		}

	static Point NewPolar(const double rho, const double theta)
		{
			return { rho*cos(theta), rho*sin(theta) };
		}
};

int main()
{
	// will not work because constructer is private
    //Point p{ 1,2 }; 
	
	auto p = PointFactory::NewPolar(5, M_PI_4); // then here how i am able to access 
	std::cout << p << "\n";	             //the constructer? ;) 

	auto p1 = PointFactory::NewCartesian(3.123, 4.12412);
	std::cout << p1 << "\n";
	 
	getchar();
	return 0;
}

