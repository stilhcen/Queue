#ifndef FILE_H
#define FILE_H

typedef struct Element {
    char valeur;
    struct Element* suivant;
} Element;

typedef struct File {
    Element* tete;
    Element* queue;
    int size;
} File;

File* creeFile();
Element* creeElement(char valeur);
int estVide(File* file);
void Enfiler(File* file, char valeur);
char Defiler(File* file);
void AfficherFile(File* file);
void GEnererMot(int N);

#endif
