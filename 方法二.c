//ͷ�ļ�
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
};//ѧ�ţ����������䣬�Ա𣬳������£���ַ���绰��E-mail
/*//��Ϣ
struct birth
{
	int year;
	int month;
	int day;
};//��������
*/

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
		printf("%d\t %s\t %d\t %c\t %d\t %s\t %d\t %s\n",pMove->data.xh,pMove->data.name,pMove->data.old,pMove->data.sex,
			pMove->data.year,pMove->data.month,pMove->data.day,pMove->data.dz,pMove->data.dh,pMove->data.mail);
		pMove=pMove->next;
	}
	printf("\n");
}

//ָ��λ��ɾ��
//!struct Node *delectAppoinNode(struct Node *headNode,int data)
//��ΪdataΪstruct student data���Կ���ָ������������ѧ�Ž���ɾ��
struct Node *delectAppoinNode(struct Node *headNode,int xh)
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

//���ҹ���
//!struct Node *search(struct Node *headNode,int data)
//��ΪdataΪstruct student data���Կ���ָ������������ѧ�Ž��в���
struct Node *search(struct Node *headNode,int xh)
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


//ѧ����Ϣ¼�빦��
struct student *lulu()
{
	char flag;
	struct student *data;
	struct Node *head,*current,*next;
	//������ͷ
	head=(struct Node *)malloc(sizeof(struct Node));
	head->next=NULL;
	printf("�Ƿ�Ҫ����ѧ����Ϣ��Y/N");
	printf("\n");
	scanf("%c",&flag);
	getchar();
	if(flag!='n')
	{
		printf("������ѧ����\n");
		printf("ѧ��\t����\t����\t�Ա�\t��������(�ο�2000 1 1)\t��ַ\t�绰\tE-mail:\n");
		scanf("%d%s%d%c%d%s%d%s",head->data.xh,head->data.name,head->data.old,head->data.sex,
	   head->data.year,
	   head->data.month,
	   head->data.day,head->data.dz,head->data.dh,head->data.mail);
	}
	getchar();

	//�½ڵ�
	current=head;
	printf("�Ƿ�������룿Y/N");
	printf("\n");
	scanf("%c",&flag);
	getchar();
	while(flag!='n')
	{
		//��һ�ڵ�
		next=(struct Node *)malloc(sizeof(struct Node));
		printf("������\n");
		printf("ѧ�ţ����������䣬�Ա𣬳������£���ַ���绰��E-mail:\n");
		scanf("%d%s%d%c%d%s%d%s",head->data.xh,head->data.name,head->data.old,head->data.sex,
	   head->data.year,
	   head->data.month,
	   head->data.day,head->data.dz,head->data.dh,head->data.mail);

		current->next=next;
		current=next;

		printf("�Ƿ�������룿Y/N");		
		printf("\n");
		scanf("%c",&flag);
		getchar();
	}
	current->next=NULL;
	return head;
}//ѧ����Ϣ¼��

//�˵�
void menu()
{
	printf("----------�� ѧ����Ϣ����ϵͳ��--------------");
	printf("\n\t1.ѧ����Ϣ¼��");
	printf("\n\t2.ѧ����Ϣ�������");
	printf("\n\t3.��ѯ��������");
	printf("\n\t a.��ѧ�Ų�ѯ");
	printf("\n\t b.��������ѯ");
	printf("\n\t4.ѧ����Ϣ��ɾ��");
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
	int x;
	char m;
	struct Node *list=NULL;
	struct student *data;
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
		list=lulu();
		getchar();
		system("pause");
		break;
	case 2:
		printf("\tѧ����Ϣ���\n");
		//��ӡ����
		printfList(list);
		system("pause");
		break;
	case 3:
		printf("\t��ѯ������\n");
		printf("�������ѯ��ʽ:a��ѧ�Ų�ѯ/b��������ѯ:");
		getchar();
		m=getchar();
		if(m=='a')
			printf("\t-------��ѧ�Ų�ѯ--------\n");
		else if(m=='b')
			printf("\t-------��������ѯ--------\n");
		else
			printf("\t��ѯ��ʽ����������a����b\n");
		break;
	case 4:
		printf("ѧ����Ϣ��ɾ�����޸�\n");
		system("pause");
		break;
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
		printf("��������Ҫ�Ĺ�����ţ�");
		keydown();
		system("pause");
		system("cls");
	}


}
