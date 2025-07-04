#include "file.h"
#include <stdlib.h>
#include <stdio.h>  // pour printf et exit

File* creeFile() {
    File* file = (File*)malloc(sizeof(File));
    if (file) {
        file->tete = NULL;
        file->queue = NULL;
        file->size = 0;
    }
    return file;
}

Element* creeElement(char valeur) {
    Element* elem = (Element*)malloc(sizeof(Element));
    if (elem) {
        elem->valeur = valeur;
        elem->suivant = NULL;
    }
    return elem;
}

int estVide(File* file) {
    return (file->tete == NULL);
}

void Enfiler(File* file, char valeur) {
    Element* elem = creeElement(valeur);
    if (elem) {
        if (estVide(file)) {
            file->tete = elem;
        } else {
            file->queue->suivant = elem;
        }
        file->queue = elem;
        file->size++;
    }
}

char Defiler(File* file) {
    if (estVide(file)) {
        printf("La file est vide.\n");
        exit(EXIT_FAILURE);
    }

    Element* elem = file->tete;
    char valeur = elem->valeur;

    file->tete = elem->suivant;
    if (file->tete == NULL) {
        file->queue = NULL;
    }
    free(elem);
    file->size--;

    return valeur;
}

void AfficherFile(File* file) {
    if (estVide(file)) {
        printf("La file est vide.\n");
        return;
    }

    Element* current = file->tete;
    while (current != NULL) {
        printf("%c ", current->valeur);  // %c au lieu de %d
        current = current->suivant;
    }
    printf("NULL\n");
}

void GEnererMot(int N) {
    File* file = creeFile();
    Enfiler(file, 'A');

    for (int etape = 0; etape < N; etape++) {
        int taille = file->size;  // stocker la taille pour itérer correctement
        for (int j = 0; j < taille; j++) {
            char El = Defiler(file);

            if (El == 'A') {
                Enfiler(file, 'A');
                Enfiler(file, 'B');
                Enfiler(file, 'C');
            } else if (El == 'B') {
                Enfiler(file, 'B');
                Enfiler(file, 'C');
            } else if (El == 'C') {
                Enfiler(file, 'A');
            }
        }
        AfficherFile(file);
    }

    // Libérer la mémoire de la file
    while (!estVide(file)) {
        Defiler(file);
    }
    free(file);
}
