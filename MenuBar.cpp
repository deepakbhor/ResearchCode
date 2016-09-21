

#include<Windows.h>

LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);
#define BUTTONID 1


int WINAPI WinMain(HINSTANCE hcurinstance, HINSTANCE hPrevinstance, LPSTR cmdline, int windowformat)
{
	static HWND mainwindow;
	TCHAR szAppName[] = L"MenuBar";
	WNDCLASS wcl;
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	wcl.hCursor = LoadCursor(NULL, IDI_APPLICATION);

	wcl.hIcon = LoadIcon(NULL, IDC_ARROW);
	wcl.hInstance = hcurinstance;
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

	wcl.lpfnWndProc = WinProc;
	wcl.lpszClassName = szAppName;
	wcl.lpszMenuName = NULL;

	wcl.style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClass(&wcl))
	{
		MessageBox(NULL, L"ERROR", L"This program requires Windows NT", MB_ICONERROR);
		return 0;
	}

	
	mainwindow = CreateWindow(wcl.lpszClassName,
		L"Menu Bar tutorial",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hcurinstance,
		NULL
	);

	ShowWindow(mainwindow, windowformat);
	UpdateWindow(mainwindow);

	MSG msg;
	while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}


LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	static HWND button;
	
	

	static HMENU MenuBar;

	static HMENU level1Menu;
	static HMENU level2Menu;

	static HMENU build;
	static HMENU buildpopup;
	static HMENU projectonly;

	static HMENU openpopup;

	static HMENU View;
	static HMENU ViewMenu;

	switch (message)
	{
		
		case WM_CREATE:
			
			
			/* hMenubar = CreateMenu();
			 hMenu = CreateMenu();
			 hSubMenu = CreatePopupMenu();

			AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hMenu, L"Menu");
			AppendMenu(hMenu, MF_STRING, ID_SM, L"Sub Menu");*/



//			AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT_PTR)hSubMenu, L"Sub-Sub Menu");

		//	SetMenu(hwnd, hMenubar);
			
			MenuBar = CreateMenu();// For Creating Main Menu bar.
			level1Menu = CreateMenu();//For Adding the level 1 menu bar, i.e. Menu Item and Build When u run the project.
			View = CreateMenu();
			build = CreateMenu();
			//level2Menu = CreateMenu();
			level2Menu = CreatePopupMenu();//This is for adding the pop up required for Menu Item.
			//openpopup = CreatePopupMenu();
			
			AppendMenu(MenuBar, MF_POPUP, (UINT_PTR)level1Menu, L"Menu Item 1");

			
			//AppendMenu(MenuBar, MF_POPUP, (UINT_PTR)level1Menu, L"Menu Item 2");
			//AppendMenu(level1Menu,MF_STRING,ID_SM,L"Level 1 Menu");
			AppendMenu(level1Menu, MF_STRING, (UINT_PTR)level2Menu, L"Level 2 Menu");
			AppendMenu(level1Menu, MF_STRING, (UINT_PTR)level2Menu, L"File");
			AppendMenu(level1Menu, MF_STRING, (UINT_PTR)level2Menu, L"Edit");
			AppendMenu(level1Menu, MF_STRING|MF_POPUP, (UINT_PTR)level2Menu, L"Open");
			//AppendMenu();

			

			//The Following is for adding Build Menu and Sub Menus under it.
			
			buildpopup = CreatePopupMenu();
			projectonly = CreatePopupMenu();//The following is for adding the project pop up.
			AppendMenu(MenuBar, MF_POPUP, (UINT_PTR)build, L"Build");
			AppendMenu(build, MF_STRING, (UINT_PTR)buildpopup, L"Build Solution");
			AppendMenu(build, MF_STRING, (UINT_PTR)buildpopup, L"Re Build Solution");
			AppendMenu(build, MF_STRING, (UINT_PTR)buildpopup, L"Clean Solution");
			AppendMenu(build, MF_STRING, (UINT_PTR)buildpopup, L"Run Code Analysis on Solution");
			AppendMenu(build, MF_SEPARATOR, (UINT_PTR)buildpopup, NULL); //For INserting Seprator line, i.e. to insert a line.
			AppendMenu(build, MF_STRING|MF_POPUP, (UINT_PTR)buildpopup, L"Project Only");
			AppendMenu(buildpopup, MF_STRING, (UINT_PTR)projectonly, L"Build Only the Current Project");


			//For Adding View Menu 
			AppendMenu(MenuBar, MF_POPUP, (UINT_PTR)View, L"View");
			ViewMenu = CreatePopupMenu();
			AppendMenu(View, MF_STRING, (UINT_PTR)ViewMenu, L"Code");
			AppendMenu(View, MF_STRING, (UINT_PTR)ViewMenu, L"Open");
			SetMenu(hwnd, MenuBar);

			
		//	SetMenu(hwnd, menu);
			

		button	= CreateWindow(L"BUTTON",
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


		case WM_DESTROY:
				PostQuitMessage(0);
			
			
			return 0;

	}
	return DefWindowProc(hwnd, message, wparam, lparam);//If you ignore this the main window will not be visible.
}