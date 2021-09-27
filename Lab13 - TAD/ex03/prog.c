#include <stdio.h>
#include <stdlib.h>
#include "TMat2D.h"

int main () {
    
    TMat2D *m1 = mat2D_create(2,3);
    TMat2D *m2 = mat2D_create(2,3);
    TMat2D *m3 = mat2D_create(5,5);
    TMat2D *mSum;
    double *sumColumns, *sumRows;
    double val, trace;

    mat2D_random_mat (m1, 10, 5);

    mat2D_set_value(m2,0,0,1.1);
    mat2D_set_value(m2,0,1,2.2);
    mat2D_set_value(m2,0,2,3.3);
    mat2D_set_value(m2,1,0,4.4);
    mat2D_set_value(m2,1,1,5.5);
    mat2D_set_value(m2,1,2,6.6);

    mat2D_random_mat (m3, 10, 5);

    mat2D_get_value(m2,1,0,&val);
    printf("M2 - Linha 1 e Coluna 0: %.1lf\n\n", val);

    mSum = mat2D_sum2matrices(m1,m2,mSum);

    mat2D_print (m1);
    printf("+\n");
    mat2D_print (m2);
    printf("=\n");
    mat2D_print (mSum);

    mat2D_escalate(2.0, mSum); // theres 2 versions of this function: one returning a pointer to TMat2D and this one returning a integer, wich sinalizes errors
    printf("\nEscalated (by 2) sum matrice:\n");
    mat2D_print (mSum);

    mat2D_trace(m3, &trace);
    printf("\nm3:\n");
    mat2D_print (m3);
    printf("\nTrace of m3: %.1lf\n", trace);

    mat2d_increase_size(m3, 8, 8);
    printf("\nm3 after mat2d_increase_size:\n");
    mat2D_print (m3);

    printf("\n=== rows and columns sum tests ===\n(using mat2D_get_columns and mat2D_get_rows)\nm2:\n\n");
    mat2D_print (m2);
    printf("\nm2 columns sum: ");
    sumColumns = mat2D_sum_columns(m2);
    for (int i=0; i<mat2D_get_columns(m2); i++){
        printf("%.1lf ", sumColumns[i]);
    }

    printf("\nm2 rows sum: ");
    sumRows = mat2D_sum_rows(m2);
    for (int i=0; i<mat2D_get_rows(m2); i++){
        printf("%.1lf ", sumRows[i]);
    }
    printf("\n");


    mat2D_free (m1);
    mat2D_free (m2);
    mat2D_free (mSum);

    free(sumColumns);
    free(sumRows);
}
