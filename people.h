#pragma once
#include <iostream>
#include "tool.h"

class People
{
public:
	People()
	{

	}
	~People()
	{

	}

	//纯虚函数，显示菜单
	virtual void show_menu();
	//纯虚函数，输入密码
	virtual bool enter_password();
	//输出学生列表
	void show_student_list();
	//输出老师列表
	void show_teacher_list();
	//修改密码
	virtual bool change_password();
	//退出角色
	virtual bool exit_character();
protected:
	//编号
	int my_id = 0;
	//名字
	std::string my_name = "null";
	//学号或工号
	std::string my_num = "0";
	//密码
	std::string my_password = "0";
	//类别
	std::string my_type = "null";
};