#include <iostream>
using namespace std;
#define MAXIMUM_RESULT_LENGTH 128
bool IsNumberPrime(int number)
{
	if (number == 1)
		return false;
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}
void Partition(int maxNumber, int change, int counter, int* path)
{
	for (int i = 2; i <= maxNumber; i++)
	{
		if (!IsNumberPrime(i))
		{
			continue;
		}
		if (change - i < 0)
		{
			return;
		}
		if (change - i == 0)
		{
			for (int j = 0; j < counter; j++)
			{
				cout << path[j] << "+";
			}
			cout << i << endl;
			return;
		}
		path[counter] = i;
		Partition(i, change - i, counter + 1, path);
	}
}
int main()
{
	int counter = 0;
	int table_of_n;
	int table_of_k;
	int number_of_lines;
	cin >> number_of_lines;
	while (counter < number_of_lines)
	{
		cin >> table_of_n;
		cin >> table_of_k;
		int result[MAXIMUM_RESULT_LENGTH];
		result[0] = table_of_k;
		if (IsNumberPrime(table_of_k) && table_of_n - table_of_k == 0)
			cout << table_of_k << endl;
		else if (IsNumberPrime(table_of_k))
			Partition(table_of_k, table_of_n - table_of_k, 1, result);
		counter++;
	}
	return (0);
}