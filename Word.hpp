#ifndef WORD_HPP
#define WORD_HPP
#include <string>
#include <cstddef>
class Word
{
public:
  Word(const std::string &word):
  word_(word),
  amount_(1)
  {
  }
  Word():
  word_(""),
  amount_(1)
  {
  }
  std::string getWord() const;
  std::size_t getAmount() const;
  void increaseAmount();

private:
  std::string word_;
  std::size_t amount_;
};

bool operator==(const Word& left, const Word& right);
bool operator>(const Word& left, const Word& right);

#endif