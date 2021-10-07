/*
 3) Considerando o TAD Matriz implementado em aula², crie uma nova 
função que permite aumentar o tamanho da matriz (mat2d_increase_size).
Os elementos da matriz original devem continuar na mesma posição que
estavam antes do aumento. Os novos elementos devem receber valor 0.
Por exemplo, caso o usuário tenha uma matriz 2x2 e queria que ela vire uma 
matriz 3x3, ele poderá usar a função de aumento de tamanho como
abaixo:

// criando matriz 2x2
mat = mat2D_create(2,2);

// Exemplo de preenchimento
// |2 7|
// |4 5|

// aumentando o tamanho da matriz para 3x3
mat2d_increase_size(mat,3,3)

// Exemplo após o aumento de tamanho
// |2 7 0|
// |4 5 0|
// |0 0 0|



²struct TMat2D
 {
  int nrows; // número de linhas
  int ncolumns; // número de colunas
  double *data; // ponteiro para os dados da matriz
 };

*/
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
    *mat = *new_mat;// check:<<<erro: essa cópia fez só a cópia do ponteiro para o data>>>>
    mat2D_free(new_mat);    // check:<<<erro: então, ao chamar aqui vc acaba apagando o data>>>>
    return 0;
}

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

void mat2D_free(TMat2D *mat){
    free(mat->data);
    free(mat);
}