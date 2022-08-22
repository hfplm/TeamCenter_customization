#include"ITK_Header.h"

tag_t currentUser, home;

int createFolder(char* name, char* user) {

	ifail = FL_create2(name, "", &folder);
	errorHandler(ifail);

	ifail = AOM_save(folder);
	errorHandler(ifail);

	ifail = SA_find_user2(user, &currentUser);
	errorHandler(ifail);

	ifail = SA_ask_user_home_folder(currentUser, &home);
	errorHandler(ifail);

	ifail = FL_insert(home, folder, 999);
	errorHandler(ifail);
	
	ifail = AOM_save(home);
	errorHandler(ifail);

	return 0;
}