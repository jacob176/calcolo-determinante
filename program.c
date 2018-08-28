#include<stdio.h>
#include<stdlib.h>
/*calcolo determinante di una matrice nxn*/
int menu();
void input(int m[100][100],int r,int c);
void stampa(int m[100][100],int r,int c);
int  determinante(int m[100][100],int r,int c);
void sottomatrice(int m[100][100],int m1[100][100],int r,int c,int i);
main()
{
	int scelta;
	int flag=0;
	int r,c;
	int det;
	int m[100][100];
	do
	{
		scelta=menu();
		switch(scelta)
		{
			case 1:
				do
				{
					printf("\nInserire r e c matrice quadrata di cui si vuole sapere il determinante:\n");
					do
					{
						printf("\nInserire righe della matrice(max 100):\n");
						scanf("%d",&r);
					}while((r<0)||(r>100));
					do
					{
						printf("\nInserire colonne della matrice(max 100):\n");
						scanf("%d",&c);
					}while((c<0)||(c>100));
				}while(r!=c);
				flag=1;
				break;
			case 2:
				if(flag>=1)
				{
					input(m,r,c);
					flag++;
				}	
				break;
			case 3:
				if(flag>=2)
				{
					stampa(m,r,c);
				}
				break;
			case 4:
				if(flag>=2)
				{
					det=determinante(m,r,c);
				}
				printf("\nIl determinante e' pari a:\n%d",det);
				break;
		}
	}while(scelta!=0);
}
int menu()
{
	int scelta;
	do
	{
		printf("\n1.Inserimento cardinalità matrice");
		printf("\n2.Inserimento matrice");
		printf("\n3.Stampa matrice");
		printf("\n4.Calcolo determinate");
		printf("\n0.Exit\n");
		scanf("%d",&scelta);
	}while((scelta<0)||(scelta>4));
	return(scelta);
}
void input(int m[100][100],int r,int c)
{
	int j,k;
	printf("\n");
	for(j=0;j<r;j++)
	{
		for(k=0;k<c;k++)
		{
			printf("\nm[%d][%d]=",j,k);
			scanf("%d",&m[j][k]);
		}
	}
}
void stampa(int m[100][100],int r,int c)
{
	int j,k;
	printf("\n\n\n\n");
	for(j=0;j<r;j++)
	{
		for(k=0;k<c;k++)
		{
			printf("%d\t",m[j][k]);
		}
		printf("\n");
	}
}
int determinante(int m[100][100],int r,int c)
{
	int det=0;
	int i;
	int a,b;
	int s=1;
	int m1[100][100];
	if(r==1)
	{
		return(m[0][0]);
	}
	if((r==2)&&(c==2))
	{
		det=(m[0][0]*m[1][1])-(m[0][1]*m[1][0]);

		return(det);
	}
	else
	{
		for(i=0;i<c;i++)
		{
			sottomatrice(m,m1,r,c,i);
			a=r-1;
			b=c-1;
			det=det+(s*m[0][i]*determinante(m1,a,b));
			s=s*-1;
		}
	}
	return(det);
}
void sottomatrice(int m[100][100],int m1[100][100],int r,int c,int i)
{
	int j,k;
	int a=0;
	int b=0;
	for(j=1;j<r;j++)
	{
		for(k=0;k<c;k++)
		{
			if((j!=0)&&(k!=i))
			{
				m1[a][b]=m[j][k];
				b++;	
			}
		}
		a++;
		b=0;
	}
}
