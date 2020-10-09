#include "main.h"

int main()
{
	srand(unsigned (time(0)));
	unsigned int computer_score = 0, player_score = 0;
	bool whoMovesFirst = WhoMovesFirst();
	
	for (size_t i = 0; i < 8; i++)
	{
		if (whoMovesFirst) {
			cout << "Computer moves!" << endl;
			computer_score += Throw();
			PrintScore(computer_score, player_score);
		}
		else
		{
			char c;
			cout << "Press Y to throw or N to exit: ";
			cin >> c;
			switch (c) {
			case 'Y':
				player_score += Throw();
				break;
			case 'N':
				exit(0);
			default:
				break;
			}
			PrintScore(computer_score, player_score);
		}
		whoMovesFirst = !whoMovesFirst;

	}
	if (computer_score > player_score)
		cout << "Computer won" << " by " << computer_score - player_score << " point";
	else if (computer_score < player_score)
		cout << "You won" << " by " << player_score - computer_score << " point";
	else
		cout << "Draw";
	return 0;
}
unsigned int Throw()
{
	
	unsigned int result = 0, tmp = 0;

	for (size_t i = 0; i < 2; i++)
	{
		tmp = 1 + rand() % 6;
		PrintCube(tmp);
		cout << endl;
		result += tmp;
	}
	cout << "Total: " << result << endl;
	return result;
}

bool WhoMovesFirst()
{
	return rand() % 2;
}

void PrintCube(unsigned int n)
{
	switch (n)
	{
	case 1:
		cout << "@@@@@@@" << endl;
		cout << "@@@@@@@" << endl;
		cout << "@@@ @@@" << endl;
		cout << "@@@@@@@" << endl;
		cout << "@@@@@@@" << endl;
		break;
	case 2:
		cout << "@@@@@@@" << endl;
		cout << "@ @@@@@" << endl;
		cout << "@@@@@@@" << endl;
		cout << "@@@@@ @" << endl;
		cout << "@@@@@@@" << endl;
		break;
	case 3:
		cout << "@@@@@@@" << endl;
		cout << "@ @@@@@" << endl;
		cout << "@@@ @@@" << endl;
		cout << "@@@@@ @" << endl;
		cout << "@@@@@@@" << endl;
		break;
	case 4:
		cout << "@@@@@@@" << endl;
		cout << "@ @@@ @" << endl;
		cout << "@@@@@@@" << endl;
		cout << "@ @@@ @" << endl;
		cout << "@@@@@@@" << endl;
		break;
	case 5:
		cout << "@@@@@@@" << endl;
		cout << "@ @@@ @" << endl;
		cout << "@@@ @@@" << endl;
		cout << "@ @@@ @" << endl;
		cout << "@@@@@@@" << endl;
		break;
	case 6:
		cout << "@@@@@@@" << endl;
		cout << "@ @@@ @" << endl;
		cout << "@ @@@ @" << endl;
		cout << "@ @@@ @" << endl;
		cout << "@@@@@@@" << endl;
		break;
	default:
		break;
	}
}

void PrintScore(unsigned int ScoreComp, unsigned int ScorePlayer)
{
	cout << "------------------------------------------" << endl;
	cout << "|      COMPUTER      |       PLAYER      |" << endl;
	cout << '|' << setw(11) << ScoreComp << setw(10) << '|' << setw(11) << ScorePlayer << setw(9) << '|' << endl;
	cout << "------------------------------------------" << endl;
}
