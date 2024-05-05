/// \file CIsoTriangle.cpp
///	\brief class IsoTriangle: implementation of the functions
///
///	Details.
///

#include <iostream>
#include <cmath>
#include "CIsoTriangle.h"

/// @brief default constructor 
IsoTriangle::IsoTriangle() 
{
	cout << "IsoTriangle - constructor - default" << endl;

	Init();
}

/// @brief constructor 
/// @param b base of the isosceles triangle
/// @param h height of the isosceles triangle
IsoTriangle::IsoTriangle(float b, float h)
{
	Init();

	cout << "IsoTriangle - constructor" << endl;

	if (b <= 0. || h <= 0.) 
	{
		WarningMessage("constructor: base and height should be > 0"); 
		SetDim(0,0);
	}
	else
		SetDim(b,h);
}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
IsoTriangle::IsoTriangle(const IsoTriangle &o) 
{ 
	cout << "IsoTriangle - copy constructor" << endl;

	Init(o);
}

/// @brief destructor 
IsoTriangle::~IsoTriangle() 
{
	cout << "IsoTriangle - destructor" << endl;
	Reset();
}


/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
IsoTriangle& IsoTriangle::operator=(const IsoTriangle &o)
{ 
	cout << "IsoTriangle - operator =" << endl;

	Init(o);
	
	return *this;
}

/// @brief overload of operator == 
/// @param t reference to the object on the right side of the operator 
/// @return true if the two objects have the same base and the same height  
bool IsoTriangle::operator==(const IsoTriangle &t) 
{ 
	if (t.base == base && t.height == height)
		return true;
		
	return false;
}


/// @brief default initialization of the object
void IsoTriangle::Init() 
{
	SetDim(0,0);	
}

/// @brief initialization of the object as a copy of an object 
/// @param t reference to the object that should be copied 
void IsoTriangle::Init(const IsoTriangle &t) 
{
	Init();
	SetDim(t.base, t.height);
}

/// @brief total reset of the object  
void IsoTriangle::Reset() 
{	
	SetDim(0,0);	
}


/// @brief set base of the object
/// @param b base 
void IsoTriangle::SetBase(float b) 
{
	if (b < 0.) {
		WarningMessage("SetBase: base should be > 0");
		return;
	}

	SetDim(b,height);
}

/// @brief set height of the object
/// @param h height 
void IsoTriangle::SetHeight(float h) 
{
	if (h < 0.) {
		WarningMessage("SetHeight: height should be > 0");
		return;
	}

	SetDim(base,h);
}

void IsoTriangle::SetSide(float b, float h)
{	
	side = sqrt((b * b + h * h) / 4);
	return;
}

/// @brief set base and height of the object
/// @param b base
/// @param h height
void IsoTriangle::SetDim(float b, float h) 
{
	base = b;
	height = h;
	SetSide(b, h);
	Triangle::SetSides(b, side, side);
	
	return;
}

/// @brief get base and length of the object
/// @param b base
/// @param h height
void IsoTriangle::GetDim(float &b, float &h, float &s)
{
	b = base;
	h = height;
	s = side;
	
	return;
}

/// @brief get base of the object
/// @return base
float IsoTriangle::GetBase()
{
	return base;
}

/// @brief get height of the object
/// @return height
float IsoTriangle::GetHeight() 
{
	return height;
}

float IsoTriangle::GetSide() 
{
	return side;
}


/// @brief computes the angles of the object
/// @return the angles 
void IsoTriangle::GetAngles(float h, float s)
{
	double bAngles = asin(h/s);
	cout << endl;
	cout << "Base angles = " << bAngles << endl;
	double tAngle = 2*acos(h/s);
	cout << endl;
	cout << "Top angle = " << tAngle << endl;
	cout << endl;
	
	return;
}

/// @brief computes the area of the object
/// @return the area 
float IsoTriangle::GetArea() 
{	
	return (base*height)/2;
}


/// @brief write an error message 
/// @param string message to be printed
void IsoTriangle::ErrorMessage(const char *string) 
{	
	cout << endl << "ERROR -- IsoTriangle --";
	cout << string << endl;
}

/// @brief write a warning message 
/// @param string message to be printed
void IsoTriangle::WarningMessage(const char *string) 
{	
	cout << endl << "WARNING -- IsoTriangle --";
	cout << string << endl;
}


/// @brief for debugging: all about the object
void IsoTriangle::Dump() 
{
	cout << endl;
	cout << "---IsoTriangle---" << endl; 
	cout << endl;
	
	cout << "Base = " << base << endl;
	cout << "Height = " << height << endl;
	cout << "Oblique side = " << side << endl;
	cout << "Area = " << GetArea() << endl;
	GetAngles(height, side);

	Triangle::Dump();
	
	cout << endl;
}






