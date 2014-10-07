#include <iostream>
#include <math.h>
#include <locale.h>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(void) {
	setlocale(LC_ALL, "Russian");
	cout << left;

	int const n = 10;
	int const n2 = n / 2;
	double B[n2], C[n2], A[n];
	int i, i1, k, err;
	double r, d;
	int D[n];

	for (i = 0; i < n; ++i) {
		D[i] = 0;
	}

	cout << "Введите " << n << " элементов массива" << endl;
	for (i = 0; i < n; ++i) {
		err = scanf_s("%lf", &d);
		if (err != 1) {
			cout << "Введенны неверные данные" << endl;
			return -1;
		}
		A[i] = d;
	}

	sort(A, A + 10);
	cout << endl;

	for (k = 0; k < n2; ++k) {
		for (i = 0; i < n - 1; ++i) {
			if ((D[i] == 0) && (D[i + 1] == 0)) {
				r = abs(A[i] - A[i + 1]);
				i1 = i;
				break;
			}
		}
		for (i; i < n - 1; ++i) {
			if ((D[i] == 0) && (D[i + 1] == 0)) {
				if (r > abs(A[i] - A[i + 1])) {
					r = abs(A[i] - A[i + 1]);
					i1 = i;
				}
			}
		}
		D[i1] = 1;
		D[i1 + 1] = 1;
		B[k] = A[i1];
		C[k] = A[i1 + 1];

	}

	for (i = 0; i < n2; ++i){
		cout << B[i] << " ";
	}
	cout << endl;
	for (i = 0; i < n2; ++i){
		cout << C[i] << " ";
	}

	return 0;
}
