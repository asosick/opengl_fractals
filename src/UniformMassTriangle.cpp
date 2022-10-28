#include "UniformMassTriangle.h"

UniformMassTriangle::UniformMassTriangle(){
    base_units.push_back(UniformMassSubTriangle(
            glm::vec3(-0.5f, -0.5f, 0.f),
            glm::vec3(0.5f, -0.5f, 0.f),
            glm::vec3(0.f, 0.5f, 0.f)
    ));
}
/*
 * Uniform mass sub triangle
 */
UniformMassSubTriangle::UniformMassSubTriangle(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3)
{
    points.push_back(v1);
    points.push_back(v2);
    points.push_back(v3);
}

void UniformMassSubTriangle::subDivide()
{
    auto t0_vec_0 = glm::vec3(points.at(0));
    auto t0_vec_1 = glm::vec3(points.at(1));
    auto t0_vec_2 = glm::vec3(middleOfTriangle());
    sub_units.push_back(UniformMassSubTriangle(t0_vec_0, t0_vec_1, t0_vec_2));

    auto t1_vec_0 = glm::vec3(middleOfTriangle());
    auto t1_vec_1 = glm::vec3(points.at(1));
    auto t1_vec_2 = glm::vec3(points.at(2));
    sub_units.push_back(UniformMassSubTriangle(t1_vec_0, t1_vec_1, t1_vec_2));

    auto t2_vec_0 = glm::vec3(points.at(0));
    auto t2_vec_1 = glm::vec3(middleOfTriangle());
    auto t2_vec_2 = glm::vec3(points.at(2));
    sub_units.push_back(UniformMassSubTriangle(t2_vec_0, t2_vec_1, t2_vec_2));
}

glm::vec3 UniformMassSubTriangle::middleOfTriangle() {
    return {(points.at(0).x +  points.at(1).x +  points.at(2).x)/3,
            (points.at(0).y +  points.at(1).y +  points.at(2).y)/3,
            (points.at(0).z +  points.at(1).z +  points.at(2).z)/3};
}

void UniformMassSubTriangle::leafNodeVerticies(UniformMassSubTriangle& unit, std::vector<glm::vec3>& vec)
{
    if(unit.sub_units.empty())
    {
        vec.push_back(unit.points.at(0));
        vec.push_back(unit.points.at(1));

        vec.push_back(unit.points.at(1));
        vec.push_back(unit.points.at(2));

        vec.push_back(unit.points.at(2));
        vec.push_back(unit.points.at(0));
    }
    else
        for(auto& u: unit.sub_units)
            leafNodeVerticies(u, vec);
}