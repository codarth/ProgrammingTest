#include "Rectangle.h"
#include <iostream>



//Default constructor
Rectangle::Rectangle()
{
	point->x = 1.0f;
	point->y = 1.0f;
	dimensions->width = 4.0f;
	dimensions->height = 4.0f;

	std::cout << "Default Constructor...\n";
}

//Parameterized constructor
Rectangle::Rectangle(Point2D _point, Dimensions _dimentions) :
	point(&_point), dimensions(&_dimentions) 
{
	std::cout << "Parameterized Constructor...\n";
}

//Copy constructor
Rectangle::Rectangle(const Rectangle& _rectangle)
{
	this->point = _rectangle.point;
	this->dimensions = _rectangle.dimensions;
	std::cout << "Copy Constructor...\n";
}

// Move contructor
Rectangle::Rectangle(Rectangle&& otherRect)
{
	this->point = otherRect.point;
	this->dimensions = otherRect.dimensions;
	otherRect.point = nullptr;
	otherRect.dimensions = nullptr;
	std::cout << "Move Constructor...\n";
}

Rectangle::~Rectangle()
{
	delete point;
	point = nullptr;
	delete dimensions;
	dimensions = nullptr;

	std::cout << "Deconstruct...";
}

Rectangle& Rectangle::operator=(const Rectangle& otherRect)
{
	this->point = otherRect.point;
	this->dimensions = otherRect.dimensions;

	std::cout << "Ref Copy...\n";

	return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& otherRect)
{
	this->point = otherRect.point;
	this->dimensions = otherRect.dimensions;
	otherRect.point = nullptr;
	otherRect.dimensions = nullptr;

	std::cout << "rvalue Copy...\n";

	return *this;
}

bool Rectangle::isPointIn(Point2D otherPoint)
{
	if (otherPoint.x >= this->point->x &&
		otherPoint.x <= (this->point->x + this->dimensions->width) &&
		otherPoint.y >= this->point->y &&
		otherPoint.y <= (this->point->y + this->dimensions->height))
	{
		return true;
	}
	return false;
}

bool Rectangle::isIntersecting(const Rectangle* otherRect)
{
	if (this->point->x < (otherRect->point->x + otherRect->dimensions->width) &&
		(this->point->x + this->dimensions->width) > otherRect->point->x &&
		this->point->y < (otherRect->point->y + otherRect->dimensions->height) &&
		(this->point->y + this->dimensions->height) > otherRect->point->y)
	{
		return true;
	}
	return false;
}

Point2D* Rectangle::GetPoint() {	return this->point; }

Dimensions* Rectangle::GetDimensions() { return this->dimensions; }

void Rectangle::SetPoint(Point2D _point)
{
	this->point = &_point;
}

void Rectangle::SetDimensions(Dimensions _dimensions)
{
	this->dimensions = &_dimensions;
}

std::ostream& operator<<(std::ostream & out, Rectangle* rect)
{
	return out << "x: " << rect->GetPoint()->x
		<< " y: " << rect->GetPoint()->y
		<< " width: " << rect->GetDimensions()->width
		<< " height: " << rect->GetDimensions()->height;
}