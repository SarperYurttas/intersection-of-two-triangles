// vector3.h

#ifndef VECTOR3_H
#define VECTOR3_H
#include <iostream>

class Vector3
{
public:
    double x, y, z;

    Vector3 operator-(const Vector3 &v) const;
    Vector3 operator+(const Vector3 &v) const;
    Vector3 cross(const Vector3 &v) const;
    double dot(const Vector3 &v) const;
    float length() const;
    void print() const;
};

#endif
