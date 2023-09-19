#include <stdio.h>
#include <stdlib.h>

//o conjunto desses dados vai direcionar o usuário até o livro na estante
typedef struct{
    char nome_do_autor[20]
    char titulo_do_livro[20];
    char local_de_publicacao[20]; //onde o livro foi publicado
    char editora_do_livro[20]; 
    int ano_do_livro;
    int paginacao; // quantas páginas o livro tem
    int numero_de_exemplar_do_livro; // cada livro recebe um número de exemplar que é como se fosse a identidade dele
   // char categoria_do_livro[20]; -> pelo que vi na ficha catalográfica lá nao precisaria disso assim
    int numero_de_chamada; // uma numeração conhecida como número de chamada, que é composta por uma numração que identifica o assunto e o autor
} ficha_catalografica;

int main(){

    return 0;
}