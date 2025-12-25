#include "student.h"

Student::Student()
{
	this->my_type = "学生";
}

Student::~Student()
{

}

//显示学生菜单
void Student::show_menu() 
{
	using namespace std;
	system("cls");
	while (true)
	{
		cout << "*************学生评教管理系统***************\n" << endl;
		cout << "** 学生:" << this->my_name << "\n" << endl;
		cout << "1. 查看自己评价\n" << endl;
		cout << "2. 修改密码\n" << endl;
		cout << "3. 退出学生角色\n" << endl;
		cout << "*************学生评教管理系统***************\n" << endl;

		int choice = 0;

		choice = tool_num_input();

		switch (choice)
		{
		case 1:
			this->student_check_comment();
			break;
		case 2:
			this->change_password();
			break;
		case 3:
		{
			if (this->exit_character())
			{
				return;
			}
			break;
		}

		default:
			system("cls");
			continue;
		}
	}
}

//用姓名查询学生是否在文本文件中
bool Student::check_student_by_name(std::string check_name)
{
	std::ifstream infile("student.txt");
	if (!infile.is_open())
	{
		system("cls");
		std::cout << "student.txt打开失败！请联系管理员修复系统！" << std::endl;
		system("pause");
		return false;
	}

	int id = 0;
	std::string name;
	std::string num;
	std::string password;
	std::string comment;

	//跳过空格/换行，按「编号 名字 学号 密码」顺序提取
	while (infile >> id >> name >> num >> password >> comment)
	{
		if (check_name == name)
		{
			system("cls");
			std::cout << "查询成功，信息如下：" << std::endl;
			tool_print_3_line();
			std::cout << id << " " << name << " " << num << std::endl;
			system("pause");

			this->my_id = id;
			this->my_name = name;
			this->my_num = num;
			this->my_password = password;
			this->my_comment = comment;

			infile.close();
			return true;
		}
	}

	//没有
	system("cls");
	std::cout << "未查询到该人名" << std::endl;
	system("pause");

	infile.close();
	return false;
}

//用学号查询学生是否在文本文件中
bool Student::check_student_by_num(std::string check_num)
{
	std::ifstream infile("student.txt");
	if (!infile.is_open())
	{
		system("cls");
		std::cout << "student.txt打开失败！请联系管理员修复系统！" << std::endl;
		system("pause");
		return false;
	}

	int id = 0;
	std::string name;
	std::string num;
	std::string password;
	std::string comment;

	//跳过空格/换行，按「编号 名字 学号 密码」顺序提取
	while (infile >> id >> name >> num >> password >> comment)
	{
		if (check_num == num)
		{
			system("cls");
			std::cout << "查询成功，信息如下：" << std::endl;
			tool_print_3_line();
			std::cout << id << " " << name << " " << num << "\n" << std::endl;
			this->my_id = id;
			this->my_name = name;
			this->my_num = num;
			this->my_password = password;
			this->my_comment = comment;
			system("pause");

			infile.close();
			return true;
		}
	}

	//没有
	system("cls");
	std::cout << "未查询到该学号" << std::endl;
	system("pause");

	infile.close();
	return false;
}

//输入学生密码界面
bool Student::enter_password()
{
	using namespace std;
	system("cls");

	cout << "** 请输入你的学号(10位)：                          " << endl;

	std::string account;
	std::string password;

	account = tool_string_input();

	//遍历学生列表,查找是否有这个学号
	if (check_student_by_num(account) == false)
	{
		return false;
	}
	
	//输入密码
	system("cls");
	cout << "你好，" << this->my_name << std::endl;
	cout << "学号：" << this->my_num << std::endl;
	cout << "** 请输入你的密码：                          " << endl;

	if (tool_string_input() == this->my_password)
	{
		//进入学生菜单
		system("cls");
		std::cout << "登录成功！" << std::endl;
		system("pause");
		return true;
	}
	return false;
}

//查看自己的评价
bool Student::student_check_comment()
{
	system("cls");
	
	std::cout << this->my_num << " " << this->my_name << " 评价如下：" << std::endl;
	std::cout << this->my_comment << std::endl;

	system("pause");
	system("cls");

	return true;
}



