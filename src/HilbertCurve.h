#ifndef INC_453_SKELETON_HILBERTCURVE_H
#define INC_453_SKELETON_HILBERTCURVE_H
#include "Fractal_Base.h"

enum direction{
    UP = 0,
    DOWN = 180,
    LEFT = 270,
    RIGHT = 90
};

class HilbertCurveCup : public Fractal_Unit<HilbertCurveCup>
{
public:
    direction dir;
    float length;
    HilbertCurveCup(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, glm::vec3 p4);
    void subDivide() override;
    void hilbertY(float scale, direction dir);
};

class HilbertCurve : public Fractal_Base<HilbertCurveCup>
{
public:
    HilbertCurve();
};

#endif //INC_453_SKELETON_HILBERTCURVE_H
