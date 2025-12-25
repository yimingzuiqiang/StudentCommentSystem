#include <iostream>
#include "system.h"


using namespace std;

int main()
{
	StudentCommentSystem* system = StudentCommentSystem::system_get_instance();
		

	int choice = -1;
	while (true)
	{
		system->system_main_menu();
		std::cout<<"\n请输入选择（数字）：" << std::endl;

		//检查有效性
		choice = tool_num_input();
		if (choice == (-1))
		{
			continue;
		}
		
		//检查选择

		switch (choice)
		{
		case 1:
			system->system_enter_admin();
			break;
		case 2:
			system->system_enter_teacher();
			break;
		case 3:
			system->system_enter_student();
			break;
		case 4:
			system->system_exit();
			break;

		default:
			break;
		}
		
	}
	
}