#include <iostream>

using namespace std;

double P0(int K, int N);	//iter
double P1(const int K,const int N, const int i);	//rec up ++
double P2(const int K,const int N, const int i);	//rec up --
double P3(const int K,const int N, const int i, double t);	//rec down ++
double P4(const int K,const int N, const int i, double t);	//rec down --
int main() {
	int i, K, N;
	double p0, p1, p2, p3=1, p4=1 ,t = 1;
	cout << "K = ";cin >> K;
	cout << "N = ";cin >> N;
	i = K;
	p0 = P0(K, N);
	p1 = P1(K, N, K);
	p2 = P2(K, N, N);
	p3 = P3(K, N, K, t);
	p4 = P4(K, N, N, t);
	
	cout << "iter = " << p0 << endl;
	cout << "rec up ++ = " << p1 << endl;
	cout << "rec up -- = " << p2 << endl;
	cout << "rec down ++ = " << p3 << endl;
	cout << "rec down -- = " << p4 << endl;


	return 0;
}

double P0(int K, int N) {	//iter
	double R, p;
	int i = K;
	p = 1;
	for (i; i <= N; i++) {
		R = ((K * 1.0 / i) + (i * 1.0 / N));
		p *= R;
	}

	return p;
}
double P1(const int K, const int N, const int i) {	//rec up ++

	if (i > N)
		return 1;

	return ((K * 1.0 / i) + (i * 1.0 / N)) * P1(K, N, i + 1);
}
double P2(const int K, const int N, const int i) {	//rec up --

	if (i < K)
		return 1;

	return ((K * 1.0 / i) + (i * 1.0 / N)) * P2(K, N, i - 1);
}
double P3(const int K, const int N, const int i, double t) {	//rec down ++
	t = t * ((K * 1.0 / i) + (i * 1.0 / N));
	if (i >= N)
		return t;
	return P3(K, N, i + 1, t);
}
double P4(const int K, const int N, const int i, double t) {	//rec down --
	t = t * ((K * 1.0 / i) + (i * 1.0 / N));
	if (i <= K)
		return t;

	return P4(K, N, i - 1, t);
}