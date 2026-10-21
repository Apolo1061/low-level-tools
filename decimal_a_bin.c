/*
* decimal -> binario
* Este script pasa de decimal a binario
* Ya te los deja ordenado los bits
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int var = 0;
    int dacsd = 56;

    printf("> ");
    if(scanf("%d", &var) != 1){
        fprintf(stderr, "Error scanf");
        return -1;
    }

    if(var <= 0){
        fprintf(stderr, "\nNo se encontro un valor ingresado");
        return -1;
    }

    int tam = 10;
    int *r = calloc(tam, sizeof(int));
    if (!r) {
        perror("ERROR: ");
        return -1;
    }

    int pos = 0;
    while(var != 0){
        int tmp = var % 2;
        
        if(pos >= tam){
            tam++;
            int *tempr = realloc(tempr, tam * sizeof(int));
            if(!tempr){
                perror("ERROR: ");
                free(r);
                return -1;
            }
            r = tempr;
        }

        r[pos] = tmp;
        var = var/2;
        pos++;
    }

    for(int i = pos - 1; i >= 0; i--){
        printf("\nR[ %d ] = %d", i, r[i]);
    }

    free(r);
    return 0;
}