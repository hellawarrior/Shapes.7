#ifndef pShapes_h
#define pShapes_h

// c++ libraries
#include <iostream>
#include <vector>
using namespace std;

struct Shape
{
	virtual void output(ostream&) const = 0;
	friend ostream& operator<<(ostream&, const Shape*);
	virtual ~Shape() {};
};

class Square: public Shape
{
protected:
	const double side; // constant data member
public:
	void output(ostream&) const; //member function
	Square (const vector<string>&); // constructor functions
	Square& operator=(const Square&); // parameter is a constant reference
};
namespace comsc
{
	class Rectangle : public Shape
	{
	protected:
		const double length;
		const double width;
	public:
		void output(ostream&) const; //member function
		Rectangle(const vector<string>&); // constructor functions
		Rectangle& operator=(const Rectangle&); // parameter is a constant reference
	};
}
class Circle: public Shape
{
protected:
	const double radius;
public:
	void output(ostream&) const; //member function
	Circle(const vector<string>&); // constructor functions
	Circle& operator=(const Circle&); // parameter is a constant reference
};
class Triangle: public Shape
{
protected:
	const double side;
public:
	void output(ostream&) const; //member function
	Triangle(const vector<string>&); // constructor functions
	Triangle& operator=(const Triangle&); // parameter is a constant reference
};
class Cube: public Square
{
public:
	void output(ostream&) const; //member function
	Cube(const vector<string>&); // constructor functions
	Cube& operator=(const Cube&); // parameter is a constant reference
};
class Box: public comsc::Rectangle
{
	const double height;
public:
	void output(ostream&) const; //member function
	Box(const vector<string>&); // constructor functions
	Box& operator=(const Box&); // parameter is a constant reference
};
class Cylinder: public Circle
{
	const double height;
public:
	void output(ostream&) const; //member function
	Cylinder(const vector<string>&); // constructor functions
	Cylinder& operator=(const Cylinder&); // parameter is a constant reference
};
class Prism: public Triangle
{
	const double height;
public:
	void output(ostream&) const; //member function
	Prism(const vector<string>&); // constructor functions
	Prism& operator=(const Prism&); // parameter is a constant reference
};
// prototypes
ostream& roundingTwo(ostream&); // a manipulator to turn on floating point rounding
ostream& roundingOff(ostream&); // a manipulator to turn off floating point rounding
#endif
