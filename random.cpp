/*freopen("t.txt","w",stdout);
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<ll> uni(1,20);
	std::uniform_int_distribution<ll> ps(1,50);
	std::uniform_int_distribution<ll> vl(80,100);
	cout<<50<<" "<<500<<endl;
	for(int z=1;z<=500;z++){
		for(int i=1;i<=50;i++){
			for(int j=1;j<=50;j++){
				bor[z][i][j]=uni(rng);
			}
		}
	}
	for(int z=1;z<=500;z++){
		for(int i=1;i<=40;i++){
			int a=ps(rng),b=ps(rng);
			int val=vl(rng);
			bor[z][a][b]=val;
		}
	}
	for(int z=1;z<=500;z++){
		for(int i=1;i<=50;i++){
			for(int j=1;j<=50;j++){
				cout<<bor[z][i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;*/