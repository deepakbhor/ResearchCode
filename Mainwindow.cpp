

#include<Windows.h>
LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);

#define EDITID 10
#define BUTTONID 20

int WINAPI WinMain(HINSTANCE hcurrinstance,HINSTANCE hprevinstance,LPSTR cmdlineargs,int windowformat)
{
	HWND mainwindow;
	TCHAR szAppName[] = L"Custom Window";

	WNDCLASS wcl;
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hInstance = hcurrinstance;
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);

	wcl.lpszClassName = szAppName;
	wcl.lpszMenuName = NULL;
	wcl.style = CS_VREDRAW | CS_HREDRAW;

	wcl.lpfnWndProc = WinProc;

	if (!RegisterClass(&wcl))
	{
		MessageBox(NULL, L"ERROR", L"This program requires Windows NT", MB_ICONERROR);
		return 0;
	}


	mainwindow = CreateWindow(wcl.lpszClassName,
		L"Main Window",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hcurrinstance,
		0
	);

	ShowWindow(mainwindow, windowformat);
	UpdateWindow(mainwindow);

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;

}

LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	static HWND button,button1;
	static HWND editcontrol,editcontrol1;
	static HWND heading;
	TCHAR content[30];

	switch (message)
	{
		
		case WM_CREATE:
			{

				heading = CreateWindow(L"static",
				L"Webservice Config",
				WS_CHILD | WS_VISIBLE | WS_BORDER,
				20,
				20,
				150,
				20,
				hwnd,
				NULL,
				GetModuleHandle(NULL),
				NULL
			);

				editcontrol = CreateWindow(L"EDIT",
				L"",
				WS_CHILD | WS_BORDER,
				30,	
				30,
				100,
				100,
				hwnd,
				(HMENU)EDITID,
				GetModuleHandle(NULL),
				NULL
			);
				HGDIOBJ hfDefault = GetStockObject(DEFAULT_GUI_FONT);
				SendMessage(editcontrol,
					WM_SETFONT,
					(WPARAM)hfDefault,
					MAKELPARAM(FALSE, 0));
			ShowWindow(editcontrol, 9);
		

			

			editcontrol1 = CreateWindow(L"EDIT",
				L"",
				WS_CHILD | WS_BORDER,
				50,
				50,
				100,
				100,
				hwnd,
				NULL,
				NULL,
				NULL
			);
			//SetWindowText(editcontrol1, content);
			ShowWindow(editcontrol1, 1);

			button = CreateWindow(L"BUTTON",
				L"OK",
				WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
				800,
				400,
				60,
				30,
				hwnd,
				(HMENU)BUTTONID,
				GetModuleHandle(NULL),
				NULL
			);


		return 0;
		}


		case WM_COMMAND:
		{
			switch (LOWORD(wparam))
			{
			case BUTTONID:
			{
				GetWindowText(editcontrol, content, 20);
				SetWindowText(editcontrol1, content);
			}
			return 0;
			}
			return 0;
		}


		case WM_DESTROY:
		{//In this case if we dont call PostQuitMessage(0); then the application wont start after it has been started initially.
			PostQuitMessage(0);
			return 0;
		}
	}


	return DefWindowProc(hwnd, message, wparam, lparam);
	
	
}