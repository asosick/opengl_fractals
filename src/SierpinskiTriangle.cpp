#include "SierpinskiTriangle.h"

SierpinskiTriangle::SierpinskiTriangle()
{
    base_units.push_back(SierpinskiSubTriangle(
                    glm::vec3(-0.5f, -0.5f, 0.f),
                    glm::vec3(0.5f, -0.5f, 0.f),
                    glm::vec3(0.f, 0.5f, 0.f)
                    ));
}
/*
 * SierpinskiSubTriangle
 */
SierpinskiSubTriangle::SierpinskiSubTriangle(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3)
{
    points.push_back(v1);
    points.push_back(v2);
    points.push_back(v3);
}

glm::vec3 SierpinskiSubTriangle::midOfVec3s(glm::vec3 one, glm::vec3 two)
{
    return {(two.x + one.x)/2, (two.y + one.y)/2, (two.z + one.z)/2 };
}

void SierpinskiSubTriangle::subDivide() 
{
    auto t0_vec_0 = glm::vec3(points.at(0));
    auto t0_vec_1 = glm::vec3(midOfVec3s(points.at(0), points.at(1)));
    auto t0_vec_2 = glm::vec3(midOfVec3s(points.at(0), points.at(2)));
    sub_units.push_back(SierpinskiSubTriangle(t0_vec_0, t0_vec_1, t0_vec_2));

    auto t1_vec_0 = glm::vec3(midOfVec3s(points.at(0), points.at(1)));
    auto t1_vec_1 = glm::vec3(points.at(1));
    auto t1_vec_2 = glm::vec3(midOfVec3s(points.at(1), points.at(2)));
    sub_units.push_back(SierpinskiSubTriangle(t1_vec_0, t1_vec_1, t1_vec_2));

    auto t2_vec_0 = glm::vec3(midOfVec3s(points.at(0), points.at(2)));
    auto t2_vec_1 = glm::vec3(midOfVec3s(points.at(1), points.at(2)));
    auto t2_vec_2 = glm::vec3(points.at(2));
    sub_units.push_back(SierpinskiSubTriangle(t2_vec_0, t2_vec_1, t2_vec_2));
}