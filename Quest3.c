#include<stdio.h>
#include<string.h>
//verifica placa
int placaValida(char *Placa) {
     char placa[8];

    
    
    fgets(Placa, sizeof(Placa), stdin);

    Placa[strcspn(Placa, "\n")] = '\0';

   
    if (strlen(placa) == 7) {
        if (Placa[4] == 'X' || (Placa[3] == '-' && Placa[4] != 'X')) {
            
            return 1;
        } else {
         
            return 0;
        }
    } else {
      
        return 0;
    }
}
//verifica dia
int DiaValido(char *DiaDaSem, char *ultmcaract) {
    char segundaf[15] = "SEGUNDA-FEIRA";
    char tercaf[15] = "TERCA-FEIRA";
    char quartaf[15] = "QUARTA-FEIRA";
    char quintaf[15] = "QUINTA-FEIRA";
    char sextaf[15] = "SEXTA-FEIRA";
    char sabado[15] = "SABADO";
    char domingo[15] = "DOMINGO";

        int cnt;

        if ((cnt = strcmp(DiaDaSem, segundaf)) == 0) {
            if (ultmcaract == '0' || ultmcaract == '1') {
                return 1;
            }else{
                return 10;
            }
        } else if ((cnt = strcmp(DiaDaSem, tercaf)) == 0) {
            if (ultmcaract == '2' || ultmcaract == '3') {
                return 2;
            }else{
                return 20;
            }
        } else if ((cnt = strcmp(DiaDaSem, quartaf)) == 0) {
            if (ultmcaract == '4' || ultmcaract == '5') {
                return 3;
            }else{
                return 30;
            }
        } else if ((cnt = strcmp(DiaDaSem, quintaf)) == 0) {
            if (ultmcaract == '6' || ultmcaract == '7') {
                return 4;
            }else{
                return 40;
            }
        } else if ((cnt = strcmp(DiaDaSem, sextaf)) == 0) {
            if (ultmcaract == '8' || ultmcaract == '9') {
                return 5;
            }else{
                return 50;
            }
        } else if ((cnt = strcmp(DiaDaSem, sabado)) == 0) {
           return 6;
         
            
        } else if ((cnt = strcmp(DiaDaSem, domingo)) == 0) {
          return 7;
            
        }else{
        printf("peido\n");

         }
    }



int main() {
    char Placa[9], DiaDaSem[15];
    int a, b;
    char ultmcaract;

    scanf("%s", Placa);
    Placa[8] = '\0';
    scanf("%s", DiaDaSem);

    size_t comprimento = strlen(Placa);
        if (comprimento > 0) {
            char ultmcaract = Placa[comprimento - 1];
        }
    

    if (placaValida(Placa)) {
        printf("Placa valida\n");
        a = 1;
    } else {
        printf("Placa invalida!\n");
        b = 0;
    }

    int resultadoDia = DiaValido(DiaDaSem,ultmcaract);
printf("o resultado e %d",resultadoDia);
    if (resultadoDia == 1) {
        printf("segundona\n");
    } else if (resultadoDia == 100) {
        printf("Dia invalido ou erro na entrada\n");
    } else if (resultadoDia ==6){
        printf("sabadou %d\n", resultadoDia);
    }

    return 0;
}
