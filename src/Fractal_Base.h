#ifndef INC_453_SKELETON_FRACTAL_BASE_H
#define INC_453_SKELETON_FRACTAL_BASE_H

#include <vector>
#include "Fractal.h"
#include "../../../util/Geometry.h"

template<class T>
class Fractal_Unit
{
public:
    std::vector<T> sub_units;
    std::vector<glm::vec3> points;

    virtual void leafNodeVerticies(T& unit, std::vector<glm::vec3>& vec)
    {
        if(unit.sub_units.empty())
            vec.insert(vec.end(), unit.points.begin(), unit.points.end());
        else
            for(auto& u: unit.sub_units)
                leafNodeVerticies(u, vec);
    }
    virtual void subDivide() = 0;
};

template<class T>
class Fractal_Base : public Fractal
{
public:
    std::vector<T> base_units;
    std::vector<glm::vec3> convertToVerticies()
    {
        std::vector<glm::vec3> ret;
        for(T& u : base_units)
        {
            u.leafNodeVerticies(u, ret);
        }
        return ret;

    }

    void recurse()
    {
        for(auto& base_unit : base_units)
            recursiveSubDivide(base_unit);
    }
    void derecurse()
    {
        for(auto& base_unit : base_units)
            derecurseSubDivision(base_unit, base_unit);
    }

    void recursiveSubDivide(T& unit)
    {
        if(unit.sub_units.empty())
            unit.subDivide();
        else
            for(auto& u: unit.sub_units)
                recursiveSubDivide(u);
    }
    void derecurseSubDivision(T& unit, T& previous)
    {
        if(unit.sub_units.empty())
            previous.sub_units.clear();
        else
            for(auto& u: unit.sub_units)
                derecurseSubDivision(u, unit);
    }
};

#endif //INC_453_SKELETON_FRACTAL_BASE_H
