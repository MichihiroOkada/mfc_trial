#include "Controller.h"

int Controller::run()
{
	// モーダル
	int result = m_dialogError.show();

	if (result == RESULT_OK) {
		printf("OK Button pushed\n");
	}
	else if (result == RESULT_CANCEL) {
		printf("Cancel Button pushed\n");
	}
	return 0;
}
