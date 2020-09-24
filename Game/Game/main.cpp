#include <Engine.h>

INT WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, INT nCmdShow)
{
	EngineSetup setup;
	new Engine(&setup);
	engine->Run();
	return 0;
}