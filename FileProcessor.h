/*
Stephanie Munday
2343625
smunday@chapman.edu
CPSC-350-08
Assignment 4
*/

//Header file for FileProcessor

#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include <string>
#include <iostream>
#include <fstream>
#include "RPNCalc.h"
#include "DNAComplement.h"

class FileProcessor {
  public:
    FileProcessor(); //constructor
    ~FileProcessor(); //destructor
    void processFile(std::string fileIn); //takes a file as input, calls DNA computations and prints to output file
};

#endif
