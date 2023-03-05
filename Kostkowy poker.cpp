//Konrad Sitek
#include <iostream>

using namespace std;

int main()
{
	//Wczytywanie liczby rozgrywek
	int GamesCount,LpGame = 1;
	cin >> GamesCount;

	char IdPlayer1, IdPlayer2;
	int VP1_1, VP1_2, VP1_3, VP1_4, VP2_1, VP2_2, VP2_3, VP2_4;

	//Statystyki graczy
	float winA{}, roundsA{}, loseA{},
		winB{}, roundsB{}, loseB{},
		winC{}, roundsC{}, loseC{},
		winD{}, roundsD{}, loseD{},
		winE{}, roundsE{}, loseE{};


	while (LpGame <= GamesCount)
	{

		int  P1_Score{ 0 }, P2_Score{ 0 };

		//Wczytywanie rzutow gracza 1
		cin >> IdPlayer1;
		cin >> VP1_1 >> VP1_2 >> VP1_3 >> VP1_4;

		//Wczytywanie rzutow gracza 2
		cin >> IdPlayer2;
		cin >> VP2_1 >> VP2_2 >> VP2_3 >> VP2_4;
	
		//Kto zwycięża
		bool P1_Win_1{ false }, P2_Win_1{ false }, P1_Win_2{ false }, P2_Win_2{ false }, P1_Win_3{ false }, P2_Win_3{ false }, P1_Win_4{ false }, P2_Win_4{ false }, P1_Win_5{ false }, P2_Win_5{ false };

		//Reguła 1.
		if (VP1_1 == VP1_2 && VP1_1 == VP1_3 && VP1_1 == VP1_4) P1_Win_1 = true;
		if (VP2_1 == VP2_2 && VP2_1 == VP2_3 && VP2_1 == VP2_4) P2_Win_1 = true;

		//Reguła 2.
		if (VP1_1 != VP1_2 && VP1_1 != VP1_3 && VP1_1 != VP1_4 && VP1_2 != VP1_3 && VP1_2 != VP1_4 && VP1_3 != VP1_1 && VP1_3 != VP1_2 && VP1_3 != VP1_4 && VP1_4 != VP1_1 && VP1_4 != VP1_2 && VP1_4 != VP1_3) P1_Win_2 = true;
		if (VP2_1 != VP2_2 && VP2_1 != VP2_3 && VP2_1 != VP2_4 && VP2_2 != VP2_3 && VP2_2 != VP2_4 && VP2_3 != VP2_1 && VP2_3 != VP2_2 && VP2_3 != VP2_4 && VP2_4 != VP2_1 && VP2_4 != VP2_2 && VP2_4 != VP2_3) P2_Win_2 = true;

		//Reguła 3.
		 if ((VP1_1 == VP1_2 && VP1_3 == VP1_4 )|| (VP1_1 == VP1_3 && VP1_2 == VP1_4 )|| (VP1_1 == VP1_4 && VP1_2 == VP1_3)) if (P1_Win_1 != true) P1_Win_3 = true;
		 if ((VP2_1 == VP2_2 && VP2_3 == VP2_4) || (VP2_1 == VP2_3 && VP2_2 == VP2_4) || (VP2_1 == VP2_4 && VP2_2 == VP2_3)) if (P2_Win_1 != true) P2_Win_3 = true;
		
		//Reguła 4.
		if ((VP1_1 != VP1_2 && VP1_1 != VP1_3 && VP1_1 != VP1_4 && VP1_2 == VP1_3 && VP1_3 == VP1_4) ||
			(VP1_2 != VP1_1 && VP1_2 != VP1_3 && VP1_2 != VP1_4 && VP1_1 == VP1_3 && VP1_3 == VP1_4) ||
			(VP1_3 != VP1_1 && VP1_3 != VP1_2 && VP1_3 != VP1_4 && VP1_1 == VP1_2 && VP1_2 == VP1_4) ||
			(VP1_4 != VP1_1 && VP1_4 != VP1_2 && VP1_4 != VP1_3 && VP1_1 == VP1_2 && VP1_2 == VP1_3)) P1_Win_4 = true;

		if ((VP2_1 != VP2_2 && VP2_1 != VP2_3 && VP2_1 != VP2_4 && VP2_2 == VP2_3 && VP2_3 == VP2_4) ||
			(VP2_2 != VP2_1 && VP2_2 != VP2_3 && VP2_2 != VP2_4 && VP2_1 == VP2_3 && VP2_3 == VP2_4) ||
			(VP2_3 != VP2_1 && VP2_3 != VP2_2 && VP2_3 != VP2_4 && VP2_1 == VP2_2 && VP2_2 == VP2_4) ||
			(VP2_4 != VP2_1 && VP2_4 != VP2_2 && VP2_4 != VP2_3 && VP2_1 == VP2_2 && VP2_2 == VP2_3)) P2_Win_4 = true;
		
		//Reguła 5.
		if (VP1_1 == VP1_2 || VP1_1 == VP1_3 || VP1_1 == VP1_4 || VP1_2 == VP1_3 || VP1_2 == VP1_4 || VP1_3 == VP1_4) if (P1_Win_1 == false && P1_Win_3 == false && P1_Win_4 == false)  P1_Win_5 = true;
		if (VP2_1 == VP2_2 || VP2_1 == VP2_3 || VP2_1 == VP2_4 || VP2_2 == VP2_3 || VP2_2 == VP2_4 || VP2_3 == VP2_4) if (P2_Win_1 == false && P2_Win_3 == false && P2_Win_4 == false)  P2_Win_5 = true;


		
		if (P1_Win_1 == true || P2_Win_1 == true) //Wtnik rundy jeżeli: Warunek 1
		{
			if (P1_Win_1 == true && P2_Win_1 == true)
			{
				if (VP1_1 > VP2_1) P1_Score++;
				else if (VP2_1 > VP1_1) P2_Score++;
			}
			else
			{
				if (P1_Win_1 == true) P1_Score++;
				else P2_Score++;
			}
		}
		else if (P1_Win_2 == true || P2_Win_2 == true) //Wtnik rundy jeżeli: Warunek 2
		{
			if (P1_Win_2 == true && P2_Win_2 == true) {}
			else if (P1_Win_2 == true) P1_Score++; 
			else P2_Score++;

		}
		else if (P1_Win_3 == true || P2_Win_3 == true) //Wtnik rundy jeżeli: Warunek 3
		{
			if (P1_Win_3 == true && P2_Win_3 == true)
			{
				int MaxV_1{}, MaxV_2{};

				if (VP1_1 > MaxV_1) MaxV_1 = VP1_1;
				if (VP1_2 > MaxV_1) MaxV_1 = VP1_2;
				if (VP1_3 > MaxV_1) MaxV_1 = VP1_3;
				if (VP1_4 > MaxV_1) MaxV_1 = VP1_4;

				if (VP2_1 > MaxV_2) MaxV_2 = VP2_1;
				if (VP2_2 > MaxV_2) MaxV_2 = VP2_2;
				if (VP2_3 > MaxV_2) MaxV_2 = VP2_3;
				if (VP2_4 > MaxV_2) MaxV_2 = VP2_4;

				if (MaxV_1 > MaxV_2) P1_Score++;
				else if (MaxV_2 > MaxV_1) P2_Score++;
			}
			else
			{
				if (P1_Win_3 == true) P1_Score++;
				else P2_Score++;
			}

		}
		else if (P1_Win_4 == true || P2_Win_4 == true) //Wtnik rundy jeżeli: Warunek 4
		{
			if (P1_Win_4 == true && P2_Win_4 == true)
			{
				int MaxV_1{}, MaxV_2{};
				if (VP1_1 == VP1_2 || VP1_1 == VP1_3 || VP1_1 == VP1_4) MaxV_1 = VP1_1;
				if (VP1_2 == VP1_1 || VP1_2 == VP1_3 || VP1_2 == VP1_4) MaxV_1 = VP1_2;
				if (VP1_3 == VP1_2 || VP1_1 == VP1_3 || VP1_3 == VP1_4) MaxV_1 = VP1_3;
				if (VP1_4 == VP1_2 || VP1_4 == VP1_3 || VP1_4 == VP1_1) MaxV_1 = VP1_4;

				if (VP2_1 == VP2_2 || VP2_1 == VP2_3 || VP2_1 == VP2_4) MaxV_2 = VP2_1;
				if (VP2_2 == VP2_1 || VP2_2 == VP2_3 || VP2_2 == VP2_4) MaxV_2 = VP2_2;
				if (VP2_3 == VP2_2 || VP2_1 == VP2_3 || VP2_3 == VP2_4) MaxV_2 = VP2_3;
				if (VP2_4 == VP2_2 || VP2_4 == VP2_3 || VP2_4 == VP2_1) MaxV_2 = VP2_4;

				if (MaxV_1 > MaxV_2) P1_Score++;
				else if (MaxV_2 > MaxV_1) P2_Score++;
			}
			else
			{
				if (P1_Win_4 == true) P1_Score++;
				else P2_Score++;
			}

		}
		else if (P1_Win_5 == true || P2_Win_5 == true) //Wtnik rundy jeżeli: Warunek 5
		{
			if (P1_Win_5 == true && P2_Win_5 == true)
			{
				int MaxV_1{}, MaxV_2{};
				if (VP1_1 == VP1_2 || VP1_1 == VP1_3 || VP1_1 == VP1_4) MaxV_1 = VP1_1;
				if (VP1_2 == VP1_1 || VP1_2 == VP1_3 || VP1_2 == VP1_4) MaxV_1 = VP1_2;
				if (VP1_3 == VP1_2 || VP1_1 == VP1_3 || VP1_3 == VP1_4) MaxV_1 = VP1_3;
				if (VP1_4 == VP1_2 || VP1_4 == VP1_3 || VP1_4 == VP1_1) MaxV_1 = VP1_4;


				if (VP2_1 == VP2_2 || VP2_1 == VP2_3 || VP2_1 == VP2_4) MaxV_2 = VP2_1;
				if (VP2_2 == VP2_1 || VP2_2 == VP2_3 || VP2_2 == VP2_4) MaxV_2 = VP2_2;
				if (VP2_3 == VP2_2 || VP2_1 == VP2_3 || VP2_3 == VP2_4) MaxV_2 = VP2_3;
				if (VP2_4 == VP2_2 || VP2_4 == VP2_3 || VP2_4 == VP2_1) MaxV_2 = VP2_4;

				if (MaxV_1 > MaxV_2) P1_Score++;
				else if (MaxV_2 > MaxV_1) P2_Score++;
			}
			else
			{
				if (P1_Win_5 == true) P1_Score++;
				else P2_Score++;
			}
		}
	if (P1_Score == 0 && P2_Score == 0) //Wtnik rundy jeżeli: Remis
	{
		if (VP1_1 + VP1_2 + VP1_3 + VP1_4 > VP2_1 + VP2_2 + VP2_3 + VP2_4) P1_Score++;
		else if(VP2_1 + VP2_2 + VP2_3 + VP2_4> VP1_1 + VP1_2 + VP1_3 + VP1_4) P2_Score++;
	}
		if (P1_Score == 1) //Wygrana gracza 1
		{
			if (IdPlayer1 == 'a') winA++;
			else if (IdPlayer1 == 'b') winB++;
			else if (IdPlayer1 == 'c') winC++;
			else if (IdPlayer1 == 'd') winD++;
			else if (IdPlayer1 == 'e') winE++;

			if (IdPlayer2 == 'a') loseA++;
			else if (IdPlayer2 == 'b') loseB++;
			else if (IdPlayer2 == 'c') loseC++;
			else if (IdPlayer2 == 'd') loseD++;
			else if (IdPlayer2 == 'e') loseE++;

		}
		else if (P2_Score == 1) //Wygrana gracza 2
		{

			if (IdPlayer2 == 'a') winA++;
			else if (IdPlayer2 == 'b') winB++;
			else if (IdPlayer2 == 'c') winC++;
			else if (IdPlayer2 == 'd') winD++;
			else if (IdPlayer2 == 'e') winE++;

			if (IdPlayer1 == 'a') loseA++;
			else if (IdPlayer1 == 'b') loseB++;
			else if (IdPlayer1 == 'c') loseC++;
			else if (IdPlayer1 == 'd') loseD++;
			else if (IdPlayer1 == 'e') loseE++;
			
		}

		//Licznik Rund
		if (IdPlayer1 == 'a') roundsA++;
		else if (IdPlayer1 == 'b') roundsB++;
		else if (IdPlayer1 == 'c') roundsC++;
		else if (IdPlayer1 == 'd') roundsD++;
		else if (IdPlayer1 == 'e') roundsE++;


		if (IdPlayer2 == 'a') roundsA++;
		else if (IdPlayer2 == 'b') roundsB++;
		else if (IdPlayer2 == 'c') roundsC++;
		else if (IdPlayer2 == 'd') roundsD++;
		else if (IdPlayer2 == 'e') roundsE++;
		

		LpGame++; // Zmiana rundy
	}

	if (roundsA != 0) //Wynik gracza A
	{
		cout << "gracz a" << endl;
		if (winA != 0) cout << "    wygrane: " << winA / roundsA * 100<< "%" << endl;
		if (loseA + winA != roundsA) cout << "    remisy: " << (roundsA - loseA - winA) / roundsA * 100 << "%" << endl;
		if(loseA != 0) cout << "    przegrane: " << loseA / roundsA * 100 << "%" << endl;
		cout << endl;	
	}
	if (roundsB != 0) //Wynik gracza B
	{
		cout << "gracz b" << endl;
		if (winB != 0) cout << "    wygrane: " << winB / roundsB * 100 << "%" << endl;
		if (loseB + winB != roundsB) cout << "    remisy: " << (roundsB - loseB - winB) / roundsB * 100 << "%" << endl;
		if (loseB != 0) cout << "    przegrane: " << loseB / roundsB * 100 << "%" << endl;
		cout << endl;
	}
	if (roundsC != 0) //Wynik gracza C
	{
		cout << "gracz c" << endl;
		if (winC != 0) cout << "    wygrane: " << winC / roundsC * 100 << "%" << endl;
		if (loseC + winC != roundsC) cout << "    remisy: " << (roundsC - loseC - winC) / roundsC * 100 << "%" << endl;
		if (loseC != 0) cout << "    przegrane: " << loseC / roundsC * 100 << "%" << endl;
		cout << endl;
	}
	if (roundsD != 0) //Wynik gracza D
	{
		cout << "gracz d" << endl;
		if (winD != 0) cout << "    wygrane: " << winD / roundsD * 100 << "%" << endl;
		if (loseD + winD != roundsD) cout << "    remisy: " << (roundsD - loseD - winD) / roundsD * 100 << "%" << endl;
		if (loseD != 0) cout << "    przegrane: " << loseD / roundsD * 100 << "%" << endl;
		cout << endl;
	}
	if (roundsE != 0) //Wynik gracza E
	{
		cout << "gracz e" << endl;
		if (winE != 0) cout << "    wygrane: " << winE / roundsE * 100 << "%" << endl;
		if (loseE + winE != roundsE) cout << "    remisy: " << (roundsE - loseE - winE) / roundsE * 100 << "%" << endl;
		if (loseE != 0) cout << "    przegrane: " << loseE / roundsE * 100 << "%" << endl;
		cout << endl;
	}




}