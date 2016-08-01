//
// Created by eric on 21/07/16.
//

#include <cassert>
#include <iostream>
#include "testDriver.h"
#include "word.h"
#include "btree.h"
#include "exQueue.h"

void testDriver::testAllNonException()
{
	wordValidate();
	
	btreeInsertNormal();
	btreeInsertDuplicateWord();
	btree4Valid();
	btree4Invalid();
	btree2of4ValidFirst();
	btreeSearchSorted();
	btreeSearchUnsorted();
	btreeSearchNotExists();
	
	exQueueInsert();
	exQueueInsertRemove();
	exQueueExpand();
	exQueueRandomize();
}

void testDriver::throwException()
{
	throw(classException("Error, wtf mate?"));
}

void testDriver::wordValidate()
{
	word word1("word id test"); //single argument
	word word2("test src", "test dest"); //both fields
	
	assert(word1.getSrc() == "word id test");
	assert(word2.getDest() == "test dest");
	
	word word3("test src", "test other dest");
	assert(word2 == word3);
}

void testDriver::btreeInsertNormal()
{
	btree<word> wordBtree;
//	btree<word> wordBtree = btree<word>();
	word testWord1 = word("aaa", "bbb");
	word testWord2 = word("ccc", "ddd");
	
	uint8_t status1 = wordBtree.insert(testWord1);
	uint8_t status2 = wordBtree.insert(testWord2);
//	std::cout << (unsigned int)status1 << (unsigned int)status2 << std::endl;
//	wordBtree.print(0);
	assert(status1 == 0 && status2 == 0);
}

void testDriver::btreeInsertDuplicateWord()
{
	btree<word> wordBtree;
//	btree<word> wordBtree = btree<word>();
	word testWord1 = word("aaa", "bbb");
	word testWord2 = word("aaa", "ddd");
	word testWord3 = word("aaa", "bbb");
	
	uint8_t status1 = wordBtree.insert(testWord1);
	uint8_t status2 = wordBtree.insert(testWord2);
	uint8_t status3 = wordBtree.insert(testWord3);
//	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << std::endl;
//	wordBtree.print();
	assert(status1 == 0 && status2 == 1 && status3 == 1);
}

void testDriver::btree4Valid()
{
	btree<word> wordBtree;
//	btree<word> wordBtree = btree<word>();
	word testWord1 = word("word 1", "word 2");
	word testWord2 = word("word 3", "word 4");
	word testWord3 = word("word 5", "word 6");
	word testWord4 = word("word 7", "word 8");
	
	uint8_t status1 = wordBtree.insert(testWord1);
	uint8_t status2 = wordBtree.insert(testWord2);
	uint8_t status3 = wordBtree.insert(testWord3);
	uint8_t status4 = wordBtree.insert(testWord4);
//	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
//	wordBtree.print();
	assert(status1 == 0 && status2 == 0 && status3 == 0 && status4 == 0);
}

void testDriver::btree4Invalid()
{
	btree<word> wordBtree;
//	btree<word> wordBtree = btree<word>();
	word testWord1 = word("word 3", "word 4");
	word testWord2 = word("word 3", "");
	word testWord3 = word("word 3");
	word testWord4 = word("word 3", "word 5");
	
	uint8_t status1 = wordBtree.insert(testWord1);
	uint8_t status2 = wordBtree.insert(testWord2);
	uint8_t status3 = wordBtree.insert(testWord3);
	uint8_t status4 = wordBtree.insert(testWord4);
//	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
//	wordBtree.print();
	assert(status1 == 0 && status2 == 1 && status3 == 1 && status4 == 1);
}

void testDriver::btree2of4ValidFirst()
{
	btree<word> wordBtree;
//	btree<word> wordBtree = btree<word>();
	word testWord1 = word("word 3", "word 4");
	word testWord2 = word("word 5", "word 6");
	word testWord3 = word("word 3", "word 6");
	word testWord4 = word("word 5", "word 4");
	
	uint8_t status1 = wordBtree.insert(testWord1);
	uint8_t status2 = wordBtree.insert(testWord2);
	uint8_t status3 = wordBtree.insert(testWord3);
	uint8_t status4 = wordBtree.insert(testWord4);
//	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
//	wordBtree.print();
	assert(status1 == 0 && status2 == 0 && status3 == 1 && status4 == 1);
}

void testDriver::btreeSearchSorted()
{
	btree<word> wordBtree;
//	btree<word> wordBtree = btree<word>();
	word testWord1 = word("word 1", "word 2");
	word testWord2 = word("word 3", "word 4");
	word testWord3 = word("word 5", "word 6");
	word testWord4 = word("word 7", "word 8");
	
	wordBtree.insert(testWord1);
	wordBtree.insert(testWord2);
	wordBtree.insert(testWord3);
	wordBtree.insert(testWord4);
//	uint8_t status1 = wordBtree.insert(testWord1);
//	uint8_t status2 = wordBtree.insert(testWord2);
//	uint8_t status3 = wordBtree.insert(testWord3);
//	uint8_t status4 = wordBtree.insert(testWord4);
//	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
//	wordBtree.print();
	
	word searchWord = word("word 5");
	word searchResult = wordBtree.search(&searchWord);
//	searchResult.print();
	assert(searchWord.getSrc() == searchResult.getSrc());

//	std::cout << "Src1: " << searchWord.getSrc() << ", Src2: " << searchResult.getSrc() << ", Dest1: " << searchWord.getDest() << ", Dest2: " << searchResult.getDest() << std::endl;
//	wordBtree.print();
	assert(testWord3.getSrc() == searchResult.getSrc() && testWord3.getDest() == searchResult.getDest());
}

void testDriver::btreeSearchUnsorted()
{
	btree<word> wordBtree;
//	btree<word> wordBtree = btree<word>();
	word testWord1 = word("word 5", "word 6");
	word testWord2 = word("word 3", "word 4");
	word testWord3 = word("word 1", "word 2");
	word testWord4 = word("word 7", "word 8");
	
	wordBtree.insert(testWord1);
	wordBtree.insert(testWord2);
	wordBtree.insert(testWord3);
	wordBtree.insert(testWord4);
//	uint8_t status1 = wordBtree.insert(testWord1);
//	uint8_t status2 = wordBtree.insert(testWord2);
//	uint8_t status3 = wordBtree.insert(testWord3);
//	uint8_t status4 = wordBtree.insert(testWord4);
//	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
//	wordBtree.print();
	
	word searchWord = word("word 3");
	word searchResult = wordBtree.search(&searchWord);
//	searchResult.print();
	assert(searchWord.getSrc() == searchResult.getSrc());

//	std::cout << "Src1: " << searchWord.getSrc() << ", Src2: " << searchResult.getSrc() << ", Dest1: " << searchWord.getDest() << ", Dest2: " << searchResult.getDest() << std::endl;
//	wordBtree.print();
	assert(testWord2.getSrc() == searchResult.getSrc() && testWord2.getDest() == searchResult.getDest());
}


void testDriver::btreeSearchNotExists()
{
	btree<word> wordBtree;
//	btree<word> wordBtree = btree<word>();
	word testWord1 = word("word 1", "word 2");
	word testWord2 = word("word 3", "word 4");
	word testWord3 = word("word 5", "word 6");
	word testWord4 = word("word 7", "word 8");
	
	wordBtree.insert(testWord1);
	wordBtree.insert(testWord2);
	wordBtree.insert(testWord3);
	wordBtree.insert(testWord4);
//	uint8_t status1 = wordBtree.insert(testWord1);
//	uint8_t status2 = wordBtree.insert(testWord2);
//	uint8_t status3 = wordBtree.insert(testWord3);
//	uint8_t status4 = wordBtree.insert(testWord4);
//	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
//	wordBtree.print();
	
	word searchWord = word("non existent");
	word searchResult = wordBtree.search(&searchWord);
//	searchResult.print();
	assert(searchResult.getString() == ":");
}

void testDriver::exQueueInsert()
{
	exQueue testQueue;
	for(int i = 0; i < 10; i++)
	{
		testQueue.push(std::to_string(i));
		
		assert(testQueue.pop() == std::to_string(i));
	}
	
	assert(testQueue.getSize() == 0);
}

void testDriver::exQueueInsertRemove()
{
	exQueue testQueue;
	for(int i = 0; i < 10; i++)
	{
		testQueue.push(std::to_string(i));
	}
	assert(testQueue.getSize() == 10);
	
	for(int i = 0; i < 9; i++) //miss 9 intentionally
	{
		assert(testQueue.pop() == std::to_string(i));
	}
	assert(testQueue.getSize() == 1);
	
	for(int i = 10; i < 20; i++)
	{
		testQueue.push(std::to_string(i));
	}
	assert(testQueue.getSize() == 11);
	
	for(int i = 9; i < 20; i++) //catch 9 now
	{
		assert(testQueue.pop() == std::to_string(i));
	}
	assert(testQueue.getSize() == 0);
}

void testDriver::exQueueExpand()
{
	exQueue testQueue;
	for(int i = 0; i < 200; i++)
	{
		testQueue.push(std::to_string(i));
	}
	assert(testQueue.getSize() == 200);
	
	for(int i = 0; i < 199; i++) //miss 199 intentionally
	{
		assert(testQueue.pop() == std::to_string(i));
	}
	assert(testQueue.getSize() == 1);
	
	for(int i = 200; i < 500; i++)
	{
		testQueue.push(std::to_string(i));
	}
	assert(testQueue.getSize() == 301);
	
	for(int i = 199; i < 500; i++) //catch 199 now
	{
		assert(testQueue.pop() == std::to_string(i));
	}
	assert(testQueue.getSize() == 0);
}

void testDriver::exQueueRandomize()
{
	exQueue testQueue;
	for(int i = 0; i < 10; i++)
	{
		testQueue.push(std::to_string(i));
	}
//	std::cout << "Before:\n";
//	testQueue.print();
	testQueue.randomize();
//	std::cout << "\nAfter:\n";
//	testQueue.print();
	
	std::string scrambled;
	std::string nonScrambled;
	
	for(int i = 0; i < 10; i++)
	{
		scrambled += testQueue.pop();
		nonScrambled += std::to_string(i);
	}
//	std::cout << "diff: " << scrambled.compare(nonScrambled);
	assert(scrambled != nonScrambled);
}