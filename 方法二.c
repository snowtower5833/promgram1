//头文件
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string.h>

 struct student
{
	int xh;
	char name[10];
	int old;
	char sex;
	int year ;
	int month;
	int day;
	char dz[10];
	int dh;
	char mail[20];
	struct student *next;
};//学号，姓名，年龄，性别，出生年月，地址，电话，E-mail
/*//信息
struct birth
{
	int year;
	int month;
	int day;
};//出生年月
*/

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
		printf("%d\t %s\t %d\t %c\t %d\t %s\t %d\t %s\n",pMove->data.xh,pMove->data.name,pMove->data.old,pMove->data.sex,
			pMove->data.year,pMove->data.month,pMove->data.day,pMove->data.dz,pMove->data.dh,pMove->data.mail);
		pMove=pMove->next;
	}
	printf("\n");
}

//指定位置删除
//!struct Node *delectAppoinNode(struct Node *headNode,int data)
//因为data为struct student data所以可以指定姓名或者是学号进行删除
struct Node *delectAppoinNode(struct Node *headNode,int xh)
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

//查找功能
//!struct Node *search(struct Node *headNode,int data)
//因为data为struct student data所以可以指定姓名或者是学号进行查找
struct Node *search(struct Node *headNode,int xh)
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


//学生信息录入功能
struct student *lulu()
{
	char flag;
	struct student *data;
	struct Node *head,*current,*next;
	//创建表头
	head=(struct Node *)malloc(sizeof(struct Node));
	head->next=NULL;
	printf("是否要输入学生信息？Y/N");
	printf("\n");
	scanf("%c",&flag);
	getchar();
	if(flag!='n')
	{
		printf("请输入学生的\n");
		printf("学号\t姓名\t年龄\t性别\t出生年月(参考2000 1 1)\t地址\t电话\tE-mail:\n");
		scanf("%d%s%d%c%d%s%d%s",head->data.xh,head->data.name,head->data.old,head->data.sex,
	   head->data.year,
	   head->data.month,
	   head->data.day,head->data.dz,head->data.dh,head->data.mail);
	}
	getchar();

	//新节点
	current=head;
	printf("是否继续输入？Y/N");
	printf("\n");
	scanf("%c",&flag);
	getchar();
	while(flag!='n')
	{
		//下一节点
		next=(struct Node *)malloc(sizeof(struct Node));
		printf("请输入\n");
		printf("学号，姓名，年龄，性别，出生年月，地址，电话，E-mail:\n");
		scanf("%d%s%d%c%d%s%d%s",head->data.xh,head->data.name,head->data.old,head->data.sex,
	   head->data.year,
	   head->data.month,
	   head->data.day,head->data.dz,head->data.dh,head->data.mail);

		current->next=next;
		current=next;

		printf("是否继续输入？Y/N");		
		printf("\n");
		scanf("%c",&flag);
		getchar();
	}
	current->next=NULL;
	return head;
}//学生信息录入

//菜单
void menu()
{
	printf("----------【 学生信息管理系统】--------------");
	printf("\n\t1.学生信息录入");
	printf("\n\t2.学生信息浏览功能");
	printf("\n\t3.查询、排序功能");
	printf("\n\t a.按学号查询");
	printf("\n\t b.按姓名查询");
	printf("\n\t4.学生信息的删除");
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
	int x;
	char m;
	struct Node *list=NULL;
	struct student *data;
	scanf("%d",&x);
	switch(x)
	{
	case 0:
		printf("安全退出\n");
		system("pause");
		exit(0);
	case 1:
		printf("\t学生信息录入\n");
		//调用链表
		list=lulu();
		getchar();
		system("pause");
		break;
	case 2:
		printf("\t学生信息浏览\n");
		//打印链表
		printfList(list);
		system("pause");
		break;
	case 3:
		printf("\t查询、排序\n");
		printf("请输入查询方式:a按学号查询/b按姓名查询:");
		getchar();
		m=getchar();
		if(m=='a')
			printf("\t-------按学号查询--------\n");
		else if(m=='b')
			printf("\t-------按姓名查询--------\n");
		else
			printf("\t查询方式错误，请输入a或者b\n");
		break;
	case 4:
		printf("学生信息的删除与修改\n");
		system("pause");
		break;
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
		printf("请输入需要的功能序号：");
		keydown();
		system("pause");
		system("cls");
	}


}
