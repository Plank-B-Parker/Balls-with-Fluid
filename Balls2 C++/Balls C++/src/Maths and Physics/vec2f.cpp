#include "vec2f.h"
#include <cmath>

vec2f::vec2f()
{

}
vec2f::vec2f(const float x, const float y)
{
	this->x = x;
	this->y = y;
}

vec2f::vec2f(const float& component)
{
	x = component;
	y = component;
}

void vec2f::set(const vec2f v)
{
	x = v.x;
	y = v.y;
}

vec2f vec2f::operator +(const vec2f v) const
{
	return vec2f(x + v.x, y + v.y);
}

vec2f vec2f::operator -(const vec2f v) const
{
	return vec2f(x - v.x, y - v.y);
}

vec2f vec2f::operator -() {
	return vec2f(-x, -y);
}

vec2f vec2f::operator *(const  float s) const
{
	return vec2f(s * x, s * y);
}

vec2f operator *(const float s, vec2f v)
{
	return vec2f(s * v.x, s * v.y);
}

vec2f vec2f::operator /(const float s) const
{
	return vec2f(x / s, y/ s);
}

void vec2f::operator +=(const vec2f v)
{
	x += v.x;
	y += v.y;
}

void vec2f::operator -=(const vec2f v)
{
	x -= v.x;
	y -= v.y;
}

void vec2f::operator *=(const float s)
{
	x *= s;
	y *= s;
}

float dot(const vec2f v1, const vec2f v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

float cross(const vec2f v1, const vec2f v2)
{
	return v1.x * v2.y - v1.y * v2.x;
}

float vec2f::lengthSq() const
{
	return x * x + y * y;
}

void vec2f::normalise()
{
	float length = std::sqrt(this->lengthSq());
	*this = *this * length;
}
