#include<Windows.h>
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
//typedef struct _SYSTEMTIME {
//	WORD wYear;// 年
//	WORD wMonth;// 月
//	WORD wDayOfWeek;// 星期：0 为星期日，1 为星期一，2 为星期二……
//	WORD wDay;// 日
//	WORD wHour;// 时
//	WORD wMinute;//分
//	WORD wSecond;//秒
//	WORD wMilliseconds;// 毫秒
//}SYSTEMTIME,*PSYSTEMTIME;
void SetFont(int r, int c) {//调整控制台字体
	CONSOLE_FONT_INFOEX cfi;
	wcscpy_s(cfi.FaceName, L"黑体");//字体
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = r;//每个字符的宽
	cfi.dwFontSize.Y = c;//每个字符的高
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;//不加粗
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
void SetColor(UINT uFore, UINT uBack) {//调整控制台一部分的颜色
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, uFore + uBack * 0x10);
}
void SetTitle(LPCWSTR lpTitle) {//换控制台标题
	SetConsoleTitle(lpTitle);
}
string s,st="md ";
char S[1000],t;
int flag;
LL lst,Time, prt;
int main() {
	SetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE, GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE) & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);//隐藏最大化、最小化按钮
	SetFont(7, 14);
	system("mode con cols=40 lines=40");//将控制台调为40行10列
	SetColor(4, 15);
	SetTitle(L"Hidder");
	while(true){
		SetColor(4, 15);
		printf("你想隐藏文件夹还是查看隐藏的文件夹？\n\n");
		if (flag == 0)	SetColor(6, 7);
		printf("                        ");
		SetColor(4, 15);
		printf("\n");
		if (flag == 0)	SetColor(6, 7);
		printf("   新建并隐藏文件夹     ");
		SetColor(4, 15);
		printf("\n");
		if (flag == 0)	SetColor(6, 7);
		printf("                        \n");
		SetColor(4, 15);
		if (flag == 1)	SetColor(6, 7);
		printf("                        ");
		SetColor(4, 15);
		printf("\n");

		if (flag == 1)	SetColor(6, 7);
		printf("    调整隐藏的文件夹    ");
		SetColor(4, 15);
		printf("\n");
		if (flag == 1)	SetColor(6, 7);
		printf("                        \n");
		SetColor(4, 15);

		if (flag == 2)	SetColor(6, 7);
		printf("                        ");
		SetColor(4, 15);
		printf("\n");
		if (flag == 2)	SetColor(6, 7);
		printf("   打开隐藏的文件(夹)   ");
		SetColor(4, 15);
		printf("\n");
		if (flag == 2)	SetColor(6, 7);
		printf("                        \n");
		SetColor(4, 15);

		if (flag == 3)	SetColor(6, 7);
		printf("                        ");
		SetColor(4, 15);
		printf("\n");
		if (flag == 3)	SetColor(6, 7);
		printf("  隐藏已存在的文件(夹)  ");
		SetColor(4, 15);
		printf("\n");
		if (flag == 3)	SetColor(6, 7);
		printf("                        \n");
		SetColor(4, 15);

		if (flag == 4)	SetColor(6, 7);
		printf("                        ");
		SetColor(4, 15);
		printf("\n");
		if (flag == 4)	SetColor(6, 7);
		printf("解除隐藏已存在的文件(夹)");
		SetColor(4, 15);
		printf("\n");
		if (flag == 4)	SetColor(6, 7);
		printf("                        \n");
		SetColor(4, 15);

		SetColor(3, 15);
		printf("\n\n使用↑和↓键来调整你的选择,\n   按Enter键确定。");
		SYSTEMTIME ST = {};
		GetLocalTime(&ST);
		Time = ST.wSecond * 1000 + ST.wMilliseconds, prt = ST.wSecond * 1000 + ST.wMilliseconds-1000;
		while (true) {//选择隐藏文件夹还是查看隐藏的文件夹
			if (GetKeyState(VK_RETURN) < 0)	break;//按[Enter]表示选择现在的选项 
			GetLocalTime(&ST);
			Time = ST.wSecond*1000+ST.wMilliseconds;
			LL now = 0;
			if (GetKeyState(VK_DOWN) < 0)	now = 1;
			if (GetKeyState(VK_UP) < 0)	now = 2;
			if (now == 0) {
				lst = 0;
				continue;
			}
			if ((lst == now && Time - prt<1000))	continue;
			if (flag != 4 && GetKeyState(VK_DOWN) < 0)	flag++;
			else if (flag != 0 && GetKeyState(VK_UP) < 0)	flag--;
			else	continue;
			system("cls");
			SetColor(4, 15);
			printf("你想隐藏文件夹还是查看隐藏的文件夹？\n\n");
			if (flag == 0)	SetColor(6, 7);
			printf("                        ");
			SetColor(4, 15);
			printf("\n");
			if (flag == 0)	SetColor(6, 7);
			printf("   新建并隐藏文件夹     ");
			SetColor(4, 15);
			printf("\n");
			if (flag == 0)	SetColor(6, 7);
			printf("                        \n");
			SetColor(4, 15);

			if (flag == 1)	SetColor(6, 7);
			printf("                        ");
			SetColor(4, 15);
			printf("\n");
			if (flag == 1)	SetColor(6, 7);
			printf("    调整隐藏的文件夹    ");
			SetColor(4, 15);
			printf("\n");
			if (flag == 1)	SetColor(6, 7);
			printf("                        \n");
			SetColor(4, 15);

			if (flag == 2)	SetColor(6, 7);
			printf("                        ");
			SetColor(4, 15);
			printf("\n");
			if (flag == 2)	SetColor(6, 7);
			printf("   打开隐藏的文件(夹)   ");
			SetColor(4, 15);
			printf("\n");
			if (flag == 2)	SetColor(6, 7);
			printf("                        \n");
			SetColor(4, 15);

			if (flag == 3)	SetColor(6, 7);
			printf("                        ");
			SetColor(4, 15);
			printf("\n");
			if (flag == 3)	SetColor(6, 7);
			printf("  隐藏已存在的文件(夹)  ");
			SetColor(4, 15);
			printf("\n");
			if (flag == 3)	SetColor(6, 7);
			printf("                        \n");
			SetColor(4, 15);

			if (flag == 4)	SetColor(6, 7);
			printf("                        ");
			SetColor(4, 15);
			printf("\n");
			if (flag == 4)	SetColor(6, 7);
			printf("解除隐藏已存在的文件(夹)");
			SetColor(4, 15);
			printf("\n");
			if (flag == 4)	SetColor(6, 7);
			printf("                        \n");
			SetColor(4, 15);

			SetColor(3, 15);
			printf("\n\n使用↑和↓键来调整你的选择,\n   按Enter键确定。");

			GetLocalTime(&ST);
			if (lst != now)	prt = ST.wSecond * 1000 + ST.wMilliseconds;
			lst = now;
		}
		if (flag == 0) {
			system("cls");
			SetColor(4, 15);
			printf("\n你想创建一个什么名字的隐藏文件夹?");
			SetColor(6, 15);
			cin >> s;//输入文件夹名
			if (s.size() > 240) {
				SetColor(4, 15);
				system("cls");
				printf("\n文件夹名太长！");//Windows对文件路径有限制
				Sleep(2500);
				return 0;
			}
			st += s;//用md命令创建文件夹
			for (int i = 0; i < st.size(); i++)	S[i] = st[i];
			system(S);
			SetColor(4, 15);
			system("cls");
			printf("请存入文件,然后按下");//等待存储文件到文件夹中
			SetColor(6, 15);
			printf("Enter");
			SetColor(4, 15);
			printf("键");
			cin.get();
			cin.get();
			st = "attrib +s +h " + s;//用attrib命令隐藏文件夹
			for (int i = 0; i < st.size(); i++)	S[i] = st[i];
			system(S);
			system("cls");
			cout << "成功！";
			Sleep(2500);
		}
		if (flag == 1) {
			system("cls");
			SetColor(4, 15);
			printf("\n你想向一个什么名字的隐藏文件夹内存入文件？\n    ");
			SetColor(6, 15);
			cin >> s;
			if (s.size() > 240) {
				SetColor(4, 15);
				system("cls");
				printf("\n文件夹名太长！");//Windows对文件路径有限制
				Sleep(2500);
				return 0;
			}
			st = "attrib -s -h " + s;//用attrib命令解除隐藏
			for (int i = 0; i < st.size(); i++)	S[i] = st[i];
			system(S);
			SetColor(4, 15);
			system("cls");
			printf("请存入文件,然后按下");//等待存储文件到文件夹中
			SetColor(6, 15);
			printf("Enter");
			SetColor(4, 15);
			printf("键");
			cin.get();
			cin.get();
			st = "attrib +s +t " + s;//用attrib命令恢复隐藏
			for (int i = 0; i < st.size(); i++)	S[i] = st[i];
			system(S);
			system("cls");
			cout << "成功！";
			Sleep(2500);
		}
		if (flag == 2) {
			system("cls");
			SetColor(4, 15);
			printf("\n你想打开一个什么名字的隐藏文件(夹)？\n    ");
			SetColor(6, 15);
			cin >> s;
			if (s.size() > 240) {
				SetColor(4, 15);
				system("cls");
				printf("\n文件夹名太长！");//Windows对文件路径有限制
				Sleep(2500);
				return 0;
			}
			st = "explorer.exe " + s;
			for (int i = 0; i < st.size(); i++)	S[i] = st[i];
			system(S);
			SetColor(4, 15);
			system("cls");
			cout << "成功！";
			Sleep(2500);
		}
		if (flag == 3) {
			system("cls");
			SetColor(4, 15);
			printf("\n你想隐藏一个什么名字的文件(夹)?");
			SetColor(6, 15);
			cin >> s;//输入文件夹名
			if (s.size() > 240) {
				SetColor(4, 15);
				system("cls");
				printf("\n文件夹名太长！");//Windows对文件路径有限制
				Sleep(2500);
				return 0;
			}
			st = "attrib +s +h " + s;//用attrib命令隐藏文件夹
			for (int i = 0; i < st.size(); i++)	S[i] = st[i];
			system(S);
			SetColor(4, 15);
			system("cls");
			cout << "成功！";
			Sleep(2500);
		}
		if (flag == 4) {
			system("cls");
			SetColor(4, 15);
			printf("\n你想解除隐藏一个什么名字的文件(夹)？\n    ");
			SetColor(6, 15);
			cin >> s;
			if (s.size() > 240) {
				SetColor(4, 15);
				system("cls");
				printf("\n文件夹名太长！");//Windows对文件路径有限制
				Sleep(2500);
				return 0;
			}
			st = "attrib -s -h " + s;//用attrib命令解除隐藏
			for (int i = 0; i < st.size(); i++)	S[i] = st[i];
			system(S);
			system("cls");
			cout << "成功！";
			Sleep(2500);
		}
	}
	return 0;
}