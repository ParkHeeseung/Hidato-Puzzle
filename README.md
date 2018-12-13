# Hidato-Puzzle


* Hidato Puzzle Generator and Solver

-- 목표
Hidato Puzzle 을 임의의 주어진 숫자(퍼즐의 크기)에 대해 생성하고 주어진 퍼즐을 풀 수
있는 Solver 알고리즘을 구현한다.
각 빈 칸에 자연수를 배치하여 번호가 매겨진 사각형의 "1"에서 순서대로 다음 숫자가
직사각형의 수평, 수직 또는 대각선 근처(8 방향)에 있도록 한다. 따라서 그리드 위에서 숫자
순서대로 처음부터 마지막 칸까지 경로를 따라 규칙에 따라 움직일 수 있다.
사각형에는 하나의 숫자만 포함될 수 있으며 Hidato Puzzle 에서 Unique 한 해결책을 갖는다.

* 규칙
1. 숫자가 들어있는 표가 주어진다. 그리드의 다른 사각형은 비어 있다.
2. 그리드가 반드시 직사각형 일 필요는 없다.
3. 그리드에 구멍이 있을 수 있다. (힌트가 아닌 곳)
4. 그리드는 항상 연결되어 있다.
5. 그리드에는 시작 숫자 "1"이 항상 표시된다.
6. 그리드에 있는 숫자의 차이가 13 이하라고 가정 할 수 있다.

팀장 : 
컴퓨터공학부 20163113 박희승

팀원 :  
소프트웨어학부 20143029 공병민
소프트웨어학부 20143048 김철현
컴퓨터공학부 20163146 이진주

* 업무 분담
@ Generator
  - 담당 팀원 : 김철현, 박희승
  - Generator 알고리즘 구현 (퍼즐 크기 입력에 따라 랜덤한 퍼즐 생성)
  - Testcase 제작
@ Solver
  - 담당 팀원: 공병민, 이진주
  - Solver 알고리즘 구현 (탐색 효율성 고려)
  - 알고리즘에 Testcase 적용


