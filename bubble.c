#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Bubble(int A[], int n);

int main(int argc, char const *argv[])
{
    
    clock_t t_inicio, t_final;
    double t_intervalo;
    int n = atoi(argv[1]);
    int *A;

    //Apartar memoria para n números  enteros
	A=malloc(n*sizeof(int));
	if(A==NULL)
	{
		printf("\nError al intentar reservar memoria para %d elementos\n",n);		
		exit(1);
	}	

    for(int i=0;i<n;i++)
		scanf("%d",&A[i]);

    //Inicia medición del tiempo
	t_inicio = clock();
	
	//Llamar al algoritmo
    
	Bubble(A,n);
	
	//Termina medición del tiempo	
	t_final = clock();
	
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",A[i]);
    }
    


	//Cálculo del tiempo y enviar mensaje a salida estandar con la medición  
    t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
    printf("\nTiempo medido: %.10f segundos.", t_intervalo);

    return 0;
}

void Bubble(int A[], int n){
    int i=0, j, cambios;
    do{
        cambios=0;
        for ( j = 0; j < (n-1)-i; j++)
        {
            if (A[j]>A[j+1])
            {
                int aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
                cambios=1;
            }
        }
        i++;
    }
    while ((i<=n-1)&&(cambios!=0));
}
