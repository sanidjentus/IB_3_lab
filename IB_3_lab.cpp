#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

//проверка на простое число
bool isPrime(int x) {
	for (int i = 2; i < x; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

//проверка на взаимно простые числа
bool isCoprime(int x, int y) {
	for (int i = 2; i < y; i++) {
		if (x % i == 0 && y % i == 0)
			return false;
	}
	return true;
}

//ф-я нахождения длинны массива
int massLength(char mass[]) {
	int i = 0;
	while (mass[i++]);
	return (i - 1);
}


int main() {
	setlocale(LC_ALL, "Russian");
	
	int p = 3, q = 19; //заданы
	int n = p * q;
	int f = (p - 1) * (q - 1);
	int e;
	for (int i = 2; i < f; i++){
		if (isCoprime(i, f) && isPrime(i)) {
			e = i;
			break;
		}
	}
	int d = 0;
	while (true) {
		d++;
		int k = (d * e) % f;
		if (k == 1)
			break;
	}
	
	cout << "n = " << n << endl;
	cout << "f = " << f << endl;
	cout << "e = " << e << endl;
	cout << "d = " << d << endl << endl;

	cout << "Открытый ключ RSA: {e, n} = {" << e << ", " << n << "}" << endl;
	cout << "Закрытый ключ RSA: {d, n} = {" << d << ", " << n << "}" << endl << endl;

	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char word[] = "magic"; //открытое сообщение
	
	int wordNum[100] = { 0 }; //массив индексов букв исходного сообщения
	int wordEncription[100] = { 0 }; //массив индексов букв зашифрованного сообщения
	int wordDecription[100] = { 0 }; //массив индексов букв расшифрованного сообщения

	cout << "Открытое сообщение: " << word << endl;
	cout << "Индексы букв открытого сообщения по порядку: ";
	int k = 0;
	while (k <= massLength(word)) {
		for (int i = 0; i < 25; i++) {
			if (word[k] == alphabet[i]) {
				wordNum[k] = i;
				cout << wordNum[k] << " ";
			}
		}
		k++;
	}
	cout << endl;

	cout << "Индексы букв зашифрованного сообщения по порядку: ";
	for (int i = 0; i < massLength(word); i++) {
		int rem = wordNum[i]; //остаток
		for (int j = 0; j < e - 1; j++) {
			rem = (wordNum[i] * rem) % n;
		}
		wordEncription[i] = rem;
		cout << rem << " ";
	}
	cout << endl;

	cout << "Индексы букв расшифрованного сообщения по порядку: ";
	for (int i = 0; i < massLength(word); i++) {
		int rem = wordEncription[i];
		for (int j = 0; j < d - 1; j++) {
			rem = (wordEncription[i] * rem) % n;
		}
		wordDecription[i] = rem;
		cout << rem << " ";
	}
	cout << endl;

	cout << "Исходное сообщение: ";	
	k = 0;	
	while (k < massLength(word)) {
		cout << alphabet[wordDecription[k]];
		k++;
	}
	cout << endl;
	return 0;
}