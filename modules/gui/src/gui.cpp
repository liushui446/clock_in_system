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

		//MainWindow mainwindow;
		//mainwindow.show();

        if (!InitParam())
        {
            // todo: 返回错误或是弹框
        }

        LoadDialog appTest;
        appTest.show();

        return app.exec();
#else
        return 0;
#endif
    }
} // namespace as