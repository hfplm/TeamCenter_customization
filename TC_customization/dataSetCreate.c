#include"ITK_Header.h"

tag_t dataSetType, createdDataset, relation_type, relation;

int dataSetCreate(char* datasetType, char* datasetRelation, tag_t rev) {

	ifail = AE_find_datasettype2(datasetType, &dataSetType);
	errorHandler(ifail);

	ifail = AE_create_dataset_with_id(dataSetType, "sample", " ", "0", "0", &createdDataset);
	errorHandler(ifail);

	ifail = AE_save_myself(createdDataset);
	errorHandler(ifail);

	ifail = GRM_find_relation_type(datasetRelation, &relation_type);
	errorHandler(ifail);

	ifail = GRM_create_relation(rev, createdDataset, relation_type, NULLTAG, &relation);
	errorHandler(ifail);

	ifail = GRM_save_relation(relation);
	errorHandler(ifail);

}