#include"sims.h"

void trim_space(char*src)
{
	int fast_index, last_index ;
	for(fast_index = 0, last_index = -1 ; src[fast_index] != 0 ;fast_index ++)
	{
		if(!isspace(src[fast_index]))
		{
			src[++last_index] = src[fast_index];
		}else 
		{
			if(last_index != -1 && !isspace(src[last_index]) )
			{
				src[++last_index] =' ';
			}
		}
	}
	src[++last_index] = 0;
}
void system_init(char* config, pACCOUNT* pphead_acc, pSTU* pphead_stu)
{
	FILE* fp_config, *fp_account, *fp_stu ;
	char line[LINE_LEN] ;
	pACCOUNT pnew, pcur, ppre ;
	pSTU pnew_stu, pcur_stu, ppre_stu ;

	fp_config = fopen(config, "r");
	if(fp_config == NULL)
	{
		printf("open config fail!\n");
		system("pause");
		exit(1); 
	}
	memset(line, 0, sizeof(line));
	fflush(stdin);
	fgets(line, LINE_LEN, fp_config);
	line[strlen(line) - 1] = 0;

	fp_account = fopen(line, "r");
	if(fp_account == NULL)
	{
		printf("open account fail!\n");
		system("pause");
		exit(1); 
	}
	while(memset(line, 0, sizeof(line)), fgets(line, LINE_LEN, fp_account) != NULL)
	{
		pnew = (pACCOUNT)calloc(1, sizeof(ACCOUNT));
		sscanf(line,"%s%s%d", pnew ->m_name, pnew ->m_passwd, &pnew ->m_role);

		pcur = *pphead_acc ;
		ppre = NULL ;
		while(pcur && strcmp(pcur ->m_name, pnew ->m_name) < 0)
		{
			ppre = pcur ;
			pcur = pcur ->m_next ;
		}
		if(ppre == NULL)
		{
			pnew ->m_next = *pphead_acc ;
			*pphead_acc = pnew ;
		}else 
		{
			pnew ->m_next = pcur ;
			ppre ->m_next = pnew ;
		}
	}
	fclose(fp_account);


	memset(line, 0, sizeof(line));
	fgets(line, LINE_LEN, fp_config);
	line[strlen(line) - 1] = 0;
	fclose(fp_config);

	fp_stu = fopen(line, "r");
	if(fp_stu == NULL)
	{
		printf("open stu fail!\n");
		system("pause");
		exit(1); 
	}

	while(memset(line, 0, sizeof(line)), fgets(line, LINE_LEN, fp_stu) != NULL)
	{
		pnew_stu = (pSTU)calloc(1, sizeof(STU));
		//sscanf(line,"%s%s%d", pnew ->m_name, pnew ->m_passwd, &pnew ->m_role);
		trim_space(line);

		sscanf(line,"%d%s %c%lf%lf%lf%lf%lf", &pnew_stu ->m_id, pnew_stu ->m_name, &pnew_stu->m_gender, &pnew_stu->m_socres[0],&pnew_stu->m_socres[1],&pnew_stu->m_socres[2],&pnew_stu->m_socres[3],&pnew_stu->m_socres[4]);

		pcur_stu = *pphead_stu ;
		ppre_stu = NULL ;
		while(pcur_stu && pcur_stu ->m_id < pnew_stu ->m_id)
		{
			ppre_stu = pcur_stu ;
			pcur_stu = pcur_stu ->m_next ;
		}
		if(ppre_stu == NULL)
		{
			pnew_stu ->m_next = *pphead_stu ;
			*pphead_stu = pnew_stu ;
		}else 
		{
			pnew_stu ->m_next = pcur_stu ;
			ppre_stu ->m_next = pnew_stu ;
		}
	}
	fclose(fp_stu);





}
int role_confirm(pACCOUNT phead_acc)
{
	int cnt = 0 ;
	pACCOUNT pcur ;
	char usr_name[NAME_LEN] ;
	char usr_passwd[PWD_LEN];
	while(cnt < CONFIRM_CNT)
	{
		system("cls");
		printf("usr_name:");
		fflush(stdin);
		fgets(usr_name, NAME_LEN, stdin);
		usr_name[strlen(usr_name) - 1] = 0 ;
		printf("usr_pwd:");
		fflush(stdin);
		fgets(usr_passwd, PWD_LEN, stdin);
		usr_passwd[strlen(usr_passwd) - 1] = 0 ;

		pcur = phead_acc ;
		while(pcur)
		{
			if(strcmp(usr_name, pcur ->m_name) == 0 && strcmp(usr_passwd, pcur ->m_passwd) == 0)
			{
				break ;
			}
			pcur = pcur ->m_next ;
		}
		if(pcur)
		{
			return pcur ->m_role;
		}else 
		{
			cnt ++ ;	
		}



	}
	return -1;
}
int show_system_menu(int role)
{
	int select ;
	int flag = 0 ;
	while(!flag)
	{
		system("cls");
		if(role == 1)
		{
			//printf("1.");
			printf("%s\n", M1);
			printf("%s\n", M2);
			printf("%s\n", M3);
			printf("%s\n", M4);
			printf("%s\n", M5);
			printf("%s\n", M6);
			printf("%s\n", M7);
			printf("%s\n", M8);
			printf("%s\n", M9);
		}else 
		{
			printf("%s\n", M1);
			printf("%s\n", M9);
		}
		printf("select:");
		fflush(stdin);
		select = getchar();
		if(role == 1)
		{
			if( '1' <= select && select <= '9')
			{
				flag = 1 ;
			}
		}else 
		{
			if(select == '1' || select == '9')
			{
				flag = 1 ;
			}
		}

	}
	return select - '0';
}