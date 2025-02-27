#include <cstddef>
#include "Word.hpp"
#include "DictionaryList.hpp"
#include <exception>


std::size_t hashFunc(const Word& word);

class HashTable
{
public:
  void add(const Word& word);
  void increaseCounter(const std::string& word);
  std::size_t count(const std::string& word);
  void top();
  void getFromFile(const std::string& fileName);
  void remove(const Word& word);

  static const size_t minValue = int('A') + int('0');
  static const size_t maxValue = int('z') + int('z');
  static const size_t tableSize = maxValue - minValue;
private:
  DictionaryList<Word> hashTable[tableSize];
};

