#include <stdio.h>
#include <windows.h>

#define MAX_LETRAS 100
#define MAX_LINHAS 50

struct Cliente{
	char nome[50];
	int idade;
	char sexo;
};

void main(){
	SetConsoleOutputCP(CP_UTF8);
	int qtdLinhas = 0;
	struct Cliente clientes[MAX_LINHAS];
	FILE *arquivo = fopen("clientes.txt","r");              
	if(arquivo == NULL){
		printf("Você não tem o arquivo .\n");
		getch();
		return 0;
	}
	char linha[MAX_LETRAS];
	while(fgets(linha,sizeof(linha),arquivo) != NULL && qtdLinhas < MAX_LINHAS){
		linha[strcspn(linha,"\n")] = '\0';//Remove o \n nas linhas
		qtdLinhas++;
		//Ignorar a primeira linha, por isso maior que 1
		if(qtdLinhas > 1){
			sscanf(linha,"%49[^,],%d,%c",
			clientes[qtdLinhas - 2].nome,
			&clientes[qtdLinhas - 2].idade,
			&clientes[qtdLinhas - 2].sexo
			);
		}
	}
	fclose(arquivo);
	
	double media = 0;
	int m=0;
	int f=0;
	float mediaM, mediaF;
	printf("Nome\tIdade\tSexo\n");
	for(int i = 0; i < qtdLinhas - 1; i++){
		printf("%s\t%d\t%c\n",clientes[i].nome, clientes[i].idade, clientes[i].sexo);
		media += clientes[i].idade;
		if(clientes[i].sexo == 'M'){
			m++;
			mediaM += clientes[i].idade;
		} else{
			f++;
			mediaF += clientes[i].idade;
		}
	}
	mediaM = mediaM / m;
	mediaF = mediaF / f;
	media = media / (float)(qtdLinhas - 1);
	printf("\nForam analizados %d clientes\n", qtdLinhas - 1);
	printf("A média de idade dos clientes é %.1f anos\n", media);
	printf("Foram analizadas %d pessoas do sexo masculino e %d do sexo feminino\n",  m, f);
	printf("A média de idade das pessoas do sexo masculino é %.1f anos\n", mediaM);
	printf("A média de idade das pessoas do sexo feminino é %.1f anos\n", mediaF);
	getch();
}