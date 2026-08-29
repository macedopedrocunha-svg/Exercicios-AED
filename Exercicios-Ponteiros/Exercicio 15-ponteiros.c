 #include <stdio.h>
            #include <stdlib.h>

            int soma_diagonal(int **mat, int n) {
                int soma = 0;
                for (int i = 0; i < n; i++) {
                    soma += mat[i][i];
                }
                return soma;
            }

            int main() {
                int n;

                printf("Difite o tamanho n da matriz quadrada (n x n): ");
                scanf("%d", &n);

                if (n <= 0) {
                    printf("Tamanho invalido.\n");
                    return 1;
                }

                int **mat = (int **) malloc(n * sizeof(int *));
                if (mat == NULL) {
                    printf("Erro de alocacao de memoria.\n");
                    return 1;
                }

                for (int i = 0; i < n; i++) {
                    mat[i] = (int *) malloc(n * sizeof(int));
                    if (mat[i] == NULL) {
                        printf("Erro de alocacao de memoria.\n");
                        return 1;
                    }
                }

                printf("Digite os %d elementos da matriz (linha por linha):\n", n * n);
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        scanf("%d", &mat[i][j]);
                    }
                }

                printf("\nMatriz %dx%d:\n", n, n);
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%d\t", mat[i][j]);
                    }
                    printf("\n");
                }

                
                int soma = soma_diagonal(mat, n);
                printf("\nSoma da diagonal principal: %d\n", soma);

                for (int i = 0; i < n; i++) {
                    free(mat[i]);
                }
                free(mat);
                mat = NULL;

                return 0;
            }

