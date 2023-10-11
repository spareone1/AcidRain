#include <stdio.h>

int start();      // main.c의 start() 함수를 사용합니다.
int game(int n);     // game.c의 game() 함수를 사용합니다.

int main() {
	int input = start() - 48;    // start()함수를 호출 후 리턴 값에다 48을 빼 input에 저장 (48을 빼는 이유는 0을 입력했을 때 58을 반환했기 때문)

	
	if (input == 0) {         // input이 0이면
		return 0;           //프로그램 종료
	}
	else {         // 아니면
		input = game(input);   // 해당 라운드의 입력을 매개변수로 하여 game() 함수 실행
	}
}
