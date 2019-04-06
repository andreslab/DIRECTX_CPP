#pragma once
#include "RenderWindow.h" 

class WindowContainer {
public:
	//windowProc
	//keyboard
	//mouse
	LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
protected:
	RenderWindow render_window;
private:
};