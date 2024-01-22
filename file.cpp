#include "file.h"
#include <fstream>
#include <string>


using namespace std;

void File::Save(Game* game)
{
	ofstream fout;
	fout.open(game->GetUserName() + ".txt", ofstream::out);

	vector<Card*> cards = game->GetCards();

	if (fout.is_open())
	{
		fout << game->GetUserBalance() << endl;
		fout << game->GetBank() << endl;
		fout << game->GetRoundsCount() << endl;

		for (int k = 0; k < MAX_CARDS_AMOUNT; k++)
		{
			int** cells = cards[k]->GetCells();

			for (int i = 0; i < ROWS; i++)
				for (int j = 0; j < COLUMNS; j++)
					fout << cells[i][j] << " ";

			fout << endl << cards[k]->IsFilled() << endl;
		}
	}

	fout.close();
}

Game File::Load(std::string nickname)
{
	ifstream fin;
	fin.open(nickname + ".txt");

	ShortCardObject cards[MAX_CARDS_AMOUNT];
	int playerBalance = 0;
	int bank = 0;
	int roundsCount = 0;

	if (fin.is_open())
	{
		fin >> playerBalance;
		fin >> bank;
		fin >> roundsCount;

		for (int i = 0; i < MAX_CARDS_AMOUNT; i++)
		{
			string line;
			getline(fin, line);
			getline(fin, line);
			line.pop_back();
			string delimiter = " ";
			bool isFilled = false;

			size_t pos = 0;
			string token;
			int cells[ROWS * COLUMNS];
			int j = 0;
			while ((pos = line.find(delimiter)) != string::npos)
			{
				token = line.substr(0, pos);
				cells[j] = stoi(token);
				line.erase(0, pos + delimiter.length());
				j++;
			}

			cells[j] = stoi(line);
			fin >> isFilled;

			cards[i] = ShortCardObject(cells, isFilled);
		}
	}

	fin.close();

	return Game(cards, nickname, playerBalance, bank, roundsCount);
}

bool File::IsUserExist(std::string nickname)
{
	ifstream fin;
	fin.open(nickname + ".txt");

	if (fin.is_open())
	{
		fin.close();
		return true;
	}
	else
	{
		fin.close();
		return false;
	}
}

void File::SaveRecord(Record record)
{
	vector<Record> records = GetRecords();

	for (int i = 0; i < records.size(); i++)
	{
		if (records[i].GetName() == record.GetName())
		{
			if (records[i].GetScore() > record.GetScore())
				return;

			records.erase(records.cbegin() + i);
			break;
		}
	}

	records.push_back(record);

	ofstream fout;
	fout.open(RECORDS_FILE_PATH, ofstream::out);

	if (fout.is_open())
	{
		for (int i = 0; i < records.size(); i++)
		{
			fout << records[i].GetName() << " ";
			fout << records[i].GetScore() << " ";
			fout << records[i].GetRoundsPassedAmount() << endl;
		}
	}

	fout.close();
}

std::vector<Record> File::GetRecords()
{
	ifstream fin;
	fin.open(RECORDS_FILE_PATH);

	vector<Record> records;

	if (fin.is_open())
	{
		string line;

		while(getline(fin, line))
		{
			string name;
			int score = 0;
			int roundsPassedAmount = 0;
			string delimiter = " ";

			size_t pos = 0;
			string token;

			int count = 0;

			while ((pos = line.find(delimiter)) != string::npos)
			{
				token = line.substr(0, pos);

				if (count == 0)
					name = token;
				else
					score = stoi(token);

				line.erase(0, pos + delimiter.length());
				count++;
			}

			roundsPassedAmount = stoi(line);

			records.push_back(Record(name, score, roundsPassedAmount));
		}
	}

	fin.close();

	return records;
}
