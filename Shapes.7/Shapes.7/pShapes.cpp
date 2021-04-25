#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

// c libraries
#include <cmath> // sqrt
#include <cstdlib>

#include "pShapes.h"

const double PI = 3.14159;

// a manipulator to turn on floating point rounding
ostream& roundingTwo(ostream& out)
{
	out.setf(ios::fixed);
	out.precision(2); // 2 decimal digits
	return out;
}
// a manipulator to turn off floating point rounding
ostream& roundingOff(ostream& out)
{
	out.unsetf(ios::fixed);
	out.precision(6); // the C++ default
	return out;
}

//member functions of shapes
void Square::output(ostream& out) const
{
	out << "SQUARE side=" << side;
	out << roundingTwo << " area=" << side * side << " perimeter=" << side * 4 << roundingOff << endl;
}
Square::Square (const vector<string>& tokens)
: side (tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) // this is the initializer list
{
}
Square& Square::operator=(const Square& copyThis)
{
	Square& host = *this; // a reference to the host object
	if (this != &copyThis) // skips self-copy if host and parameter are same object
	{
		const_cast<double&>(host.side) = copyThis.side;
	}
	return host; // returns a "self-reference"
}
void comsc::Rectangle::output(ostream& out) const
{
	out << "RECTANGLE length=" << length << " width=" << width;
	out << roundingTwo << " area=" << length * width << " perimeter=" << (length + width) * 2 << roundingOff << endl;
}
comsc::Rectangle::Rectangle(const vector<string>& tokens)
: length (tokens.size() > 1 ? atof(tokens[1].c_str()) : 0), // this is the initializer list
width (tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) // this is the initializer list
{
}
comsc::Rectangle& comsc::Rectangle::operator=(const Rectangle& copyThis)
{
	Rectangle& host = *this; // a reference to the host object
	if (this != &copyThis) // skips self-copy if host and parameter are same object
	{
		const_cast<double&>(host.length) = copyThis.length;
		const_cast<double&>(host.width) = copyThis.width;
	}
	return host; // returns a "self-reference"
}
void Circle::output(ostream& out) const
{
	out << "CIRCLE radius=" << radius;
	out << roundingTwo << " area=" << radius * radius * PI << " perimeter=" << 2 * radius * PI << roundingOff << endl;
}
Circle::Circle (const vector<string>& tokens)
: radius (tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) // this is the initializer list
{
}
Circle& Circle::operator=(const Circle& copyThis)
{
	Circle& host = *this; // a reference to the host object
	if (this != &copyThis) // skips self-copy if host and parameter are same object
	{
		const_cast<double&>(host.radius) = copyThis.radius;
	}
	return host; // returns a "self-reference"
}
void Triangle::output(ostream& out) const
{
	out << "TRIANGLE side=" << side;
	out << roundingTwo << " area=" << sqrt(3.0) * side * side / 4 << " perimeter=" << 3 * side << roundingOff << endl;
}
Triangle::Triangle (const vector<string>& tokens)
: side (tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) // this is the initializer list
{
}
Triangle& Triangle::operator=(const Triangle& copyThis)
{
	Triangle& host = *this; // a reference to the host object
	if (this != &copyThis) // skips self-copy if host and parameter are same object
	{
		const_cast<double&>(host.side) = copyThis.side;
	}
	return host; // returns a "self-reference"
}
void Cube::output(ostream& out) const
{
	out << "CUBE side=" << side;
	out << roundingTwo << " surface area=" << side * side * 6 << " volume=" << side * side * side << roundingOff << endl;
}
Cube::Cube (const vector<string>& tokens)
: Square(tokens) // this is the initializer list
{
}
Cube& Cube::operator=(const Cube& copyThis)
{
	Cube& host = *this; // a reference to the host object
	if (this != &copyThis) // skips self-copy if host and parameter are same object
	{
		const_cast<double&>(host.side) = copyThis.side;
	}
	return host; // returns a "self-reference"
}
void Box::output(ostream& out) const
{
	out << "BOX length=" << length << " width=" << width << " height=" << height;
	out << roundingTwo << " surface area=" << (length * width + length * height + width * height) * 2 << " volume=" <<  length * width * height << roundingOff << endl;
}
Box::Box (const vector<string>& tokens)
: comsc::Rectangle(tokens), // this is the initializer list
height (tokens.size() > 3 ? atof(tokens[3].c_str()) : 0) // this is the initializer list
{
}
Box& Box::operator=(const Box& copyThis)
{
	Box& host = *this; // a reference to the host object
	if (this != &copyThis) // skips self-copy if host and parameter are same object
	{
		const_cast<double&>(host.length) = copyThis.length;
		const_cast<double&>(host.width) = copyThis.width;
		const_cast<double&>(host.height) = copyThis.height;
	}
	return host; // returns a "self-reference"
}
void Cylinder::output(ostream& out) const
{
	out << "CYLINDER radius=" << radius << " height=" << height;
	out << roundingTwo << " surface area=" << 2 * radius * radius * PI + 2 * radius * PI * height << " volume=" << radius * radius * PI * height << roundingOff << endl;
}
Cylinder::Cylinder(const vector<string>& tokens)
: Circle(tokens), // this is the initializer list
height (tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) // this is the initializer list
{
}
Cylinder& Cylinder::operator=(const Cylinder& copyThis)
{
	Cylinder& host = *this; // a reference to the host object
	if (this != &copyThis) // skips self-copy if host and parameter are same object
	{
		const_cast<double&>(host.radius) = copyThis.radius;
		const_cast<double&>(host.height) = copyThis.height;
	}
	return host; // returns a "self-reference"
}
void Prism::output(ostream& out) const
{
	out << "PRISM side=" << side << " height=" << height;
	out << roundingTwo << " surface area=" << sqrt(3.0) * side * side / 4 * 2 + 3 * side * height << " volume=" << sqrt(3) * side * height << roundingOff << endl;
}
Prism::Prism(const vector<string>& tokens)
: Triangle(tokens), // this is the initializer list
height (tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) // this is the initializer list
{
}
Prism& Prism::operator=(const Prism& copyThis)
{
	Prism& host = *this; // a reference to the host object
	if (this != &copyThis) // skips self-copy if host and parameter are same object
	{
		const_cast<double&>(host.side) = copyThis.side;
		const_cast<double&>(host.height) = copyThis.height;
	}
	return host; // returns a "self-reference"

}

ostream& operator<<(ostream& out, const Shape* shape)
{
	shape->output(out);
	return out;
}
