

#include<stdio.h>
#include<Windows.h>
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
int main()
{
	mciOpen.lpstrElementName = "C:\\Users\\user\\Desktop\\Bang\\BANG_BGM.mp3"; // ���� ��� �Է�
	mciOpen.lpstrDeviceType = "mpegvideo";

	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
		(DWORD)(LPVOID)&mciOpen);

	dwID = mciOpen.wDeviceID;

	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // play & repeat
		(DWORD)(LPVOID)&m_mciPlayParms);
	//���� ���� ��ġ, SND_ASYNC, SND_LOOP �������� ���� �߿�
	//SND_ASYNC : ����ϸ鼭 �����ڵ� ����
	//SND_LOOP : �ݺ����
	Sleep(2000);
	PlaySound(BANG_BANG, NULL, SND_NOSTOP);
	Sleep(1000);
	PlaySound(BANG_MISS, NULL, SND_ASYNC);
	Sleep(1000);
	PlaySound(BANG_BEER, NULL, SND_SYNC);
	Sleep(1000);
	PlaySound(BANG_COIN, NULL, SND_SYNC);
	Sleep(1000);
	PlaySound(BANG_HORSE, NULL,  SND_SYNC);
	Sleep(1000);

	Sleep(10000);
	return;

}