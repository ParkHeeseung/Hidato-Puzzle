  #include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

const int MAX_SIZE = 100;
const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int nMAX = 8;

using namespace std;

void generate_puzzle(int x, int y, int height, int width,
  int count, int betweenNum,  int grid[][MAX_SIZE], int problemGrid[][MAX_SIZE]);
void cutting_puzzle(int height, int width, int grid[][MAX_SIZE]);
void display(int height, int width, int grid[][MAX_SIZE]);
void testCasesPrint(int height, int width, int problemGrid[][MAX_SIZE]);

int main(){

  int height, width;
  int grid[MAX_SIZE][MAX_SIZE];
  int problemGrid[MAX_SIZE][MAX_SIZE];
  int count = 1;
  memset(grid, 0, sizeof(grid));
  memset(problemGrid, 0, sizeof(problemGrid));


  srand((unsigned int)time(0));

  cout << "width : " << endl;
  cin >> width;
  cout << "height : " << endl;
  cin >> height;

  int startY = rand() % height;
  int startX = rand() % width;


  cout << "=====start=====" << endl;
  cout << startX << " | " << startY << endl;

  grid[startY][startX] = count++;
  problemGrid[startY][startX] = 1;

  generate_puzzle(startX, startY, height, width, count, 1, grid, problemGrid);
  // cutting_puzzle(height, width, grid);
  // cutting_puzzle(height, width, problemGrid);


  cout << "=====solution=====" << endl;
  display(height, width, grid);

  cout << "=====problem=====" << endl;
  display(height, width, problemGrid);

  cout << "=====testCase=====" << endl;
  testCasesPrint(height, width, problemGrid);




  return 0;
}

void generate_puzzle(int x, int y, int height, int width,
  int count, int betweenNum,  int grid[][MAX_SIZE], int problemGrid[][MAX_SIZE]){

  int randomNum[nMAX] = { 0, };
  bool bCheckExistOfNum[nMAX] = { false, };

  for(int i = 0; i < nMAX;) {
    int nTemp = rand() % 8;

    if(bCheckExistOfNum[nTemp] == false){
      bCheckExistOfNum[nTemp] = true;
      randomNum[i++] = nTemp;
    }
  }

  if(betweenNum == 0){
    betweenNum = rand() % 7 + 1;
  }



  for(int i = 0; i < nMAX; i++){
    int next_x = x + dx[randomNum[i]];
    int next_y = y + dy[randomNum[i]];

    if (next_x < 0 || next_x >= width || next_y < 0 || next_y >= height) continue;

    if(grid[next_y][next_x] == 0){

      cout << "x : " << next_x << " " << "y : " << next_y << endl;

      grid[next_y][next_x] = count;
      if(betweenNum == 1){
        problemGrid[next_y][next_x] = count;
      }
      else{
        problemGrid[next_y][next_x] = -1;
      }
      count++;
      betweenNum--;
      return generate_puzzle(next_x, next_y, height, width, count, betweenNum, grid, problemGrid);

    }


  }

  problemGrid[y][x] = count - 1;
}

void cutting_puzzle(int height, int width, int grid[][MAX_SIZE]){

  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      if(grid[i][j] == 0) grid[i][j] = 0;
      else if(grid[i][j] == -1) grid[i][j] = -1;
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
      if(grid[i][j] == 0){
        cout << "||" << "|";
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

void testCasesPrint(int height, int width, int problemGrid[][MAX_SIZE]){

  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      cout << problemGrid[i][j] << " ";
    }
    cout << endl;
  }
}
