#include <conio.h>

int start() {
	system("cls");  // 화면 초기화
	puts("┌─────────────────────────────────────────────────────────────────────────────────────────┐");
	puts("│                                        산 성 비                                         │");
	puts("├─────────────────────────────────────────────────────────────────────────────────────────┤");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                    1. 1단계 플레이                                      │");
	puts("│                                    2. 2단계 플레이                                      │");
	puts("│                                    3. 3단계 플레이                                      │");
	puts("│                                    4. 4단계 플레이                                      │");
	puts("│                                    5. 5단계 플레이                                      │");
	puts("│                                    6. 6단계 플레이                                      │");
	puts("│                                    7. 7단계 플레이                                      │");
	puts("│                                    8. 8단계 플레이                                      │");
	puts("│                                    9. 9단계 플레이                                      │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                     0. 게임 종료                                        │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("├─────────────────────────────────────────────────────────────────────────────────────────┤");
	puts("│                                    제작 : spareone                                       │");
	puts("└─────────────────────────────────────────────────────────────────────────────────────────┘");

	return _getch();    // 입력받은 값을 반환
}
