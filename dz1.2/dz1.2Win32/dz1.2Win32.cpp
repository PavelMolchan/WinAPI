#include <windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <time.h>


INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	srand(time(NULL));
	int randnum;
	int answer;
	wchar_t str1[5];
	do{
		int steps = 0;
		do{
			randnum = rand() % 100 + 1;
			_itow(randnum, str1, 10);
			answer = MessageBox(
				0,
				str1,
				TEXT("�� �������� ��� �����?"),
				MB_YESNO | MB_ICONQUESTION
				);
			steps++;
		} while (answer != IDYES);
		wchar_t str2[25] = TEXT("���������� �������: ");
		_itow(steps, str1, 10);
		wcscat(str2, str1);
		answer = MessageBox(
			0,
			TEXT("������ ����������� ��� ���?"),
			str2,
			MB_YESNO | MB_ICONQUESTION
			);
	} while (answer != IDNO);
	return 0;
}