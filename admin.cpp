#include "admin.h"

Admin::Admin()
{
	this->my_type = "管理员";
}

Admin::~Admin()
{

}

//显示管理员菜单
void Admin::show_menu()
{
	using namespace std;
	while (true)
	{
		system("cls");
		cout << "*************学生评教管理系统***************\n" << endl;
		cout << "** 管理员:" << this->my_name << "\n" << endl;
		cout << "1. 查看对学生的评价\n" << endl;
		cout << "2. 修改对学生的评价\n" << endl;
		cout << "3. 添加账号\n" << endl;
		cout << "4. 删除账号\n" << endl;
		cout << "5. 删库跑路\n" << endl;
		cout << "6. 修改密码\n" << endl;
		cout << "7. 退出管理员角色\n" << endl;
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
			this->admin_add_account();
			break;
		case 4:
			this->admin_delete_account();
			break;
		case 5:
			this->admin_clean_database();
			break;
		case 6:
			this->change_password();
			break;
		case 7:
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

//用工号查询管理员是否在文本文件中
bool Admin::check_admin_by_num(std::string check_num)
{
	std::ifstream infile("admin.txt");
	if (!infile.is_open())
	{
		system("cls");
		std::cout << "admin.txt打开失败！请联系管理员修复系统！" << std::endl;
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

//输入密码
bool Admin::enter_password()
{
	using namespace std;
	system("cls");

	cout << "** 请输入你的工号(10位)：                          " << endl;

	std::string account;
	std::string password;

	account = tool_string_input();

	//遍历老师列表,查找是否有这个工号
	if (check_admin_by_num(account) == false)
	{
		return false;
	}

	//输入密码
	system("cls");
	cout << "你好，" << this->my_name << "管理员" << std::endl;
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

//添加账号
bool Admin::admin_add_account()
{
	//选择添加的身份（1-学生，2-老师，3-管理员）
	system("cls");
	std::cout << "请选择要添加的身份（1-学生，2-老师，3-管理员）：" << std::endl;
	int type_choice = tool_num_input();
	std::string file_path;

	int id = 0;

	//获取现在列表最末尾的编号
	switch (type_choice)
	{
	case 1:
		id = tool_get_student_tail_id();
		file_path = "student.txt";
		break;
	case 2:
		id = tool_get_teacher_tail_id();
		file_path = "teacher.txt";
		break;
	case 3:
		id = tool_get_admin_tail_id();
		file_path = "admin.txt";
		break;
	default:
		system("cls");
		std::cout << "输的啥玩意？" << std::endl;
		system("pause");
		system("cls");
		return false;
	}

	//输入信息
	system("cls");
	std::cout << "请输入姓名：" << std::endl;
	std::string name = tool_string_input();
	std::cout << "请输入学号或工号:" << std::endl;
	std::string num = tool_string_input();
	std::cout << "请输入密码:" << std::endl;
	std::string password = tool_string_input();
	

	//追加在文件末尾
	std::ofstream outfile(file_path, std::ios::app);
	if (!outfile.is_open())
	{
		system("cls");
		std::cout << file_path << "打开失败！请联系管理员修复系统！" << std::endl;
		system("pause");
		outfile.close();
		return false;
	}

	if (type_choice == 1)
	{
		std::string comment = "无";
		outfile << id + 1 << " " << name << " " << num << " "<<password << " " << comment << std::endl;
		system("cls");
		std::cout << "添加成功！" << std::endl;
		system("pause");
		system("cls");
		outfile.close();
		return true;
	}
	else
	{
		outfile << id + 1 << " " << name << " " << num << " " << password << std::endl;
		system("cls");
		std::cout << "添加成功！" << std::endl;
		system("pause");
		system("cls");
		outfile.close();
		return true;
	}
	return false;
}

//删除账号
bool Admin::admin_delete_account()
{
	//类似教师的查找，找到待删除的人
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
	//确认是否删除
	system("cls");
	std::cout << "选中学生：" << std::endl;
	std::cout << the_student.id << " " << the_student.name << " "
		<< the_student.num << " " << the_student.comment << std::endl;
	tool_print_3_line();
	
	std::cout << "是否要删除？（1-是，2-不）:" << std::endl;
	int change_choice = tool_num_input();
	if (change_choice == 1)
	{
		//准备两个容器
		std::vector<personal_info> v1;
		std::vector<personal_info> v2;
		//容器1读取文件内容
		tool_read_infobase_student("student.txt", v1);
		//遍历容器1，放入容器2
		bool is_found = false;
		for (auto& stu : v1)
		{
			if (stu.num == the_student.num)
			{
				//找到待删除学生的信息
				is_found = true;
				//不放入容器2，且后续的数据的id-1
				continue;
			}
			if (is_found)
			{
				stu.id--;
				v2.push_back(stu);
				continue;
			}
			v2.push_back(stu);
			continue;
		}
		//用容器2写文件
		tool_write_infobase_student("student.txt",v2);

		system("cls");
		std::cout << "删除成功！" << std::endl;
		system("pause");
		system("cls");
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

//删库跑路
bool Admin::admin_clean_database()
{
	//选择要清空的库
	system("cls");
	std::cout << "请选择要删除哪个库：" << std::endl;
	std::cout << "1-学生库，2-老师库，3-管理员库" << std::endl;
	int choice = tool_num_input();
	std::string file_path;
	switch (choice)
	{
	case 1:
		file_path = "student.txt";
		break;
	case 2:
		file_path = "teacher.txt";
		break;
	case 3:
		file_path = "admin.txt";
		break;
	default:
		system("cls");
		std::cout << "超出范围了！" << std::endl;
		system("pause");
		system("cls");
		return false;
	}
	//确认是否清空
	system("cls");
	std::cout << "确定要删库跑路吗？本公司待你不薄!" << std::endl;
	std::cout << "1-我就删，2-好，那不删了" << std::endl;
	choice = tool_num_input();

	if (choice == 1) //删库
	{
		std::ofstream outfile(file_path);
		if (!outfile.is_open())
		{
			system("cls");
			std::cout << file_path << "打开失败！请联系管理员修复系统！" << std::endl;
			system("pause");
			return false;
		}
		outfile.close();
		system("cls");
		std::cout << "删库成功，快跑！" << std::endl;
		system("pause");
		system("cls");
		return true;
	}
	else
	{
		return false;
	}
}