#include <stdio.h>
#include <stdlib.h>

#define TAILLE 9
typedef int t_grille[TAILLE][TAILLE];

void chargerGrille(t_grille g);

void afficherGrille(t_grille grille);

int main() {
    int grille[TAILLE][TAILLE];
    chargerGrille(grille);
    afficherGrille(grille);

    return EXIT_SUCCESS;
}

void chargerGrille(t_grille g)
{
    char nomFichier[30];
    FILE *f;
    printf("Nom du fichier ? ");
    scanf("%s", nomFichier);
    f = fopen(nomFichier, "rb");
    if (f==NULL)
    {
        printf("\n ERREUR sur le fichier %s\n", nomFichier);
    }
    else
    {
        fread(g, sizeof(int), TAILLE*TAILLE, f);
    }
    fclose(f);
}

void afficherGrille(t_grille grille)
{
    for (int x=0; x < TAILLE; x++)
    {
        printf("%d |",x);
        for (int y=0; y < TAILLE; y++)
        {
            //printf("(%d,%d) : %d |",x,y,grille[x][y]);
            printf(" %c |", (grille[x][y]==0)?'.':grille[x][y]+48);
        }
        printf("\n");
    }
}