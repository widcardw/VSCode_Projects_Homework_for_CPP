#ifndef _WORD_H_
#define _WORD_H_
class Word
{
private:
    char *word_;
    unsigned int frequency_;
    char *nature_;

public:
    Word(char *, char *, unsigned int);
    Word(const Word &);
    Word();
    ~Word();
};

#endif