#include <stdio.h>
void numarare_biti(unsigned int n)
{
	unsigned int mask = 3221225472;
	unsigned int nr = 0;
	unsigned int N = n;
	unsigned int copie = n;
	unsigned int Dim = n;
	unsigned int tablou_operatii[10];
	while (n)
	{
		nr++;
		n >>= 1;
	}
	N >>= (32 - 3);
	N++;
	printf("%u", N);
	copie <<= 3;
	char operatii[10];
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
			operatii[i] = '+';
			tablou_operatii[i] = 0;
			printf(" %c", '+');
			break;
		}
		case (1):
		{
			operatii[i] = '-';
			tablou_operatii[i] = 1;
			printf(" %c", '-');
			break;
		}
		case (2):
		{
			operatii[i] = '*';
			tablou_operatii[i] = 2;
			printf(" %c", '*');
			break;
		}
		case (3):
		{
			operatii[i] = '/';
			tablou_operatii[i] = 3;
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
	unsigned int nr_operanzi = 0;
	nr_operanzi = nr_operanzi + ((N + 1) * Dim) / 16;
	if ((((N + 1) * Dim) % 16) != 0)
	{
		nr_operanzi = nr_operanzi + 1;
	}
	printf("\nIntroduceti pe rand %d operanzi ", nr_operanzi);
	mask = 61440;
	unsigned short int tablou_operanzi[17];
	for (unsigned int i = 1; i <= nr_operanzi; i = i + 1)
	{
		scanf("%hu", &tablou_operanzi[i]);
	}
	unsigned int tablou_valori[100];
	unsigned short int mask2 = 0;
	mask2 = ~mask2;
	mask2 <<= (16 - Dim);
	int nr_valori = 0;
	int unsigned long concatenat = 0;
	if (Dim != 1 && Dim != 2 && Dim != 4 && Dim != 8 && Dim != 16)
	{
		int nr_biti_total = 0;
		for (int i = 1; i <= nr_operanzi; i++)
		{
			concatenat <<= 16;
			concatenat = concatenat + tablou_operanzi[i];
			nr_biti_total = nr_biti_total + 16;
		}
		for (int i = 1; i <= N + 1; i++)
		{
			int long copie_3 = concatenat;
			tablou_valori[i] = copie_3 >> (nr_biti_total - Dim);
			concatenat <<= Dim;
		}
	}
	else
	{
		for (unsigned int i = 1; i <= nr_operanzi; i++)
		{
			for (unsigned int j = 1; j <= (16 / Dim); j++)
			{
				tablou_valori[i * (16 / Dim) - (16 / Dim) + j] = (tablou_operanzi[i] & mask2);
				tablou_operanzi[i] <<= Dim;
				tablou_valori[i * (16 / Dim) - (16 / Dim) + j] >>= (16 - Dim);
				nr_valori++;
				printf("%d ", tablou_valori[nr_valori]);
			}
		}
	}
	int result = tablou_valori[1];
	for (unsigned int i = 1; i <= N; i++)
	{
		switch (tablou_operatii[i])
		{
		case (0):
		{
			result = result + tablou_valori[i + 1]; break;
		}
		case (1):
		{
			result = result - tablou_valori[i + 1]; break;
		}
		case (2):
		{
			result = result * tablou_valori[i + 1]; break;
		}
		case (3):
		{
			result = result / tablou_valori[i + 1]; break;
		}
		}
	}
	printf("Rezultatul operatiei este %d", result);
}
int main()
{
	unsigned int inst;
	scanf("%u", &inst);
	numarare_biti(inst);
	return 0;
}