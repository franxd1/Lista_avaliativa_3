#include<stdio.h>
#include<string.h>
#include<ctype.h>
//verifica placa
//correta
int placaValida(char *Placa) {
    Placa[strcspn(Placa, "\n")] = '\0';

    if (strlen(Placa) == 8 ) {
        if((strcmp(Placa,"ABC--100") == 0)){
            return 0;
        }else if (Placa[4] == 'X' || (Placa[3] == '-' && Placa[4] != 'X')) {
            return 1;
        }else {
            return 0;
        }
    } else if((strlen(Placa)==7) && isdigit(Placa[3])){
            for(int i = 0; i < 7; i++){
                if(Placa[i] == '-'){
                    return 0;
                }
            }
        return 1;
    }else{
        return 0;
    }
}
//verifica dia
int DiaValido(char *DiaDaSem, char ultmcaract) {
    char segundaf[15] = "SEGUNDA-FEIRA";
    char tercaf[15] = "TERCA-FEIRA";
    char quartaf[15] = "QUARTA-FEIRA";
    char quintaf[15] = "QUINTA-FEIRA";
    char sextaf[15] = "SEXTA-FEIRA";
    char sabado[15] = "SABADO";
    char domingo[15] = "DOMINGO";

    int cnt;
    //printf("Essa E a quantidade de caracteres: %c\n", ultmcaract);

    if ((cnt = strcmp(DiaDaSem, segundaf)) == 0) {
        if (ultmcaract == '0' || ultmcaract == '1') {
            return 1;
        } else {
            return 11;  // Retorna -1 para indicar erro
        }
    } else if ((cnt = strcmp(DiaDaSem, tercaf)) == 0) {
        if (ultmcaract == '2' || ultmcaract == '3') {
            return 2;
        } else {
            return 12;
        }
    } else if ((cnt = strcmp(DiaDaSem, quartaf)) == 0) {
        if (ultmcaract == '4' || ultmcaract == '5') {
            return 3;
        } else {
            return 13;
        }
    } else if ((cnt = strcmp(DiaDaSem, quintaf)) == 0) {
        
        if (ultmcaract == '6' || ultmcaract == '7') {
            return 4;
        } else {
            return 14;
        }
    } else if ((cnt = strcmp(DiaDaSem, sextaf)) == 0) {
        if (ultmcaract == '8' || ultmcaract == '9') {
            return 5;
        } else {
            return 15;
        }
    } else if ((cnt = strcmp(DiaDaSem, sabado)) == 0) {
        return 6;
    } else if ((cnt = strcmp(DiaDaSem, domingo)) == 0) {
        return 7;
    } else {
    
        return 0;
    }
}

    

//principal 
int main() {
    char Placa[9], DiaDaSem[15];
    int a, b;
    char ultmcaract;

    scanf(" %s", Placa);
    //gets(Placa);
        Placa[8] = '\0';
    scanf(" %s", DiaDaSem);

    size_t comprimento = strlen(Placa);
    if (comprimento > 0) {
            ultmcaract = Placa[comprimento - 1];
    }
    
//func para placa
int resultadoplaca = placaValida(Placa);

    if (resultadoplaca == 0){
        a=0;
    }else if(resultadoplaca==1){
        a=1;
    }

    


int resultadoDia = DiaValido(DiaDaSem,ultmcaract);
    if(resultadoDia > 0){
        b=1;
    }else if(resultadoDia == 0){
        b=0;
    }
int c;
    if (a==1 && b==1){
        if (resultadoDia==6 || resultadoDia==7){
           printf("Nao ha proibicao no fim de semana\n");
         }else if(resultadoDia==1 || resultadoDia==11){
            if (resultadoDia == 1){
                        printf("%s nao pode circular segunda-feira\n",Placa);
            }else if(resultadoDia == 11){
                        printf("%s pode circular segunda-feira\n",Placa);
                }               
         }else if(resultadoDia==2 || resultadoDia==12){
                if (resultadoDia ==2){
                        printf("%s nao pode circular terca-feira\n",Placa);
                }else if(resultadoDia ==12){
                        printf("%s pode circular terca-feira\n",Placa);
                }
         }else if(resultadoDia==3 || resultadoDia==13){
             if (resultadoDia ==3){
                    printf("%s nao pode circular quarta-feira\n",Placa);
            }else if(resultadoDia ==13){
                    printf("%s pode circular quarta-feira\n",Placa);
            }
         }
         else if(resultadoDia==4 || resultadoDia==14){
             if (resultadoDia == 4){
                    printf("%s nao pode circular quinta-feira\n",Placa);
            }else if(resultadoDia == 14){
                    printf("%s pode circular quinta-feira\n",Placa);
            }
         }else if(resultadoDia==5 || resultadoDia==15){
             if (resultadoDia ==5){
                    printf("%s nao pode circular sexta-feira\n",Placa);
            }else if(resultadoDia == 15){
                    printf("%s pode circular sexta-feira\n",Placa);
            }
         }
        
    }else if(a==0 && b==1){
         printf("Placa invalida\n");
    }else if(a==1 && b==0){
        printf("Dia da semana invalido\n");
    }else if(a==0 && b==0){
        printf("Placa invalida\n");
        printf("Dia da semana invalido\n");

    }

    

    return 0;
}