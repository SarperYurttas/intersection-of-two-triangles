// vector3.h

#ifndef VECTOR3_H
#define VECTOR3_H

/**
 * @brief A class representing a 3-dimensional vector.
 *
 * The Vector3 class provides basic vector operations such as addition, subtraction,
 * dot product, cross product, and length calculation.
 */
class Vector3
{
private:
    double x; /**< The x-coordinate of the vector. */
    double y; /**< The y-coordinate of the vector. */
    double z; /**< The z-coordinate of the vector. */

public:
    /**
     * @brief Default constructor that initializes the vector to (0, 0, 0).
     */
    Vector3() : x(0), y(0), z(0) {}

    /**
     * @brief Parameterized constructor that initializes the vector with the given x, y, z values.
     *
     * @param x The x-coordinate of the vector.
     * @param y The y-coordinate of the vector.
     * @param z The z-coordinate of the vector.
     */
    Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

    /**
     * @brief Getter for the x-coordinate.
     * @return The x-coordinate of the vector.
     */
    double _x() const { return x; }

    /**
     * @brief Getter for the y-coordinate.
     * @return The y-coordinate of the vector.
     */
    double _y() const { return y; }

    /**
     * @brief Getter for the z-coordinate.
     * @return The z-coordinate of the vector.
     */
    double _z() const { return z; }

    /**
     * @brief Subtracts one vector from another.
     *
     * This operator returns a new vector that is the result of subtracting
     * the given vector from the current vector.
     *
     * @param v The vector to be subtracted.
     * @return A new vector that is the result of the subtraction.
     */
    Vector3 operator-(const Vector3 &v) const;

    /**
     * @brief Adds two vectors.
     *
     * This operator returns a new vector that is the result of adding
     * the given vector to the current vector.
     *
     * @param v The vector to be added.
     * @return A new vector that is the result of the addition.
     */
    Vector3 operator+(const Vector3 &v) const;

    /**
     * @brief Computes the cross product of two vectors.
     *
     * This function returns a new vector that is the cross product of
     * the current vector and the given vector.
     *
     * @param v The vector to compute the cross product with.
     * @return A new vector that is the result of the cross product.
     */
    Vector3 cross(const Vector3 &v) const;

    /**
     * @brief Computes the dot product of two vectors.
     *
     * This function returns the dot product of the current vector and the given vector.
     *
     * @param v The vector to compute the dot product with.
     * @return The dot product of the two vectors.
     */
    double dot(const Vector3 &v) const;

    /**
     * @brief Computes the length of the vector.
     *
     * This function returns the length (magnitude) of the vector.
     *
     * @return The length of the vector.
     */
    double length() const;
};

#endif
