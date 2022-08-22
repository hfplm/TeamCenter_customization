#include"ITK_Header.h"

int ITK_user_main(int argc, char* argv[]) {
	
	char* u = ITK_ask_cli_argument("-u=");
	char* p = ITK_ask_cli_argument("-p=");
	char* g = ITK_ask_cli_argument("-g=");
	char* file = ITK_ask_cli_argument("-file=");
	char* folderName = ITK_ask_cli_argument("-folderName=");


	tag_t item, rev;
	tag_t currentUser, home;

	
	
	char buffer[100];
	//char* id;
	char* name;
	char* type;
	char* datasetType;
	char* datasetRelation;

	ifail = ITK_init_module(u, p, g);
	errorHandler(ifail);

	createFolder(folderName, u);

	FILE* csv = fopen(file, "rt");

	if (!csv) perror("Unable to read file.");

	while(fgets(buffer, 100, csv)) {

		// id = strtok(buffer, ",");
		name = strtok(buffer, ",");
		type = strtok(NULL, ",");
		datasetType = strtok(NULL, ",");
		datasetRelation = strtok(NULL, ",");

		printf("\n %s", buffer);

		ifail = ITEM_create_item(NULL, name, type, "A", &item, &rev);
		errorHandler(ifail);

		ifail = ITEM_save_item(item);
		errorHandler(ifail);

		dataSetCreate(datasetType, datasetRelation, rev);

		//ifail = SA_find_user2(u, &currentUser);
		//errorHandler(ifail);

		//ifail = SA_ask_user_home_folder(currentUser, &home);
		//errorHandler(ifail);

		ifail = FL_insert(folder, item, 999);
		errorHandler(ifail);

		ifail = AOM_save(folder);
		errorHandler(ifail);
 }
	
	ifail = ITK_exit_module(true);
	errorHandler(ifail);

	return 0;
}