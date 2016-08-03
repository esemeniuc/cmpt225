/*
 * filename: testDriver.h/testDriver.cpp
 *
 * Description: A word object that stores a pair of strings
 * Creation date: July 21, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */
//
//#include <cassert>
//#include <iostream>
//#include "testDriver.h"
//#include "word.h"
//#include "btree.h"
//#include "ekt.h"
//
//void testDriver::testAllNonException()
//{
//	wordValidate();
//
//	btreeInsertNormal();
//	btreeInsertDuplicateWord();
//	btree4Valid();
//	btree4Invalid();
//	btree2of4ValidFirst();
//	btreeSearchSorted();
//	btreeSearchUnsorted();
//	btreeSearchNotExists();
//
//	exQueueInsert();
//	exQueueInsertRemove();
//	exQueueExpand();
//	exQueueRandomize();
//
//	ektTestHash();
//	ektInsertNotChained();
//	ektInsertChained();
//	ektNotChainedStdDev();
//	ektChainedStdDev();
//	ektTranslate6Valid();
//	ektTranslate6Invalid();
//	ektTranslate2of6ValidFirst();
//}
//
//void testDriver::throwException()
//{
//	throw(classException("Error, wtf mate?"));
//}
//
//void testDriver::wordValidate()
//{
//	word word1("word id test"); //single argument
//	word word2("test src", "test dest"); //both fields
//
//	assert(word1.getSrc() == "word id test");
//	assert(word2.getDest() == "test dest");
//
//	word word3("test src", "test other dest");
//	assert(word2 == word3);
//}
//
//void testDriver::btreeInsertNormal()
//{
//	btree<word> wordBtree;
////	btree<word> wordBtree = btree<word>();
//	word testWord1 = word("aaa", "bbb");
//	word testWord2 = word("ccc", "ddd");
//
//	nodeDL<word>* status1 = wordBtree.insert(testWord1);
//	nodeDL<word>* status2 = wordBtree.insert(testWord2);
////	std::cout << (unsigned int)status1 << (unsigned int)status2 << std::endl;
////	wordBtree.print(0);
//	assert(status1 != nullptr && status2 != nullptr);
//}
//
//void testDriver::btreeInsertDuplicateWord()
//{
//	btree<word> wordBtree;
////	btree<word> wordBtree = btree<word>();
//	word testWord1 = word("aaa", "bbb");
//	word testWord2 = word("aaa", "ddd");
//	word testWord3 = word("aaa", "bbb");
//
//	nodeDL<word>* status1 = wordBtree.insert(testWord1);
//	nodeDL<word>* status2 = wordBtree.insert(testWord2);
//	nodeDL<word>* status3 = wordBtree.insert(testWord3);
////	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << std::endl;
////	wordBtree.print();
//	assert(status1 != nullptr && status2 == nullptr && status3 == nullptr);
//}
//
//void testDriver::btree4Valid()
//{
//	btree<word> wordBtree;
////	btree<word> wordBtree = btree<word>();
//	word testWord1 = word("word 1", "word 2");
//	word testWord2 = word("word 3", "word 4");
//	word testWord3 = word("word 5", "word 6");
//	word testWord4 = word("word 7", "word 8");
//
//	nodeDL<word>* status1 = wordBtree.insert(testWord1);
//	nodeDL<word>* status2 = wordBtree.insert(testWord2);
//	nodeDL<word>* status3 = wordBtree.insert(testWord3);
//	nodeDL<word>* status4 = wordBtree.insert(testWord4);
////	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
////	wordBtree.print();
//	assert(status1 != nullptr && status2 != nullptr && status3 != nullptr && status4 != nullptr);
//}
//
//void testDriver::btree4Invalid()
//{
//	btree<word> wordBtree;
////	btree<word> wordBtree = btree<word>();
//	word testWord1 = word("word 3", "word 4");
//	word testWord2 = word("word 3", "");
//	word testWord3 = word("word 3");
//	word testWord4 = word("word 3", "word 5");
//
//	nodeDL<word>* status1 = wordBtree.insert(testWord1);
//	nodeDL<word>* status2 = wordBtree.insert(testWord2);
//	nodeDL<word>* status3 = wordBtree.insert(testWord3);
//	nodeDL<word>* status4 = wordBtree.insert(testWord4);
////	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
////	wordBtree.print();
//	assert(status1 != nullptr && status2 == nullptr && status3 == nullptr && status4 == nullptr);
//}
//
//void testDriver::btree2of4ValidFirst()
//{
//	btree<word> wordBtree;
////	btree<word> wordBtree = btree<word>();
//	word testWord1 = word("word 3", "word 4");
//	word testWord2 = word("word 5", "word 6");
//	word testWord3 = word("word 3", "word 6");
//	word testWord4 = word("word 5", "word 4");
//
//	nodeDL<word>* status1 = wordBtree.insert(testWord1);
//	nodeDL<word>* status2 = wordBtree.insert(testWord2);
//	nodeDL<word>* status3 = wordBtree.insert(testWord3);
//	nodeDL<word>* status4 = wordBtree.insert(testWord4);
////	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
////	wordBtree.print();
//	assert(status1 != nullptr && status2 != nullptr && status3 == nullptr && status4 == nullptr);
//}
//
//void testDriver::btreeSearchSorted()
//{
//	btree<word> wordBtree;
////	btree<word> wordBtree = btree<word>();
//	word testWord1 = word("word 1", "word 2");
//	word testWord2 = word("word 3", "word 4");
//	word testWord3 = word("word 5", "word 6");
//	word testWord4 = word("word 7", "word 8");
//
//	wordBtree.insert(testWord1);
//	wordBtree.insert(testWord2);
//	wordBtree.insert(testWord3);
//	wordBtree.insert(testWord4);
////	uint8_t status1 = wordBtree.insert(testWord1);
////	uint8_t status2 = wordBtree.insert(testWord2);
////	uint8_t status3 = wordBtree.insert(testWord3);
////	uint8_t status4 = wordBtree.insert(testWord4);
////	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
////	wordBtree.print();
//
//	word searchWord = word("word 5");
//	word searchResult = wordBtree.search(&searchWord);
////	searchResult.print();
//	assert(searchWord.getSrc() == searchResult.getSrc());
//
////	std::cout << "Src1: " << searchWord.getSrc() << ", Src2: " << searchResult.getSrc() << ", Dest1: " << searchWord.getDest() << ", Dest2: " << searchResult.getDest() << std::endl;
////	wordBtree.print();
//	assert(testWord3.getSrc() == searchResult.getSrc() && testWord3.getDest() == searchResult.getDest());
//}
//
//void testDriver::btreeSearchUnsorted()
//{
//	btree<word> wordBtree;
////	btree<word> wordBtree = btree<word>();
//	word testWord1 = word("word 5", "word 6");
//	word testWord2 = word("word 3", "word 4");
//	word testWord3 = word("word 1", "word 2");
//	word testWord4 = word("word 7", "word 8");
//
//	wordBtree.insert(testWord1);
//	wordBtree.insert(testWord2);
//	wordBtree.insert(testWord3);
//	wordBtree.insert(testWord4);
////	uint8_t status1 = wordBtree.insert(testWord1);
////	uint8_t status2 = wordBtree.insert(testWord2);
////	uint8_t status3 = wordBtree.insert(testWord3);
////	uint8_t status4 = wordBtree.insert(testWord4);
////	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
////	wordBtree.print();
//
//	word searchWord = word("word 3");
//	word searchResult = wordBtree.search(&searchWord);
////	searchResult.print();
//	assert(searchWord.getSrc() == searchResult.getSrc());
//
////	std::cout << "Src1: " << searchWord.getSrc() << ", Src2: " << searchResult.getSrc() << ", Dest1: " << searchWord.getDest() << ", Dest2: " << searchResult.getDest() << std::endl;
////	wordBtree.print();
//	assert(testWord2.getSrc() == searchResult.getSrc() && testWord2.getDest() == searchResult.getDest());
//}
//
//
//void testDriver::btreeSearchNotExists()
//{
//	btree<word> wordBtree;
////	btree<word> wordBtree = btree<word>();
//	word testWord1 = word("word 1", "word 2");
//	word testWord2 = word("word 3", "word 4");
//	word testWord3 = word("word 5", "word 6");
//	word testWord4 = word("word 7", "word 8");
//
//	wordBtree.insert(testWord1);
//	wordBtree.insert(testWord2);
//	wordBtree.insert(testWord3);
//	wordBtree.insert(testWord4);
////	uint8_t status1 = wordBtree.insert(testWord1);
////	uint8_t status2 = wordBtree.insert(testWord2);
////	uint8_t status3 = wordBtree.insert(testWord3);
////	uint8_t status4 = wordBtree.insert(testWord4);
////	std::cout << (unsigned int)status1 << (unsigned int)status2 << (unsigned int)status3 << (unsigned int)status4 << std::endl;
////	wordBtree.print();
//
//	word searchWord = word("non existent");
//	word searchResult = wordBtree.search(&searchWord);
////	searchResult.print();
//	assert(searchResult.getString() == ":");
//}
//
//void testDriver::exQueueInsert()
//{
//	exQueue testQueue;
//	for(int i = 0; i < 10; i++)
//	{
//		testQueue.push(std::to_string(i));
//
//		assert(testQueue.pop() == std::to_string(i));
//	}
//
//	assert(testQueue.getSize() == 0);
//}
//
//void testDriver::exQueueInsertRemove()
//{
//	exQueue testQueue;
//	for(int i = 0; i < 10; i++)
//	{
//		testQueue.push(std::to_string(i));
//	}
//	assert(testQueue.getSize() == 10);
//
//	for(int i = 0; i < 9; i++) //miss 9 intentionally
//	{
//		assert(testQueue.pop() == std::to_string(i));
//	}
//	assert(testQueue.getSize() == 1);
//
//	for(int i = 10; i < 20; i++)
//	{
//		testQueue.push(std::to_string(i));
//	}
//	assert(testQueue.getSize() == 11);
//
//	for(int i = 9; i < 20; i++) //catch 9 now
//	{
//		assert(testQueue.pop() == std::to_string(i));
//	}
//	assert(testQueue.getSize() == 0);
//}
//
//void testDriver::exQueueExpand()
//{
//	exQueue testQueue;
//	for(int i = 0; i < 200; i++)
//	{
//		testQueue.push(std::to_string(i));
//	}
//	assert(testQueue.getSize() == 200);
//
//	for(int i = 0; i < 199; i++) //miss 199 intentionally
//	{
//		assert(testQueue.pop() == std::to_string(i));
//	}
//	assert(testQueue.getSize() == 1);
//
//	for(int i = 200; i < 500; i++)
//	{
//		testQueue.push(std::to_string(i));
//	}
//	assert(testQueue.getSize() == 301);
//
//	for(int i = 199; i < 500; i++) //catch 199 now
//	{
//		assert(testQueue.pop() == std::to_string(i));
//	}
//	assert(testQueue.getSize() == 0);
//}
//
//void testDriver::exQueueRandomize()
//{
//	exQueue testQueue;
//	for(int i = 0; i < 10; i++)
//	{
//		testQueue.push(std::to_string(i));
//	}
////	std::cout << "Before:\n";
////	testQueue.print();
//	testQueue.randomize();
////	std::cout << "\nAfter:\n";
////	testQueue.print();
//
//	std::string scrambled;
//	std::string nonScrambled;
//
//	for(int i = 0; i < 10; i++)
//	{
//		scrambled += testQueue.pop();
//		nonScrambled += std::to_string(i);
//	}
////	std::cout << "diff: " << scrambled.compare(nonScrambled);
//	assert(scrambled != nonScrambled);
//}
//
//void testDriver::ektTestHash()
//{
//	std::string testString1 = "abc";
//	std::string testString2 = "acb";
//	std::string testString3 = "bac";
//	std::string testString4 = "bca";
//	std::string testString5 = "cab";
//	std::string testString6 = "cba";
//
//	ekt testEKT;
//	testEKT.modulus = 13;
//
////	size_t hashString1 = ekt::hashStringStatic(testString1, modulus);
//	size_t hashString1 = testEKT.hashString(testString1);
//	size_t hashString2 = testEKT.hashString(testString2);
//	size_t hashString3 = testEKT.hashString(testString3);
//	size_t hashString4 = testEKT.hashString(testString4);
//	size_t hashString5 = testEKT.hashString(testString5);
//	size_t hashString6 = testEKT.hashString(testString6);
//
////	std::cout << "#: Result\n" << "1: " << hashString1 << "\n2: " << hashString2 << "\n3: " << hashString3 << "\n4: " << hashString4 << "\n5: " << hashString5 << "\n6: " << hashString6 << std::endl;
//
//	assert(hashString1 != hashString2);
//	assert(hashString1 != hashString3);
//	assert(hashString1 != hashString4);
//	assert(hashString1 != hashString5);
//	assert(hashString1 != hashString6);
//
//	assert(hashString2 != hashString3);
//	assert(hashString2 != hashString4);
//	assert(hashString2 != hashString5);
//	assert(hashString2 != hashString6);
//
//	assert(hashString3 != hashString4);
//	assert(hashString3 != hashString5);
//	assert(hashString3 != hashString6);
//
//	assert(hashString4 != hashString5);
//	assert(hashString4 != hashString6);
//
//	assert(hashString5 != hashString6);
//}
//
//void testDriver::ektInsertNotChained()
//{
//	//all are on unique hash indexes, no collisions
//	std::string testString1 = "abc";
//	std::string testString2 = "acb";
//	std::string testString3 = "bac";
//	std::string testString4 = "bca";
//	std::string testString5 = "cab";
//	std::string testString6 = "cba";
//
//	ekt testEKT;
//	//bypass loadFromFile stuff
//	testEKT.modulus = 13;
//	testEKT.wordCount = 6;
//	testEKT.wordTable = new nodeSL<word>*[testEKT.modulus](); //() means initialize to NULL
//
//	size_t hashIndex1 = testEKT.hashString(testString1);
//	size_t hashIndex2 = testEKT.hashString(testString2);
//	size_t hashIndex3 = testEKT.hashString(testString3);
//	size_t hashIndex4 = testEKT.hashString(testString4);
//	size_t hashIndex5 = testEKT.hashString(testString5);
//	size_t hashIndex6 = testEKT.hashString(testString6);
//
////	std::cout << "#: Result\n" << "1: " << hashIndex1 << "\n2: " << hashIndex2 << "\n3: " << hashIndex3 << "\n4: " << hashIndex4 << "\n5: " << hashIndex5 << "\n6: " << hashIndex6 << std::endl;
//
//	word testWord1 = word(testString1);
//	word testWord2 = word(testString2);
//	word testWord3 = word(testString3);
//	word testWord4 = word(testString4);
//	word testWord5 = word(testString5);
//	word testWord6 = word(testString6);
//
//	testEKT.insert(testWord1);
//	testEKT.insert(testWord2);
//	testEKT.insert(testWord3);
//	testEKT.insert(testWord4);
//	testEKT.insert(testWord5);
//	testEKT.insert(testWord6);
//
//	assert(*(testEKT.wordTable[hashIndex1]->data) == testWord1);
//	assert(*(testEKT.wordTable[hashIndex2]->data) == testWord2);
//	assert(*(testEKT.wordTable[hashIndex3]->data) == testWord3);
//	assert(*(testEKT.wordTable[hashIndex4]->data) == testWord4);
//	assert(*(testEKT.wordTable[hashIndex5]->data) == testWord5);
//	assert(*(testEKT.wordTable[hashIndex6]->data) == testWord6);
//}
//
//void testDriver::ektInsertChained()
//{
//	//3 will collide
//	std::string testString1 = "abc";
//	std::string testString2 = "acb";
//	std::string testString3 = "bac";
//	std::string testString4 = "bca";
//	std::string testString5 = "cab";
//	std::string testString6 = "cba";
//
//	ekt testEKT;
//	//bypass loadFromFile stuff
//	testEKT.modulus = 6;
//	testEKT.wordTable = new nodeSL<word>*[testEKT.modulus](); //() means initialize to NULL
//
//	size_t hashIndex1 = testEKT.hashString(testString1);
//	size_t hashIndex2 = testEKT.hashString(testString2);
//	size_t hashIndex3 = testEKT.hashString(testString3);
//	size_t hashIndex4 = testEKT.hashString(testString4);
//	size_t hashIndex5 = testEKT.hashString(testString5);
//	size_t hashIndex6 = testEKT.hashString(testString6);
//
////	std::cout << "#: Result\n" << "1: " << hashIndex1 << "\n2: " << hashIndex2 << "\n3: " << hashIndex3 << "\n4: " << hashIndex4 << "\n5: " << hashIndex5 << "\n6: " << hashIndex6 << std::endl;
//
//	word testWord1 = word(testString1);
//	word testWord2 = word(testString2);
//	word testWord3 = word(testString3);
//	word testWord4 = word(testString4);
//	word testWord5 = word(testString5);
//	word testWord6 = word(testString6);
//
//	testEKT.insert(testWord1);
//	testEKT.insert(testWord2);
//	testEKT.insert(testWord3);
//	testEKT.insert(testWord4);
//	testEKT.insert(testWord5);
//	testEKT.insert(testWord6);
//
//	//assumes djb2 algorithm with the following indexes:
//	/*1st: 3
//	2nd: 5
//	3rd: 3
//	4th: 1
//	5th: 5
//	6th: 1*/
//	assert(*(testEKT.wordTable[hashIndex1]->next->data) == testWord1);
//	assert(*(testEKT.wordTable[hashIndex2]->next->data) == testWord2);
//	assert(*(testEKT.wordTable[hashIndex3]->data) == testWord3);
//	assert(*(testEKT.wordTable[hashIndex4]->next->data) == testWord4);
//	assert(*(testEKT.wordTable[hashIndex5]->data) == testWord5);
//	assert(*(testEKT.wordTable[hashIndex6]->data) == testWord6);
//}
//
//void testDriver::ektNotChainedStdDev()
//{
//	//all are on unique hash indexes, no collisions
//	std::string testString1 = "abc";
//	std::string testString2 = "acb";
//	std::string testString3 = "bac";
//	std::string testString4 = "bca";
//	std::string testString5 = "cab";
//	std::string testString6 = "cba";
//
//	ekt testEKT;
//	//bypass loadFromFile stuff
//	testEKT.modulus = 13;
//	testEKT.wordTable = new nodeSL<word>*[testEKT.modulus](); //() means initialize to NULL
//
//	word testWord1 = word(testString1);
//	word testWord2 = word(testString2);
//	word testWord3 = word(testString3);
//	word testWord4 = word(testString4);
//	word testWord5 = word(testString5);
//	word testWord6 = word(testString6);
//
//	testEKT.insert(testWord1);
//	testEKT.insert(testWord2);
//	testEKT.insert(testWord3);
//	testEKT.insert(testWord4);
//	testEKT.insert(testWord5);
//	testEKT.insert(testWord6);
//
//	double stdDev = testEKT.getStdDev();
////	std::cout << "Stddev = " << stdDev << std::endl;
//	assert(stdDev <= 0.5);
//}
//
//void testDriver::ektChainedStdDev()
//{
//	//all are on unique hash indexes, no collisions
//	std::string testString1 = "abc";
//	std::string testString2 = "acb";
//	std::string testString3 = "bac";
//	std::string testString4 = "bca";
//	std::string testString5 = "cab";
//	std::string testString6 = "cba";
//
//	ekt testEKT;
//	//bypass loadFromFile stuff
//	testEKT.modulus = 6;
//	testEKT.wordTable = new nodeSL<word>*[testEKT.modulus](); //() means initialize to NULL
//
//	word testWord1 = word(testString1);
//	word testWord2 = word(testString2);
//	word testWord3 = word(testString3);
//	word testWord4 = word(testString4);
//	word testWord5 = word(testString5);
//	word testWord6 = word(testString6);
//
//	testEKT.insert(testWord1);
//	testEKT.insert(testWord2);
//	testEKT.insert(testWord3);
//	testEKT.insert(testWord4);
//	testEKT.insert(testWord5);
//	testEKT.insert(testWord6);
//
//	double stdDev = testEKT.getStdDev();
////	std::cout << "Stddev = " << stdDev << std::endl;
//	assert(stdDev >= 0.9 && stdDev <= 1.1);
//}
//
//void testDriver::ektTranslate6Valid()
//{
//	ekt testEKT;
//	//bypass loadFromFile stuff
//	testEKT.modulus = 2;
//	testEKT.wordTable = new nodeSL<word>*[testEKT.modulus](); //() means initialize to NULL
//
//	word testWord1 = word("stop", "mevyap");
//	word testWord2 = word("food", "Soj");
//	word testWord3 = word("win", "Qap");
//	word testWord4 = word("today", "jajvam");
//	word testWord5 = word("face", "qab");
//	word testWord6 = word("roof", "beb");
//
//	testEKT.insert(testWord1);
//	testEKT.insert(testWord2);
//	testEKT.insert(testWord3);
//	testEKT.insert(testWord4);
//	testEKT.insert(testWord5);
//	testEKT.insert(testWord6);
//
//	word* word1 = testEKT.getWord(word("stop"));
//	word* word2 = testEKT.getWord(word("food"));
//	word* word3 = testEKT.getWord(word("win"));
//	word* word4 = testEKT.getWord(word("today"));
//	word* word5 = testEKT.getWord(word("face"));
//	word* word6 = testEKT.getWord(word("roof"));
//
//	assert(word1->getString() == "stop:mevyap");
//	assert(word2->getString() == "food:Soj");
//	assert(word3->getString() == "win:Qap");
//	assert(word4->getString() == "today:jajvam");
//	assert(word5->getString() == "face:qab");
//	assert(word6->getString() == "roof:beb");
//}
//
//void testDriver::ektTranslate6Invalid()
//{
//	ekt testEKT;
//	//bypass loadFromFile stuff
//	testEKT.modulus = 2;
//	testEKT.wordTable = new nodeSL<word>*[testEKT.modulus](); //() means initialize to NULL
//
//	word testWord1 = word("stop", "mevyap");
//	word testWord2 = word("food", "Soj");
//	word testWord3 = word("win", "Qap");
//	word testWord4 = word("today", "jajvam");
//	word testWord5 = word("face", "qab");
//	word testWord6 = word("roof", "beb");
//
//	testEKT.insert(testWord1);
//	testEKT.insert(testWord2);
//	testEKT.insert(testWord3);
//	testEKT.insert(testWord4);
//	testEKT.insert(testWord5);
//	testEKT.insert(testWord6);
//
//	word* word1 = testEKT.getWord(word("stoOp"));
//	word* word2 = testEKT.getWord(word("fUd"));
//	word* word3 = testEKT.getWord(word("vin"));
//	word* word4 = testEKT.getWord(word("tooday"));
//	word* word5 = testEKT.getWord(word("2face"));
//	word* word6 = testEKT.getWord(word("roofr"));
//
//	assert(word1 == NULL);
//	assert(word2 == NULL);
//	assert(word3 == NULL);
//	assert(word4 == NULL);
//	assert(word5 == NULL);
//	assert(word6 == NULL);
//}
//
//void testDriver::ektTranslate2of6ValidFirst()
//{
//	ekt testEKT;
//	//bypass loadFromFile stuff
//	testEKT.modulus = 2;
//	testEKT.wordTable = new nodeSL<word>*[testEKT.modulus](); //() means initialize to NULL
//
//	word testWord1 = word("stop", "mevyap");
//	word testWord2 = word("food", "Soj");
//	word testWord3 = word("win", "Qap");
//	word testWord4 = word("today", "jajvam");
//	word testWord5 = word("face", "qab");
//	word testWord6 = word("roof", "beb");
//
//	testEKT.insert(testWord1);
//	testEKT.insert(testWord2);
//	testEKT.insert(testWord3);
//	testEKT.insert(testWord4);
//	testEKT.insert(testWord5);
//	testEKT.insert(testWord6);
//
//	word* word1 = testEKT.getWord(word("stop"));
//	word* word2 = testEKT.getWord(word("food"));
//	word* word3 = testEKT.getWord(word("vin"));
//	word* word4 = testEKT.getWord(word("tooday"));
//	word* word5 = testEKT.getWord(word("2face"));
//	word* word6 = testEKT.getWord(word("roofr"));
//
//	assert(word1->getString() == "stop:mevyap");
//	assert(word2->getString() == "food:Soj");
//	assert(word3 == NULL);
//	assert(word4 == NULL);
//	assert(word5 == NULL);
//	assert(word6 == NULL);
//}