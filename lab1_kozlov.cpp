#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void mc(fstream& arr); //создание "неизвестного" массива 
void mw(fstream& arr); //обработка массива
void msort(int* A, int N); //сортировка от большего к меньшему

void m2c(int* A, int N); //создание массива cо случайными элементами в промежуьке от а до b
void m2w(int* A, int N); //работа со вторым массивом

void output(int* A, int N); //вывод
void input(int* A, int N, fstream& arr); //ввод массива из файла

int main() {

	setlocale(LC_ALL, "Russian");

	fstream s1;
	s1.open("C:/Users/dadaya/Desktop/laba/randord.txt", ios::out);
	s1.close();
	fstream s2;
	s2.open("C:/Users/dadaya/Desktop/laba/randord2.txt", ios::out);
	s2.close();


	int number;
	cout << "1 - первое задание\n" << "2 - второе задание\n" << "0 - завершить работу\n" << "Введите число: ";
	cin >> number;
	while (number) {
		if (number == 1) {
			fstream arr;
			arr.open("C:/Users/dadaya/Desktop/laba/randord.txt");
			mc(arr);
			mw(arr);
			arr.close();
		}
		if (number == 2) {
			int N = rand() % 1000 + 100;
			int* A = new int[N];
			m2c(A, N);
			m2w(A, N);
		}
		cout << "1 - первое задание\n" << "2 - второе задание\n" << "0 - завершить работу\n" << "Введите число: ";
		cin >> number;
	}
	return 0;
}

void mc(fstream& arr) {
	int N = rand() % 1000 + 100;
	for (int i = 0; i <= N; i++)
		arr << rand() % N << endl;
}

void mw(fstream& arr) {

	fstream clear;
	clear.open("C:/Users/dadaya/Desktop/laba/randord_final.txt", ios::out);
	clear.close();

	fstream f_arr;
	f_arr.open("C:/Users/dadaya/Desktop/laba/randord_final.txt");

	int k, max_num = 0, LINE;
	arr.seekg(0);
	while (arr >> LINE) { 
		if (LINE % 2 == 0) {
			f_arr << LINE << endl;
			max_num++;
		}
	}
	int* A = new int(max_num);
	input(A, max_num, f_arr);
	f_arr.close();
	msort(A, max_num);
	output(A, max_num);
}

void msort(int* A, int N) {
	for (int i = 1; i <= N; i++) {
		for (int j = i - 1; j > 0; j--) if (A[j] < A[j - 1]) { 
			A[j] = A[j] + A[j - 1];
			A[j - 1] = A[j] - A[j - 1];
			A[j] = A[j] - A[j - 1];
		}
	}
}

void output(int* A, int N) {
	for (int i = 0; i < N; i++) {
		cout << "Элемент: " << A[i] << "\tИндекс элемента: " << i << endl;

	}
}

void input(int* A, int N, fstream& arr) {
	arr.seekg(0);
	for (int i = 0; i < N; i++)
		arr >> A[i];
}

void m2c(int* A, int N) {
	int a, b;
	cout << "Введите a: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;
	for (int i = 0; i <= N; i++)
		A[i] = rand() % b + a;
}

void m2w(int* A, int N) {
	fstream r2;
	r2.open("C:/Users/dadaya/Desktop/laba/randord2.txt");
	int numplus = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] % 2 == 0) {
			r2 << A[i] << endl;
			numplus++;
		}
	}

	int* B = new int(numplus);
	input(B, numplus, r2);
	r2.close();
	output(B, numplus);
}