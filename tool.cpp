#include "tool.h"


//空格3行
void tool_print_3_line()
{
	std::cout << "\n\n" << std::endl;
}

//输入(有bug)
//template<typename T>
//T& tool_input(const T& input_choice)
//{
//	std::cin >> input_choice;
//	if (std::cin.fail()) //非法输入
//	{
//		//清除错误状态
//		std::cin.clear();
//
//		//清除错误输入
//		std::cin.ignore(std::numeric_limits<std::streamsize>::std::max(), '\n');
//
//		system("cls");
//		std::cout << "输入违法！请重新输入！" << std::endl;
//		system("pause");
//
//		return (T)(-1);
//	}
//	else
//	{
//		return input_choice;
//	}
//}

//数字输入
int tool_num_input()
{
	int choice = -1;
	std::cin >> choice;
	if (std::cin.fail()) //非法输入
	{
		//清除错误状态
		std::cin.clear();

		//清除错误输入
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		system("cls");
		std::cout << "输入违法！请重新输入！" << std::endl;
		system("pause");

		return (-1);
	}
	else
	{
		return choice;
	}
}

//字符串输入
std::string tool_string_input()
{
	std::string choice = "null";
	std::cin >> choice;
	if (std::cin.fail()) //非法输入
	{
		//清除错误状态
		std::cin.clear();

		//清除错误输入
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		system("cls");
		std::cout << "输入违法！请重新输入！" << std::endl;
		system("pause");

		return "null";
	}
	else
	{
		return choice;
	}
}

//字符输入
char tool_char_input()
{
	char choice = 'z';
	std::cin >> choice;
	if (std::cin.fail()) //非法输入
	{
		//清除错误状态
		std::cin.clear();

		//清除错误输入
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		system("cls");
		std::cout << "输入违法！请重新输入！" << std::endl;
		system("pause");

		return 'z';
	}
	else
	{
		return choice;
	}
}

//将密码库内容完整读取
void tool_read_infobase_student(std::string file_path, std::vector<personal_info>& infos)
{
	std::ifstream infile(file_path);
	if (!infile.is_open())
	{
		system("cls");
		std::cout << file_path << "打开失败！请联系管理员修复系统！" << std::endl;
		system("pause");
		return;
	}
	personal_info pi;
	while (infile >> pi.id >> pi.name >> pi.num >> pi.password >> pi.comment)
	{
		infos.push_back(pi);
	}
	infile.close();
	return;
}

//将密码库内容完整写入
void tool_write_infobase_student(std::string file_path, std::vector<personal_info>& infos)
{
	std::ofstream outfile(file_path, std::ios::out);

	if (!outfile.is_open())
	{
		system("cls");
		std::cout << file_path << "打开失败！请联系管理员修复系统！" << std::endl;
		system("pause");
		return;
	}
	for (personal_info& info : infos)
	{
		outfile << info.id << " " << info.name << " "
			<< info.num << " " << info.password << " " << info.comment << std::endl;
	}
	outfile.close();
	return;
}

//将密码库内容完整读取（老师与管理员）
void tool_read_infobase_teacher(std::string file_path, std::vector<personal_info>& infos)
{
	std::ifstream infile(file_path);
	if (!infile.is_open())
	{
		system("cls");
		std::cout << file_path << "打开失败！请联系管理员修复系统！" << std::endl;
		system("pause");
		return;
	}
	personal_info pi;
	while (infile >> pi.id >> pi.name >> pi.num >> pi.password)
	{
		infos.push_back(pi);
	}
	infile.close();
	return;
}

//将密码库内容完整写入（老师与管理员）
void tool_write_infobase_teacher(std::string file_path, std::vector<personal_info>& infos)
{
	std::ofstream outfile(file_path, std::ios::out);

	if (!outfile.is_open())
	{
		system("cls");
		std::cout << file_path << "打开失败！请联系管理员修复系统！" << std::endl;
		system("pause");
		return;
	}
	for (personal_info& info : infos)
	{
		outfile << info.id << " " << info.name << " "
			<< info.num << " " << info.password << std::endl;
	}
	outfile.close();
	return;
}

//获取学生文件末尾的编号
int tool_get_student_tail_id()
{
	std::ifstream infile("student.txt");
	if (!infile.is_open())
	{
		system("cls");
		std::cout << "student.txt打开失败！请联系管理员修复系统！" << std::endl;
		system("pause");
		return -1;
	}
	int id = 0;
	std::string name;
	std::string num;
	std::string password;
	std::string comment;
	while (infile >> id >> name >> num >> password >> comment)
	{

	}

	infile.close();
	return id;
}

//获取老师文件末尾的编号
int tool_get_teacher_tail_id()
{
	std::ifstream infile("teacher.txt");
	if (!infile.is_open())
	{
		system("cls");
		std::cout << "teacher.txt打开失败！请联系管理员修复系统！" << std::endl;
		system("pause");
		return -1;
	}
	int id = 0;
	std::string name;
	std::string num;
	std::string password;
	std::string comment;
	while (infile >> id >> name >> num >> password >> comment)
	{

	}

	infile.close();
	return id;
}

//获取管理员文件末尾的编号
int tool_get_admin_tail_id()
{
	std::ifstream infile("admin.txt");
	if (!infile.is_open())
	{
		system("cls");
		std::cout << "admin.txt打开失败！请联系管理员修复系统！" << std::endl;
		system("pause");
		return -1;
	}
	int id = 0;
	std::string name;
	std::string num;
	std::string password;
	std::string comment;
	while (infile >> id >> name >> num >> password >> comment)
	{

	}

	infile.close();
	return id;
}

//检查文件是否为空
bool tool_check_txt_is_clean(std::string file_path)
{
	//只读模式读取
	std::ifstream infile(file_path,std::ios::in);
	if (!infile.is_open())
	{
		system("cls");
		std::cout << file_path << "打开失败！请联系管理员修复系统！" << std::endl;
		system("pause");
		return false;
	}
	if (infile.peek() == EOF)
	{
		//文件为空
		return true;
	}
	return false;
}