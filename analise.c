#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Converte uma string para letras minúsculas
void txtminusculo(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Classifica os comentários
void classificacao(const char *comment) {
    // Palavras-chave para cada grupo
    const char *homem_keywords[] = {"homem","perdoou" , "pai", "masculino", "homens", "família", "perdão", "chance", "deus", "reconhece", "aprender", "feliz", "pedra"};
    const char *mulher_apoio_keywords[] = {"mulher", "mãe", "feminino", "apoio", "força", "respeito", "coitada", "mãezona", "amor", "amada", "grandiosa", "coragem"};
    const char *mulher_critica_keywords[] = {"não se valoriza","crítica", "culpa", "problema", "fraqueza", "erros", "pensão", "dependência", "chifre", "voltou", "apagar", "defender", "ridículo", "iluda", "sujeita", "gaia", "exigir", "constrangedor"};

    // Converter o comentário para minúsculas
    char comment_lower[1000];
    strncpy(comment_lower, comment, sizeof(comment_lower) - 1);
    comment_lower[sizeof(comment_lower) - 1] = '\0';
    txtminusculo(comment_lower);

    // Verificar palavras-chave
    int homem_match = 0, mulher_apoio_match = 0, mulher_critica_match = 0;

    for (size_t i = 0; i < sizeof(homem_keywords) / sizeof(homem_keywords[0]); i++) {
        if (strstr(comment_lower, homem_keywords[i])) {
            homem_match++;
        }
    }

    for (size_t i = 0; i < sizeof(mulher_apoio_keywords) / sizeof(mulher_apoio_keywords[0]); i++) {
        if (strstr(comment_lower, mulher_apoio_keywords[i])) {
            mulher_apoio_match++;
        }
    }

    for (size_t i = 0; i < sizeof(mulher_critica_keywords) / sizeof(mulher_critica_keywords[0]); i++) {
        if (strstr(comment_lower, mulher_critica_keywords[i])) {
            mulher_critica_match++;
        }
    }

    // Determinar a categoria
    if (homem_match > mulher_apoio_match && homem_match > mulher_critica_match) {
        printf("Categoria: Grupo de Apoio ao Homem e à Família\n\n");
    } else if (mulher_apoio_match > homem_match && mulher_apoio_match > mulher_critica_match) {
        printf("Categoria: Grupo de Apoio à Mulher\n\n");
    } else if (mulher_critica_match > homem_match && mulher_critica_match > mulher_apoio_match) {
        printf("Categoria: Grupo de Crítica à Mulher\n\n");
    } else {
        printf("Categoria: Indeterminado ou Neutro\n\n");
    }
}

int main() {
    char comment[1000];
    printf("Digite um comentário (ou 'sair' para encerrar):\n");

    while (1) {
        printf("Comentário: ");
        fgets(comment, sizeof(comment), stdin);

        // Remove o caractere de nova linha
        comment[strcspn(comment, "\n")] = 0;

        // Ignorar comentários vazios
        if (strlen(comment) == 0) {
            continue;
        }

        // Encerrar o programa se "sair" for digitado
        if (strcmp(comment, "sair") == 0) {
            break;
        }

        classificacao(comment);
    }

    printf("Encerrando o programa.\n");
    return 0;
}
