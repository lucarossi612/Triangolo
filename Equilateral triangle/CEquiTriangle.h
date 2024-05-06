/*! \file CEquiTriangle.h
	\brief Declaration of the class EquiTriangle

	Details.
*/

#ifndef EQUITRIANGLE_H
#define EQUITRIANGLE_H

#include <iostream>

#include "CTriangle.h"

using namespace std;

/// @class EquiTriangle
/// @brief to manage an object with the shape of an equilateral triangle
class EquiTriangle : public Triangle
{
protected:
	float side;

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	EquiTriangle();
	EquiTriangle(float s);
	EquiTriangle(const EquiTriangle& o);

	~EquiTriangle();
	/// @}

	/// @name OPERATORS
	/// @{
	EquiTriangle& operator=(const EquiTriangle& o);
	bool operator==(const EquiTriangle& t);
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Init(const EquiTriangle& t);
	void Reset();
	/// @}


	/// @name GETTERS / SETTERS
	/// @{
	void SetSide(float s);
	void SetDim(float s);

	void GetDim(float& s);
	float GetSide();
	float GetHeight(float s);
	/// @}


	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char* string);
	void WarningMessage(const char* string);
	void Dump();
	/// @}

};

#endif