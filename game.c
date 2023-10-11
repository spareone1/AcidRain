#define _CRT_SECURE_NO_WARNINGS
#define CLS system("cls")      // system("cls")을 CLS 메크로 상수로 선언

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include <string.h>
#include <conio.h>

void gotoxy(int x, int y);   // 커서를 해당 위치로 이동할 함수
void word(int len);   // 단어가 저장되어 있고, print하는 함수
void ui();  // 게임 ui 구성 함수
void hpui();  // 게임 ui쪽의 hp를 담당하는 함수
void cursor(int n);  // 커서를 숨기기 위한 함수

int hp = 10;         // hp를 저장할 변수
int score = 0;       // 점수를 저장할 변수

int m, s;       // 분, 초를 저장할 타이머 용도의 변수

typedef struct Render {         // 나타난 단어를 저장하는 구조체
	char word[11];      // 단어 문자열 배열
	int x;          // 단어 위치 x좌표
	int y;          // 단어 위치 y좌표
} Render;           // Render 자료형 재정의

int wordNum;         // render 배열의 인덱스 계산을 위한 변수
Render render[20];   // Render을 자료형으로 한 render 구조체 배열 생성

unsigned __stdcall Thread(void *arg) //스레드 함수
{
	
	while (hp > 0 && score != 50){     // hp가 0 초과하거나 score가 50이 아닐 때 반복
		char input[10];              // 입력받을 문자열 변수
		gotoxy(41, 25);             // 커서를 해당 좌표로 이동
		gets(input);                // 문자열 입력
		
		for (int i = 0; i < 20; i++) {       // i를 0부터 19까지 반복
			if (!strcmp(render[i].word, input)) {   // render의 word와 비교 후 같은 경우 (strcmp()는 맞으면 0을 반환함)
				gotoxy(1, 25);    // 해당 좌표로 이동
				score += 2;       // 점수 2점 추가
				wordNum = i;      // i를 wordNum에 저장
				render[wordNum].y = 0;  // render[wordNum]의 y좌표를 0으로 처리
				break;                  // for문을 빠져나옴
			}
		}
	}	
}


int game(int n) {
	int wordLen;     // wordLen 변수 정의
	int wordTime;    // wordTime 변수 정의

	srand((long)time(NULL));   // rand 난수 생성

	cursor(0);  // 커서 숨김

	
	// 난이도 매개변수를 n으로 받습니다.
	if (n == 1 || n == 4 || n == 7) {  // 난이도 1, 4, 7일 때
		wordLen = 3;  // wordLen을 3으로 설정
	}
	else if (n == 2 || n == 5 || n == 8) { // 난이도 2, 5, 8일 때
		wordLen = 4;  // wordLen을 4로 설정
	}
	else {  // 그 외의 경우
		wordLen = 5;  // wordLen을 5로 설정
	}

	if (1 <= n && n <= 3) {  // 난이도가 1, 2, 3일 때
		wordTime = 3;  // wordTime을 3으로 설정
	}
	else if (4 <= n && n <= 6) {  // 난이도가 4, 5, 6일 때
		wordTime = 2;  // wordTime을 2로 설정
	}
	else {  // 그 외 경우
		wordTime = 1;  // wordTime을 1로 설정
	}

	_beginthreadex(NULL, 0, Thread, 0, 0, NULL);  // 스레드 실행

	int t = 0;  // 변수 t를 0으로 설정(단어가 생성될 조건을 결정하는 변수)
	while (hp > 0 && score != 50)     // hp가 0 초과하거나 score가 50이 아닐 때 반복
	{
		t++;   // t에다 1 추가
		
		ui();   // ui() 함수 호출
		hpui();   // hpui() 함수 호출
		for (int i = 0; i < 20; i++) {             // 단어 스크롤, 제거, HP감소를 구현할 for문. i가 0부터 19까지 반복
			if (render[i].y != 0) {       // 해당 단어 y좌표가 0이 아닐 때
				if (++render[i].y > 23) {  // y좌표에 1을 더하고 23이 초과하면 단어가 끝까지 떨어진 것이므로
					hp--;  // hp 1 감소
					wordNum = i;  // i를 wordNum에 대입
					render[wordNum].y = 0;   // y좌표를 0으로 설정
				}
				else {   // 그 외의 경우(단어가 다 떨어지지 않았을 때)
					gotoxy(render[i].x, render[i].y);   // 해당 단어의 x, y 좌표로 이동 (y좌표에 +1을 하지 않는 이유는 이미 if 조건을 판별할 때 1을 더하고 조건을 확인했기 때문)
					printf("%s", render[i].word);   // 단어 출력
				}
			}
		}
		if (t == wordTime) {   // t와 wordTime이 동일할 때
			word(wordLen);   // wordLen을 매개변수로 한 word() 함수 호출 (단어 생성 함수)
			t = 0;  // t를 0으로 처리
		}
		s++;    // s에 1 추가 (초)
		if (s == 60) {  // s가 60인 경우(60초가 지난 경우)
			m++; // m에 1 추가
			s = 0;  // s를 0으로 처리
		}
		hpui();   // hpui() 호출 (앞뒤로 호출하는 이유는 반응속도를 위함임)
		gotoxy(41, 25);  // 해당 좌표로 커서를 이동
		Sleep(1000);  // 1초 대기
	}

	
	return 0;  // 프로그램 종료
	
}


void word(int len) {

	// 다음은 국립국어원에서 가져온 200개의 단어들입니다.
	char *two[] = { "호안", "화주", "팻말", "세척", "약력", "깔다", "깔기", "양식", "서식", "형식",
		  "필명", "축전", "축제", "기금", "자금", "상대", "부분", "일부", "여행", "관광",
		  "합계", "치다", "치기", "냉각", "개념", "부호", "성향", "경우", "상자", "조건",
		  "상태", "출소", "뚫림", "경로", "통로", "기회", "가림", "걷기", "청구", "모음",
		  "높이", "점심", "제외", "원점", "전환", "언론", "지인", "이웃", "걸다", "논점"};

	char *three[] = { "잠김선", "바다숲", "둑보호", "여름철", "화물주", "확인증", "증명서", "혼합형", "손팻말", "맵시꾼",
		  "알림창", "동반자", "상대방", "도움말", "봉사료", "탐방로", "하향식", "식탁보", "헤제폰", "주제곡",
		  "돌풍앱", "맵시꽃", "결정권", "결정표", "초읽기", "초기화", "점검표", "가맹점", "거두기", "지지선",
		  "점심밥", "파견소", "관리소", "아침밥", "일용직", "쌍방향", "양방향", "대화형", "전기차", "그림말",
		  "고기소", "사용자", "웹검색", "어깨쇠", "다걸기", "병따개", "소리책", "듣는책", "잎담배", "건축물"};

	char *four[] = { "휴대전화", "폭넓히기", "거친바다", "가치환산", "가정체험", "바닷말류", "전류제한", "집중기간", "절정기간", "바로사용",
		  "조립모형", "인물소개", "사전공연", "공기통로", "촬영구역", "붙임쪽지", "닫힌회로", "열차편성", "홍보여행", "기획상품",
		  "후진운전", "지하통로", "템페스트", "일괄발주", "일괄주문", "전담조직", "기억상자", "반짝할인", "자판보안", "화면계약",
		  "냉각하다", "지도과학", "짝꿍차림", "안전의자", "새끼조개", "부착하다", "붙임서류", "최대부하", "구멍뚫기", "가림시설",
		  "물저장고", "앞선위성", "직접연결", "전선높이", "뒤진위상", "출력증가", "증강현실", "점심식사", "파견분소", "좀비피시" };

	char *five[] = { "옆바람주의", "가사도우미", "가정집묵기", "홈네트워크", "안전손잡이", "나팔스피커", "게을리하다", "항만국통제", "손뼉맞장구", "하이브리드",
		  "전력선통신", "공정흐름도", "자백감형제", "인격표지권", "꾸러미상품", "묶음디자인", "유명블로거"," 체험평가자", "무동력운전", "구름컴퓨팅",
		  "모닥불놀이", "점자안내도", "청렴협의체", "종자붙이기", "연기차단벽", "전자파장해", "전자이용권", "물저장시설", "수중방파제", "무부하계량",
		  "잃지않도록", "잠시빌린돈", "전압을걸다", "전기자동차", "손수제작물", "손수저작물", "유비쿼터스", "인터넷검색", "참살이마을", "결혼설계사",
		  "운행관제실", "운행관제사", "난바다양식", "공공시설물", "어가도우미", "오염침전물", "사무자동화", "전선총길이", "전선을펴다", "주제어장치" };

	// a의 변수 값에 따라 리턴되는 단어
	// a == 1 : 2자리
	// a == 2 : 3자리
	// a == 3 : 4자리
	// a == 4 : 5자리

	int x = rand() % 80 + 2;  // x좌표 랜덤 생성
	gotoxy(x, 4);  // 해당 좌표로 커서 이동

	render[wordNum].y = 4;   // 해당 원소의 y좌표를 4로 설정(y좌표가 4부터 시작해서 떨어지기 때문)

	if (len == 3) {    // wordLen으로 받아온 단어 길이가 3일 때
		int a = rand() % 2 + 1; // a 랜덤 생성
		if (a == 1) {  // a가 1일 때
			int wordIndex = rand() % 50;  // wordIndex 랜덤 생성
			strcpy(render[wordNum].word, two[wordIndex]);   // 해당 단어를 render 원소에 저장
			render[wordNum].x = x;  // 여기서 뽑은 x좌표를 해당 단어의 x좌표를 대입
			printf("%s", render[wordNum].word);   // 단어 출력 (이하 if문 모두 동일)
		}
		else {
			int wordIndex = rand() % 50;
			strcpy(render[wordNum].word, three[wordIndex]);
			render[wordNum].x = x;
			printf("%s", render[wordNum].word);
		}
	}
	else if (len == 4) {    // wordLen으로 받아온 단어 길이가 4일 때
		int a = rand() % 3 + 1;
		if (a == 1) {
			int wordIndex = rand() % 50;
			strcpy(render[wordNum].word, two[wordIndex]);
			render[wordNum].x = x;
			printf("%s", render[wordNum].word);
		}
		else if (a == 2) {
			int wordIndex = rand() % 50;
			strcpy(render[wordNum].word, three[wordIndex]);
			render[wordNum].x = x;
			printf("%s", render[wordNum].word);
		}
		else {
			int wordIndex = rand() % 50;
			strcpy(render[wordNum].word, four[wordIndex]);
			render[wordNum].x = x;
			printf("%s", render[wordNum].word);
		}
	}
	else {    // 그 외의 경우 (wordLen으로 받아온 단어 길이가 5일 때)
		int a = rand() % 4 + 1;
		if (a == 1) {
			int wordIndex = rand() % 50;
			strcpy(render[wordNum].word, two[wordIndex]);
			render[wordNum].x = x;
			printf("%s", render[wordNum].word);
		}
		else if (a == 2) {
			int wordIndex = rand() % 50;
			strcpy(render[wordNum].word, three[wordIndex]);
			render[wordNum].x = x;
			printf("%s", render[wordNum].word);
		}
		else if (a == 3) {
			int wordIndex = rand() % 50;
			strcpy(render[wordNum].word, four[wordIndex]);
			render[wordNum].x = x;
			printf("%s", render[wordNum].word);
		}
		else {
			int wordIndex = rand() % 50;
			strcpy(render[wordNum].word, five[wordIndex]);
			render[wordNum].x = x;
			printf("%s", render[wordNum].word);
		}
	}

	wordNum++; // wordNum에 1 추가
}

void ui() {
	CLS;  // 화면 초기화
	puts("┌────────────────────────────┬──────────────────────────────┬─────────────────────────────┐");
	puts(""); //hpui 함수 담당 구역이기 때문에 공백으로 비움
	puts("├────────────────────────────┴──────────────────────────────┴─────────────────────────────┤");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("│                                                                                         │");
	puts("├────────────────────────────┬──────────────────────────────┬─────────────────────────────┤");
	printf("│                            │                              │                             │\n");
	puts("└────────────────────────────┴──────────────────────────────┴─────────────────────────────┘");

	return;
}

void hpui() {
	gotoxy(1, 2);    // 해당 커서로 이동

	// hp에 따라 다음과 같이 출력됩니다.
	if (hp == 10) {
		printf("│ HP : ■■■■■■■■■■  │       경과 시간 : %02d:%02d      │            획득 점수 : %3d점│\n", m, s, score);
	}
	else if (hp == 9) {
		printf("│ HP : ■■■■■■■■■    │       경과 시간 : %02d:%02d      │            획득 점수 : %3d점│\n", m, s, score);
	}
	else if (hp == 8) {
		printf("│ HP : ■■■■■■■■      │       경과 시간 : %02d:%02d      │            획득 점수 : %3d점│\n", m, s, score);
	}
	else if (hp == 7) {
		printf("│ HP : ■■■■■■■        │       경과 시간 : %02d:%02d      │            획득 점수 : %3d점│\n", m, s, score);
	}
	else if (hp == 6) {
		printf("│ HP : ■■■■■■          │       경과 시간 : %02d:%02d      │            획득 점수 : %3d점│\n", m, s, score);
	}
	else if (hp == 5) {
		printf("│ HP : ■■■■■            │       경과 시간 : %02d:%02d      │            획득 점수 : %3d점│\n", m, s, score);
	}
	else if (hp == 4) {
		printf("│ HP : ■■■■              │       경과 시간 : %02d:%02d      │            획득 점수 : %3d점│\n", m, s, score);
	}
	else if (hp == 3) {
		printf("│ HP : ■■■                │       경과 시간 : %02d:%02d      │            획득 점수 : %3d점│\n", m, s, score);
	}
	else if (hp == 2) {
		printf("│ HP : ■■                  │       경과 시간 : %02d:%02d      │            획득 점수 : %3d점│\n", m, s, score);
	}
	else {
		printf("│ HP : ■                    │       경과 시간 : %02d:%02d      │            획득 점수 : %3d점│\n", m, s, score);
	}

}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void cursor(int n) // 커서 보이기 & 숨기기
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
