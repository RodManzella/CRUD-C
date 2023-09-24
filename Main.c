#include <stdio.h>
#include <stdlib.h>

//o conjunto desses dados vai direcionar o usuário até o livro na estante
typedef struct{
    char nome_do_autor[100];
    //char sobrenome_do_autor[20]; // p conciliar diante do problema do gets
    char titulo_do_livro[100];
    char local_de_publicacao[100]; //onde o livro foi publicado -lugar geográfico-
    char editora_do_livro[100]; 
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
    arquivo = fopen("livros.txt","r+b");
    if(arquivo == NULL){
      arquivo = fopen("livros.txt", "w+b"); //-> para a primeira vez rodando
        //printf("Erro!");
    }
}

void linha() {
  int i;
  
  for (i = 1; i <= 50; i++)
    printf("_");
}

void cadastrar_o_livro() {
  int x;
  do
  {
    printf("--CADASTRO DE LIVRO--\n");
    /*printf("Digite o nome do autor: ");
    scanf("%s", &dados_livro.nome_do_autor);*/

    printf("Digite o nome do autor: ");
    getchar();
    fgets(dados_livro.nome_do_autor, sizeof(dados_livro.nome_do_autor), stdin);
    //scanf("%s", &dados_livro.nome_do_autor);

    /*printf("Digite o sobrenome do autor: ");
    scanf("%s", &dados_livro.sobrenome_do_autor);*/

    printf("Digite o título do livro: ");
    //getchar();
    gets(dados_livro.titulo_do_livro,     sizeof(dados_livro.titulo_do_livro), stdin);
    fflush(stdin);
    //scanf("%s", &dados_livro.titulo_do_livro);
    
    printf("Digite o local de publicacao: ");
     //getchar();
    fflush(stdin);
    gets(dados_livro.local_de_publicacao,     sizeof(dados_livro.local_de_publicacao), stdin);
    //scanf("%s", &dados_livro.local_de_publicacao);

    printf("Digite a editora do livro: ");
    // getchar();
    fflush(stdin);
    gets(dados_livro.editora_do_livro,     sizeof(dados_livro.editora_do_livro), stdin);
    //scanf("%s", &dados_livro.editora_do_livro);

    printf("Digite o ano do livro: ");
    scanf("%d", &dados_livro.ano_do_livro);
   
    printf("Digite o número de páginas: ");
    scanf("%d", &dados_livro.paginacao);

    printf("Digite o número de exemplar: ");
    scanf("%d", &dados_livro.numero_de_exemplar_do_livro);

    printf("Digite o número de chamada: ");
    scanf("%d", &dados_livro.numero_de_chamada);

    printf("Digite o estoque: ");
    scanf("%d", &dados_livro.estoque);
    

      fseek(arquivo, 0, SEEK_END);
        fwrite(&dados_livro, sizeof(Ficha_Catalografica), 1, arquivo);

        printf("Cadastro concluído com sucesso!\n");

    printf("Voce quer fazer um novo cadastro? Digite 1 para não, ou digite 2 para sim: ");
    scanf("%d", &x);
  } while (x != 1);
}

int procura_Livro(int numero_de_exemplar_do_livro){
	
	int p;
	p = 0;
	rewind(arquivo);
	fread(&dados_livro, sizeof(Ficha_Catalografica), 1,arquivo);
	
	while(feof(arquivo) == 0){
		if(dados_livro.numero_de_exemplar_do_livro == numero_de_exemplar_do_livro){

			return p;
		}
		else{
			fread(&dados_livro, sizeof(Ficha_Catalografica), 1, arquivo);
			p++;
		}
	}
	return -1;
}

// só é chamado quando o remover é solicitado
void mostrarLivro(int pos) {
   fseek(arquivo, pos * sizeof(Ficha_Catalografica), SEEK_SET); //direciona
  fread(&dados_livro, sizeof(Ficha_Catalografica), 1, arquivo);
    printf("Dados do Livro:\n");
    printf("Autor: %s", dados_livro.nome_do_autor);
    printf("Título: %s\n", dados_livro.titulo_do_livro);
    printf("Local de Publicação: %s\n", dados_livro.local_de_publicacao);
    printf("Editora: %s\n", dados_livro.editora_do_livro);
    printf("Ano de Publicação: %d\n", dados_livro.ano_do_livro);
    printf("Número de Páginas: %d\n", dados_livro.paginacao);
    printf("Número de Exemplar: %d\n", dados_livro.numero_de_exemplar_do_livro);
    printf("Número de Chamada: %d\n", dados_livro.numero_de_chamada);
    printf("Estoque: %d\n", dados_livro.estoque);
}

void consultar_livro(){
    int num, escolha;
    do{
      printf("Digite o número de exemplar: ");
      scanf("%d", &num);
      int var = procura_Livro(num);
      if(var == -1){
        printf("Livro não encontrado!");
      }
      else{
          mostrarLivro(var);
      }
      printf("\n\n\nDeseja consultar outro livro (1-não/2-sim)? ");
          scanf("%d", &escolha);
  }while(escolha != 1);
}
void remover_livro() {
    int numero_de_exemplar_do_livro, escolha, resp, posicao;
    memset(&livro_null, 0, sizeof(Ficha_Catalografica)); // Inicializa a estrutura com zeros

    do {
        printf("\n\nRemover livro\n\n\n");
        printf("Digite o número de exemplar do livro desejado: ");
        scanf("%d", &numero_de_exemplar_do_livro);
        posicao = procura_Livro(numero_de_exemplar_do_livro);

        if (posicao == -1) {
            printf("\nLivro não encontrado!\a");
        } else {
            mostrarLivro(posicao);
            printf("\n\nDeseja remover o livro (1-sim/0-não)? ");
            scanf("%d", &escolha);
            if (escolha == 1) {
                fseek(arquivo, posicao * sizeof(Ficha_Catalografica), SEEK_SET); //direciona
                fwrite(&livro_null, sizeof(Ficha_Catalografica), 1, arquivo); //e seta escrevendo naquela posição como nulo, ou seja, removido
                printf("\n\nLivro removido com sucesso!");
            } else {
                printf("\nRemoção cancelada!");
            }
        }

        printf("\n\n\nDeseja remover outro (1-sim/0-não)? ");
        scanf("%d", &resp);
    } while (resp == 1);
}


void listarLivros() {
    int cont = 1;
    printf("Lista de Livros Cadastrados:\n");

    // Voltar ao início do arquivo
    fseek(arquivo, 0, SEEK_SET);

    // Ler e listar os livros enquanto o arquivo não chegar ao fim
 // Para listar os livros corretamente, ler os registros do arquivo usando a função fread() e verificar o final do arquivo (feof()) para determinar quando parar de listar os livros. 
    while (fread(&dados_livro, sizeof(Ficha_Catalografica), 1, arquivo) == 1) {
      printf("\n\n");
      printf("Livro %d\n", cont);
        printf("Autor: %s", dados_livro.nome_do_autor);
        printf("Título: %s\n", dados_livro.titulo_do_livro);
        printf("Local de Publicação: %s\n", dados_livro.local_de_publicacao);
        printf("Editora: %s\n", dados_livro.editora_do_livro);
      
 printf("Ano do livro: %d\n",dados_livro.ano_do_livro);
        printf("Número de Páginas: %d\n", dados_livro.paginacao);
        printf("Número de Exemplar: %d\n", dados_livro.numero_de_exemplar_do_livro);
        printf("Número de Chamada: %d\n", dados_livro.numero_de_chamada);
      printf("Estoque: %d\n", dados_livro.estoque);
      
        printf("\n"); // Separar cada livro com uma linha em branco
      linha();
     cont++;
    }
}

void alterar_livro() // alterar o estoque 
{
  int etqAlt, conf, resp, posicao;

  do {
    printf("\n\nAlterar estoque do livro\n\n");
    printf("Digite o número exemplar do livro: ");
    scanf("%d", &etqAlt);
    posicao = procura_Livro(etqAlt);

    if(posicao == -1){
        printf("\nLivro não encontrado!\a");
    }
    else{
      mostrarLivro(posicao);
      printf("\n\nAlterar o estoque do livro(1-sim/0-não)? ");
      scanf("%d", &conf);

      if(conf == 1){
        printf("\nNovo estoque: ");
        scanf("%d", &dados_livro.estoque);
        printf("\nEstoque alterado com sucesso!\n\n");
        fseek(arquivo, posicao*sizeof(Ficha_Catalografica), SEEK_SET);
        fwrite(&dados_livro,sizeof(Ficha_Catalografica), 1, arquivo);
        mostrarLivro(posicao);
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
        printf("Digite 5 para: Alterar o estoque do livro \n\n");
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
          case 5:
              alterar_livro();
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