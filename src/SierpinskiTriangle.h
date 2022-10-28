//
// Created by August Sosick on 2022-09-17.
//

#ifndef INC_453_SKELETON_SIERPINSKITRIANGLE_H
#define INC_453_SKELETON_SIERPINSKITRIANGLE_H
#include "Fractal_Base.h"

class SierpinskiSubTriangle : public Fractal_Unit<SierpinskiSubTriangle>
{
public:
    SierpinskiSubTriangle(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3);
    void subDivide();
    glm::vec3 midOfVec3s(glm::vec3 one, glm::vec3 two);
};

class SierpinskiTriangle : public Fractal_Base<SierpinskiSubTriangle>
{
public:
    SierpinskiTriangle();
};
#endif //INC_453_SKELETON_SIERPINSKITRIANGLE_H
