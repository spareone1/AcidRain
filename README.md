# AcidRain
산성비 타자연습 게임


C로 구현한 산성비 게임입니다.
이거 제작할 당시에는 그래도 돌아가긴 했는데 지금도 돌아갈지는 잘 모르겠습니다.

당시에 화면에 내려오는 글자가 사라지는 버그가 있었던것으로 기억합니다.


*게임 규칙
-1단계~9단계 구성 (메인화면에서 선택 가능)
-각 단계에는 다음과 같은 규칙에 맞춰 단어가 떨어짐
--1단계 : 3초, 3글자까지
--2단계 : 3초, 4글자까지
--3단계 : 3초, 5글자까지
--4단계 : 2초, 3글자까지
--5단계 : 2초, 4글자까지
--6단계 : 2초, 5글자까지
--7단계 : 1초, 3글자까지
--8단계 : 1초, 4글자까지
--9단계 : 1초, 5글자까지
-총 50개의 단어가 떨어짐
-단어를 10번 놓치면 게임오버
-50개의 단어를 모두 입력하면 다음 단계로 이동
-9단계에서 50개 입력 시 종료
-점수 계산 방법 = 맞은 단어 개수 * 2 (만점 100점)


-국립국어원 표준 전문용어에서 추출한 200개의 단어를 사용한다.

2글자 - 호안, 화주, 팻말, 세척, 약력, 깔다, 깔기, 양식, 서식, 형식
          필명, 축전, 축제, 기금, 자금, 상대, 부분, 일부, 여행, 관광
          합계, 치다, 치기, 냉각, 개념, 부호, 성향, 경우, 상자, 조건
          상태, 출소, 뚫림, 경로, 통로, 기회, 가림, 걷기, 청구, 모음
          높이, 점심, 제외, 원점, 전환, 언론, 지인, 이웃, 걸다, 논점 (50개)

3글자 - 잠김선, 바다숲, 둑보호, 여름철, 화물주, 확인증, 증명서, 혼합형, 손팻말, 맵시꾼
          알림창, 동반자, 상대방, 도움말, 봉사료, 탐방로, 하향식, 식탁보, 헤제폰, 주제곡
          돌풍앱, 맵시꽃, 결정권, 결정표, 초읽기, 초기화, 점검표, 가맹점, 거두기, 지지선
          점심밥, 파견소, 관리소, 아침밥, 일용직, 쌍방향, 양방향, 대화형, 전기차, 그림말
          고기소, 사용자, 웹검색, 어깨쇠, 다걸기, 병따개, 소리책, 듣는책, 잎담배, 건축물 (50개)

4글자 - 휴대전화, 폭넓히기, 거친바다, 가치환산, 가정체험, 바닷말류, 전류제한, 집중기간, 절정기간, 바로사용
          조립모형, 인물소개, 사전공연, 공기통로, 촬영구역, 붙임쪽지, 닫힌회로, 열차편성, 홍보여행, 기획상품
          후진운전, 지하통로, 템페스트, 일괄발주, 일괄주문, 전담조직, 기억상자, 반짝할인, 자판보안, 화면계약
          냉각하다, 지도과학, 짝꿍차림, 안전의자, 새끼조개, 부착하다, 붙임서류, 최대부하, 구멍뚫기, 가림시설
          물저장고, 앞선위성, 직접연결, 전선높이, 뒤진위상, 출력증가, 증강현실, 점심식사, 파견분소, 좀비피시 (50개)

5글자 - 옆바람주의, 가사도우미, 가정집묵기, 홈네트워크, 안전손잡이, 나팔스피커, 게을리하다, 항만국통제, 손뼉맞장구, 하이브리드
          전력선통신, 공정흐름도, 자백감형제, 인격표지권, 꾸러미상품, 묶음디자인, 유명블로거, 체험평가자, 무동력운전, 구름컴퓨팅
          모닥불놀이, 점자안내도, 청렴협의체, 종자붙이기, 연기차단벽, 전자파장해, 전자이용권, 물저장시설, 수중방파제, 무부하계량
          잃지않도록, 잠시빌린돈, 전압을걸다, 전기자동차, 손수제작물, 손수저작물, 유비쿼터스, 인터넷검색, 참살이마을, 결혼설계사
          운행관제실, 운행관제사, 난바다양식, 공공시설물, 어가도우미, 오염침전물, 사무자동화, 전선총길이, 전선을펴다, 주제어장치 (50개)


*구현
**메인 화면
─────────────────────────────────────────────
                                                       산 성 비
─────────────────────────────────────────────
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■ 1. 1단계 플레이 ■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■ 2. 2단계 플레이 ■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■ 3. 3단계 플레이 ■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■ 4. 4단계 플레이 ■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■ 5. 5단계 플레이 ■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■ 6. 6단계 플레이 ■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■ 7. 7단계 플레이 ■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■ 8. 8단계 플레이 ■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■ 9. 9단계 플레이 ■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■ 0. 게임 종료■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
─────────────────────────────────────────────
                                               제작자 : spareone
─────────────────────────────────────────────
** 네모 특수기호는 UI 설계를 위한 것으로, 실제 게임플레이 시에는 보이지 않습니다. **

처음 시작하거나, 9단계를 통과했을 때 표시하는 화면입니다.
1~9를 누르면 게임이 시작되며, 0번을 누르면 종료합니다.

0 : 48 반환
1 : 49 반환

*게임 화면
-------------------------------------------------------------------------------------------------------
HP : ■■■■■■■■■■      |            경과 시간 : 00:00            |             획득 점수 : 100점
-------------------------------------------------------------------------------------------------------
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
-------------------------------------------------------------------------------------------------------
N단계                                |            단 어 입 력 공 간            |                                  
-------------------------------------------------------------------------------------------------------
** 네모 특수기호는 UI 설계를 위한 것으로, 실제 게임플레이 시에는 보이지 않습니다. (HP 표시하는 네모 제외) **
위쪽은 HP, 경과 시간, 획득 점수가 표시됨
가운데는 단어가 내려오는 영역 - 45*20 사이즈
아래쪽 왼쪽에는 단계가 표시됨
아래쪽 가운데는 단어 입력 공간임

단어입력공간에 커서를 맞춥니다. 글자를 입력받아 해당 글자가 화면 위에 있으면 사라지면서 2점씩 얻습니다.
단어가 위에서 아래로 이동합니다. 단어가 계속 아래로 이동해 한계치에 도달하면 단어는 사라집니다.
이 때 HP는 한 칸이 깎입니다. 총 10번이 깎이면 게임 오버가 되며, 메인화면으로 돌아갑니다.
한 단계당 나오는 단어의 개수는 50개입니다. 50개를 다 입력할 시 (100점 받을 시) 다음 라운드로 이동합니다.
9단계 통과 시, 메인 화면으로 이동합니다.

한 단계를 끝냈을 때 사용된 HP, 점수는 모두 초기화됩니다.

gotoxy(2,4) 최소시작부분

단어 최대 20개
단어가 나타났을 때 동시에 배열에 저장
gets 함수로 단어를 입력받은 후 배열에 저장된 단어가 있으면 없애고 점수 적립

*함수 구성
int main()                  // 메인 함수
int start()                  // 메인화면 함수
int game()                 // 게임화면 함수 (시간 경과, 점수, HP 계산도 여기서 이루어짐)
char word(a,b)            // 단어를 반환할 함수. a,b(a글자, b번째 의미)를 입력받으면 해당하는 글자를 반환함. 입력은 game() 함수에서 rand()로 받음.
void gotoxy()             // 커서 이동 함수

*파일 구성
-index.c (main 함수가 들어있는 파일)
-main.c (start 함수가 들어있는 파일)
-game.c (game, char 함수가 들어있는 파일)
