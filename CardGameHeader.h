#pragma once
#ifndef _CARD_MATCHING_HEADER_
#define _CARD_MATCHING_HEADER_
#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

enum CARDSTATE { OPEN_CASE = 1, CLOSE_CASE, SELECT_CASE }; // ī���� ������ ǥ���� �������� ���̱� ���� ���Ÿ����.
enum GAMESTATE { INIT, READY, OPENCARD, RUNNING, STOP, SUCCES, FAIL, RESULT }; // ������ ������ ���ϵ���

class Alphabet
{
	char _alphabet;
	bool _used;
public:
	Alphabet();
	void SetUsed(bool what);
	bool GetUsed()const;
	void SetAlphabet(char alphabet);
	char GetAlphabet()const;
};

class Card
{
	CARDSTATE _state;
	int _posx, _posy;
	Alphabet _alphabet;
	bool _used;
public:
	void SetAlphabet(char);
	CARDSTATE GetState()const;
	void SetState(CARDSTATE);
	int GetXPos()const;
	void SetXPos(int);
	int GetYPos()const;
	void SetYPos(int);
	bool GetUsed()const;
	void SetUsed(bool);
	Alphabet GetAlphabet()const;
	void OpenCard(int, int, char);
	void MatchCard(int, int, char);
	void CloseCard(int, int);
	void Print2Screen(int, int, const char*);
	void Render();
};

class GameManager
{
	Card _card_list[30]; //ī�� 30���� ����Ʈ
	Alphabet _alphabet_list[26]; //���ĺ� 26���� ����Ʈ
	int point;
	int curXPos;
	int curYPos;
public:
	int GetXPos()const;
	Card& GetCurrentCard(int);
	int GetYPos()const;
	void SetXPos(int);
	void SetYPos(int);
	void ShowData()
	{
		for (int i = 0; i < 30; i++)
		{
			cout << _card_list[i].GetAlphabet().GetAlphabet() << "  ";
		}
		cout << endl;
		for (int i = 0; i < 26; i++)
		{
			cout << _alphabet_list[i].GetAlphabet() << "  ";
		}

	}
	void InitGame();
	void MovePosition(int,int);
};

#endif // !_CARD_MATCHING_HEADER_
