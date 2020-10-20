#include <iostream>
/*
const int ci = 1;
int a = 2;
int b = 3;
const int *cpi1 = &ci;
const int *cpi2 = &a;
int const *cpi3;
int *const pci1 = &b;
const int *const cpci = &ci;

*cpi1 = 3; x
*cpi2 = 3; x
cpi3 = &b; o
*pci1 = 4; o
pci1 = &a; x
cpci = &a; x
*cpci = 5; x
int *const pci2 = &ci; x
*/
int AndProcessing(int m, int n)
{
	int count = 0;
	while (m != n)
	{
		m = m>>1;
		n = n>>1;
		count++;
	}
	m = m<<count;
	return m;
}
int main()
{
	int m = 0, n = 0;
	std::cin >> m >> n;
	int t = AndProcessing(m, n);
	std::cout << t << std::endl;
    return 0;
}