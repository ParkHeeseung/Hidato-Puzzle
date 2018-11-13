#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

const int MAX_SIZE = 100;
const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int nMAX = 8;

using namespace std;

void generate_puzzle(int x, int y, int height, int width, int count, int grid[][MAX_SIZE]);
void cutting_puzzle(int height, int width, int grid[][MAX_SIZE]);
void display(int height, int width, int grid[][MAX_SIZE]);

int main(){

  int height, width;
  int grid[MAX_SIZE][MAX_SIZE];
  int count = 1;
  memset(grid, 0, sizeof(grid));

  srand((unsigned int)time(0));

  cout << "height : " << endl;
  cin >> height;
  cout << "width : " << endl;
  cin >> width;

  int startY = rand() % height;
  int startX = rand() % width;

  cout << startX << " | " << startY << endl;

  grid[startX][startY] = count++;

  generate_puzzle(startX, startY, height, width, count, grid);
  cutting_puzzle(height, width, grid);
  display(height, width, grid);


  return 0;
}

void generate_puzzle(int x, int y, int height, int width, int count, int grid[][MAX_SIZE]){

  int randomNum[nMAX] = { 0, };
  bool bCheckExistOfNum[nMAX] = { false, };

  for(int i = 0; i < nMAX;) {
    int nTemp = rand() % 8;

    if(bCheckExistOfNum[nTemp] == false){
      bCheckExistOfNum[nTemp] = true;
      randomNum[i++] = nTemp;
    }
  }

  for(int i = 0; i < nMAX; i++){
    int next_x = x + dx[randomNum[i]];
    int next_y = y + dy[randomNum[i]];

    if (next_x <= 0 || next_x >= width || next_y <= 0 || next_y >= height) continue;

    if(grid[next_x][next_y] == 0){

      grid[next_x][next_y] = count++;
      return generate_puzzle(next_x, next_y, height, width, count, grid);

    }
  }

}

void cutting_puzzle(int height, int width, int grid[][MAX_SIZE]){

  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      if(grid[i][j] == 0) grid[i][j] = -1;
    }
  }
}

void display(int height, int width, int grid[][MAX_SIZE]){

  for(int j = 0; j < width; j++){
      cout << "+--";
  }
  cout << "+" << endl;


  for(int i = 0; i < height; i++){
    cout << "|";
    for(int j = 0; j < width; j++){
      if(grid[i][j] == -1){
        cout << " X" << "|";
      }
      else if(grid[i][j] / 10 == 0){
        cout << " "<< grid[i][j] << "|";
      }
      else{
        cout << grid[i][j] << "|";
      }
    }
    cout << endl;
    for(int j = 0; j < width; j++){
        cout << "+--";
    }
    cout << "*" << endl;

  }
}
