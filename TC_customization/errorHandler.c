#include"ITK_Header.h"

int errorHandler(int ifail) {
	char* msg;
	if (ifail == 0) {
		printf("\n\n Test Passed ! ");
	}
	else {
		printf("\n Error Code : %d", ifail);
		EMH_ask_error_text(ifail, &msg);
		printf("\n Error: %s", msg);
	}
	return 0;
}