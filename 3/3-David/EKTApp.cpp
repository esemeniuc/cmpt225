/*
 * filename: EKTApp.cpp
 * 
 * Description: A file, with a main that tests the other components specified in the Makefile.
 * Creation date: July 8, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

// TODO:
// Put all files into templates.
// Reconfirm whether we should print all translation in a row, or "As our EKTApp reads the English words entered, it finds and retrieves their Klingon translations, then prints them on the computer monitor screen as follows."
// UML Diagram!!!
// Remove debug commenting -- http://i2.kym-cdn.com/photos/images/original/000/128/418/ea0.jpg
// Add more commenting to where it's needed. - Contact me (David) if needed.



#include <iostream>
#include <fstream>
#include "btree.h" 
#include <random> 
#include <ctime> 
#include <algorithm>

int dictLoader(std::string* stringArray, std::string inputFilename )
{
	
	int i = 0;
	std::ifstream inputFile;
	inputFile.open(inputFilename, std::ios::in); //set to read as input mode only
	if (inputFile.is_open()) //check if file is available
	{
		std::string tempString; //temporary holding string to save result
		while(inputFile.eof() == 0) //while not reaching eof
		{
			//getline(inputFile, tempString);
			getline(inputFile, stringArray[i]);
			//std::cout << "Input: " << stringArray[i] << std::endl;
			i++;
		}
	}
	
	
	
	inputFile.close();
	return i;
}


int main(int argc, char* argv[])
{	
	bool displayMode = false;
	if(argc==2){
		if(std::string(argv[1]) == "display"){
			displayMode = true;
		}
	}
	std::string holder[1000];
	int amount = dictLoader(holder,"dataFile.txt");
	//std::cout << "===" << std::endl;
	//for(int i = 0; i<amount;i++){
	//	std::cout << holder[i] << std::endl;
	//}
	//std::cout << "===" << std::endl;
	random_shuffle(&holder[0], &holder[amount]);
	btree* testbtree = new btree();
	for(int i = 0; i<amount;i++){
		testbtree->insert(holder[i]);
	}
	//std::cout << "===" << std::endl;
	//load data into tree
	
	//receive input words from user and store the input into queue until eof is reached
	
	
	//process the queue by popping each element from the queue
	//and calling btree.getDest() to print out the corresponding word pair
	
	//dictLoader("dataFile.txt");
	
	
//	word testword = word("tom2", "bob");
//	word testword2 = word("tom3", "albert");
//	word testword3 = word();
//	word testword4 = word("rob", "");
//
//	if (testword < testword2)
//	{
//		cout << "less" << endl;
//	}
//	else
//	{
//		cout << "greater" << endl;
//	}
//
//	cout << "1: " << (unsigned int)testword.isEmpty() << endl;
//	cout << "2: " << (unsigned int)testword2.isEmpty() << endl;
//	cout << "3: " << (unsigned int)testword3.isEmpty() << endl;
//	cout << "4: " << (unsigned int)testword4.isEmpty() << endl;
	
	/*testbtree->insert("tester:bling");
	testbtree->insert("red:orange");
	testbtree->insert("abra:kadabra");
	testbtree->insert("gray:grey");
	testbtree->insert("grey:gray");
	//std::cout << "OKAY" << std::endl;
	testbtree->search("grey");
	//std::cout<<"GOOD"<<std::endl;
	*/
	if(displayMode){ // Display commenting code.
		testbtree->print();
	}
	else {
		bool switcher = false;
		std::string input;
		while(!std::cin.eof()){
			if(switcher==true){
				std::string result = testbtree->search(input);
				if(result != ""){
					std::cout << result << std::endl;
				}
			}
			std::cin >> input;
			switcher=true;
		}
	}
	delete testbtree;	
	return 0;
}
