#pragma once
struct vec2f
{

	float x = 0;
	float y = 0;

	vec2f();
	vec2f(const float& components);
	vec2f(const float x, const float y);
	void set(const vec2f v);

	vec2f operator +(vec2f v) const;
	vec2f operator -(vec2f v) const;
	vec2f operator -();
	vec2f operator *(float s) const;
	vec2f operator /(float s) const;
	void operator +=(vec2f v);
	void operator -=(vec2f v);
	void operator *=(float s);

	/*float operator <> (vec2f v);
	float operator >< (vec2f v);*/

	void normalise();
	float lengthSq() const;

};

vec2f operator *(const float s, const vec2f);

float dot(const vec2f v1, const vec2f v2);
float cross(const vec2f v1, const vec2f v2);

const static vec2f X = vec2f(1.0f, 0.0f);
const static vec2f Y = vec2f(0.0f, 1.0f);
const static vec2f O = vec2f(0.0f, 0.0f);

