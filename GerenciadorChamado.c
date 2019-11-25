#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//#include <string.h>

// http://linguagemc.com.br/struct-em-c/
// https://www.inf.pucrs.br/~pinho/LaproI/Listas/Listas1.htm
// https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html
// https://medium.com/aprendacpp/criando-uma-lista-encadeada-em-c-17e7f5692f36

int menu = -1;

typedef struct cha {//ESTRUTURA DE DADOS

	int id;
	char titulo[40];
	int status;
	struct cha *proximo;

} chamado;

typedef struct agen {//ESTRUTURA DE DADOS

    int id;
	int idChamado;
	char dataAgendamento[12]; // 25/11/2019
	char horaAgendamento[10]; // 23:59:59
	struct agen *proximo; // PONTEIRO DE ESTRUTURA AGEN

} agenda;

chamado *listaChamados = NULL; // LISTA DE CHAMADOS PARA ARMAZENAR OS CHAMADOS DO SISTEMA.(PONTEIRO)

agenda *listaDeAgendamentos = NULL;

int gerarIdChamado(){

	int id = 0;

	chamado *tmpChamado = listaChamados;

    while(tmpChamado != NULL){

    	if(tmpChamado->id >= id){

    		id = tmpChamado->id;

		}

    	tmpChamado = tmpChamado->proximo;

	}

	id += 1;

	return id;

}

int gerarIdAgendamento(){

	int id = 0;

	agenda *tmpDeAgendamentos = listaDeAgendamentos;

    while(tmpDeAgendamentos != NULL){

    	if(tmpDeAgendamentos->id >= id){

    		id = tmpDeAgendamentos->id;

		}

    	tmpDeAgendamentos = tmpDeAgendamentos->proximo;

	}

	id += 1;

	return id;

}

void cadastrarChamados(){

	printf("\n---------- Cadastro de chamados -----------\n\n");

	chamado *tmpChamado = (chamado *) malloc(sizeof(chamado));

	tmpChamado->id = gerarIdChamado();

    printf("ID Chamado...: %d\n", tmpChamado->id);

	printf("Titulo ......: ");
	fflush(stdin);
	fgets(tmpChamado->titulo, 40, stdin);

	printf("Status ......: ");
	scanf("%i", &tmpChamado->status);

	if(listaChamados == NULL){

		tmpChamado->proximo = NULL;

		listaChamados = tmpChamado;

	} else {

		tmpChamado->proximo = listaChamados;
		listaChamados = tmpChamado;

	}

	printf("\nChamado adicionado com sucesso !!!\n");
	printf("Precione enter para voltar ao menu");
	getch();

}

void cadastrarAgendamentos(){

    int id = 0;
    int chamadoValido = 0;

    printf("Digite o ID do chamado: ");
    scanf("%i", &id);

    chamado *tmpChamado = listaChamados;

    while(tmpChamado != NULL){

        if (id == tmpChamado->id){
           chamadoValido = tmpChamado->id;
        }

        tmpChamado = tmpChamado->proximo;

    }

    if(chamadoValido == 0){

        printf("Chamado invalido.\nPrecione enter para voltar ao menu.");
        getch();

    } else {
        system("cls");
        printf("\n---------- Cadastro de Agendamentos -----------\n\n");

        agenda *tmpAgendamento = (agenda *) malloc(sizeof(agenda));

        tmpAgendamento->id = gerarIdAgendamento();
        tmpAgendamento->idChamado = id;

        printf("ID Agenda ................: %d\n", tmpAgendamento->id);

        printf("ID Chamado................: %d\n", tmpAgendamento->idChamado);

        printf("Data do agendamento ......: ");
        fflush(stdin);
        fgets(tmpAgendamento->dataAgendamento, 12, stdin);

        printf("Hora do agendamento ......: ");
        fflush(stdin);
        fgets(tmpAgendamento->horaAgendamento, 10, stdin);

        if(listaDeAgendamentos == NULL){

            tmpAgendamento->proximo = NULL;

            listaDeAgendamentos = tmpAgendamento;

        } else {

            tmpAgendamento->proximo = listaDeAgendamentos;
            listaDeAgendamentos = tmpAgendamento;

            agenda *listaDeAgendamentos = NULL;

        }

        printf("\nAgenda adicionada com sucesso !!!\n");
        printf("Precione enter para voltar ao menu");
        getch();

    }

}

void alterarChamados(){

    int id = 0;

    printf("Digite o ID do chamado: ");
    scanf("%i", &id);

    chamado *tmpChamado = listaChamados;

    while(tmpChamado != NULL){

        if (id == tmpChamado->id){
            system("cls");
            printf("\n---------- Alterar chamados -----------\n\n");

            printf("ID Chamado ...: %i\n", tmpChamado->id);

            printf("Titulo .......: ");
            fflush(stdin);
            fgets(tmpChamado->titulo, 40, stdin);

            printf("Status .......: ");
            scanf("%i", &tmpChamado->status);

        }

        tmpChamado = tmpChamado->proximo;

    }

    printf("\nPrecione enter para voltar ao menu");
    getch();

}

void acompanharChamados(){

    printf("+-------------------------------------------------+\n");
	printf("|---------- Acompanhamento de chamados -----------|\n");
	printf("+-------------------------------------------------+\n\n");

	chamado *tmpChamado = listaChamados;

    while(tmpChamado != NULL){

    	printf("ID ...............: %i\n", tmpChamado->id);
    	printf("Titulo ...........: %s", tmpChamado->titulo);
		printf("Status ...........: %i\n\n", tmpChamado->status);

    	tmpChamado = tmpChamado->proximo;

	}

}

void acompanharAgendamentos(){

    printf("+-------------------------------------------------+\n");
	printf("|---------- Acompanhamento de Agendamentos -------|\n");
	printf("+-------------------------------------------------+\n\n");

	agenda *tmpAgenda = listaDeAgendamentos;

    while(tmpAgenda != NULL){

    	printf("ID Agenda ................: %i\n", tmpAgenda->id);
    	printf("ID Chamado ...............: %i\n", tmpAgenda->idChamado);
    	printf("Data do agendamento ......: %s", tmpAgenda->dataAgendamento);
		printf("Hora do agendamento ......: %i\n\n", tmpAgenda->horaAgendamento);

    	tmpAgenda = tmpAgenda->proximo;

	}

}

void removerChamados(){

	printf("---------- Remocao de chamados -----------\n\n");

	int id = 0;
	printf("Digite o ID do chamado para remover ......: ");
	scanf("%i", &id);

	chamado *prt = listaChamados;
	chamado *antes = listaChamados;

    while(prt != NULL){

		if(prt->id == id){

			if(prt == listaChamados){

				listaChamados = listaChamados->proximo;
				free(prt);

			} else {

				antes->proximo = prt->proximo;
				free(prt);

			}

		} else {

			antes = prt;
			prt = prt->proximo;

		}

	}

    printf("\nPrecione enter para voltar ao menu");
	getch();

}

void menuCliente(){

	printf("Menu > 1 Cliente\n");
	printf("-------------------------------\n");
	printf("1 - Criar chamados\n");
	printf("2 - Acompanhar chamados\n");
	printf("3 - Remover chamados\n");
	printf("4 - Voltar\n");
	printf("0 - Sair \n");

	int menuCliente = -1;
	printf("Selecione o menu: ");
	scanf("%i", &menuCliente);
	system("cls");

	switch(menuCliente){
		case 1:
			cadastrarChamados();
			break;

		case 2:
			acompanharChamados();
            printf("Precione enter para voltar ao menu");
            getch();
			break;

		case 3:
			removerChamados();
			break;

		case 4:
			menu = -1;
			break;

		case 0:
			menu = 0;
			break;
	}

}

void menuGerente(){

		printf("Menu > 2 Gerente\n");
		printf("-------------------------------\n");
		printf("1 - Acompanhar chamados\n");
		printf("2 - Alterar chamados\n");
		printf("3 - Agendar visita tecnica\n");
		printf("4 - Relatorios\n");
		printf("5 - Voltar\n");
		printf("0 - Sair \n");

		int menuGerente = -1;
		printf("Selecione o menu: ");
		scanf("%i", &menuGerente);
		system("cls");

		switch(menuGerente){
			case 1:
				acompanharChamados();
                printf("Precione enter para voltar ao menu");
                getch();
			break;

			case 2:
                alterarChamados();
			break;

			case 3:
				cadastrarAgendamentos();
			break;

			case 4:
				acompanharChamados();
				acompanharAgendamentos();
				printf("Precione enter para voltar ao menu");
                getch();
			break;

			case 5:
				menu = -1;
			break;

			case 0:
				menu = 0;
			break;
		}

}

void menuPrincipal(){

	printf("Menu\n");
	printf("-------------------------------\n");
	printf("1 - Cliente\n");
	printf("2 - Gerente\n");
	printf("0 - Sair \n");

	printf("Selecione o menu: ");
	scanf("%i", &menu);

}

int main (void){

	while(menu != 0){

		switch(menu){

			case 1:
				menuCliente();
				break;

			case 2:
				menuGerente();
				break;

			default:
				menuPrincipal();


		}

		system("cls");

	}

	return 0;


}

