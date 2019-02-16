#ifndef RECTANGLE
#define RECTANGLE

#include <iostream>


struct Point2D 
{
	float x;
	float y;
};

struct Dimensions 
{
	float width;
	float height;
};



class Rectangle 
{
public:
	///Constructors
	Rectangle(); //Defaut constructor: point at 1,1 with dimensions of 4,4
	Rectangle(Point2D _point, Dimensions _dimentions); //Parameterized constructor
	Rectangle(const Rectangle& _rectangle); //Copy constructor
	Rectangle(Rectangle&& otherRect); //Move constructor

	~Rectangle();

	Rectangle& operator=(const Rectangle& otherRect);
	Rectangle& operator=(Rectangle&& otherRect); //rvalue


	bool isPointIn(Point2D otherPoint);
	bool isIntersecting(const Rectangle* otherRect);

	Point2D GetPoint();
	Dimensions GetDimensions();

	void SetPoint(Point2D _point);
	void SetDimensions(Dimensions _dimensions);

private:
	Point2D point;
	Dimensions dimensions;
};

std::ostream& operator<<(std::ostream& out, Rectangle* rect);

#endif // !RECTANGLE
