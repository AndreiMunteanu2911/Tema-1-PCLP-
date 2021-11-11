#include <stdio.h>
#include <stdio.h>
void numarare_biti(unsigned int n)
{
	unsigned int mask = 3221225472;
	unsigned int nr = 0;
	unsigned int N = n;
	unsigned int copie = n;
	unsigned int Dim = n;
	while (n)
	{
		nr++;
		n >>= 1;
	}
	N >>= (32 - 3);
	N++;
	printf("%u", N);
	copie <<= 3;
	for (unsigned int i = 1; i <= N; i++)
	{
		unsigned int operator_temp = 0;
		operator_temp = copie & mask;
		copie <<= 2;
		operator_temp >>= 30;
		switch (operator_temp)
		{
			case (0):
			{
				printf(" %c", '+');
				break;
			}
			case (1):
			{
				printf(" %c", '-');
				break;
			}
			case (2):
			{
				printf(" %c", '*');
				break;
			}
			case (3):
			{
				printf(" %c", '/');
				break;
			}
		}
	}
	mask = 4026531840;
	copie = copie & mask;
	copie = copie >>= 28;
	Dim = copie + 1;
	printf(" %u", Dim);
}
int main()
{
	unsigned int inst;
	scanf("%u", &inst);
	numarare_biti(inst);
	return 0;
}