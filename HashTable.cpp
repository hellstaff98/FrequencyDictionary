#include <exception>
#include <string>
#include <fstream>
#include <cstring>
#include "HashTable.hpp"

std::size_t hashFunc(const Word& word)
{
    if (word.getWord().size() == 1)
    {
      return 2 * std::size_t(word.getWord()[0]);
    }
    return std::size_t(word.getWord()[0]) + std::size_t(word.getWord()[1]);
}

void HashTable::add(const Word& word)
{
  hashTable[hashFunc(word) - minValue].insertToEnd(word);
}

void HashTable::increaseCounter(const std::string& word)
{
  DictionaryList<Word>& line = hashTable[hashFunc(word) - minValue];
  Word* neededWord = line.search(word);
  if (!neededWord)
  {
    add(Word(word));
  }
  else
  {
    neededWord->increaseAmount();
  }
}

std::size_t HashTable::count(const std::string& word)
{
  DictionaryList<Word>& line = hashTable[hashFunc(word) - minValue];
  Word* neededWord = line.search(word);
  if (!neededWord)
  {
    throw std::logic_error("Word doesn't exist");
  }
  return neededWord->getAmount();
}

void HashTable::top()
{
  Word firstMax("");
  Word secondMax("");
  Word thirdMax("");
  for (std::size_t i = 0; i < tableSize; ++i)
  {
    DictionaryList<Word>& line = hashTable[i];
    Word maxFromLine = line.maxValue();

    if (maxFromLine > firstMax)
    {
      thirdMax = secondMax;
      secondMax = firstMax;
      firstMax = maxFromLine;

    }
    else if (maxFromLine > secondMax)
    {
      thirdMax = secondMax;
      secondMax = maxFromLine;
    }
    else if (maxFromLine > thirdMax)
    {
      thirdMax = maxFromLine;
    }
  }
  std::cout << "Top 3 words: \n";
  if (!(firstMax == Word("")))
  {
    std::cout << firstMax.getWord() << ": " << firstMax.getAmount() << "\n";
  }
  if (!(secondMax == Word("")))
  {
    std::cout << secondMax.getWord() << ": " << secondMax.getAmount() << "\n";
  }
  if (!(thirdMax == Word("")))
  {
    std::cout << thirdMax.getWord() << ": " << thirdMax.getAmount() << "\n";
  }
}

void HashTable::getFromFile(const std::string& fileName)
{
  const char* const delimiters = ", !.;";
  std::string str;
  std::ifstream input(fileName);
  if (!input.is_open())
  {
    throw std::logic_error("This file doesn't exist");
  }

  while (std::getline(input, str))
  {
    char* strC = strdup(str.c_str());
    char* token = std::strtok(strC, delimiters);
    while (token != nullptr)
    {
      token[0] = std::tolower(token[0]);
      increaseCounter(token);
      token = std::strtok(nullptr, delimiters);
    }

    free(strC);
  }
  std::cout << "Frequency Dictionary is created from " << "'" << fileName << "'\n";

}

void HashTable::remove(const Word& word)
{
  DictionaryList<Word>& line = hashTable[hashFunc(word) - minValue];
  Word* neededWord = line.search(word);
  if (!neededWord)
  {
    throw std::logic_error("Word doesn't exist");
  }
  line.remove(word);
}