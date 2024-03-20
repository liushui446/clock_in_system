#include <iostream>
#include <memory>
#include <iostream>

#include "as/camera.hpp"
#include "as/core.hpp"
#include "as/data.hpp"
#include "as/database.hpp"
#include "as/gui.hpp"
#include "as/hardware.hpp"
#include "as/imgproc.hpp"
#include "as/io.hpp"
#include "as/optimization.hpp"
#include "as/process.hpp"

void MainTest(int argc, char* argv[])
{
    std::cout << "Hello world!" << std::endl;
    as::CameraTest();
    as::CoreTest();
    as::DataTest();
    as::DataBaseTest();
    as::HardwareTest();
    as::ImgProcTest();
    as::IOTest();
    as::OptimizationTest();
    as::ProcessTest();
    as::GuiTest(argc, argv);
}

int main(int argc, char* argv[])
{
    MainTest(argc, argv);
    return 0;
}