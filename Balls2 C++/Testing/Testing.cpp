// Testing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "mathTEst.h"
#include <unordered_map>
#include <string>


//struct vec2f {
//	float x;
//	float y;
//
//	vec2f operator +(vec2f);
//	vec2f operator -(vec2f);
//};
//vec2f operator *(vec2f, float);
//vec2f operator *(float, vec2f);
//
//
////float ddx(float (*func)(float), float x);
////float ddx(float (*func)( float (*)(), float), float x);
//
//template<typename T>
//struct FieldPtr;
//
//template<typename T>
//class Field {
//
//	FieldPtr<T> ptr0;
//	
//	float ds;			//Cell spacing.
//
//	int nX, nY;			//Number of non-boundary cells.
//	int aX, aY;			//Array size.
//	T boundaryVal;		
//	T boundaryDerivative;
//	const vec2f dimensions;	
//
//	//Returns index of vector position in array as an integer.
//	int index(vec2f pos);
//
//public:
//
//	Field(float width, float height, float spacing) : dimensions({ width, height}), ds(spacing){
//		nX = width / ds;
//		nY = height / ds;
//
//		aX = nX + 4;	//+2 for derivative values, +2 for nullptr padding.
//		aY = nY + 4;
//		
//		ptr0 = FieldPtr<T>(new T*[aX * aY], new T*[aX * aY], ds);
//	}
//
//	const T operator [](int) const;
//	T& operator [](int);
//
//	void setBoundary(T val) {
//		boundaryVal = val;
//	}
//	
//	//Copies writable buffer to read-only buffer.
//	void bindChanges();
//
//	FieldPtr<T> getPtr(vec2f pos) {
//		FieldPtr<T> ptr = ptr0 + index(pos);
//		
//		return ptr;
//	}
//
//	FieldPtr<T> getPtr(int index) {
//		return ptr0 + index;
//	}
//
//	T ddx(int);
//	T ddy(int);
//	T ddx(vec2f);
//	T ddy(vec2f);
//
//	FieldPtr<T> lastPtr();
//	int size();
//};
//
//template<typename T>
//struct FieldPtr {
//
//
//	const float ds;
//
//	const T val() const;
//	const T operator *() const{
//		return **rPtr;
//	}
//	T& operator *() {
//		return **wPtr;
//	}
//
//	FieldPtr<T> operator +(int);
//	FieldPtr<T> operator -(int);
//	int operator -(FieldPtr<T> ptr2);
//
//	bool operator >(FieldPtr<T>);
//	bool operator <(FieldPtr<T>);
//	bool operator >=(FieldPtr<T>);
//	bool operator <=(FieldPtr<T>);
//	
//	FieldPtr() :wPtr(nullptr), rPtr(nullptr), ds(0) {
//
//	}
//
//private:
//
//	friend class Field<T>;
//
//	T** rPtr;	//read only array.
//	T** wPtr;	//write only array.
//
//	FieldPtr(T** rPtr, T** wPtr , float spacing) : rPtr(rPtr), wPtr(wPtr), ds(spacing) {
//		
//	}
//
//	operator T**() {
//		return rPtr;
//	}
//
//};

template<typename T>
struct A {
	const T variable;
	T variableSq;

	A(float param) : variable(param), variableSq(variable * variable) {

	}

	T operator [] (int i) const{
		return variableSq;
	}

	T& operator [] (int i) {
		return variableSq;
	}

};

int main()
{

	int a[5] = {1,2,3,4,5};

	int* ptrA = &a[0];
	
	
	
	

	//std::unordered_map<
	std::cout << "hello + " << ptrA[3] << std::endl;
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
