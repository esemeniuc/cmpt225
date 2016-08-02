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
	void btreeSearchSorted();
	void btreeSearchUnsorted();
	void btreeSearchNotExists();
	
	//queue tests
	void exQueueInsert();
	void exQueueInsertRemove();
	void exQueueExpand();
	void exQueueRandomize();
	
	//ekt tests
	//note make sure "#define private public" is on in ekt.h
	void ektTestHash();
	void ektInsertNotChained();
	void ektInsertChained();
	void ektNotChainedStdDev();
	void ektChainedStdDev();
	void ektTranslate6Valid();
	void ektTranslate6Invalid();
	void ektTranslate2of6ValidFirst();
};

#endif //INC_4P2_TESTDRIVER_H
