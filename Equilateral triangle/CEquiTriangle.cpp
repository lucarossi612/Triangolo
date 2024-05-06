/// \file CEquiTriangle.cpp
///	\brief class EquiTriangle: implementation of the functions
///
///	Details.
///

#include <iostream>
#include "CEquiTriangle.h"

/// @brief default constructor 
EquiTriangle::EquiTriangle()
{
	cout << "EquiTriangle - constructor - default" << endl;

	Init();
}

/// @brief constructor 
/// @param b base of the isosceles triangle
/// @param h height of the isosceles triangle
EquiTriangle::EquiTriangle(float s)
{
	Init();

	cout << "EquiTriangle - constructor" << endl;

	if (s <= 0.)
	{
		WarningMessage("constructor: side should be > 0");
		SetDim(0);
	}
	else
		SetDim(s);
}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
EquiTriangle::EquiTriangle(const EquiTriangle& o)
{
	cout << "EquiTriangle - copy constructor" << endl;

	Init(o);
}

/// @brief destructor 
EquiTriangle::~EquiTriangle()
{
	cout << "EquiTriangle - destructor" << endl;
	Reset();
}


/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
EquiTriangle& EquiTriangle::operator=(const EquiTriangle& o)
{
	cout << "EquiTriangle - operator =" << endl;

	Init(o);

	return *this;
}

/// @brief overload of operator == 
/// @param t reference to the object on the right side of the operator 
/// @return true if the two objects have the same base and the same height  
bool EquiTriangle::operator==(const EquiTriangle& t)
{
	if (t.side == side)
		return true;

	return false;
}


/// @brief default initialization of the object
void EquiTriangle::Init()
{
	SetDim(0);
}

/// @brief initialization of the object as a copy of an object 
/// @param t reference to the object that should be copied 
void EquiTriangle::Init(const EquiTriangle& t)
{
	Init();
	SetDim(t.side);
}

/// @brief total reset of the object  
void EquiTriangle::Reset()
{
	SetDim(0);
}

void EquiTriangle::SetSide(float s)
{
	if (s < 0.) 
	{
		WarningMessage("SetSide: side should be > 0");
		return;
	}

	SetDim(s);
}

/// @brief set base and height of the object
/// @param b base
/// @param h height
void EquiTriangle::SetDim(float s)
{
	side = s;
	Triangle::SetSides(side, side, side);

	return;
}

/// @brief get side of the object
/// @param s side
void EquiTriangle::GetDim(float& s)
{
	s = side;

	return;
}

/// @brief get side of the object
/// @return side
float EquiTriangle::GetSide()
{
	return side;
}

/// @brief get height of the object
/// @return height
float EquiTriangle::GetHeight(float s)
{
	return sin(side);
}


/// @brief write an error message 
/// @param string message to be printed
void EquiTriangle::ErrorMessage(const char* string)
{
	cout << endl << "ERROR -- EquiTriangle --";
	cout << string << endl;
}

/// @brief write a warning message 
/// @param string message to be printed
void EquiTriangle::WarningMessage(const char* string)
{
	cout << endl << "WARNING -- EquiTriangle --";
	cout << string << endl;
}


/// @brief for debugging: all about the object
void EquiTriangle::Dump()
{
	cout << endl;
	cout << "---EquiTriangle---" << endl;
	cout << endl;

	cout << "Side = " << side << endl;
	cout << "Angles = " << "60, 60, 60" << endl;

	Triangle::Dump();

	cout << endl;
}






