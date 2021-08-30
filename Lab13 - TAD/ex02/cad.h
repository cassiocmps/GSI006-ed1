typedef struct aluno aluno;

aluno* cadastra_aluno(char nome[], char matricula[], double cra);
void imprime_aluno(aluno* p);
int destroi_aluno (aluno* p);
int atualizar_cra(aluno* p, double novo_cra);
int copia_dados(aluno* p, char *nome, char *matricula, double *cra);
