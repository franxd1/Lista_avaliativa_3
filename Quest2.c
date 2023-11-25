#include<stdio.h>
#include<math.h>


int main(){
   double montante,valorinv,taxadejuros;
   int meses;
    
    scanf("%d",&meses);
    scanf("%lf",&valorinv);
    scanf("%lf",&taxadejuros); 
    
        for (int i=1; i <=meses ; i++){
            double soma;

                soma =(1+ taxadejuros);                
                montante =valorinv * soma* (pow(soma,i)-1)/taxadejuros;
                printf("Montante ao fim do mes %d: R$ %0.2lf\n",i,montante);
                }  
  return 0 ;
}