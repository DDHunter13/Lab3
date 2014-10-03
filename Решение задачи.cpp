#include <iostream>
#include <math.h>
#include <locale.h>
#include <iomanip>
using namespace std;

int main(void) {
	setlocale(LC_ALL, "Russian");
	cout << left;

	int const n = 10;
	int const n2 = n / 2;
	double B[n2], C[n2], A[n];
	int i, j, i1, j2, k, err;
	double m1, m2, r, d;
	int D[n];

	for (i = 0; i < n; ++i) {
		D[i] = 0;
	}

	cout << "Введите " <<n<< " элементов массива" << endl;
	for (int i = 0; i < n; ++i) {
		err = scanf_s("%lf", &d);
		if (err != 1) {
			cout << "Введенны неверные данные" << endl;
			return -1;
		}
		A[i] = d;
	}

	for (k = 0; k < n / 2; ++k) {
		for (i = 0; i < n; ++i) {
			for (j = i + 1; j < n; ++j) {
				if ((D[i] == 0) && (D[j] == 0)) {
					r = abs(A[i] - A[j]);
					m1 = A[i];
					i1 = i;
					m2 = A[j];
					j2 = j;
					goto l1;
				}
			}
		}
		l1:
		for (i; i < n; ++i){
			for (j = i + 1; j < n; ++j){
				if ((D[i] == 0) && (D[j] == 0)) {
					if (r > abs(A[i] - A[j])) {
						r = abs(A[i] - A[j]);
						m1 = A[i];
						i1 = i;
						m2 = A[j];
						j2 = j;
					}
				}
			}
		}
		if (m1 > m2) {
			swap(m1, m2);
		}
		r = 0;
		D[i1] = 1;
		D[j2] = 1;
		B[k] = m1;
		C[k] = m2;
	}

	for (i = 0; i < n2; ++i){
		cout << B[i] << " " ;
	}
	cout << endl;
	for (i = 0; i < n2; ++i){
		cout << C[i] << " " ;
	}

	return 0;
}
