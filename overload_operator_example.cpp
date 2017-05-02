// vect.cpp
// Member-function definitions for class VecType


#include "vect.h"
#include <iostream>
#include <cassert>
using namespace std;
//display on monitor details of the authors of code in cpp file
void info(){
	cout<<"***********************************"<<endl;
	cout<<"*   Michael Zhao        *"<<endl;
	cout<<"***********************************"<<endl<<endl<<endl;
}

ostream &operator<<(ostream &out, const VecType &v ){
	for(int i=0;i<v.size;i++){
		if(v.ptr[i]<10){
			cout<<"     ";
		}
		if((v.ptr[i]>=10)&&(v.ptr[i]<100)){
			cout<<"    ";
		}
		if((v.ptr[i]>=100)&&(v.ptr[i]<1000)){
			cout<<"   ";
		}
		if((v.ptr[i]>=1000)&&(v.ptr[i]<10000)){
			cout<<"  ";
		}
		cout<<v.ptr[i];
		if((i+1)%5==0){
			cout<<endl;
		}
	}
	cout<<endl;
	return out;
}

//overlaod input operator for Vectype,fill up array[size]
istream &operator>>(istream &in , VecType &v){
	cout<<"you must enter "<<v.size<<" integer numbers(eg:1 2 3)"<<endl;
	cout<<"(The cin will keep reading integers until "<<v.size<<" integers has been loaded)"<<endl;
	cout<<"(others will be discarded)"<<endl;
	for(int i=0;i<v.size;i++){
		cin>>v.ptr[i];
	}
	return in;
}

// default constructor,array will be initilized as 0 for each elements
VecType :: VecType(int i){
	size=i;
	ptr=new ElemType[size];
	for(int count=0;count<size;count++){
		ptr[count]=0;
	}
}

// copy constructor, deep coy
VecType :: VecType(const VecType &v){
	size=v.size;
	ptr=new ElemType[size];
	for(int i=0;i<size;i++){
		ptr[i]=v.ptr[i];
	}
}	

// destructor, remove the dynamic array
VecType :: ~VecType(){
	delete [] ptr;
}

// return size
int VecType :: getSize() const{
	return size;
}	


//overload assignment operator,deep coy
const VecType& VecType :: operator=(const VecType &v){
	if(&v!=this){
		delete [] ptr;
		size=v.size;
		ptr= new ElemType[size];
		for(int i=0;i<size;i++){
			ptr[i]=v.ptr[i];
	   }
	}
	return *this;
}


//overload equality operator
bool VecType :: operator==( const VecType &v ) const{	
	if(size==v.size){
		for(int i=0;i<size;i++){
			if(ptr[i]!=v.ptr[i]){
				return false;
			}
		}
		return true;
	}
	return false;
} 

//overload not-equal operator: 
bool VecType :: operator!=( const VecType &v ) const{
	if(size==v.size){
		for(int i=0;i<size;i++){
			if(ptr[i]!=v.ptr[i]){
				return true;
			}
		}
		return false;
	}
	return true;
}


// subscript operator for non-const objects, read&write array
ElemType& VecType :: operator[](int i){
	assert((i>=0)&&(i<size));
	return ptr[i];
}   

// subscript operator for const objects, read array only eg:const array[]
ElemType VecType :: operator[](int i) const{
	assert((i>=0)&&(i<size));
	return ptr[i];
}
