//__declspec(dllexport)修饰符指示编译器和链接器从 
//DLL 导出函数或变量，以便其他应用程序可以使用它，在insect.h

#pragma once

#ifndef INSECT_H

#define INSECT_H

#define EXPORTDLL_API __declspec(dllexport)

//导出的类
class EXPORTDLL_API testD {

};

//也可用下列方法定义导出函数
//extern "C" EXPORTDLL_API int add(int ,int );

#endif // !INSECT_H
