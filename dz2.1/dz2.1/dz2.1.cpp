#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Каркасное приложение");

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcl;
	wcl.cbSize = sizeof(wcl);	
	wcl.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;	
	wcl.lpfnWndProc = WindowProc;	
	wcl.cbClsExtra = 0;		
	wcl.cbWndExtra = 0; 	
	wcl.hInstance = hInst;	
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);	
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);		
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		
	wcl.lpszMenuName = NULL;	
	wcl.lpszClassName = szClassWindow;	
	wcl.hIconSm = NULL;
	if (!RegisterClassEx(&wcl))
		return 0;	
	hWnd = CreateWindowEx(
		0,		
		szClassWindow,	
		TEXT("Каркас  Windows приложения"),
		WS_OVERLAPPEDWINDOW,	
		CW_USEDEFAULT,	
		CW_USEDEFAULT,	
		CW_USEDEFAULT,	
		CW_USEDEFAULT,	
		NULL,			
		NULL,			
		hInst,		
		NULL);		
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);	
	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);	
		DispatchMessage(&lpMsg);	
	}
	return lpMsg.wParam;
}

int left = 0;
int right = 0;
int mid = 0;

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	TCHAR str[60];
	switch (uMessage)
	{
	case WM_LBUTTONUP:
		left++;
		wsprintf(str, TEXT("Левая кнопка нажата %d раз, правая %d раз, средняя %d раз."), left,right, mid); 
		SetWindowText(hWnd, str);	
		break;
	case WM_RBUTTONUP:
		right++;
		wsprintf(str, TEXT("Левая кнопка нажата %d раз, правая %d раз, средняя %d раз."), left, right, mid);
		SetWindowText(hWnd, str);
		break;
	case WM_MBUTTONUP:
		mid++;
		wsprintf(str, TEXT("Левая кнопка нажата %d раз, правая %d раз, средняя %d раз."), left, right, mid);
		SetWindowText(hWnd, str);
		break;
	case WM_DESTROY: 
		PostQuitMessage(0);	
		break;
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
}