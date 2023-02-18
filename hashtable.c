#include <stdio.h>
#include <stdlib.h>
#include<time.h>
typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
} node ;

void ajouteNode(node **tree, int key)
{
    node *tmpNode;
    node *tmpTree = *tree;

    node *elem = malloc(sizeof(node));
    elem->key = key;
    elem->left = NULL;
    elem->right = NULL;

    if(tmpTree)
    do
    {
        tmpNode = tmpTree;
        if(key > tmpTree->key )
        {
            tmpTree = tmpTree->right;
            if(!tmpTree) tmpNode->right = elem;
        }
        else
        {
            tmpTree = tmpTree->left;
            if(!tmpTree) tmpNode->left = elem;
        }
    }
    while(tmpTree);
    else  *tree = elem;
}

int recherchNode(node *tree, int key)
{
    while(tree)
    {
        if(key == tree->key) return 1;

        if(key > tree->key ) tree = tree->right;
        else tree = tree->left;
    }
    return 0;
}
int hash (int val,int n)
{
    return (val % n);
}

int main()
{
    FILE *fp;
	fp=fopen("asd.txt","w");
    float temps;
    int n,i,val,a;
    do
    {
        printf("Donnez nbr des elmens:");
        scanf("%d",&n);
        node **TTree ;
        TTree=malloc(n*sizeof(node));
        fprintf(fp, "%d", n);
        for(i=0;i<n;i++)
        {
            TTree[i]=NULL;
        }
        srand(time(NULL));
        for (i=0 ; i<n ; i++)
        {
            val=rand();
            ajouteNode(&TTree[hash(val,n)],val);
        }
        printf("Donnez une valleur :");
        scanf("%d",&val);
        clock_t start=clock();
        i=recherchNode(TTree[hash(val,n)],val);
        printf("\n\n%d\n\n",i);
        clock_t end=clock();
        temps=(float)(end-start);
        printf ("\nTemps d'excution = %f", (float)temps / CLOCKS_PER_SEC);
        fprintf(fp, "\n%f\r\t", temps);
        printf("\nvoulez vous ressayer %d ? \n1: Oui\n2: Non.\n", i);
	    scanf("%d", &a);
    }while(a == 1);


        return 0;
}
