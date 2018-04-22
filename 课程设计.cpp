#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>

typedef struct class_information
{
	char coding[20];
	char name[20];
	char scope[20];
	char type[20];
	char credit[20];
	char hours[20];
	char teacher[20];
	struct class_information *next;
 }*list,Class_Inf;
 
  struct class_inf
 {
 	char Course_name[20];
 };
 
 typedef struct Stu_information
 {
 	char id[20];
 	char name[20];
 	struct class_inf course[15];
 	struct Stu_information *next;
 }*Stu_list,Stu;
 

void Main_Menu();                       //主菜单 

void login();                            //管理员登录 

int Second_Level_Menu();                //二级菜单 

int Course_Management_Menu();            //课程管理菜单 

int Stu_Select_Course_Management_Menu();             //学生选课管理菜单 

int Inquire_Select_Course_Result_Menu();             //选课结果查询菜单 

int Count_Select_Course_Result_Menu();              //统计选课信息菜单 

void look_class_information();               //浏览课程信息 

void Add_Course();                           //增加课程函数 

void Revise_Course();                   //修改课程函数 

void Del_Course();                      //删除课程函数 

void Add_Stu_Select_Course();          //增加学生选课

void Revise_Stu_Select_Course();         //修改学生选课 

void Del_Stu_Select_Course();           //删除学生选课 

void Inquire_By_Course();               //按课程查询 

void Inquire_By_Credit();             //按学分查询 

void Inquire_By_Stu_Id();            //按学号查询   

void Count_By_A_Course();        //统计某门课程选课结果  

void Count_By_Unqualified(); 

int main()
{
	int choice_1,choice_2;
	while(1)
	{
		Main_Menu();                   //主菜单
		login();
		while(1)
		{
			choice_1 = Second_Level_Menu();              //二级菜单
			if(choice_1==1)
			{
				while(1)
				{
					choice_2 = Course_Management_Menu();
					if(choice_2 == 1)
			    	look_class_information();
					else if(choice_2 == 2)
					Add_Course();                    //增加课程 
					else if(choice_2 == 3 )
					Revise_Course();                 //修改课程 
					else if(choice_2 == 4)
					Del_Course();                   //删除课程 
					else
					break;
				}
			}
			else if(choice_1 == 2)
			{
				while(1)
				{
					choice_2 = Stu_Select_Course_Management_Menu();
					if(choice_2 == 1)
    				Add_Stu_Select_Course();      //增加学生选课 
					else if(choice_2 == 2)
					Revise_Stu_Select_Course();      //修改学生选课 
					else if(choice_2 == 3)
					Del_Stu_Select_Course();        //删除学生选课 
					else
					break;
				}
			}
			else if(choice_1 == 3)
			{
				while(1)
				{
					choice_2 = Inquire_Select_Course_Result_Menu();
					if(choice_2 == 1)
					Inquire_By_Course();         //按课程查询 
					else if(choice_2 == 2)
					Inquire_By_Credit();         //按学分查询 
					else if(choice_2 == 3)
					Inquire_By_Stu_Id();         //按学号查询 
					else
					break;
				}
			}
			else if(choice_1 == 4)
			{
				while(1)
				{
					choice_2 = Count_Select_Course_Result_Menu();
					if(choice_2 == 1)
					Count_By_A_Course();             //统计某门课程选课结果
					else if(choice_2 == 2)
					Count_By_Unqualified();
					else
					break;
				}
			}
			else
			break;
		}
	}
	return 0; 
 }
  
/*---------------------------------------------------------------------------统计选课不合格名单----------------------------------------------------------------------*/ 
void Count_By_Unqualified()
{
	system("cls");
	float Min_Req,sum_credit;
	int judge,judge_1,choice,i; 
    FILE *fp;
 	fp = fopen("Stu_Select_Course.txt","r");
 	if(fp == NULL)
 	{
 		system("cls");
 		printf("\nFailed to open the file.\n");
 		exit(1);
	 }
	 Stu_list head,p,r;                  //学生选课信息的链表 
	 head = (Stu_list)malloc(sizeof(Stu));
	 head->next = NULL;
	 r = head;
	 while(!feof(fp))
	 {
	 	p = (Stu_list)malloc(sizeof(Stu));
	 	fscanf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n\n",p->id,p->name,p->course[0].Course_name,p->course[1].Course_name,p->course[2].Course_name,
		p->course[3].Course_name,p->course[4].Course_name,p->course[5].Course_name,p->course[6].Course_name,p->course[7].Course_name,p->course[8].Course_name,
		p->course[9].Course_name,p->course[10].Course_name,p->course[11].Course_name,p->course[12].Course_name,p->course[13].Course_name,p->course[14].Course_name);
		r->next = p;
		r = p;
	 }
	 r->next = NULL;
	 r = NULL;
	 p = NULL;
	 fclose(fp);
	 fp = fopen("class_information.txt","r");
	if(fp ==NULL)
	{
		system("cls");
		printf("\nFailed to open the file.\n");
		exit(1);
	}
	list head1,p1,r1;                    //课程信息的链表 
	head1 = (list)malloc(sizeof(Class_Inf));
	head1->next = NULL;
	r1 = head1;
	while(!feof(fp))
	{
		p1 = (list)malloc(sizeof(Class_Inf));
		fscanf(fp,"%s %s %s %s %s %s %s\n\n",p1->coding,p1->name,p1->scope,p1->type,p1->credit,p1->hours,p1->teacher);
		r1->next = p1;
		r1 = p1;
	}
	r1->next = NULL;
	fclose(fp);
	r1 = NULL;
	p1 = NULL;
	while(1)
	{
		printf("\n\n----------------------统计不符合要求学生信息----------------------\n\n");
    	printf("\n请输入满足要求的最低学分:");
    	scanf("%f",&Min_Req); 
    	printf("\n选课总学分不满足%-2.1f学分的学生信息为:",Min_Req);
    	judge = 1;
    	p = head;                    //学生选课信息的链表 
    	do{
    		sum_credit = 0;
    		p = p->next;
    		for(i=0;i<15;i++)
    		{
    			if(strcmp(p->course[i].Course_name,"NULL") != 0)
    			{
    				p1 = head1;
    				do{
    					p1 = p1->next;
    					if(strcmp(p->course[i].Course_name,p1->name)==0)
    					{
    						sum_credit += atoi(p1->credit);
    					}
					}while(p1->next != NULL);
				}
			}
			if(sum_credit < Min_Req)
			{
				judge = 0;
				printf("\n\n学号:%-10s\n\n姓名:%-15s\n\n",p->id,p->name);
				printf("已选课程:");
				judge_1 = 0;
			    for(i=0;i<15;i++)
		    	{
		    		if(strcmp(p->course[i].Course_name,"NULL" )!= 0)
		    		{
		    			judge_1 = 1;
		    			printf("%-10s",p->course[i].Course_name);
		    		}
		    	}
		    	if(judge_1==0)
		    	{
		    		printf("无课程选择");
				}
		   	}
		   	if(judge==0)
		   	printf("\n");
		}while(p->next != NULL);
		p = NULL;
		p1 = NULL;
		if(judge==1)
		{
			printf("\n\n所有学生都满足该要求，不存在不满足该要求的学生！");
		}
		while(1)
		{
			printf("\n\n1.继续统计\t\t2.Back");
    		printf("\n\n请输入您的选择:");
	    	scanf("%d",&choice);
	    	if(choice==1||choice==2)
	    	break;
	    	else
	    	{
	    		system("cls");
	    		printf("您的选择有误，请重新选择！\n");
			}
		}
		if(choice==1)
		{
			system("cls");
			continue;
		}
		else
		{
			system("cls");
			break;
		}
	}
}
       
/*------------------------------------------------------------------------------------主菜单-----------------------------------------------------------------------------------*/ 
void Main_Menu()       
{
	int choice;
	while(1)
	{
		printf("\n\t\tMenu:\n\n");
     	printf("\t\t1.选课信息管理(管理员)\n\n");
	    printf("\t\t2.退出\n\n");
	    printf("\t\t请输入您的选择:");                    
		scanf("%d",&choice);                                                               
		if(choice==1)
		break;
		else if(choice==2)
		{
			system("cls");
			printf("\n谢谢您的使用！\n");
			exit(0);
		}
		else                       //选择错误，重新选择 
		{
			system("cls");
			printf("您的选择有误，请重新选择！\n");
		}
	}
}

 /*----------------------------------------------------------------------------管理员登录函数-----------------------------------------------------------*/ 
 void login()
 {
 	system("cls");
 	char account[10],password[10];
 	int time = 0;
 	while(1)
 	{
 		printf("--------------------管理员登录(账号:admin 密码:admin)--------------------\n\n\n");
 		printf("\t\t账户:");
 		scanf("%s",account);
 		printf("\n\n\t\t密码:");
 		scanf("%s",password);
 		time++;
 		if(strcmp(account,"admin")==0&&strcmp(password,"admin")==0)
 		{
 			system("cls");
 			break;
		 }
 		else
 		{
 			system("cls");
 			printf("\n您输入的账号或密码有误，请重新输入！\n\n");
		 }
		 if(time==3)
		 {
		 	system("cls");
		 	printf("\nSorry，您已经连续3次输入错误，请稍后再试！\n");
		 	exit(0);
		 }
	 }
 }
 
/*-----------------------------------------------------------------二级菜单----------------------------------------------------------*/ 
 int Second_Level_Menu()
 {
 	int choice;
 	while(1)
 	{
 		printf("\n\t\tMenu:\n\n");
     	printf("\t\t1.课程管理\n\n");
	    printf("\t\t2.学生选课管理\n\n");
	    printf("\t\t3.选课结果查询\n\n");
	    printf("\t\t4.统计选课信息\n\n");
	    printf("\t\t5.Back\n\n");
	    printf("\t\t6.Exit\n\n");
	    printf("\t\t请输入您的选择:");                    
		scanf("%d",&choice);
		if(choice==1||choice==2||choice==3||choice==4||choice==5)
		{
			system("cls");
			break;
		}
		else if(choice==6)
		{
			system("cls");
			printf("\n谢谢您的使用！\n");
			exit(0);
		}
		else
		{
			system("cls");
			printf("\n您的选择有误，请重新选择！\n");
		 } 
	 }
	 return choice;
 }
 
 /*---------------------------------------------------------------------------课程管理菜单-----------------------------------------------------------------------*/ 
 int Course_Management_Menu()
 {
 	int choice;
 	while(1)
 	{
 		printf("\n\t\tMenu:\n\n");
     	printf("\t\t1.浏览课程信息\n\n");
	    printf("\t\t2.录入课程信息\n\n");
	    printf("\t\t3.修改课程信息\n\n");
	    printf("\t\t4.删除课程信息\n\n");
	    printf("\t\t5.Back\n\n");
	    printf("\t\t6.Exit\n\n");
	    printf("\t\t请输入您的选择:");                    
		scanf("%d",&choice);
		if(choice==1||choice==2||choice==3||choice==4||choice==5)
		{
			system("cls");
			break;
		}
		else if(choice==6)
		{
			system("cls");
			printf("\n谢谢您的使用！\n");
			exit(0);
		}
		else
		{
			system("cls");
			printf("\n您的选择有误，请重新选择！\n");
		 } 
	 }
	 return choice; 
 }
 
 /*--------------------------------------------------------------------------学生选课管理菜单----------------------------------------------------------------*/ 
 int Stu_Select_Course_Management_Menu()
 {
   int choice;
   while(1)
   {
	 printf("\n\t\tMenu:\n\n");
   	 printf("\t\t1.增加学生选课\n\n");
	 printf("\t\t2.修改学生选课\n\n");
     printf("\t\t3.删除学生选课\n\n");
	 printf("\t\t4.Back\n\n");
	 printf("\t\t5.Exit\n\n");
	 printf("\t\t请输入您的选择:");               
	 scanf("%d",&choice);
	 if(choice==1||choice==2||choice==3||choice==4)
		{
			system("cls");
			break;
		}
	 else if(choice==5)
		{
			system("cls");
			printf("\n谢谢您的使用！\n");
			exit(0);
		}
	 else
		{
			system("cls");
			printf("\n您的选择有误，请重新选择！\n");
		 } 
   }
   return choice;	
 }
 
 /*-----------------------------------------------------选课结果查询菜单--------------------------------------------------------------*/ 
 int Inquire_Select_Course_Result_Menu()
 {
 	int choice;
 	while(1)
 	{
 		printf("\n\t\tMenu:\n\n");
   	    printf("\t\t1.按课程查询\n\n");
	    printf("\t\t2.按学分查询\n\n");
        printf("\t\t3.按学号查询\n\n");
   	    printf("\t\t4.Back\n\n");
	    printf("\t\t5.Exit\n\n");
	    printf("\t\t请输入您的选择:");               
	    scanf("%d",&choice);
	    if(choice==1||choice==2)
		{
			system("cls");
			break;
		}
		else if(choice==3||choice==4)
		{
			system("cls");
			break;
		}
	    else if(choice==5)
		{
			system("cls");
			printf("\n谢谢您的使用！\n");
			exit(0);
		}
	    else
		{
			system("cls");
			printf("\n您的选择有误，请重新选择！\n");
		 } 
	 }
	 return choice; 
 }
 
 /*---------------------------------------------------统计选课信息菜单-------------------------------------------------*/ 
 int Count_Select_Course_Result_Menu()
 {
 	int choice;
	 while(1)
	 {
	 	printf("\n\t\tMenu:\n\n");
   	    printf("\t\t1.统计某门课程学生选修情况\n\n");
	    printf("\t\t2.统计选课不合格的学生名单\n\n");
   	    printf("\t\t3.Back\n\n");
	    printf("\t\t4.Exit\n\n");
	    printf("\t\t请输入您的选择:");               
	    scanf("%d",&choice);
	    if(choice==1||choice==2||choice==3)
		{
			system("cls");
			break;
		}
	    else if(choice==4)
		{
			system("cls");
			printf("\n谢谢您的使用！\n");
			exit(0);
		}
	    else
		{
			system("cls");
			printf("\n您的选择有误，请重新选择！\n");
		 } 
	  }
	  return choice; 
 }
 
 /*---------------------------------------------------------------------------浏览课程信息函数---------------------------------------------------------------------*/ 
void look_class_information()
{
	Class_Inf class_data;
	int choice;
	system("cls");
	FILE *class_infor;
	class_infor = fopen("class_information.txt","r");                  //从class_information.txt中读取文件 
	if(class_infor==NULL)                  //判断是否读取成功 
	{
		printf("\nFailed to open the file.\n");
		exit(1);
	}
	printf("Class Information:\n\n");
	printf("课程编码 课程名称   适用专业             课程类型        学分  学时 主讲教师\n");
	while(!feof(class_infor))
	    {
	    	fscanf(class_infor,"%s %s %s %s %s %s %s\n\n",class_data.coding,class_data.name,class_data.scope,class_data.type,class_data.credit,class_data.hours,class_data.teacher);
	    	printf("%-8s%-12s%-20s%-18s%-5s%-4s%-8s\n",class_data.coding,class_data.name,class_data.scope,class_data.type,class_data.credit,class_data.hours,class_data.teacher);
		}
	fclose(class_infor);                       //关闭class_information.txt 
	while(1)
	{
		printf("\n\n1.Back\t\t2.Exit\n\n");
		printf("Please select the choice:");
	    scanf("%d",&choice);
	    if(choice==1) 
	    {
	    	system("cls");
			break;
		}
		else if(choice==2)
		{
			system("cls");
			printf("\n谢谢您的使用！\n");
			exit(0);
		}
	    else
		 {                                    //选择错误，重新选择 
	     	system("cls");
	     	printf("\n您的选择有误，请重新选择！\n");
		}
	}
}

  /*-------------------------------------------------------------------增加课程函数------------------------------------------------------------*/ 
void Add_Course()
{
	system("cls"); 
	int choice,judge;
	list temp;
	temp = (list)malloc(sizeof(Class_Inf));
	while(1)
	{
		FILE *fp;
		fp = fopen("class_information.txt","r");
		if(fp==NULL)                  //判断是否读取成功 
 	       {
			   printf("\nFailed to open the file.\n");
			   exit(1);
		    }
		list head,p,r;
		head = (list)malloc(sizeof(Class_Inf));
		head->next = NULL;
		r = head;
		while(!feof(fp))
		{
			p = (list)malloc(sizeof(Class_Inf));
			fscanf(fp,"%s %s %s %s %s %s %s\n\n",p->coding,p->name,p->scope,p->type,p->credit,p->hours,p->teacher);
			r->next = p;
			r = p;
		}
		r->next = NULL;
		fclose(fp);
		r = NULL;
		p = NULL;
		judge=0;
		printf("\n-----------------------请输入要增加课程的相关信息!-----------------------");
		printf("\n\n\t\t课程编码:");
		scanf("%s",temp->coding);
		printf("\n\n\t\t课程名称:");
		scanf("%s",temp->name);
		p = head;
		do{
			p = p->next;
			if(strcmp(p->coding,temp->coding)==0||strcmp(p->name,temp->name)==0)
			{
				judge = 1;
				break;
			}
			
		}while(p->next != NULL);
		if(judge == 1)
		{
			system("cls");
			while(1)
			{
				printf("\n\t已存在相同课程编号或名称的课程，请输入不同课程编号和名称的课程！\n\n");
		    	printf("\t\t1.重新输入\n\n");
			    printf("\t\t2.Back\n\n");
	    		printf("\t\t3.Exit\n\n");
		    	printf("\t\t请输入您的选择:");
		     	scanf("%d",&choice);
		     	if(choice==1||choice==2||choice==3)
		     	break;
		     	else
		     	{
		     		system("cls");
	         	    printf("您的选择有误，请重新选择！\n");
				 }
			}
			if(choice==1)
			{
				system("cls");
				continue;
			}
			else if(choice==2)
			{
				system("cls");
				break;
			}
			else
			{
			   	system("cls");
			    printf("\n谢谢您的使用！\n");
			    exit(0);
			}	
		}
		else
		{
			printf("\n\n\t\t适用专业:");
			scanf("%s",temp->scope);
			printf("\n\n\t\t课程类型:");
			scanf("%s",temp->type);
			printf("\n\n\t\t    学分:");
			scanf("%s",temp->credit);
			printf("\n\n\t\t    学时:");
			scanf("%s",temp->hours);
			printf("\n\n\t\t主讲教师:");
			scanf("%s",temp->teacher);
			fp = fopen("class_information.txt","a");
			fprintf(fp,"%s %s %s %s %s %s %s\n\n",temp->coding,temp->name,temp->scope,temp->type,temp->credit,temp->hours,temp->teacher);
			fclose(fp);
			system("cls");
			printf("\n--------------------------------成功增加课程！--------------------------------\n");
			while(1)
			{
				printf("\n\n\t\t1.继续增加课程\n\n");
		     	printf("\t\t2.Back\n\n");
		    	printf("\t\t3.Exit\n\n");
		    	printf("\t\t请输入您的选择:");
		    	scanf("%d",&choice);
		    	if(choice==1||choice==2||choice==3)
		    	break;
		    	else
		    	{
		    		system("cls");
	         	    printf("您的选择有误，请重新选择！\n");
				}
			}
			if(choice==1)
			{
				system("cls");
				continue;
			}
			else if(choice==2)
			{
				system("cls");
				break;
			}
			else
			{
				system("cls");
			    printf("\n谢谢您的使用！\n");
		    	exit(0);
			}
		}
	}
}

/*-------------------------------------------------------------------------修改课程函数----------------------------------------------------------------*/ 
void Revise_Course()
{
	system("cls");
	FILE *fp;
	Class_Inf temp;
	int choice,choice_1,judge,judge_1;
	list head,p,r;
	fp = fopen("class_information.txt","r");
	if(fp==NULL)                                   //判断是否读取成功 
    	{
		printf("\nFailed to open the file.\n");
		exit(1);
    	}
    head = (list)malloc(sizeof(Class_Inf));
	head->next = NULL;
	r = head;
	while(!feof(fp))
		{
			p = (list)malloc(sizeof(Class_Inf));
			fscanf(fp,"%s %s %s %s %s %s %s\n\n",p->coding,p->name,p->scope,p->type,p->credit,p->hours,p->teacher);
			r->next = p;
			r = p;
		}
	r->next = NULL;
	fclose(fp);
	r = NULL;
	p = head;
	while(1)
	{
		judge = 0;
		printf("\n-----------------------请输入相关课程信息！-----------------------\n\n");
		printf("\n\n\t请输入需要修改课程的编号或名称:");
		scanf("%s",temp.coding);
		strcpy(temp.name,temp.coding);
		p = head;
		do{
			p = p->next;
			if(strcmp(p->coding,temp.coding)==0||strcmp(p->name,temp.name)==0)
			{
				judge = 1;
				break;
			}
		}while(p->next != NULL);
		if(judge==0)
		{
			system("cls");
			printf("\n--------------------Sorry,未能查找到该课程！---------------------");
			while(1)
			{
				printf("\n\n\t1.重新输入\n\n");
			    printf("\t2.Back\n\n");
			    printf("\t3.Exit\n\n");
			    printf("\t请输入您的选择:");
			    scanf("%d",&choice);
			    if(choice==1||choice==2||choice==3)
			    break;
			    else
			    {
			    	system("cls");
				    printf("\n您的选择有误，请重新选择！\n");
			    }
			}
			if(choice==1)
			{
				system("cls");
				continue;
			}
			else if(choice==2)
			{
				system("cls");
				break;
			}
			else
			{
				system("cls");
			    printf("\n谢谢您的使用！\n");
			    exit(0);
			}
		}
		else
		{
			system("cls");
			printf("\n-----------------------成功查找到该课程！-----------------------\n\n");
			while(1)
			{
				printf("该课程信息如下:\n\n");
		    	printf("课程编码 课程名称   适用专业             课程类型        学分  学时 主讲教师\n");
			    printf("%-8s%-12s%-20s%-18s%-5s%-4s%-8s",p->coding,p->name,p->scope,p->type,p->credit,p->hours,p->teacher);
		    	printf("\n\n\n1.修改课程编码");
		    	printf("\t2.修改课程名称");
		    	printf("\t3.修改适用专业");
		    	printf("\t4.修改课程类型");
		    	printf("\n\n5.修改课程学分");
		    	printf("\t6.修改课程学时");
		    	printf("\t7.修改主讲教师");
		    	printf("\n\n请输入您的选择:");
		    	scanf("%d",&choice);
		    	if(choice==1||choice==2||choice==3)
		    	break;
		    	else if(choice==4||choice==5)
		    	break;
		    	else if(choice==6||choice==7)
		    	break;
		    	else
		    	{
		    		system("cls");
				    printf("\n您的选择有误，请重新选择！\n\n");
				}
			}
			if(choice==1)
			{
				while(1)
				{
					judge_1 = 0;
					printf("\n\n请输入更改后的课程编码:");
				    scanf("%s",temp.coding);
				    r = head;
				    do{
				    	r = r->next;
				    	if(strcmp(temp.coding,r->coding)==0)
				    	{
				    		judge_1 = 1;
				    		break;
						}
					}while(r->next != NULL);
					r = NULL;
					if(judge_1==1)
					{
						system("cls");
						printf("\n修改失败，已存在相同编码的课程！");
						continue;
					}
					else
					{
						strcpy(p->coding,temp.coding);
						fp = fopen("class_information.txt","w");
						r = head;
						do{
							r = r->next;
							fprintf(fp,"%s %s %s %s %s %s %s\n\n",r->coding,r->name,r->scope,r->type,r->credit,r->hours,r->teacher);
						}while(r->next != NULL);
						fclose(fp);
						r = NULL;
						system("cls");
						printf("\n-----------------------修改成功！-------------------------");
						break;
			   		}
				}
				while(1)
						{
						    printf("\n\n\t1.继续修改\t\t2.Back");
						    printf("\n\n\t输入您的选择:");
						    scanf("%d",&choice_1);
						    if(choice_1==1||choice_1==2)
						    break;
						    else
						    {
						    	system("cls");
						    	printf("\n您的选择有误，请重新选择！\n\n");
							}
						 } 
			    if(choice_1==1)
			    {
			    	system("cls");
			    	continue;
				}
				else
				{
					system("cls");
					break;
				}
			}
			else if(choice==2)
			{
				while(1)
				{
					judge_1 = 0;
					printf("\n\n请输入更改后的课程名称:");
				    scanf("%s",temp.name);
				    r = head;
				    do{
				    	r = r->next;
				    	if(strcmp(temp.name,r->name)==0)
				    	{
				    		judge_1 = 1;
				    		break;
						}
					}while(r->next != NULL);
					r = NULL;
					if(judge_1==1)
					{
						system("cls");
						printf("\n修改失败，已存在相同名称的课程！");
						continue;
					}
					else
					{
						strcpy(p->name,temp.name);
						fp = fopen("class_information.txt","w");
						r = head;
						do{
							r = r->next;
							fprintf(fp,"%s %s %s %s %s %s %s\n\n",r->coding,r->name,r->scope,r->type,r->credit,r->hours,r->teacher);
						}while(r->next != NULL);
						fclose(fp);
						r = NULL;
						system("cls");
						printf("\n----------------------修改成功！--------------------");
						break;
					}
				}
				while(1)
						{
						    printf("\n\n\t1.继续修改\t\t2.Back");
						    printf("\n\n\t输入您的选择:");
						    scanf("%d",&choice_1);
						    if(choice_1==1||choice_1==2)
						    break;
						    else
						    {
						    	system("cls");
						    	printf("\n您的选择有误，请重新选择！\n\n");
							}
						 } 
				 if(choice_1==1)
			    {
			    	system("cls");
			    	continue;
				}
				else
				{
					system("cls");
					break;
				}
			}
			else if(choice==3)
			{
				printf("\n\n请输入更改后的适用专业:");
				scanf("%s",p->scope);
				fp = fopen("class_information.txt","w");
				r = head;
				do{
					r = r->next;
					fprintf(fp,"%s %s %s %s %s %s %s\n\n",r->coding,r->name,r->scope,r->type,r->credit,r->hours,r->teacher);
				}while(r->next != NULL);
				fclose(fp);
				r = NULL;
				system("cls"); 
				printf("\n-----------------------修改成功！---------------------\n\n\n");
				while(1)
						{
						    printf("\n\n\t1.继续修改\t\t2.Back");
						    printf("\n\n\t输入您的选择:");
						    scanf("%d",&choice_1);
						    if(choice_1==1||choice_1==2)
						    break;
						    else
						    {
						    	system("cls");
						    	printf("\n您的选择有误，请重新选择！\n\n");
							}
						 } 
				if(choice_1==1)
			    {
			    	system("cls");
			    	continue;
				}
				else
				{
					system("cls");
					break;
				}
			}
			else if(choice==4)
			{
				printf("\n\n请输入更改后的课程类型:");
				scanf("%s",p->type);
				fp = fopen("class_information.txt","w");
				r = head;
				do{
					r = r->next;
					fprintf(fp,"%s %s %s %s %s %s %s\n\n",r->coding,r->name,r->scope,r->type,r->credit,r->hours,r->teacher);
				}while(r->next != NULL);
				fclose(fp);
				r = NULL;
				system("cls");
				printf("\n-------------------------------修改成功！------------------------------\n\n\n");
				while(1)
						{
						    printf("\t1.继续修改\t\t2.Back");
						    printf("\n\n\t输入您的选择:");
						    scanf("%d",&choice_1);
						    if(choice_1==1||choice_1==2)
						    break;
						    else
						    {
						    	system("cls");
						    	printf("\n您的选择有误，请重新选择！\n\n");
							}
						 } 
				if(choice_1==1)
			    {
			    	system("cls");
			    	continue;
				}
				else
				{
					system("cls");
					break;
				}
			}
			else if(choice==5)
			{
				printf("\n\n请输入更改后的课程学分:");
				scanf("%s",p->credit);
				fp = fopen("class_information.txt","w");
				r = head;
				do{
					r = r->next;
					fprintf(fp,"%s %s %s %s %s %s %s\n\n",r->coding,r->name,r->scope,r->type,r->credit,r->hours,r->teacher);
				}while(r->next != NULL);
				fclose(fp);
				r = NULL;
				system("cls");
				printf("\n-------------------------修改成功！----------------------\n\n\n");
				while(1)
						{
						    printf("\t1.继续修改\t\t2.Back");
						    printf("\n\n\t输入您的选择:");
						    scanf("%d",&choice_1);
						    if(choice_1==1||choice_1==2)
						    break;
						    else
						    {
						    	system("cls");
						    	printf("\n您的选择有误，请重新选择！\n\n");
							}
						 } 
				if(choice_1==1)
			    {
			    	system("cls");
			    	continue;
				}
				else
				{
					system("cls");
					break;
				}
			}
			else if(choice==6)
			{
				printf("\n\n请输入更改后的课程学时:");
				scanf("%s",p->hours);
				fp = fopen("class_information.txt","w");
				r = head;
				do{
					r = r->next;
					fprintf(fp,"%s %s %s %s %s %s %s\n\n",r->coding,r->name,r->scope,r->type,r->credit,r->hours,r->teacher);
				}while(r->next != NULL);
				fclose(fp);
				r = NULL;
				system("cls");
				printf("\n----------------------修改成功！-------------------\n\n\n");
				while(1)
						{
						    printf("\t1.继续修改\t\t2.Back");
						    printf("\n\n\t输入您的选择:");
						    scanf("%d",&choice_1);
						    if(choice_1==1||choice_1==2)
						    break;
						    else
						    {
						    	system("cls");
						    	printf("\n您的选择有误，请重新选择！\n\n");
							}
						 } 
			    if(choice_1==1)
			    {
			    	system("cls");
			    	continue;
				}
				else
				{
					system("cls");
					break;
				}
			}
			else
			{
				printf("\n\n请输入更改后的主讲教师:");
				scanf("%s",p->teacher);
				fp = fopen("class_information.txt","w");
				r = head;
				do{
					r = r->next;
					fprintf(fp,"%s %s %s %s %s %s %s\n\n",r->coding,r->name,r->scope,r->type,r->credit,r->hours,r->teacher);
				}while(r->next != NULL);
				fclose(fp);
				r = NULL;
				system("cls");
				printf("\n-------------------------修改成功！------------------------\n\n\n");
				while(1)
						{
						    printf("\t1.继续修改\t2.Back");
						    printf("\n\n\t输入您的选择:");
						    scanf("%d",&choice_1);
						    if(choice_1==1||choice_1==2)
						    break;
						    else
						    {
						    	system("cls");
						    	printf("\n您的选择有误，请重新选择！\n\n");
							}
						 } 
				if(choice_1==1)
			    {
			    	system("cls");
			    	continue;
				}
				else
				{
					system("cls");
					break;
				}
			}
		}
	}
}

/*--------------------------------------------------------------------------------------------删除课程函数-----------------------------------------------------------------------------*/ 
 void Del_Course()
 {
 	system("cls");
 	FILE *fp;
 	list head,p,r;
 	Class_Inf temp;
 	int choice,judge;
 	char ch;
 	while(1)
 	{
 		judge = 0;
 		fp = fopen("class_information.txt","r");
 		if(fp==NULL)                                   //判断是否读取成功 
    	{
		printf("\nFailed to open the file.\n");
		exit(1);
    	}
    	printf("\n---------------------------请输入相关课程信息！---------------------------\n\n");
    	printf("\n\n\t请输入需要删除课程的编号或名称:");
    	scanf("%s",temp.coding);
		strcpy(temp.name,temp.coding);
		head = (list)malloc(sizeof(Class_Inf));
		head->next = NULL;
		r = head;
		while(!feof(fp))
		{
			p = (list)malloc(sizeof(Class_Inf));
			fscanf(fp,"%s %s %s %s %s %s %s\n\n",p->coding,p->name,p->scope,p->type,p->credit,p->hours,p->teacher);
			r->next = p;
			r = p;
		}
		r->next = NULL;
		r = NULL;
		p = NULL;
		fclose(fp);                                  //关闭文件 
		p = head;
		do{
			r = p;
			p = p->next;
			if(strcmp(p->coding,temp.coding)==0||strcmp(p->name,temp.name)==0)
			{
				judge = 1;
				break;
			}
		}while(p->next != NULL);
		if(judge==0)
		{
			system("cls");
			printf("\n-------------------------Sorry,未能查找到该课程！-----------------------------");
			while(1)
			{
				printf("\n\n\t1.重新输入\n\n");
				printf("\t2.Back\n\n");
				printf("\t3.Exit\n\n");
			    printf("\t请输入您的选择:");
			    scanf("%d",&choice);
			    if(choice==1||choice==2||choice==3)
			    break;
			    else
			    {
			    	system("cls");
				    printf("\n您的选择有误，请重新选择！\n");
			    }
			}
			if(choice==1)
			{
				system("cls");
				continue;
			}
			else if(choice==2)
			{
				system("cls");
				break;
			}
			else
			{
				system("cls");
			    printf("\n谢谢您的使用！\n");
			    exit(0);
			}
		}
		else
		{
			system("cls");
			printf("\n-----------------------成功查找到该课程！-------------------------\n\n");
			printf("该课程信息如下:\n\n");
			printf("课程编码 课程名称   适用专业             课程类型        学分  学时 主讲教师\n");
			printf("%-8s%-12s%-20s%-18s%-5s%-4s%-8s",p->coding,p->name,p->scope,p->type,p->credit,p->hours,p->teacher);
			while(1)
			{
				printf("\n\n\n是否删除该课程(Y or N):");
				fflush(stdin);                                 //清空输入 
				ch = getchar();
				if(ch=='Y'||ch=='y')
				break;
				else if(ch=='N'||ch=='n')
				break;
				else
				{
					system("cls");
					printf("\n该课程信息如下:\n\n");
					printf("课程编码 课程名称   适用专业             课程类型        学分  学时 主讲教师\n");
					printf("%-8s%-12s%-20s%-18s%-5s%-4s%-8s",p->coding,p->name,p->scope,p->type,p->credit,p->hours,p->teacher);
					printf("\n\n\n您的输入有误，请重新输入！");
					continue;
				}
			}
			if(ch=='Y'||ch=='y')
			{
				if(p->next != NULL)
				{
					r->next = p->next;
					p->next = NULL;
				}
				else
				{
					r->next = NULL;
				}
				r = NULL;
				p = NULL;
				fp = fopen("class_information.txt","w");
				if(fp==NULL)                                   //判断是否读取成功 
    	        {
        		printf("\nFailed to open the file.\n");
	        	exit(1);
            	}
				r = head;
				do{
					r = r->next;
					fprintf(fp,"%s %s %s %s %s %s %s\n\n",r->coding,r->name,r->scope,r->type,r->credit,r->hours,r->teacher);
				}while(r->next != NULL);
				fclose(fp);
				r = NULL;
				system("cls");
				printf("\n------------------------删除成功！------------------------\n\n");
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				printf("\n\n\t成功取消！");
				printf("\n\n\t3秒后自动返回！");
				for(int i=1;i<=30;i++)
				{
					printf("·");
					Sleep(100); 
				}
				system("cls");
				break;
			}
		}
	 }
 }
 
 /*--------------------------------------------------------------------------------------增加学生选课函数----------------------------------------------------------------------------*/
void Add_Stu_Select_Course()
{
	system("cls");
	FILE *fp;
	int i,size,choice,choice_1,judge,judge_1,judge_2,judge_3;
	Stu_list temp,head,p,r;
	list head1,p1,r1;
	temp = (Stu_list)malloc(sizeof(Stu));
	while(1)
	{
		fp = fopen("Stu_Select_Course.txt","r");
		if(fp ==NULL)
		{
			system("cls");
			printf("\nFailed to open the file.\n");
			exit(1);
		 } 
		head = (Stu_list)malloc(sizeof(Stu));
		head->next = NULL;
		r = head;
		while(!feof(fp))
		{
			p = (Stu_list)malloc(sizeof(Stu));
			fscanf(fp,"%s %s",p->id,p->name);
			for(i=0;i<14;i++)
			fscanf(fp," %s",p->course[i].Course_name);
			fscanf(fp," %s\n\n",p->course[14].Course_name);
			r->next = p;
			r = p;
		}
		r->next = NULL;
		fclose(fp);
		fp = fopen("class_information.txt","r");
		if(fp==NULL)                  //判断是否读取成功 
		{
			printf("\nFailed to open the file.\n");
			exit(1);
		}
		head1 = (list)malloc(sizeof(Class_Inf));
		head1->next = NULL;
		r1 = head1;
		size = 0;
		while(!feof(fp))
			{
				p1 = (list)malloc(sizeof(Class_Inf));
				fscanf(fp,"%s %s %s %s %s %s %s\n\n",p1->coding,p1->name,p1->scope,p1->type,p1->credit,p1->hours,p1->teacher);
				size++;
				r1->next = p1;
				r1 = p1;
			}
		r1->next = NULL;
		fclose(fp);
		while(1)
		{
			printf("\n\n1.增加已有学生选课\t\t2.增加新学生选课\n\n");
			printf("\n\n输入您的选择:");
			scanf("%d",&choice);
			if(choice==1||choice==2)
			break;
			else
			{
				system("cls");
				printf("\nSorry,您输入有误！请重新输入！");
			}
		}
	 if(choice==1)
	 {
	 	system("cls");
	 	judge = 0;
	 	printf("\n--------------------请输入学生的相关信息!------------------------\n");
	 	printf("\n\n\t请输入学生的学号或姓名:");
    	scanf("%s",temp->id);
    	strcpy(temp->name,temp->id); 
    	p = head;
    	do{
    		p = p->next;
    		if(strcmp(p->id,temp->id)==0||strcmp(p->name,temp->name)==0)
    		{
    			judge = 1;
    			break;
    		}
    	}while(p->next != NULL);
    	if(judge==0)
    	{
    		system("cls");
    		printf("\nSorry,您输入的学生不存在！\n\n");
    		continue;
		}
		else
		{
			judge_3 = 1;
			for(i=0;i<size;i++)
			if(strcmp(p->course[i].Course_name,"NULL")==0)
			{ 
				judge_3 = 0;
				break;
		    }
				if(judge_3==1)
		   {
			  	system("cls");
		    	printf("\n您已选择全部课程，无法继续增加课程！\n\n");
			  	system("pause");
			  	system("cls");
			  	break;
			}
			system("cls");
			printf("Class Information:\n\n");
			printf("课程编码 课程名称   适用专业             课程类型        学分  学时 主讲教师\n");
			p1 = head1;
			do{
				p1 = p1->next;
				printf("%-8s%-12s%-20s%-18s%-5s%-4s%-8s\n",p1->coding,p1->name,p1->scope,p1->type,p1->credit,p1->hours,p1->teacher);
			}while(p1->next != NULL);
			printf("\n学生信息为:");
			printf("\n学号:%s\t姓名:%s",p->id,p->name);
			printf("\n已选课程:");
			for(i=0;i<15;i++)
			if(strcmp(p->course[i].Course_name,"NULL")!=0)
			printf("%s ",p->course[i].Course_name);
			
			judge_1 = 0;
			judge_2 = 0;
			printf("\n\n输入增加课程的编码或者名称:");
			scanf("%s",temp->name);
			p1 = head1;
			do{
				p1 = p1->next;
				if(strcmp(temp->name,p1->name)==0||strcmp(temp->name,p1->coding)==0)
				{
					judge_1 = 1;
					break;
				}
			}while(p1->next != NULL);
			if(judge_1==0)
			{
				system("cls");
				printf("\nSorry,您输入的课程不存在！\n\n");
				continue; 
			}
			else
			{
				for(i=0;i<15;i++)
				if(strcmp(p1->name,p->course[i].Course_name)==0)
				{
					judge_2 = 1;
					break;
				}
				if(judge_2==1)
				{
					system("cls");
					printf("\n\n您选择的新课程已存在已选课程中！\n\n");
					continue;
				}
				else
				{
					for(i=0;i<15;i++)
					if(strcmp(p->course[i].Course_name,"NULL")==0)
					break;
					strcpy(p->course[i].Course_name,p1->name);
					fp = fopen("Stu_Select_Course.txt","w");
					r = head;
					do{
						r = r->next;
						fprintf(fp,"\n\n%s %s",r->id,r->name);
						for(i=0;i<14;i++)
						fprintf(fp," %s",r->course[i].Course_name);
						fprintf(fp," %s\n\n",r->course[14].Course_name);
					}while(r->next != NULL);
					fclose(fp);
					while(1)
					{
						printf("\nAdd Successful!");
						printf("\n\n1.继续增加\t\t2.Back");
						printf("\n输入您的选择:");
						scanf("%d",&choice_1);
						if(choice_1==1||choice_1==2)
						break;
						else
						{
							system("cls");
							printf("\n您的输入有误，请重新输入！\n");
						}
					 } 
					 if(choice_1==1)
					 {
					 	system("cls");
					 	continue;
					 }
					 else
					 {
					 	system("cls");
					 	break;
					 }
				}
			}
		}
	 }
	 else     //增加新学生选课 
	 {
	 	system("cls");
	 	printf("\n--------------------请输入学生的相关信息!------------------------\n");
	 	printf("\n\n\t请输入新学生的学号:");
    	scanf("%s",temp->id);
    	printf("\n\n\t请输入新学生的姓名:");
    	scanf("%s",temp->name);
    	
    	judge = 0;
    	p = head;
    	do{
    		p = p->next;
    		if(strcmp(temp->id,p->id)==0||strcmp(temp->name,p->name)==0)
    		{
    			judge = 1;
    			break;
			}
		}while(p->next != NULL);
		if(judge==1)
    	{
    		system("cls");
    		printf("\nSorry,您输入的学生已存在！\n\n");
    		continue;
		}
		else
		{
			 r = (Stu_list)malloc(sizeof(Stu));
			 strcpy(r->id,temp->id);
			 strcpy(r->name,temp->name);
			 for(i=0;i<15;i++)
			 strcpy(r->course[i].Course_name,"NULL");
			 system("cls");
			 while(1)
			 {
			 	 printf("Class Information:\n\n");
		   		 printf("课程编码 课程名称   适用专业             课程类型        学分  学时 主讲教师\n");
				 p1 = head1;
				 do{
					p1 = p1->next;
					printf("%-8s%-12s%-20s%-18s%-5s%-4s%-8s\n",p1->coding,p1->name,p1->scope,p1->type,p1->credit,p1->hours,p1->teacher);
				 }while(p1->next != NULL);
				 printf("\n\n输入增加课程的编码或者名称:");
				 scanf("%s",temp->name);
				 judge_1 = 0;
				 judge_2 = 0;
				 p1 = head1;
				 do{
					p1 = p1->next;
					if(strcmp(temp->name,p1->name)==0||strcmp(temp->name,p1->coding)==0)
					{
						judge_1 = 1;
						break;
					}
				 }while(p1->next != NULL);
				 if(judge_1==0)
				 {
				 	system("cls");
				 	printf("\nSorry,您输入的课程不存在！\n\n");
				 	continue;
				 }
				 else
				 {
				 	 for(i=0;i<15;i++)
				 	 if(strcmp(p1->name,r->course[i].Course_name)==0)
					 {
						judge_2 = 1;
						break;
				 	 }
				 	if(judge_2==1)
					{
						system("cls");
						printf("\n\n您选择的新课程已存在已选课程中！\n\n");
						continue;
					}
					else
					{
						for(i=0;i<15;i++)
						if(strcmp(r->course[i].Course_name,"NULL")==0)
						break;
						strcpy(r->course[i].Course_name,p1->name);
						judge_3 = 1;
						for(i=0;i<size;i++)
						if(strcmp(r->course[i].Course_name,"NULL")==0)
						{ 
							judge_3 = 0;
							break;
					    }
					    if(judge_3==1)
					    {
					    	system("cls");
					    	printf("\n您已选择全部课程，无法继续增加课程！\n\n");
					    	system("pause");
					    	system("cls");
					    	break;
						}
						while(1)
						{
							printf("\n\nAdd Successful!");
							printf("\n\n1.继续增加\t\t2.Back");
							printf("\n\n输入您的选择:");
							scanf("%d",&choice_1);
							if(choice_1==1||choice_1==2)
							break;
							else
							{
								system("cls");
								printf("\n您的输入有误，请重新输入！\n");
							}
						}
						if(choice_1==1)
						{
							system("cls");
							continue;
						}
						else
						{
							system("cls");
							break;
					    }
					}
				 }
			 }
			 fp = fopen("Stu_Select_Course.txt","a");
			 fprintf(fp,"\n\n%s %s",r->id,r->name);
			 for(i=0;i<14;i++)
			 fprintf(fp," %s",r->course[i].Course_name);
			 fprintf(fp," %s",r->course[14].Course_name);
			 fclose(fp);
			 if(choice_1==2)
			 break;
			 if(judge_3==1)
			 break;
		} 
	 }
    }
}
/*-------------------------------------------------------------------------------修改学生选课函数--------------------------------------------------------------------------------*/ 
void Revise_Stu_Select_Course()
{
	system("cls");
	FILE *fp;
	int i,choice,judge,judge_1;
	Stu temp;
	Stu_list head,p,r;
	while(1)
	{
		fp = fopen("Stu_Select_Course.txt","r");
		if(fp == NULL)
		{
			system("cls");
			printf("\nFailed to open the file.\n");
			exit(1);
		}
		head = (Stu_list)malloc(sizeof(Stu));
		head->next = NULL;
		r = head;
		while(!feof(fp))
		{
			p = (Stu_list)malloc(sizeof(Stu));
			fscanf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n\n",p->id,p->name,p->course[0].Course_name,p->course[1].Course_name,p->course[2].Course_name,
			p->course[3].Course_name,p->course[4].Course_name,p->course[5].Course_name,p->course[6].Course_name,p->course[7].Course_name,p->course[8].Course_name,
			p->course[9].Course_name,p->course[10].Course_name,p->course[11].Course_name,p->course[12].Course_name,p->course[13].Course_name,p->course[14].Course_name);
			r->next = p;
			r = p;
		}
		r->next = NULL;
		fclose(fp);
		r = NULL;
		p = NULL;
		judge = 0;
		printf("\n-------------------------请输入学生的相关信息!--------------------------");
		printf("\n\n\t\t请输入需修改学生的学号或姓名:");
    	scanf("%s",temp.id);
    	strcpy(temp.name,temp.id); 
    	p = head;
    	do{
    		p = p->next;
    		if(strcmp(p->id,temp.id)==0||strcmp(p->name,temp.name)==0)
    		{
    			judge =1;
    			break;
			}
		}while(p->next != NULL);
		if(judge==0)
		{
			system("cls");
			printf("\nSorry,您输入的学生不存在，请重新输入！");
			continue;
		}
		else
		{
			system("cls");
			printf("\t该名学生的选课信息为:\n\n");
			printf("\t学号:%-5s\n姓名:%-5s\n",p->id,p->name);
			printf("\t已选课程:");
			for(i=0;i<15;i++)
			{
				if(strcmp(p->course[i].Course_name,"NULL") != 0)
				printf("%-15s",p->course[i].Course_name);
			}
			while(1)
			{
				printf("\n\n\t请输入要进行修改的课程:");
		    	scanf("%s",temp.name);
		    	judge_1 = 0;
		    	for(i=0;i<15;i++)
		    	{
		    		if(strcmp(temp.name,p->course[i].Course_name)==0)
		    		{
		    			judge_1 = 1;
		    			break;
					}
		     	}
		    	if(judge_1==0)
		    	{
		    		system("cls");
		    		printf("\nSorry,您输入有误！请重新输入！");
		    		continue; 
	    		}
	    		else
	    		{
	    			system("cls");
	    			printf("\n\n\t请输入修改后的课程:");
	    			scanf("%s",temp.name);
	    			for(int k=0;k<15;k++)
	    			{
	    				if(strcmp(temp.name,p->course[k].Course_name)==0)
	    				{
	    					system("cls");
	    					printf("\nSorry,您输入的课程已存在，请重新输入！");
	    					continue;
						}
					}
				}
				strcpy(p->course[i].Course_name,temp.name);
				fp = fopen("Stu_Select_Course.txt","w");
				p = head;
				do{
	            	p = p->next;
	            	fprintf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n\n",p->id,p->name,p->course[0].Course_name,p->course[1].Course_name,p->course[2].Course_name,
	            	p->course[3].Course_name,p->course[4].Course_name,p->course[5].Course_name,p->course[6].Course_name,p->course[7].Course_name,p->course[8].Course_name,
		            p->course[9].Course_name,p->course[10].Course_name,p->course[11].Course_name,p->course[12].Course_name,p->course[13].Course_name,p->course[14].Course_name);
                	}while(p->next != NULL);
                fclose(fp);
                p = NULL;
                break;
			}
		}
		system("cls");
		while(1)
		{
			printf("\n--------------------------修改成功！-----------------------\n");
	    	printf("\n\t1.继续修改\t\t2.Back");
    		printf("\n\n\t请输入您的选择");
	    	scanf("%d",&choice);
	    	if(choice==1||choice==2)
	    	break;
	    	else
	    	{
	    		system("cls");
	    		printf("\n您的输入有误，请重新输入！\n");
			}
		}
		if(choice==1)
		{
			system("cls");
			continue;
		}
		else
		{
			system("cls");
			break;
		}
	}
}

/*---------------------------------------------------------------------删除学生选课函数----------------------------------------------------------------------------*/
 void Del_Stu_Select_Course()
 {
 	 system("cls");
 	 FILE *fp;
	 int i,choice,judge,judge_1;
	 Stu temp;
	 Stu_list head,p,r;
	 while(1)
	 {
	 	fp = fopen("Stu_Select_Course.txt","r");
	 	if(fp == NULL)
	 	{
	 		system("cls");
	 		printf("\nFailed to open the file.\n");
	 		exit(1);
		 }
		 head = (Stu_list)malloc(sizeof(Stu));
		 head->next = NULL;
		 r = head;
		 while(!feof(fp))
		 {
		 	p = (Stu_list)malloc(sizeof(Stu));
		 	fscanf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n\n",p->id,p->name,p->course[0].Course_name,p->course[1].Course_name,p->course[2].Course_name,
			p->course[3].Course_name,p->course[4].Course_name,p->course[5].Course_name,p->course[6].Course_name,p->course[7].Course_name,p->course[8].Course_name,
			p->course[9].Course_name,p->course[10].Course_name,p->course[11].Course_name,p->course[12].Course_name,p->course[13].Course_name,p->course[14].Course_name);
			r->next = p;
			r = p;
		 }
		 r->next = NULL;
		 fclose(fp);
		 r = NULL;
		 p = NULL;
	 	judge = 0;
	 	printf("\n--------------------------请输入学生相关信息！---------------------------");
	 	printf("\n\n\t请输入学生学号或姓名:");
	 	scanf("%s",temp.id);
	 	strcpy(temp.name,temp.id);
	 	p = head;
	 	do{
	 		p = p->next;
	 		if(strcmp(temp.id,p->id)==0||strcmp(temp.name,p->name)==0)
	 		{
	 			judge = 1;
	 			break;
			 }
		 }while(p->next != NULL);
		 if(judge==0)
		 {
		 	system("cls");
		 	printf("\nSorry,您输入的学生不存在，您重新输入！\n\n");
		 	continue;
		 }
		 else
		 {
		 	system("cls");
		 	printf("\n\t查找成功！\n\n");
		 	printf("\t该名学生选课信息为:\n\n");
		 	printf("\t学号:%-5s\n\n\t姓名:%-5s\n\n",p->id,p->name);
		 	printf("\t已选课程:");
		 	for(i=0;i<15;i++)
		 	{
		 		if(strcmp(p->course[i].Course_name,"NULL") != 0)
		 		printf("%-15s",p->course[i].Course_name);
			 }
			 while(1)
			 {
				 printf("\n\n\n\t请输入要进行删除的课程名称:");
		    	 scanf("%s",temp.name);
		    	 judge_1 = 0;
		    	 for(i=0;i<15;i++)
		    	 {
		    	 	if(strcmp(temp.name,p->course[i].Course_name)==0)
		    	 	{
			 	    	judge_1 = 1;
			     		break;
		     		 }
			     }
	      		 if(judge_1==0)
		    	 {
			    	system("cls");
			    	printf("\n\n您输入的课程不存在！请重新输入！"); 
			    	continue;
			     }
		    	 else
		    	 {
			    	strcpy(p->course[i].Course_name,"NULL");
			    	fp = fopen("Stu_Select_Course.txt","w");
			 	    p = head;
		    	 	do{
			 		p = p->next;
			   		fprintf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n\n",p->id,p->name,p->course[0].Course_name,p->course[1].Course_name,p->course[2].Course_name,
		            p->course[3].Course_name,p->course[4].Course_name,p->course[5].Course_name,p->course[6].Course_name,p->course[7].Course_name,p->course[8].Course_name,
		            p->course[9].Course_name,p->course[10].Course_name,p->course[11].Course_name,p->course[12].Course_name,p->course[13].Course_name,p->course[14].Course_name);
		    		 }while(p->next != NULL);
		    		 fclose(fp);
			    	 p = NULL;
			    	 break; 
			     } 
			 }
		 }
		 system("cls");
		 printf("\n-------------------------删除成功！-----------------------------\n");
		 while(1)
		 {
		 	 printf("\n\n\t1.继续删除");
	    	 printf("\n\n\t2.Back");
	    	 printf("\n\n\t请输入您的选择:");
	    	 scanf("%d",&choice);
	    	 if(choice==1||choice==2)
	    	 break;
	    	 else
	    	 {
	    	 	system("cls");
	    	 	printf("\n您的输入有误！请重新输入！\n");
			 }
		 }
		 if(choice==1)
		 {
		 	system("cls");
		 	continue;
		 }
		 else
		 {
		 	system("cls");
		 	break;
		 }
	 }
  }
  
/*------------------------------------------------------------------------通过课程查询-------------------------------------------------------------------------------*/       
void Inquire_By_Course()       
{
	system("cls");
	int i,k,choice,judge;
	char temp[20],change[20];
	FILE *fp;
	fp = fopen("Stu_Select_Course.txt","r");
	if(fp == NULL)
	{
		system("cls");
		printf("\nFailed to open the file.\n");
		exit(1);
	}
	Stu_list head,p,r;
	head = (Stu_list)malloc(sizeof(Stu));
	head->next = NULL;
	r = head;
	while(!feof(fp))
	{
		p = (Stu_list)malloc(sizeof(Stu));
		fscanf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n\n",p->id,p->name,p->course[0].Course_name,p->course[1].Course_name,p->course[2].Course_name,
		p->course[3].Course_name,p->course[4].Course_name,p->course[5].Course_name,p->course[6].Course_name,p->course[7].Course_name,p->course[8].Course_name,
		p->course[9].Course_name,p->course[10].Course_name,p->course[11].Course_name,p->course[12].Course_name,p->course[13].Course_name,p->course[14].Course_name);
		r->next = p;
		r = p;
	}
	r->next = NULL;
	fclose(fp);
	r = NULL;
	p = NULL;
	fp = fopen("class_information.txt","r");
	if(fp ==NULL)
	{
		system("cls");
		printf("\nFailed to open the file.\n");
		exit(1);
	}
	list head1,p1,r1;
	head1 = (list)malloc(sizeof(Class_Inf));
	head1->next = NULL;
	r1 = head1;
	while(!feof(fp))
	{
		p1 = (list)malloc(sizeof(Class_Inf));
		fscanf(fp,"%s %s %s %s %s %s %s\n\n",p1->coding,p1->name,p1->scope,p1->type,p1->credit,p1->hours,p1->teacher);
		r1->next = p1;
		r1 = p1;
	}
	r1->next = NULL;
	fclose(fp);
	r1 = NULL;
	p1 = NULL;
	while(1)
	{
		printf("-------------------------------请输入课程相关信息------------------------------\n\n");
		printf("您可以查询的课程有:");
		p1 = head1;
		k = 0;
		do{
			p1 = p1->next;
			printf("%-12s",p1->name);
			k++;
			if(k==4)
			{
				printf("\n\t\t   ");
				k = 0;
			}
		}while(p1->next != NULL);
		p1 = NULL;
		printf("\n\n\n请输入需要查找的课程名称(不区分大小写):");
		scanf("%s",temp);
		for(k=0;temp[k] != '\0';k++)
		temp[k] = tolower(temp[k]);
		judge = 0;
		p1 = head1;
		do{
			p1 = p1->next;
			for(k=0;p1->name[k]!='\0';k++)
			change[k] = tolower(p1->name[k]);
			change[k] = '\0';
			if(strcmp(temp,change)==0)
			{
				judge = 1;
				break;
			}
		}while(p1->next != NULL);
		p1 = NULL;
		if(judge==0)
		{
			system("cls");
			printf("\nSorry,您输入的课程不存在！请重新输入！\n\n");
			continue;
		}
		judge = 0;
		printf("\n\n\n选择该课程的学生有:");
		p = head;
		do{
			p = p->next;
			for(i=0;i<15;i++)
			{
				if(strcmp(p->course[i].Course_name,"NULL")!=0)
				{
					for(k=0;p->course[i].Course_name[k]!='\0';k++)
					change[k] = tolower(p->course[i].Course_name[k]);
					change[k] = '\0';
					if(strcmp(temp,change)==0)
					{
						judge = 1;
						printf("%-7s",p->name);
					}
				}
			}
		}while(p->next != NULL);
		p = NULL;
		if(judge==0)
		{
			printf(" 无学生选择该课程！");
		}
		while(1)
		{
			printf("\n\n\n1.继续查询\t\t2.Back");
	    	printf("\n\n请输入您的选择:");
	     	scanf("%d",&choice);
	     	if(choice==1||choice==2)
	     	break;
	     	else
	     	{
	     		system("cls");
	     		printf("\n您的选择有误，请重新选择！\n");
			 }
		}
		if(choice==1)
		{
			system("cls");
			continue;
		}
		else
		{
			system("cls");
			break;
		}
	}
}

/*----------------------------------------------------------------------------通过学分查询----------------------------------------------------------------------------*/       
void Inquire_By_Credit() 
{
	system("cls"); 
	float temp,sum_credit;
	int i,choice,judge,judge_1; 
    FILE *fp;
 	fp = fopen("Stu_Select_Course.txt","r");
 	if(fp == NULL)
 	{
 		system("cls");
 		printf("\nFailed to open the file.\n");
 		exit(1);
	 }
	 list head1,p1,r1;                    //课程信息的链表 
	 Stu_list head,p,r;                  //学生选课信息的链表 
	 head = (Stu_list)malloc(sizeof(Stu));
	 head->next = NULL;
	 r = head;
	 while(!feof(fp))
	 {
	 	p = (Stu_list)malloc(sizeof(Stu));
	 	fscanf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n\n",p->id,p->name,p->course[0].Course_name,p->course[1].Course_name,p->course[2].Course_name,
		p->course[3].Course_name,p->course[4].Course_name,p->course[5].Course_name,p->course[6].Course_name,p->course[7].Course_name,p->course[8].Course_name,
		p->course[9].Course_name,p->course[10].Course_name,p->course[11].Course_name,p->course[12].Course_name,p->course[13].Course_name,p->course[14].Course_name);
		r->next = p;
		r = p;
	 }
	 r->next = NULL;
	 r = NULL;
	 p = NULL;
	 fclose(fp);
	 fp = fopen("class_information.txt","r");
	if(fp ==NULL)
	{
		system("cls");
		printf("\nFailed to open the file.\n");
		exit(1);
	}
	head1 = (list)malloc(sizeof(Class_Inf));
	head1->next = NULL;
	r1 = head1;
	while(!feof(fp))
	{
		p1 = (list)malloc(sizeof(Class_Inf));
		fscanf(fp,"%s %s %s %s %s %s %s\n\n",p1->coding,p1->name,p1->scope,p1->type,p1->credit,p1->hours,p1->teacher);
		r1->next = p1;
		r1 = p1;
	}
	r1->next = NULL;
	fclose(fp);
	r1 = NULL;
	p1 = NULL;
	while(1)
	{
		printf("\n\n---------------------------------通过学分查询----------------------------------\n\n");
    	printf("\n\n请输入需要查询的学分:");
    	scanf("%f",&temp);
    	printf("\n\n选课总学分为%-2.1f的学生信息为:",temp);
    	judge = 0;
    	p = head;
    	do{
    		sum_credit = 0;
    		p = p->next;
    		for(i=0;i<15;i++)
    		{
    			if(strcmp(p->course[i].Course_name,"NULL") != 0)
    			{
    				p1 = head1;
    				do{
    					p1 = p1->next;
    					if(strcmp(p->course[i].Course_name,p1->name)==0)
    					{
    						sum_credit += atoi(p1->credit);
    					}
					}while(p1->next != NULL);
				}
			}
			if(temp==sum_credit)
			{
				judge = 1;
				printf("%-6s--已选课程: ",p->name);
				judge_1 = 0;
			    for(i=0;i<15;i++)
		    	{
		    		if(strcmp(p->course[i].Course_name,"NULL" )!= 0)
		    		{
		    			judge_1 = 1;
		    			printf("%-10s",p->course[i].Course_name);
		    		}
		    	}
		    	if(judge_1==0)
		    	{
		    		printf("无课程选择");
				}
		   	}
			if(judge==1)
			printf("\n\t\t            ");
		}while(p->next != NULL);
		p = NULL;
		p1 = NULL;
		if(judge==0)
		{
			printf(" 未查询到符合条件的学生信息！");
		}
		while(1)
		{
			printf("\n\n\n\n1.继续查询\t\t2.Back");
    		printf("\n\n请输入您的选择:");
	    	scanf("%d",&choice);
	    	if(choice==1||choice==2)
	    	break;
	    	else
	    	{
	    		system("cls");
	    		printf("您的选择有误，请重新选择！\n");
			}
		}
		if(choice==1)
		{
			system("cls");
			continue;
		}
		else
		{
			system("cls");
			break;
		}
	}
}

/*--------------------------------------------------------------------按学号查询函数-----------------------------------------------------------------------*/ 
void Inquire_By_Stu_Id()
{
	system("cls");
	int i,choice,judge,judge_1;
	char temp[10]; 
	Stu_list head,p,r;
	FILE *fp;
	fp = fopen("Stu_Select_Course.txt","r");
	if(fp == NULL)
	{
		system("cls");
		printf("\nFailed to open the file.\n");
		exit(1);
	}
	head = (Stu_list)malloc(sizeof(Stu));
	head->next = NULL;
	r = head;
	while(!feof(fp))
	{
		p = (Stu_list)malloc(sizeof(Stu));
		fscanf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n\n",p->id,p->name,p->course[0].Course_name,p->course[1].Course_name,p->course[2].Course_name,
		p->course[3].Course_name,p->course[4].Course_name,p->course[5].Course_name,p->course[6].Course_name,p->course[7].Course_name,p->course[8].Course_name,
		p->course[9].Course_name,p->course[10].Course_name,p->course[11].Course_name,p->course[12].Course_name,p->course[13].Course_name,p->course[14].Course_name);
		r->next = p;
		r = p;
	}
	r->next = NULL;
	fclose(fp);
	r = NULL;
	p = NULL;
	while(1)
	{
		judge = 0;
		printf("-------------------------------请输入相关信息------------------------------\n");
		printf("\n\n请输入需要查找的学号:");
		scanf("%s",temp);
		p = head;
		do{
			p = p->next;
			if(strcmp(temp,p->id)==0)
			{
				judge = 1;
				break;
			}
		}while(p->next != NULL);
		if(judge==0)
		{
			printf("\n\nSorry,未查找到相关信息！"); 
		}
		else
		{
			printf("\n\n学号:%-10s",p->id);
			printf("\n\n姓名:%-15s",p->name);
			printf("\n\n已选课程:");
			judge_1 = 0;
			for(i=0;i<15;i++)
			{
				if(strcmp(p->course[i].Course_name,"NULL") != 0)
				{
					judge_1 = 1;
					printf("%-10s",p->course[i].Course_name);
				}
			}
			if(judge_1==0)
			printf("无已选课程！");
		}
		while(1)
		{
			printf("\n\n\n1.继续查找\t\t2.Back");
	    	printf("\n\n输入您的选择:");
	    	scanf("%d",&choice); 
	    	if(choice==1||choice==2)
	    	break;
	    	else
	    	{
	    		system("cls");
	    		printf("您的输入有误，请重新输入！\n");
			}
		}
		if(choice==1)
		{
			system("cls");
			continue;
		}
		else
		{
			system("cls");
			break;
		}
	}
}

/*------------------------------------------------------------------按课程统计选课结果------------------------------------------------------------------------------*/ 
void Count_By_A_Course()
{
	system("cls");
	int i,k,choice,judge;
	char temp[20],change[20];
	FILE *fp;
	fp = fopen("Stu_Select_Course.txt","r");
	if(fp == NULL)
	{
		system("cls");
		printf("\nFailed to open the file.\n");
		exit(1);
	}
	Stu_list head,p,r;
	head = (Stu_list)malloc(sizeof(Stu));
	head->next = NULL;
	r = head;
	while(!feof(fp))
	{
		p = (Stu_list)malloc(sizeof(Stu));
		fscanf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n\n",p->id,p->name,p->course[0].Course_name,p->course[1].Course_name,p->course[2].Course_name,
		p->course[3].Course_name,p->course[4].Course_name,p->course[5].Course_name,p->course[6].Course_name,p->course[7].Course_name,p->course[8].Course_name,
		p->course[9].Course_name,p->course[10].Course_name,p->course[11].Course_name,p->course[12].Course_name,p->course[13].Course_name,p->course[14].Course_name);
		r->next = p;
		r = p;
	}
	r->next = NULL;
	fclose(fp);
	r = NULL;
	p = NULL;
	fp = fopen("class_information.txt","r");
	if(fp ==NULL)
	{
		system("cls");
		printf("\nFailed to open the file.\n");
		exit(1);
	}
	list head1,p1,r1;
	head1 = (list)malloc(sizeof(Class_Inf));
	head1->next = NULL;
	r1 = head1;
	while(!feof(fp))
	{
		p1 = (list)malloc(sizeof(Class_Inf));
		fscanf(fp,"%s %s %s %s %s %s %s\n\n",p1->coding,p1->name,p1->scope,p1->type,p1->credit,p1->hours,p1->teacher);
		r1->next = p1;
		r1 = p1;
	}
	r1->next = NULL;
	fclose(fp);
	r1 = NULL;
	p1 = NULL;
	while(1)
	{
		printf("-------------------------------请输入相关信息------------------------------\n\n");
		printf("您可以统计的课程有:");
		p1 = head1;
		k = 0;
		do{
			p1 = p1->next;
			printf("%-12s",p1->name);
			k++;
			if(k==4)
			{
				printf("\n\t\t   ");
				k = 0;
			}
		}while(p1->next != NULL);
		p1 = NULL;
		printf("\n\n\n请输入需要统计的课程名称(不区分大小写):");
		scanf("%s",temp);
		for(k=0;temp[k] != '\0';k++)
		temp[k] = tolower(temp[k]);
		judge = 0;
		p1 = head1;
		do{
			p1 = p1->next;
			for(k=0;p1->name[k]!='\0';k++)
			change[k] = tolower(p1->name[k]);
			change[k] = '\0';
			if(strcmp(temp,change)==0)
			{
				judge = 1;
				break;
			}
		}while(p1->next != NULL);
		p1 = NULL;
		if(judge==0)
		{
			system("cls");
			printf("\nSorry,您输入的课程不存在！请重新输入！\n\n");
			continue;
		}
		judge = 0;
		printf("\n\n\n选择该课程的学生有:");
		p = head;
		do{
			p = p->next;
			for(i=0;i<15;i++)
			{
				if(strcmp(p->course[i].Course_name,"NULL")!=0)
				{
					for(k=0;p->course[i].Course_name[k]!='\0';k++)
					change[k] = tolower(p->course[i].Course_name[k]);
					change[k] = '\0';
					if(strcmp(temp,change)==0)
					{
						judge = 1;
						printf("%-7s",p->name);
					}
				}
			}
		}while(p->next != NULL);
		p = NULL;
		if(judge==0)
		{
			printf(" 无学生选择该课程！");
		}
		while(1)
		{
			printf("\n\n\n1.统计其他课程\t\t2.Back");
	    	printf("\n\n请输入您的选择:");
	     	scanf("%d",&choice);
	     	if(choice==1||choice==2)
	     	break;
	     	else
	     	{
	     		system("cls");
	     		printf("\n您的选择有误，请重新选择！\n");
			 }
		}
		if(choice==1)
		{
			system("cls");
			continue;
		}
		else
		{
			system("cls");
			break;
		}
	}
}
