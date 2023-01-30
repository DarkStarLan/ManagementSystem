//#pragma warning(disable:4996)
//#pragma warning(disable:6031)

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
//课程类
struct Class {
	//成员
	char id[100];			//编号
	char name[100];			//名称
	char property[100];		//性质
	int period_all;			//总学时
	int period_show;		//授课学时
	int period_use;			//实验或上机学时
	int start_time;			//开课学期
	int score;				//学分
};
struct Class* CS[1000] = { NULL };  //课程
struct Class* MY[1000] = { NULL };  //我的
int cs, my;  //个数
//构造函数
void initClass(struct Class* c, char* Id, char* Name, char* Property,
	int p_a, int p_s, int p_u, int start_t, int s) {
	strcpy(c->id, Id);
	strcpy(c->name, Name);
	strcpy(c->property, Property);
	c->period_all = p_a;
	c->period_show = p_s;
	c->period_use = p_u;
	c->start_time = start_t;
	c->score = s;
}
//输入一个课程
void getClass(struct Class* C) {
	while (getchar() != '\n');
	char id[100] = { 0 };			//编号
	char name[100] = { 0 };			//名称
	char property[100] = { 0 };		//性质
	int period_all;					//总学时
	int period_show;				//授课学时
	int period_use;					//实验或上机学时
	int start_time;					//开课学期
	int score;						//学分
	printf("输入编号");
	scanf("%s", id);
	printf("输入名称");
	scanf("%s", name);
	printf("输入性质");
	scanf("%s", property);
	printf("输入总学时");
	scanf("%d", &period_all);
	printf("输入授课学时");
	scanf("%d", &period_show);
	printf("输入实验或上机学时");
	scanf("%d", &period_use);
	printf("输入开课学期");
	scanf("%d", &start_time);
	printf("输入学分");
	scanf("%d", &score);
	strcpy(C->id, id);
	strcpy(C->name, name);
	strcpy(C->property, property);
	C->period_all = period_all;
	C->period_show = period_show;
	C->period_use = period_use;
	C->score = score;
	C->start_time = start_time;
}
//打印课程信息
void printClass(struct Class* c) {
	printf("%s\t%s\t%s\t%d\t%d\t\t%d\t\t%d\t\t%d\n", c->id, c->name, c->property, c->period_all, c->period_show, c->period_use, c->start_time, c->score);
}
//函数声明
void show();
void save();
void addClass();
void readFile();
void FreeData();
void lookClass();
void searchClass();
void deleteClass();
void resetClass();
void initProgram();
void takeClass();
void lookTakedClass();
void dropClass();
void alert();
//主函数
int main(void) {
	//初始化
	initProgram();
	readFile();  //读取数据
	//printf("%d %d\n", cs, my);  //数量
	char ch = '\0';
	for (;;) {
		show();
		scanf("%c", &ch);
		switch (ch) {
		case '1':
			addClass();
			break;
		case '2':
			lookClass();
			system("pause");
			system("cls");
			break;
		case '3':
			searchClass();
			break;
		case '4':
			deleteClass();
			break;
		case '5':
			resetClass();
			break;
		case '6':
			takeClass();
			break;
		case '7':
			lookTakedClass();
			system("pause");
			system("cls");
			break;
		case '8':
			dropClass();
			break;
		case '9':
			alert();
			break;
		case '0':
			system("pause");
			FreeData();
			return 0;
			break;
		default:
			printf("输入有误, 请重新输入!\n");
			system("pause");
			system("cls");
			break;
		}
		while (getchar() != '\n');
	}
	FreeData();
	return 0;
}
//主页面
void show() {
	printf("-------------\n");
	printf("======A======\n");
	printf("1.课程信息录入\n");
	printf("2.课程信息浏览\n");
	printf("3.课程信息查询\n");
	printf("4.课程信息删除\n");
	printf("5.课程信息修改\n");
	printf("======B======\n");
	printf("6.选修课程\n");
	printf("7.选课信息\n");
	printf("8.退选课程\n");
	printf("9.预警查询\n");
	printf("-------------\n");
	printf("0.退出\n\n");
	printf("输入选择:");
}
//课程信息录入
void addClass() {
	system("cls");
	struct Class* c = ((struct Class*)malloc(sizeof(struct Class)));
	getClass(c);
	if (c == NULL) {
		printf("数据出错!\n");
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < cs; ++i) {
		if (strcmp(CS[i]->id, c->id) == 0) {
			printf("编号重复!\n添加失败!\n");
			free(c);
			system("pause");
			system("cls");
			return;
		}
	}
	CS[cs++] = c;
	printf("添加完毕!\n");
	system("pause");
	system("cls");
}
//课程信息浏览
void lookClass() {
	system("cls");
	printf("课程信息浏览\n");
	printf("编号\t名称\t性质\t总学时\t授课学时\t实验或上机学时\t开课学期\t学分\n");
	for (int i = 0; i < cs; ++i) {
		printClass(CS[i]);
	}
}
//课程信息查询
void searchClass() {
	system("cls");
	printf("输入查询模式:\n1.按学分查询\n2.按课程性质查询\n");
	while (getchar() != '\n');
	char ch = '\0';
	do {
		printf("请输入正确的数字:");
		scanf("%c", &ch);
	}
	while (ch != '1' && ch != '2');
	if (ch == '1') {
		system("cls");
		printf("按学分查询\n");
		int s = 0;
		scanf("%d", &s);
		printf("编号\t名称\t性质\t总学时\t授课学时\t实验或上机学时\t开课学期\t学分\n");
		for (int i = 0; i < cs; ++i) {
			if (CS[i]->score == s) printClass(CS[i]);
		}
	}
	else {
		system("cls");
		printf("按课程性质查询\n");
		char s[100] = { 0 };
		scanf("%s", &s);
		printf("编号\t名称\t性质\t总学时\t授课学时\t实验或上机学时\t开课学期\t学分\n");
		for (int i = 0; i < cs; ++i) {
			if (strcmp(CS[i]->property, s) == 0) printClass(CS[i]);
		}
	}
	system("pause");
	system("cls");
}
//课程信息删除
void deleteClass() {
	system("cls");
	lookClass();
	printf("课程信息删除\n请输入需要删除的课程的编号:\n");
	char id[100] = {0};
	int index = 0, flag = 0;
	scanf("%s", id);
	printf("删除以下课程:\n编号\t名称\t性质\t总学时\t授课学时\t实验或上机学时\t开课学期\t学分\n");
	for (; index < cs; ++index) {
		if (strcmp(CS[index]->id, id) == 0) {
			printClass(CS[index]);
			flag = 1;
			break;
		}
	}
	if (!flag) printf("未找到!");
	else {
		//删除课程
		for (int i = cs - 1; i > index; --i) CS[i] = CS[i - 1];
		printf("删除完成!\n");
		--cs;
	}
	system("pause");
	system("cls");
}
//课程信息修改
void resetClass() {
	system("cls");
	lookClass();
	printf("课程信息修改\n请输入需要修改的课程的编号:\n");
	char id[100] = { 0 };
	int index = 0, flag = 0;
	scanf("%s", id);
	printf("被修改的课程如下:\n编号\t名称\t性质\t总学时\t授课学时\t实验或上机学时\t开课学期\t学分\n");
	for (; index < cs; ++index) {
		if (strcmp(CS[index]->id, id) == 0) {
			printClass(CS[index]);
			flag = 1;
			break;
		}
	}
	if (!flag) {
		printf("未找到!\n");
		system("pause");
		system("cls");
		return;
	}
	//找到了
	free(CS[index]);
	struct Class* newC = ((struct Class*)malloc(sizeof(struct Class)));
	getClass(newC);
	CS[index] = newC;
	printf("修改完成!\n");
	system("pause");
	system("cls");
}
//学生选修课程
void takeClass() {
	lookClass();
	printf("课程选修\n请输入需要选修的课程的编号:\n");
	char id[100] = { 0 };
	int index = 0, flag = 0;
	scanf("%s", id);
	printf("选修以下课程:\n编号\t名称\t性质\t总学时\t授课学时\t实验或上机学时\t开课学期\t学分\n");
	for (; index < cs; ++index) {
		if (strcmp(CS[index]->id, id) == 0) {
			printClass(CS[index]);
			flag = 1;
			break;
		}
	}
	if (!flag) printf("未找到!");
	else {
		MY[my++] = CS[index];
		printf("选修成功!\n");
	}
	system("pause");
	system("cls");
}
//选修课程浏览
void lookTakedClass() {
	system("cls");
	printf("选修课程浏览\n");
	printf("编号\t名称\t性质\t总学时\t授课学时\t实验或上机学时\t开课学期\t学分\n");
	for (int i = 0; i < my; ++i) {
		printClass(MY[i]);
	}
}
//退选课程
void dropClass() {
	lookTakedClass();
	printf("退选选修课程\n请输入需要退选的课程的编号:\n");
	char id[100] = { 0 };
	int index = 0, flag = 0;
	scanf("%s", id);
	printf("退选以下课程:\n编号\t名称\t性质\t总学时\t授课学时\t实验或上机学时\t开课学期\t学分\n");
	for (; index < my; ++index) {
		if (strcmp(MY[index]->id, id) == 0) {
			printClass(MY[index]);
			flag = 1;
			break;
		}
	}
	if (!flag) printf("未找到!");
	else {
		//退选课程
		for (int i = my - 1; i > index; --i) MY[i] = MY[i - 1];
		printf("退选成功!\n");
		--my;
	}
	system("pause");
	system("cls");
}
//预警查询
void alert() {
	lookTakedClass();
	printf("选修课程中学分不足30分的如下:\n");
	for (int i = 0; i < my; ++i) {
		if (MY[i]->score < 30) printClass(MY[i]);
	}
	system("pause");
	system("cls");
}
//保存文件
void save() {
	FILE* frp = NULL;
	frp = fopen("cs.txt", "w+");
	fprintf(frp, "%d %d", cs, my);
	fclose(frp);
	//保存数据
	FILE* fp1 = NULL;
	fp1 = fopen("class.txt", "w+");
	for (int i = 0; i < cs; ++i) {
		struct Class* c = CS[i];
		fprintf(fp1, "%s %s %s %d %d %d %d %d ", c->id, c->name, c->property,
			c->period_all, c->period_show, c->period_use, c->start_time, c->score);
	}
	fclose(fp1);
	FILE* fp2 = NULL;
	fp2 = fopen("my.txt", "w+");
	for (int i = 0; i < my; ++i) {
		struct Class* c = MY[i];
		fprintf(fp2, "%s %s %s %d %d %d %d %d ", c->id, c->name, c->property,
			c->period_all, c->period_show, c->period_use, c->start_time, c->score);
	}
	fclose(fp2);
}
//读取文件
void readFile() {
	FILE* frp = fopen("cs.txt", "r+");
	fscanf(frp, "%d %d", &cs, &my);
	fclose(frp);
	//读取数据
	FILE* fp1 = NULL;
	fp1 = fopen("class.txt", "r+");
	for (int i = 0; i < cs; ++i) {
		char id[100] = { 0 };			//编号
		char name[100] = { 0 };			//名称
		char property[100] = { 0 };		//性质
		int period_all;			//总学时
		int period_show;		//授课学时
		int period_use;			//实验或上机学时
		int start_time;			//开课学期
		int score;				//学分
		fscanf(fp1, "%s %s %s %d %d %d %d %d", id, name, property,
			&period_all, &period_show, &period_use, &start_time, &score);
		struct Class* c = (struct Class*)(malloc(sizeof(struct Class)));
		strcpy(c->id, id);
		strcpy(c->name, name);
		strcpy(c->property, property);
		c->period_all = period_all;
		c->period_show = period_show;
		c->period_use = period_use;
		c->start_time = start_time;
		c->score = score;
		CS[i] = c;
	}
	fclose(fp1);
	FILE* fp2 = NULL;
	fp2 = fopen("my.txt", "r+");
	for (int i = 0; i < my; ++i) {
		char id[100] = { 0 };			//编号
		char name[100] = { 0 };			//名称
		char property[100] = { 0 };		//性质
		int period_all;			//总学时
		int period_show;		//授课学时
		int period_use;			//实验或上机学时
		int start_time;			//开课学期
		int score;				//学分
		fscanf(fp2, "%s %s %s %d %d %d %d %d", id, name, property,
			&period_all, &period_show, &period_use, &start_time, &score);
		struct Class* c = (struct Class*)(malloc(sizeof(struct Class)));
		strcpy(c->id, id);
		strcpy(c->name, name);
		strcpy(c->property, property);
		c->period_all = period_all;
		c->period_show = period_show;
		c->period_use = period_use;
		c->start_time = start_time;
		c->score = score;
		MY[i] = c;
	}
	fclose(fp2);
}
//释放空间并保存
void FreeData() {
	save();
	for (int i = 0; i < cs; ++i) {
		free(CS[i]);
	}
	for (int i = 0; i < my; ++i) {
		free(MY[i]);
	}
}
//初始化程序
void initProgram() {
	if (access("cs.txt", 0)) {  //文件不存在
		FILE* frp = NULL;
		frp = fopen("cs.txt", "w+");
		fclose(frp);
	}
	if (access("class.txt", 0)) {  //文件不存在
		FILE* fp1 = NULL;
		fp1 = fopen("class.txt", "w+");
		fclose(fp1);
	}
	if (access("my.txt", 0)) {  //文件不存在
		FILE* fp2 = NULL;
		fp2 = fopen("my.txt", "w+");
		fclose(fp2);
	}
}
