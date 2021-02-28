#ifndef _HASH_STRUCT
#define _HASH_STRUCT

struct HashStruct {
    char keyword[10];       // 存入的关键词
    int keynum;             // 关键词出现的次数
    int searchTimes;        // 查找次数
};

#endif

#ifndef _HASHMAP
#define _HASHMAP

class HashMap{
    HashStruct hashlist[41];
    char KeyWords[32][10] = {
		"auto","break","case","char","const","continue",
		"default","do","double","else","enum","extern",
		"float","for","goto","if","int","long","register",
		"return","short","signed","sizeof","static",
		"struct","switch","typedef","union","unsigned",
		"void","volatile","while",
	};
public:
    HashMap();                    // 初始化
    bool isKeyWord(char *word);   // 判断是否是关键词
    bool isLetter(char ch);       // 判断传入的是不是字母
    int GetHashKey(char *word);   // 计算hash算法得到的哈希值
    int SearchProperSeat(char *word); 
    bool insertNode(char *word);  // 传入关键词,插入到hash表中
    void CreateHashMapFromFile(FILE *in);
    void PrintList(std::ostream&);
    int CalSearchLen();
};

#endif