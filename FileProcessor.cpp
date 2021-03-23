/*
Stephanie Munday
2343625
smunday@chapman.edu
CPSC-350-08
Assignment 4
*/

//Cpp file for FileProcessor

#include "FileProcessor.h"

FileProcessor::FileProcessor() {
  //constructor
}

FileProcessor::~FileProcessor() {
  //destructor
}

//takes a file as input, calls DNA computations and prints to output file
void FileProcessor::processFile(std::string fileIn) {
  // create and/or open files to read/write to
  std::ifstream readFile;
  readFile.open(fileIn);

  std::ofstream writeFile;
  std::string fileOut = "dnaoutput.txt";
  writeFile.open(fileOut);

  std::string toConvert = "";
  std::string toWrite = "";

  DNAComplement dna;
  string comp = "";
  string revComp = "";

  if (readFile.is_open()) { // checks to see if file exists/is open
    writeFile << "DNA Complement: " << endl;
    while (getline(readFile, toConvert)) { // stores the line in the string variable toConvert, which is used by DNA Complement
      comp = dna.Complement(toConvert);
      writeFile << comp;
      revComp += dna.RevComplement(toConvert);
    }
    writeFile << endl;
    writeFile << "DNA Reverse Complement: " << endl;
    writeFile << revComp;
    readFile.close();
  }
  else { // in the case that the file doesn't exist/isn't open
    toWrite = "The input file name you entered does not exist. Try again.";
    writeFile << toWrite;
  }
  writeFile.close();
}
