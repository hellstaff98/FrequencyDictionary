
#include <iostream>
#include <string>
#include "DictionaryList.hpp"
#include "Word.hpp"
#include "HashTable.hpp"


int main()
{
  std::cout << "Enter name of the file with data\n";
  std::string fileName = "";
  std::cin >> fileName;
  HashTable hashTable;
  std::cout << hashTable.tableSize << "\n";
  try
  {
    hashTable.getFromFile(fileName);
    hashTable.top();
  }
  catch (const std::exception& ex)
  {
    std::cerr << ex.what() << "\n";
  }

  return 0;
}

