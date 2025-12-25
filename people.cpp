#include "people.h"

//纯虚函数，显示菜单
void People::show_menu()
{
	std::cout << "阿米娅生日快乐!" << std::endl;
}

//纯虚函数 输入学生密码界面
bool People::enter_password()
{
	return false;
}

//修改密码
bool People::change_password()
{
	system("cls");
	std::cout << "请输入你的旧密码：" << std::endl;
	std::string password = tool_string_input();
	if (password == this->my_password)
	{
		system("cls");
		std::cout << "请输入你的新密码：" << std::endl;
		password = tool_string_input();
		std::string temp_password = password;
		system("cls");
		std::cout << "请重复输入你的新密码：" << std::endl;
		password = tool_string_input();
		if (password == temp_password)
		{
			//可以修改
			std::vector<personal_info> vpi;
			if (this->my_type == "学生")
			{
				//读取
				tool_read_infobase_student("student.txt", vpi);
				for (personal_info& pi : vpi)
				{
					if (pi.num == this->my_num)
					{
						//修改密码
						pi.password = password;

						//重新写入
						tool_write_infobase_student("student.txt", vpi);

						system("cls");
						std::cout << "修改成功！" << std::endl;
						system("pause");
						system("cls");

						return true;
					}
				}
			}
			else if (this->my_type == "老师")
			{
				//读取
				tool_read_infobase_teacher("teacher.txt", vpi);
				for (personal_info& pi : vpi)
				{
					if (pi.num == this->my_num)
					{
						//修改密码
						pi.password = password;

						//重新写入
						tool_write_infobase_teacher("teacher.txt", vpi);

						system("cls");
						std::cout << "修改成功！" << std::endl;
						system("pause");
						system("cls");

						return true;
					}
				}
			}
			else
			{
				//读取
				tool_read_infobase_teacher("admin.txt", vpi);
				for (personal_info& pi : vpi)
				{
					if (pi.num == this->my_num)
					{
						//修改密码
						pi.password = password;

						//重新写入
						tool_write_infobase_teacher("admin.txt", vpi);

						system("cls");
						std::cout << "修改成功！" << std::endl;
						system("pause");
						system("cls");

						return true;
					}
				}
			}
		}
		else
		{
			//两次输入结果不同
			system("cls");
			std::cout << "两次输入结果不同，请重试！" << std::endl;
			system("pause");
			return false;
		}
	}
	else
	{
		//旧密码错误
		system("cls");
		std::cout << "密码错误，请重试！" << std::endl;
		system("pause");
		return false;
	}
}

//退出角色
bool People::exit_character()
{
	system("cls");
	std::cout << "真的要退出吗？" << std::endl;
	std::cout << "输入y确定，输入n返回" << std::endl;
	tool_print_3_line();
	char choice = tool_char_input();

	//检查输入是否违法
	if (choice == 'z')
	{
		return false;
	}
	else
	{
		if (choice == 'y')
		{
			system("cls");
			std::cout << "退出成功！" << std::endl;
			system("pause");
			return true;
		}
		else
		{
			return false;
		}
	}
}

//输出学生列表
void People::show_student_list()
{
	//读取学生列表文件
}

//输出老师列表
void People::show_teacher_list()
{
	//读取老师列表文件
}