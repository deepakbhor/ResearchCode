//#include "stdafx.h"
#include "tchar.h"
// Import the type library.

#import "C:\Users\Oval.Anurag\Documents\Visual Studio 2015\Projects\ClassLibrary4Try03\ClassLibrary4Try03\bin\Debug\ManagedDLL.tlb" raw_interfaces_only
using namespace ClassLibrary4Try03;
int _tmain(int argc, _TCHAR* argv[])
{
	// Initialize COM.
	HRESULT hr = CoInitialize(NULL);

	// Create the interface pointer.
	ICalculatorPtr pICalc(__uuidof(Class1));

	long lResult = 0;

	// Call the Add method.
	pICalc->Add(500, 100, &lResult);

	wprintf(L"The result is %d\n", lResult);


	// Uninitialize COM.
	CoUninitialize();
	return 0;
}