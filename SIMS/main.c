#include"sims.h"
int main(int argc, char* argv[])
{
	pACCOUNT account_list = NULL;
	pSTU stu_list = NULL ;
	int role;
	int select;
	system_init(argv[1], &account_list, &stu_list);

	if( (role = role_confirm(account_list) )== -1)
	{
		printf("fail to login\n");
		system("pause");
		return 0 ;
	}
	while(system("cls"),(select = show_system_menu(role)) != 9)
	{
		if(role == 1)
		{
			switch(select)
			{
			case 1: 
				system("cls");
				printf("1\n");

				fflush(stdin);
				getchar();
				getchar();
				break;
			case 2:  
				printf("2\n");
				break;
			case 3: 
				printf("3\n");
				break;
			case 4: 
				printf("4\n");
				break;
			case 5:  
				printf("5\n");
				break;
			case 6: 
				printf("6\n");
				break;
			case 7:  
				printf("7\n");
				break;
			case 8: 
				printf("8\n");
				break;
			case 9: 
				printf("9\n");
				break;
			}
		}else
		{
			switch(select)
			{
			case 1:  break;
			case 9:  break;
			}
		}
	}

	system("pause");
	return 0 ;
}