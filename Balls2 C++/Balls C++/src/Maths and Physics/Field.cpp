#include "Field.h"




//template<typename T>
//Field<T>::Field(vec2f centre, float width, float height, float spacing) : centre(centre), dimensions({ width, height }), ds(spacing) {
//	nX = width / ds;
//	nY = height / ds;
//
//	padding = 2;
//
//	aX = nX + padding;	//+2 for derivative values, +2 for nullptr padding.
//	aY = nY + padding;
//
//	rPtr0 = new T * [aX * aY];
//	wPtr0 = new T * [aX * aY];
//	ptr0 = FieldPtr<T>(rPtr0, wPtr0, ds, nX, nY, padding);
//
//	
//	//TODO: Change all code bellow to while loops.
//	//Boundary padding.
//
//	int i = 0;
//	int increment = 1;
//	int ptrDir = aX;
//	bool finished = false;
//	while (!finished) {
//
//		T** rPtr = rPtr0 + i;
//		T** wPtr = wPtr0 + i;
//
//		*rPtr = &boundaryDerivative;
//		*wPtr = &boundaryDerivative;
//
//		*(rPtr + ptrDir) = &boundaryVal;
//		*(wPtr + ptrDir) = &boundaryVal;
//
//		if (i == aX - 1) {
//			increment = aX;
//			ptrDir = -1;
//		}
//		if (i == aX * aY - 1){
//			increment = -1;
//			ptrDir = -aX;
//		}
//		if (i == aX * (aY - 1) ) {
//			increment = -aX;
//			ptrDir = 1;
//		}
//		if (i == aX) {
//			finished == true;
//		}
//
//		i += increment;
//	}
//
//}
//
//int getAbsoluteIndex(int index, int nX, int padding) {
//	int aX = nX + padding;
//	return padding * (1 + aX) + index % nX + (index / nX) * aX;
//}
//
//template<typename T>
//int Field<T>::index(vec2f pos) const {
//	vec2f topLeft = centre - dimensions / 2;
//	vec2f diff = pos - topLeft;
//	diff.x = diff.x / dimensions.x;
//	diff.y = diff.y / dimensions.y;
//
//	int i = diff.x / ds;
//	int j = -diff.y / ds;
//
//	return i + j * aX;
//}  
//
//template<typename T>
//void Field<T>::bindChanges() {
//	for (int index = 0; index < nX * nY; index++) {
//		int j = getAbsoluteIndex(index, nX, padding);
//		**(rPtr0 + j) = **(wPtr0 + j);
//
//	}
//}
//
//template<typename T>
//T Field<T>::ddx(int index) {
//	FieldPtr<T> fptr = getPtr(index);
//	return (*(fptr + 1) - *(fptr - 1)) / (2 * ds);
//}
//template<typename T>
//T Field<T>::ddx(vec2f pos) {
//	FieldPtr<T> fptr = getPtr(pos);
//	return (*(fptr + 1) - *(fptr - 1)) / (2 * ds);
//}
//
//int index){
//	FieldPtr<T> fptr = getPtr(index);
//	return (*(fptr + nX) - *(fptr - nX)) / (2 * ds);
//}
//template<typename T>
//T Field<T>::ddy(vec2f pos) {
//	FieldPtr<T> fptr = getPtr(pos);
//	return (*(fptr + nX) - *(fptr - nX)) / (2 * ds);
//}
//
//vec2f Field<float>::grad(int index) {
//	return vec2f(ddx(index), ddy(index));
//}
//vec2f Field<float>::grad(vec2f pos) {
//	return vec2f(ddx(pos), ddy(pos));
//}
//
//float Field<vec2f>::div(int index) {
//	vec2f dFx = ddx(index);
//	vec2f dFy = ddy(index);
//
//	return dFx.x + dFy.y;
//}
//float Field<vec2f>::div(vec2f pos) {
//	vec2f dFx = ddx(pos);
//	vec2f dFy = ddy(pos);
//
//	return dFx.x + dFy.y;
//}
//
//float Field<vec2f>::curl(int index) {
//	vec2f dFx = ddx(index);
//	vec2f dFy = ddy(index);
//
//	return dFx.y - dFy.x;
//}
//float Field<vec2f>::curl(vec2f pos) {
//	vec2f dFx = ddx(pos);
//	vec2f dFy = ddy(pos);
//
//	return dFx.y - dFy.x;
//}
//
//
//
//template<typename T>
//T FieldPtr<T>::operator *() const {
//
//	int x = index % nX;
//	int y = index / nX;
//
//	int realIndex = x + y * aX;
//	return **(rPtr0 + realIndex);
//}
//template<typename T>
//T& FieldPtr<T>::operator *() {
//	int x = index % nX;
//	int y = index / nY;
//
//	int realIndex = x + y * aX;
//	return **(wPtr0 + realIndex);
//}
