#include <GL/glew.h>
#include "GLFW/glfw3.h"

#include "../util/Geometry.h"
#include "../util/GLDebug.h"
#include "../util/Log.h"
#include "../util/ShaderProgram.h"
#include "../util/Window.h"

#include "Fractal_Base.h"
#include "DragonCurve.h"
#include "KochSnowflake.h"
#include "UniformMassTriangle.h"
#include "SierpinskiTriangle.h"
#include "Fractal.h"

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"


Dragon dragon;
KochSnowflake kochSnowflake;
UniformMassTriangle uniformMassTriangle;
SierpinskiTriangle sierpinskiTriangle;
std::vector<Fractal*> a = {&dragon, &kochSnowflake, &uniformMassTriangle, &sierpinskiTriangle};

int fractal_index;


int main() {
    Log::debug("Starting main");

    // WINDOW
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac

    Window window(800, 800, "Fractals"); // can set callbacks at construction if desired
    GLDebug::enable();

    //ImGUI
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableSetMousePos;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window.window.get(), true);
    ImGui_ImplOpenGL3_Init("#version 150");

    // SHADERS
    ShaderProgram shader("shaders/test.vert", "shaders/test.frag");

    // GEOMETRY
    CPU_Geometry cpuGeom;
    GPU_Geometry gpuGeom;

    // vertices
    gpuGeom.setVerts(cpuGeom.verts);
    gpuGeom.setCols(cpuGeom.cols);

    ImVec4 color = ImVec4(0.90f, 0.20f, 0.75f, 1.00f);
    // RENDER LOOP
    while (!window.shouldClose()) {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::SetNextFrameWantCaptureKeyboard(false);

        if(ImGui::IsKeyPressed(ImGuiKey_R))
            a.at(fractal_index)->recurse();
        else if(ImGui::IsKeyPressed(ImGuiKey_D))
            a.at(fractal_index)->derecurse();
        else if(ImGui::IsKeyPressed(ImGuiKey_S))
            fractal_index = ++fractal_index % 4;

        {
            ImGui::Begin("Fractal Navigator");

            ImGui::Text("Please select the fractal you want to display (or use the S-Key to switch)");
            if(ImGui::Button("Dragon"))
                fractal_index = 0;
            ImGui::SameLine();
            if(ImGui::Button("Koch Snowflake"))
                fractal_index = 1;
            ImGui::SameLine();
            if(ImGui::Button("Uniform Mass Triangle"))
                fractal_index = 2;
            ImGui::SameLine();
            if(ImGui::Button("Sierpinski Triangle"))
                fractal_index = 3;

            if (ImGui::Button("Recurse (R-Key)"))
                a.at(fractal_index)->recurse();
            ImGui::SameLine();
            if (ImGui::Button("De-recurse (D-Key)"))
                a.at(fractal_index)->derecurse();

            ImGui::End();
        }

        cpuGeom.verts.clear();
        cpuGeom.cols.clear();
        std::vector<glm::vec3> verticies = a.at(fractal_index)->convertToVerticies();
        glm::vec3 colour = glm::vec3(1.f,0.f,0.f);
        int i = 0;
        int modulo = fractal_index == 3 ? 3 : 2;
        for(const auto& vertex: verticies) {
            cpuGeom.verts.push_back(vertex);
            if(i%modulo==0){
                float r = std::abs(vertex.x);
                float g = std::abs(vertex.y);
                float b = std::abs(vertex.z);
                if(r+g+b < 0.01)
                    colour = glm::vec3(0.1f,0,0);
                else
                    colour = glm::vec3(r,g,b);
            }
            cpuGeom.cols.push_back(colour);
            ++i;
        }

        gpuGeom.setVerts(cpuGeom.verts);
        gpuGeom.setCols(cpuGeom.cols);

        shader.use();
        gpuGeom.bind();

        glEnable(GL_FRAMEBUFFER_SRGB);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if(fractal_index == 3)
            glDrawArrays(GL_TRIANGLES, 0, verticies.size());
        else
            glDrawArrays(GL_LINES, 0, verticies.size());
        glDisable(GL_FRAMEBUFFER_SRGB); // disable sRGB for things like imgui

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        window.swapBuffers();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
    return 0;
}

