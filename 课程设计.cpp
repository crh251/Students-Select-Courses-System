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
 

void Main_Menu();                       //���˵� 

void login();                            //����Ա��¼ 

int Second_Level_Menu();                //�����˵� 

int Course_Management_Menu();            //�γ̹���˵� 

int Stu_Select_Course_Management_Menu();             //ѧ��ѡ�ι���˵� 

int Inquire_Select_Course_Result_Menu();             //ѡ�ν����ѯ�˵� 

int Count_Select_Course_Result_Menu();              //ͳ��ѡ����Ϣ�˵� 

void look_class_information();               //����γ���Ϣ 

void Add_Course();                           //���ӿγ̺��� 

void Revise_Course();                   //�޸Ŀγ̺��� 

void Del_Course();                      //ɾ���γ̺��� 

void Add_Stu_Select_Course();          //����ѧ��ѡ��

void Revise_Stu_Select_Course();         //�޸�ѧ��ѡ�� 

void Del_Stu_Select_Course();           //ɾ��ѧ��ѡ�� 

void Inquire_By_Course();               //���γ̲�ѯ 

void Inquire_By_Credit();             //��ѧ�ֲ�ѯ 

void Inquire_By_Stu_Id();            //��ѧ�Ų�ѯ   

void Count_By_A_Course();        //ͳ��ĳ�ſγ�ѡ�ν��  

void Count_By_Unqualified(); 

int main()
{
	int choice_1,choice_2;
	while(1)
	{
		Main_Menu();                   //���˵�
		login();
		while(1)
		{
			choice_1 = Second_Level_Menu();              //�����˵�
			if(choice_1==1)
			{
				while(1)
				{
					choice_2 = Course_Management_Menu();
					if(choice_2 == 1)
			    	look_class_information();
					else if(choice_2 == 2)
					Add_Course();                    //���ӿγ� 
					else if(choice_2 == 3 )
					Revise_Course();                 //�޸Ŀγ� 
					else if(choice_2 == 4)
					Del_Course();                   //ɾ���γ� 
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
    				Add_Stu_Select_Course();      //����ѧ��ѡ�� 
					else if(choice_2 == 2)
					Revise_Stu_Select_Course();      //�޸�ѧ��ѡ�� 
					else if(choice_2 == 3)
					Del_Stu_Select_Course();        //ɾ��ѧ��ѡ�� 
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
					Inquire_By_Course();         //���γ̲�ѯ 
					else if(choice_2 == 2)
					Inquire_By_Credit();         //��ѧ�ֲ�ѯ 
					else if(choice_2 == 3)
					Inquire_By_Stu_Id();         //��ѧ�Ų�ѯ 
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
					Count_By_A_Course();             //ͳ��ĳ�ſγ�ѡ�ν��
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
  
/*---------------------------------------------------------------------------ͳ��ѡ�β��ϸ�����----------------------------------------------------------------------*/ 
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
	 Stu_list head,p,r;                  //ѧ��ѡ����Ϣ������ 
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
	list head1,p1,r1;                    //�γ���Ϣ������ 
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
		printf("\n\n----------------------ͳ�Ʋ�����Ҫ��ѧ����Ϣ----------------------\n\n");
    	printf("\n����������Ҫ������ѧ��:");
    	scanf("%f",&Min_Req); 
    	printf("\nѡ����ѧ�ֲ�����%-2.1fѧ�ֵ�ѧ����ϢΪ:",Min_Req);
    	judge = 1;
    	p = head;                    //ѧ��ѡ����Ϣ������ 
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
				printf("\n\nѧ��:%-10s\n\n����:%-15s\n\n",p->id,p->name);
				printf("��ѡ�γ�:");
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
		    		printf("�޿γ�ѡ��");
				}
		   	}
		   	if(judge==0)
		   	printf("\n");
		}while(p->next != NULL);
		p = NULL;
		p1 = NULL;
		if(judge==1)
		{
			printf("\n\n����ѧ���������Ҫ�󣬲����ڲ������Ҫ���ѧ����");
		}
		while(1)
		{
			printf("\n\n1.����ͳ��\t\t2.Back");
    		printf("\n\n����������ѡ��:");
	    	scanf("%d",&choice);
	    	if(choice==1||choice==2)
	    	break;
	    	else
	    	{
	    		system("cls");
	    		printf("����ѡ������������ѡ��\n");
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
       
/*------------------------------------------------------------------------------------���˵�-----------------------------------------------------------------------------------*/ 
void Main_Menu()       
{
	int choice;
	while(1)
	{
		printf("\n\t\tMenu:\n\n");
     	printf("\t\t1.ѡ����Ϣ����(����Ա)\n\n");
	    printf("\t\t2.�˳�\n\n");
	    printf("\t\t����������ѡ��:");                    
		scanf("%d",&choice);                                                               
		if(choice==1)
		break;
		else if(choice==2)
		{
			system("cls");
			printf("\nлл����ʹ�ã�\n");
			exit(0);
		}
		else                       //ѡ���������ѡ�� 
		{
			system("cls");
			printf("����ѡ������������ѡ��\n");
		}
	}
}

 /*----------------------------------------------------------------------------����Ա��¼����-----------------------------------------------------------*/ 
 void login()
 {
 	system("cls");
 	char account[10],password[10];
 	int time = 0;
 	while(1)
 	{
 		printf("--------------------����Ա��¼(�˺�:admin ����:admin)--------------------\n\n\n");
 		printf("\t\t�˻�:");
 		scanf("%s",account);
 		printf("\n\n\t\t����:");
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
 			printf("\n��������˺Ż������������������룡\n\n");
		 }
		 if(time==3)
		 {
		 	system("cls");
		 	printf("\nSorry�����Ѿ�����3������������Ժ����ԣ�\n");
		 	exit(0);
		 }
	 }
 }
 
/*-----------------------------------------------------------------�����˵�----------------------------------------------------------*/ 
 int Second_Level_Menu()
 {
 	int choice;
 	while(1)
 	{
 		printf("\n\t\tMenu:\n\n");
     	printf("\t\t1.�γ̹���\n\n");
	    printf("\t\t2.ѧ��ѡ�ι���\n\n");
	    printf("\t\t3.ѡ�ν����ѯ\n\n");
	    printf("\t\t4.ͳ��ѡ����Ϣ\n\n");
	    printf("\t\t5.Back\n\n");
	    printf("\t\t6.Exit\n\n");
	    printf("\t\t����������ѡ��:");                    
		scanf("%d",&choice);
		if(choice==1||choice==2||choice==3||choice==4||choice==5)
		{
			system("cls");
			break;
		}
		else if(choice==6)
		{
			system("cls");
			printf("\nлл����ʹ�ã�\n");
			exit(0);
		}
		else
		{
			system("cls");
			printf("\n����ѡ������������ѡ��\n");
		 } 
	 }
	 return choice;
 }
 
 /*---------------------------------------------------------------------------�γ̹���˵�-----------------------------------------------------------------------*/ 
 int Course_Management_Menu()
 {
 	int choice;
 	while(1)
 	{
 		printf("\n\t\tMenu:\n\n");
     	printf("\t\t1.����γ���Ϣ\n\n");
	    printf("\t\t2.¼��γ���Ϣ\n\n");
	    printf("\t\t3.�޸Ŀγ���Ϣ\n\n");
	    printf("\t\t4.ɾ���γ���Ϣ\n\n");
	    printf("\t\t5.Back\n\n");
	    printf("\t\t6.Exit\n\n");
	    printf("\t\t����������ѡ��:");                    
		scanf("%d",&choice);
		if(choice==1||choice==2||choice==3||choice==4||choice==5)
		{
			system("cls");
			break;
		}
		else if(choice==6)
		{
			system("cls");
			printf("\nлл����ʹ�ã�\n");
			exit(0);
		}
		else
		{
			system("cls");
			printf("\n����ѡ������������ѡ��\n");
		 } 
	 }
	 return choice; 
 }
 
 /*--------------------------------------------------------------------------ѧ��ѡ�ι���˵�----------------------------------------------------------------*/ 
 int Stu_Select_Course_Management_Menu()
 {
   int choice;
   while(1)
   {
	 printf("\n\t\tMenu:\n\n");
   	 printf("\t\t1.����ѧ��ѡ��\n\n");
	 printf("\t\t2.�޸�ѧ��ѡ��\n\n");
     printf("\t\t3.ɾ��ѧ��ѡ��\n\n");
	 printf("\t\t4.Back\n\n");
	 printf("\t\t5.Exit\n\n");
	 printf("\t\t����������ѡ��:");               
	 scanf("%d",&choice);
	 if(choice==1||choice==2||choice==3||choice==4)
		{
			system("cls");
			break;
		}
	 else if(choice==5)
		{
			system("cls");
			printf("\nлл����ʹ�ã�\n");
			exit(0);
		}
	 else
		{
			system("cls");
			printf("\n����ѡ������������ѡ��\n");
		 } 
   }
   return choice;	
 }
 
 /*-----------------------------------------------------ѡ�ν����ѯ�˵�--------------------------------------------------------------*/ 
 int Inquire_Select_Course_Result_Menu()
 {
 	int choice;
 	while(1)
 	{
 		printf("\n\t\tMenu:\n\n");
   	    printf("\t\t1.���γ̲�ѯ\n\n");
	    printf("\t\t2.��ѧ�ֲ�ѯ\n\n");
        printf("\t\t3.��ѧ�Ų�ѯ\n\n");
   	    printf("\t\t4.Back\n\n");
	    printf("\t\t5.Exit\n\n");
	    printf("\t\t����������ѡ��:");               
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
			printf("\nлл����ʹ�ã�\n");
			exit(0);
		}
	    else
		{
			system("cls");
			printf("\n����ѡ������������ѡ��\n");
		 } 
	 }
	 return choice; 
 }
 
 /*---------------------------------------------------ͳ��ѡ����Ϣ�˵�-------------------------------------------------*/ 
 int Count_Select_Course_Result_Menu()
 {
 	int choice;
	 while(1)
	 {
	 	printf("\n\t\tMenu:\n\n");
   	    printf("\t\t1.ͳ��ĳ�ſγ�ѧ��ѡ�����\n\n");
	    printf("\t\t2.ͳ��ѡ�β��ϸ��ѧ������\n\n");
   	    printf("\t\t3.Back\n\n");
	    printf("\t\t4.Exit\n\n");
	    printf("\t\t����������ѡ��:");               
	    scanf("%d",&choice);
	    if(choice==1||choice==2||choice==3)
		{
			system("cls");
			break;
		}
	    else if(choice==4)
		{
			system("cls");
			printf("\nлл����ʹ�ã�\n");
			exit(0);
		}
	    else
		{
			system("cls");
			printf("\n����ѡ������������ѡ��\n");
		 } 
	  }
	  return choice; 
 }
 
 /*---------------------------------------------------------------------------����γ���Ϣ����---------------------------------------------------------------------*/ 
void look_class_information()
{
	Class_Inf class_data;
	int choice;
	system("cls");
	FILE *class_infor;
	class_infor = fopen("class_information.txt","r");                  //��class_information.txt�ж�ȡ�ļ� 
	if(class_infor==NULL)                  //�ж��Ƿ��ȡ�ɹ� 
	{
		printf("\nFailed to open the file.\n");
		exit(1);
	}
	printf("Class Information:\n\n");
	printf("�γ̱��� �γ�����   ����רҵ             �γ�����        ѧ��  ѧʱ ������ʦ\n");
	while(!feof(class_infor))
	    {
	    	fscanf(class_infor,"%s %s %s %s %s %s %s\n\n",class_data.coding,class_data.name,class_data.scope,class_data.type,class_data.credit,class_data.hours,class_data.teacher);
	    	printf("%-8s%-12s%-20s%-18s%-5s%-4s%-8s\n",class_data.coding,class_data.name,class_data.scope,class_data.type,class_data.credit,class_data.hours,class_data.teacher);
		}
	fclose(class_infor);                       //�ر�class_information.txt 
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
			printf("\nлл����ʹ�ã�\n");
			exit(0);
		}
	    else
		 {                                    //ѡ���������ѡ�� 
	     	system("cls");
	     	printf("\n����ѡ������������ѡ��\n");
		}
	}
}

  /*-------------------------------------------------------------------���ӿγ̺���------------------------------------------------------------*/ 
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
		if(fp==NULL)                  //�ж��Ƿ��ȡ�ɹ� 
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
		printf("\n-----------------------������Ҫ���ӿγ̵������Ϣ!-----------------------");
		printf("\n\n\t\t�γ̱���:");
		scanf("%s",temp->coding);
		printf("\n\n\t\t�γ�����:");
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
				printf("\n\t�Ѵ�����ͬ�γ̱�Ż����ƵĿγ̣������벻ͬ�γ̱�ź����ƵĿγ̣�\n\n");
		    	printf("\t\t1.��������\n\n");
			    printf("\t\t2.Back\n\n");
	    		printf("\t\t3.Exit\n\n");
		    	printf("\t\t����������ѡ��:");
		     	scanf("%d",&choice);
		     	if(choice==1||choice==2||choice==3)
		     	break;
		     	else
		     	{
		     		system("cls");
	         	    printf("����ѡ������������ѡ��\n");
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
			    printf("\nлл����ʹ�ã�\n");
			    exit(0);
			}	
		}
		else
		{
			printf("\n\n\t\t����רҵ:");
			scanf("%s",temp->scope);
			printf("\n\n\t\t�γ�����:");
			scanf("%s",temp->type);
			printf("\n\n\t\t    ѧ��:");
			scanf("%s",temp->credit);
			printf("\n\n\t\t    ѧʱ:");
			scanf("%s",temp->hours);
			printf("\n\n\t\t������ʦ:");
			scanf("%s",temp->teacher);
			fp = fopen("class_information.txt","a");
			fprintf(fp,"%s %s %s %s %s %s %s\n\n",temp->coding,temp->name,temp->scope,temp->type,temp->credit,temp->hours,temp->teacher);
			fclose(fp);
			system("cls");
			printf("\n--------------------------------�ɹ����ӿγ̣�--------------------------------\n");
			while(1)
			{
				printf("\n\n\t\t1.�������ӿγ�\n\n");
		     	printf("\t\t2.Back\n\n");
		    	printf("\t\t3.Exit\n\n");
		    	printf("\t\t����������ѡ��:");
		    	scanf("%d",&choice);
		    	if(choice==1||choice==2||choice==3)
		    	break;
		    	else
		    	{
		    		system("cls");
	         	    printf("����ѡ������������ѡ��\n");
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
			    printf("\nлл����ʹ�ã�\n");
		    	exit(0);
			}
		}
	}
}

/*-------------------------------------------------------------------------�޸Ŀγ̺���----------------------------------------------------------------*/ 
void Revise_Course()
{
	system("cls");
	FILE *fp;
	Class_Inf temp;
	int choice,choice_1,judge,judge_1;
	list head,p,r;
	fp = fopen("class_information.txt","r");
	if(fp==NULL)                                   //�ж��Ƿ��ȡ�ɹ� 
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
		printf("\n-----------------------��������ؿγ���Ϣ��-----------------------\n\n");
		printf("\n\n\t��������Ҫ�޸Ŀγ̵ı�Ż�����:");
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
			printf("\n--------------------Sorry,δ�ܲ��ҵ��ÿγ̣�---------------------");
			while(1)
			{
				printf("\n\n\t1.��������\n\n");
			    printf("\t2.Back\n\n");
			    printf("\t3.Exit\n\n");
			    printf("\t����������ѡ��:");
			    scanf("%d",&choice);
			    if(choice==1||choice==2||choice==3)
			    break;
			    else
			    {
			    	system("cls");
				    printf("\n����ѡ������������ѡ��\n");
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
			    printf("\nлл����ʹ�ã�\n");
			    exit(0);
			}
		}
		else
		{
			system("cls");
			printf("\n-----------------------�ɹ����ҵ��ÿγ̣�-----------------------\n\n");
			while(1)
			{
				printf("�ÿγ���Ϣ����:\n\n");
		    	printf("�γ̱��� �γ�����   ����רҵ             �γ�����        ѧ��  ѧʱ ������ʦ\n");
			    printf("%-8s%-12s%-20s%-18s%-5s%-4s%-8s",p->coding,p->name,p->scope,p->type,p->credit,p->hours,p->teacher);
		    	printf("\n\n\n1.�޸Ŀγ̱���");
		    	printf("\t2.�޸Ŀγ�����");
		    	printf("\t3.�޸�����רҵ");
		    	printf("\t4.�޸Ŀγ�����");
		    	printf("\n\n5.�޸Ŀγ�ѧ��");
		    	printf("\t6.�޸Ŀγ�ѧʱ");
		    	printf("\t7.�޸�������ʦ");
		    	printf("\n\n����������ѡ��:");
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
				    printf("\n����ѡ������������ѡ��\n\n");
				}
			}
			if(choice==1)
			{
				while(1)
				{
					judge_1 = 0;
					printf("\n\n��������ĺ�Ŀγ̱���:");
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
						printf("\n�޸�ʧ�ܣ��Ѵ�����ͬ����Ŀγ̣�");
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
						printf("\n-----------------------�޸ĳɹ���-------------------------");
						break;
			   		}
				}
				while(1)
						{
						    printf("\n\n\t1.�����޸�\t\t2.Back");
						    printf("\n\n\t��������ѡ��:");
						    scanf("%d",&choice_1);
						    if(choice_1==1||choice_1==2)
						    break;
						    else
						    {
						    	system("cls");
						    	printf("\n����ѡ������������ѡ��\n\n");
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
					printf("\n\n��������ĺ�Ŀγ�����:");
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
						printf("\n�޸�ʧ�ܣ��Ѵ�����ͬ���ƵĿγ̣�");
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
						printf("\n----------------------�޸ĳɹ���--------------------");
						break;
					}
				}
				while(1)
						{
						    printf("\n\n\t1.�����޸�\t\t2.Back");
						    printf("\n\n\t��������ѡ��:");
						    scanf("%d",&choice_1);
						    if(choice_1==1||choice_1==2)
						    break;
						    else
						    {
						    	system("cls");
						    	printf("\n����ѡ������������ѡ��\n\n");
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
				printf("\n\n��������ĺ������רҵ:");
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
				printf("\n-----------------------�޸ĳɹ���---------------------\n\n\n");
				while(1)
						{
						    printf("\n\n\t1.�����޸�\t\t2.Back");
						    printf("\n\n\t��������ѡ��:");
						    scanf("%d",&choice_1);
						    if(choice_1==1||choice_1==2)
						    break;
						    else
						    {
						    	system("cls");
						    	printf("\n����ѡ������������ѡ��\n\n");
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
				printf("\n\n��������ĺ�Ŀγ�����:");
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
				printf("\n-------------------------------�޸ĳɹ���------------------------------\n\n\n");
				while(1)
						{
						    printf("\t1.�����޸�\t\t2.Back");
						    printf("\n\n\t��������ѡ��:");
						    scanf("%d",&choice_1);
						    if(choice_1==1||choice_1==2)
						    break;
						    else
						    {
						    	system("cls");
						    	printf("\n����ѡ������������ѡ��\n\n");
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
				printf("\n\n��������ĺ�Ŀγ�ѧ��:");
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
				printf("\n-------------------------�޸ĳɹ���----------------------\n\n\n");
				while(1)
						{
						    printf("\t1.�����޸�\t\t2.Back");
						    printf("\n\n\t��������ѡ��:");
						    scanf("%d",&choice_1);
						    if(choice_1==1||choice_1==2)
						    break;
						    else
						    {
						    	system("cls");
						    	printf("\n����ѡ������������ѡ��\n\n");
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
				printf("\n\n��������ĺ�Ŀγ�ѧʱ:");
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
				printf("\n----------------------�޸ĳɹ���-------------------\n\n\n");
				while(1)
						{
						    printf("\t1.�����޸�\t\t2.Back");
						    printf("\n\n\t��������ѡ��:");
						    scanf("%d",&choice_1);
						    if(choice_1==1||choice_1==2)
						    break;
						    else
						    {
						    	system("cls");
						    	printf("\n����ѡ������������ѡ��\n\n");
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
				printf("\n\n��������ĺ��������ʦ:");
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
				printf("\n-------------------------�޸ĳɹ���------------------------\n\n\n");
				while(1)
						{
						    printf("\t1.�����޸�\t2.Back");
						    printf("\n\n\t��������ѡ��:");
						    scanf("%d",&choice_1);
						    if(choice_1==1||choice_1==2)
						    break;
						    else
						    {
						    	system("cls");
						    	printf("\n����ѡ������������ѡ��\n\n");
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

/*--------------------------------------------------------------------------------------------ɾ���γ̺���-----------------------------------------------------------------------------*/ 
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
 		if(fp==NULL)                                   //�ж��Ƿ��ȡ�ɹ� 
    	{
		printf("\nFailed to open the file.\n");
		exit(1);
    	}
    	printf("\n---------------------------��������ؿγ���Ϣ��---------------------------\n\n");
    	printf("\n\n\t��������Ҫɾ���γ̵ı�Ż�����:");
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
		fclose(fp);                                  //�ر��ļ� 
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
			printf("\n-------------------------Sorry,δ�ܲ��ҵ��ÿγ̣�-----------------------------");
			while(1)
			{
				printf("\n\n\t1.��������\n\n");
				printf("\t2.Back\n\n");
				printf("\t3.Exit\n\n");
			    printf("\t����������ѡ��:");
			    scanf("%d",&choice);
			    if(choice==1||choice==2||choice==3)
			    break;
			    else
			    {
			    	system("cls");
				    printf("\n����ѡ������������ѡ��\n");
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
			    printf("\nлл����ʹ�ã�\n");
			    exit(0);
			}
		}
		else
		{
			system("cls");
			printf("\n-----------------------�ɹ����ҵ��ÿγ̣�-------------------------\n\n");
			printf("�ÿγ���Ϣ����:\n\n");
			printf("�γ̱��� �γ�����   ����רҵ             �γ�����        ѧ��  ѧʱ ������ʦ\n");
			printf("%-8s%-12s%-20s%-18s%-5s%-4s%-8s",p->coding,p->name,p->scope,p->type,p->credit,p->hours,p->teacher);
			while(1)
			{
				printf("\n\n\n�Ƿ�ɾ���ÿγ�(Y or N):");
				fflush(stdin);                                 //������� 
				ch = getchar();
				if(ch=='Y'||ch=='y')
				break;
				else if(ch=='N'||ch=='n')
				break;
				else
				{
					system("cls");
					printf("\n�ÿγ���Ϣ����:\n\n");
					printf("�γ̱��� �γ�����   ����רҵ             �γ�����        ѧ��  ѧʱ ������ʦ\n");
					printf("%-8s%-12s%-20s%-18s%-5s%-4s%-8s",p->coding,p->name,p->scope,p->type,p->credit,p->hours,p->teacher);
					printf("\n\n\n���������������������룡");
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
				if(fp==NULL)                                   //�ж��Ƿ��ȡ�ɹ� 
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
				printf("\n------------------------ɾ���ɹ���------------------------\n\n");
				system("pause");
				system("cls");
				break;
			}
			else
			{
				system("cls");
				printf("\n\n\t�ɹ�ȡ����");
				printf("\n\n\t3����Զ����أ�");
				for(int i=1;i<=30;i++)
				{
					printf("��");
					Sleep(100); 
				}
				system("cls");
				break;
			}
		}
	 }
 }
 
 /*--------------------------------------------------------------------------------------����ѧ��ѡ�κ���----------------------------------------------------------------------------*/
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
		if(fp==NULL)                  //�ж��Ƿ��ȡ�ɹ� 
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
			printf("\n\n1.��������ѧ��ѡ��\t\t2.������ѧ��ѡ��\n\n");
			printf("\n\n��������ѡ��:");
			scanf("%d",&choice);
			if(choice==1||choice==2)
			break;
			else
			{
				system("cls");
				printf("\nSorry,�������������������룡");
			}
		}
	 if(choice==1)
	 {
	 	system("cls");
	 	judge = 0;
	 	printf("\n--------------------������ѧ���������Ϣ!------------------------\n");
	 	printf("\n\n\t������ѧ����ѧ�Ż�����:");
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
    		printf("\nSorry,�������ѧ�������ڣ�\n\n");
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
		    	printf("\n����ѡ��ȫ���γ̣��޷��������ӿγ̣�\n\n");
			  	system("pause");
			  	system("cls");
			  	break;
			}
			system("cls");
			printf("Class Information:\n\n");
			printf("�γ̱��� �γ�����   ����רҵ             �γ�����        ѧ��  ѧʱ ������ʦ\n");
			p1 = head1;
			do{
				p1 = p1->next;
				printf("%-8s%-12s%-20s%-18s%-5s%-4s%-8s\n",p1->coding,p1->name,p1->scope,p1->type,p1->credit,p1->hours,p1->teacher);
			}while(p1->next != NULL);
			printf("\nѧ����ϢΪ:");
			printf("\nѧ��:%s\t����:%s",p->id,p->name);
			printf("\n��ѡ�γ�:");
			for(i=0;i<15;i++)
			if(strcmp(p->course[i].Course_name,"NULL")!=0)
			printf("%s ",p->course[i].Course_name);
			
			judge_1 = 0;
			judge_2 = 0;
			printf("\n\n�������ӿγ̵ı����������:");
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
				printf("\nSorry,������Ŀγ̲����ڣ�\n\n");
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
					printf("\n\n��ѡ����¿γ��Ѵ�����ѡ�γ��У�\n\n");
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
						printf("\n\n1.��������\t\t2.Back");
						printf("\n��������ѡ��:");
						scanf("%d",&choice_1);
						if(choice_1==1||choice_1==2)
						break;
						else
						{
							system("cls");
							printf("\n���������������������룡\n");
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
	 else     //������ѧ��ѡ�� 
	 {
	 	system("cls");
	 	printf("\n--------------------������ѧ���������Ϣ!------------------------\n");
	 	printf("\n\n\t��������ѧ����ѧ��:");
    	scanf("%s",temp->id);
    	printf("\n\n\t��������ѧ��������:");
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
    		printf("\nSorry,�������ѧ���Ѵ��ڣ�\n\n");
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
		   		 printf("�γ̱��� �γ�����   ����רҵ             �γ�����        ѧ��  ѧʱ ������ʦ\n");
				 p1 = head1;
				 do{
					p1 = p1->next;
					printf("%-8s%-12s%-20s%-18s%-5s%-4s%-8s\n",p1->coding,p1->name,p1->scope,p1->type,p1->credit,p1->hours,p1->teacher);
				 }while(p1->next != NULL);
				 printf("\n\n�������ӿγ̵ı����������:");
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
				 	printf("\nSorry,������Ŀγ̲����ڣ�\n\n");
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
						printf("\n\n��ѡ����¿γ��Ѵ�����ѡ�γ��У�\n\n");
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
					    	printf("\n����ѡ��ȫ���γ̣��޷��������ӿγ̣�\n\n");
					    	system("pause");
					    	system("cls");
					    	break;
						}
						while(1)
						{
							printf("\n\nAdd Successful!");
							printf("\n\n1.��������\t\t2.Back");
							printf("\n\n��������ѡ��:");
							scanf("%d",&choice_1);
							if(choice_1==1||choice_1==2)
							break;
							else
							{
								system("cls");
								printf("\n���������������������룡\n");
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
/*-------------------------------------------------------------------------------�޸�ѧ��ѡ�κ���--------------------------------------------------------------------------------*/ 
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
		printf("\n-------------------------������ѧ���������Ϣ!--------------------------");
		printf("\n\n\t\t���������޸�ѧ����ѧ�Ż�����:");
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
			printf("\nSorry,�������ѧ�������ڣ����������룡");
			continue;
		}
		else
		{
			system("cls");
			printf("\t����ѧ����ѡ����ϢΪ:\n\n");
			printf("\tѧ��:%-5s\n����:%-5s\n",p->id,p->name);
			printf("\t��ѡ�γ�:");
			for(i=0;i<15;i++)
			{
				if(strcmp(p->course[i].Course_name,"NULL") != 0)
				printf("%-15s",p->course[i].Course_name);
			}
			while(1)
			{
				printf("\n\n\t������Ҫ�����޸ĵĿγ�:");
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
		    		printf("\nSorry,�������������������룡");
		    		continue; 
	    		}
	    		else
	    		{
	    			system("cls");
	    			printf("\n\n\t�������޸ĺ�Ŀγ�:");
	    			scanf("%s",temp.name);
	    			for(int k=0;k<15;k++)
	    			{
	    				if(strcmp(temp.name,p->course[k].Course_name)==0)
	    				{
	    					system("cls");
	    					printf("\nSorry,������Ŀγ��Ѵ��ڣ����������룡");
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
			printf("\n--------------------------�޸ĳɹ���-----------------------\n");
	    	printf("\n\t1.�����޸�\t\t2.Back");
    		printf("\n\n\t����������ѡ��");
	    	scanf("%d",&choice);
	    	if(choice==1||choice==2)
	    	break;
	    	else
	    	{
	    		system("cls");
	    		printf("\n���������������������룡\n");
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

/*---------------------------------------------------------------------ɾ��ѧ��ѡ�κ���----------------------------------------------------------------------------*/
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
	 	printf("\n--------------------------������ѧ�������Ϣ��---------------------------");
	 	printf("\n\n\t������ѧ��ѧ�Ż�����:");
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
		 	printf("\nSorry,�������ѧ�������ڣ����������룡\n\n");
		 	continue;
		 }
		 else
		 {
		 	system("cls");
		 	printf("\n\t���ҳɹ���\n\n");
		 	printf("\t����ѧ��ѡ����ϢΪ:\n\n");
		 	printf("\tѧ��:%-5s\n\n\t����:%-5s\n\n",p->id,p->name);
		 	printf("\t��ѡ�γ�:");
		 	for(i=0;i<15;i++)
		 	{
		 		if(strcmp(p->course[i].Course_name,"NULL") != 0)
		 		printf("%-15s",p->course[i].Course_name);
			 }
			 while(1)
			 {
				 printf("\n\n\n\t������Ҫ����ɾ���Ŀγ�����:");
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
			    	printf("\n\n������Ŀγ̲����ڣ����������룡"); 
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
		 printf("\n-------------------------ɾ���ɹ���-----------------------------\n");
		 while(1)
		 {
		 	 printf("\n\n\t1.����ɾ��");
	    	 printf("\n\n\t2.Back");
	    	 printf("\n\n\t����������ѡ��:");
	    	 scanf("%d",&choice);
	    	 if(choice==1||choice==2)
	    	 break;
	    	 else
	    	 {
	    	 	system("cls");
	    	 	printf("\n���������������������룡\n");
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
  
/*------------------------------------------------------------------------ͨ���γ̲�ѯ-------------------------------------------------------------------------------*/       
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
		printf("-------------------------------������γ������Ϣ------------------------------\n\n");
		printf("�����Բ�ѯ�Ŀγ���:");
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
		printf("\n\n\n��������Ҫ���ҵĿγ�����(�����ִ�Сд):");
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
			printf("\nSorry,������Ŀγ̲����ڣ����������룡\n\n");
			continue;
		}
		judge = 0;
		printf("\n\n\nѡ��ÿγ̵�ѧ����:");
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
			printf(" ��ѧ��ѡ��ÿγ̣�");
		}
		while(1)
		{
			printf("\n\n\n1.������ѯ\t\t2.Back");
	    	printf("\n\n����������ѡ��:");
	     	scanf("%d",&choice);
	     	if(choice==1||choice==2)
	     	break;
	     	else
	     	{
	     		system("cls");
	     		printf("\n����ѡ������������ѡ��\n");
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

/*----------------------------------------------------------------------------ͨ��ѧ�ֲ�ѯ----------------------------------------------------------------------------*/       
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
	 list head1,p1,r1;                    //�γ���Ϣ������ 
	 Stu_list head,p,r;                  //ѧ��ѡ����Ϣ������ 
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
		printf("\n\n---------------------------------ͨ��ѧ�ֲ�ѯ----------------------------------\n\n");
    	printf("\n\n��������Ҫ��ѯ��ѧ��:");
    	scanf("%f",&temp);
    	printf("\n\nѡ����ѧ��Ϊ%-2.1f��ѧ����ϢΪ:",temp);
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
				printf("%-6s--��ѡ�γ�: ",p->name);
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
		    		printf("�޿γ�ѡ��");
				}
		   	}
			if(judge==1)
			printf("\n\t\t            ");
		}while(p->next != NULL);
		p = NULL;
		p1 = NULL;
		if(judge==0)
		{
			printf(" δ��ѯ������������ѧ����Ϣ��");
		}
		while(1)
		{
			printf("\n\n\n\n1.������ѯ\t\t2.Back");
    		printf("\n\n����������ѡ��:");
	    	scanf("%d",&choice);
	    	if(choice==1||choice==2)
	    	break;
	    	else
	    	{
	    		system("cls");
	    		printf("����ѡ������������ѡ��\n");
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

/*--------------------------------------------------------------------��ѧ�Ų�ѯ����-----------------------------------------------------------------------*/ 
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
		printf("-------------------------------�����������Ϣ------------------------------\n");
		printf("\n\n��������Ҫ���ҵ�ѧ��:");
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
			printf("\n\nSorry,δ���ҵ������Ϣ��"); 
		}
		else
		{
			printf("\n\nѧ��:%-10s",p->id);
			printf("\n\n����:%-15s",p->name);
			printf("\n\n��ѡ�γ�:");
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
			printf("����ѡ�γ̣�");
		}
		while(1)
		{
			printf("\n\n\n1.��������\t\t2.Back");
	    	printf("\n\n��������ѡ��:");
	    	scanf("%d",&choice); 
	    	if(choice==1||choice==2)
	    	break;
	    	else
	    	{
	    		system("cls");
	    		printf("���������������������룡\n");
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

/*------------------------------------------------------------------���γ�ͳ��ѡ�ν��------------------------------------------------------------------------------*/ 
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
		printf("-------------------------------�����������Ϣ------------------------------\n\n");
		printf("������ͳ�ƵĿγ���:");
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
		printf("\n\n\n��������Ҫͳ�ƵĿγ�����(�����ִ�Сд):");
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
			printf("\nSorry,������Ŀγ̲����ڣ����������룡\n\n");
			continue;
		}
		judge = 0;
		printf("\n\n\nѡ��ÿγ̵�ѧ����:");
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
			printf(" ��ѧ��ѡ��ÿγ̣�");
		}
		while(1)
		{
			printf("\n\n\n1.ͳ�������γ�\t\t2.Back");
	    	printf("\n\n����������ѡ��:");
	     	scanf("%d",&choice);
	     	if(choice==1||choice==2)
	     	break;
	     	else
	     	{
	     		system("cls");
	     		printf("\n����ѡ������������ѡ��\n");
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
