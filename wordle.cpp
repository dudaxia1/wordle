#include<bits/stdc++.h>
using namespace std;
#define N 30005
string s[N],dt[N];
string guess,word;
int n,sn[N],m,len,tail,fr;
mt19937 rnd((unsigned)time(NULL));
int check(){
	if(len!=(signed int)guess.size())return 1;
	int ret=1;
	for(int i=sn[len];i<=sn[len+1]-1;++i){
		int pip=1;
		for(int j=0;j<len;++j){
			if(guess[j]!=s[i][j]){
				pip=0;
				break;
			}
		}
		if(pip==1){ret=0;}
	}
	if(ret==1)return 3;
	for(int i=0;i<len;++i){
		if(word[i]!=guess[i])return 2;
	}
	return 0;
}
int main(){
	cout<<"Reading data...\n";
	if(freopen("words.txt","r",stdin)==0){
		printf("Missing data. Download data at \n");
		system("pause");
	};
	cin>>m>>n;
	for(int i=1;i<=m;++i)cin>>sn[i];
	for(int i=1;i<=n;++i)cin>>s[i];
	cout<<"Reading completed.\nInput length.\n";
	freopen("con","r",stdin);
	cin>>len;
	for(int i=sn[len];i<=sn[len+1]-1;++i){
		dt[++tail]=s[i];
	}
	if(tail==0){
		cout<<"Words in this length does't exist.\n";
		return 114514;
	}
	cout<<"Input difficulty from 1 to 100.\n";
	cin>>fr;
	word=dt[rnd()%(tail*fr/100)+1];
	cout<<"Input a random word...\n";
	cin>>guess;
	int flag=check();
	while(flag!=0){
		switch(flag){
			case 1:{
				cout<<"Too short or too long.\n";
				break;
			}
			case 2:{
				cout<<"Partly correct.\n\n";
				cout<<guess<<endl;
				for(int i=0;i<len;++i){
					if(guess[i]==word[i])cout<<"V";
					else{
						bool ret=false;
						for(int j=0;j<len;++j){
							if(guess[i]==word[j])ret=true;
						}
						if(ret)cout<<"O";
						else cout<<" ";
					}
				}
				cout<<endl<<endl;
				break;
			}
			case 3:{
				cout<<"Don't xiabibi yigedanci!!!!!\n";
				break;
			}
			default:{
				cout<<"An unknown error happened sorryyyyyyyyyyyyyyyyyyy\n";
				break;
			}
		}
		cin>>guess;
		flag=check();
	}
	cout<<"You win!!!!!\n";
	return 0;
}
