#include <stdio.h>
#include <string.h>

// Maximum number of productions
#define MAX_PROD 10
// Maximum length of a production
#define MAX_LEN 20

// Function to eliminate left factoring
void eliminateLeftFactoring(char productions[MAX_PROD][MAX_LEN], int numProd) {
    int i, j, k;
    char common[MAX_LEN];
    int commonLen;

    for (i = 0; i < numProd; i++) {
        for (j = i + 1; j < numProd; j++) {
            commonLen = 0;
            while (productions[i][commonLen] == productions[j][commonLen] && productions[i][commonLen] != '\0') {
                commonLen++;
            }
            if (commonLen > 0) {
                // Found a common prefix, extract it
                strncpy(common, productions[i], commonLen);
                common[commonLen] = '\0';

                printf("Common prefix found: %s\n", common);

                // Replace common prefix with a new non-terminal
                printf("New production rules:\n");
                printf("A -> %sA'\n", common);
                printf("A' -> ");
                for (k = commonLen; productions[i][k] != '\0'; k++) {
                    printf("%c", productions[i][k]);
                }
                printf("|");
                for (k = commonLen; productions[j][k] != '\0'; k++) {
                    printf("%c", productions[j][k]);
                }
                printf("|epsilon\n");
            }
        }
    }
}

int main() {
    int numProd;
    char productions[MAX_PROD][MAX_LEN];

    printf("Enter the number of productions: ");
    scanf("%d", &numProd);

    printf("Enter the production rules:\n");
    int i;
    for (i = 0; i < numProd; i++) {
        scanf("%s", productions[i]);
    }

    printf("\nEliminating left factoring...\n");
    eliminateLeftFactoring(productions, numProd);

    return 0;
}

