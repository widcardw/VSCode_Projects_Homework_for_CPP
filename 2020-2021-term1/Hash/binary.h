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
    BinStruct binlist[37];
    char KeyWords[37][10] = {
		"auto","bool","break","case","char","const","continue",
        "default","do","double","else","enum","extern", "false",
        "float","for","goto","if","inline","int","long","register","restrict",
        "return","short","signed","sizeof","static",
        "struct","switch","true","typedef","union","unsigned",
        "void","volatile","while"
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