#pragma once
#include "CDialogError.h"

enum {
	RESULT_OK = 100,
	RESULT_CANCEL = 101,
};

class Controller
{
public:
	Controller() {};
	~Controller() {};
	int run();

private:
	CDialogError m_dialogError;
};

