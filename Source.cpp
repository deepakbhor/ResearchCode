#include<Windows.h>

/*

WINAPI defines a standard call, i.e. Calling Convention
HINSTANCE specifies a handler which is nothing but an integer value. It is an instance handle.It identifies the current window
Windowformat, tells in which format is the window shown.
PSTR - Pointer to a string which tells command line args.
Second parameter is always null.

*/

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE previnstance, PSTR cmdlinearg, int windowformat)
{
	
	int whichbuttonclikced = 0;
	int finalresult = 0;

	//the return value of the YES button is 6.
	whichbuttonclikced=MessageBox(NULL, TEXT("HELLO WINDOWS 98"), TEXT("HelloMsg"), MB_YESNO);
	
	if (whichbuttonclikced == 6) {
		//MessageBox(NULL, TEXT("HELLO WINDOWS 98"), TEXT("Yes was clicked in main"), MB_YESNO);
		finalresult = 1;

	}
	else
	{
		//MessageBox(NULL, TEXT("HELLO WINDOWS 98"), TEXT("No was clicked in main"), MB_YESNO);
		finalresult = 0;
	}
	
	
	return 0;

}