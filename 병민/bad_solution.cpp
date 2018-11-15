#include <cstdio>
#include <ctime>
int d[10][10],start_c,start_r,max_hidato,n;
const int dx[8]={1,-1,0,0,1,1,-1,-1};
const int dy[8]={0,0,1,-1,1,-1,-1,1};
bool go(int c, int r, int l){
 if(l == max_hidato){
 	for(int i =0; i <n ;i++){
		for(int j=0; j <n ; j++) printf("%d ",d[i][j]);
		printf("\n");
	}
	return true;
 }
 for(int i =0; i < 8 ;i++){
 	int nc = c+ dx[i], nr = r+dy[i];
 	if(nc>=0 && nc<8 && nr >=0 && nr<8) {
 		
 		if(d[nc])
 		if(d[nc][nr]==-1)d[nc][nr] =l+1,go(nc, tnr, l+1), d[nc][nr] =-1;
 		else if(d[nc][nr] ==l+1) go(nc, nr, l+1);
 	}
 }
}
int main(){
	clock_t begin, end;
	scanf("%d",&n);
	for(int i =0; i < n;i++){
		for(int j =0; j <n;j++) {
			scanf("%d",&d[i][j]);
			max_hidato = max_hidato > d[i][j] ? max_hidato:d[i][j];
			if(d[i][j]==1) start_c =i, start_r = j;
		}
	}
	begin = clock();
	go(start_c,start_r,1);

	end=clock();
	printf("run time is : %lf ms\n",(double)(end-begin));
	return 0;
}
