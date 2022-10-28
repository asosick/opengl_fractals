//
// Created by August Sosick on 2022-09-17.
//

#ifndef INC_453_SKELETON_FRACTAL_H
#define INC_453_SKELETON_FRACTAL_H
#include "../../../util/Geometry.h"

class Fractal
{
public:

    virtual void recurse() = 0;
    virtual void derecurse() = 0;

    virtual std::vector<glm::vec3> convertToVerticies() = 0;
};

#endif //INC_453_SKELETON_FRACTAL_H
