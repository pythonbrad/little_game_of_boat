#include <stdio.h>
#include <stdlib.h>

#define MAX_CASE 5

int main()
{
    /*Initiation de la carte de jeu*/
    int map[MAX_CASE][MAX_CASE] = {};
    /*On initinie un deuxieme map qui servira du map de l'utilisateur*/
    int map_user[MAX_CASE][MAX_CASE] = {};
    /*Initiation du nombre de solution*/
    int nb_solution = MAX_CASE;
    /*Initiation des coordonnees de tir*/
    int x;
    int y;
    /*Initiation de la variable essai*/
    int essai = MAX_CASE;
    /*On cree les coordonnees du map*/
    for(int y=0;y<MAX_CASE;y++)
    {
        map[0][y] = y;
        map_user[0][y] = y;
        map[y][0] = y;
        map_user[y][0] = y;
    };
    /*On cree les solutions du map*/
    for(int y=0;y<MAX_CASE;y++)
    {
        /*On stocke l'indice de la solution dans x*/
        x = rand()%MAX_CASE;
        /*Puis que */
        if(x==0)
            x++;
        if(y==0)
            y++;
        /*On place la solution dans le map*/
        map[y][x] = 1;
    };
    /*GAME*/
    while (essai)
    {
        /*On affiche le map_user*/
        for(int y=0;y<MAX_CASE;y++)
        {
            for(int x=0;x<MAX_CASE;x++)
            {
                printf("|%d", map_user[y][x]);
            }
            printf("|\n");
        }
        x=0;
        y=0;
        while(x==0 | y==0)
        {
            printf("Donner les coordonnees du tir (x,y)\n");
            printf("x: ");
            scanf("%d", &x);
            y++;
            printf("y: ");
            scanf("%d", &y);
        }
        if(map[y][x])
        {
            printf("Bateau toucher\n");
            map_user[y][x] = 1;
        }
        else
        {
            printf("Aucun bateau toucher\n");
            map_user[y][x] = 0;
        }
        essai--;
        printf("Il vous reste %d essai\n", essai);
        system("pause");
        system("cls");
    }
    printf("Essai fini");
    /*END GAME*/
    printf("Solution:\n");
    /*On affiche le map avec les solutions*/
    for(int y=0;y<MAX_CASE;y++)
    {
        for(int x=0;x<MAX_CASE;x++)
        {
            printf("|%d", map[y][x]);
        }
        printf("|\n");
    }
    return 0;
}
