#include"ITK_Header.h"

int ITK_user_main(int argc, char* argv[]) {

	char* u = ITK_ask_cli_argument("-u=");
	char* p = ITK_ask_cli_argument("-p=");
	char* g = ITK_ask_cli_argument("-g=");


	tag_t item, rev;
	tag_t currentUser, home;


	ifail = ITK_init_module(u, p, g);
	errorHandler(ifail);

	ifail = ITEM_create_item(NULL, "myItem", "Item", "A", &item, &rev);
	errorHandler(ifail);

	ifail = ITEM_save_item(item);
	errorHandler(ifail);

	ifail = SA_find_user2(u, &currentUser);
	errorHandler(ifail);

	ifail = SA_ask_user_home_folder(currentUser, &home);
	errorHandler(ifail);

	ifail = FL_insert(home, item, 999);
	errorHandler(ifail);

	ifail = AOM_save(home);
	errorHandler(ifail);

	ifail = ITK_exit_module(true);
	errorHandler(ifail);

	return 0;
}