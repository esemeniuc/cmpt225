//
// Created by eric on 31/07/16.
//

#ifndef INC_4P2_TESTDRIVER_H
#define INC_4P2_TESTDRIVER_H


class testDriver
{
public:
	//general tests
	void testAllNonException();
	
	//exception tests
	void throwException();
	
	//word tests
	void wordValidate();
	
	//btree tests
	void btreeInsertNormal();
	void btreeInsertDuplicateWord();
	void btree4Valid();
	void btree4Invalid();
	void btree2of4ValidFirst();
	void btreeSearch();
	void btreeSearchNotExists();
	
	
	//queue tests
	void exQueueRandomize();
};

#endif //INC_4P2_TESTDRIVER_H
