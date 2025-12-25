#include "system.h"

//静态变量类外声明
StudentCommentSystem StudentCommentSystem::my_instance;

//显示主菜单
void StudentCommentSystem::system_main_menu()
{
	using namespace std;
	system("cls");

	cout << "*************学生评教管理系统***************\n" << endl;
	cout << "** 请选择你的角色：                          \n" << endl;
	cout << "1. 管理员\n" << endl;
	cout << "2. 老师\n" << endl;
	cout << "3. 学生\n" << endl;
	cout << "4. 退出系统\n" << endl;
	cout << "*************学生评教管理系统***************\n" << endl;
}

//退出系统
void StudentCommentSystem::system_exit()
{
	system("cls");
	std::cout << "真的要退出吗？" << std::endl;
	std::cout << "输入y确定，输入n返回" << std::endl;
	tool_print_3_line();
	char choice = tool_char_input();
	
	//检查输入是否违法
	if (choice == 'z')
	{
		return;
	}
	else
	{
		if (choice == 'y')
		{
			system("cls");
			std::cout << "ヾ(·ω·`)o拜拜" << std::endl;
			system("pause");
			exit(0);
		}
		else
		{
			return;
		}
	}
	
}


//进入学生界面
void StudentCommentSystem::system_enter_student()
{
	system("cls");
	Student* a_student = new Student;
	

	//密码输入
	if (a_student->enter_password())
	{
		a_student->show_menu();
	}
	else
	{
		system("cls");
		std::cout << "登录失败！" << std::endl;
		system("pause");
		return;
	}

	delete a_student;
	a_student = nullptr;

	return;
}

//进入老师界面
void StudentCommentSystem::system_enter_teacher()
{
	system("cls");
	Teacher* a_teacher = new Teacher;

	//密码输入
	if (a_teacher->enter_password())
	{
		a_teacher->show_menu();
	}
	else
	{
		system("cls");
		std::cout << "登录失败！" << std::endl;
		system("pause");
		return;
	}

	delete a_teacher;
	a_teacher = nullptr;

	return;
}

//进入管理员界面
void StudentCommentSystem::system_enter_admin()
{
	system("cls");
	Admin* a_administrator = new Admin;

	//密码输入
	if (a_administrator->enter_password())
	{
		a_administrator->show_menu();
	}
	else
	{
		system("cls");
		std::cout << "登录失败！" << std::endl;
		system("pause");
		return;
	}

	delete a_administrator;
	a_administrator = nullptr;

	return;
}

//获取单例的指针
StudentCommentSystem* StudentCommentSystem::system_get_instance()
{
	return &my_instance;
}

StudentCommentSystem::StudentCommentSystem()
{
	std::cout << " 学生评价系统启动中..." << std::endl;
	std::cout << "||---------------------||" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	system("cls");
	std::cout << " 学生评价系统启动中..." << std::endl;
	std::cout << "||#--------------------||" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	system("cls");
	std::cout << " 学生评价系统启动中..." << std::endl;
	std::cout << "||###------------------||" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	system("cls");
	std::cout << " 学生评价系统启动中..." << std::endl;
	std::cout << "||#########------------||" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	system("cls");
	std::cout << " 学生评价系统启动中..." << std::endl;
	std::cout << "||#################----||" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	system("cls");
	std::cout << " 学生评价系统启动中..." << std::endl;
	std::cout << "||###################--||" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	system("cls");
	std::cout << " 学生评价系统启动中..." << std::endl;
	std::cout << "||#####################||" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	system("cls");
}

StudentCommentSystem::~StudentCommentSystem()
{
	std::cout << "学生评价系统关闭成功！" << std::endl;
}
