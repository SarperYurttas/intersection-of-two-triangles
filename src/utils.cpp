#include "utils.h"

double dmin3(double a, double b, double c)
{
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

double dmax3(double a, double b, double c)
{
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

bool are_projections_separated(double p0, double p1, double p2, double q0, double q1, double q2)
{
    double min_p = dmin3(p0, p1, p2);
    double max_p = dmax3(p0, p1, p2);
    double min_q = dmin3(q0, q1, q2);
    double max_q = dmax3(q0, q1, q2);

    return (min_p > max_q) || (max_p < min_q);
}
