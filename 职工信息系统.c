#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct worker
{
	char num[4];  /*职工号*/
	char name[10]; /*姓名*/
	char sex;
	int age;
	char edu[10];/*学历*/
	int salary;
	char address[20];
	char phone[12];
	struct worker *next;
};

#define LEN sizeof(struct worker)
void input(struct worker *h);   /*声明*/
void output(struct worker *h); 
void eight(struct worker *h); 
void seven(struct worker *h);
void add(struct worker *h);   
void fdelete(struct worker *h);
void search(struct worker *h);
void change(struct worker *h);
main()                            /*主函数*/
{
	int choice;
	char s;

	struct worker *head;
    head=(struct worker *)malloc(LEN);
    head->next=NULL;

	while(1)
	{
		system("cls");
		printf("\n\n\n");
		printf("\t\t********************************\n");
		printf("\t\t*       职工信息管理系统       *\n");
		printf("\t\t********************************\n");
		printf("\t\t*         1初始化数据          *\n");
		printf("\t\t*         2新增数据            *\n");
		printf("\t\t*         3修改数据            *\n");
		printf("\t\t*         4删除数据            *\n");
		printf("\t\t*         5查找数据            *\n");
		printf("\t\t*         6浏览数据            *\n");
		printf("\t\t*         7导入数据            *\n");
		printf("\t\t*         8导出数据            *\n");
		printf("\t\t*         0退出系统            *\n");
		printf("\t\t********************************\n");
	
		printf("%5s请选择你想要的功能(0~8):\n"," ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				{	if(head->next!=NULL) 
					{printf("是否需要将数据导入文件?(y)\n");
					getchar();
					s=getchar();
					if(s=='y'||s=='Y') eight(head);}
					return 0;
				}
			case 1:input(head);break;
			case 2:add(head);break;
			case 3:change(head);break;
			case 4:fdelete(head);break;
			case 5:search(head);break;
			case 6:output(head);break;
			case 7:seven(head);break;
			case 8:eight(head);break;
			default:printf("输入有误！");break;
		}

	}
}

  void input(struct worker *h)   /*1初始化*/
	{
		int i,n;
		struct worker *p,*q;
		p=h;
		if(h->next) 
			{
				printf("非空，不能进行初始化！\n");
				system("pause");
				return;
			}
		printf("人数：");	scanf("%d",&n);
		getchar();
		for(i=0;i<n;i++)
		{
			q=(struct worker *)malloc(LEN);
			system("cls");
	   		printf("职工号:");     gets(q->num);
		 	printf("姓名:");       gets(q->name);
	 	 	printf("性别:");       q->sex=getchar();
	  		printf("年龄:");   	   scanf("%d",&q->age);
	     	getchar();      	   
		 	printf("学历:");       gets(q->edu);
		  	printf("工资:");	    scanf("%d",&q->salary);
 		  	getchar();
		 	printf("地址:");		gets(q->address);
		  	printf("电话号码:");	gets(q->phone);
			p->next=q;                                                                                                
			q->next=NULL;
			p=q;
		}
	}


 

    void output(struct worker *h)  /*6浏览*/
	{
		struct worker *p;
		p=h->next;
		if(h->next==NULL) {printf("链表为空！\n");system("pause");return;}
		system("cls");
		printf("%-8s%-10s%-6s%-6s%-10s%-8s%-20s%-15s\n","职工号","姓名","性别","年龄","学历","工资","家庭地址","电话号码");
		while(p!=NULL)
		{ 
			printf("%-8s%-10s%-6c%-6d%-10s%-8d%-20s%-15s\n",p->num,p->name,p->sex,p->age,p->edu,p->salary,p->address,p->phone);
			p=p->next;
		}
	system("pause");
	}
	



    void eight(struct worker *h)     /*8导出*/
    {
		struct worker *p;
		FILE *fp;
		if(h->next==NULL) {printf("链表为空，不需要导出数据!\n");system("pause");return;}
		fp=fopen("f1.dat","wb");
		if(fp==NULL)
		{ 
			printf("文件打开失败!\n");
			exit(0);
		}
		p=h->next;
        while(p)
        {
			fwrite(p,LEN,1,fp);
			p=p->next;
		}
		
		fclose(fp);
		printf("导出成功!\n");
		system("pause");
	}
void seven(struct worker *h)     /*7导入*/
    {
	    char ch;
		struct worker *p,*q;
		FILE *fp;
		if(h->next!=NULL) 
			{
				printf("链表中有数据，导入数据后，原链表中的数据将丢失!\n是否继续导入数据？(是-y)\n");
				system("pause");
				fflush(stdin);
				scanf("%c",&ch);
				if(ch!='y'&&ch!='Y') return;
			}
		
			fp=fopen("f1.dat","rb");
			if(fp==NULL)
			{ 
				printf("文件打开失败!\n");
				exit(0);
			}
			q=(struct worker *)malloc(LEN);
			fread(q,LEN,1,fp);
			p=h;
			while(!feof(fp))
			{
				p->next=q;q->next=NULL;
				p=q;
				q=(struct worker *)malloc(LEN);
				fread(q,LEN,1,fp);	
			}
			fclose(fp);
			printf("导入成功!\n");
			system("pause");
		
	}

   void add(struct worker *h)      /*2新增数据*/
   {
	   int i,m=1;
	   char ch;
	   void myadd1(struct worker *h);
       void myadd2(struct worker *h);
       if(h->next==NULL) {printf("链表为空！请进行初始化！\n\n");system("pause");return;}
	   while(1)
	   {
			system("cls");
			printf("\n\n");
			printf("\t\t********************************\n");
			printf("\t\t**     1在指定职工号之后      **\n");
			printf("\t\t**     2在指定职工号之前      **\n");
			printf("\t\t**     0返回上一层            **\n");
			printf("\t\t********************************\n\n\n");
			printf("请选择:");scanf("%d",&i);
			switch(i)
			 { 
				case 0:return;
				case 1:	myadd1(h);break;
				case 2:	myadd2(h);break;
				default:{printf("输入错误！\n");system("pause");break;}
			 }
			printf("是否继续追加数据？(Y?)\n");scanf("%c",&ch);
			getchar();
			if(ch=='y'||ch=='Y') m=1;
			else return;

	   }
   }
		


    void myadd1(struct worker *h)      /*2新增数据，在指定职工号位置之后添加*/
	{
		char num0[4];
		struct worker *p,*r;
		getchar();
		printf("插入职工号之后:");
		gets(num0);
        r=(struct worker *)malloc(LEN);
        p=h->next;
		while(p)
		{
			if(strcmp(p->num,num0)==0)break;
			else p=p->next;
		}
		if(p)
		{
			r->next=p->next;
			p->next=r;
		}
		else {printf("未找到此职工号！\n");return;}
		printf("新增成员信息:\n");
		 printf("职工号:");  gets(r->num);
		 printf("姓名:");    gets(r->name);
		 printf("性别:");    r->sex=getchar();
		 printf("年龄:");    scanf("%d",&r->age);
	     getchar();
		 printf("学历:");   gets(r->edu);
		 printf("工资:");   scanf("%d",&r->salary);
	     getchar();
		 printf("地址:");     gets(r->address);
		 printf("电话号码:");  gets(r->phone);

	}

	void myadd2(struct worker *h)      /*2新增数据，在指定职工号位置之前添加*/
	{
		char num0[4];
		struct worker *p,*q,*r;
		getchar();
		printf("插入职工号之前:");
		gets(num0);
        r=(struct worker *)malloc(LEN);
        p=h;q=h->next;
		while(q)
		{
			if(strcmp(q->num,num0)==0)break;
			else {p=q;q=q->next;}
		}
		if(q)
		{
			r->next=q;
			p->next=r;
		}
		else {printf("未找到此职工号！\n");return;}
		printf("新增成员信息:\n");
	 	printf("职工号:");  gets(r->num);
		printf("姓名:");    gets(r->name);
		printf("性别:");    r->sex=getchar();
		printf("年龄:");    scanf("%d",&r->age);
	    getchar();
		printf("学历:");   gets(r->edu);
		printf("工资:");   scanf("%d",&r->salary);
	    getchar();
		printf("地址:");     gets(r->address);
		printf("电话号码:");  gets(r->phone);

	}


	void fdelete(struct worker *h)     /*4删除*/
	{
		int i,m=1;char ch;
		void delete1(struct worker *h);
     	void delete2(struct worker *h);
		if(h->next==NULL) {printf("链表为空,不能删除！\n");system("pause");return;}
		
	  while(m)
	  {
	  	system("cls");
	  	printf("\n\n");
		printf("\t\t********************************\n");
		printf("\t\t**     1按职工号删除          **\n");
		printf("\t\t**     2按姓名删除            **\n");
		printf("\t\t**     0返回上一层            **\n");
		printf("\t\t********************************\n\n\n");
		printf("请选择:");
		scanf("%d",&i);
		switch(i)
		{
			 case 0:return;break;
			 case 1:delete1(h);break;
			 case 2:delete2(h);break;
			 default:printf("输入有误!\n");break;
		} 
			printf("是否继续追加数据？(Y?)\n");scanf("%c",&ch);
			getchar();
			if(ch=='y'||ch=='Y') m=1;
			else return;
	  }
	}
	
    void delete1(struct worker *h)     /*4按职工号删除*/
    {
		char num0[4];
    	struct worker *p,*q;
    	p=h;q=h->next;
		getchar();
		printf("输入删除的职工号:");
		gets(num0);
    	while(q)
    	{
	    	if(strcmp(q->num,num0)==0)break;
	    	p=q;q=q->next;
	    }
	    if(q) 
	        {
        		printf("find!\n");
        		p->next=q->next;
        	}
    	else printf("not find!\n");
    	system("pause");
    } 
    
    void delete2(struct worker *h)     /*4按姓名删除*/
    {
    	int count=0;
		char name0[10];
    	struct worker *p,*q;
		getchar();
		printf("输入删除的姓名:");
		gets(name0);
    	p=h;q=h->next;
    	while(q)
    	{
	    	if(strcmp(q->name,name0)==0)
	    	{
	    		count++;
        		p->next=q->next;
	    	}
	    	p=q;q=q->next;
	    }
        if(count==0) printf("not find!\n");
        else   		printf("find\n%d个！\n",count);
        system("pause");
    } 
    
    
   	void search(struct worker *h)     /*5查找*/
	{
		int i,m=1;char ch;
		void search1(struct worker *h);
   	    void search2(struct worker *h);
		if(h->next==NULL) {printf("链表为空，不能删除！\n");system("pause");return;}
		while(1)
		{
				system("cls");
				printf("\n\n\n");
				printf("\t\t********************************\n");
				printf("\t\t**     1按职工号查找          **\n");
				printf("\t\t**     2按姓名查找            **\n");
				printf("\t\t**     0返回上一层            **\n");
				printf("\t\t********************************\n\n\n");
				printf("请选择:");
				scanf("%d",&i);
				switch(i)
				{
					case 0:return;
					case 1:search1(h);break;
					case 2:search2(h);break;
					default:printf("输入有误！");break;
				}
					printf("是否继续追加数据？(Y?)\n");
			ch=getchar();
			if(ch=='y'||ch=='Y') m=1;
			else return;
		}
	}
	
	void search1(struct worker *h) /*按职工号查找*/
	{
		char num0[4];
		struct worker *p;
		p=h->next;
		getchar();                            /*!!!!!!!!!!!!!!*/
		printf("输入要查找的职工号：");
		gets(num0);
		printf("%-8s%-10s%-6s%-6s%-10s%-8s%-20s%-15s\n","职工号","姓名","性别","年龄","学历","工资","家庭地址","电话号码");
		while(p)
		{
			if(strcmp(p->num,num0)==0)
				   printf("%-8s%-10s%-6c%-6d%-10s%-8d%-20s%-15s\n",p->num,p->name,p->sex,p->age,p->edu,p->salary,p->address,p->phone);break;
			p=p->next;
		}
		if(p==NULL) printf("not find!\n");
		system("pause");
	} 
	
	 void search2(struct worker *h)     /*按姓名查找*/
    {
    	int count=0;
    	char name[10];
   		struct worker *p;
		p=h->next;
		fflush(stdin);                            /*!!!!!!!!!!!!!!*/
		printf("输入要查找的姓名：");
		gets(name);
		printf("\n\n%-8s%-10s%-6s%-6s%-10s%-8s%-20s%-15s\n","职工号","姓名","性别","年龄","学历","工资","家庭地址","电话号码");
		while(p)
		{
			if(strcmp(p->name,name)==0)
			 {
			 	count++;
 				 printf("%-8s%-10s%-6c%-6d%-10s%-8d%-20s%-15s\n",p->num,p->name,p->sex,p->age,p->edu,p->salary,p->address,p->phone);break;
			 }
			p=p->next;
		}
        if(count==0) printf("not find!\n");
        else   		printf("find\n找到%d个！\n",count);
        system("pause");
    } 
    
    void change(struct worker *h)  /*修改*/
    {
	 	int i;
 	 	void change1(struct worker *h);
		void change2(struct worker *h);
		if(h->next==NULL) {printf("链表为空！\n");system("pause");return;}
		while(1)
	  {	
			system("cls");
  	   printf("\t\t********************************\n");
       printf("\t\t**     1职工号修改            **\n");
	   printf("\t\t**     2姓名修改              **\n");
	   printf("\t\t**     0返回上一级            **\n");
	   printf("\t\t********************************\n\n\n");
	   printf("请选择:");
	   scanf("%d",&i);
	   switch(i)
	   {
	   		case 0:return;
	   	  	case 1:change1(h);break;
	  		case 2:change2(h);break;
  			default:printf("输入错误！\n");break;
      	}
	  }
	   
 	} 
	void change1(struct worker *h)  /*职工号修改*/
	{
		char num0[4],num1[4];
		struct worker *p;
		p=h->next;
		getchar();
		printf("输入需要修改的职工号:");
	    gets(num0);
		while(p)
		{
			if(strcmp(p->num,num0)==0)break;
			p=p->next;
		}
		if(p)
		{
			printf("输入修改后的职工号:");
	    	gets(num1);
	    	strcpy(p->num,num1);
		}
	    else printf("not find！\n"); 
	}
 	
	void change2(struct worker *h)  /*姓名修改*/
	{
		int count=0;
		char name0[10],name1[10];
		struct worker *p;
		p=h->next;
		getchar();
		printf("输入需要修改的姓名:");
	    gets(name0);
		while(p)
		{
			if(strcmp(p->name,name0)==0)
			{count++;
			printf("输入修改后的姓名:");
	    	gets(name1);
			strcpy(p->name,name1);}
			p=p->next;
		}
		
	    if(count==0)printf("not find！\n"); 
		else printf("修改了%d次！\n",count);
		system("pause"); 
	}
    
