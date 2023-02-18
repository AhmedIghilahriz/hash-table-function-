#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main()
{ FILE *fp;
fp=fopen("algo_projet.txt","w");
    int *T;
    int i,nombre,valeur,a,b=0;
    float temps;
    do {
    printf("Donnez nombre :");   scanf("%d",&nombre);
    T=malloc(sizeof(int)*nombre);
    srand(time(NULL));
for (i=0 ;i<nombre ;i++)
    {
     T[i]=rand();
    }
    fprintf(fp, "%d\t,", i);
    printf("Donnez valeur:");
    scanf("%d",&valeur);
float debut =0;
i=0;
    while(i<nombre && b ==0)
    {if(T[i]==valeur){b=1;}
        i++;}
    float fin = clock();
    temps = (float)(fin-debut)/CLOCKS_PER_SEC;
    printf("le temps est :\n%f\n",(temps));
    free(T);
    printf("\nvoulez vous reessaye %d ? \n1: Oui\n2: Non.\n", i);
    scanf("%d", &a);
    fprintf(fp,"%f\t",temps);
    }while(a == 1);
    return 0;
}
