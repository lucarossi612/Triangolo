#include "CTriangle.h"

/// @brief default constructor 
Triangle::Triangle()
{
	cout << "Triangle - constructor - default" << endl;

	Reset();
} 

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
Triangle::Triangle(const Triangle &o){
	
	cout << "Triangle - copy constructor" << endl;

	Init(o);
}

/// @brief destructor
Triangle::~Triangle() {

	cout << "Triangle - destructor" << endl;
	Reset();

}  


/// @brief sets the value of the four sides 
/// @param s1 side 1 
/// @param s2 side 2 
/// @param s3 side 3
void Triangle::SetSides(float s0, float s1, float s2) {
	
	sides[0] = s0;
	sides[1] = s1;
	sides[2] = s2;
	
	return;

} 

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Triangle& Triangle::operator=(const Triangle &o) { 

	return *this;
	
}

/// @brief overload of operator == 
/// @param o reference to the object on the right side of the operator 
/// @return always false 
bool Triangle::operator==(const Triangle &o) 
{
	if (o.sides[0]==sides[0] || o.sides[1]==sides[1] || o.sides[2]==sides[2])
		return true;
	return false;
}

/// @brief default initialization of the object
void Triangle::Init() {
	sides[0]= sides[1]= sides[2] = 0.;
}


/// @brief initialization of the object as a copy of an object 
/// @param o reference to the object that should be copied 
void Triangle::Init(const Triangle &o) {
	Init();
	sides[0] = o.sides[0]; 
	sides[1] = o.sides[1]; 
	sides[2] = o.sides[2]; 
}

/// @brief total reset of the object  
void Triangle::Reset() {
	sides[0]= sides[1]= sides[2] = 0.;
	
}


/// @brief get the perimeter of the object
/// @return perimeter 
float Triangle::GetPerimeter() {

	return (sides[0]+sides[1]+sides[2]);

} 

/// @brief get the sides of the object 
/// @param s0 side 0 
/// @param s1 side 1
/// @param s2 side 2
void Triangle::GetSides(float &s0, float &s1, float &s2) {

	s0 = sides[0]; 
	s1 = sides[1];
	s2 = sides[2];
}

/// @brief write an error message 
/// @param string message to be printed
void Triangle::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Triangle --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Triangle::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Triangle --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void Triangle::Dump() {
	
	cout << endl;
	cout << "Sides = " << sides[0] << "; " << sides[1] << "; " << sides[2] << "; " << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;
	cout << endl;

}

