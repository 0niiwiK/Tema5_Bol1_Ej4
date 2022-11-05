#include <stdio.h>

//PROTOTIPOS
void imprimeVector(int v[]);
void rellenaVector(int v[]);
void insertaDesplazaVector(int v[], int pos, int num);
int leerOpcion();



int main() {
    int v[]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    do {
        imprimeVector(v);
        rellenaVector(v);
        imprimeVector(v);
    } while (leerOpcion()==1);
    return 0;
}

void imprimeVector(int v[]){
    printf("\nContenido del vector: ");
    printf("|");
    for (int i = 0; i < 10; i++) {
        if (v[i]==-1)
            printf(" - |");
        else
            printf(" %d |",v[i]);
    }
    printf("\n");
}

void rellenaVector(int v[]){
    int num, pos;
    printf("\nIntroduzca el valor (positivo): ");
    scanf("%d",&num);
    fflush(stdin);
    while (num<0){
        printf("Numero invalido\nIntroduzca el valor (positivo): ");
        scanf("%d",&num);
        fflush(stdin);
    }
    printf("Introduzca posicion (1 - 10): ");
    scanf("%d",&pos);
    fflush(stdin);
    while (pos<1 || pos>10){
        printf("Numero invalido\nIntroduzca posicion (1 - 10): ");
        scanf("%d",&pos);
        fflush(stdin);
    }
    pos--;
    if (v[pos]==-1)
        v[pos]=num;
    else
        insertaDesplazaVector(v,pos,num);
}

void insertaDesplazaVector(int v[], int pos, int num){
    int poslibre=9;
    for (int i = 9; i > pos; i--) {
        if (v[i]==-1)
            poslibre=i;
    }
    for (int i = poslibre; i > pos; i--) {
        v[i]=v[i-1];
    }
    v[pos]=num;
}

int leerOpcion(){
    char opcion;
    int opcionNum=0;
    printf("\nDesea introducir otro valor (s/n): ");
    scanf("%c",&opcion);
    fflush(stdin);
    while (opcion!='s' && opcion!='n'){
        printf("Desea introducir otro valor (s/n): ");
        scanf("%c",&opcion);
        fflush(stdin);
    }
    if (opcion=='s')
        opcionNum=1;
    return opcionNum;
}