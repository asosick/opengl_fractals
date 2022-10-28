//
// Created by August Sosick on 2022-09-15.
//

#include "DragonCurve.h"
#include "constants.h"

bool right = false;
bool alternate()
{
    if(right)
    {
        right = false;
        return right;
    }
    else
    {
        right = true;
        return right;
    }
}

DragonLine::DragonLine(glm::vec3 p1, glm::vec3 p2)
{
    points.push_back(p1);
    points.push_back(p2);
    this->positive = alternate();
}


void DragonLine::subDivide()
{
    float distance =  glm::distance(points.at(0), points.at(1));
    float dist_x = points.at(1).x - points.at(0).x;
    float dist_y = points.at(1).y - points.at(0).y;
    float horizion_angle_rad = -atan2(-dist_y, dist_x);

    glm::vec3 a = points.at(0);
    glm::vec3 b = glm::vec3(cos(horizion_angle_rad + (positive ? -RIGHT_ANGLE_RAD : RIGHT_ANGLE_RAD)) * (distance*cos(glm::radians(45.f))) + a.x,
                            sin(horizion_angle_rad + (positive ? -RIGHT_ANGLE_RAD : RIGHT_ANGLE_RAD)) * (distance*sin(glm::radians(45.f))) + a.y,
                            0.f);
    glm::vec3 c = points.at(1);

    sub_units.insert(sub_units.end(),
                     {
                             DragonLine(a,b),
                             DragonLine(b,c)
                     });
}

/* Dragon */
Dragon::Dragon()
{
    auto p1 = glm::vec3(-0.5f, 0.f, 0.f);
    auto p2 = glm::vec3(0.f, -0.5f, 0.f);
    auto p3 = glm::vec3(0.5f, 0.f, 0.f);
    base_units.insert(base_units.end(),
                 {
                         DragonLine(p1, p2),
                         DragonLine(p2, p3)
                 });
}
