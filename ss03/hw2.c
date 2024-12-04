#include<stdio.h>
int fac(int n, int m ){
	//khong hop le
	if(n>m){
		return 0;
	}
	// base case
	if(n==m){
		return n;
	}
	return n + fac(n+1,m);
}

int main(){
	int n,m;
	printf("nhap n:");
	scanf("%d",&n);
	printf("nhap m:");
	scanf("%d",&m);
	
	int result = fac(n,m);
	printf("%d",result);

	return 0;
}



