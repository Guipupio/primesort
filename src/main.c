#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


#define True 1
#define False 0
#define FIM -1


uint8_t eh_primo(int num){


	
	if (num>3){
    if (num % 2 == 0) return False;
		for (int i =3; i*i<=num; i+=1)
			if(num % i == 0)
				return False;
	return True;
	} else if (num == 2 || num == 3)
       return True;
    else
  	   return False;	
}

int main() {

  int i = 0, j = 0, entrada = 0;
  uint8_t flag_fim_leitura = False;

  FILE *txt;
  FILE *pipein;
  FILE *pipeout;

  pipein = popen("> auxiliar","w");

  if((txt = fopen("auxiliar","w") ) == NULL){
  	printf("DEU MERDA 1\n");
  	exit(1);
  }

  while (!flag_fim_leitura){
  	scanf("%d",&entrada);
  	if(entrada == FIM)
  		flag_fim_leitura = True;
  	else{
  		if (!eh_primo(entrada)){
  			fprintf(txt, "%d\n",entrada);
  		i++;
  		}
  	 	
  	}
  }

 pipeout = popen("sort -n -r auxiliar", "r");
 
  // i = 0;
  // while (fscanf(txt,"%d\n",&entrada[i]) != EOF)
  // 	i++;

  pclose(pipein);
  pclose(pipeout);
  free(txt);
  return 0;
}
