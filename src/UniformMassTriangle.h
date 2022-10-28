//
// Created by August Sosick on 2022-09-17.
//

#ifndef INC_453_SKELETON_UNIFORMMASSTRIANGLE_H
#define INC_453_SKELETON_UNIFORMMASSTRIANGLE_H
#include "Fractal_Base.h"

class UniformMassSubTriangle : public Fractal_Unit<UniformMassSubTriangle>
{
public:
    glm::vec3 middleOfTriangle();
    UniformMassSubTriangle(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3);
    void subDivide();
    void leafNodeVerticies(UniformMassSubTriangle& unit, std::vector<glm::vec3>& vec);
};

class UniformMassTriangle : public Fractal_Base<UniformMassSubTriangle>
{
public:
    UniformMassTriangle();
};
#endif //INC_453_SKELETON_UNIFORMMASSTRIANGLE_H
