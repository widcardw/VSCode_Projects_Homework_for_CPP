#ifndef _BINARYSTRUCT_H
#define _BINARYSTRUCT_H

struct BinStruct{
    char keyword[10];
    int keynum;
    int searchtimes;
};

#endif

#ifndef _BINMAP_H
#define _BINMAP_H

class BinMap{
    BinStruct binlist[32];
    char KeyWords[32][10] = {
		"auto","break","case","char","const","continue",
		"default","do","double","else","enum","extern",
		"float","for","goto","if","int","long","register",
		"return","short","signed","sizeof","static",
		"struct","switch","typedef","union","unsigned",
		"void","volatile","while",
	};
public:
    BinMap();
    int GetSearchLength(char *word);
    bool isKeyWord(char *word);
    bool isLetter(char ch);
    int BinarySearch(char *word);
    void CreateMapFromFile(FILE* in);
    void PrintList(std::ostream& out);
    int CalSearchLen();
};

#endif