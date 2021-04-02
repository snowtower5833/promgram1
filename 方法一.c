
//方法一
#define _CRT_SECURE_NO_WARNINGS
//头文件
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string.h>
#include<conio.h>
#include<io.h>


/*//信息
struct birth
{
	int year;
	int month;
	int day;
};//出生年月
*/
struct student
{
	int xh;
	char name[10];
	int old;
	char sex[2];
	int year;
	int month;
	int day; 
	//ar sr[20]; //000-8-7
	char dz[10];
	int dh;
	char mail[20];
	struct student *next;
};//学号，姓名，年龄，性别，出生年月，地址，电话，E-mail


//链表
struct Node
{
	//!int data;
	struct student data;
	struct Node *next;
};

//创建链表
//创建表头
struct Node *createList()
{
	struct Node *headNode=(struct Node *)malloc(sizeof(struct Node));
	headNode->next=NULL;
	return headNode;
}

//创建结点
//!struct Node *createNode(int data)
struct Node *createNode(struct student data)
{
	struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}

//插入结点
//!struct Node *insertNodeByHead(struct Node *headNode,int data)
struct Node *insertNodeByHead(struct Node *headNode,struct student data)
{
	struct Node *newNode=createNode(data);//!!!!
	newNode->next=headNode->next;
	headNode->next=newNode;
	return newNode;
}

//打印链表
struct Node *printfList(struct Node *headNode)
{
	struct Node *pMove=headNode->next;
	printf("学号，姓名，年龄，性别，出生年月，地址，电话，E-mail:");
	while(pMove)
	{
		//!printf("%d->",pMove->data);
		printf("%d\t %s\t %d\t %s\t %d\t %d\t %d\t %s\t %d\t %s\n",pMove->data.xh,pMove->data.name,pMove->data.old,pMove->data.sex,
			pMove->data.year,pMove->data.month,pMove->data.day,pMove->data.dz,pMove->data.dh,pMove->data.mail);
		pMove=pMove->next;
		pMove=pMove->next;
	}
	printf("\n");
}

//指定位置删除1
//!struct Node *delectAppoinNode(struct Node *headNode,int data)
//因为data为struct student data所以可以指定学号进行删除
struct Node *delectAppoinNodexh(struct Node *headNode,int xh)
{
	struct Node *posNode=headNode->next;
	struct Node *posFrontNode=headNode;
	if(posNode==NULL)
	{
		printf("无数据，无法删除\n");
		return NULL;
	}
	//!while(posNode->data!=data)因为data为struct student data
	while( posNode->data.xh!=xh)
	{
		posFrontNode=posNode;
		posNode=posFrontNode->next;
		if(posNode==NULL)
		{
			printf("未找到指定位置\n");
			return NULL;
		}
	}
	posFrontNode->next=posNode->next;
	free(posNode);
}


//指定位置删除2
//!struct Node *delectAppoinNode(struct Node *headNode,int data)
//因为data为struct student data所以可以指定姓名进行删除
struct Node *delectAppoinNodexm(struct Node *headNode,char name[])
{
	struct Node *posNode=headNode->next;
	struct Node *posFrontNode=headNode;
	if(posNode==NULL)
	{
		printf("无数据，无法删除\n");
		return NULL;
	}
	//!while(posNode->data!=data)因为data为struct student data
	while(strcmp(posNode->data.name,name))
	{
		posFrontNode=posNode;
		posNode=posFrontNode->next;
		if(posNode==NULL)
		{
			printf("未找到指定位置\n");
			return NULL;
		}
	}
	posFrontNode->next=posNode->next;
	free(posNode);
}





//查找功能1
//!struct Node *search(struct Node *headNode,int data)
//因为data为struct student data所以可以指定学号进行查找
struct Node *searchxh(struct Node *headNode,int xh)
{
	struct Node *pMove=headNode->next;
	if(pMove==NULL)
	{
		printf("数据为空，查找失败\n");
		return NULL;
	}
	//!!!!	while(pMove->data!=data)
	while(pMove->data.xh!=xh)
	{
		pMove=pMove->next;
		if(pMove==NULL)
		{
			printf("未找到数据\n");
			return NULL;
		}
		return pMove;
	}
}

////查找功能1
//!struct Node *search(struct Node *headNode,int data)
//因为data为struct student data所以可以指定姓名进行查找
struct Node *searchxm(struct Node *headNode,char name[])
{
	struct Node *pMove=headNode->next;
	if(pMove==NULL)
	{
		printf("数据为空，查找失败\n");
		return NULL;
	}
	//!!!!	while(pMove->data!=data)
	while(strcmp(pMove->data.name,name))
	{
		pMove=pMove->next;
		if(pMove==NULL)
		{
			printf("未找到数据\n");
			return NULL;
		}
		return pMove;
	}
}


//菜单
void menu()
{
	printf("----------【 学生信息管理系统】--------------");
	printf("\n\t1.学生信息录入");
	printf("\n\t2.学生信息浏览功能");
	printf("\n\t3.查询、排序功能");
	printf("\n\t a.按学号查询");
	printf("\n\t b.按姓名查询");
	printf("\n\t4.学生信息的删除与修改");
	printf("\n\t a.按学号删除");
	printf("\n\t b.按姓名删除");
	printf("\n\t0.安全退出\n");
	printf("---------------------------------------------\n");
}/*以菜单方式工作
a系统以菜单方式工作
b学生信息录入功能（学生信息用文件保存）---输入
c学生信息浏览功能——输出
d 查询、排序功能——算法
1、按学号查询
2、按姓名查询
e学生信息的删除与修改（可选项）*/


//选择功能按键
void keydown()
{
	int x;//选择值（0-4）的变量;
	char m;//选择a或者b的变量m;
	char flag;//判断是否继续输入的变量flag;
	struct Node *list=createList();//创建list链表
	struct student *data;
	printf("请输入需要的功能序号(0-4):");
	scanf("%d",&x);
	switch(x)
	{
	case 0:
		printf("安全退出\n");
		system("pause");
		exit(0);
	case 1:
		printf("\t学生信息录入\n");
		//插入链表
		//每次录入一个信息
		printf("请输入");
		printf("学号\t姓名\t年龄\t性别\t出生年月（2000 1 1）\t地址\t电话\tE-mail:\n");
		fflush(stdin);
		scanf("%d %s %d	%s %d %d &d %s %d %s",&data->xh,&data->name,&data->old,&data->sex,
	   &data->year,
	   &data->month,
	   &data->day,
	   &data->dz,
	   &data->dh,
	   &data->mail);

	    getchar();
		insertNodeByHead(list,*data);
		system("pause");
		break;
	case 2:
		printf("\t学生信息浏览\n");
		//打印链表
		printfList(list);
		system("pause");
		break;
	case 3:
		printf("\t查询\n");
		printf("请输入查询方式:a按学号查询/b按姓名查询:");
		getchar();
		m=getchar();
		if(m=='a')
		{	
			printf("\t-------按学号查询--------\n");
			printf("请输入学生学号:");
			fflush(stdin);

			scanf("%d",&data->xh);
			if(searchxh(list,data->xh)==NULL)
			{
				printf("未找到相关信息\n");
				system("pause");
			}
			else
			{
				printf("学生信息为\n:");
				printf("学号\t姓名\t年龄\t性别\t出生年月\t地址\t电话\tE-mail:\n");
				printf("%d\t %s\t %d\t %s\t %d\t %s\t %d\t %s\n",searchxh(list,data->xh)->data.xh,searchxh(list,data->xh)->data.name,
					searchxh(list,data->xh)->data.old,searchxh(list,data->xh)->data.sex,searchxh(list,data->xh)->data.year,
					searchxh(list,data->xh)->data.month,searchxh(list,data->xh)->data.day,searchxh(list,data->xh)->data.dz,
					searchxh(list,data->xh)->data.dh,searchxh(list,data->xh)->data.mail);
			}
		}
		else if(m=='b')
		{
			printf("\t-------按姓名查询--------\n");
			printf("请输入的学生姓名:");
			fflush(stdin);

			scanf("%s",data->name);
			if(searchxm(list,data->name)==NULL)
			{
				printf("未找到相关信息\n");
				system("pause");
			}
			else
			{			
				printf("学生信息为\n:");
				printf("学号\t姓名\t年龄\t性别\t出生年月\t地址\t电话\tE-mail:\n");
				printf("%d\t %s\t %d\t %s\t %d\t %s\t %d\t %s\n",searchxm(list,data->name)->data.xh,searchxm(list,data->name)->data.name,
					searchxm(list,data->name)->data.old,searchxm(list,data->name)->data.sex,searchxm(list,data->name)->data.year,
					searchxm(list,data->name)->data.month,searchxm(list,data->name)->data.day,searchxm(list,data->name)->data.dz,
					searchxm(list,data->name)->data.dh,searchxm(list,data->name)->data.mail);
			}
		}
		else
			printf("\t查询方式错误，请输入a或者b\n");
		break;
	case 4:
		printf("学生信息的删除\n");
		printf("请选择删除方式：a按学号删除/b按姓名修改：");

		fflush(stdin);
		m=getchar();
		if(m=='a')
		{	
			printf("\t-------按学号删除--------\n");
			printf("请输入删除的学生学号:");
			fflush(stdin);

			scanf("%d",&data->xh);
			if(searchxm(list,data->xh)==NULL)
			{
				printf("未找到相关信息，无法删除\n");
				system("pause");
			}
			else
			{
				printf("删除的学生信息为\n:");
				printf("学号\t姓名\t年龄\t性别\t出生年月\t地址\t电话\tE-mail:\n");
				printf("%d\t %s\t %d\t %s\t %d\t %s\t %d\t %s\n",searchxm(list,data->xh)->data.xh,searchxm(list,data->xh)->data.name,
					searchxm(list,data->xh)->data.old,searchxm(list,data->xh)->data.sex,searchxm(list,data->xh)->data.year,
					searchxm(list,data->xh)->data.month,searchxm(list,data->xh)->data.day,searchxm(list,data->xh)->data.dz,
					searchxm(list,data->xh)->data.dh,searchxm(list,data->xh)->data.mail);
				printf("是否删除？y/n");
				printf("\n");
				scanf("%c",&flag);
				getchar();
				if(flag!='n')
				{
					delectAppoinNodexh(list,data->xh);
					printf("成功删除\n");
				}			
			}
		}
		else if(m=='b')
		{
			printf("\t-------按姓名删除--------\n");
			printf("请输入删除的学生姓名:");
			scanf("%s",data->name);
			if(searchxm(list,data->name)==NULL)
			{
				printf("未找到相关信息，无法删除\n");
				system("pause");
			}
			else
			{			
				printf("删除的学生信息为\n:");
				printf("学号\t姓名\t年龄\t性别\t出生年月\t地址\t电话\tE-mail:\n");
				printf("%d\t %s\t %d\t %s\t %d\t %s\t %d\t %s\n",searchxm(list,data->name)->data.xh,searchxm(list,data->name)->data.name,
					searchxm(list,data->name)->data.old,searchxm(list,data->name)->data.sex,searchxm(list,data->name)->data.year,
					searchxm(list,data->name)->data.month,searchxm(list,data->name)->data.day,searchxm(list,data->name)->data.dz,
					searchxm(list,data->name)->data.dh,searchxm(list,data->name)->data.mail);
				printf("是否删除？y/n");
				printf("\n");
				scanf("%c",&flag);
				getchar();
				if(flag!='n')
				{
					delectAppoinNodexm(list,data->name);
					printf("成功删除\n");
				}
			}	
		}
	default:
		printf("输入错误,请重新输入\n");
		system("pause");
		break;
	}
}//与用户交互，以按键输入





//主函数
void main()
{
	//list为链表表头
	struct Node *list=createList();

	while(1)
	{
		menu();
		keydown();
		system("cls");
		system("pause");
	}

}








