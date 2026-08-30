/*
* project   : https://github.com/Robin005cr/Design_Patterns
* file name : constructor_injection.cpp
* author    : Robin CR
* mail id   : robinchovallurraju@gmail.com
* LinkedIn  : https://www.linkedin.com/in/robin-cr/
* portfolio : https://robin005cr.github.io/
*
* Note : If any mistakes, errors, or inconsistencies are found in the code, please feel free to mail me.
* Suggestions for improvements or better methods are always welcome and appreciated.
* I value constructive feedback and aim to continuously improve the quality of the work.
*
*/
#include <iostream>
#include <memory>
using namespace std;
class Renderer
{
public:
    virtual void draw() = 0;
};

class CudaRenderer : public Renderer
{
public:
    void draw()
    {
        cout << "Draw called from Cuda renderer" << endl;
    }
};

class OpenGLRenderer : public Renderer
{
public:
    void draw()
    {
        cout << "Draw called from OpenGL renderer" << endl;
    }
};

class SimulationTool
{
public:
    SimulationTool(std::shared_ptr<Renderer> ptr) : renderer(ptr)
    {
    }
    void run()
    {
        cout << "Run called" << endl;
        renderer->draw();
    }

private:
    std::shared_ptr<Renderer> renderer;
};
int main()
{
    auto renderer = std::make_shared<CudaRenderer>();
    SimulationTool vision(renderer);
    vision.run();

    return 0;
}