#pragma once
#include <iostream>
#include <fstream>
#include <vector>

typedef struct
{
	int id;
	std::string num;
	std::string name;
	std::string password;
	std::string comment;
}personal_info;

//空格3行
void tool_print_3_line();

////输入(有bug)
//template<typename T>
//T& tool_input(const T& input_choice);


//数字输入
int tool_num_input();

//字符串输入
std::string tool_string_input();

//字符输入
char tool_char_input();

//将密码库内容完整读取（学生）
void tool_read_infobase_student(std::string file_path, std::vector<personal_info>& infos);

//将密码库内容完整写入（学生）
void tool_write_infobase_student(std::string file_path, std::vector<personal_info>& infos);

//将密码库内容完整读取（老师与管理员）
void tool_read_infobase_teacher(std::string file_path, std::vector<personal_info>& infos);

//将密码库内容完整写入（老师与管理员）
void tool_write_infobase_teacher(std::string file_path, std::vector<personal_info>& infos);

//获取学生文件末尾的编号
int tool_get_student_tail_id();

//获取老师文件末尾的编号
int tool_get_teacher_tail_id();

//获取管理员文件末尾的编号
int tool_get_admin_tail_id();

//检查文件是否为空
bool tool_check_txt_is_clean(std::string file_path);