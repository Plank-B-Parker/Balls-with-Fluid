
#pragma once
#include "vec2f.h"
#include "Field.h"
#include <cMath>
#include <vector>

//struct gridFloat {
//	float value;
//	int index;
//};


//class fluidGrid {
//	
//	static const int resolution = 100;
//	const float ds = 1.0f / (float)(resolution);
//	float width;
//	float height;
//	int size;
//
//	Field<float> rho;
//	Field<float> P;
//	Field<vec2f> v;
//	Field<float> T;
//	Field<int> fluid;
//
//	//fluids in grid.
//	std::vector<float> R;
//	std::vector<float> heatCapacity;
//	std::vector<float> heatTransfCoeff;
//	std::vector<float> diffusivity;
//
//	template<typename T>
//	void transferSubstance(Field<T> something, float dt); 
//};
//
//class fluid {
//
//	//Grid Constants
//	static const int resolution = 100;
//	const float ds = 1.0f / (float)(resolution);
//	float width;
//	float height;
//	int size;
//
//	//Fluid Fields
//	Field<float> rho;
//	Field<float> P;
//	Field<vec2f>* vPtr;
//	Field<vec2f> v;
//	Field<float> T;
//	Field<float> s; //Scalar field for concentration
//
//	//Fluid Constants
//	const float R = 287.0f;
//	const float heatTransfCoeff = 0.01f;
//	const float heatCapacity = 10.0f;
//	const float diffusivity = 0.001f;
//
//	void transferSubstance(Field<vec2f> s, float dt) {
//		for (int i = 0; i < s.size(); i++) {
//
//			for (int j = 0; j < 4; j++) {
//				int di = s.directions[j];
//				vec2f normal = s.normals[j];
//
//				vec2f v1 = v[i];
//
//				//Doesn't include diagnoal directions (corners).
//				vec2f vAvg = 0.5f * (v[i] + v[i + di]);
//
//				if (dot(normal, vAvg) > 0) {
//					s[i] += -s[i] * dot(normal, vAvg) * dt / s.ds;
//				}
//				else {
//					s[i] += -s[i + di] * dot(normal, vAvg) * dt / s.ds;
//				}
//			
//			}
//		}
//	}
//
//
//	//TODO: Make following two methods more general for any state equation.
//	void computePressure() {
//		for (int i = 0; i < size; i++) {
//			P[i] = rho[i] * R * T[i];
//		}
//	}
//
//	void updateTemp(float dt) {
//		//Note: divergence for scalar field = laplacian.
//		for (int i = 0; i < size; i++) {
//			T[i] += ((heatTransfCoeff / heatCapacity) * T.div(i) / rho[i] - dot(T.grad(i), v[i]) - (1.0f / heatCapacity) * (dot(P.grad(i), v[i]) + P[i] * v.div(i)) / rho[i]) * dt;
//		}
//	}
//
//	void updateVel(float dt) {
//		for (int i = 0; i < size; i++) {
//			vec2f dP = P.grad(i);
//			vec2f dvdx = v.ddx(i);
//			vec2f dvdy = v.ddy(i);
//
//			vec2f dvdt = -(dP / rho[i] + dvdx * v[i].x + dvdy * v[i].y);
//
//			v[i] += dvdt * dt;
//		}
//	}
//
//	void updateRho(float dt) {
//		for (int i = 0; i < size; i++) {
//			rho[i] += -(dot(rho.grad(i), v[i]) + rho[i] * v.div(v[i])) * dt;
//		}
//	}
//
//	void updateScalar(float dt) {
//		for (int i = 0; i < size; i++) {
//			s[i] += -(T.div(i)*s[i] + 2*dot(T.grad(i), s.grad(i)) + T[i] * s.div(i)) * dt;
//		}
//	}
//
//public:
//
//	fluid(float width, float height):
//		width(width), height(height), 
//		rho(Field<float>(vec2f(0,0), width, height, ds)), P((Field<float>(vec2f(0, 0), width, height, ds))),
//		T((Field<float>(vec2f(0, 0), width, height, ds))), s((Field<float>(vec2f(0, 0), width, height, ds))),
//		v((Field<vec2f>(vec2f(0, 0), width, height, ds))) 
//	{
//		size = rho.size();
//	}
//
//	void update(float dt) {
//		computePressure();
//		updateVel(dt);
//		updateRho(dt);
//		updateTemp(dt);
//	}
//};



