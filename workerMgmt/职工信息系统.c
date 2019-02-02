#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct worker
{
	char num[4];  /*ְ����*/
	char name[10]; /*����*/
	char sex;
	int age;
	char edu[10];/*ѧ��*/
	int salary;
	char address[20];
	char phone[12];
	struct worker *next;
};

#define LEN sizeof(struct worker)
void input(struct worker *h);   /*����*/
void output(struct worker *h); 
void eight(struct worker *h); 
void seven(struct worker *h);
void add(struct worker *h);   
void fdelete(struct worker *h);
void search(struct worker *h);
void change(struct worker *h);
main()                            /*������*/
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
		printf("\t\t*       ְ����Ϣ����ϵͳ       *\n");
		printf("\t\t********************************\n");
		printf("\t\t*         1��ʼ������          *\n");
		printf("\t\t*         2��������            *\n");
		printf("\t\t*         3�޸�����            *\n");
		printf("\t\t*         4ɾ������            *\n");
		printf("\t\t*         5��������            *\n");
		printf("\t\t*         6�������            *\n");
		printf("\t\t*         7��������            *\n");
		printf("\t\t*         8��������            *\n");
		printf("\t\t*         0�˳�ϵͳ            *\n");
		printf("\t\t********************************\n");
	
		printf("%5s��ѡ������Ҫ�Ĺ���(0~8):\n"," ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				{	if(head->next!=NULL) 
					{printf("�Ƿ���Ҫ�����ݵ����ļ�?(y)\n");
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
			default:printf("��������");break;
		}

	}
}

  void input(struct worker *h)   /*1��ʼ��*/
	{
		int i,n;
		struct worker *p,*q;
		p=h;
		if(h->next) 
			{
				printf("�ǿգ����ܽ��г�ʼ����\n");
				system("pause");
				return;
			}
		printf("������");	scanf("%d",&n);
		getchar();
		for(i=0;i<n;i++)
		{
			q=(struct worker *)malloc(LEN);
			system("cls");
	   		printf("ְ����:");     gets(q->num);
		 	printf("����:");       gets(q->name);
	 	 	printf("�Ա�:");       q->sex=getchar();
	  		printf("����:");   	   scanf("%d",&q->age);
	     	getchar();      	   
		 	printf("ѧ��:");       gets(q->edu);
		  	printf("����:");	    scanf("%d",&q->salary);
 		  	getchar();
		 	printf("��ַ:");		gets(q->address);
		  	printf("�绰����:");	gets(q->phone);
			p->next=q;                                                                                                
			q->next=NULL;
			p=q;
		}
	}


 

    void output(struct worker *h)  /*6���*/
	{
		struct worker *p;
		p=h->next;
		if(h->next==NULL) {printf("����Ϊ�գ�\n");system("pause");return;}
		system("cls");
		printf("%-8s%-10s%-6s%-6s%-10s%-8s%-20s%-15s\n","ְ����","����","�Ա�","����","ѧ��","����","��ͥ��ַ","�绰����");
		while(p!=NULL)
		{ 
			printf("%-8s%-10s%-6c%-6d%-10s%-8d%-20s%-15s\n",p->num,p->name,p->sex,p->age,p->edu,p->salary,p->address,p->phone);
			p=p->next;
		}
	system("pause");
	}
	



    void eight(struct worker *h)     /*8����*/
    {
		struct worker *p;
		FILE *fp;
		if(h->next==NULL) {printf("����Ϊ�գ�����Ҫ��������!\n");system("pause");return;}
		fp=fopen("f1.dat","wb");
		if(fp==NULL)
		{ 
			printf("�ļ���ʧ��!\n");
			exit(0);
		}
		p=h->next;
        while(p)
        {
			fwrite(p,LEN,1,fp);
			p=p->next;
		}
		
		fclose(fp);
		printf("�����ɹ�!\n");
		system("pause");
	}
void seven(struct worker *h)     /*7����*/
    {
	    char ch;
		struct worker *p,*q;
		FILE *fp;
		if(h->next!=NULL) 
			{
				printf("�����������ݣ��������ݺ�ԭ�����е����ݽ���ʧ!\n�Ƿ�����������ݣ�(��-y)\n");
				system("pause");
				fflush(stdin);
				scanf("%c",&ch);
				if(ch!='y'&&ch!='Y') return;
			}
		
			fp=fopen("f1.dat","rb");
			if(fp==NULL)
			{ 
				printf("�ļ���ʧ��!\n");
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
			printf("����ɹ�!\n");
			system("pause");
		
	}

   void add(struct worker *h)      /*2��������*/
   {
	   int i,m=1;
	   char ch;
	   void myadd1(struct worker *h);
       void myadd2(struct worker *h);
       if(h->next==NULL) {printf("����Ϊ�գ�����г�ʼ����\n\n");system("pause");return;}
	   while(1)
	   {
			system("cls");
			printf("\n\n");
			printf("\t\t********************************\n");
			printf("\t\t**     1��ָ��ְ����֮��      **\n");
			printf("\t\t**     2��ָ��ְ����֮ǰ      **\n");
			printf("\t\t**     0������һ��            **\n");
			printf("\t\t********************************\n\n\n");
			printf("��ѡ��:");scanf("%d",&i);
			switch(i)
			 { 
				case 0:return;
				case 1:	myadd1(h);break;
				case 2:	myadd2(h);break;
				default:{printf("�������\n");system("pause");break;}
			 }
			printf("�Ƿ����׷�����ݣ�(Y?)\n");scanf("%c",&ch);
			getchar();
			if(ch=='y'||ch=='Y') m=1;
			else return;

	   }
   }
		


    void myadd1(struct worker *h)      /*2�������ݣ���ָ��ְ����λ��֮�����*/
	{
		char num0[4];
		struct worker *p,*r;
		getchar();
		printf("����ְ����֮��:");
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
		else {printf("δ�ҵ���ְ���ţ�\n");return;}
		printf("������Ա��Ϣ:\n");
		 printf("ְ����:");  gets(r->num);
		 printf("����:");    gets(r->name);
		 printf("�Ա�:");    r->sex=getchar();
		 printf("����:");    scanf("%d",&r->age);
	     getchar();
		 printf("ѧ��:");   gets(r->edu);
		 printf("����:");   scanf("%d",&r->salary);
	     getchar();
		 printf("��ַ:");     gets(r->address);
		 printf("�绰����:");  gets(r->phone);

	}

	void myadd2(struct worker *h)      /*2�������ݣ���ָ��ְ����λ��֮ǰ���*/
	{
		char num0[4];
		struct worker *p,*q,*r;
		getchar();
		printf("����ְ����֮ǰ:");
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
		else {printf("δ�ҵ���ְ���ţ�\n");return;}
		printf("������Ա��Ϣ:\n");
	 	printf("ְ����:");  gets(r->num);
		printf("����:");    gets(r->name);
		printf("�Ա�:");    r->sex=getchar();
		printf("����:");    scanf("%d",&r->age);
	    getchar();
		printf("ѧ��:");   gets(r->edu);
		printf("����:");   scanf("%d",&r->salary);
	    getchar();
		printf("��ַ:");     gets(r->address);
		printf("�绰����:");  gets(r->phone);

	}


	void fdelete(struct worker *h)     /*4ɾ��*/
	{
		int i,m=1;char ch;
		void delete1(struct worker *h);
     	void delete2(struct worker *h);
		if(h->next==NULL) {printf("����Ϊ��,����ɾ����\n");system("pause");return;}
		
	  while(m)
	  {
	  	system("cls");
	  	printf("\n\n");
		printf("\t\t********************************\n");
		printf("\t\t**     1��ְ����ɾ��          **\n");
		printf("\t\t**     2������ɾ��            **\n");
		printf("\t\t**     0������һ��            **\n");
		printf("\t\t********************************\n\n\n");
		printf("��ѡ��:");
		scanf("%d",&i);
		switch(i)
		{
			 case 0:return;break;
			 case 1:delete1(h);break;
			 case 2:delete2(h);break;
			 default:printf("��������!\n");break;
		} 
			printf("�Ƿ����׷�����ݣ�(Y?)\n");scanf("%c",&ch);
			getchar();
			if(ch=='y'||ch=='Y') m=1;
			else return;
	  }
	}
	
    void delete1(struct worker *h)     /*4��ְ����ɾ��*/
    {
		char num0[4];
    	struct worker *p,*q;
    	p=h;q=h->next;
		getchar();
		printf("����ɾ����ְ����:");
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
    
    void delete2(struct worker *h)     /*4������ɾ��*/
    {
    	int count=0;
		char name0[10];
    	struct worker *p,*q;
		getchar();
		printf("����ɾ��������:");
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
        else   		printf("find\n%d����\n",count);
        system("pause");
    } 
    
    
   	void search(struct worker *h)     /*5����*/
	{
		int i,m=1;char ch;
		void search1(struct worker *h);
   	    void search2(struct worker *h);
		if(h->next==NULL) {printf("����Ϊ�գ�����ɾ����\n");system("pause");return;}
		while(1)
		{
				system("cls");
				printf("\n\n\n");
				printf("\t\t********************************\n");
				printf("\t\t**     1��ְ���Ų���          **\n");
				printf("\t\t**     2����������            **\n");
				printf("\t\t**     0������һ��            **\n");
				printf("\t\t********************************\n\n\n");
				printf("��ѡ��:");
				scanf("%d",&i);
				switch(i)
				{
					case 0:return;
					case 1:search1(h);break;
					case 2:search2(h);break;
					default:printf("��������");break;
				}
					printf("�Ƿ����׷�����ݣ�(Y?)\n");
			ch=getchar();
			if(ch=='y'||ch=='Y') m=1;
			else return;
		}
	}
	
	void search1(struct worker *h) /*��ְ���Ų���*/
	{
		char num0[4];
		struct worker *p;
		p=h->next;
		getchar();                            /*!!!!!!!!!!!!!!*/
		printf("����Ҫ���ҵ�ְ���ţ�");
		gets(num0);
		printf("%-8s%-10s%-6s%-6s%-10s%-8s%-20s%-15s\n","ְ����","����","�Ա�","����","ѧ��","����","��ͥ��ַ","�绰����");
		while(p)
		{
			if(strcmp(p->num,num0)==0)
				   printf("%-8s%-10s%-6c%-6d%-10s%-8d%-20s%-15s\n",p->num,p->name,p->sex,p->age,p->edu,p->salary,p->address,p->phone);break;
			p=p->next;
		}
		if(p==NULL) printf("not find!\n");
		system("pause");
	} 
	
	 void search2(struct worker *h)     /*����������*/
    {
    	int count=0;
    	char name[10];
   		struct worker *p;
		p=h->next;
		fflush(stdin);                            /*!!!!!!!!!!!!!!*/
		printf("����Ҫ���ҵ�������");
		gets(name);
		printf("\n\n%-8s%-10s%-6s%-6s%-10s%-8s%-20s%-15s\n","ְ����","����","�Ա�","����","ѧ��","����","��ͥ��ַ","�绰����");
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
        else   		printf("find\n�ҵ�%d����\n",count);
        system("pause");
    } 
    
    void change(struct worker *h)  /*�޸�*/
    {
	 	int i;
 	 	void change1(struct worker *h);
		void change2(struct worker *h);
		if(h->next==NULL) {printf("����Ϊ�գ�\n");system("pause");return;}
		while(1)
	  {	
			system("cls");
  	   printf("\t\t********************************\n");
       printf("\t\t**     1ְ�����޸�            **\n");
	   printf("\t\t**     2�����޸�              **\n");
	   printf("\t\t**     0������һ��            **\n");
	   printf("\t\t********************************\n\n\n");
	   printf("��ѡ��:");
	   scanf("%d",&i);
	   switch(i)
	   {
	   		case 0:return;
	   	  	case 1:change1(h);break;
	  		case 2:change2(h);break;
  			default:printf("�������\n");break;
      	}
	  }
	   
 	} 
	void change1(struct worker *h)  /*ְ�����޸�*/
	{
		char num0[4],num1[4];
		struct worker *p;
		p=h->next;
		getchar();
		printf("������Ҫ�޸ĵ�ְ����:");
	    gets(num0);
		while(p)
		{
			if(strcmp(p->num,num0)==0)break;
			p=p->next;
		}
		if(p)
		{
			printf("�����޸ĺ��ְ����:");
	    	gets(num1);
	    	strcpy(p->num,num1);
		}
	    else printf("not find��\n"); 
	}
 	
	void change2(struct worker *h)  /*�����޸�*/
	{
		int count=0;
		char name0[10],name1[10];
		struct worker *p;
		p=h->next;
		getchar();
		printf("������Ҫ�޸ĵ�����:");
	    gets(name0);
		while(p)
		{
			if(strcmp(p->name,name0)==0)
			{count++;
			printf("�����޸ĺ������:");
	    	gets(name1);
			strcpy(p->name,name1);}
			p=p->next;
		}
		
	    if(count==0)printf("not find��\n"); 
		else printf("�޸���%d�Σ�\n",count);
		system("pause"); 
	}
    
