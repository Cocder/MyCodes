ll pasc[22][22];
for(int i=0;i<=20;i++){pasc[i][0]=1;}
	for(int i=1;i<=20;i++){
		for(int j=1;j<=i;j++){
			pasc[i][j]=((tll)pasc[i-1][j-1]+pasc[i-1][j]);//c(n,k)=c(n-1,k-1)+c(n-1,k)
		}
	}