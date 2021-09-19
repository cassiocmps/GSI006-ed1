
typedef struct TMat2D TMat2D; 

TMat2D *mat2D_create(int nrows, int ncolumns);
void mat2D_free(TMat2D *mat);

int mat2D_set_value(TMat2D *mat, int i, int j, double val);
int mat2D_get_value(TMat2D *mat, int i, int j, double *val);
int mat2D_random_mat (TMat2D *mat, double upper, double lower);
TMat2D* mat2D_sum2matrices(TMat2D *mat1, TMat2D *mat2, TMat2D *matR);
int mat2D_escalate(double val, TMat2D *mat);
// TMat2D *mat2D_escalate(double val, TMat2D *mat, TMat2D *matR);
int mat2D_trace(TMat2D *mat, double *result);
double *mat2D_sum_rows(TMat2D *mat);
double *mat2D_sum_columns(TMat2D *mat);
int mat2D_get_rows(TMat2D *mat);
int mat2D_get_columns(TMat2D *mat);
int mat2D_print (TMat2D *mat);