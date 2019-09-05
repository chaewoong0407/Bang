#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include "Mmsystem.h"
#include "Digitalv.h"
MCI_OPEN_PARMS m_mciOpenParms;
MCI_PLAY_PARMS m_mciPlayParms;
DWORD m_dwDeviceID;
MCI_OPEN_PARMS mciOpen;
MCI_PLAY_PARMS mciPlay;

int dwID;

#define BANG_BGM "C:\\Users\\user\\Desktop\\Bang\\BANG_BGM.wav"
#define BANG_BANG "C:\\Users\\user\\Desktop\\Bang\\BANG_BANG.wav"
#define BANG_MISS "C:\\Users\\user\\Desktop\\Bang\\BANG_MISS.wav"
#define BANG_BEER "C:\\Users\\user\\Desktop\\Bang\\BANG_BEER.wav"
#define BANG_COIN "C:\\Users\\user\\Desktop\\Bang\\BANG_COIN.wav"
#define BANG_HORSE "C:\\Users\\user\\Desktop\\Bang\\BANG_HORSE.wav"
#define BANG_INDIAN "C:\\Users\\user\\Desktop\\Bang\\BANG_INDIAN.wav"
#define BANG_CUT "C:\\Users\\user\\Desktop\\Bang\\BANG_CUT.wav"
#define BANG_CAT "C:\\Users\\user\\Desktop\\Bang\\BANG_CAT.wav"


int boan_num = 0, baesin_num = 0,
boo_num = 0, mubub_num = 0;
int n, peeple, win = 0, mh = 0;
int bang_check = 0; // 0 이면 뱅 가능, 1이면 불가능
int people; //사람 수 ( 나중에 입력받음 )
int py1 = 2, py2 = 36, e = 0;
int p3 = 3, p162 = 162, p42 = 42, p122 = 122, p80 = 80, p57 = 57, p104 = 104;
int tmp2 = 0;
int FMT();
void win_check();
void print_seat();
void panic();
void act_saloon(int py);
int check_maxhp();
void saloon_maxhp();
void print_result(int r);
void hpcard(struct Player *py);
void throw_card(struct Player *py);
void act_Panic(int py);
void four(struct Player player_check[]);
void five(struct Player player_check[]);
void six(struct Player player_check[]);
void seven(struct Player player_check[]);
void check_skill(int target);
void gotoxy(int x, int y);
void card_draw(struct Player *py, int repeat_cnt);
void print_nemo(int n);
void act_gun();
void swap(int* A, int* B);
void hp_card(int py);
void randomCard(int* card, int size);
void act_beer();
void nokturn();
void turn();
void charre();
void find_card(int target_card);
void Bang(int py);
void act_bang();
void SCcard(int x, int y, int py);
void printhp(int hp);
void Cat_balou();
void act_cat(int py);
void yeokhal(int people);
void printcard(int card_num);
void printskill(int skill_num);
void printyeokhal(int yeokhal_num);
void start_check();
void Gun(int py);
void death_check(int py);
void act(struct Player act_player);
void act_Store(int py);
void start(int a);
void random();
void act_indian();
void empty_check();
void Indian(int py);
int person(int peo);
void act_fight();
#define CARDSIZE 80
int CCard[CARDSIZE];
enum card {
	bang = 0, // 뱅!!
	miss,     // 빗나감
	beer,     // 맥주
	bank,     // 웰스파고은행
	bank2,    // 역마차
	gun,      // 기관총
	indian,   // 인디언
	saloon,   // 주점
	Balou,    // 캣 벌로우
	Panic,    // 강탈
	Store,	  // 잡화점
	fight,	  // 결투
	card_amount
};//발표발표
enum skill {
	빌리_더_키드 = 0,
	수지_라파예트,
	마사_제인_캐너리,
	바트_캐시디,
	skill_amount
};
struct Player {
	char name[20];// 플레이어 이름
	int yeokhal;// 역할
	int skill;// 능력
	int card[10];// 카드 card[카드 칸]
	int hp;// 체력
	int turn;
	int seat_X;
	int seat_Y;
	int mhp;
};
struct Player player[7];
int main() {

	int x = 30, y = 3;
	char h;
	int han;
	int i_arr[7] = { -1,-1,-1,-1,-1,-1,-1 };
	int skill_arr[7] = { -1,-1,-1,-1,-1,-1,-1 };
	int  a = 0, i, j, tmp;
	int skill_count = 3;
	srand(time(NULL) + 7);
	random();
	randomCard(CCard, CARDSIZE); // 카드를 섞어준다.
	system("mode con cols=190 lines=50");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); //짙은 회색
	gotoxy(x, y++);
	printf("                                                                                                                    ■   ");
	gotoxy(x, y++);
	printf("          □             □□□□□□□□□□□□□□□□□□□□□■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(x, y++);
	printf("          □□   □□□□□□□□□□□□□□□□□□□□□□□□□■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(x, y++);
	printf("           □□□ □□□□□□□□□□□□□□□□□□□□□□□□□■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(x, y++);
	printf("           □□□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(x, y++);
	printf("       ■■■■■■■■□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(x, y++);
	printf("         ■■■■■■■□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(x, y++);
	printf("       ■■■■■■■■□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(x, y++);
	printf("     ■■■■■■■■■□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(x, y++);
	printf("     ■■■■■■■■■□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(x, y++);
	printf("     ■■■■■■■■■□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(x, y++);
	printf("     ■■■■■■■■■□□□□□□□□□□□□□□□□□□□□□□□");
	gotoxy(x, y++);
	printf("   ■■■■■■■■■■    □□       ■■■       □□          ");
	gotoxy(x, y++);
	printf(" ■■■■■■■■■■■     □□       ■■        □□       ");
	gotoxy(x, y++);
	printf(" ■■■■■■■■■■■     □□       ■         □□       ");
	gotoxy(x, y++);
	printf("■■■■■■■■■■        □□       ■       □□");
	gotoxy(x, y++);
	printf("■■■■■■■               □□              □□                   ");
	gotoxy(x, y++);
	printf("■■■■■■■                 □□□        □□                   ");
	gotoxy(x, y++);
	printf("■■■■■■■                    □□□□□□                   ");
	gotoxy(x, y++);
	printf("■■■■■■■");
	gotoxy(x, y++);
	printf("■■■■■■■");
	gotoxy(x, y++);
	printf("■■■■■■■");
	gotoxy(x, y++);
	printf("■■■■■■■");
	gotoxy(x, y++);
	printf("■■■■■■■");
	y = 13;
	x = 88;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //빨강
	gotoxy(x, y);
	printf("■■■■■    ■              ■         ■      ■■■■        ■■  ■■");
	gotoxy(x, ++y);
	printf(" ■      ■    ■■            ■■       ■     ■      ■       ■■  ■■");
	gotoxy(x, ++y);
	printf("  ■       ■   ■ ■           ■ ■      ■   ■          ■     ■■  ■■");
	gotoxy(x, ++y);
	printf("   ■      ■    ■   ■         ■  ■     ■  ■            ■    ■■  ■■");
	gotoxy(x, ++y);
	printf("    ■■■■      ■    ■        ■   ■    ■  ■                  ■■  ■■");
	gotoxy(x, ++y);
	printf("     ■      ■    ■■■■■      ■    ■   ■   ■       ■■■    ■■  ■■");
	gotoxy(x, ++y);
	printf("      ■       ■   ■        ■    ■     ■  ■   ■           ■   ");
	gotoxy(x, ++y);
	printf("       ■      ■    ■         ■   ■      ■ ■     ■         ■    ■■  ■■");
	gotoxy(x, ++y);
	printf("        ■■■■      ■           ■ ■       ■■       ■■■■■     ■■  ■■");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 하양
	gotoxy(x, ++y);
	gotoxy(x, ++y);
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(x, ++y);
	y = y + 2;
	gotoxy(x - 15, ++y);
	printf("게임 시작: 아무키나 누르십시오  게임 종료: Z 도움말 : C ");
	gotoxy(x - 15, ++y);
	scanf_s("%c", &h);
	getchar();
	if (h == 'z') {
		exit(0);
	}
	else if (h == 'c') {
		system("cls");
		printf("\'뱅\'이라는 게임은 4 ~ 7명이 할 수 있는 게임입니다.\n플레잉 카드는 63장 이며, 직업은 4개, 캐릭터 3개로 구성되어 있습니다\n직업은 보안관,무법자,배신자,부관으로 구성되어 있습니다. 보안관은 체력이 하나 더 많습니다.\n");
		printf("보안관은 무법자와 배신자를 모두 죽이면 승리하고, 무법자는 보안관을 죽이면 승리합니다.\n또한, 배신자는 자신 이외의 모든 플레이어를 죽이면 승리하며, 부관은 보안관이 승리할 시 함께 승리 합니다.\n");

		printf("※카드 설명\n");
		printf("뱅 : 원하는 플레이어의 체력을 1 깎을 수 있습니다. 하지만 1턴에 한번씩만 사용 할 수 있습니다.\n또한 타겟이 빗나감을 가지고 있다면 방어할 수 있습니다. 또한 뱅을 사용해 인디언을 방어할 수 있습니다.\n");
		printf("빗나감 : 누군가가 뱅, 기관총을 사용하였을 때 공격을 회피할 수 있습니다.\n");
		printf("맥주 : 체력을 1 회복할 수 있습니다. 하지만 체력이 최대일때도 마실 수는 있지만 체력은 증가하지 않으며 카드는 사라집니다.\n");
		printf("웰스파고은행 : 덱에서 카드 3장을 드로우합니다. 단, 10장을 초과할경우 더 드로우되지 않습니다.\n");
		printf("역마차 : 덱에서 카드 2장을 드로우합니다. 단, 10장을 초과할경우 더 드로우되지 않습니다.\n");
		printf("기관총 : 자신을 제외한 모두의 체력을 1 깎습니다. 단 빗나감이 있다면 회피할 수 있습니다.\n");
		printf("인디언 : 자신을 제외한 모두의 체력을 1 깎습니다. 단 뱅이 있다면 회피할 수 있습니다.\n");
		printf("주점 : 자신을 포함한 모두의 체력을 1 회복시킵니다. 단 체력이 최대 체력이라면 회복되지 않습니다.\n");
		printf("캣 벌로우 : 원하는 플레이어의 카드의 제일 위에 있는 카드를 제거합니다.\n");
		printf("※캐릭터 설명\n");
		printf("빌리 더 키드 : 뱅을 원하는 대로 사용할 수 있습니다.\n");
		printf("수지 라파예트 : 자신의 덱에 카드가 하나도 없다면 즉시 카드를 1장 드로우 합니다.\n");
		printf("마사 제인 캐너리 : 뱅을 빗나감으로, 빗나감을 뱅으로 사용 할 수 있습니다.\n\n");
		printf("메인 화면 : 아무키나 누르십시오");
		scanf_s("%c", &h);
		getchar();
		main();
		return;
	}
	start(a); // 인원 수 입력 받음
	a = rand() % people;
	for (i = 0; i < 7; i++) { // player[i].card[j] 모두 -1으로 초기화
		for (j = 0; j < 10; j++) {
			player[i].card[j] = -1;
		}
	}
	for (i = 0; i < people; i++) {  // i_arr[0 ~ people]값을 랜덤으로 넣어줌
		a = rand() % people;
		i_arr[i] = a;
		for (j = 0; j < people; j++) {
			while (i_arr[i] == i_arr[j] && i != j) {
				i_arr[i] = rand() % people;
				j = 0;
			}
		}
	}
	i = 0;
	while (i < people) { //player[난수].yeokhal 에 값을 넣어줌
		for (j = 0; j < boan_num; j++) {
			player[i_arr[i]].yeokhal = 0;
			i++;
		}
		for (j = 0; j < baesin_num; j++) {
			player[i_arr[i]].yeokhal = 1;
			i++;
		}
		for (j = 0; j < boo_num; j++) {
			player[i_arr[i]].yeokhal = 2;
			i++;
		}
		for (j = 0; j < mubub_num; j++) {
			player[i_arr[i]].yeokhal = 3;
			i++;
		}
	}
	//void selectYH(player,i_arr,people);

	x = 90;
	y = 5;
	gotoxy(x, y);
	for (i = 0; i < people; i++) {
		gotoxy(x, ++y);
		printf("%s의 역할", player[i].name);
		y = y + 2;
		gotoxy(x, ++y);
		printyeokhal(player[i].yeokhal);
		gotoxy(x, ++y);
		printf("다음 플레이어 보기: 아무키나 누르십시오");
		while (1)
		{
			if (_kbhit())
			{
				Sleep(2000);
				system("cls");
				break;
			}
		}
		Sleep(500);
	}

	printf("능력 보기: 아무키나 누르십시오\n");
	scanf_s("%d", &tmp);
	getchar();
	system("cls");
	// ▼ 능력 정하기 ▼
	for (i = 0; i < people; i++) {  // skill_arr[0 ~ people]값을 0 ~ skill_count 까지 랜덤으로 넣어줌
		player[i].skill = rand() % skill_amount;
	}
	for (i = 0; i < people; i++) {
		printf("%s의 능력\n", player[i].name);
		printskill(player[i].skill);
		printf("\n");

	}
	printf("카드 보기: 아무키나 누르십시오\n");
	scanf_s("%d", &tmp);
	getchar();
	system("cls");


	// ▼ 체력 지급(모두 4) ▼
	for (i = 0; i < people; i++) {
		player[i].hp = 10;
		player[i].mhp = 10;
	}
	// ▼ 차례 정하기 ▼ (player[i].turn이 1이라면 그 사람 차례)
	for (i = 0; i < people; i++)
		player[i].turn = 0;
	for (i = 0; i < people; i++) {
		if (player[i].yeokhal == 0) {
			player[i].hp = player[i].hp + 1;// 보안관 찾기(보안관이면 turn값이 1이 됨)
			player[i].mhp++;
			break;
		}
	}
	player[i].turn = 1;


	// ▼ 초반 카드 지급 
	for (i = 0; i < people; i++) {
		printf("%s의 카드\n", player[i].name);
		for (j = 0; j < player[i].hp; j++) {
			empty_check();
			player[i].card[j] = CCard[e];
			printcard(player[i].card[j]);
			printf(" ");
			CCard[e] = -1;
			e++;
		}
		printf("\n");
	}
	/*for (j = 0; j < people; j++) {
		printf("%s의 카드\n", player[j].name);
		for (i = e; i < player[j].hp; i++) {


			e = i;
		}
		printf("\n");
	}*/
	// ▼ 게임 시작 ▼ 
	printf("게임 시작: 아무키나 누르십시오\n");
	scanf_s("%d", &han);
	getchar();
	mciOpen.lpstrElementName = "C:\\Users\\user\\Desktop\\Bang\\BANG_BGM.mp3"; // 파일 경로 입력
	mciOpen.lpstrDeviceType = "mpegvideo";

	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
		(DWORD)(LPVOID)&mciOpen);

	dwID = mciOpen.wDeviceID;

	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // play & repeat
		(DWORD)(LPVOID)&m_mciPlayParms);
	system("cls");
	start_check();


	act(player[FMT()]);

	/*for (i = 0; i < 4; i++) {
		printf("%d", player[0].card[i]);
	}*/
	return 0;
}
void act(struct Player act_player) { //player 구조체를 불러옴
	int select = -1, i, j, tm = 0;
	start_check(); //화면 리로드
	if (tmp2 == 0) {
		printf("\n드로우 : 아무키나 누르십시오\n");
		scanf_s("%d", &select);
		getchar();

		card_draw(&player[FMT()], 2);
		tmp2 = 1;
	}
	printf("\n무엇을 하시겠습니까?\n ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("(뱅!! : 0) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("(빗나감 : 1) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("(맥주 : 2) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printf("(웰스파고은행 : 3) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printf("(역마차 : 4) \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf("(기관총 : 5) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("(인디언 : 6) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("(주점 : 7) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("(캣 벌로우 : 8)\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("(강탈 : 9) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("(잡화점 : 10) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("(결투 : 11) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("차례 넘기기 : -1");
	scanf_s("%d", &select);
	getchar();
	switch (select) {
	case -1:
		charre();
		break;
	case bang:
		for (i = 0; i < 10; i++)
		{
			if (player[FMT()].card[i] == 0) {
				tm = 1;
			}
		}
		if (player[FMT()].skill == 2) {
			for (i = 0; i < 10; i++) {
				if (player[FMT()].card[i] == 1) {
					break;
				}
			}
		}
		else if (tm == 0) {
			printf("뱅을 가지고 있지 않습니다.");
			Sleep(200);
			act(act_player);
			break;
		} // BANG 카드가 있는지 없는지 검사
		act_bang();
		break;
	case miss:
		if (player[FMT()].skill == 2) {
			for (i = 0; i < 10; i++) {
				if (player[FMT()].card[i] == 1) {
					tm = 1;
				}
			}
			if (tm == 0) {
				printf("빗나감을 가지고 있지 않습니다.");
				Sleep(200);
				act(act_player);
			}
		}
		else
			break;
		//수지 라파예트 능력 
		break;
	case beer:
		for (i = 0; i < 10; i++) {
			if (player[FMT()].card[i] == 2) {
				tm = 1;
			}
		}
		if (tm == 0) {
			printf("맥주를 가지고 있지 않습니다.");
			Sleep(200);
			act(act_player);
			break;
		} // 맥주 카드가 있는지 없는지 검사
		act_beer();
		break;
	case bank:
		for (i = 0; i < 10; i++) {
			if (player[FMT()].card[i] == 3) {
				tm = 1;
			}
		}
		if (tm == 0) {
			printf("웰스 파고 은행을 가지고 있지 않습니다.");
			Sleep(200);
			act(act_player);
			break;
		}
		for (j = 0; j < 10; j++) {
			if (player[FMT()].card[j] == 3) {
				player[FMT()].card[j] = -1;
				card_draw(&player[FMT()], 3);
				break;
			}
		}
		Sleep(500);
		PlaySound(BANG_COIN, NULL, SND_SYNC);  //웰스 파고 은행 소리
		break;
	case bank2:
		for (i = 0; i < 10; i++) {
			if (player[FMT()].card[i] == 4) {
				tm = 1;
			}
		}
		if (tm == 0) {
			printf("역마차를 가지고 있지 않습니다.");
			Sleep(200);
			act(act_player);
			break;
		}
		for (j = 0; j < 10; j++) {
			if (player[FMT()].card[j] == 4) {
				player[FMT()].card[j] = -1;
				card_draw(&player[FMT()], 2);
				break;
			}
		}
		Sleep(500);
		PlaySound(BANG_HORSE, NULL, SND_SYNC); // 역마차 소리
		break;
	case gun:
		for (i = 0; i < 10; i++) {
			if (player[FMT()].card[i] == 5) {
				tm = 1;
			}
		}
		if (tm == 0) {
			printf("기관총을 가지고 있지 않습니다.");
			Sleep(200);
			act(act_player);
			break;
		}
		act_gun();
		break;
	case indian:
		for (i = 0; i < 10; i++) {
			if (player[FMT()].card[i] == 6) {
				tm = 1;
			}
		}
		if (tm == 0) {
			printf("인디언을 가지고 있지 않습니다.");
			Sleep(200);
			act(act_player);
			break;
		}
		act_indian();
		break;
	case saloon:
		for (i = 0; i < 10; i++) {
			if (player[FMT()].card[i] == 7) {
				tm = 1;
			}
		}
		if (tm == 0) {
			printf("주점을 가지고 있지 않습니다.");
			Sleep(200);
			act(act_player);
			break;
		}
		act_saloon(FMT());
		break;
	case Balou:
		for (i = 0; i < 10; i++) {
			if (player[FMT()].card[i] == 8) {
				tm = 1;
			}
		}
		if (tm == 0) {
			printf("캣 벌로우를 가지고 있지 않습니다.");
			Sleep(200);
			act(act_player);
			break;
		}
		Cat_balou();
		break;
	case Panic:
		for (i = 0; i < 10; i++) {
			if (player[FMT()].card[i] == 9) {
				tm = 1;
			}
		}
		if (tm == 0) {
			printf("강탈을 가지고 있지 않습니다.");
			Sleep(200);
			act(act_player);
			break;
		}
		panic();
		break;
	case Store:
		for (i = 0; i < 10; i++) {
			if (player[FMT()].card[i] == 10) {
				tm = 1;
			}
		}
		if (tm == 0) {
			printf("잡화점을 가지고 있지 않습니다.");
			Sleep(200);
			act(act_player);
			break;
		}
		act_Store(FMT());
		break;
	case fight:
		for (i = 0; i < 10; i++) {
			if (player[FMT()].card[i] == 11) {
				tm = 1;
			}
		}
		if (tm == 0) {
			printf("결투를 가지고 있지 않습니다.");
			Sleep(200);
			act(act_player);
			break;
		}
		act_fight();
		break;
	default:
		printf("잘못 된 입력 입니다");
		act(act_player);
	}
	act(act_player);
}
void Bang(int py) {
	int i, tmp = 0;
	char z;
	for (i = 0; i < 10; i++) {
		if (player[FMT()].skill == 2 && player[FMT()].card[i] == 1) {
			find_card(1);
			check_skill(FMT());
			break;
		}
		else if (player[FMT()].card[i] == 0) {
			find_card(0);
			check_skill(FMT());
			break;
		}
	}

	for (i = 0; i < 10; i++) {
		if (player[py].card[i] == 1 || (player[py].skill == 2 && player[py].card[i] == 0)) {
			tmp = 1;
			printf("\n %s님 빗나감이 있습니다. 막으시겠습니까?\n 예: 아무키나 누르십시오, 아니오: z", player[py].name);
			scanf_s("%c", &z);
			getchar();
			if (z == 'z') {
				printf("\n %s님이 맞았다!", player[py].name);  //맞음
				PlaySound(BANG_BANG, NULL, SND_NOSTOP);  // 뱅 소리
				player[py].hp--;
				if (player[py].skill == 3)
					hp_card(py);
				Sleep(500);
				death_check(py);

				start_check();
				break;
			}
			else {
				printf("\n %s님이 빗나감으로 피하셨습니다.", player[py].name); //빗나감
				player[py].card[i] = -1;
				check_skill(py);
				Sleep(500);
				PlaySound(BANG_MISS, NULL, SND_ASYNC); // 빗나감 소리
				start_check();
				break;
			}
		}
	}
	if (tmp == 0) {
		printf("\n %s님이 맞았다!", player[py].name); //맞음
		player[py].hp--;
		if (player[py].skill == 3)
			hp_card(py);
		Sleep(500);
		PlaySound(BANG_BANG, NULL, SND_NOSTOP);  // 뱅 소리
		death_check(py);
		start_check();
	}
}
void Gun(int py) {
	int i, tmp = 0;
	char z;
	for (i = 0; i < 10; i++) {
		if (player[py].card[i] == 1 || (player[py].skill == 2 && player[py].card[i] == 0)) {
			tmp = 1;
			printf("\n %s님 빗나감이 있습니다. 막으시겠습니까?\n 예: 아무키나 누르십시오, 아니오: z", player[py].name);
			scanf_s("%c", &z);
			getchar();
			if (z == 'z') {

				printf("\n %s님이 맞았다!", player[py].name);
				player[py].hp--;
				if (player[py].skill == 3)
					hp_card(py);
				Sleep(500);
				PlaySound(BANG_BANG, NULL, SND_NOSTOP);  // 뱅 소리
				death_check(py);

				start_check();
				break;
			}
			else {
				printf("\n %s님이 빗나감으로 피하셨습니다.", player[py].name);
				player[py].card[i] = -1;
				check_skill(py);
				Sleep(500);
				PlaySound(BANG_MISS, NULL, SND_ASYNC); // 빗나감 소리
				start_check();
				break;
			}
		}
	}
	if (tmp == 0) {
		printf("\n %s님이 맞았다!", player[py].name);
		player[py].hp--;
		if (player[py].skill == 3)
			hp_card(py);
		Sleep(500);
		PlaySound(BANG_BANG, NULL, SND_NOSTOP);  // 뱅 소리
		death_check(py);
		start_check();
	}
}
void find_card(int target_card) {
	int i, j;

	for (j = 0; j < 10; j++) {
		if (player[FMT()].card[j] == target_card) {
			player[FMT()].card[j] = -1;
			j = 10;
			i = 7;
		}
	}
} // 차례인 플레이어의 target_card를 1개 제거 하는 함수         //발표발표
void target_card(int target_card, int target) {
	int i, j;

	for (j = 0; j < 10; j++) {
		if (player[target].card[j] == target_card) {

			player[target].card[j] = -1;
			j = 10;
			i = 7;
		}
	}
}      //발표발표
void act_bang() {
	int target;
	if (bang_check == 0) {
		printf("\n누구를 쏘시겠습니까? (번호 입력) || 돌아가기: 0\n");
		scanf_s("%d", &target);
		getchar();
		if (target == 0) {
			start_check();
			act(player[FMT()]);
		}
		else if ((target > people) || player[target - 1].hp <= 0) {
			printf("\n해당 타겟 없음");
			Sleep(500);
			start_check();
			act_bang();
			return;
		}
		else if (player[target - 1].turn == 1) {
			printf("\n자신은 쏠 수 없습니다.");
			Sleep(500);
			start_check();
			act_bang();
			return;
		}
		bang_check = 1;
		printf("%s에게 뱅!", player[target - 1].name);
		check_skill(FMT());
		Bang(target - 1);
	}
	else {
		printf("뱅은 한턴에 한번만 사용 가능합니다");
		Sleep(500);
		act(player[FMT()]);
	}
}  //
void printhp(int hp) {
	printf("HP ");
	for (int i = 0; i < hp; i++) {
		printf("□");
	}
}
void printyeokhal(int yeokhal_num) {
	if (yeokhal_num == 0) {  //보안관
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		printf("보안관");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else if (yeokhal_num == 1) {  //배신자
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		printf("배신자");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else if (yeokhal_num == 2) {  //부관
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		printf("부관");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	else if (yeokhal_num == 3) {  //무법자
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //빨강
		printf("무법자");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}
void printskill(int skill_num) {
	switch (skill_num) {// 캐릭터 0 : 빌리 더 키드(뱅 제한없이 사용 가능)  
						//	   	 1 : 수지 라파예트(들고있는 카드 없으면 한장 뽑음) 
						//		 2 : 마사 제인 캐너리(뱅을 빗나감으로 사용가능)
	case 빌리_더_키드:
		printf(" 빌리 더 키드\n");
		break;
	case 수지_라파예트:
		printf(" 수지 라파예트\n");
		break;
	case 마사_제인_캐너리:
		printf(" 마사 제인 캐너리\n");
		break;
	case 바트_캐시디:
		printf("바트 캐시디");

	}
}
void printcard(int card_num) {
	switch (card_num) {
	case bang:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //빨강
		printf("뱅!!");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case miss:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1); //파랑
		printf("빗나감");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case beer:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //노랑
		printf("맥주");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case bank:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); //하늘
		printf("웰스 파고 은행");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case bank2:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3); //하늘
		printf("역마차");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case gun:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); //회색
		printf("기관총");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case indian:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); //어두운 노랑
		printf("인디언");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case saloon:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //초록
		printf("주점");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case Balou:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //노랑
		printf("캣 벌로우");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case Panic:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //연한 빨간색
		printf("강탈");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case Store:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6); //연한 빨간색
		printf("잡화점");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		break;
	case fight:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //빨간색
		printf("결투");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}
void yeokhal(int people) { // 보안관 0 배신자 1 부관 2 무법자 3
	if (people == 4) {
		boan_num = 1;
		baesin_num = 1;
		mubub_num = 2;
	}
	// 보안관 1명, 배신자 1명, 무법자 2명
	else if (people == 5) {
		boan_num = 1;
		baesin_num = 1;
		boo_num = 1;
		mubub_num = 2;
	}
	// 보안관 1명, 배신자 1명, 부관 1명, 무법자 2명
	else if (people == 6) {
		boan_num = 1;
		baesin_num = 1;
		boo_num = 1;
		mubub_num = 3;
	}
	// 보안관 1명, 배신자 1명, 부관 1명, 무법자 3명
	else if (people == 7) {
		boan_num = 1;
		baesin_num = 1;
		boo_num = 2;
		mubub_num = 3;
	}
	// 보안관 1명, 배신자 1명, 부관 2명, 무법자 3명

}
void start(int a) {
	int people;
	if (a == 'z') {
		printf("게임을 종료합니다");
	}
	else {
		printf("게임을 할 인원수를 입력해 주십시오 : ");
		scanf_s("%d", &people);
		getchar();
		person(people);
		peeple = people;
	}
}
int person(int peo) {
	int a, b = 0, i;
	if (peo < 4) {
		printf("뱅은 4명부터 할 수 있습니다.\n");
		start(b);
		return 0;
	}
	else if (peo > 7) {
		printf("뱅은 7명까지만 할 수 있습니다. \n");
		start(b);
		return 0;
	}
	else {
		printf("%d 명에서 시작합니다. 선택한 인원수가 맞나요?\n", peo);
		printf("네: 아무키나 누르십시오 , 아니요: 0\n");
		people = peo;
	}
	scanf_s("%d", &a);
	getchar();

	if (a == 0) {
		start(a);
	}
	else {
		for (i = 0; i < people; i++) {
			printf("플레이어[%d]의 이름 : ", i + 1);
			scanf_s("%s", &player[i].name);
		}
		for (int i = 3; i > 0; i--) {
			printf("%d초 후 시작합니다\n", i);
			Sleep(1000);
		}
		system("cls");
		// ▼ 역할 정하기 ▼
		yeokhal(people); // people수에 따른 역할 수 배정
	}
}
void start_check() {
	check_skill(FMT());
	int card_tmp = 0, tmp = 0;
	system("cls");
	if (people == 4) {
		four(player);
		player[0].seat_X = 3;
		player[0].seat_Y = 2;
		player[1].seat_X = 162;
		player[1].seat_Y = 2;
		player[2].seat_X = 3;
		player[2].seat_Y = 36;
		player[3].seat_X = 162;
		player[3].seat_Y = 36;
		print_seat();
		gotoxy(130, 20);
		printf("상자의 왼쪽 상단에 역할, 그다음에 캐릭터가 표시됩니다.");
		gotoxy(130, 21);
		printf("그 밑에 체력이 표시되며 그 밑에 카드 정렬이 표시됩니다.");
	}
	else if (people == 5) {
		five(player);
		player[0].seat_X = 42;
		player[0].seat_Y = 2;
		player[1].seat_X = 122;
		player[1].seat_Y = 2;
		player[2].seat_X = 3;
		player[2].seat_Y = 36;
		player[3].seat_X = 80;
		player[3].seat_Y = 36;
		player[4].seat_X = 162;
		player[4].seat_Y = 36;
		print_seat();
		gotoxy(130, 20);
		printf("상자의 왼쪽 상단에 역할, 그다음에 캐릭터가 표시됩니다.");
		gotoxy(130, 21);
		printf("그 밑에 체력이 표시되며 그 밑에 카드 정렬이 표시됩니다.");
	}
	else if (people == 6) {
		six(player);
		player[0].seat_X = 3;
		player[0].seat_Y = 2;
		player[1].seat_X = 80;
		player[1].seat_Y = 2;
		player[2].seat_X = 162;
		player[2].seat_Y = 2;
		player[3].seat_X = 3;
		player[3].seat_Y = 36;
		player[4].seat_X = 80;
		player[4].seat_Y = 36;
		player[5].seat_X = 162;
		player[5].seat_Y = 36;
		print_seat();

		gotoxy(130, 20);
		printf("상자의 왼쪽 상단에 역할, 그다음에 캐릭터가 표시됩니다.");
		gotoxy(130, 21);
		printf("그 밑에 체력이 표시되며 그 밑에 카드 정렬이 표시됩니다.");
	}
	else if (people == 7) {
		seven(player);
		player[0].seat_X = 3;
		player[0].seat_Y = 2;
		player[1].seat_X = 80;
		player[1].seat_Y = 2;
		player[2].seat_X = 162;
		player[2].seat_Y = 2;
		player[3].seat_X = 3;
		player[3].seat_Y = 36;
		player[4].seat_X = 57;
		player[4].seat_Y = 36;
		player[5].seat_X = 104;
		player[5].seat_Y = 36;
		player[6].seat_X = 162;
		player[6].seat_Y = 36;
		print_seat();
		gotoxy(130, 20);
		printf("상자의 왼쪽 상단에 역할, 그다음에 캐릭터가 표시됩니다.");
		gotoxy(130, 21);
		printf("그 밑에 체력이 표시되며 그 밑에 카드 정렬이 표시됩니다.");
	}
}
void SCcard(int x, int y, int py) {
	int i;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;
	gotoxy(x, y);
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	x = curInfo.dwCursorPosition.X;
	y = curInfo.dwCursorPosition.Y;

	for (i = 0; i < 10; i++) {
		printf("%d", i + 1);
		printcard(player[py].card[i]);
		gotoxy(x, ++y);
	}
}
void turn() {
	int i, k;
	k = FMT();
	bang_check = 0;
	/*for (i = 0; i < people; i++) {
		if (player[i].turn == 1) {
			player[i].turn = 0;
			if (i >= peeple - 1) {
				i = -1;
			}
			if (player[i + 1].turn == 2) {
				if (i >= peeple - 1) {
					i = -1;
				}
				while (player[i + 1].turn == 2) {
					if (i >= peeple - 1) {
						i = -1;
					}
					i = i + 1;
				}
			}
			player[i + 1].turn = 1;
			act(player[i + 1]);
			return;
		}
	}*/
		player[k].turn = 0;
		
		if (k + 1 >= people) {
			k = -1;
		}
		while (player[k + 1].turn == 2) {
			k++;
			if (k + 1 >= people) {
				k = -1;

			}
		}
		
		player[k + 1].turn = 1;
		
}
void nokturn() {
	act(player[FMT()]);
}
void charre() {
	char h;
	printf("\n 차례를 넘기시겠습니까? 계속하기: 아무키나 누르십시오/ 차례 넘기기 : z\n");
	scanf_s("%c", &h);
	getchar();
	if (h == 'z') {
		hpcard(&player[FMT()]);
		tmp2 = 0;
		turn();
	}
	else {
		nokturn();
	}
}
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int  nemo(int xx, int yy, int turn_check) {

	int i, ytmp, xtmp;
	int kan;
	kan = 10;
	ytmp = yy;
	xtmp = xx;
	gotoxy(xx, yy);
	for (i = 0; i < kan + 4; i++) {
		print_nemo(turn_check);
	}
	for (i = 0; i < kan + 7; i++) {
		gotoxy(xx, ++yy);
		print_nemo(turn_check);
	}
	xx = xx + kan * 3 - (kan - 6);
	yy = ytmp;
	for (i = 0; i < kan + 7; i++) {
		gotoxy(xx, ++yy);
		print_nemo(turn_check);
	}
	xx = xtmp;
	gotoxy(xx, yy);
	for (i = 0; i < kan + 4; i++) {
		print_nemo(turn_check);
	}
	return 0;
}
void four(struct Player player_check[]) {

	nemo(1, 1, player_check[0].turn);
	nemo(160, 1, player_check[1].turn);
	nemo(1, 35, player_check[2].turn);
	nemo(160, 35, player_check[3].turn);
}
void five(struct Player player_check[]) {
	nemo(40, 1, player_check[0].turn);
	nemo(120, 1, player_check[1].turn);
	nemo(1, 35, player_check[2].turn);
	nemo(78, 35, player_check[3].turn);
	nemo(160, 35, player_check[4].turn);
}
void six(struct Player player_check[]) {
	nemo(1, 1, player_check[0].turn);
	nemo(78, 1, player_check[1].turn);
	nemo(160, 1, player_check[2].turn);
	nemo(1, 35, player_check[3].turn);
	nemo(78, 35, player_check[4].turn);
	nemo(160, 35, player_check[5].turn);
}
void seven(struct Player player_check[]) {
	nemo(1, 1, player_check[0].turn);
	nemo(78, 1, player_check[1].turn);
	nemo(160, 1, player_check[2].turn);
	nemo(1, 35, player_check[3].turn);
	nemo(55, 35, player_check[4].turn);
	nemo(102, 35, player_check[5].turn);
	nemo(160, 35, player_check[6].turn);
}
void print_nemo(int n) {
	if (n == 1) {
		printf("■");
	}
	else if(n == 0) {
		printf("□");
	}
	else if (n == 2) {
		printf("×");
	}
}
void act_beer() {
	char tp;
	if (check_maxhp() == 1) { //hp가 맥스보다 더 커질떄
		printf("이미 최대 체력입니다. 마시겠습니까? \n 예 : z 아니오 : 아무키나 누르십시오.");
		scanf_s("%c", &tp);
		getchar();
		if (tp == 'z') {
			printf("맥주를 마십니다");
			Sleep(700);
			PlaySound(BANG_BEER, NULL, SND_SYNC);
			find_card(2);
			check_skill(FMT());
			start_check();
			return;
		}
		else {
			printf("맥주를 안마셨습니다.");
			Sleep(700);
			act(player[FMT()]);
			return;
		}
	}
	else { //hp가 맥스보다 작을때
		printf("%d", player[FMT()].hp);
		player[FMT()].hp++;
	}
	printf("체력을 회복합니다");
	find_card(2);
	check_skill(FMT());
	Sleep(500);
	PlaySound(BANG_BEER, NULL, SND_SYNC);
	start_check();
}
void act_gun() {
	int i;
	find_card(5);
	check_skill(FMT());
	for (i = 0; i < people; i++) {
		if (player[i].turn == 0) {
			Gun(i);
		}
	}
}
void act_indian() {
	int i;
	find_card(6);
	check_skill(FMT());
	PlaySound(BANG_INDIAN, NULL, SND_SYNC);
	Sleep(500);
	for (i = 0; i < people; i++) {
		if (player[i].turn == 0) {
			Indian(i);
		}
	}
}
void act_fight() {
	int target, i, ch = 0;
	char an;
	find_card(11);
	check_skill(FMT());
	printf("싸울 대상을 정하세요.|| 돌아가기 : 0");
	scanf_s("%d", &target); 
	if (target == 0) {
		start_check();
		act(player[FMT()]);
	}
	else if ((target > people) || player[target - 1].hp <= 0) {
		printf("\n해당 타겟 없음");
		Sleep(500);
		start_check();
		act_fight();
		return;
	}
	else if (player[target - 1].turn == 1) {
		printf("\n자신의 카드는 제거할 수 없습니다.");
		Sleep(500);
		start_check();
		act_fight();
		return;
	}
	target--;
	PlaySound(BANG_INDIAN, NULL, SND_SYNC);
	Sleep(500);
	while (1) {
		ch = 0;
		for (i = 0; i < 10; i++) {
			if (player[target].card[i] == 0 || (player[target].skill == 2 && player[target].card[i] == 1)) {
				ch = 1;
			}
		}
		if (ch == 1) {
			printf("\n%s님뱅을 내겠습니까? 예 : 아무키나 누르십시오. 아니오: z", player[target].name);
			scanf_s("%c", &an);
			getchar();
			if (an != 'z')
			{
				printf("뱅을 냈다!");
				Sleep(300);
				for (i = 0; i < 10; i++) {
					ch = 0;
					if (player[target].skill == 2 && player[target].card[i] == 1) {
						target_card(1, target);
						check_skill(target);
						break;
					}
					else if (player[target].card[i] == 0) {
						ch = 0;
						target_card(0, target);
						check_skill(target);
						break;
					}
				}
				start_check();
			}
			else if (an == 'z') {
				printf("%s님이 결투에서 패배했습니다...", player[target].name);
				player[target].hp--;
				if (player[target].skill == 3)
					hp_card(target);
				death_check(target);
				Sleep(700);
				break;
			}
		}
		else {
			printf("더이상 뱅이 없습니다!");
			printf("%s님이 결투에서 패배했습니다...", player[target].name);
			player[target].hp--;
			if (player[target].skill == 3)
				hp_card(target);
			death_check(target);
			Sleep(700);
			break;
		}
		ch = 0;
		for (i = 0; i < 10; i++) {
			if (player[FMT()].card[i] == 0 || (player[FMT()].skill == 2 && player[FMT()].card[i] == 1)) {
				ch = 1;
			}
		}
		if (ch == 1) {
			printf("\n%s님\n뱅을 내겠습니까? 예 : 아무키나 누르십시오. 아니오: z", player[FMT()].name);
			scanf_s("%c", &an);
			getchar();
			if (an != 'z')
			{
				printf("뱅을 냈다!");
				for (i = 0; i < 10; i++) {
					ch = 0;
					if (player[FMT()].skill == 2 && player[FMT()].card[i] == 1) {
						find_card(1);
						check_skill(FMT());
						break;
					}
					else if (player[FMT()].card[i] == 0) {
						ch = 0;
						find_card(0);
						check_skill(FMT());
						break;
					}
				}
				Sleep(300);
				start_check();
			}
			else if (an == 'z') {
				printf("%s님이 결투에서 패배했습니다...", player[FMT()].name);
				player[FMT()].hp--;
				if (player[FMT()].skill == 3)
					hp_card(FMT());
				death_check(FMT());
				Sleep(700);
				break;
			}
		}
		else {
			printf("더이상 뱅이 없습니다!");
			printf("%s님이 결투에서 패배했습니다...", player[FMT()].name);
			player[FMT()].hp--;
			if (player[FMT()].skill == 3)
				hp_card(FMT());
			death_check(FMT());
			Sleep(700);
			break;
		}
	}
}
void act_saloon(int py) {
	int i;
	printf("%s가 주점을 열었습니다. 모두의 hp가 1이 채워집니다.", player[py].name);
	for (i = 0; i < people; i++) {
		if (player[i].turn != 2) {
			player[i].hp++;
			saloon_maxhp();
		}
	}
	find_card(7);
	check_skill(py);
	Sleep(500);
	PlaySound(BANG_BEER, NULL, SND_SYNC);
	start_check();
}
void act_Store(int py) {
	int i;
	printf("%s가 잡화점을 열었습니다. 모두에게 카드 한장씩을 지급합니다.", player[py].name);
	PlaySound(BANG_COIN, NULL, SND_NOSTOP);
	Sleep(500);
	for (i = 0; i < people; i++) {
		if (player[i].turn != 2) {
			card_draw(&player[i], 1);
		}
	}
	Sleep(500);
	find_card(10);
	check_skill(py);
	start_check();
}
void Cat_balou() {
	int tp;
	printf("누구의 카드를 제거할까요??|| 돌아가기 : 0");
	scanf_s("%d", &tp);
	if (tp == 0) {
		start_check();
		act(player[FMT()]);
	}
	else if ((tp > people) || player[tp - 1].hp <= 0) {
		printf("\n해당 타겟 없음");
		Sleep(500);
		start_check();
		Cat_balou();
		return;
	}
	else if (player[tp - 1].turn == 1) {
		printf("\n자신의 카드는 제거할 수 없습니다.");
		Sleep(500);
		start_check();
		Cat_balou();
		return;
	}
	find_card(8);
	check_skill(FMT());
	act_cat(tp - 1);
}
void act_Panic(int py) {
	int i, ran = 0, tmp = 1;
	for (i = 0; i < 10; i++) {
		if (player[py].card[i] != -1) {
			ran = player[py].card[i];
			player[py].card[i] = -1;
			printf("%d", ran);
			Sleep(1000);
			break;
		}
	}
	for (i = 0; i < 10; i++) {
		if (player[FMT()].card[i] == -1) {
			player[FMT()].card[i] = ran;
			break;
		}
	}
	printf("%s님의 카드를 뺏어옵니다.", player[py].name);

	check_skill(py);
	start_check();
}
void panic() {
	int tp;
	printf("누구의 카드를 뺏어올까요?? || 돌아가기 : 0");
	scanf_s("%d", &tp);
	if (tp == 0) {
		start_check();
		act(player[FMT()]);
	}
	else if ((tp > people) || player[tp - 1].hp <= 0) {
		printf("\n해당 타겟 없음");
		Sleep(500);
		start_check();
		panic();
		return;
	}
	else if (player[tp - 1].turn == 1) {
		printf("\n자신의 카드는 뻇을 수 없습니다.");
		Sleep(500);
		start_check();
		panic();
		return;
	}
	find_card(9);
	act_Panic(tp - 1);

}
void act_cat(int py) {
	int i, ran = 0, tmp = 1;
	for (i = 0; i < 10; i++) {
		if (player[py].card[i] != -1) {
			player[py].card[i] = -1;
			break;
		}
	}

	printf("%s님의 카드를 제거합니다.", player[py].name);
	PlaySound(BANG_CAT, NULL, SND_NOSTOP);
	Sleep(700);
	check_skill(py);
	start_check();
}
void Indian(int py) {
	int i, tmp = 0;
	char z;
	find_card(6);
	check_skill(FMT());

	for (i = 0; i < 10; i++) {
		if (player[py].card[i] == 0 || (player[py].skill == 2 && player[py].card[i] == 1)) {
			tmp = 1;
			printf("\n %s님 뱅이 있습니다. 막으시겠습니까?\n 예: 아무키나 누르십시오, 아니오: z", player[py].name);
			scanf_s("%c", &z);
			getchar();
			if (z == 'z') {
				printf("\n %s님이 인디언에게 습격당했다!", player[py].name);  //맞음
				PlaySound(BANG_CUT, NULL, SND_NOSTOP);  // 인디언 소리
				player[py].hp--;
				if (player[py].skill == 3)
					hp_card(py);
				Sleep(500);
				death_check(py);

				start_check();
				break;
			}
			else {
				printf("\n %s님이 뱅으로 피하셨습니다.", player[py].name); //빗나감
				player[py].card[i] = -1;
				check_skill(py);
				Sleep(500);
				PlaySound(BANG_MISS, NULL, SND_ASYNC); // 빗나감 소리
				start_check();
				break;
			}
		}
	}
	if (tmp == 0) {
		printf("\n %s님이 인디언에게 습격당했다!", player[py].name); //맞음
		player[py].hp--;
		if (player[py].skill == 3)
			hp_card(py);
		Sleep(500);
		PlaySound(BANG_CUT, NULL, SND_NOSTOP);   // 인디언 소리
		death_check(py);
		start_check();
	}
}
void card_draw(struct Player *py, int repeat_cnt) { //  card_draw(카드를 얻을 플레이어, 반복 수)
	int i, j, cnt = 0;
	for (i = 0; i < repeat_cnt; i++) {
		for (j = 0; j < 10; j++) {
			if ((*py).card[j] == -1) {
				empty_check();
				(*py).card[j] = CCard[e];
				CCard[e] = -1;
				e++;
				break;
			}
		}
	}
	start_check();
} //발표발표
void throw_card(struct Player *py) {
	int a, i, tmp = 0;
	start_check();
	printf("\n무엇을 버리시겠습니까?\n ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("(뱅!! : 0) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	printf("(빗나감 : 1) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printf("(맥주 : 2) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printf("(웰스파고은행 : 3) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printf("(역마차 : 4) \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printf("(기관총 : 5) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("(인디언 : 6) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf("(주점 : 7) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("(캣 벌로우 : 8)\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("(강탈 : 9) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printf("(잡화점 : 10) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("(결투 : 11) ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	scanf_s("%d", &a);
	getchar();
	for (i = 0; i < 10; i++) {
		if ((*py).card[i] == a && a != -1) {
			(*py).card[i] = -1;
			tmp = 1;
			break;
		}
	}
	if (tmp == 0) {
		printf("\n그런 카드는 없습니다!\n");
		Sleep(500);
		start_check();
		throw_card(py);
	}
}
void hpcard(struct Player *py) {
	int cnt = 0, i;
	for (i = 0; i < 10; i++) {
		if ((*py).card[i] != -1) {
			cnt++;
		}
	}
	while (cnt > (*py).hp) {
		printf("\n카드가 체력보다 많습니다. 카드를 버리십시오\n");
		throw_card(py);
		start_check();
		cnt--;
	}
}
void death_check(int py) {
	int i, oo;
	for (i = 0; i < 10; i++) {
		if (player[py].card[i] == 2 && player[py].hp == 0) {
			printf("\n맥주가 있습니다. 사용하여 체력을 회복시키겠습니까? 예 : 아무키나 누르십시오");
			scanf_s("%d", &oo);
			player[py].hp++;
			target_card(2, py);
			check_skill(py);
			start_check();
		}
	}
	if (player[py].hp == 0) {
		printf("\n%s님이 죽었습니다!\n", player[py].name);
		peeple--;
		player[py].turn = 2;
		printf("%s의 역할 : ", player[py].name);
		printyeokhal(player[py].yeokhal);
		for (i = 0; i < 10; i++) {
			memset(&player[py].card[i], -1, sizeof(int));
		}
		memset(&player[py].hp, 0, sizeof(int));
		memset(&player[py].skill, -1, sizeof(int));
		Sleep(3000);
		start_check();
	}
	win_check();
}
void win_check() {
	int i, boan_cnt = 0, moo_cnt = 0, bae_cnt = 0, boo_cnt = 0;
	for (i = 0; i < people; i++) {
		if (player[i].turn != 2) {
			if (player[i].yeokhal == 0) { //보안
				boan_cnt++;
			}
			if (player[i].yeokhal == 1) { //배신
				bae_cnt++;
			}
			if (player[i].yeokhal == 3) {  //무법
				moo_cnt++;
			}
			if (player[i].yeokhal == 2) {  //부관
				boo_cnt++;
			}


		}
	}
	if (bae_cnt != 0 && moo_cnt == 0 && boo_cnt == 0 && boan_cnt == 0) {//배신자 승리 조건 : 자기빼고 다 뒤짐
		print_result(2);
		Sleep(2000);
		win = 1;
	}
	else if (boan_cnt == 0) {//무법자 승리 조건 : 보안관 없음
		print_result(0);

		Sleep(2000);
		win = 1;
	}
	else if ((moo_cnt == 0) && (bae_cnt == 0)) {//보안관 승리 조건 : 무법자 없음 + 배신자 죽음
		print_result(1);

		Sleep(2000);
		win = 1;
	}
}
void print_result(int r) {
	if (r == 0) {
		printf("\n무법자 승리!");
		Sleep(4000);
		system("cls");
		exit(0);
	}
	if (r == 1) {
		printf("\n보안관 승리!");
		Sleep(4000);
		system("cls");
		exit(0);
	}
	if (r == 2) {
		printf("\n배신자 승리!");
		Sleep(4000);
		system("cls");
		exit(0);
	}
}
void print_seat() {
	int i;
	for (i = 0; i < people; i++) {
		if (player[i].yeokhal == 0) {
			gotoxy(player[i].seat_X, player[i].seat_Y);
			printyeokhal(player[i].yeokhal);
			gotoxy(player[i].seat_X + 6, player[i].seat_Y);
			printskill(player[i].skill);
		}
		else {
			gotoxy(player[i].seat_X, player[i].seat_Y);
			printskill(player[i].skill);
		}
		gotoxy(player[i].seat_X, player[i].seat_Y + 12);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //진한 흰색
		printf("%s", player[i].name);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		gotoxy(player[i].seat_X, player[i].seat_Y + 1);
		printhp(player[i].hp);
		SCcard(player[i].seat_X, player[i].seat_Y + 2, i);
	}
	for (i = 0; i < people; i++) {
		if (player[i].turn == 2) {
			gotoxy(player[i].seat_X, player[i].seat_Y);
			printyeokhal(player[i].yeokhal);
		}
	}
}
int check_maxhp() {
	if (player[FMT()].hp >= player[FMT()].mhp) { //지금 차례인 플레이어의 hp가 최대 hp보다 더 커질때
		return 1;
	}
	else {
		return 0;
	}
}
int FMT() {
	int i;
	for (i = 0; i < people; i++) {
		if (player[i].turn == 1) {
			return i;
		}
	}
}//발표발표
void saloon_maxhp() {
	int i, c = 0;
	for (i = 0; i < people; i++) {
		if (player[i].hp > player[i].mhp) { //모든 플레이어의 hp가 최대 hp보다 더 커질때
			player[i].hp--;
		}
	}
}
void randomCard(int* card, int size)   // 여기서 주목 해야 할 함수.
{
	int i;  // 반복문에 쓰일 변수
	for (i = 0; i < size; i++)
	{
		// 현재 위치의 카드와 현재 위치의 다음위치에서 랜덤하게 뽑은 카드를 바꾼다.
		swap(&card[i], &card[(rand() % (CARDSIZE - i)) + i]);
	}
}  //발표발표
void swap(int* A, int* B)
{
	int temp;
	temp = *A;
	*A = *B;
	*B = temp;
}  //발표발표
void empty_check() {
	int i, cnt = 0;
	for (i = 0; i < CARDSIZE; i++) {
		if (CCard[i] != -1) {
			cnt = 1;
		}
	}
	if (cnt == 0) {
		e = 0;
		printf("카드를 새로 섞습니다");
		Sleep(1000);
		random();
		randomCard(CCard, CARDSIZE);
	}
}  //발표발표
void random() {
	int i;
	for (i = 0; i < 20; i++) {
		CCard[i] = 0; //뱅
	}
	for (i = 20; i < 32; i++) {
		CCard[i] = 1;
	}
	for (i = 32; i < 42; i++) {
		CCard[i] = 2;
	}
	CCard[42] = 3;
	CCard[43] = 3;
	for (i = 44; i < 49; i++) {
		CCard[i] = 4;
	}
	for (i = 49; i < 52; i++) {
		CCard[i] = 5;
	}
	for (i = 52; i < 5; i++) {
		CCard[i] = 6;
	}
	for (i = 54; i < 57; i++) {
		CCard[i] = 7;
	}
	for (i = 57; i < 64; i++) {
		CCard[i] = 8;
	}
	for (i = 64; i < 74; i++) {
		CCard[i] = 9;
	}
	for (i = 74; i < 77; i++) {
		CCard[i] = 10;
	}
	for (i = 77; i < 80; i++) {
		CCard[i] = 11;
	}
}    //발표발표
void check_skill(int target) {
	int i, cnt = 0;
	// 캐릭터 0 : 빌리 더 키드(뱅 제한없이 사용 가능)  
	//	   	 1 : 수지 라파예트(들고있는 카드 없으면 즉시 한장 뽑음) 
	//		 2 : 마사 제인 캐너리(뱅을 빗나감으로 사용가능)
	if (player[FMT()].skill == 0) {
		bang_check = 0;
	}
	if (player[target].skill == 1) {
		for (i = 0; i < 10; i++) {
			if (player[target].card[i] != -1) {
				cnt = 1;
				break;
			}
		}
		if (cnt == 0) {
			printf("\n수지 라파예트의 능력! 카드를 한장 드로우 합니다");
			Sleep(700);
			card_draw(&player[target], 1);
		}
	}
}
void hp_card(int py) {
	if (player[py].skill == 3) {
		printf("\n 바트 캐시디의 능력! 카드를 한장 드로우 합니다");
		Sleep(700);
		card_draw(&player[py], 1);
	}
}