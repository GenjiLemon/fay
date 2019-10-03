#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//void save(Node*worker);
struct workers
{
    char num[25];//职工号
    char name[25];//职工姓名
    char sex[25];//职工性别
    char addr[20];//职工地址
    char degree[25];//职工学历
    int age;       //职工年龄
    char tel[25];  //职工电话
    char salary[25];//职工工资
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
    printf("需要保存文件吗？(0--不保存，1--保存)");
    scanf("%d",&n);
    if(n==1)
    {
        if(worker->next==NULL)
            printf("无记录");
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
    char n[10];//先用于输入职工号，也用于判断是否跳出循环
    r=worker;
    while(r->next!=NULL)
        r=r->next;
    while(1)
    {
        printf("......提示：输入0则返回主菜单!\n......");
        printf("......请输入职工号;......");
        scanf("%s",&n);
        if(strcmp(n,"0")==0)
            break;
        p=(Node*)malloc(sizeof(Node));//申请空间
        strcpy(p->data.num,n);
        printf("请输入姓名");
        scanf("%s",p->data.name);
        printf("请输入性别");
        scanf("%s",p->data.sex);
        printf("请输入地址");
        scanf("%s",p->data.addr);
        printf("请输入学历");
        scanf("%s",p->data.degree);
        printf("请输入年龄");
        scanf("%d",&p->data.age);
        printf("请输入电话");
        scanf("%s",p->data.tel);
        printf("请输入工资");
        scanf("%s",p->data.salary);
        printf("提示：完成一条信息添加\n");
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
        printf("\n......提示：没有资料可修改\n......");
        return;
    }
    printf("请输入要修改的职工号");
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
            printf("完成修改输入0否侧输入任意数字进行修改");
            scanf("%d",&x);
            if(x==0)
            {
                break;
            }
            printf("请输入新职工号");
            scanf("%s",p->data.num);
            printf("请输入新职工姓名");
            scanf("%s",p->data.name);
            printf("请输入新职工性别");
            scanf("%s",p->data.sex);
            printf("请输入新职工地址");
            scanf("%s",p->data.addr);
            printf("请输入新职工学历");
            scanf("%s",p->data.degree);
            printf("请输入新职工年龄");
            scanf("%d",&p->data.age);
            printf("请输入新职工电话");
            scanf("%s",p->data.tel);
            printf("请输入新职工工资");
            scanf("%s",p->data.salary);
            printf("提示：该项信息资料已经修改成功\n");
        }
    }
    else
        printf("提示；你要修改的信息不存在\n");
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
    printf("文件共有%d条信息",recordnum);
}
void show(Node*worker)
{
	 int n;
    Node*p;
    p=worker->next;
    if(!p)
    {
        printf("提示:没有信息可以显示\n");
        printf("输入0则返回主菜单!\n");
      	scanf("%d",&n);
      	if(n==0)return ;
    }
    printf("\t\t\t\t显示结果\n");
    printf("职工号   职工姓名   职工性别   职工地址   职工学历   职工年龄  职工电话   职工工资\n");
    while(p)
    {
        printf("13s%-11s%-7s%-10s%-13s%-10d%-5s-7%s\n",p->data.num,p->data.name,p->data.sex,p->data.addr,p->data.degree,&(p->data.age),p->data.tel,p->data.salary);
        p=p->next;
    }
    printf("\n......提示：输入0则返回主菜单!\n......");
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
        printf("提示没有信息可以分类\n");
        return;
    }
    printf("提示：n====>0退出\n====>1按职工号统计\n====>2按职工姓名统计\n");
    scanf("%d",sel);
    if(sel==1)
    {
      printf("请输入统计分类的职工号");
      scanf("%s",find);
      while(p)
      {
          if(strcmp(p->data.num,find)==0)
          {
              flag2++;
          }
          if(flag2==1&&a!=flag2)
          {
              printf("职工号   职工姓名   职工性别   职工地址   职工学历   职工年龄  职工电话   职工工资\n");
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
          printf("按设备号%s统计分类有%d条信息");
      }
      else
      {
        printf("按职工号%s统计结果为0个");
      }
    }
      else if(sel==2)
      {
          printf("请输入统计分类职工姓名");
          scanf("%s",find);
          while(p)
          {
              if(strcmp(p->data.name,find)==0)
              {
                  flag2++;
              }
              if(flag2==1&&a!=flag2)
              {
                  printf("职工号   职工姓名   职工性别   职工地址   职工学历   职工年龄  职工电话   职工工资\n");
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
              printf("共查到%d条信息");
          }
          else
          {
              printf("按职工新名%s统计结果为0个");
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
        printf("提示:没有信息可以删除");
        return;
    }
    printf("提示:请输入要删除的职工号");
    scanf("%s",find);
    p=worker->next;
    while(p!=NULL)
    {
        if(strcmp(p->data.num,find)==0)
        break;
        p=p->next;
    }
    if(!p)
        printf("提示:找不到想要删除的职工号");
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
        printf("\t\t\t\t职工管理系统\n");
        printf(".............选单............\n");
        printf("1--添加信息:\n");
        printf("2--修改信息:\n");
        printf("3--显示信息:\n");
        printf("4--分类查找信息:\n");
        printf("5--删除信息:\n");
        printf("6--读取信息:\n");
        printf("0--退出系统:\n");
        printf("输入选择:");
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
            default:  printf("提示:输入错误");break;
        }
        system("cls");
    }
}
