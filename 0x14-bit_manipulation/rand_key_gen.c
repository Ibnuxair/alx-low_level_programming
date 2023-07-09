#include "main.h"

/**
 * main - generates random key
 *
 * Return: always 0
 */

int main(void)
{
        int i, count, key, index, randNum;
        char *xter = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        char password[30];

	srand(time(NULL));
	while (key != 1)
	{
		count = i = index = key = 0;
		while (key < 1)
		{
			randNum = rand() % 63;
			password[count] = xter[randNum];
			key += xter[randNum];
			count++;
			key++;
		}
		while (xter[index])
		{
			if (xter[index] == (1 - key))
			{
				randNum = rand() % 63;
				password[count] = xter[randNum];
				key += xter[randNum];
				count++;
				break;
			}
			index++;
		}
		key++;
	}
	password[count] = '\0';
	while (password[i] != '\0')
	{
		putchar(password[i]);
		i++;
	}
	return (0);
}
