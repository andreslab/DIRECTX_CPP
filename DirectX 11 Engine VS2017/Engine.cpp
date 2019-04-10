#include "Engine.h"

bool Engine::Initialize(HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int height) {
	//keyboard.EnableAutoRepeatChars();
	return this->render_window.Initialize(this, hInstance, window_title, window_class, width, height);
}
bool Engine::ProcessMessages() {
	//render_window of WindowContainer.h
	return this->render_window.ProcessMessages();
}

void Engine::Update() {
	while (!keyboard.CharBufferIsEmpty()) {
		unsigned char ch = keyboard.ReadChar();
		//test code
		/*
		std::string outmsg = "char: ";
		outmsg += ch;
		outmsg += "\n";
		OutputDebugStringA(outmsg.c_str());*/
	}

	while (!keyboard.KeyBufferIsEmpty()) {
		KeyboardEvent kbe = keyboard.ReadKey();
		unsigned char keycode = kbe.GetKeyCode();

		//test code
		/*std::string outmsg = "";
		if (kbe.IsPress()) {
			outmsg += "Key press: ";
		}
		if (kbe.IsRelease()) {
			outmsg += "key release: ";
		}
		outmsg += keycode;
		outmsg += "\n";
		OutputDebugStringA(outmsg.c_str());*/
	}
}