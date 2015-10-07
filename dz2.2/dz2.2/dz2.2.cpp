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



LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	RECT RectWnd;
	GetWindowRect(
		hWnd,
		&RectWnd);
	TCHAR str[60];
	switch (uMessage)
	{
	case WM_LBUTTONUP:
		if (RectWnd.left + 10<HIWORD(lParam) && RectWnd.right - 10>HIWORD(lParam) && RectWnd.top + 10<LOWORD(lParam) && RectWnd.bottom - 10>LOWORD(lParam))
		SetWindowText(hWnd,TEXT("Курсор внутри означеной зоны"));
		else
			SetWindowText(hWnd, TEXT("Курсор вне означеной зоны"));
		break;
	case WM_RBUTTONUP:
		wsprintf(str, TEXT("Ширина клиентской зоны %d пикселей, высота %d пикселей."), RectWnd.right-RectWnd.left,RectWnd.bottom-RectWnd.top);
		SetWindowText(hWnd, str);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
}