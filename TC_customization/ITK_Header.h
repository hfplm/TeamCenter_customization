#include<stdio.h>
#include<conio.h>
#include<tc/tc_startup.h>
#include<tcinit/tcinit.h>
#include<tc/emh.h>
#include<tccore/item.h>
#include<sa/user.h>
#include<tc/folder.h>
#include<tccore/aom.h>
#include<ae/dataset.h>
#include<ae/datasettype.h>
#include<tccore/grm.h>
#include<fclasses/tc_string.h>




int ifail;
tag_t folder;
int errorHandler(int ifail);
int createFolder(char* name, char* user);
int dataSetCreate(char* datasetType, char* datasetRelation, tag_t rev);
