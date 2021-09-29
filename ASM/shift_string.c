char str[20] = "??????$";
int len;
int main()
{
    int count = 0;
    while (str[count] != '$') count ++;

    while (count >= 0)
        str[count + 2] = str[count];
    
    return 0;
}