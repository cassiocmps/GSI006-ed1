typedef struct aluno aluno;

struct aluno {
    char nome[50];
    char matricula[20];
    double cra;
};

void cadastraAluno(int tamanho, aluno *vetor);
