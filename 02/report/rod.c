#include <stdio.h>

#define n 10
#define nline printf("\n");

void rod(int p[]);

int main(void){

	int p[]={0,1,5,8,9,10,17,17,20,21,30}; // 1-indexed

	rod(p);

	return 0;
}

void rod(int p[]){

	int r[n+1];
	r[0]=0;

	for(int j=1;j<=n;j++){
		int q=-1;
		for(int i=1;i<=j;i++){
			if(q<p[i]+r[j-i]){
				q=p[i]+r[j-i];
			}
		}
		r[j]=q;
	}

	nline printf("n│ ");
	for(int i=1;i<=n;i++)
		printf("%d\t",i);
	printf("\n─┼────────────────────────────────────────────────────────────────────────\n");
	printf("r│ ");
	for(int i=1;i<=n;i++)
		printf("%d\t",*(r+i));
}