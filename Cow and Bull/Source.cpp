#include<iostream>
#include<ctime>

using namespace std;

void random_number(int number[], int size)
{
	int temp;
	int x;
	int array[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	srand(time(0));

	temp = rand() % 9;
	number[0] = array[temp];
	array[temp] = array[9];

	int j = 9;

	for (int i = 1; i < size; i++)
	{
		temp = rand() % j;
		number[i] = array[temp];
		array[temp] = array[j - 1];
		j--;
	}

	/*
	cout << "--------------------" << endl;
	for (int i = 0; i < 4; i++)
	{
	cout << number[i];
	}

	cout << "\n---------------------" << endl;
	*/
}

int check(int number, int array[], int size)
{
	bool flag = 0;//flag=0 --- all right; 
	int temp, x = number;
	if (number < 1000 || number>9999)
	{
		cout << "\t-=INVALID=-" << endl;;
		flag++;
		return flag;
	}
	for (int i = 0, k = 3; i < size, k >= 0; k--, i++)
	{
		temp = x / pow(10, k);
		array[i] = temp;
		x = x - temp*pow(10, k);

	}


	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (array[i] == array[j])
			{
				cout << "\t-=INVALID=-" << endl;
				flag++;
				break;
			}
		}
		if (flag == 1)
			break;
	}

	return flag;
}

void input(int number, int array[], int size)
{
	int x;
	bool flag = 0;
	do
	{
		cout << "Enter the number" << endl;
		cin >> number;
		x = check(number, array, size);
		if (x == 0)
			flag++;
	} while (flag == 0);


}

int main()
{
	
	int bull = 0, cow = 0, num = 0;
	const int size = 4;
	int computer_num[size], user_num[size];

	int choice;

	random_number(computer_num, size);

	cout << " - = Bull and Cow = -" << endl;

	do
	{
		input(num, user_num, size);

		bull = 0;
		cow = 0;

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (computer_num[i] == user_num[j])
				{
					if (i == j)
						bull++;
					else
						cow++;
				}

			}
		}

		cout << "BULLS: " << bull << "\tCOWS: " << cow << endl;

	} while (bull != 4);
	cout << "\t-=CONGRATULATIONS=-" << endl << endl;

	system("pause");
	return 0;
}