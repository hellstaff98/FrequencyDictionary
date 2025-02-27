#include <string>
#include "Word.hpp"

std::size_t Word::getAmount() const
{
    return amount_;
}

std::string Word::getWord() const
{
    return word_;
}

void Word::increaseAmount()
{
    ++amount_;
}

bool operator==(const Word& left, const Word& right)
{
    return left.getWord() == right.getWord();
}

bool operator>(const Word& left, const Word& right)
{
    return left.getAmount() > right.getAmount();
}