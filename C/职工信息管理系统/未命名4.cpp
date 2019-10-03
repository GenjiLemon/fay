#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//void save(Node*worker);
struct workers
{
    char num[25];//ְ����
    char name[25];//ְ������
    char sex[25];//ְ���Ա�
    char addr[20];//ְ����ַ
    char degree[25];//ְ��ѧ��
    int age;       //ְ������
    char tel[25];  //ְ���绰
    char salary[25];//ְ������
};
typedef struct node
{
    struct workers data;
    struct node*next;
}Node;
void save(Node*worker)
{
    int n;
    Node*p;
    FILE*fp;
    printf("��Ҫ�����ļ���(0--�����棬1--����)");
    scanf("%d",&n);
    if(n==1)
    {
        if(worker->next==NULL)
            printf("�޼�¼");
        else
            p=worker->next;
        if((fp=fopen("zg.data","wb"))==NULL)
            printf("can not open file\n");
            else{
        while(p!=NULL)
        {
            fprintf(fp,"%s %s %s %s %s %d %s %s",p->data.num,p->data.name,p->data.sex,p->data.addr,p->data.degree,p->data.age,p->data.tel,p->data.salary);
            p=p->next;
        }
        fclose(fp);
            }
    }
}
void add(Node*worker)
{
    Node*p,*r;
    char n[10];//����������ְ���ţ�Ҳ�����ж��Ƿ�����ѭ��
    r=worker;
    while(r->next!=NULL)
        r=r->next;
    while(1)
    {
        printf("......��ʾ������0�򷵻����˵�!\n......");
        printf("......������ְ����;......");
        scanf("%s",&n);
        if(strcmp(n,"0")==0)
            break;
        p=(Node*)malloc(sizeof(Node));//����ռ�
        strcpy(p->data.num,n);
        printf("����������");
        scanf("%s",p->data.name);
        printf("�������Ա�");
        scanf("%s",p->data.sex);
        printf("�������ַ");
        scanf("%s",p->data.addr);
        printf("������ѧ��");
        scanf("%s",p->data.degree);
        printf("����������");
        scanf("%d",&p->data.age);
        printf("������绰");
        scanf("%s",p->data.tel);
        printf("�����빤��");
        scanf("%s",p->data.salary);
        printf("��ʾ�����һ����Ϣ���\n");
        p->next=NULL;
        r->next=p;
        r=p;
        save(worker);
 
    }
}
void change(Node*worker)
{
    Node*p;
    char find[25];
    if(!worker->next)
    {
        printf("\n......��ʾ��û�����Ͽ��޸�\n......");
        return;
    }
    printf("������Ҫ�޸ĵ�ְ����");
    scanf("%s",find);
    p=worker->next;
    while(p!=NULL)
    {
        if(strcmp(p->data.num,find)==0)
            break;
        p=p->next;
    }
    if(p)
    {
        int x;
        while(1)
        {
            printf("����޸�����0��������������ֽ����޸�");
            scanf("%d",&x);
            if(x==0)
            {
                break;
            }
            printf("��������ְ����");
            scanf("%s",p->data.num);
            printf("��������ְ������");
            scanf("%s",p->data.name);
            printf("��������ְ���Ա�");
            scanf("%s",p->data.sex);
            printf("��������ְ����ַ");
            scanf("%s",p->data.addr);
            printf("��������ְ��ѧ��");
            scanf("%s",p->data.degree);
            printf("��������ְ������");
            scanf("%d",&p->data.age);
            printf("��������ְ���绰");
            scanf("%s",p->data.tel);
            printf("��������ְ������");
            scanf("%s",p->data.salary);
            printf("��ʾ��������Ϣ�����Ѿ��޸ĳɹ�\n");
        }
    }
    else
        printf("��ʾ����Ҫ�޸ĵ���Ϣ������\n");
}
void load(Node*worker)
{
    Node*p,*q;
    FILE*fp;
    int recordnum;
    if((fp=fopen("zg.data","rb"))==NULL)
    {
        printf("can not open file\n");
    }
    p=worker;
    recordnum=0;
    while(!(feof(fp)))
    {
        q=(Node*)malloc(sizeof(Node));
        fscanf(fp,"%s %s %s %s %s %d %s %s",p->data.num,p->data.name,p->data.sex,p->data.addr,p->data.degree,&(p->data.age),p->data.tel,p->data.salary);
        p->next=q;
        q->next=NULL;
        p=q;
        recordnum++;
    }
    fclose(fp);
    printf("�ļ�����%d����Ϣ",recordnum);
}
void show(Node*worker)
{
	 int n;
    Node*p;
    p=worker->next;
    if(!p)
    {
        printf("��ʾ:û����Ϣ������ʾ\n");
        printf("����0�򷵻����˵�!\n");
      	scanf("%d",&n);
      	if(n==0)return ;
    }
    printf("\t\t\t\t��ʾ���\n");
    printf("ְ����   ְ������   ְ���Ա�   ְ����ַ   ְ��ѧ��   ְ������  ְ���绰   ְ������\n");
    while(p)
    {
        printf("13s%-11s%-7s%-10s%-13s%-10d%-5s-7%s\n",p->data.num,p->data.name,p->data.sex,p->data.addr,p->data.degree,&(p->data.age),p->data.tel,p->data.salary);
        p=p->next;
    }
    printf("\n......��ʾ������0�򷵻����˵�!\n......");
    scanf("%d",&n);
    if(n==0)return ;
    
 
}
void tongji(Node*worker)
{
    Node*p;
    int sel;
    int flag2=0,a=0;
    char find[25];
    p=worker->next;
    if(!worker->next)
    {
        printf("��ʾû����Ϣ���Է���\n");
        return;
    }
    printf("��ʾ��n====>0�˳�\n====>1��ְ����ͳ��\n====>2��ְ������ͳ��\n");
    scanf("%d",sel);
    if(sel==1)
    {
      printf("������ͳ�Ʒ����ְ����");
      scanf("%s",find);
      while(p)
      {
          if(strcmp(p->data.num,find)==0)
          {
              flag2++;
          }
          if(flag2==1&&a!=flag2)
          {
              printf("ְ����   ְ������   ְ���Ա�   ְ����ַ   ְ��ѧ��   ְ������  ְ���绰   ְ������\n");
              printf("13s%-11s%-7s%-10s%-13s%-10d%-5s%-7s%\n",p->data.num,p->data.name,p->data.sex,p->data.addr,p->data.degree,&(p->data.age),p->data.tel,p->data.salary);
              a=flag2;
          }
          else if(flag2>a)
          {
              printf("13s%-11s%-7s%-10s%-13s%-10d%-5s-7s%\n",p->data.num,p->data.name,p->data.sex,p->data.addr,p->data.degree,&(p->data.age),p->data.tel,p->data.salary);
              a=flag2;
          }
          p=p->next;
      }
      if(flag2)
      {
          printf("���豸��%sͳ�Ʒ�����%d����Ϣ");
      }
      else
      {
        printf("��ְ����%sͳ�ƽ��Ϊ0��");
      }
    }
      else if(sel==2)
      {
          printf("������ͳ�Ʒ���ְ������");
          scanf("%s",find);
          while(p)
          {
              if(strcmp(p->data.name,find)==0)
              {
                  flag2++;
              }
              if(flag2==1&&a!=flag2)
              {
                  printf("ְ����   ְ������   ְ���Ա�   ְ����ַ   ְ��ѧ��   ְ������  ְ���绰   ְ������\n");
                  printf("13s%-11s%-7s%-10s%-13s%-10d%-5s%-7s%\n",p->data.num,p->data.name,p->data.sex,p->data.addr,&(p->data.age),p->data.age,p->data.tel,p->data.salary);
                  a=flag2;
              }
          else if(flag2>a)
          {
              printf("13s%-11s%-7s%-10s%-13s%-10d%-5s-7s%\n",p->data.num,p->data.name,p->data.sex,p->data.addr,p->data.degree,&(p->data.age),p->data.tel,p->data.salary);
              a=flag2;
          }
          p=p->next;
          }
          if(flag2)
          {
              printf("���鵽%d����Ϣ");
          }
          else
          {
              printf("��ְ������%sͳ�ƽ��Ϊ0��");
          }
      }
          else if(flag2==0)
            return;
}
void del(Node*worker)
{
    Node*p,*r,*s;
    char find[25];
    if(!worker->next)
    {
        printf("��ʾ:û����Ϣ����ɾ��");
        return;
    }
    printf("��ʾ:������Ҫɾ����ְ����");
    scanf("%s",find);
    p=worker->next;
    while(p!=NULL)
    {
        if(strcmp(p->data.num,find)==0)
        break;
        p=p->next;
    }
    if(!p)
        printf("��ʾ:�Ҳ�����Ҫɾ����ְ����");
    else
        {
            r=worker;
            while(r->next!=p)
            r=r->next;
            s=r->next;
            r->next=r->next->next;
        }
}
int  main()
{
 
    Node*worker;
    FILE*fp;
    int flag;
    Node*p,*q;
    worker = (Node*)malloc(sizeof(Node));
    if (worker == NULL) {
      printf("Memory malloc ERROR!!");
    }
    worker->next=NULL;
    p=worker;
    while(1)
    {
        printf("\t\t\t\tְ������ϵͳ\n");
        printf(".............ѡ��............\n");
        printf("1--�����Ϣ:\n");
        printf("2--�޸���Ϣ:\n");
        printf("3--��ʾ��Ϣ:\n");
        printf("4--���������Ϣ:\n");
        printf("5--ɾ����Ϣ:\n");
        printf("6--��ȡ��Ϣ:\n");
        printf("0--�˳�ϵͳ:\n");
        printf("����ѡ��:");
        scanf("%d",&flag);
        switch(flag)
        {
            case 0:exit(0);
            case 1:add(worker);break;
            case 2:change(worker);break;
            case 3:show(worker);break;
            case 4:tongji(worker);break;
            case 5:del(worker);break;
            case 6:load(worker);break;
            default:  printf("��ʾ:�������");break;
        }
        system("cls");
    }
}
