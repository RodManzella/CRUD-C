#include <stdio.h>
#include <stdlib.h>

//o conjunto desses dados vai direcionar o usuário até o livro na estante
typedef struct{
    char nome_do_autor[20];
    char titulo_do_livro[20];
    char local_de_publicacao[20]; //onde o livro foi publicado
    char editora_do_livro[20]; 
    int ano_do_livro;
    int paginacao; // quantas páginas o livro tem
    int numero_de_exemplar_do_livro; // cada livro recebe um número de exemplar que é como se fosse a identidade dele
   // char categoria_do_livro[20]; -> pelo que vi na ficha catalográfica lá nao precisaria disso assim
    int numero_de_chamada; // uma numeração conhecida como número de chamada, que é composta por uma numração que identifica o assunto e o autor
    int estoque; // quantos livros vão ser cadastrados
} Ficha_Catalografica;

FILE *arquivo; //FILE -> tipo de dado(definido pela biblioteca padrão do C -> stdio.h)usado para manipular arquivo e arquivo é uma variavel que é um ponteiro que armazena o endereço de memória de uma estrutura do tipo FILE

Ficha_Catalografica dados_livro, livro_null; // dados_livro -> é usada para armazenar temporariamente dados de livros durante operações como inserção, consulta e alteração. livro_null -> é usada para representar livros removidos no arquivo, permitindo que o programa marque alunos que foram excluídos sem a necessidade de excluir fisicamente seus registros do arquivo, portanto ele tem informações vazias.

void abrir_arquivo_txt(){
    arquivo = fopen("livros.txt","r");
    if(arquivo == NULL){
        printf("Erro!");
    }
}

void cadastrar_o_livro() {
  int x;
  do
  {
    printf("--CADASTRO DE LIVRO--");
    printf("Digite o nome do autor: ");
    scanf("%s", &dados_livro.nome_do_autor);

    printf("Digite o título do livro: ");
    scanf("%s", &dados_livro.titulo_do_livro);

    printf("Digite o local de publicacao: ");
    scanf("%s", &dados_livro.local_de_publicacao);

    printf("Digite a editora do livro: ");
    scanf("%s", &dados_livro.editora_do_livro);

    printf("Digite o ano do livro: ");
    scanf("%d", &dados_livro.ano_do_livro);

    printf("Digite o número de páginas: ");
    scanf("%d", &dados_livro.paginacao);

    printf("Digite o número de exemplar: ");
    scanf("%d", &dados_livro.numero_de_exemplar_do_livro);

    printf("Digite o número de chamada: ");
    scanf("%d", &dados_livro.numero_de_chamada);

    printf("Voce quer fazer um novo cadastro?");
    scanf("%d", &x);
  } while (x != 1);
}

// int procura_Livro(int numero_de_exemplar_do_livro){

//}

//void mostre(int parametro){  // ver qual é o parametro adaptado

//}


void mostrarLivro(Ficha_Catalografica idlivro) {
    printf("Dados do Livro:\n");
    printf("Autor: %s\n", idlivro.nome_do_autor);
    printf("Título: %s\n", idlivro.titulo_do_livro);
    printf("Local de Publicação: %s\n", idlivro.local_de_publicacao);
    printf("Editora: %s\n", idlivro.editora_do_livro);
    printf("Ano de Publicação: %d\n", idlivro.ano_do_livro);
    printf("Número de Páginas: %d\n", idlivro.paginacao);
    printf("Número de Exemplar: %d\n", idlivro.numero_de_exemplar_do_livro);
    printf("Número de Chamada: %d\n", idlivro.numero_de_chamada);
}

void consultar_livro(){

}

void remover_livro(){

}

//void listagem(){

//}

void listarLivros(ficha_catalografica livros[], int numLivros) {
    printf("Lista de Livros Cadastrados:\n");
    for (int i = 0; i < numLivros; i++) {
        printf("Livro %d:\n", i + 1);
        printf("Autor: %s\n", livros[i].nome_do_autor);
        printf("Título: %s\n", livros[i].titulo_do_livro);
	      printf("Local de Publicação: %d\n", livros[i].local_de_publicação);
        printf("Editora: %d\n", livros[i].editora_do_livro);
	      printf("Ano de Publicação: %d\n", livros[i].ano_do_livro);
	      printf("Número de Páginas: %d\n", livros[i].paginacao);
	      printf("Número de Exemplar: %d\n", livros[i].numero_de_exemplar_do_livro);
	      printf("Número de Chamada: %d\n", livros[i].numero_de_chamada);
    }
}

//void alterar(int estoque){ // alterar o estoque

//}
void alterar() // alterar o estoque
{
  int etqAlt, conf, resp, posicao;

  do {
    printf("\n\nAlterar estoque do livro");
    printf("Número exemplar do livro");
    scanf("%d", &etqAlt);
    posicao = procura_Livro(etqAlt);

    if(posicao == -1){
        printf("\nLivro não encontrado!\a");
    }
    else{
      mostre(posicao);
      printf("\n\nAlterar o estoque do livro(1-sim/0-não)? ");
      scanf("%d", &conf);

      if(conf == 1){
        printf("\nNovo estoque: ");
        scanf("%f", &livro_aux.estoque);
        printf("\nEstoque alterado com sucesso!\n\n");
        fseek(arquivo, posicao*sizeof(ficha_catalografica), SEEK_SET);
        fwrite(&livro_aux,sizeof(ficha_catalografica), 1, arquivo);
        mostre(posicao);
        printf("\nEstoque do livro alterado com sucesso!\n");
      }
      else{
        printf("\n\nAlteração cancelada");
      }
    }

    printf("\n\nDeseja alterar outro (1-sim/0-não) ?");
    scanf("%d", &resp);

  } while (resp == 1);
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

        switch(escolha){
            case 1:
              cadastrar_o_livro();
              break;
            case 2:
              remover_livro();
              break;
            case 3:   
              consultar_livro();
              break;
            case 4:
              listarLivros();
              break;
            case -1:
              fclose(arquivo);
              break;
            default:
              printf("\n\n\a Digite uma opção válida");
              break;
        }

    }while(escolha != -1);

    return 0;
}