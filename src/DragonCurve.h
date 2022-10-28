//
// Created by August Sosick on 2022-09-15.
//

#ifndef INC_453_SKELETON_DRAGONCURVE_H
#define INC_453_SKELETON_DRAGONCURVE_H

#include "Fractal_Base.h"
#include <vector>
#include "../../../util/Geometry.h"

bool alternate();

class DragonLine : public Fractal_Unit<DragonLine>
{
public:
    bool positive = true;
    DragonLine(glm::vec3 p1, glm::vec3 p2);
    void subDivide();
};

class Dragon : public Fractal_Base<DragonLine>
{
public:
    Dragon();
};


#endif //INC_453_SKELETON_DRAGONCURVE_H
