#include <stdio.h>


int main(int argc, char *argv[]){
	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		printf("Erro ! %s",SDL_GetError());
		return 1;
	}
	
	SDL_Window *janela;
	janela = SDL_CreateWindow("Janela",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,0);
	
	if(janela == NULL){
		printf("Janela não pode ser inicializada !");
		return 1;
	}
	
	SDL_Delay(5000);
	
	SDL_DestroyWindow(janela);
	
	printf("Sucesso !");
	SDL_Quit();
}


