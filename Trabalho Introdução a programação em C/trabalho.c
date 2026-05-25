#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    char diaBusca[20];

    FILE *arquivo;

    while(opcao != 4) {

        printf("\n===== SISTEMA =====\n");
        printf("1 - Cadastrar medicamento\n");
        printf("2 - Listar medicamentos\n");
        printf("3 - Buscar por dia\n");
        printf("4 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        getchar();

        switch(opcao) {

            case 1:

                printf("\n=== CADASTRAR MEDICAMENTO ===\n");

                printf("Nome do medicamento: ");
                fgets(remedio[total].nome, 50, stdin);
                
                remedio[total].nome[strcspn(remedio[total].nome, "\n")] = 0;

                printf("Quantidade: ");
                fgets(remedio[total].quantidade, 50, stdin);
                
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
                    fprintf(arquivo, "--------------------------\n");

                    fclose(arquivo);

                }

                total++;

                printf("\nMedicamento cadastrado com sucesso!\n");

                break;

            case 2:

                if(total == 0) {

                    printf("\nNenhum medicamento cadastrado.\n");

                } else {

                    printf("\n=== LISTA DE MEDICAMENTOS ===\n");

                    for(i = 0; i < total; i++) {

                        printf("%d - %s\n", i + 1, remedio[i].nome);

                    }

                    printf("\nSelecione o medicamento: ");
                    scanf("%d", &escolha);

                    getchar();

                    escolha--;

                    if(escolha >= 0 && escolha < total) {

                        printf("\n=== INFORMACOES ===\n");

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

                printf("\nDigite o dia da semana: ");
                fgets(diaBusca, 20, stdin);

                diaBusca[strcspn(diaBusca, "\n")] = 0;

                printf("\n=== MEDICAMENTOS ENCONTRADOS ===\n");

                for(i = 0; i < total; i++) {

                    if(strstr(remedio[i].dias, diaBusca) != NULL) {

                        printf("%s\n", remedio[i].nome);

                    }

                }

                break;

            case 4:

                printf("\nSaindo do sistema...\n");

                break;

            default:

                printf("\nOpcao invalida.\n");

        }

    }

    return 0;
}