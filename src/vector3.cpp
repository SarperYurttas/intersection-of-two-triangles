#include "vector3.h"
#include <cmath> // std::sqrt

// Overload the subtraction operator
Vector3 Vector3::operator-(const Vector3 &v) const
{
    return {x - v.x, y - v.y, z - v.z};
}

// Overload the addition operator
Vector3 Vector3::operator+(const Vector3 &v) const
{
    return {x + v.x, y + v.y, z + v.z};
}

// Overload the cross product
Vector3 Vector3::cross(const Vector3 &v) const
{
    return {
        y * v.z - z * v.y,
        z * v.x - x * v.z,
        x * v.y - y * v.x};
}

// Dot product
double Vector3::dot(const Vector3 &v) const
{
    return x * v.x + y * v.y + z * v.z;
}

// Length (magnitude) of the vector
double Vector3::length() const
{
    return std::sqrt(x * x + y * y + z * z);
}
