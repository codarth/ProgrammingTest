#include <iostream>
#include "Rectangle.h"

int main(int argv, char** argc) {
	///Defaut constructor: point at 1,1 with dimensions of 4,4
	Rectangle r1; 

	///Copy constructor
	Rectangle r2(r1);

	///Parameterized constructor
	Rectangle r3({ 2.0f, 3.0f }, { 3.0f, 4.0f }); // the two {} are prvalues

	Rectangle r4;
	{	
		Rectangle r5;
		r5.SetPoint({ 1.0f,2.0f });
		r5.SetDimensions({ 2.0f,3.0f });
		r4 = std::move(r5); // r5 is xvalue, rvalue copy
	}
	///prvalue move after construction
	Rectangle r6 = Rectangle();

	r4 = r3; // reference copy

	std::cout << std::endl << std::endl;

	std::cout << "Rectangle 1: " << &r1 << std::endl;
	std::cout << "Rectangle 2: " << &r2 << std::endl;
	std::cout << "Rectangle 3: " << &r3 << std::endl;
	std::cout << "Rectangle 4: " << &r4 << std::endl;

	std::cout << std::endl << std::endl;

	if (r1.isPointIn({ 2.0f, 2.0f })) // point should be in rectangle
	{
		std::cout << "Point 2,2 IS in the r1.\n";
	}
	else
	{
		std::cout << "Point 2,2 is NOT in the r1.\n";
	}
	if (r1.isPointIn({ 6.0f, 1.0f })) // point should not be in rectangle
	{
		std::cout << "Point 6,1 IS in the r1.\n";
	}
	else
	{
		std::cout << "Point 6,1 is NOT in the r1.\n";
	}

	if (r2.isIntersecting(&r3)) // they do intersect
	{
		std::cout << "r3 IS intersecting r2.\n";
	}
	else
	{
		std::cout << "r3 is NOT intersecting r2.\n";
	}

	r2.SetPoint({ 6.0f, 1.0f }); // Move r2
	std::cout << "After moving r2: " << &r2 << std::endl;

	if (r2.isIntersecting(&r3)) // they no longer intersect
	{
		std::cout << "r3 IS intersecting r2.\n";
	}
	else
	{
		std::cout << "r3 is NOT intersecting r2.\n";
	}

	r1.~Rectangle();

	r2.~Rectangle();

	r3.~Rectangle();

	r4.~Rectangle();

	r6.~Rectangle();


	return 0;
}