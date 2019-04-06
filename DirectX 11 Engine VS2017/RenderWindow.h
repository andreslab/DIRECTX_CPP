#pragma once
#include "ErrorLogger.h"

class WindowContainer;

class RenderWindow {
public:
	bool Initialize(WindowContainer * pWindowContainer, HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int height);
	bool ProcessMessages(); //si se presiona una tecla o se usa el mouse
	~RenderWindow();
private:
	void RegisterWindowClass();
	HWND handle = NULL; //handle to this window, cuando se crea una ventana se recibe un handle
	HINSTANCE hInstance = NULL; //handle to application instance
	std::string window_title = "";
	std::wstring window_title_wide = L""; //wide string representation of window title
	std::string window_class = "";
	std::wstring window_class_wide = L""; //wide string representation of window class name
	int width = 0;
	int height = 0;

};