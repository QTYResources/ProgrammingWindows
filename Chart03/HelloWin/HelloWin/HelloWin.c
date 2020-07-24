/*-------------------------------------------------------------------------------------
	HELLOWIN.c -- Displays "Hello, Windows 98!" in client area
					(c) Charles Petzold, 1998
   ------------------------------------------------------------------------------------*/
#include <windows.h>

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("HelloWin");
	HWND		hwnd;
	MSG			msg;
	WNDCLASS	wndclass;

	wndclass.style					= CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc			= WndProc;
	wndclass.cbClsExtra				= 0;
	wndclass.cbWndExtra				= 0;
	wndclass.hInstance				= hInstance;
	wndclass.hIcon					= LoadIcon (hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wndclass.hCursor				= LoadCursor (NULL, IDC_ARROW);
	wndclass.hbrBackground			= (HBRUSH) (COLOR_WINDOW + 1);
	wndclass.lpszMenuName			= NULL;
	wndclass.lpszClassName			= szAppName;


	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT!"), szAppName, MB_ICONERROR);
		return 1;
	}

	hwnd = CreateWindow (szAppName,						// window class name
						 TEXT("The Hello Program"),	// window caption
						 WS_OVERLAPPEDWINDOW,			// window style
						 CW_USEDEFAULT,					// initial x position
						 CW_USEDEFAULT,					// initial y position
						 CW_USEDEFAULT,					// initial x size
						 CW_USEDEFAULT,					// initial y size
						 NULL,							// parent window handle
						 NULL,							// window menu handle
						 hInstance,						// program instance handle
						 NULL);							// create parameters

	if (!hwnd) {
		MessageBox(NULL, TEXT("Call to CreateWindow failed!"), szAppName, NULL);
		return 2;
	}

	ShowWindow (hwnd, iCmdShow);
	UpdateWindow (hwnd);

	while (GetMessage (&msg, NULL, 0, 0))
	{
		TranslateMessage (&msg);
		DispatchMessage (&msg);
	}

	return (int) msg.wParam;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
	HDC			hdc;
	PAINTSTRUCT ps;
	RECT		rect;

	switch (message)
	{
	case WM_CREATE:
		PlaySound (TEXT("HelloWin.mp3"), NULL, SND_FILENAME | SND_ASYNC);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint (hwnd, &ps);

		GetClientRect (hwnd, &rect);

		DrawText (hdc, TEXT("Hello, Windows 98!"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint (hwnd, &ps);
		return 0;

	case WM_DESTROY:
		PostQuitMessage (0);
		return 0;
	}
	return DefWindowProc (hwnd, message, wParam, lParam);
}