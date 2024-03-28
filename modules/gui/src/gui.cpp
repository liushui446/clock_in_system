#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <corecrt_io.h>
#include <filesystem>
#include <codecvt>
#include <string>
#include <fstream>
#include <iostream>
#include <functional>
#include <comutil.h> 

#include <QApplication>
#include "mainwindow.h"
#include <QtWidgets>

#include "LoadDialog.h"
#include "src/module/server/TcpServerDialog.h"

#include "as/gui.hpp"
#include "as/io.hpp"


namespace
{
    bool InitParam()
    {
        return true;
    }

    bool OpenTestOffLineWidget()
    {
		// 获取当前路径并查找切割process
		std::wstring current_path = std::filesystem::current_path();
		std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
		string fileName = converter.to_bytes(current_path);
		int pos = fileName.find("build");
		fileName.erase(pos);
		fileName += "inifile\\CommonConfig.ini";

        as::IniFile loginifile;
        loginifile.SetIniFilePath(fileName);
        return (atoi(loginifile.ReadIniContent("OperationMode", "IsAlgTestOffLine", "0").c_str()) == 1);
    }
}

namespace as
{
    int GuiTest(int argc, char* argv[])
    {
        std::cout << "Module 'Gui' is Ready" << std::endl;
        return 0;
    }

    int RunGUI(int argc, char* argv[])
    {
#if 1
        QApplication app(argc, argv);

        if (!InitParam())
        {
            // todo: 返回错误或是弹框
        }

        /*TcpServerDialog serverdialog;
        serverdialog.setWindowTitle(QString::fromLocal8Bit("Server"));
        serverdialog.show();*/
        MainWindow mainwindow_1;
        ////MainWindow mainwindow_2;
        LoadDialog appTest_1;
        ////LoadDialog appTest_2;
        //appTest_1.setWindowTitle(QString::fromLocal8Bit("Take Leave System"));
        if (appTest_1.exec() == QDialog::Accepted)
        {
            mainwindow_1.SetAuthority(appTest_1.GetUsername(), appTest_1.GetUserType());
            mainwindow_1.SetSocket(appTest_1.GetSocket());
            mainwindow_1.ShowUserNa();
            mainwindow_1.show();
        }

        /*if (appTest_2.exec() == QDialog::Accepted)
        {
            mainwindow_2.SetAuthority(appTest_2.GetUsername(), appTest_2.GetUserType());
            mainwindow_2.SetSocket(appTest_2.GetSocket());
            mainwindow_2.ShowUserNa();
            mainwindow_2.show();
        }*/   

        return app.exec();
#else
        return 0;
#endif
    }
} // namespace as