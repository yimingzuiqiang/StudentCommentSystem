#pragma once
#include "teacher.h"
#include "tool.h"

class Admin : public Teacher
{
public:
	Admin();
	
	~Admin();
	
	//用工号查询管理员是否在文本文件中
	bool check_admin_by_num(std::string check_num);
	//输入管理员密码界面
	virtual bool enter_password() override;
	//显示管理员菜单
	virtual void show_menu() override;
	//添加账号
	bool admin_add_account();
	//删除账号
	bool admin_delete_account();
	//删库跑路
	bool admin_clean_database();
};