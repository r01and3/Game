#pragma once
#include <Windows.h>

struct EngineSetup {
	HINSTANCE instance;
	const char* name;

	EngineSetup() {
		instance = NULL;
		name = "Application";
	}
};

class Engine {
public:
	Engine(EngineSetup* _setup);
	~Engine();

	void Run();
	//HWND GetWindow();
	void SetDeactiveFlag(bool _deactive);

private:
	bool loaded;
	HWND window;
	bool deactive;
	EngineSetup* setup;
};

extern Engine* engine;
