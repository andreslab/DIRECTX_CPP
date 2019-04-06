#include "Engine.h"

bool Engine::Initialize(HINSTANCE hInstance, std::string window_title, std::string window_class, int width, int height) {
	return this->render_window.Initialize(hInstance, window_title, window_class, width, height);
}
bool Engine::ProcessMessages() {
	//render_window of WindowContainer.h
	return this->render_window.ProcessMessages();
}