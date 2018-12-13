#include <cstdio>
#include <ctime>

int d[100][100],start_c,start_r,max_num,n,m;

bool check[10001];

const int dx[8]={1,-1,0,0,1,1,-1,-1};
const int dy[8]={0,0,1,-1,1,-1,-1,1};

int find(int x, int y,int l){
	int value = 0;

	for(int i=0 ; i < 8; i++){

		int nx=x+dx[i], ny = y+dy[i];

		if(nx>=0 && nx<n && ny>=0 && ny<m){

			if(d[nx][ny] != 0) value |= (1<<i); // 다음 방향으로

			if(d[nx][ny] == max_num && l == max_num) {
				value = 1e9;
				break;
			}
		}
	}
	return value;
}

bool hidato(int c, int r, int l){

	int find_num = find(c, r, l); //다음 방향에 대한 숫자

	if(find_num == 1e9 ){ //다음이 끝이면 출력

		for(int i =0; i < n;i++){
			for(int j =0; j <m ;j++)
				printf("%d ",d[i][j]);
			printf("\n");
		}
		return true;
	}


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

			if(d[nc][nr]== -1 ){

				d[nc][nr] = l;
				if(hidato(nc, nr, l+1)) return true; //끝났을 경우 끝내
				d[nc][nr] = -1; // 끝나지 않았을 경우 다시 -1로 만들기


			}

		}

	}
	return false;
}


int main(){

	clock_t begin, end;

	scanf("%d %d",&n, &m);
	\
	for(int i =0; i < n;i++){
		for(int j =0; j <m;j++) {
			scanf("%d",&d[i][j]);

			max_num = max_num > d[i][j] ? max_num:d[i][j];

			if(d[i][j] > 0) check[d[i][j]] = true;

			if(d[i][j]==1) start_c =i, start_r = j;
		}
	}
	begin = clock();

	puts(" ");

	hidato(start_c,start_r, 2);

	end=clock();

	printf("run time is %lf ms\n",(double)(end-begin));

	return 0;
}
