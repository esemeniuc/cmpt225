/*
 * filename: EKTApp.cpp
 *
 * Description: An english klingon translator class
 * Creation date: July 31, 2016
 * Author: Eric Semeniuc, David Magaril
 * ID: esemeniu_dmagaril
 */

#ifndef INC_4P2_EKT_H
#define INC_4P2_EKT_H

#include "btree.h"
#include "exQueue.h"
#include "word.h"

class ekt
{
private:
	
public:
	void dictLoader(std::string inputFilename, btree<word>* inputBtree);
	
	void userInputLoader(exQueue* inputQueue);
};

#endif //INC_4P2_EKT_H
