#include <iostream>
#include "utils.h"
#include "vector3.h"

/**
 * @brief Determines if two triangles in 3D space intersect.
 *
 * This function takes the coordinates of two triangles in 3D space and determines whether they intersect.
 * Each triangle is represented by an array of 9 doubles, corresponding to the coordinates of its 3 vertices
 * (x1, y1, z1, x2, y2, z2, x3, y3, z3).
 *
 * @param t1 Array of 9 doubles representing the first triangle.
 * @param t2 Array of 9 doubles representing the second triangle.
 * @return true if the triangles intersect, false otherwise.
 *
 * @note The algorithm implemented in this function is based on the work of David Eberly.
 *
 * @see Eberly, David. "Dynamic Collision Detection using Oriented Bounding Boxes", 2001/05/25.
 */
bool doTrianglesIntersect(double t1[9], double t2[9])
{
    Vector3 A0 = {t1[0], t1[1], t1[2]};
    Vector3 A1 = {t1[3], t1[4], t1[5]};
    Vector3 A2 = {t1[6], t1[7], t1[8]};

    Vector3 B0 = {t2[0], t2[1], t2[2]};
    Vector3 B1 = {t2[3], t2[4], t2[5]};
    Vector3 B2 = {t2[6], t2[7], t2[8]};

    Vector3 E0 = A1 - A0;
    Vector3 E1 = A2 - A0;
    Vector3 E2 = E1 - E0;
    Vector3 N = E0.cross(E1);

    Vector3 F0 = B1 - B0;
    Vector3 F1 = B2 - B0;
    Vector3 F2 = F1 - F0;
    Vector3 M = F0.cross(F1);

    Vector3 D = B0 - A0;

    double p0 = 0;
    double p1 = 0;
    double p2 = 0;
    double q0 = 0;
    double q1 = 0;
    double q2 = 0;

    // Seperating axis: N

    p0 = 0;
    p1 = 0;
    p2 = 0;
    q0 = N.dot(D);
    q1 = q0 + N.dot(F0),
    q2 = q0 + N.dot(F1);

    if (are_projections_separated(p0, p1, p2, q0, q1, q2))
        return false;

    // Seperating axis: M

    p0 = 0;
    p1 = M.dot(E0);
    p2 = M.dot(E1);
    q0 = M.dot(D);
    q1 = q0,
    q2 = q0;

    if (are_projections_separated(p0, p1, p2, q0, q1, q2))
        return false;

    // Seperating axis: E0 × F0

    p0 = 0;
    p1 = 0;
    p2 = -(N.dot(F0));
    q0 = E0.cross(F0).dot(D);
    q1 = q0;
    q2 = q0 + M.dot(E0);

    if (are_projections_separated(p0, p1, p2, q0, q1, q2))
        return false;

    // Seperating axis: E0 × F1
    p0 = 0;
    p1 = 0;
    p2 = -(N.dot(F1));
    q0 = E0.cross(F1).dot(D);
    q1 = q0 - M.dot(E0);
    q1 = q0;

    if (are_projections_separated(p0, p1, p2, q0, q1, q2))
        return false;

    // Seperating axis: E0 × F2

    p0 = 0;
    p1 = 0;
    p2 = -(N.dot(F2));
    q0 = E0.cross(F2).dot(D);
    q1 = q0 - M.dot(E0);
    q2 = q1;

    if (are_projections_separated(p0, p1, p2, q0, q1, q2))
        return false;

    // Seperating axis: E1 × F0

    p0 = 0;
    p1 = N.dot(F0);
    p2 = 0;
    q0 = E1.cross(F0).dot(D);
    q1 = q0;
    q2 = q0 + M.dot(E1);

    if (are_projections_separated(p0, p1, p2, q0, q1, q2))
        return false;

    // Seperating axis: E1 × F1

    p0 = 0;
    p1 = N.dot(F1);
    p2 = 0;
    q0 = E1.cross(F1).dot(D);
    q1 = q0 - M.dot(E1);
    q2 = q0;

    if (are_projections_separated(p0, p1, p2, q0, q1, q2))
        return false;

    // Seperating axis: E1 × F2

    p0 = 0;
    p1 = N.dot(F2);
    p2 = 0;
    q0 = E1.cross(F2).dot(D);
    q1 = q0 - M.dot(E1);
    q2 = q1;

    if (are_projections_separated(p0, p1, p2, q0, q1, q2))
        return false;

    // Seperating axis: E2 × F0

    p0 = 0;
    p1 = N.dot(F0);
    p2 = p1;
    q0 = E2.cross(F0).dot(D);
    q1 = q0;
    q2 = q0 + M.dot(E2);

    if (are_projections_separated(p0, p1, p2, q0, q1, q2))
        return false;

    // Seperating axis: E2 × F1

    p0 = 0;
    p1 = N.dot(F1);
    p2 = p1;
    q0 = E2.cross(F1).dot(D);
    q1 = q0 - M.dot(E2);
    q2 = q0;

    if (are_projections_separated(p0, p1, p2, q0, q1, q2))
        return false;

    // Seperating axis: E2 × F2

    p0 = 0;
    p1 = N.dot(F2);
    p2 = p1;
    q0 = E2.cross(F2).dot(D);
    q1 = q0 - M.dot(E2);
    q2 = q1;

    if (are_projections_separated(p0, p1, p2, q0, q1, q2))
        return false;

    /*
     * For coplanar triangles
     *
     * lambda is calculated as follows:
     * l^2 = ||N||^2
     * λij = Ei × Fj . N / ||N||^2
     * λijl^2 = Ei × Fj . N
     *
     * μ is calculated as follows:
     *
     * μ = F0 × F1 . N / ||N||^2
     * μl^2 = F0 × F1 . N
     *
     */

    // Seperating axis: N
    /* This part most likely is not correct in the paper and results in wrong answers */

    // p0 = 0;
    // p1 = 0;
    // p2 = 0;
    // q0 = N.dot(D);
    // q1 = q0;
    // q2 = q0;

    // if (are_projections_separated(p0, p1, p2, q0, q1, q2))
    //     return false;

    // Seperating axis: N x E0

    p0 = 0;
    p1 = 0;
    p2 = N.length() * N.length();
    q0 = N.cross(E0).dot(D);
    q1 = q0 + E0.cross(F0).dot(N);
    q2 = q0 + E0.cross(F1).dot(N);

    if (are_projections_separated(p0, p1, p2, q0, q1, q2))
        return false;

    // Seperating axis: N x E1

    p0 = 0;
    p1 = -(N.length() * N.length());
    p2 = 0;
    q0 = N.cross(E1).dot(D);
    q1 = q0 + E1.cross(F0).dot(N);
    q2 = q0 + E1.cross(F1).dot(N);

    if (are_projections_separated(p0, p1, p2, q0, q1, q2))
        return false;

    // Seperating axis: N x E2

    p0 = 0;
    p1 = -(N.length() * N.length());
    p2 = p1;
    q0 = N.cross(E2).dot(D);
    q1 = q0 + E1.cross(F0).dot(N) - E0.cross(F0).dot(N);
    q2 = q0 + E1.cross(F1).dot(N) - E0.cross(F1).dot(N);

    if (are_projections_separated(p0, p1, p2, q0, q1, q2))
        return false;

    // Seperating axis: N x F0

    p0 = 0;
    p1 = -E0.cross(F0).dot(N);
    p2 = -E1.cross(F0).dot(N);
    q0 = N.cross(F0).dot(D);
    q1 = q0;
    q2 = q0 + F0.cross(F1).dot(N);

    if (are_projections_separated(p0, p1, p2, q0, q1, q2))
        return false;

    // Seperating axis: N x F1

    p0 = 0;
    p1 = -E0.cross(F1).dot(N);
    p2 = -E1.cross(F1).dot(N);
    q0 = N.cross(F1).dot(D);
    q1 = q0 - F0.cross(F1).dot(N);
    q2 = q0;

    if (are_projections_separated(p0, p1, p2, q0, q1, q2))
        return false;

    // Seperating axis: N x F2

    p0 = 0;
    p1 = E0.cross(F0).dot(N) - E0.cross(F1).dot(N);
    p2 = E1.cross(F0).dot(N) - E1.cross(F1).dot(N);
    q0 = N.cross(F2).dot(D);
    q1 = q0 - F0.cross(F1).dot(N);
    q2 = q1;

    if (are_projections_separated(p0, p1, p2, q0, q1, q2))
        return false;

    return true;
}

int main()
{
    /* Test case 1 */
    double t1_1[] = {0, 1, 0, 0, 0, 1, 0, 1, 1};
    double t2_1[] = {1, 2, 1, 1, 1, 2, 1, 2, 2};

    bool result_1 = doTrianglesIntersect(t1_1, t2_1);
    bool answer_1 = false;

    std::cout << "Test Case 1: " << (result_1 == answer_1 ? "passed" : "failed") << std::endl;

    /* Test case 2 */
    double t1_2[] = {3.864994683561619, 1.2509252852376846, -3.6066277261844815, 1.1975897709872267, 4.586221316913052, 3.6670550244269933, 4.267812696229356, -0.7021303537570001, -2.1079316301943796};
    double t2_2[] = {-3.6345636519509705, 3.1124790353390086, -1.5461949016779863, 4.238340236606968, 4.259454430432568, -2.509734340518097, -3.3604777082954973, 3.2556602609236798, -0.7180647959668685};

    bool result_2 = doTrianglesIntersect(t1_2, t2_2);
    bool answer_2 = false;

    std::cout << "Test Case 2: " << (result_2 == answer_2 ? "passed" : "failed") << std::endl;

    /* Test case 3 */
    double t1_3[] = {-1.3128973224686935, 3.5447127734128827, -0.7569481047827225, 1.9429648277005622, 3.5253203246575566, 1.541561842679073, -1.3038717031394254, -1.1334543159408361, 4.883277124721193};
    double t2_3[] = {-4.652730714964097, 1.0383217756329444, 3.453144179978585, -0.6914959254539106, 3.434352137877923, 3.375107570321818, 4.889264091143776, -2.8931032184747707, 0.19042646559876086};

    bool result_3 = doTrianglesIntersect(t1_3, t2_3);
    bool answer_3 = true;

    std::cout << "Test Case 3: " << (result_3 == answer_3 ? "passed" : "failed") << std::endl;

    /* Test case 4 (Coplanar Triangles) */
    double t1_4[] = {1, 0.9, 0, 1, 0, 0, 1, 1, 1};
    double t2_4[] = {1, 2, 0, 1, 1.5, 0, 1, 2, 2};

    bool result_4 = doTrianglesIntersect(t1_4, t2_4);
    bool answer_4 = false;

    std::cout << "Test Case 4: " << (result_4 == answer_4 ? "passed" : "failed") << std::endl;

    /* Test case 5 (Parallel Triangles) */
    double t1_5[] = {1, 0.9, 0, 1, 0, 0, 1, 1, 1};
    double t2_5[] = {2, 0.9, 0, 2, 0, 0, 2, 1, 1};

    bool result_5 = doTrianglesIntersect(t1_5, t2_5);
    bool answer_5 = false;

    std::cout << "Test Case 5: " << (result_5 == answer_5 ? "passed" : "failed") << std::endl;

    /* Test case 6 */
    double t1_6[] = {0, 0, 0, 5, 0, 0, 0, 5, 0};
    double t2_6[] = {1, 1, 0, 4, 1, 0, 1, 4, 0};

    bool result_6 = doTrianglesIntersect(t1_6, t2_6);
    bool answer_6 = true;

    std::cout << "Test Case 6: " << (result_6 == answer_6 ? "passed" : "failed") << std::endl;

    /* Test case 7 */
    double t1_7[] = {0, 0, 0, 2, 2, 2, 2, 0, 2};
    double t2_7[] = {1, 0, 0, 1, 1, 1, 0, 1, 1};

    bool result_7 = doTrianglesIntersect(t1_7, t2_7);
    bool answer_7 = true;

    std::cout << "Test Case 7: " << (result_7 == answer_7 ? "passed" : "failed") << std::endl;

    return EXIT_SUCCESS;
}
