/*! \file CScalTriangle.h
	\brief Declaration of the class ScalTriangle

	Details.
*/

#ifndef SCALTRIANGLE_H
#define SCALTRIANGLE_H

#include <iostream>

#include "CTriangle.h"

using namespace std;

/// @class ScalTriangle
/// @brief to manage an object with the shape of an scalene triangle
class ScalTriangle : public Triangle
{
protected:
	float side1;
	float side2;
	float side3;

public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	ScalTriangle();
	ScalTriangle(float s1, float s2, float s3);
	ScalTriangle(const ScalTriangle& o);

	~ScalTriangle();
	/// @}

	/// @name OPERATORS
	/// @{
	ScalTriangle& operator=(const ScalTriangle& o);
	bool operator==(const ScalTriangle& t);
	/// @}

	/// @name BASIC HANDLING
	/// @{
	void Init();
	void Init(const ScalTriangle& t);
	void Reset();
	/// @}


	/// @name GETTERS / SETTERS
	/// @{
	void SetFirstSide(float s1);
	void SetSecondSide(float s2);
	void SetThirdSide(float s3);
	void SetDim(float s1, float s2, float s3);

	void GetDim(float& s1, float& s2, float& s3);
	float GetFirstSide();
	float GetSecondSide();
	float GetThirdSide();
	/// @}


	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char* string);
	void WarningMessage(const char* string);
	void Dump();
	/// @}

};

#endif