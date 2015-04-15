#ifndef __SIMS__
#define __SIMS__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define PWD_LEN 10
#define NAME_LEN 20
#define LINE_LEN 512
#define CONFIRM_CNT 3
#define M1 "1.search stu"
#define M2 "2.update stu"
#define M3 "3.delete stu"
#define M4 "4.add stu"
#define M5 "5.search acc"
#define M6 "6.update acc"
#define M7 "7.delete acc"
#define M8 "8.add acc"
#define M9 "9.exit"
typedef struct stu_accout_tag
{
	char m_passwd[PWD_LEN];
	char m_name[20];
	int  m_role ;
	struct stu_accout_tag* m_next ;
}ACCOUNT, *pACCOUNT;
typedef struct stu_info_tag
{
	int m_id ;
	char m_name[NAME_LEN];
	char m_gender ;
	double m_socres[5] ;
	struct stu_info_tag* m_next ;
}STU, *pSTU;

void system_init(char* config, pACCOUNT* pphead_acc, pSTU* pphead_stu) ;
int role_confirm(pACCOUNT phead_acc);
int show_system_menu(int role);
#endif