#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <windows.h>
using namespace std;
#define N 10
#define YES 1
#define NO 0
void free(char rus[N][20], char eng[N][20]);
void kontrol(char rus[N][20], char eng[N][20], int cnt[2], unsigned int x);
void rand_mas(char screen[2 * N][20], char rus[N][20], char eng[N][20]);
void observer(char rus[5 * N][20], char eng[5 * N][20]);
int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	char rus[5 * N][20] = { "рыба","цветок","часы","ночь","тетрадь","стол","кружка","клавиатура","небо","экран","город","улица","машина","процессор","письмо","столица","сладости","табуретка","розетка","переключатель","рыба2","цветок","часы","ночь","тетрадь","стол","кружка","клавиатура","небо","экран","рыба3","цветок","часы","ночь","тетрадь","стол","кружка","клавиатура","небо","экран","рыба4","цветок","часы","ночь","тетрадь","стол","кружка","клавиатура","небо","экран" };
	char eng[5 * N][20] = { "fish","flower","watch","night","notebook","table","mug","keyboard","sky","screen","city","street","car","processor","letter","capital","sweets","stool","socket","switch","fish2","flower2","watch2","night2","notebook2","table2","mug2","keyboard2","sky2","screen2","fish3","flower3","watch3","night3","notebook3","table3","mug3","keyboard3","sky3","screen3","fish4","flower4","watch4","night4","notebook4","table4","mug4","keyboard4","sky4","screen4" };

	int menu = 0;
	while (menu != 5)
	{
		system("cls");
		cout << "Меню\n  1: Свободный режим\n  2: Контроль\n  5: Выход" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
			free(rus, eng);
			break;
		case 2:
			observer(rus, eng);
			break;
		}
	}

	return 0;
}

void free(char rus[N][20], char eng[N][20])
{
	int first, second;
	int k;
	int flag = NO; // флаг сходства
	int score = 0;
	char screen[2 * N][20];
	rand_mas(screen, rus, eng);
	while (score != N)
	{
		
		while (flag ==  NO)
		{
			system("cls");
			cout << "\n Вам представлены два столбца с русскими и английскими\n значениями. Требуется выбрать слово из первого столбца\n и ввести номер слова, являющеся его значением\n на другом языке.\n" << endl;

			for (int i = 0; i < N; ++i)
			{
				cout << " | ";
				cout.setf(ios::left);
				cout.width(2);
				cout << i + 1 << ". ";
				cout.width(20);
				cout << screen[i];
				cout.width(2);
				cout << i + N+1 << ". ";
				cout.width(20);
				cout << screen[i + N] << endl;
			}
			cout << "Введите номер первого столбца: ";
			cin >> first;
			--first;
			cout << "Введите номер второго столбца: ";
			cin >> second;
			--second;
			if ((second > 2*N-1 || second < N) || (first > N-1 || first < 0))
			{
				--score;
				break;
			}
			for (k = 0; k < N; ++k)
			{
				if (strcmp(rus[k], screen[first]) == 0)
					break;
			}
			if (strcmp(eng[k], screen[second]) == 0)
			{
				strcpy(screen[first], "");
				strcpy(screen[second], "");
				break;
			}
		}
		++score;
	}
	return;
}

void observer(char rus[5 * N][20], char eng[5 * N][20])
{
	unsigned int startTime, endTime;
	int cnt[2] = {0,0};
	startTime = clock();
	char rus1[N][20], eng1[N][20];
	for (int i = 0, j = 0, k; i < 5; ++i)
	{
		for (k = 0; k < N; ++j, ++k)
		{
			strcpy(rus1[k], rus[j]);
			strcpy(eng1[k], eng[j]);
		}
		kontrol(rus1,eng1,cnt, startTime);
	}
	endTime = clock();

	ofstream file;
	file.open("res.txt", ios_base::app); // запись в конец файла
	file << " Количество пар слов: " << cnt[1] << " Затраченное время (в сек): " << (endTime-startTime)/1000.0 << "\n Правильные, неправильные ответы: " << cnt[1] << " " << cnt[0] << " Процент ошибок: " << 100*cnt[0]/(cnt[0]+cnt[1]) << "%\n Среднее время на ответ (в сек): " << (endTime - startTime) / 1000.0/(cnt[0]+cnt[1]) << endl;
	file.close();
	return;
}

void kontrol(char rus[N][20], char eng[N][20], int cnt[2], unsigned int x)
{
	unsigned int time;
	int error = 0, ok = 0;
	int first, second;
	int k;
	int flag = NO; // флаг сходства
	int score = 0;
	char screen[2 * N][20];
	rand_mas(screen, rus, eng);
	while (score != N)
	{
		while (flag == NO)
		{
			system("cls");
			time = clock();
			if (time - x > 120000)
			{
				cnt[0] += error;
				cnt[1] += ok;
				return;
			}
			cout << "\n Вам представлены два столбца с русскими и английскими\n значениями. Требуется выбрать слово из первого столбца\n и ввести номер слова, являющеся его значением\n на другом языке.\n Введено ограничение по времени (2 минуты)\n" << endl;

			for (int i = 0; i < N; ++i)
			{
				cout << " | ";
				cout.setf(ios::left);
				cout.width(2);
				cout << i + 1 << ". ";
				cout.width(20);
				cout << screen[i];
				cout.width(2);
				cout << i + N + 1 << ". ";
				cout.width(20);
				cout << screen[i + N] << endl;
			}
			cout << "Введите номер первого столбца: ";
			cin >> first;
			--first;
			cout << "Введите номер второго столбца: ";
			cin >> second;
			--second;
			if ((second > 2 * N - 1 || second < N) || (first > N - 1 || first < 0))
			{
				--score;
				++error;
				--ok;
				break;
			}
			for (k = 0; k < N; ++k)
			{
				if (strcmp(rus[k], screen[first]) == 0)
					break;
			}
			if (strcmp(eng[k], screen[second]) == 0)
			{
				strcpy(screen[first], "");
				strcpy(screen[second], "");
				break;
			}
			++error;
		}
		++ok;
		++score;
	}
	cnt[0] += error;
	cnt[1] += ok;
	return;
}

void rand_mas(char screen[2 * N][20], char rus[N][20], char eng[N][20])
{
	srand(time(NULL));
	int num; // = rand() % 10;
	int num_m[2 * N];
	for (int i = 0; i < 2 * N;)
	{
		for (; i < N; ++i) //rus
		{
			num = rand() % 10;
			for (int j = 0; j < i; ++j)
			{
				if (num == num_m[j])
				{
					num = rand() % 10;
					j = -1;
				}
			}
			num_m[i] = num;
			strcpy(screen[i], rus[num]);
		}
		for (; i < 2 * N; ++i)
		{
			num = rand() % 10;
			for (int j = 10; j < i; ++j)
			{
				if (num == num_m[j])
				{
					num = rand() % 10;
					j = 9;
				}
			}
			num_m[i] = num;
			strcpy(screen[i], eng[num]);
		}
	}
	return;
}