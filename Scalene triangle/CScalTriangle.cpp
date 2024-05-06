/// \file CScalTriangle.cpp
///	\brief class ScalTriangle: implementation of the functions
///
///	Details.
///

#include <iostream>
#include "CScalTriangle.h"

/// @brief default constructor 
ScalTriangle::ScalTriangle()
{
	cout << "ScalTriangle - constructor - default" << endl;

	Init();
}

/// @brief constructor 
/// @param b base of the isosceles triangle
/// @param h height of the isosceles triangle
ScalTriangle::ScalTriangle(float s1, float s2, float s3)
{
	Init();

	cout << "ScalTriangle - constructor" << endl;

	if (s1 <= 0. || s2 <= 0. || s3 <= 0.)
	{
		WarningMessage("constructor: side should be > 0");
		SetDim(0, 0, 0);
	}
	else
		SetDim(s1, s2, s3);
}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
ScalTriangle::ScalTriangle(const ScalTriangle& o)
{
	cout << "ScalTriangle - copy constructor" << endl;

	Init(o);
}

/// @brief destructor 
ScalTriangle::~ScalTriangle()
{
	cout << "ScalTriangle - destructor" << endl;
	Reset();
}


/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
ScalTriangle& ScalTriangle::operator=(const ScalTriangle& o)
{
	cout << "ScalTriangle - operator =" << endl;

	Init(o);

	return *this;
}

/// @brief overload of operator == 
/// @param t reference to the object on the right side of the operator 
/// @return true if the two objects have the same for each side.
bool ScalTriangle::operator==(const ScalTriangle& t)
{
	if (t.side1 == side1 && t.side2 == side2 && t.side3 == side3)
		return true;

	return false;
}


/// @brief default initialization of the object
void ScalTriangle::Init()
{
	SetDim(0,0,0);
}

/// @brief initialization of the object as a copy of an object 
/// @param t reference to the object that should be copied 
void ScalTriangle::Init(const ScalTriangle& t)
{
	Init();
	SetDim(t.side1, t.side2, t.side3);
}

/// @brief total reset of the object  
void ScalTriangle::Reset()
{
	SetDim(0,0,0);
}

/// @brief set first side of the object
/// @param s1 side1
void ScalTriangle::SetFirstSide(float s1)
{
	if (s1 < 0.)
	{
		WarningMessage("SetSide: side1 should be > 0");
		return;
	}

	SetDim(s1, side2, side3);
}

/// @brief set second side of the object
/// @param s2 side2
void ScalTriangle::SetSecondSide(float s2)
{
	if (s2 < 0.)
	{
		WarningMessage("SetSide: side2 should be > 0");
		return;
	}

	SetDim(side1, s2, side3);
}

/// @brief set third side of the object
/// @param s3 side3
void ScalTriangle::SetThirdSide(float s3)
{
	if (s3 < 0.)
	{
		WarningMessage("SetSide: side3 should be > 0");
		return;
	}

	SetDim(side1, side2, s3);
}


/// @brief set sides of the object
/// @param s1 side1
/// @param s2 side2
/// @param s3 side3
void ScalTriangle::SetDim(float s1, float s2, float s3)
{
	side1 = s1;
	side2 = s2;
	side3 = s3;
	Triangle::SetSides(side1, side2, side3);

	return;
}

/// @brief get sides of the object
/// @param s1 side1
/// @param s2 side2
/// @param s3 side3
void ScalTriangle::GetDim(float& s1, float& s2, float& s3)
{
	s1 = side1;
	s2 = side2;
	s3 = side3;

	return;
}

/// @brief get first side of the object
/// @return side
float ScalTriangle::GetFirstSide()
{
	return side1;
}

/// @brief get second side of the object
/// @return side
float ScalTriangle::GetSecondSide()
{
	return side2;
}

/// @brief get third side of the object
/// @return side
float ScalTriangle::GetThirdSide()
{
	return side3;
}


/// @brief write an error message 
/// @param string message to be printed
void ScalTriangle::ErrorMessage(const char* string)
{
	cout << endl << "ERROR -- ScalTriangle --";
	cout << string << endl;
}

/// @brief write a warning message 
/// @param string message to be printed
void ScalTriangle::WarningMessage(const char* string)
{
	cout << endl << "WARNING -- ScalTriangle --";
	cout << string << endl;
}


/// @brief for debugging: all about the object
void ScalTriangle::Dump()
{
	cout << endl;
	cout << "---ScalTriangle---" << endl;
	cout << endl;

	Triangle::Dump();

	cout << endl;
}






