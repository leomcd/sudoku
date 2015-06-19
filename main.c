#include <stdio.h>
#include <stdlib.h>

#define N 9

int op, numero, linha, coluna;


int grade1[N][N] =
{ { 0, 6, 0, 1, 0, 4, 0, 5, 0 },
{ 0, 0, 8, 3, 0, 5, 6, 0, 0 },
{ 2, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 8, 0, 0, 4, 0, 7, 0, 0, 6 },
{ 0, 0, 6, 0, 0, 0, 3, 0, 0 },
{ 7, 0, 0, 9, 0, 1, 0, 0, 4 },
{ 5, 0, 0, 0, 0, 0, 0, 0, 2 },
{ 0, 0, 7, 2, 0, 6, 9, 0, 0 },
{ 0, 4, 0, 5, 0, 8, 0, 7, 0 }
};

int grade2[N][N] =
{ { 3, 6, 0, 1, 0, 4, 0, 5, 0 },
{ 0, 0, 8, 3, 0, 5, 6, 0, 0 },
{ 2, 0, 0, 0, 0, 0, 0, 0, 1 },
{ 8, 0, 0, 4, 0, 7, 0, 0, 6 },
{ 0, 0, 6, 0, 0, 0, 3, 0, 0 },
{ 7, 0, 0, 9, 0, 1, 0, 0, 4 },
{ 5, 0, 0, 0, 0, 0, 0, 0, 2 },
{ 0, 0, 7, 2, 0, 6, 9, 0, 0 },
{ 0, 4, 0, 5, 0, 8, 0, 7, 0 }
};


void desenha_grade(int grade[N][N])
{

	int i, j;
	printf("  1  2  3   4  5  6   7  8  9  \n");
	printf("+---------+---------+---------+\n");
	for (i = 0; i < N; i++)
	{
		printf("|");
		for (j = 0; j < N; j++)
		{
			if (grade[i][j] != 0)
				printf(" %d ", grade[i][j]);
			else
				printf("   ");
			if (j % 3 == 2)
				printf("|");
		}
		if (i % 3 == 2)
			printf("\n+---------+---------+---------+");
		printf("\n");
	}
}

int checar(int grade[N][N], int linha, int coluna, int numero)
{
	if (grade[linha][coluna] == 0)
		return 1;
	else
		return 0;
}

int tenta_colocar(int grade[N][N],int i, int j, int k)
{
	int c, l;
	for (l = 0; l < N; l++)
		if (grade[l][j] == k)
			return 0;
	for (c = 0; c < N; c++)
		if (grade[i][c] == k)
			return 0;
	for (l = i - i % 3; l < i - i % 3 + 3; l++)
		for (c = j - j % 3; c < j - j % 3 + 3; c++)
			if (grade[l][c] == k)
				return 0;
	grade[i][j] = k;
	desenha_grade(grade);
	return 1;
}

int coordenadavalida(int linha, int coluna)
{
	if (linha >= 0 && linha <9 && coluna >= 0 && coluna <9)
		return 1;
	else
		return 0;
}

int numerovalido(int numero)
{
	if (numero>0 && numero <= 9)
		return 1;
	else
		return 0;

}

int existenaColuna(int grade[N][N],int coluna, int numero)
{
	int i;

	for (i = 0; i<9; i++)
	{
		if (grade[i][coluna] == numero)
			return 1;
	}
}

int existenalinha(int grade[N][N], int linha, int numero)
{

	int j;
	for (j = 0; j<9; j++)
	{
		if (grade[linha][j] == numero)
			return 1;
	}
}

void escreve(int grade[N][N], int linha, int coluna, int numero)
{


	grade[linha][coluna] = numero;
}

void jogo(int grade[N][N])
{

	printf("digite 0(ZERO) para sair");
	if (coordenadavalida(linha - 1, coluna - 1) == 1)
	{
		printf("Coordenada Valida\n");
		if (numerovalido(numero) == 1)
		{
			printf("Numero valido\n");
			if (checar(grade,linha - 1, coluna - 1, numero) == 1)
			{
				printf("Posicao vazia\n");
				if (tenta_colocar(grade, linha - 1, coluna - 1, numero) == 1)
				{
					printf("Quadrante OK\n");
					escreve(grade, linha - 1, coluna - 1, numero);
					printf("Gravado\n");
					system("clear");

				}
				else
				{
					printf("Nao foi possivel, ja existe na linha ou na coluna ou no mesmo quadrante\n");
				}
			}
			else
			{
				printf("Posicao ja esta ocupada\n");
			}
		}
		else
		{
			printf("Numero invalido\n");
		}
	}
	else
	{
		printf("Coordenada invalida\n");
	}
}

int terminar()
{
	int i, j;
	for (i = 0; i<9; i++)
		for (j = 0; j<9; j++)
			if (grade1[i][j] == 0)
				return 1;
}

void geratela(int grade[N][N])
{
	desenha_grade(grade);

	printf("Digite uma linha: ");
	scanf("%d", &linha);

	printf("Digite uma coluna: ");
	scanf("%d", &coluna);

	printf("Digite o numero: ");
	scanf("%d", &numero);

	jogo(grade);
}

void comecarJogo(int fase)
{
	
	if (fase == 1)
		geratela(grade1);
	if (fase == 2)
		geratela(grade2);

	terminar();
}


int main()
{

	printf("SUDOKU\n\n\n");

	int fase;

	printf("Escolha uma fase 1-?:");
	scanf("%d", &fase);

	while (terminar() != 0)
	{

		comecarJogo(fase);
	}

	return 0;
}

