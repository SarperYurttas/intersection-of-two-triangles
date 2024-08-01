#include <iostream>
#include <cmath>
#include <cassert>
#include "vector3.h"

void testVector3Subtraction()
{
    Vector3 v1 = {3.0f, 2.0f, 1.0f};
    Vector3 v2 = {1.0f, 0.0f, 1.0f};
    Vector3 result = v1 - v2;

    assert(result.x == 2.0f);
    assert(result.y == 2.0f);
    assert(result.z == 0.0f);
}

void testVector3Addition()
{
    Vector3 v1 = {3.0f, 2.0f, 1.0f};
    Vector3 v2 = {1.0f, 0.0f, 1.0f};
    Vector3 result = v1 + v2;

    assert(result.x == 4.0f);
    assert(result.y == 2.0f);
    assert(result.z == 2.0f);
}

void testVector3CrossProduct()
{
    Vector3 v1 = {1.0f, 0.0f, 0.0f};
    Vector3 v2 = {0.0f, 1.0f, 0.0f};
    Vector3 result = v1.cross(v2);

    assert(result.x == 0.0f);
    assert(result.y == 0.0f);
    assert(result.z == 1.0f);
}

void testVector3DotProduct()
{
    Vector3 v1 = {1.0f, 2.0f, 3.0f};
    Vector3 v2 = {4.0f, 5.0f, 6.0f};
    float result = v1.dot(v2);

    assert(result == 32.0f);
}

void testVector3Length()
{
    Vector3 v = {1.0f, 2.0f, 2.0f};
    float length = v.length();

    assert(length == 3.0f);
}

void testTriangleCalculations()
{
    Vector3 A0 = {1.0f, 0.0f, 0.0f};
    Vector3 A1 = {0.0f, 1.0f, 0.0f};
    Vector3 A2 = {0.0f, 0.0f, 1.0f};

    Vector3 B0 = {1.0f, 1.0f, 0.0f};
    Vector3 B1 = {0.0f, 1.0f, 1.0f};
    Vector3 B2 = {1.0f, 0.0f, 1.0f};

    Vector3 E0 = A1 - A0;
    Vector3 E1 = A2 - A0;
    Vector3 E2 = E1 - E0;
    Vector3 N = E0.cross(E1);

    Vector3 F0 = B1 - B0;
    Vector3 F1 = B2 - B0;
    Vector3 F2 = F1 - F0;
    Vector3 M = F0.cross(F1);

    Vector3 D = B0 - A0;

    assert(E0.x == -1.0f && E0.y == 1.0f && E0.z == 0.0f);
    assert(E1.x == -1.0f && E1.y == 0.0f && E1.z == 1.0f);
    assert(E2.x == 0.0f && E2.y == -1.0f && E2.z == 1.0f);
    assert(N.x == 1.0f && N.y == 1.0f && N.z == 1.0f);

    assert(F0.x == -1.0f && F0.y == 0.0f && F0.z == 1.0f);
    assert(F1.x == 0.0f && F1.y == -1.0f && F1.z == 1.0f);
    assert(F2.x == 1.0f && F2.y == -1.0f && F2.z == 0.0f);
    assert(M.x == 1.0f && M.y == 1.0f && M.z == 1.0f);

    assert(D.x == 0.0f && D.y == 1.0f && D.z == 0.0f);
}

int main()
{
    testVector3Subtraction();
    std::cout << "testVector3Subtraction passed!" << std::endl;

    testVector3Addition();
    std::cout << "testVector3Addition passed!" << std::endl;

    testVector3CrossProduct();
    std::cout << "testVector3CrossProduct passed!" << std::endl;

    testVector3DotProduct();
    std::cout << "testVector3DotProduct passed!" << std::endl;

    testVector3Length();
    std::cout << "testVector3Length passed!" << std::endl;

    testTriangleCalculations();
    std::cout << "testTriangleCalculations passed!" << std::endl;

    return 0;
}
