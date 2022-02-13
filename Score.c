/*
问题描述：
对学生成绩进行管理，学生信息包括：学号、姓名、班级、课程1、课程2、课程3、课程4、学期。
基本要求
(1)	能按学期、按班级完成对学生成绩的录入、修改；
(2)	能按班级统计学生的成绩，求学生的总分及平均分，并能根据学生的平均成绩进行排序；
(3)	能查询学生成绩，不及格科目及学生名单；
(4)	能按班级输出学生的成绩单。
*/
 
#include<stdio.h>
#include<stdlib.h> 
#include<string.h> 
 
typedef struct//学号，姓名，班级，课程1，课程2，课程3，课程4，学期。
{
	char num[20];
	char name[20];
	int cla;
	int c1;
	int c2;
	int c3;
	int c4;
	int term; 
	float aver;
	int sum; 
}Student; 
Student stu[80];
 
int in(Student a[],int n);//输入学生信息 
int chick(Student st[],int n);//查看函数 
int clasort(Student st[],int n);//按班级排序 
int change(Student st[],int n);//修改学生成绩 
int aversort(Student st[],int n);//平均分排序 
int find(Student st[],int n);//查询学生成绩 
int unlow(Student st[],int n);//不及格学生
void file(Student st[],int n);//保存到文件 
 
int main()//主函数 
{
	int n=0;
	for(;;)
	{
	printf("		1.录入学生成绩\n");
	printf("		2.修改学生成绩\n");
	printf("		3.查看学生成绩\n");
	printf("		4.平均分排序\n");
	printf("		5.查询学生成绩\n");
	printf("		6.不及格学生\n");
	printf("		7.输出成绩单\n");
	printf("		8.结束程序\n");
	int a=0;
	scanf("%d",&a);
	switch(a)
	{ 
		case 1:
			n=in(stu,n);
			break;
		case 2:
			change(stu,n);
			break;
		case 3:
			chick(stu,n);
			break;
		case 4:
			aversort(stu,n);
			break;
		case 5:
			find(stu,n);
			break;
		case 6:
			unlow(stu,n);
			break;
		case 7:
			file(stu,n);
			break;
		case 8:
			system("pause");
			exit(0);
			break;
		default:
			printf("选择错误\n") ;
			break;
	}
	system("pause"); 
	system("cls"); 
	}
	return 0;
}
 
 
int in(Student st[],int n)//学生信息录入功能 
{
	
int i=0; 
int a=1,b,c,d;
printf("按学期输入请按1，按班级输入请按2\n");
scanf("%d",&b); 
if(b==1&&a==1)
{ 
printf("请输入学期:");
scanf("%d",&c);
while(a==1)
{ 
printf("\t学生学号 :");
scanf("\t%s",st[n+i].num);
printf("\t学生姓名 :"); 
scanf("\t%s",st[n+i].name); 
printf("\t学生班级 :"); 
scanf("\t%d",&st[n+i].cla); 
printf("\t学生科目1:"); 
scanf("\t%d",&st[n+i].c1); 
printf("\t学生科目2:"); 
scanf("\t%d",&st[n+i].c2);
printf("\t学生科目3:"); 
scanf("\t%d",&st[n+i].c3);
printf("\t学生科目4:"); 
scanf("\t%d",&st[n+i].c4);
st[n+i].term=c;
st[n+i].sum=st[n+i].c1+st[n+i].c2+st[n+i].c3+st[n+i].c4;
st[n+i].aver=st[n+i].sum/4;
printf("继续输入请按1\n 结束输入请按2\n"); 
scanf("%d",&a);
i++;
}
}
 
if(b==2&&a==1)
{
printf("请输入班级:");
scanf("%d",&d);
while(a==1)
{ 
printf("\t学生学号 :");
scanf("\t%s",st[n+i].num);
printf("\t学生姓名 :"); 
scanf("\t%s",st[n+i].name); 
printf("\t学生科目1:"); 
scanf("\t%d",&st[n+i].c1); 
printf("\t学生科目2:"); 
scanf("\t%d",&st[n+i].c2);
printf("\t学生科目3:"); 
scanf("\t%d",&st[n+i].c3);
printf("\t学生科目4:"); 
scanf("\t%d",&st[n+i].c4);
printf("\t学期:"); 
scanf("\t%d",&st[n+i].term);
st[n+i].cla=c;
st[n+i].sum=st[n+i].c1+st[n+i].c2+st[n+i].c3+st[n+i].c4;
st[n+i].aver=st[n+i].sum/4;
printf("继续输入请按1\n 结束输入请按2\n"); 
scanf("%d",&a);
i++;
}
 
}
return(n+i); 
} 
 
 
int clasort(Student st[],int n)//排序判断后忘记交换判断条件 
{
int i,j,s,u;
float v; 
char t[10];
 
for(i=0;i<n-1;i++) /*冒泡法排序*/ 
for(j=0;j<n-1-i;j++) 
if(st[j].cla>st[j+1].cla) 
{
strcpy(t,st[j+1].num); 
strcpy(st[j+1].num,st[j].num); 
strcpy(st[j].num,t); //学号 
 
strcpy(t,st[j+1].name); 
strcpy(st[j+1].name,st[j].name); 
strcpy(st[j].name,t); //姓名 
 
u=st[j+1].cla;
st[j+1].cla=st[j].cla;
st[j].cla=u;
 
u=st[j+1].c1;
st[j+1].c1=st[j].c1;
st[j].c1=u;
 
u=st[j+1].c2;
st[j+1].c2=st[j].c2;
st[j].c2=u;
 
u=st[j+1].c3;
st[j+1].c3=st[j].c3;
st[j].c3=u;
 
u=st[j+1].c4;
st[j+1].c4=st[j].c4;
st[j].c4=u;
 
u=st[j+1].term;
st[j+1].term=st[j].term;
st[j].term=u;
 
u=st[j+1].sum;
st[j+1].sum=st[j].sum;
st[j].sum=u;
 
v=st[j+1].aver;
st[j+1].aver=st[j].aver;
st[j].aver=v;
}
}
 
 
int chick(Student st[],int n)//查看学生信息 
{
	int c,i=0,u;
	printf("全部学生成绩请按1\n某班级学生成绩请按2\n");
	scanf("%d",&c);
	switch(c)
	{ 
	case 1:
		clasort(st, n);
		printf("班级	  学号		 姓名		学期	科目一	科目二	科目三	科目四	总成绩	平均分\n");
			for(i=0;i<n;i++)
			{
				printf("%2d	%-15s	%-15s	%d	%d	%d	%d	%d	%d	%f\n",st[i].cla,st[i].num,st[i].name,st[i].term,st[i].c1,st[i].c2,st[i].c3,st[i].c4,st[i].sum,st[i].aver); 
			} 
	break;
	case 2:
	
		printf("请输入要查询的班级\n");
		scanf("%d",&u); 
	while((st[i].cla!=u)&&i<n) i++; //查找
	if(i==n) 
	{ 
	printf("\t\t\t没有找到!\n"); //失败
	return(n); 
	}
	
	printf("班级	  学号		 姓名		学期	科目一	科目二	科目三	科目四	总成绩	平均分\n");
	for(i=0;i<n;i++)
	if(st[i].cla==u)
		{
			printf("%2d	%-15s	%-15s	%d	%d	%d	%d	%d	%d	%f\n",st[i].cla,st[i].num,st[i].name,st[i].term,st[i].c1,st[i].c2,st[i].c3,st[i].c4,st[i].sum,st[i].aver); 
		} 
	
	}
}
 
 
int change(Student st[],int n)//修改学生成绩 
{
	char s[20];
	int c; 
	int i=0,j; 
	printf("请输入要修改学生的学号\n");
	scanf("%s",s); 
	while((strcmp(st[i].num,s)!=0)&&i<n) i++; //查找
	if(i==n) 
	{ 
		printf("\t\t\t没有找到!\n"); //失败
		return(n); 
	}
 
printf("\t学生科目1:"); 
scanf("\t%d",&c); 
st[i].c1=c;
printf("\t学生科目2:"); 
scanf("\t%d",&c);
st[i].c2=c;
printf("\t学生科目3:"); 
scanf("\t%d",&c);
st[i].c3=c;
printf("\t学生科目4:"); 
scanf("\t%d",&c);
st[i].c4=c;
printf("\t学期:"); 
scanf("\t%d",&c);
st[i].term=c;
st[i].sum=st[i].c1+st[i].c2+st[i].c3+st[i].c4;
st[i].aver=st[i].sum/4;
}
 
 
int aversort(Student st[],int n)//平均分排序 
{
int i,j,s,u,c;
float v; 
char t[10];
 
for(i=0;i<n-1;i++) /*冒泡法排序*/ 
for(j=0;j<n-1-i;j++) 
if(st[j].aver<st[j+1].aver) 
{
strcpy(t,st[j+1].num); 
strcpy(st[j+1].num,st[j].num); 
strcpy(st[j].num,t); //学号 
 
strcpy(t,st[j+1].name); 
strcpy(st[j+1].name,st[j].name); 
strcpy(st[j].name,t); //姓名 
 
u=st[j+1].cla;
st[j+1].cla=st[j].cla;
st[j].cla=u;
 
u=st[j+1].c1;
st[j+1].c1=st[j].c1;
st[j].c1=u;
 
u=st[j+1].c2;
st[j+1].c2=st[j].c2;
st[j].c2=u;
 
u=st[j+1].c3;
st[j+1].c3=st[j].c3;
st[j].c3=u;
 
u=st[j+1].c4;
st[j+1].c4=st[j].c4;
st[j].c4=u;
 
u=st[j+1].term;
st[j+1].term=st[j].term;
st[j].term=u;
 
u=st[j+1].sum;
st[j+1].sum=st[j].sum;
st[j].sum=u;
 
v=st[j+1].aver;
st[j+1].aver=st[j].aver;
st[j].aver=v;
}
 
printf("全部学生成绩请按1\n某班级学生成绩请按2\n");
	scanf("%d",&c);
	switch(c)
	{ 
	case 1:
	printf("班级	  学号		 姓名		学期	科目一	科目二	科目三	科目四	总成绩	平均分\n");
			for(i=0;i<n;i++)
			{
				printf("%2d	%-15s	%-15s	%d	%d	%d	%d	%d	%d	%f\n",st[i].cla,st[i].num,st[i].name,st[i].term,st[i].c1,st[i].c2,st[i].c3,st[i].c4,st[i].sum,st[i].aver); 
			} 
	break;
	case 2:
		printf("请输入要查询的班级\n");
		scanf("%d",&u); 
	while((st[i].cla!=u)&&i<n) i++; //查找
	if(i==n) 
	{ 
	printf("\t\t\t没有找到!\n"); //失败
	return(n); 
	}
	
	printf("班级	  学号		 姓名		学期	科目一	科目二	科目三	科目四	总成绩	平均分\n");
	for(i=0;i<n;i++)
	if(st[i].cla==u)
		{
			printf("%2d	%-15s	%-15s	%d	%d	%d	%d	%d	%d	%f\n",st[i].cla,st[i].num,st[i].name,st[i].term,st[i].c1,st[i].c2,st[i].c3,st[i].c4,st[i].sum,st[i].aver); 
		} 
	}
}
 
 
int find(Student st[],int n)//查寻学生成绩 
{
char s[20],c; 
	int i=0,j; 
	printf("请输入要查询学生的学号\n");
	scanf("%s",s); 
	while((strcmp(st[i].num,s)!=0)&&i<n) i++; //查找
	if(i==n) 
	{ 
		printf("\t\t\t没有找到!\n"); //失败
		return(n); 
	} 
	printf("班级	  学号		 姓名		学期	科目一	科目二	科目三	科目四	总成绩	平均分\n");
	printf("%2d	%-15s	%-15s	%d	%d	%d	%d	%d	%d	%f\n",st[i].cla,st[i].num,st[i].name,st[i].term,st[i].c1,st[i].c2,st[i].c3,st[i].c4,st[i].sum,st[i].aver); 
} 
 
 
int unlow(Student st[],int n)//不及格学生
{
	int i;
	int a;
	for(i=0;i<=n;i++) 
	{
		if(st[i].c1<60||st[i].c2<60||st[i].c3<60||st[i].c4<60)
		a=0;
		else 
		a=1;
		
	}
	if(a==1) printf("无不及格学生"); 
	if(a==0)
	{
		printf("班级	学号	姓名		不及格科目\n");
		for(i=0;i<=n;i++)
		{
		if(st[i].c1<60&&st[i].c2>60&&st[i].c3>60&&st[i].c4>60)	printf("%d	%s	%s		c1\n",st[i].cla,st[i].num,st[i].name);
		if(st[i].c1>60&&st[i].c2<60&&st[i].c3>60&&st[i].c4>60)	printf("%d	%s	%s		c2\n",st[i].cla,st[i].num,st[i].name); 
		if(st[i].c1>60&&st[i].c2>60&&st[i].c3<60&&st[i].c4>60)	printf("%d	%s	%s		c3\n",st[i].cla,st[i].num,st[i].name);
		if(st[i].c1>60&&st[i].c2>60&&st[i].c3>60&&st[i].c4<60)	printf("%d	%s	%s		c4\n",st[i].cla,st[i].num,st[i].name);
		if(st[i].c1<60&&st[i].c2<60&&st[i].c3>60&&st[i].c4>60)	printf("%d	%s	%s		c1   c2\n",st[i].cla,st[i].num,st[i].name);
		if(st[i].c1<60&&st[i].c2>60&&st[i].c3<60&&st[i].c4>60)	printf("%d	%s	%s		c1   c3\n",st[i].cla,st[i].num,st[i].name);
		if(st[i].c1<60&&st[i].c2>60&&st[i].c3>60&&st[i].c4<60)	printf("%d	%s	%s		c1   c4\n",st[i].cla,st[i].num,st[i].name);
		if(st[i].c1>60&&st[i].c2<60&&st[i].c3<60&&st[i].c4>60)	printf("%d	%s	%s		c2   c3\n",st[i].cla,st[i].num,st[i].name);
		if(st[i].c1>60&&st[i].c2<60&&st[i].c3>60&&st[i].c4<60)	printf("%d	%s	%s		c2   c4\n",st[i].cla,st[i].num,st[i].name);
		if(st[i].c1>60&&st[i].c2>60&&st[i].c3<60&&st[i].c4<60)	printf("%d	%s	%s		c3   c4\n",st[i].cla,st[i].num,st[i].name);
		if(st[i].c1<60&&st[i].c2<60&&st[i].c3<60&&st[i].c4>60)	printf("%d	%s	%s		c1	c2  c3\n",st[i].cla,st[i].num,st[i].name);
		if(st[i].c1<60&&st[i].c2<60&&st[i].c3>60&&st[i].c4<60)	printf("%d	%s	%s		c1	c2  c4\n",st[i].cla,st[i].num,st[i].name);
		if(st[i].c1<60&&st[i].c2>60&&st[i].c3<60&&st[i].c4<60)	printf("%d	%s	%s		c1	c3  c4\n",st[i].cla,st[i].num,st[i].name);
		if(st[i].c1>60&&st[i].c2<60&&st[i].c3<60&&st[i].c4<60)	printf("%d	%s	%s		c2	c3  c4\n",st[i].cla,st[i].num,st[i].name);	
		}
	
	}
 
}
 
 
 
 
void file(Student st[],int n)
 {
int i=0; 
FILE *fp;
int c,u;
	printf("全部学生成绩请按1\n某班级学生成绩请按2\n");
	scanf("%d",&c);
	switch(c)
	{ 
	case 1:
		clasort(st, n);
		fprintf(fp,"班级	  学号		 姓名		学期	科目一	科目二	科目三	科目四	总成绩	平均分\n");
			for(i=0;i<n;i++)
			{
				fprintf(fp,"%2d	%-15s	%-15s	%d	%d	%d	%d	%d	%d	%f\n",st[i].cla,st[i].num,st[i].name,st[i].term,st[i].c1,st[i].c2,st[i].c3,st[i].c4,st[i].sum,st[i].aver); 
			} 
	break;
	case 2:
	
		printf("请输入要保存的班级\n");
		scanf("%d",&u); 
	while((st[i].cla!=u)&&i<n) i++; //查找
	if(i==n) 
	{ 
	printf("\t\t\t没有找到!\n"); //失败
	return; 
	}
	
	fprintf(fp,"班级	  学号		 姓名		学期	科目一	科目二	科目三	科目四	总成绩	平均分\n");
	for(i=0;i<n;i++)
	if(st[i].cla==u)
		{
			fprintf(fp,"%2d	%-15s	%-15s	%d	%d	%d	%d	%d	%d	%f\n",st[i].cla,st[i].num,st[i].name,st[i].term,st[i].c1,st[i].c2,st[i].c3,st[i].c4,st[i].sum,st[i].aver); 
		} 
	
	}
fclose(fp); 
printf("保存完毕!\n"); 
} 
 
 
 