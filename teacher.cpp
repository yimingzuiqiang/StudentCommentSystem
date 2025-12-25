#include "teacher.h"

Teacher::Teacher()
{
	this->my_type = "老师";
}

Teacher::~Teacher()
{

}

//用姓名查询老师是否在文本文件中
bool Teacher::check_teacher_by_name(std::string check_name)
{
	std::ifstream infile("teacher.txt");
	if (!infile.is_open())
	{
		system("cls");
		std::cout << "teacher.txt打开失败！请联系管理员修复系统！" << std::endl;
		system("pause");
		return false;
	}

	int id = 0;
	std::string name;
	std::string num;
	std::string password;

	//跳过空格/换行，按「编号 名字 学号 密码」顺序提取
	while (infile >> id >> name >> num >> password)
	{
		if (check_name == name)
		{
			system("cls");
			std::cout << "查询成功，信息如下：" << std::endl;
			tool_print_3_line();
			std::cout << id << " " << name << " " << num << "\n" << std::endl;
			system("pause");

			this->my_id = id;
			this->my_name = name;
			this->my_num = num;
			this->my_password = password;

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

//用工号查询老师是否在文本文件中
bool Teacher::check_teacher_by_num(std::string check_num)
{
	std::ifstream infile("teacher.txt");
	if (!infile.is_open())
	{
		system("cls");
		std::cout << "teacher.txt打开失败！请联系管理员修复系统！" << std::endl;
		system("pause");
		return false;
	}

	int id = 0;
	std::string name;
	std::string num;
	std::string password;

	//跳过空格/换行，按「编号 名字 学号 密码」顺序提取
	while (infile >> id >> name >> num >> password)
	{
		if (check_num == num)
		{
			system("cls");
			std::cout << "查询成功，信息如下：" << std::endl;
			tool_print_3_line();
			std::cout << id << " " << name << " " << num << "\n" << std::endl;
			system("pause");

			this->my_id = id;
			this->my_name = name;
			this->my_num = num;
			this->my_password = password;

			infile.close();
			return true;
		}
	}

	//没有
	system("cls");
	std::cout << "未查询到该工号" << std::endl;
	system("pause");

	infile.close();
	return false;
}

//老师的菜单
void Teacher::show_menu()
{
	using namespace std;
	while (true)
	{
		system("cls");
		cout << "*************学生评教管理系统***************\n" << endl;
		cout << "** 老师:" << this->my_name << "\n" << endl;
		cout << "1. 查看对学生的评价\n" << endl;
		cout << "2. 修改对学生的评价\n" << endl;
		cout << "3. 修改密码\n" << endl;
		cout << "4. 退出老师角色\n" << endl;
		cout << "*************学生评教管理系统***************\n" << endl;

		int choice = 0;

		choice = tool_num_input();

		switch (choice)
		{
		case 1:
			this->teacher_check_comment();
			break;
		case 2:
			this->teacher_change_comment();
			break;
		case 3:
			this->change_password();
			break;
		case 4:
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

//输入老师密码界面
bool Teacher::enter_password()
{
	using namespace std;
	system("cls");

	cout << "** 请输入你的工号(10位)：                          " << endl;

	std::string account;
	std::string password;

	account = tool_string_input();

	//遍历老师列表,查找是否有这个工号
	if (check_teacher_by_num(account) == false)
	{
		return false;
	}

	//输入密码
	system("cls");
	cout << "你好，" << this->my_name << "老师" << std::endl;
	cout << "工号：" << this->my_num << std::endl;
	cout << "** 请输入您的密码：                          " << endl;

	if (tool_string_input() == this->my_password)
	{
		//进入老师菜单
		system("cls");
		std::cout << "登录成功！" << std::endl;
		system("pause");
		return true;
	}
	return false;
}

//查看全部学生的评价
bool Teacher::teacher_check_comment()
{
	std::ifstream infile("student.txt");
	if (!infile.is_open())
	{
		system("cls");
		std::cout << "teacher.txt打开失败！请联系管理员修复系统！" << std::endl;
		system("pause");
		return false;
	}

	if (tool_check_txt_is_clean("student.txt"))
	{
		//文件为空
		system("cls");
		std::cout << "学生库为空" << std::endl;
		system("pause");
		return true;
	}

	//临时打印变量
	int id;
	std::string name;
	std::string num;
	std::string password;
	std::string comment;
	system("cls");
	while (infile >> id >> name >> num >> password >> comment)
	{
		std::cout << id << " " << name << " " << num << " " << comment << std::endl;
	}
	system("pause");

	infile.close();
	return true;
}

//通过编号查找学生
personal_info Teacher::teacher_check_student_by_id()
{
	//待返回的信息
	personal_info the_student;
	the_student.id = 0;
	the_student.name = "null";
	the_student.num = "null";
	the_student.password = "null";
	the_student.comment = "null";

	system("cls");
	std::cout << "请输入要查找学生的编号：" << std::endl;
	int target_id = tool_num_input();

	std::ifstream infile("student.txt");
	if (!infile.is_open())
	{
		system("cls");
		std::cout << "student.txt打开失败！请联系管理员修复系统！" << std::endl;
		system("pause");
		return the_student;
	}

	int id = 0;
	std::string name;
	std::string num;
	std::string password;
	std::string comment;

	//跳过空格/换行，按「编号 名字 学号 密码」顺序提取
	while (infile >> id >> name >> num >> password >> comment)
	{
		if (target_id == id)
		{
			system("cls");
			std::cout << "查询成功!" << std::endl;
			system("pause");

			the_student.id = id;
			the_student.name = name;
			the_student.num = num;
			the_student.comment = comment;

			infile.close();
			return the_student;
		}
	}

	//没有
	system("cls");
	std::cout << "未查询到该编号" << std::endl;
	system("pause");

	infile.close();
	return the_student;
}

//通过姓名查找学生
personal_info Teacher::teacher_check_student_by_name()
{
	//待返回的信息
	personal_info the_student;
	the_student.id = 0;
	the_student.name = "null";
	the_student.num = "null";
	the_student.password = "null";
	the_student.comment = "null";

	system("cls");
	std::cout << "请输入要查找学生的姓名：" << std::endl;
	std::string target_name = tool_string_input();

	std::ifstream infile("student.txt");
	if (!infile.is_open())
	{
		system("cls");
		std::cout << "student.txt打开失败！请联系管理员修复系统！" << std::endl;
		system("pause");
		return the_student;
	}

	int id = 0;
	std::string name;
	std::string num;
	std::string password;
	std::string comment;

	//跳过空格/换行，按「编号 名字 学号 密码」顺序提取
	while (infile >> id >> name >> num >> password >> comment)
	{
		if (target_name == name)
		{
			system("cls");
			std::cout << "查询成功!" << std::endl;
			system("pause");

			the_student.id = id;
			the_student.name = name;
			the_student.num = num;
			the_student.comment = comment;

			infile.close();
			return the_student;
		}
	}

	//没有
	system("cls");
	std::cout << "未查询到该姓名" << std::endl;
	system("pause");

	infile.close();
	return the_student;
}

//通过学号查找学生
personal_info Teacher::teacher_check_student_by_num()
{
	//待返回的信息
	personal_info the_student;
	the_student.id = 0;
	the_student.name = "null";
	the_student.num = "null";
	the_student.password = "null";
	the_student.comment = "null";

	system("cls");
	std::cout << "请输入要查找学生的学号：" << std::endl;
	std::string target_num = tool_string_input();

	std::ifstream infile("student.txt");
	if (!infile.is_open())
	{
		system("cls");
		std::cout << "student.txt打开失败！请联系管理员修复系统！" << std::endl;
		system("pause");
		return the_student;
	}

	int id = 0;
	std::string name;
	std::string num;
	std::string password;
	std::string comment;

	//跳过空格/换行，按「编号 名字 学号 密码」顺序提取
	while (infile >> id >> name >> num >> password >> comment)
	{
		if (target_num == num)
		{
			system("cls");
			std::cout << "查询成功!" << std::endl;
			system("pause");

			the_student.id = id;
			the_student.name = name;
			the_student.num = num;
			the_student.comment = comment;

			infile.close();
			return the_student;
		}
	}

	//没有
	system("cls");
	std::cout << "未查询到该学号" << std::endl;
	system("pause");

	infile.close();
	return the_student;
}

//输入学生的编号，学号或姓名，选择是否修改评价
bool Teacher::teacher_change_comment()
{
	system("cls");
	//选择查找方式：编号，学号，姓名
	std::cout << "请选择查找方式：（1-编号，2-学号，3-姓名）" << std::endl;
	int choice = tool_num_input();

	//存储待修改学生的数据
	personal_info the_student;

	switch (choice)
	{
	case 1:
		the_student = this->teacher_check_student_by_id();
		break;
	case 2:
		the_student = this->teacher_check_student_by_num();
		break;
	case 3:
		the_student = this->teacher_check_student_by_name();
		break;
	default:
		{
			system("cls");
			std::cout << "超出范围了！" << std::endl;
			system("pause");
			system("cls");
			return false;
		}
	}

	if (the_student.name == "null")
	{
		//没找到
		system("cls");
		return false;
	}

	//查看具体内容
	system("cls");
	std::cout << "选中学生：" << std::endl;
	std::cout << the_student.id << " " << the_student.name << " " 
		<< the_student.num << " " << the_student.comment << std::endl;
	tool_print_3_line();
	//选择是否修改
	std::cout << "是否要修改？（1-是，2-不）:" << std::endl;
	int change_choice = tool_num_input();
	if (change_choice == 1)
	{
		std::cout << "\n请输入修改后的评价：" << std::endl;
		std::string new_comment = tool_string_input();

		the_student.comment = new_comment;

		std::vector<personal_info> whole_data;
		tool_read_infobase_student("student.txt", whole_data);
		//修改那个学生的评价
		for (auto& stu : whole_data)
		{
			if (stu.num == the_student.num)
			{
				stu.comment = the_student.comment;
			}
		}

		//放回数据库
		tool_write_infobase_student("student.txt", whole_data);

		system("cls");
		std::cout << "修改完成！" << std::endl;
		system("pause");
		return true;
	}
	else if (change_choice == 2)
	{
		system("cls");
		return false;
	}
	else
	{
		system("cls");
		std::cout << "输入非法，请重试！" << std::endl;
		system("pause");
		system("cls");
		return false;
	}
	return false;
}