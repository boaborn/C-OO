//  vect.h
//DO NOT change this file
//DO NOT SEND THIS FILE for marking
/* VecType class for manipulating sequences 
of  consecutively stored double values.*/
#ifndef VECT_H
#define VECT_H

#include <iostream>
using namespace std;

typedef int ElemType;
void info();/* display on monitor details of the
              authors of code in cpp file  */

class VecType{
   //IO operator overloading:
   friend ostream &operator<<( ostream &, const VecType & );
   friend istream &operator>>( istream &, VecType & );
public:
   VecType( int = 5 ); // default constructor
   VecType( const VecType & ); // copy constructor
   ~VecType(); // destructor
   int getSize() const; // return size

   // assignment operator
   const VecType &operator=( const VecType & ); 
	
  // equality operator
   bool operator==( const VecType & ) const; 

   // not-equal operator: 
   bool operator!=( const VecType &right ) const;   
   // subscript operator for non-const objects 
   ElemType &operator[]( int );              

   // subscript operator for const objects 
   ElemType operator[]( int ) const;  
private:
   int size;    // number of elements in the array object
   ElemType *ptr; /* pointer to first element  
				of pointer-based VecType */
 }; // end class VecType


#endif

