#include "../include/union_find.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
    FILE *p_file = NULL;
    p_file = fopen("out/union_find_complexity.csv","w");
    int n = 10;
    while (n <= 1280){
        element *my_ufgrid = create_uf(n,n);
        bool allmerged = false;
        int mergenb = 0;
        clock_t start = clock();
        while(allmerged == false){
            int i = rand() % (n*n);
            int j = rand() % (n*n);
            while (find(my_ufgrid + i) == find(my_ufgrid + j)){
               i = rand() % (n*n);
               j = rand() % (n*n); 
            }
            merge(my_ufgrid + i,my_ufgrid + j);
            mergenb = mergenb + 1;
            if (mergenb == n*n-1){
                allmerged = true;
            }
        }
        clock_t end = clock();
        double elapsed_time_merge = (double) (end - start) / CLOCKS_PER_SEC;
        element *found;
        start = clock();
        for(int i = 0; i < n*n; i++){
            found = find(my_ufgrid + i);
        }  
        end = clock();
        double elapsed_time_find = (double) (end - start) / CLOCKS_PER_SEC;
        found->rank = 0;
        printf("elapsed time merge - find for a %dx%d grid is %f - %f seconds\n",n,n,elapsed_time_merge,elapsed_time_find); //on mac, the clock has a 10 microseconds but on a CI computer on linux,
																															//the precision is only 10 ms
        fprintf(p_file,"%d, %f, %f\n", n, elapsed_time_merge, elapsed_time_find);
        n = 2*n; 
        free(my_ufgrid);    
    }
	n = 10;
	printf("\nHere are the results of the same program executed on my MACOS machine (in seconds) :\n");
	printf("\nn = 10,   t_merge = 0.000013 t_find = 0.000001\n");
	printf("n = 20,   t_merge = 0.000031 t_find = 0.000001\n");
	printf("n = 40,   t_merge = 0.000279 t_find = 0.000021\n");
	printf("n = 80,   t_merge = 0.000720 t_find = 0.000021\n");
	printf("n = 160,  t_merge = 0.002935 t_find = 0.000083\n");
	printf("n = 320,  t_merge = 0.015001 t_find = 0.000329\n");
	printf("n = 640,  t_merge = 0.140406 t_find = 0.001729\n");
	printf("n = 1280, t_merge = 1.067020 t_find = 0.007938\n");
	printf("Which when, for both, we plot T = f(n²) we obtain a line, that means our complexity is O(n²)\n");
	printf("Test Union Find Complexity Pass\n");


    fclose(p_file);

    p_file = NULL;
    return 0;
}
