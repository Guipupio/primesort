#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define True 1
#define False 0
#define FIM -1

uint8_t eh_primo(int num){

	if (num>3){
    if (num % 2 == 0) return False;
		for (int i = 3; i*i<=num; i+=2)
			if(num % i == 0)
				return False;
	return True;
	} else if (num & 2)
       return True;
    else
  	   return False;	
  }

int main() {

  int entrada=0;
  uint8_t flag_fim_leitura = False;

   FILE *pipein;

   if((pipein = popen("sort -n -r","w") ) == NULL){
  	printf("DEU MERDA 1\n");
  	exit(1);
   }

  while (!flag_fim_leitura){
  	scanf("%d",&entrada);
  	if(entrada == FIM)
  		flag_fim_leitura = True;
  	else{
  		if (!eh_primo(entrada))
  			 fprintf(pipein, "%d\n",entrada);
  	}
  }
   pclose(pipein);
  
  return 0;
}
