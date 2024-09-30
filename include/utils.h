// utils.h

#ifndef UTILS_H
#define UTILS_H

/**
 * @brief Computes the minimum of three double values.
 *
 * This function returns the smallest of the three given double values.
 *
 * @param a The first double value.
 * @param b The second double value.
 * @param c The third double value.
 * @return The smallest of the three double values.
 */
double dmin3(double a, double b, double c);

/**
 * @brief Computes the maximum of three double values.
 *
 * This function returns the largest of the three given double values.
 *
 * @param a The first double value.
 * @param b The second double value.
 * @param c The third double value.
 * @return The largest of the three double values.
 */
double dmax3(double a, double b, double c);

/**
 * @brief Determines if the projections of two sets of points are separated.
 *
 * This function checks whether the projections of two sets of points on an axis are separated.
 * Each set of points is represented by three double values, corresponding to their projections
 * on a particular axis.
 *
 * @param p0 The projection of the first point in the first set.
 * @param p1 The projection of the second point in the first set.
 * @param p2 The projection of the third point in the first set.
 * @param q0 The projection of the first point in the second set.
 * @param q1 The projection of the second point in the second set.
 * @param q2 The projection of the third point in the second set.
 * @return true if the projections are separated, false otherwise.
 */
bool are_projections_separated(double p0, double p1, double p2, double q0, double q1, double q2);

#endif
