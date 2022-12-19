#pragma once
#include "vec2f.h"
#include <vector>

//Ideas: 
//value resolution?
//Static for now. Make a dynamically resizing field later. Dynamic resolution?

template<typename T>
struct FieldPtr;

template<typename T>
class Field {

	/* 
	* Field Specification.


	* All fields wrap around themselves (equivalently they repeat).
	* Have operations like derivatives, divergence (and transport?).
	* 
	* 
	*/

	//Array info.
	T *rPtr0, *wPtr0;
	int nX = 0, nY = 0;
	

public:

	//World Space Info.
	const vec2f centre = vec2f(0.0f, 0.0f);
	const float width = 0.0f, height = 0.0f;
	const float ds = 0.0f;

	int directions[4];
	const vec2f normals[4] = {vec2f(1.0f, 0.0f), vec2f(0.0f, 1.0f), vec2f(-1.0f, 0.0f), vec2f(0.0f, -1.0f)};

	Field(vec2f centre, float width, float height, float ds) : width(width), height(height), ds(ds) {
		nX = width / ds;
		nY = height / ds;

		directions[0] = 1;
		directions[1] = -nX;
		directions[2] = -1;
		directions[3] = nX;

		rPtr0 = new T[nX * nY];
		wPtr0 = new T[nX * nY];
	}

	int size() {
		return nX * nY;
	}
	void bindChanges() {
		for (int i = 0; i < nX * nY; i++) {
			rPtr0[i] = wPtr0[i];
		}
	}

	~Field() {
		delete[] rPtr0;
		delete[] wPtr0;
	}

	T& operator[](int i) {
		return wPtr0[i];
	}
	T operator[](int i) const {
		return rPtr0[i];
	}
};







//Field Prototype:

//template<typename T>
//class Field {
//
//	friend FieldPtr<T>;
//
//	FieldPtr<T> ptr0;
//	T** rPtr0, ** wPtr0;	//To delete memory.
//
//	vec2f centre;
//	float ds;			//Cell spacing.
//
//	int nX, nY;			//Number of non-boundary cells.
//	int aX, aY;			//Array size.
//	int padding;
//
//	T boundaryVal;
//	T boundaryDerivative;
//	vec2f dimensions;
//
//	//Returns index of vector position in array as an integer.
//	int index(vec2f pos) const;
//
//public:
//
//	Field(vec2f centre, float width, float height, float spacing);
//	~Field() {
//		delete[] rPtr0;
//		delete[] wPtr0;
//	}
//
//	//Copies writable buffer to read-only buffer.
//	void bindChanges();
//
//	void setBoundary(T val, T derivative) {
//		boundaryVal = val;
//		boundaryDerivative = derivative;
//	}
//
//	const T operator [](int i) const {
//		return *(ptr0 + i % (nX * nY));
//	};
//	T& operator [](int i) {
//		return *(ptr0 + i % (nX * nY));
//	};
//	T& operator [](vec2f pos) {
//		return *(getPtr(pos));
//	}
//	const T operator[](vec2f pos) const {
//		return *(ptr0 + index(pos));
//	}
//
//	FieldPtr<T> getPtr(vec2f pos) {
//		return ptr0 + index(pos);
//	}
//	FieldPtr<T> getPtr(int index) {
//		return ptr0 + index;
//	}
//	FieldPtr<T> lastPtr() {
//		return ptr0 + size() - 1;
//	};
//	int size() {				//Size of accessable array.
//		return nX * nY;
//	};
//
//	T ddx(int);	
//	T ddy(int);
//	T ddx(vec2f);
//	T ddy(vec2f);
//
//	vec2f grad(int);
//	vec2f grad(vec2f);
//
//	float div(int);
//	float div(vec2f);
//	
//	float curl(int);
//	float curl(vec2f);
//	
//};
//
//template<typename T>
//struct FieldPtr {
//
//	const float ds;
//
//	T operator *() const;
//	T& operator *();
//
//	FieldPtr<T> operator ++() {
//		index++;
//		index = index % (nX * nY);
//	}
//	FieldPtr<T> operator +(int disp) const{
//		return FieldPtr<T>(*this, (index + disp) % (nX * nY));
//	}
//	FieldPtr<T> operator -(int disp) const {
//		return FieldPtr<T>(*this, (index - disp) % (nX * nY));
//	}
//	int operator -(const FieldPtr<T>& ptr2) {
//		return index - ptr2.index;
//	}
//	bool operator >(FieldPtr<T> ptr2) {
//		return index > ptr2.index;
//	}
//	bool operator <(FieldPtr<T> ptr2) {
//		return index < ptr2.index;
//	}
//	bool operator >=(FieldPtr<T> ptr2) {
//		return index >= ptr2.index;
//	}
//	bool operator <=(FieldPtr<T> ptr2) {
//		return index <= ptr2.index;
//	}
//
//	FieldPtr() 
//		:wPtr0(nullptr), rPtr0(nullptr), 
//		index(-1), ds(0), nX(0), nY(0), aX(0), aY(0),padding(0)
//	{
//
//	}
//
//	/*~FieldPtr() {
//		delete[] rPtr;
//		delete[] wPtr;
//	}*/
//
//private:
//
//	friend class Field<T>;
//
//	const int nX, nY;
//	const int aX, aY;
//	const int padding;
//
//	const T** const rPtr0;
//	T** const wPtr0;
//
//	int index = 0;
//
//	FieldPtr(T** rPtr0, T** wPtr0, float spacing, int nX, int nY, int padding) 
//		: rPtr0(rPtr0), wPtr0(wPtr0), index(0), nY(nY), nX(nX), aX(nX + padding), aY(nY + padding), padding(padding), ds(spacing)
//	{
//		
//	}
//
//	FieldPtr(const Field<T>* f) 
//		: rPtr0(f->rPtr0), wPtr0(f->wPtr0), index(0), nY(f->nY), nX(f->nX), aX(f->nX + f->padding), aY(f->nY + f->padding), padding(f->padding), ds(f->spacing)
//	{
//
//	}
//
//	FieldPtr(const FieldPtr<T>& ptr, int index)
//		: rPtr0(ptr.rPtr0), wPtr0(ptr.wPtr0), index(index), nY(ptr.nY), nX(ptr.nX), aX(ptr.aX), aY(ptr.aY), padding(ptr.padding), ds(ptr.ds)
//	{
//
//	}
//
//	//FieldPtr(FieldPtr<T> &ptr) {
//
//	//}
//
//	/*FieldPtr(T** rPtr0, T** wPtr0, Field<T>* f)
//		:rPtr0(rPtr0), wPtr0(wPtr0), index(0), ds(f->ds), 
//	{
//
//	}*/
//
//};
//
//
//template<typename T> 
//T ddx(FieldPtr<T> ptr);
//template<typename T>
//T ddy(FieldPtr<T> ptr);
//
//vec2f grad(FieldPtr<float> ptr);
//float div(FieldPtr<vec2f> ptr);
//float curl(FieldPtr<vec2f> ptr);