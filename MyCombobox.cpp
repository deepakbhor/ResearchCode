

#include<Windows.h>
#define ID_LIST 1
#define ID_TEXT 2
/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
/*  Make the class name into a global variable  */
char szClassName[] = "ComboBox App";
int WINAPI WinMain(HINSTANCE hThisInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpszArgument,
	int nFunsterStil)
{
	HWND hwnd;               /* This is the handle for our window */
	MSG messages;            /* Here messages to the application are saved */
	WNDCLASSEX wincl;        /* Data structure for the windowclass */
							 /* The Window structure */
	wincl.hInstance = hThisInstance;
	wincl.lpszClassName = L"ComboBox App";
	wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
	wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
	wincl.cbSize = sizeof(WNDCLASSEX);
	/* Use default icon and mouse-pointer */
	wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL;                 /* No menu */
	wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
	wincl.cbWndExtra = 0;                      /* structure or the window instance */
											   /* Use Windows's default color as the background of the window */
	wincl.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
	/* Register the window class, and if it fails quit the program */
	if (!RegisterClassEx(&wincl))
		return 0;
	/* The class is registered, let's create the program*/
	hwnd = CreateWindowEx(
		0,                   /* Extended possibilites for variation */
		L"ComboBox App",         /* Classname */
		L"ComboBox App1",       /* Title Text */
		WS_OVERLAPPEDWINDOW, /* default window */
		CW_USEDEFAULT,       /* Windows decides the position */
		CW_USEDEFAULT,       /* where the window ends up on the screen */
		544,                 /* The programs width */
		375,                 /* and height in pixels */
		HWND_DESKTOP,        /* The window is a child-window to desktop */
		NULL,                /* No menu */
		hThisInstance,       /* Program Instance handler */
		NULL                 /* No Window Creation data */
	);
	/* Make the window visible on the screen */
	ShowWindow(hwnd, nFunsterStil);
	/* Run the message loop. It will run until GetMessage() returns 0 */
	while (GetMessage(&messages, NULL, 0, 0))
	{
		/* Translate virtual-key messages into character messages */
		TranslateMessage(&messages);
		/* Send message to WindowProcedure */
		DispatchMessage(&messages);
	}
	/* The program return-value is 0 - The value that PostQuitMessage() gave */
	return messages.wParam;
}
//User Defined Function(s)
//Compare the efficiency of my C++ function vs. Charles Petzold's C function  
//Page #407
void FillListBox(HWND hwndList)
{
	TCHAR *pVarName[] = { L"Item1", L"Item2", L"Item3", L"Item4", L"Item5" };

	for (int i = 0; i<5; i++)

		SendMessage(hwndList, CB_ADDSTRING, 0, (LPARAM)pVarName[i]);

}

/*  This function is called by the Windows function DispatchMessage()  */
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND hwndList, hwndText;
	int iIndex, iLength, cxChar, cyChar;
	TCHAR pVarName[30];



	switch (message)                  /* handle the messages */
	{

	case WM_CREATE:

		cxChar = LOWORD(GetDialogBaseUnits());
		cyChar = HIWORD(GetDialogBaseUnits());

		//Create Display Window
		hwndText = CreateWindow(TEXT("static"), NULL, WS_CHILD | WS_VISIBLE |
			SS_LEFT, cxChar, cyChar,
			GetSystemMetrics(SM_CXSCREEN), cyChar,
			hwnd, (HMENU)ID_TEXT,
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
			NULL);

		//Create ComboBox
		hwndList = CreateWindow(TEXT("Combobox"), NULL, WS_CHILD | WS_VISIBLE |
			LBS_STANDARD, cxChar, cyChar * 3,
			cxChar * 16 + GetSystemMetrics(SM_CXVSCROLL),
			cyChar * 5, hwnd, (HMENU)ID_LIST,
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
			NULL);

		//Populate ComboBox
		FillListBox(hwndList);

		//Set a Default Selection
		SendMessage(hwndList, CB_SETCURSEL, 0, 0);
		GetWindowText(hwndList, pVarName, 30);
		SetWindowText(hwndText, pVarName);

		return 0;

	case WM_COMMAND:

		if (LOWORD(wParam) == ID_LIST && HIWORD(wParam) == CBN_SELCHANGE)
		{
			//Get Selection from Combo Box                 
			GetWindowText(hwndList, pVarName, 30);

			//Show Text in Display Window
			SetWindowText(hwndText, pVarName);
		}

		return 0;

	case WM_DESTROY:

		PostQuitMessage(0);       /* send a WM_QUIT to the message queue */
		break;

	default:
		/* for messages that we don't deal with */
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}