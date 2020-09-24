#include "Engine.h"

Engine* engine = NULL;

LRESULT CALLBACK WinProc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	switch (msg) {
	case WM_ACTIVATEAPP:
		engine->SetDeactiveFlag(!wparam);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(wnd, msg, wparam, lparam);
	}
}

Engine::Engine(EngineSetup* _setup) {
	loaded = false;
	setup = new EngineSetup;
	if (setup != NULL)
		memcpy(setup, _setup, sizeof(EngineSetup));
	engine = this;
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_OWNDC;
	wcex.lpfnWndProc = WinProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = setup->instance;
	wcex.hIcon = /*LoadIcon(NULL, IDI_APPLICATION)*/NULL;
	wcex.hCursor = /*LoadCursor(NULL, IDC_ARROW)*/NULL;
	wcex.hbrBackground = NULL;
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"WindowClass";
	wcex.hIconSm = /*LoadIcon(NULL, IDI_APPLICATION)*/NULL;
	RegisterClassEx(&wcex);

	window = CreateWindowEx(/*WS_EX_TOPMOST*/NULL, L"WindowClass", /*(LPCWSTR)setup->name*/L"Xui", WS_OVERLAPPEDWINDOW,
		0, 0, 1024, 768, NULL, NULL, setup->instance, NULL);

	loaded = true;
}

Engine::~Engine() {
	if (loaded == true) {

	}

	UnregisterClass(L"WindowClass", setup->instance);
	delete setup;
}

void Engine::Run() {
	if (loaded == false) {
		delete engine;
		return;
	}
	ShowWindow(window, SW_NORMAL);
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

void Engine::SetDeactiveFlag(bool _deactive) {
	deactive = _deactive;
}