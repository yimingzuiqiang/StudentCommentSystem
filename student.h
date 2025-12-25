#pragma once
#include "people.h"
#include "tool.h"

class Student :public People
{
public:
	Student();
	
	~Student();
	

	//显示学生菜单
	virtual void show_menu() override;

	//输入学生密码界面
	virtual bool enter_password() override;
	
	//查看自己的评价
	bool student_check_comment();

	

	
	
private:
	//通过学号查询
	bool check_student_by_num(std::string check_num);

	//通过名字查询
	bool check_student_by_name(std::string check_name);

	std::string my_comment;
};