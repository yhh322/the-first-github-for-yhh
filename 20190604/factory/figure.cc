 ///
 /// @file    figure.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-05-24 11:37:16
 ///
 
#include <math.h>
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr; 

//面向对象设计原则
//    > 开闭原则 : 对修改关闭，对扩展开放

class Figure
{
public:
	virtual
	void display() const = 0;

	virtual 
	double area() const = 0;

	virtual 
	~Figure() {	}
};

class Rectangle
: public Figure
{
public:
	Rectangle(size_t length, size_t width)
	: _length(length)
	, _width(width)
	{}

	void display() const 
	{	cout << "rectangle";	}

	double area() const
	{	return _length * _width;	}

	~Rectangle() {	cout << "~Rectangle()" << endl;	}

private:
	size_t _length;
	size_t _width;
};

class Circle
: public Figure
{
public:
	Circle(double radius)
	: _radius(radius)
	{}

	void display() const
	{	cout << "circle";	}
	
	double area() const
	{	return 3.14159 * _radius * _radius;	}

	~Circle() {	cout << "~Circle()" << endl;	}

private:
	double _radius;
};
 
class Triangle
: public Figure
{
public:
	Triangle(size_t a, size_t b, size_t c)
	: _a(a)
	, _b(b)
	, _c(c)
	{}

	void display() const
	{	cout << "triangle";	}

	double area() const
	{
		size_t p = (_a + _b + _c) / 2;
		return sqrt(p * (p - _a) * (p - _b) * (p - _c));
	}

	~Triangle() {	cout << "~Triangle()" << endl;	}	

private:
	size_t _a;
	size_t _b;
	size_t _c;
};

void display(Figure * fig)
{
	fig->display();
	cout << " 's area is " << fig->area() << endl;
}

//静态工厂方法
class Factory
{
public:
	static Figure * createRectangle()
	{
		//load xml
		//....
		return new Rectangle(3, 4);
	}

	static Figure * createTriangle()
	{
		//load xml
		//....
		return new Triangle(3, 4, 5); 
	}

	static Figure * createCircle()
	{
		//load xml
		//....
		return new Circle(10);
	}

	static Figure * createCube()
	{
		//load xml
		//....
	}
};


int main(void)
{
	unique_ptr<Figure> rectangle(Factory::createRectangle());
	unique_ptr<Figure> triangle(Factory::createTriangle());
	unique_ptr<Figure> circle(Factory::createCircle());

	display(rectangle.get());
	display(triangle.get());
	display(circle.get());
 
	return 0;
}
