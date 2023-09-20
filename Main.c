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
    int estoque; // quantos livros vão ser cadastrados
} ficha_catalografica;

FILE *arquivo; //FILE -> tipo de dado(definido pela biblioteca padrão do C -> stdio.h)usado para manipular arquivo e arquivo é uma variavel que é um ponteiro que armazena o endereço de memória de uma estrutura do tipo FILE

void abrir_arquivo_txt(){
    arquivo = fopen("livros.txt","r");
    if(arquivo == NULL){
        printf("Erro!");
    }
}

void cadastrar_o_livro(){

}

// int procura_Livro(int numero_de_exemplar_do_livro){

//}

//void mostre(int parametro){  // ver qual é o parametro adaptado

//}

void consultar_livro(){

}

void remover_livro(){

}

void listagem(){

}

void alterar(int estoque){ // alterar o estoque

}

int main(){
    int escolha;
    abrir_arquivo_txt();
    // do - while para realizar a execução pelo menos uma vez
    do{
        printf("\n\n\n Escolha uma das opções abaixo: \n\n\n");
        printf(" Digite 1 para: Cadastrar um novo livro \n\n");
        printf(" Digite 2 para: Remover um livro \n\n");
        printf(" Digite 3 para: Consultar um livro pelo número exemplar \n\n"); //acredito que seja pelo ID 
        printf(" Digite 4 para: Ver os livros cadastrados no sistema \n\n");
        printf(" Digite -1 para: Sair\n\n");

        scanf("%d", &escolha);



    }while(escolha != -1);
    return 0;
}