#include <Windows.h>
#include "ErrorLogger.h"
#include "RenderWindow.h"
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "DirectXTK.lib")

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int mCmdShow) {

	//HRESULT hr = E_INVALIDARG;
	HRESULT hr = S_OK;

	if (SUCCEEDED(hr)) {
		MessageBoxA(NULL, "SUCCESS", "SUCCESS", NULL);
	}

	if (FAILED(hr)) {
		ErrorLogger::Log(hr, "Failure");
	}

	//test error
	//ErrorLogger::Log(E_INVALIDARG, "Test Message");

	//creta custom window
	RenderWindow rw;
	rw.Initialize(hInstance, "Title", "MyWindowClass", 800, 600);
	//keep window active but not available fot interact
	/*while (true) {
		Sleep(50);
	}*/

	//keep window active
	while (rw.ProcessMessages() == true) {}


	return 0;
	
}