#include <stdio.h>
union u{
    int x;
    float y;
};
int main()
{
    union u k;
    k.x = 0x00000001;
    printf("%e\n", k.y);
    return 0;
}