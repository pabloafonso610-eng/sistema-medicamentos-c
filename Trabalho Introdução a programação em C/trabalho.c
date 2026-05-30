#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// PROJETO DE PROGRAMAÇÃO EM C - TRABALHO - PABLO MAIA 

typedef struct {

char nome[50];
char quantidade[50];
char dias[100];
char horarios[100];

} Medicamento;

Medicamento remedio[100];

int total = 0;

int main() {

    int opcao = 0;
    int escolha;
    int i;

    char horarioBusca[20];

    FILE *arquivo;

    while(opcao != 5) {

        printf("\nSISTEMA DE MEDICAMENTOS\n");
         printf("\nEscolha uma opcao: \n");
          printf("1 - Cadastrar medicamento\n");
        printf("2 - Listar medicamentos\n");
        printf("3 - Buscar por horario\n");
        printf("4 - Imprimir lista de medicamentos\n");
        printf("5 - Sair\n");
        printf("Digite aqui:");

        if(scanf("%d", &opcao) != 1) {
            opcao = -1;
        }
        while(getchar() != '\n');

        switch(opcao) {

            case 1:

                printf("\nCADASTRAR MEDICAMENTO\n");

                printf("Nome do medicamento: ");
                fgets(remedio[total].nome, 100, stdin);
                
                remedio[total].nome[strcspn(remedio[total].nome, "\n")] = 0;

                printf("Quantidade: ");
                fgets(remedio[total].quantidade, 100, stdin);
                
                remedio[total].quantidade[strcspn(remedio[total].quantidade, "\n")] = 0;

                printf("Dias da semana: ");
                fgets(remedio[total].dias, 100, stdin);
                
                remedio[total].dias[strcspn(remedio[total].dias, "\n")] = 0;

                printf("Horarios: ");
                fgets(remedio[total].horarios, 100, stdin);
                
                remedio[total].horarios[strcspn(remedio[total].horarios, "\n")] = 0;

                arquivo = fopen("medicamentos.txt", "a");

                if(arquivo != NULL) {

                    fprintf(arquivo, "Medicamento: %s\n", remedio[total].nome);
                    fprintf(arquivo, "Quantidade: %s\n", remedio[total].quantidade);
                    fprintf(arquivo, "Dias: %s\n", remedio[total].dias);
                    fprintf(arquivo, "Horarios: %s\n", remedio[total].horarios);

                    fclose(arquivo);

                }

                total++;

                printf("\nMedicamento cadastrado com sucesso!\n");

                break;

            case 2:

                if(total == 0) {

                    printf("\nNenhum medicamento cadastrado.\n");

                } else {

                    printf("\nLISTA DE MEDICAMENTOS\n");

                    for(i = 0; i < total; i++) {

                        printf("%d - %s\n", i + 1, remedio[i].nome);

                    }

                    printf("\nSelecione o medicamento: ");
                    scanf("%d", &escolha);

                    while(getchar() != '\n');

                    escolha--;

                    if(escolha >= 0 && escolha < total) {

                        printf("\nINFORMACOES\n");

                        printf("Medicamento: %s\n", remedio[escolha].nome);
                        printf("Quantidade: %s\n", remedio[escolha].quantidade);
                        printf("Dias: %s\n", remedio[escolha].dias);
                        printf("Horarios: %s\n", remedio[escolha].horarios);

                    } else {

                        printf("\nMedicamento invalido.\n");

                    }

                }

                break;

           case 3:

                if(total == 0) {

                    printf("\nNenhum medicamento cadastrado.\n");

                } else {

                    printf("\nDigite o horario: ");
                    fgets(horarioBusca, 20, stdin);

                    horarioBusca[strcspn(horarioBusca, "\n")] = 0;

                    printf("\nMEDICAMENTOS ENCONTRADOS\n");

                    for(i = 0; i < total; i++) {

                        if(strstr(remedio[i].horarios, horarioBusca) != NULL) {

                            printf("%s\n", remedio[i].nome);

                        }

                    }

                }

                break;
                
            case 4:

                arquivo = fopen("relatorio.txt", "w");

                if(arquivo != NULL) {

                    fprintf(arquivo, "LISTA DE MEDICAMENTOS\n\n");

                    for(i = 0; i < total; i++) {

                        fprintf(arquivo, "Medicamento: %s\n", remedio[i].nome);
                        fprintf(arquivo, "Quantidade: %s\n", remedio[i].quantidade);
                        fprintf(arquivo, "Dias: %s\n", remedio[i].dias);
                        fprintf(arquivo, "Horarios: %s\n\n", remedio[i].horarios);

                    }

                    fclose(arquivo);

                    system("notepad relatorio.txt");

                } else {

                    printf("\nErro ao gerar relatorio.\n");

                }

                break;

            case 5:

                printf("\nSaindo do sistema...\n");

                break;

            default:

                printf("\nOpcao invalida.\n");

        }

    }

    return 0;
}
