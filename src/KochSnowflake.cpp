//
// Created by August Sosick on 2022-09-17.
//

#include "KochSnowflake.h"
#include "constants.h"


KochSnowflake::KochSnowflake() {
    auto a = glm::vec3(-0.5f, -0.5f, 0.f);
    auto b = glm::vec3(0.5f, -0.5f, 0.f);
    auto c = glm::vec3(0.f, 0.5f, 0.f);

    base_units.insert(base_units.end(), {
            KochSnowFlakeLine(a,b),
            KochSnowFlakeLine(b,c),
            KochSnowFlakeLine(c,a)
    });
}


/*
 * SnowFlakeLine
 */
KochSnowFlakeLine::KochSnowFlakeLine(glm::vec3 p1, glm::vec3 p2) {
    points.push_back(p1);
    points.push_back(p2);
}

void KochSnowFlakeLine::subDivide()
{
        glm::vec3 a,b,c,d,e;
        float distance =  glm::distance(points.at(0), points.at(1))/3;
        float dist_x = points.at(1).x - points.at(0).x;
        float dist_y = points.at(1).y - points.at(0).y;
        float horizion_angle_rad = -atan2(-dist_y, dist_x);

        a = points.at(0);

        b = glm::vec3(points.at(0).x + cos(horizion_angle_rad)*(distance), points.at(0).y + sin(horizion_angle_rad)*(distance), 0.f);

        c = glm::vec3(cos(horizion_angle_rad - SIXITY_DEG_RAD) * (distance) + b.x, sin(horizion_angle_rad - SIXITY_DEG_RAD) * (distance) + b.y, 0.f);

        d = glm::vec3(cos(horizion_angle_rad + SIXITY_DEG_RAD) * (distance) + c.x, c.y + sin(horizion_angle_rad + SIXITY_DEG_RAD)*(distance), 0.f);

        e = points.at(1);

        sub_units.insert(sub_units.end(),
                         {
                                 KochSnowFlakeLine(a, b),
                                 KochSnowFlakeLine(b, c),
                                 KochSnowFlakeLine(c, d),
                                 KochSnowFlakeLine(d, e),
                         });
}