
//����һ
#define _CRT_SECURE_NO_WARNINGS
//ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string.h>
#include<conio.h>
#include<io.h>


/*//��Ϣ
struct birth
{
	int year;
	int month;
	int day;
};//��������
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
};//ѧ�ţ����������䣬�Ա𣬳������£���ַ���绰��E-mail


//����
struct Node
{
	//!int data;
	struct student data;
	struct Node *next;
};

//��������
//������ͷ
struct Node *createList()
{
	struct Node *headNode=(struct Node *)malloc(sizeof(struct Node));
	headNode->next=NULL;
	return headNode;
}

//�������
//!struct Node *createNode(int data)
struct Node *createNode(struct student data)
{
	struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}

//������
//!struct Node *insertNodeByHead(struct Node *headNode,int data)
struct Node *insertNodeByHead(struct Node *headNode,struct student data)
{
	struct Node *newNode=createNode(data);//!!!!
	newNode->next=headNode->next;
	headNode->next=newNode;
	return newNode;
}

//��ӡ����
struct Node *printfList(struct Node *headNode)
{
	struct Node *pMove=headNode->next;
	printf("ѧ�ţ����������䣬�Ա𣬳������£���ַ���绰��E-mail:");
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

//ָ��λ��ɾ��1
//!struct Node *delectAppoinNode(struct Node *headNode,int data)
//��ΪdataΪstruct student data���Կ���ָ��ѧ�Ž���ɾ��
struct Node *delectAppoinNodexh(struct Node *headNode,int xh)
{
	struct Node *posNode=headNode->next;
	struct Node *posFrontNode=headNode;
	if(posNode==NULL)
	{
		printf("�����ݣ��޷�ɾ��\n");
		return NULL;
	}
	//!while(posNode->data!=data)��ΪdataΪstruct student data
	while( posNode->data.xh!=xh)
	{
		posFrontNode=posNode;
		posNode=posFrontNode->next;
		if(posNode==NULL)
		{
			printf("δ�ҵ�ָ��λ��\n");
			return NULL;
		}
	}
	posFrontNode->next=posNode->next;
	free(posNode);
}


//ָ��λ��ɾ��2
//!struct Node *delectAppoinNode(struct Node *headNode,int data)
//��ΪdataΪstruct student data���Կ���ָ����������ɾ��
struct Node *delectAppoinNodexm(struct Node *headNode,char name[])
{
	struct Node *posNode=headNode->next;
	struct Node *posFrontNode=headNode;
	if(posNode==NULL)
	{
		printf("�����ݣ��޷�ɾ��\n");
		return NULL;
	}
	//!while(posNode->data!=data)��ΪdataΪstruct student data
	while(strcmp(posNode->data.name,name))
	{
		posFrontNode=posNode;
		posNode=posFrontNode->next;
		if(posNode==NULL)
		{
			printf("δ�ҵ�ָ��λ��\n");
			return NULL;
		}
	}
	posFrontNode->next=posNode->next;
	free(posNode);
}





//���ҹ���1
//!struct Node *search(struct Node *headNode,int data)
//��ΪdataΪstruct student data���Կ���ָ��ѧ�Ž��в���
struct Node *searchxh(struct Node *headNode,int xh)
{
	struct Node *pMove=headNode->next;
	if(pMove==NULL)
	{
		printf("����Ϊ�գ�����ʧ��\n");
		return NULL;
	}
	//!!!!	while(pMove->data!=data)
	while(pMove->data.xh!=xh)
	{
		pMove=pMove->next;
		if(pMove==NULL)
		{
			printf("δ�ҵ�����\n");
			return NULL;
		}
		return pMove;
	}
}

////���ҹ���1
//!struct Node *search(struct Node *headNode,int data)
//��ΪdataΪstruct student data���Կ���ָ���������в���
struct Node *searchxm(struct Node *headNode,char name[])
{
	struct Node *pMove=headNode->next;
	if(pMove==NULL)
	{
		printf("����Ϊ�գ�����ʧ��\n");
		return NULL;
	}
	//!!!!	while(pMove->data!=data)
	while(strcmp(pMove->data.name,name))
	{
		pMove=pMove->next;
		if(pMove==NULL)
		{
			printf("δ�ҵ�����\n");
			return NULL;
		}
		return pMove;
	}
}


//�˵�
void menu()
{
	printf("----------�� ѧ����Ϣ����ϵͳ��--------------");
	printf("\n\t1.ѧ����Ϣ¼��");
	printf("\n\t2.ѧ����Ϣ�������");
	printf("\n\t3.��ѯ��������");
	printf("\n\t a.��ѧ�Ų�ѯ");
	printf("\n\t b.��������ѯ");
	printf("\n\t4.ѧ����Ϣ��ɾ�����޸�");
	printf("\n\t a.��ѧ��ɾ��");
	printf("\n\t b.������ɾ��");
	printf("\n\t0.��ȫ�˳�\n");
	printf("---------------------------------------------\n");
}/*�Բ˵���ʽ����
aϵͳ�Բ˵���ʽ����
bѧ����Ϣ¼�빦�ܣ�ѧ����Ϣ���ļ����棩---����
cѧ����Ϣ������ܡ������
d ��ѯ�������ܡ����㷨
1����ѧ�Ų�ѯ
2����������ѯ
eѧ����Ϣ��ɾ�����޸ģ���ѡ�*/


//ѡ���ܰ���
void keydown()
{
	int x;//ѡ��ֵ��0-4���ı���;
	char m;//ѡ��a����b�ı���m;
	char flag;//�ж��Ƿ��������ı���flag;
	struct Node *list=createList();//����list����
	struct student *data;
	printf("��������Ҫ�Ĺ������(0-4):");
	scanf("%d",&x);
	switch(x)
	{
	case 0:
		printf("��ȫ�˳�\n");
		system("pause");
		exit(0);
	case 1:
		printf("\tѧ����Ϣ¼��\n");
		//��������
		//ÿ��¼��һ����Ϣ
		printf("������");
		printf("ѧ��\t����\t����\t�Ա�\t�������£�2000 1 1��\t��ַ\t�绰\tE-mail:\n");
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
		printf("\tѧ����Ϣ���\n");
		//��ӡ����
		printfList(list);
		system("pause");
		break;
	case 3:
		printf("\t��ѯ\n");
		printf("�������ѯ��ʽ:a��ѧ�Ų�ѯ/b��������ѯ:");
		getchar();
		m=getchar();
		if(m=='a')
		{	
			printf("\t-------��ѧ�Ų�ѯ--------\n");
			printf("������ѧ��ѧ��:");
			fflush(stdin);

			scanf("%d",&data->xh);
			if(searchxh(list,data->xh)==NULL)
			{
				printf("δ�ҵ������Ϣ\n");
				system("pause");
			}
			else
			{
				printf("ѧ����ϢΪ\n:");
				printf("ѧ��\t����\t����\t�Ա�\t��������\t��ַ\t�绰\tE-mail:\n");
				printf("%d\t %s\t %d\t %s\t %d\t %s\t %d\t %s\n",searchxh(list,data->xh)->data.xh,searchxh(list,data->xh)->data.name,
					searchxh(list,data->xh)->data.old,searchxh(list,data->xh)->data.sex,searchxh(list,data->xh)->data.year,
					searchxh(list,data->xh)->data.month,searchxh(list,data->xh)->data.day,searchxh(list,data->xh)->data.dz,
					searchxh(list,data->xh)->data.dh,searchxh(list,data->xh)->data.mail);
			}
		}
		else if(m=='b')
		{
			printf("\t-------��������ѯ--------\n");
			printf("�������ѧ������:");
			fflush(stdin);

			scanf("%s",data->name);
			if(searchxm(list,data->name)==NULL)
			{
				printf("δ�ҵ������Ϣ\n");
				system("pause");
			}
			else
			{			
				printf("ѧ����ϢΪ\n:");
				printf("ѧ��\t����\t����\t�Ա�\t��������\t��ַ\t�绰\tE-mail:\n");
				printf("%d\t %s\t %d\t %s\t %d\t %s\t %d\t %s\n",searchxm(list,data->name)->data.xh,searchxm(list,data->name)->data.name,
					searchxm(list,data->name)->data.old,searchxm(list,data->name)->data.sex,searchxm(list,data->name)->data.year,
					searchxm(list,data->name)->data.month,searchxm(list,data->name)->data.day,searchxm(list,data->name)->data.dz,
					searchxm(list,data->name)->data.dh,searchxm(list,data->name)->data.mail);
			}
		}
		else
			printf("\t��ѯ��ʽ����������a����b\n");
		break;
	case 4:
		printf("ѧ����Ϣ��ɾ��\n");
		printf("��ѡ��ɾ����ʽ��a��ѧ��ɾ��/b�������޸ģ�");

		fflush(stdin);
		m=getchar();
		if(m=='a')
		{	
			printf("\t-------��ѧ��ɾ��--------\n");
			printf("������ɾ����ѧ��ѧ��:");
			fflush(stdin);

			scanf("%d",&data->xh);
			if(searchxm(list,data->xh)==NULL)
			{
				printf("δ�ҵ������Ϣ���޷�ɾ��\n");
				system("pause");
			}
			else
			{
				printf("ɾ����ѧ����ϢΪ\n:");
				printf("ѧ��\t����\t����\t�Ա�\t��������\t��ַ\t�绰\tE-mail:\n");
				printf("%d\t %s\t %d\t %s\t %d\t %s\t %d\t %s\n",searchxm(list,data->xh)->data.xh,searchxm(list,data->xh)->data.name,
					searchxm(list,data->xh)->data.old,searchxm(list,data->xh)->data.sex,searchxm(list,data->xh)->data.year,
					searchxm(list,data->xh)->data.month,searchxm(list,data->xh)->data.day,searchxm(list,data->xh)->data.dz,
					searchxm(list,data->xh)->data.dh,searchxm(list,data->xh)->data.mail);
				printf("�Ƿ�ɾ����y/n");
				printf("\n");
				scanf("%c",&flag);
				getchar();
				if(flag!='n')
				{
					delectAppoinNodexh(list,data->xh);
					printf("�ɹ�ɾ��\n");
				}			
			}
		}
		else if(m=='b')
		{
			printf("\t-------������ɾ��--------\n");
			printf("������ɾ����ѧ������:");
			scanf("%s",data->name);
			if(searchxm(list,data->name)==NULL)
			{
				printf("δ�ҵ������Ϣ���޷�ɾ��\n");
				system("pause");
			}
			else
			{			
				printf("ɾ����ѧ����ϢΪ\n:");
				printf("ѧ��\t����\t����\t�Ա�\t��������\t��ַ\t�绰\tE-mail:\n");
				printf("%d\t %s\t %d\t %s\t %d\t %s\t %d\t %s\n",searchxm(list,data->name)->data.xh,searchxm(list,data->name)->data.name,
					searchxm(list,data->name)->data.old,searchxm(list,data->name)->data.sex,searchxm(list,data->name)->data.year,
					searchxm(list,data->name)->data.month,searchxm(list,data->name)->data.day,searchxm(list,data->name)->data.dz,
					searchxm(list,data->name)->data.dh,searchxm(list,data->name)->data.mail);
				printf("�Ƿ�ɾ����y/n");
				printf("\n");
				scanf("%c",&flag);
				getchar();
				if(flag!='n')
				{
					delectAppoinNodexm(list,data->name);
					printf("�ɹ�ɾ��\n");
				}
			}	
		}
	default:
		printf("�������,����������\n");
		system("pause");
		break;
	}
}//���û��������԰�������





//������
void main()
{
	//listΪ�����ͷ
	struct Node *list=createList();

	while(1)
	{
		menu();
		keydown();
		system("cls");
		system("pause");
	}

}








