#include <cstdio>
#include <ctime>

int d[100][100],start_c,start_r,max_num,n,m, unique_answer;

bool check[10001];

const int dx[8]={1,-1,0,0,1,1,-1,-1};
const int dy[8]={0,0,1,-1,1,-1,-1,1};

int find(int x, int y){
	int value = 0;

	for(int i=0 ; i < 8; i++){

		int nx=x+dx[i], ny = y+dy[i];

		if(nx>=0 && nx<n && ny>=0 && ny<m){

			if(d[nx][ny] > -1) value |= (1<<i);
		}
	}
	return value;
}

bool hidato(int c, int r, int l){
	if(l==max_num+1){
		unique_answer ++;
		for(int i =0; i < n;i++){
			for(int j =0; j <m ;j++) 
				printf("%d ",d[i][j]);
			printf("\n");
		}
		return false;
	}

	int find_num = find(c, r);

	if(check[l]){
		for(int i = 0 ; i < 8 ; i++){

			int nc = c+dx[i], nr = r+dy[i];

			if((find_num & (1 << i)) && d[nc][nr] == l){

				if(hidato(nc, nr, l+1)) return true;
			}
		}
		return false;
	}

	for(int i =0; i < 8; i++){
		int nc= c+dx[i], nr = r+dy[i];
		if(find_num & (1 << i)){
			if(d[nc][nr]== 0 ){
				d[nc][nr] = l;
				if(hidato(nc, nr, l+1)) return true;
				d[nc][nr] = 0;
			}
		}
	}
	return false;
}


int main(){

	clock_t begin, end;

	scanf("%d %d",&n, &m);

	for(int i =0; i < n;i++){
		for(int j =0; j <m;j++) {
			scanf("%d",&d[i][j]);
			max_num = max_num > d[i][j] ? max_num:d[i][j];
			if(d[i][j] > 0) check[d[i][j]] = true;
			if(d[i][j]==1) start_c =i, start_r = j;
		}
	}

	printf("\n");

	begin = clock();

	hidato(start_c,start_r, 2);

	end=clock();

	printf("\n");

	printf("%d\n", unique_answer);

	printf("run time is : %lf ms\n",(double)(end-begin));
	return 0;
}
