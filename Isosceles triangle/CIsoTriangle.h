/*! \file CIsoTriangle.h
	\brief Declaration of the class IsoTriangle

	Details.
*/

#ifndef ISOTRIANGLE_H
#define ISOTRIANGLE_H

#include <iostream>

#include "CTriangle.h"

using namespace std;

/// @class IsoTriangle
/// @brief to manage an object with the shape of an isosceles triangle
class IsoTriangle : public Triangle
{
protected:
	float height;
	float base;
	float side;

public:
	
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	IsoTriangle();
	IsoTriangle(float b, float h);
	IsoTriangle(const IsoTriangle &o);
	
	~IsoTriangle();
	/// @}
	
	/// @name OPERATORS
	/// @{
	IsoTriangle& operator=(const IsoTriangle &o); 
	bool operator==(const IsoTriangle &t);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const IsoTriangle &t);							
	void Reset();												
	/// @}
	
	
	/// @name GETTERS / SETTERS
	/// @{
	void SetBase(float b);
	void SetHeight(float h);
	void SetSide(float b, float h);
	void SetDim(float b, float h);
	
	void GetDim(float &b, float &h, float &s);
	float GetHeight();
	float GetBase();
	float GetSide();
	
	void GetAngles(float h, float s);
	/// @}
	
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}
		
};

#endif