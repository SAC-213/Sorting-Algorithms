#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Insercion(int A[], int n);

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
    
	Insercion(A,n);
	
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

void Insercion(int A[],int n){
    int i,k,j,temp;
    for ( i = 0; i < n; i++)
    {
        j=i;
        temp=A[i];
        while (j>0&&temp<A[j-1])
        {
            A[j]=A[j-1];
            j--;
        }
        A[j]=temp;
    }
}
