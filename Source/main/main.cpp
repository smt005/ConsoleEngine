
#define WINDOWS_HIDE_CONSOLE 1

#if WINDOWS_HIDE_CONSOLE
	#include <Windows.h>
#endif

#include "Execution.h"

int main(int argc, char** argv)
{
#if WINDOWS_HIDE_CONSOLE
	FreeConsole();
#endif
	return Execution::run();
}
