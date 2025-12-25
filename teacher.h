#pragma once
#include "people.h"
#include "tool.h"

class Teacher : public People
{
public:
	Teacher();

	~Teacher();
	
	//显示老师菜单
	virtual void show_menu() override;

	//输入老师密码界面
	virtual bool enter_password() override;

	//查看全部学生的评价
	bool teacher_check_comment();

	//输入学生的编号，学号或姓名，选择是否修改评价
	bool teacher_change_comment();

	
private:
	//用姓名查询老师是否在文本文件中
	bool check_teacher_by_name(std::string check_name);

	//用工号查询老师是否在文本文件中
	bool check_teacher_by_num(std::string check_num);
protected:
	

	//通过学号查找学生
	personal_info teacher_check_student_by_num();

	//通过编号查找学生
	personal_info teacher_check_student_by_id();

	//通过姓名查找学生
	personal_info teacher_check_student_by_name();
};