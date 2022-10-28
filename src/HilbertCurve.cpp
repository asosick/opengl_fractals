#include "HilbertCurve.h"

//HilbertCurveCup::HilbertCurveLine(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, glm::vec3 p4, glm::vec3 p5)
//{
//
//
//}\

//HilbertCurveCup::HilbertCurveCup(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, glm::vec3 p4)
//{
//    points.push_back(p1);
//    points.push_back(p2);
//    points.push_back(p3);
//    points.push_back(p4);
//
//    length = 1;
////    boundary_space.first = glm::vec3(-1.f,-1.f, 0.f);
////    boundary_space.second = glm::vec3(1.f,1.f, 0.f);
//}
//
//void HilbertCurveCup::hilbertY(float scale, direction dir)
//{
//        float length = 1;
//        std::vector<glm::vec3> hilbertY;
//        float travel = length * scale;
//        glm::vec3 origin = glm::vec3(0,0,0);
//
//        float x_flips = 1;
//        float y_flips = 1;
//
//
//        glm::vec3 h1_p1 = glm::vec3(origin.x - (length / (2*scale)), origin.y - (length / (2*scale)), 0.f);
//        glm::vec3 h1_p2 = glm::vec3(origin.x - (length / (4*scale)), origin.y - (length / (4*scale)), 0.f);
//        glm::vec3 h1_p3 = glm::vec3(origin.x - (length / (4*scale)), origin.y, 0.f);
//        glm::vec3 h1_p4 = glm::vec3(origin.x - (length / (2*scale)), origin.y, 0.f);
//        HilbertCurveCup bottom_l = HilbertCurveCup(h1_p1, h1_p2, h1_p3, h1_p4);
//
//        glm::vec3 h2_p1 = glm::vec3(origin.x - (length / (2*scale)), origin.y + (length / (4*scale)), 0.f);
//        glm::vec3 h2_p2 = glm::vec3(origin.x - (length / (2*scale)), origin.y + (length / (2*scale)), 0.f);
//        glm::vec3 h2_p3 = glm::vec3(origin.x - (length / (4*scale)), origin.y + (length / (2*scale)), 0.f);
//        glm::vec3 h2_p4 = glm::vec3(origin.x - (length / (4*scale)), origin.y + (length / (4*scale)), 0.f);
//        HilbertCurveCup top_l = HilbertCurveCup(h1_p1, h1_p2, h1_p3, h1_p4);
//
//        glm::vec3 h3_p1 = glm::vec3(origin.x + (length / (4*scale)), origin.y + (length / (4*scale)), 0.f);
//        glm::vec3 h3_p2 = glm::vec3(origin.x + (length / (4*scale)), origin.y + (length / (2*scale)), 0.f);
//        glm::vec3 h3_p3 = glm::vec3(origin.x + (length / (2*scale)), origin.y + (length / (2*scale)), 0.f);
//        glm::vec3 h3_p4 = glm::vec3(origin.x + (length / (2*scale)), origin.y + (length / (4*scale)), 0.f);
//        HilbertCurveCup top_r = HilbertCurveCup(h1_p1, h1_p2, h1_p3, h1_p4);
//
//        glm::vec3 h4_p1 = glm::vec3(origin.x + (length / (2*scale)), origin.y, 0.f);
//        glm::vec3 h4_p2 = glm::vec3(origin.x + (length / (4*scale)), origin.y, 0.f);
//        glm::vec3 h4_p3 = glm::vec3(origin.x + (length / (4*scale)), origin.y - (length / (4*scale)), 0.f);
//        glm::vec3 h4_p4 = glm::vec3(origin.x + (length / (2*scale)), origin.y - (length / (2*scale)), 0.f);
//        HilbertCurveCup bottom_r = HilbertCurveCup(h1_p1, h1_p2, h1_p3, h1_p4);
//        //sub_units.push_back(bottom_l, top_l, top_r, bottom_r);
//}
//
//
//void HilbertCurveCup::subDivide()
//{
//    //std::vector<glm::vec3> division_of_boundary_space;
//    std::vector<glm::vec3> sub_verticies;
//
//    for(const glm::vec3 point : points)
//    {
//        glm::vec3 top_r = glm::vec3(point.x + length/8, point.y + length/8, 0.f);
//        glm::vec3 bottom_r = glm::vec3(point.x + length/8, point.y - length/8, 0.f);
//        glm::vec3 top_l = glm::vec3(point.x - length/8, point.y + length/8, 0.f);
//        glm::vec3 bottom_l = glm::vec3(point.x - length/8, point.y - length/8, 0.f);
//
//
//    }
//
//    switch(dir)
//    {
//        /*
//         * U => Ↄ ↓ U → U ↑ C
//         * D => C ↑ n <- n ↓ Ↄ
//         * L => U -> Ↄ ↓ Ↄ <-
//         * R => n <- C ↑ C -> U
//         */
//        case UP:
//            break;
//        case DOWN:
//            break;
//        case LEFT:
//            break;
//        case RIGHT:
//            break;
//    }
//}
//
//
//HilbertCurve::HilbertCurve()
//{
//    base_units.push_back(HilbertCurveCup());
//}
