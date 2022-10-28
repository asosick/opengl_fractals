//
// Created by August Sosick on 2022-09-17.
//

#ifndef INC_453_SKELETON_KOCHSNOWFLAKE_H
#define INC_453_SKELETON_KOCHSNOWFLAKE_H
#include "Fractal_Base.h"

class KochSnowFlakeLine : public Fractal_Unit<KochSnowFlakeLine> {
public:
    KochSnowFlakeLine(glm::vec3 p1, glm::vec3 p2);
    void subDivide();
};

class KochSnowflake : public Fractal_Base<KochSnowFlakeLine>
{
public:
    KochSnowflake();
};
#endif //INC_453_SKELETON_KOCHSNOWFLAKE_H
