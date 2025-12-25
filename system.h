#pragma once
#include <iostream>
#include <thread>
#include "tool.h"
#include "student.h"
#include "teacher.h"
#include "admin.h"
#include <string>

//单例模式
class StudentCommentSystem
{
public:
	//获取单例的指针
	static StudentCommentSystem* system_get_instance();

	//单例模式，禁用拷贝和赋值
	StudentCommentSystem(const StudentCommentSystem& other) = delete;
	StudentCommentSystem& operator=(const StudentCommentSystem& other) = delete;

	//显示主菜单
	void system_main_menu();

	//退出系统
	void system_exit();

	//进入学生界面
	void system_enter_student();

	//进入老师界面
	void system_enter_teacher();

	//进入管理员界面
	void system_enter_admin();

private:
	StudentCommentSystem();
	~StudentCommentSystem();
	//静态变量初始化时创建，饿汉式
	static StudentCommentSystem my_instance;

	////学生
	//Student* my_student = nullptr;
	////老师
	//Teacher* my_teacher = nullptr;
	////管理员
	//Admin* my_admin = nullptr;
};