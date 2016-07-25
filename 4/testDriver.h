//
// Created by eric on 21/07/16.
//

#ifndef INC_4_TESTDRIVER_H
#define INC_4_TESTDRIVER_H

class testDriver
{
public:
	//general tests
	void testAllNonException();
	
	//exception tests
	void throwException();
	void studentThrowException();
	void universityThrowException();
	
	//student tests
	void studentValidate();
	
	//university tests
	void universityValidate();
	
	//btree tests
	void btreeInsertNormal();
	void btreeInsertDuplicateName();
	void btreeInsertDuplicateID();
	void btree4Valid();
	void btree4Invalid();
	void btree2of4ValidFirst();
	void btree2of4ValidMiddle();
	void btreeSearchExistsID();
	void btreeSearchExistsLName();
	void btreeSearchNotExistsID();
	void btreeSearchNotExistsLName();
	
};


#endif //INC_4_TESTDRIVER_H
