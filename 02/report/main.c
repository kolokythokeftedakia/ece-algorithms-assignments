// Πρόβλημα 2 - Αλγ΄όριθμοι

#include<stdio.h>
#define n 5
#define k 6

int max(int a, int b);
int * restaurant(int p[], int m[]);

// driver code:

int main(void){

	int p[]={0, 10, 50, 20, 30, 10};
	int m[]={0,  7, 12, 18 ,20, 45};

	int *profit;
	profit=restaurant(p,m);
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("p[%d]=%d\t\t",i,*(p+i));
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("m[%d]=%d\t\t",i,*(m+i));
	printf("\n───\n");
	for(int i=1;i<=n;i++)
		printf("R[%d]=%d\t\t",i,*(profit+i));
	printf("\n");
	return 0;
}

int max(int a, int b){
	return (a>b)?a:b;
}

// algorithm:

int * restaurant(int p[], int m[]){
	int i,j,a;
	static int revenue[n+1];

	for(i=1; i<=n; i++)
		revenue[i]=p[i];

	for(i=2; i<=n; i++){
		for(j=1; j<i; j++){
			if(m[i]-m[j]>=k){
				// revenue[i]=max(p[i], revenue[j]+p[i]);
				revenue[i]=revenue[j]+p[i];
				}
			else
				revenue[i]=max(revenue[i], revenue[j]);
		}
	}

	return revenue;
}