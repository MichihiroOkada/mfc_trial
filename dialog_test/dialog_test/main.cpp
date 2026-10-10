#include "Controller.h"

int main(void)
{
	Controller controller;

    // MFCを初期化
    if (!AfxWinInit(
        ::GetModuleHandle(NULL),
        NULL,
        ::GetCommandLine(),
        0))
    {
        return 1;
    }

	controller.run();

	return 0;
}
