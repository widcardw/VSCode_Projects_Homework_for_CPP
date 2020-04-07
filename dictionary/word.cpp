#include <iostream>
#include <cassert>
#include "word.h"
using namespace std;
Word::Word(char *word, char *nature, unsigned int frequency)
{
    word_ = new char[strlen(word) + 1];
    assert(word_);
    strcpy(word_, word);
    nature_ = new char[strlen(nature) + 1];
    assert(nature_);
    strcpy(nature_, nature);
    frequency_ = frequency + 1;
}
Word::Word(const Word &one)
{
    word_ = new char[strlen(one.word_) + 1];
    assert(word_);
    strcpy(word_, one.word_);
    nature_ = new char[strlen(one.nature_) + 1];
    assert(nature_);
    strcpy(nature_, one.nature_);
    frequency_ = one.frequency_ + 1;
}
Word::Word() {}
Word::~Word()
{
    delete[] word_;
    delete[] nature_;
}