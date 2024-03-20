#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>

#include <QApplication>
#include "mainwindow.h"
#include <QtWidgets>
#include "as/gui.hpp"

namespace as
{
    int GuiTest(int argc, char* argv[])
    {
#if 1
        QApplication a(argc, argv);
        MainWindow mainwindow;
        mainwindow.show();

        // 界面开启后执行状态机初始化函数
        //as::StateMachineInterface::GetInstance().BootToIdle0();
        std::cout << "Module 'Gui' is Ready" << std::endl;
        return a.exec();
#else
        return 0;
#endif

    }
} // namespace as