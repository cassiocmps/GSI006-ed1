#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "TMat2D.h"

struct TMat2D
{
  int nrows;
  int ncolumns;
  double *data;
};

TMat2D *mat2D_create(int nrows, int ncolumns){
    TMat2D *mat;
    mat = malloc(sizeof(TMat2D));
    if (mat != NULL){
        mat->data = malloc(nrows*ncolumns*sizeof(double));
        if (mat->data != NULL){
            mat->ncolumns = ncolumns;
            mat->nrows = nrows;
        } else {
            free(mat);
            return NULL;
        }
    }
    return mat;
}

int mat2D_set_value(TMat2D *mat, int i, int j, double val){
    if (mat == NULL)
        return -1;
    mat->data[j*mat->nrows + i] = val;
    return 0;
}

int mat2D_get_value(TMat2D *mat, int i, int j, double *val){
    if (mat == NULL)
        return -1;
    *val = mat->data[j*mat->nrows + i];
    return 0;
}

int mat2d_increase_size(TMat2D *mat, int rows, int columns){
    if (mat == NULL)
        return -1;
    if (rows < mat->nrows || columns < mat->ncolumns)
        return -1;
    if ((rows == mat->nrows && columns == mat->ncolumns))
        return -1;

    TMat2D *new_mat;
    new_mat = mat2D_create(rows,columns);

    for (int i = 0; i < new_mat->nrows*new_mat->ncolumns; i++){
        new_mat->data[i] = 0;
    }

    double temp;
    for (int i=0; i < mat->nrows; i++){
        for (int j=0; j < mat->ncolumns; j++){
            mat2D_get_value(mat, i, j, &temp);
            mat2D_set_value(new_mat, i, j, temp);
        }
    }
    *mat = *new_mat;
    mat2D_free(new_mat);    
    return 0;
}

int mat2D_get_value_admin(TMat2D *mat, int i, int j){
    if (mat == NULL)
        return -1;
    printf("%.1lf\t", mat->data[j*mat->nrows + i]);
    return 0;
}

int mat2D_random_mat (TMat2D *mat, double upper, double lower){
    if (mat == NULL)
        return -1;

    srand (time(NULL)); // initialize random seed for the rand() function
    for (int i = 0; i < mat->nrows*mat->ncolumns; i++) {  // use the rand() function to generate a random number in a defined range range
        mat->data[i] = (((rand()/(double)RAND_MAX)*100) / (upper - lower + 1)) + lower; // rever essa formula
    }
}

TMat2D* mat2D_sum2matrices(TMat2D *mat1, TMat2D *mat2, TMat2D *matR){
    if (mat1 == NULL || mat2 == NULL){
        return NULL;
    }
    if (mat1->ncolumns != mat2->ncolumns || mat1->nrows != mat2->nrows){
        return NULL;
    }
    
    matR = mat2D_create(mat1->nrows, mat1->ncolumns);
    for (int i = 0; i < mat1->nrows*mat1->ncolumns; i++){
        matR->data[i] = mat1->data[i] + mat2->data[i];
    }
    return matR;
}

// TMat2D *mat2D_escalate(double val, TMat2D *mat, TMat2D *matR){
//     if (mat == NULL || matR == NULL){
//         return NULL;
//     }
    
//     matR = mat2D_create(mat->nrows, mat->ncolumns);
//     for (int i = 0; i < mat->nrows*mat->ncolumns; i++){
//         matR->data[i] = val * mat->data[i];
//     }
//     return matR;
// }

int mat2D_escalate(double val, TMat2D *mat){
    if (mat == NULL)
        return -1;
        
    for (int i = 0; i < mat->nrows*mat->ncolumns; i++){
        mat->data[i] = val * mat->data[i];
    }
    return 0;
}

int mat2D_trace(TMat2D *mat, double *result){
    if (mat->ncolumns != mat->nrows || mat==NULL)
        return -1;

    double temp;
    for (int i=0; i < mat->nrows*mat->ncolumns; i++){
        if (i%(mat->nrows+1) == 0){
            temp = temp + mat->data[i];
        }
    }
    *result = temp;
    return 0;
}

double *mat2D_sum_rows(TMat2D *mat){
    if (mat == NULL){
        return NULL;
    }

    double *results = (double*)malloc(mat->nrows*sizeof(double));
    double temp=0;

    for (int i=0; i < mat->nrows; i++){
        for (int j=i; j < mat->ncolumns*mat->nrows; j+=mat->nrows){
            temp+=mat->data[j];
        }
        results[i]=temp;
        temp=0;
    }
    return results;
}

double *mat2D_sum_columns(TMat2D *mat){
    if (mat == NULL){
        return NULL;
    }

    double *results = (double*)malloc(mat->ncolumns*sizeof(double));

    results[0]=0;
    for (int i=0, c=0, j=0; i < mat->ncolumns*mat->nrows; i++){
        if (c < mat->nrows){
            results[j] += mat->data[i];
            c++;
        }
        else {
            results[j+1] = mat->data[i];
            j++;
            c=1;
        }
    }
    return results;
}

int mat2D_get_rows(TMat2D *mat){
    if (mat ==NULL)
        return 0;
    return mat->nrows;
}

int mat2D_get_columns(TMat2D *mat){
    if (mat ==NULL)
        return 0;
    return mat->ncolumns;
}


int mat2D_print (TMat2D *mat){
    if (mat == NULL)
        return -1;
    if (mat->data == NULL)
        return -1;
    
    for (int i = 0; i < mat->nrows; i++){
        for (int j = 0; j < mat->ncolumns; j++){
            mat2D_get_value_admin(mat, i, j);
        }
        printf("\n");
    }
    return 0;
}

void mat2D_free(TMat2D *mat){
    free(mat->data);
    free(mat);
}