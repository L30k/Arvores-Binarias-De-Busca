#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Da arvore
typedef struct no No;

typedef struct no{
    double chave;
    No *dir, *esq, *pai;
}No;

typedef struct abb{
     No *raiz;
}ABB;


ABB *criarArvore();
void inserirArvore(ABB *a, double chave);
double menorChaveArvore(ABB *a);
double maiorChaveArvore(ABB *a);
bool buscaChaveArvore(ABB *a, double chave);
double excluirChaveArvore(ABB *a, double chave);

void preOrdemArvore(ABB *a);
void emOrdemArvore(ABB *a);
void posOrdemArvore(ABB *a);


void inserirArvoreAux(No *pai, double chave);
double menorChaveArvoreAux(No *pai);
double maiorChaveArvoreAux(No *pai);
bool buscaChaveArvoreAux(No *pai, double chave);
double excluirChaveArvoreAux(No *pai, double chave);
No *excluirChaveArvoreAux2(No *pai);

void preOrdemArvoreAux(No *pai);
void emOrdemArvoreAux(No *pai);
void posOrdemArvoreAux(No *pai);

No *criarNo(double chave);

//Main
int main()
{
    ABB *arv = criarArvore();
    double chave;
    int ops;
    
    system("cls || clear");
    while(1){
        printf("Escolha uma opicao.\n");
        printf("1. Inserir um chave.\n");
        printf("2. Buscar a menor chave.\n");
        printf("3. Buscar a maior chave.\n");
        printf("4. Mostar em pre-Ordem.\n");
        printf("5. Mostar em em-Ordem.\n");
        printf("6. Mostar em pos-Ordem.\n");
        printf("7. Procurar uma chave.\n");
        printf("8. Escluir uma chave.\n");
        printf("9. Finaliar o programa.\n");
        scanf("%d", &ops);
        getchar();
        
        switch(ops){
            case 1:
                system("cls || clear");
                printf("1. Inserir um chave.\n");
                
                printf("Qual o valor da chave?\n");
                scanf("%lf", &chave);
                
                inserirArvore(arv, chave);
                
                break;
            case 2:
                system("cls || clear");
                printf("2. Buscar a menor chave.\n");
                
                printf("A menor chave e %lf.\n", menorChaveArvore(arv));
                
                break;
            case 3:
                system("cls || clear");
                printf("3. Buscar a maior chave.\n");
                
                printf("A maior chave e %lf.\n", maiorChaveArvore(arv));
                
                break;
            case 4:
                system("cls || clear");
                printf("4. Mostar em pre-Ordem.\n");
                
                preOrdemArvore(arv);
                
                break;
            case 5:
                system("cls || clear");
                printf("5. Mostar em em-Ordem.\n");
                
                emOrdemArvore(arv);
                
                break;
            case 6:
                system("cls || clear");
                printf("6. Mostar em pos-Ordem.\n");
                
                posOrdemArvore(arv);
                
                break;
            case 7:
                system("cls || clear");
                printf("7. Procurar uma chave.\n");
                
                printf("Qual o valor da chave?\n");
                scanf("%lf", &chave);
                
                if(buscaChaveArvore(arv, chave)){
                    printf("Chave encontrada.\n");
                }else{
                    printf("Chave nao encontrada.\n");
                }
                
                break;
            case 8:
                system("cls || clear");
                printf("8. Escluir uma chave.\n");
                
                printf("Qual o valor da chave?\n");
                scanf("%lf", &chave);
                
                excluirChaveArvore(arv, chave);
                printf("Valor escluido.\n");
                
                break;
            case 9:
                system("cls || clear");
                printf("9. Finaliar o programa.\n");
                
                return 0;
            default:
                system("cls || clear");
                printf("O valor nao corresponde a nada.\n");
            
        }
    }
    
    return 0;
}


//Da arvore
ABB *criarArvore(){
    ABB *novo = malloc(sizeof(ABB));
    novo->raiz = NULL;
    
    return novo;
}

void inserirArvore(ABB *a, double chave){
    if(a->raiz == NULL){
        No *novo = criarNo(chave);
        
        a->raiz = novo;
    }else{
        inserirArvoreAux(a->raiz, chave);
    }
}

double menorChaveArvore(ABB *a){
    if(a->raiz ==  NULL){
        return ;
    }else if (a->raiz->esq == NULL){
        return a->raiz->chave;
    }else{
        return menorChaveArvoreAux(a->raiz);
    }
}

double maiorChaveArvore(ABB *a){
    if(a->raiz ==  NULL){
        return ;
    }else if (a->raiz->esq == NULL && a->raiz->dir == NULL){
        return a->raiz->chave;
    }else{
        return maiorChaveArvoreAux(a->raiz);
    }
}

bool buscaChaveArvore(ABB *a, double chave){
    if(a->raiz == NULL){
        return false;
    }else{
        return buscaChaveArvoreAux(a->raiz, chave);
    }
}

double excluirChaveArvore(ABB *a, double chave){
    if(a->raiz == NULL){
        return ;
    }else{
        return excluirChaveArvoreAux(a->raiz, chave);
    }
}

//Aux
No *criarNo(double chave){
    No *novo = malloc(sizeof(No));
    novo->chave = chave;
    novo->dir = NULL;
    novo->esq = NULL;
    novo->pai = NULL;
    
    return novo;
}

void inserirArvoreAux(No *pai, double chave){
    if(pai->chave < chave){
        if(pai->dir == NULL){
            No *novo = criarNo(chave);
            
            novo->pai = pai;
            pai->dir = novo;
        }else{
            inserirArvoreAux(pai->dir, chave);
        }
    }else{
        if(pai->esq == NULL){
            No *novo = criarNo(chave);
            
            novo->pai = pai;
            pai->esq = novo;
        }else{
            inserirArvoreAux(pai->esq, chave);
        }
    }
}

double menorChaveArvoreAux(No *pai){
    if(pai->esq != NULL){
        return menorChaveArvoreAux(pai->esq);
    }else{
        return pai->chave;
    }
}

double maiorChaveArvoreAux(No *pai){
    if(pai->dir != NULL){
        return maiorChaveArvoreAux(pai->dir);
    }else {
        return pai->chave;
    }
}

bool buscaChaveArvoreAux(No *pai, double chave){
    if(pai->chave == chave){
        return true;
    }else if(pai->chave > chave){
        if(pai->esq == NULL){
            return false;
        }else{
            return buscaChaveArvoreAux(pai->esq, chave);
        }
    }else{
        if(pai->dir == NULL){
            return false;
        }else{
            return buscaChaveArvoreAux(pai->dir, chave);
        }
    }
}

double excluirChaveArvoreAux(No *pai, double chave){
    if(pai->chave == chave){
        printf("Acho o valor %lf.\n", pai->chave);
        No *aux = pai;
        double valor = pai->chave;
        
        if(pai->dir == NULL && pai->esq == NULL){
            printf("teste");
            if(pai->pai->esq->chave == chave){
                pai->pai->esq = NULL;
            }else if(pai->pai->dir->chave == chave){
                pai->pai->dir = NULL;
            }
            free(aux);
            
            return valor;
        }else{
            No *folha = excluirChaveArvoreAux2(pai->esq);
            
            if(folha->pai->dir->chave == chave){
                folha->pai->dir = NULL;
            }else if((folha->pai->esq->chave == chave)){
                folha->pai->esq = NULL;
            }
            
            pai->chave = folha->chave;
            
            free(folha);
        }
    }else{
        if(pai->esq == NULL && pai->dir == NULL){
            return ;
        }else if(pai->chave > chave){
            if(pai->esq == NULL){
                return ;
            }else{
                return excluirChaveArvoreAux(pai->esq, chave);
            }
        }else{
            if(pai->dir == NULL){
                return ;
            }else{
                return excluirChaveArvoreAux(pai->dir, chave);
            }
        }
    }
}

No *excluirChaveArvoreAux2(No *pai){
    if(pai->dir == NULL){
        return pai;
    }else{
        return excluirChaveArvoreAux2(pai->dir);
    }
}

//Ordem
void preOrdemArvore(ABB *a){
    if(a->raiz != NULL)
        preOrdemArvoreAux(a->raiz);
    else
        printf("Arvore vazia!\n");
}

void emOrdemArvore(ABB *a){
    if(a->raiz != NULL){
        emOrdemArvoreAux(a->raiz);
    }else{
        printf("Arvore vazia!\n");
    }
}

void posOrdemArvore(ABB *a){
    if(a->raiz != NULL){
        posOrdemArvoreAux(a->raiz);
    }else{
        printf("Arvore vazia!\n");
    }
}

void preOrdemArvoreAux(No *pai){
    if(pai != NULL){
        printf("Chave %lf.\n", pai->chave);
        preOrdemArvoreAux(pai->esq);
        preOrdemArvoreAux(pai->dir);
    }
}

void emOrdemArvoreAux(No *pai){
    if(pai != NULL){
        preOrdemArvoreAux(pai->esq);
        printf("Chave %lf.\n", pai->chave);
        preOrdemArvoreAux(pai->dir);
    }
}

void posOrdemArvoreAux(No *pai){
    if(pai != NULL){
        preOrdemArvoreAux(pai->esq);
        preOrdemArvoreAux(pai->dir);
        printf("Chave %lf.\n", pai->chave);
    }
}

