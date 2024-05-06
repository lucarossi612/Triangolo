/*! \file CTriangle.h
	\brief Declaration of the general class Triangle

	Details.
*/


#ifndef TRIANGLE_H
#define TRIANGLE_H

#include<iostream>

using namespace std;

/// @class Triangle
/// @brief an abstract base class for Triangle
class Triangle {
protected:

	float sides[3];
	
	void SetSides(float s0, float s1, float s2); 


public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Triangle();
	Triangle(const Triangle &o);
	virtual ~Triangle();
	/// @}
	
	/// @name OPERATORS
	/// @{
	Triangle& operator=(const Triangle &o); 
	bool operator==(const Triangle &o);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const Triangle &o);							
	void Reset();												
	/// @}

			
	/// @name GETTERS
	/// @{
	float GetPerimeter();
	float GetArea(float* sides);
	void GetSides(float &s0, float &s1, float &s2);
	/// @}
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}

};

#endif