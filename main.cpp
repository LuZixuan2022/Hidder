#include<Windows.h>
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
//typedef struct _SYSTEMTIME {
//	WORD wYear;// ��
//	WORD wMonth;// ��
//	WORD wDayOfWeek;// ���ڣ�0 Ϊ�����գ�1 Ϊ����һ��2 Ϊ���ڶ�����
//	WORD wDay;// ��
//	WORD wHour;// ʱ
//	WORD wMinute;//��
//	WORD wSecond;//��
//	WORD wMilliseconds;// ����
//}SYSTEMTIME,*PSYSTEMTIME;
void SetFont(int r, int c) {//��������̨����
	CONSOLE_FONT_INFOEX cfi;
	wcscpy_s(cfi.FaceName, L"����");//����
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = r;//ÿ���ַ��Ŀ�
	cfi.dwFontSize.Y = c;//ÿ���ַ��ĸ�
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;//���Ӵ�
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
void SetColor(UINT uFore, UINT uBack) {//��������̨һ���ֵ���ɫ
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, uFore + uBack * 0x10);
}
void SetTitle(LPCWSTR lpTitle) {//������̨����
	SetConsoleTitle(lpTitle);
}
string s,st="md ";
char S[1000],t;
int flag;
LL lst,Time, prt;
int main() {
	SetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE, GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE) & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);//������󻯡���С����ť
	SetFont(7, 14);
	system("mode con cols=40 lines=40");//������̨��Ϊ40��10��
	SetColor(4, 15);
	SetTitle(L"Hidder");
	while(true){
		SetColor(4, 15);
		printf("���������ļ��л��ǲ鿴���ص��ļ��У�\n\n");
		if (flag == 0)	SetColor(6, 7);
		printf("                        ");
		SetColor(4, 15);
		printf("\n");
		if (flag == 0)	SetColor(6, 7);
		printf("   �½��������ļ���     ");
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
		printf("    �������ص��ļ���    ");
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
		printf("   �����ص��ļ�(��)   ");
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
		printf("  �����Ѵ��ڵ��ļ�(��)  ");
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
		printf("��������Ѵ��ڵ��ļ�(��)");
		SetColor(4, 15);
		printf("\n");
		if (flag == 4)	SetColor(6, 7);
		printf("                        \n");
		SetColor(4, 15);

		SetColor(3, 15);
		printf("\n\nʹ�á��͡������������ѡ��,\n   ��Enter��ȷ����");
		SYSTEMTIME ST = {};
		GetLocalTime(&ST);
		Time = ST.wSecond * 1000 + ST.wMilliseconds, prt = ST.wSecond * 1000 + ST.wMilliseconds-1000;
		while (true) {//ѡ�������ļ��л��ǲ鿴���ص��ļ���
			if (GetKeyState(VK_RETURN) < 0)	break;//��[Enter]��ʾѡ�����ڵ�ѡ�� 
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
			printf("���������ļ��л��ǲ鿴���ص��ļ��У�\n\n");
			if (flag == 0)	SetColor(6, 7);
			printf("                        ");
			SetColor(4, 15);
			printf("\n");
			if (flag == 0)	SetColor(6, 7);
			printf("   �½��������ļ���     ");
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
			printf("    �������ص��ļ���    ");
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
			printf("   �����ص��ļ�(��)   ");
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
			printf("  �����Ѵ��ڵ��ļ�(��)  ");
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
			printf("��������Ѵ��ڵ��ļ�(��)");
			SetColor(4, 15);
			printf("\n");
			if (flag == 4)	SetColor(6, 7);
			printf("                        \n");
			SetColor(4, 15);

			SetColor(3, 15);
			printf("\n\nʹ�á��͡������������ѡ��,\n   ��Enter��ȷ����");

			GetLocalTime(&ST);
			if (lst != now)	prt = ST.wSecond * 1000 + ST.wMilliseconds;
			lst = now;
		}
		if (flag == 0) {
			system("cls");
			SetColor(4, 15);
			printf("\n���봴��һ��ʲô���ֵ������ļ���?");
			SetColor(6, 15);
			cin >> s;//�����ļ�����
			if (s.size() > 240) {
				SetColor(4, 15);
				system("cls");
				printf("\n�ļ�����̫����");//Windows���ļ�·��������
				Sleep(2500);
				return 0;
			}
			st += s;//��md������ļ���
			for (int i = 0; i < st.size(); i++)	S[i] = st[i];
			system(S);
			SetColor(4, 15);
			system("cls");
			printf("������ļ�,Ȼ����");//�ȴ��洢�ļ����ļ�����
			SetColor(6, 15);
			printf("Enter");
			SetColor(4, 15);
			printf("��");
			cin.get();
			cin.get();
			st = "attrib +s +h " + s;//��attrib���������ļ���
			for (int i = 0; i < st.size(); i++)	S[i] = st[i];
			system(S);
			system("cls");
			cout << "�ɹ���";
			Sleep(2500);
		}
		if (flag == 1) {
			system("cls");
			SetColor(4, 15);
			printf("\n������һ��ʲô���ֵ������ļ����ڴ����ļ���\n    ");
			SetColor(6, 15);
			cin >> s;
			if (s.size() > 240) {
				SetColor(4, 15);
				system("cls");
				printf("\n�ļ�����̫����");//Windows���ļ�·��������
				Sleep(2500);
				return 0;
			}
			st = "attrib -s -h " + s;//��attrib����������
			for (int i = 0; i < st.size(); i++)	S[i] = st[i];
			system(S);
			SetColor(4, 15);
			system("cls");
			printf("������ļ�,Ȼ����");//�ȴ��洢�ļ����ļ�����
			SetColor(6, 15);
			printf("Enter");
			SetColor(4, 15);
			printf("��");
			cin.get();
			cin.get();
			st = "attrib +s +t " + s;//��attrib����ָ�����
			for (int i = 0; i < st.size(); i++)	S[i] = st[i];
			system(S);
			system("cls");
			cout << "�ɹ���";
			Sleep(2500);
		}
		if (flag == 2) {
			system("cls");
			SetColor(4, 15);
			printf("\n�����һ��ʲô���ֵ������ļ�(��)��\n    ");
			SetColor(6, 15);
			cin >> s;
			if (s.size() > 240) {
				SetColor(4, 15);
				system("cls");
				printf("\n�ļ�����̫����");//Windows���ļ�·��������
				Sleep(2500);
				return 0;
			}
			st = "explorer.exe " + s;
			for (int i = 0; i < st.size(); i++)	S[i] = st[i];
			system(S);
			SetColor(4, 15);
			system("cls");
			cout << "�ɹ���";
			Sleep(2500);
		}
		if (flag == 3) {
			system("cls");
			SetColor(4, 15);
			printf("\n��������һ��ʲô���ֵ��ļ�(��)?");
			SetColor(6, 15);
			cin >> s;//�����ļ�����
			if (s.size() > 240) {
				SetColor(4, 15);
				system("cls");
				printf("\n�ļ�����̫����");//Windows���ļ�·��������
				Sleep(2500);
				return 0;
			}
			st = "attrib +s +h " + s;//��attrib���������ļ���
			for (int i = 0; i < st.size(); i++)	S[i] = st[i];
			system(S);
			SetColor(4, 15);
			system("cls");
			cout << "�ɹ���";
			Sleep(2500);
		}
		if (flag == 4) {
			system("cls");
			SetColor(4, 15);
			printf("\n����������һ��ʲô���ֵ��ļ�(��)��\n    ");
			SetColor(6, 15);
			cin >> s;
			if (s.size() > 240) {
				SetColor(4, 15);
				system("cls");
				printf("\n�ļ�����̫����");//Windows���ļ�·��������
				Sleep(2500);
				return 0;
			}
			st = "attrib -s -h " + s;//��attrib����������
			for (int i = 0; i < st.size(); i++)	S[i] = st[i];
			system(S);
			system("cls");
			cout << "�ɹ���";
			Sleep(2500);
		}
	}
	return 0;
}