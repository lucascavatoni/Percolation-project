#include "../include/union_find.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main(void){
    element *my_ufgrid = create_uf(10000,10000);
    
    for(int i = 0; i < 10000; i++){
        for(int j = 0; j< 10000; j++){
            if ((j*10000+i) % 4 == 0){
                element *random_elt = access_element(my_ufgrid,10000,i,j);
                merge(my_ufgrid,random_elt);
                assert(find(random_elt) == find(my_ufgrid));
            }
            if ((j*10000+i) % 4 == 1){
                element *random_elt = access_element(my_ufgrid,10000,i,j);
                merge(my_ufgrid + 1,random_elt);
                assert(find(random_elt) == find(my_ufgrid + 1));
            }
            if ((j*10000+i) % 4 == 2){
                element *random_elt = access_element(my_ufgrid,10000,i,j);
                merge(my_ufgrid,random_elt);
                assert(find(random_elt) == find(my_ufgrid + 2));
            }
            if ((j*10000+i) % 4 == 3){
                element *random_elt = access_element(my_ufgrid,10000,i,j);
                merge(my_ufgrid + 3,random_elt);
                assert(find(random_elt) == find(my_ufgrid + 3));
            }
        }
    }
    free(my_ufgrid);
    printf("Union Find Test Pass\n");
    return 0;
}
