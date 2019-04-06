//#include "RenderWindow.h"
#include "WindowContainer.h"

//funcion de inicializacion
bool RenderWindow::Initialize(HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int heght) {
	this->hInstance = hInstance;
	this->width = width;
	this->height = height;
	this->window_title = window_title;
	this->window_title_wide = StringConverter::StringToWide(this->window_title);
	this->window_class = window_class;
	this->window_class_wide = StringConverter::StringToWide(this->window_class); //wide string represetation of class

	this->RegisterWindowClass();

	this->handle = CreateWindowEx(0, //Extended window style
		this->window_class_wide.c_str(), //window class name
		this->window_title_wide.c_str(), //windoe title
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, // window style
		0, //window x position
		0, //window y position
		this->width, //window width
		this->height, //window height
		NULL, //handle to parent of this window
		NULL, //hanlde to menu or child window identifier
		this->hInstance, //handle to the instance of module to be used with this window
		nullptr); //param to create window

	//verify if window created
	if (this->handle == NULL) {
		ErrorLogger::Log(GetLastError(), "CreateWindowEx failed for window" + this->window_title);
		return false;
	}

	ShowWindow(this->handle, SW_SHOW);
	SetForegroundWindow(this->handle);
	SetFocus(this->handle);

	return true;
}

bool RenderWindow::ProcessMessages() {
	//hanlde thie window message
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));//initializa the message structure

	if (PeekMessage(&msg, //Where to store message (if one exists)
		this->handle, //handle to window we are checking message for
		0, //minimun filter msg value
		0, //maximun filter msg value
		PM_REMOVE)) //remove message after capturing it via PeekMessage 
	{
		TranslateMessage(&msg); //translate message from virtual key message into character message
		DispatchMessage(&msg); //dispatch message to our window proc for this window
	}

	//check if  the window was closed
	if (msg.message == WM_QUIT) {
		if (!IsWindow(this->handle)) {
			this->handle == NULL; //message processing loop takes care of destroying this window
			UnregisterClass(this->window_class_wide.c_str(), this->hInstance);
			return false;
		}
	}

	return true;
}

RenderWindow::~RenderWindow() {
	if (this->handle != NULL) {
		UnregisterClass(this->window_class_wide.c_str(), this->hInstance);
		DestroyWindow(handle);
	}
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	//return DefWindowProc(hwnd, uMsg, wParam, lParam);

	switch (uMsg)
	{
	//se ejecuta cuando crea una ventana
	case WM_NCCREATE:
	{
		OutputDebugStringA("the window was created.\n");
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	//capturar la letra luego de la presion
	/*case WM_CHAR:
	{
		unsigned char letter = static_cast<unsigned char>(wParam);
		return 0;
	}
	//captura la accion de presion de la tecla
	case WM_KEYDOWN:
	{
		unsigned char keycode = static_cast<unsigned char>(wParam);
		return 0;
	}*/
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}

void RenderWindow::RegisterWindowClass(){
	WNDCLASSEX wc; // our windows class (this has to be filled before our window can be created)
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC; //flags [REDRAW on width /height]
	//wc.lpfnWndProc = DefWindowProc; // Pointer to window Proc fuction handling message
	wc.lpfnWndProc = WindowProc;
	wc.cbClsExtra = 0; //# of extra bytes to allocate following the windows class structure
	wc.cbWndExtra = 0; //# of extra bytes to allocate following the windows instance.
	wc.hInstance = this->hInstance; //handle to the instance
	wc.hIcon = NULL; // handle to the class icon
	wc.hIconSm = NULL; // handle to small icon for this class
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); //Default Cursor - If we leave this null, we hace to explivitily set
	wc.hbrBackground = NULL; // handle to the class background brush for the windows s background color
	wc.lpszMenuName = NULL; //pointer to a null terminal character string for the menu
	wc.lpszClassName = this->window_class_wide.c_str(); //Pointer to null terminated string to our class name
	wc.cbSize = sizeof(WNDCLASSEX); //need to fill in the size of ou struct fo cbSize
	RegisterClassEx(&wc); //register thie class so that it is usuable
}	


