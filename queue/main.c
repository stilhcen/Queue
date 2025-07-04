#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int main() {
    File* file = creeFile();
    int choix, N;
    char val;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Enfiler\n");
        printf("2. Defiler\n");
        printf("3. Afficher la file\n");
        printf("4. Générer mot\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                printf("Entrer une lettre à enfiler : ");
                scanf(" %c", &val);
                Enfiler(file, val);
                break;
            case 2:
                if (!estVide(file)) {
                    printf("Défilé : %c\n", Defiler(file));
                } else {
                    printf("La file est vide.\n");
                }
                break;
            case 3:
                AfficherFile(file);
                break;
            case 4:
                printf("Entrer le nombre des étapes : ");
                scanf("%d", &N);
                GEnererMot(N);
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);

    // Libération mémoire
    while (!estVide(file)) {
        Defiler(file);
    }
    free(file);
    return 0;
}
