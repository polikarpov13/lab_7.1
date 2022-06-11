#include <iostream> // std::cout
#include <algorithm> // std::generate
#include <vector> // std::vector
#include <ctime> // std::time
#include <numeric> // std::accumulate

using namespace std;

int RandomNumber() { return (std::rand() % 100); }

void print(vector<int> a)
{
	for (int i : a)
		cout << i << " ";
	cout << endl;
}
int main()
{
	srand(unsigned(time(0)));

	int n;
	cout << "n :  "; cin >> n;

	vector<int> v(n);

	generate(v.begin(), v.end(), RandomNumber);

	print(v);

	vector<int> u(v.size());

	int j = 0;
	for (int i = 2; i < v.size(); i+=2) {
		u[j] = v[i];
		j++;
	}

	u.resize(j);
	print(u);
	auto k = u.size();
	auto s = accumulate(u.begin(), u.end(), 0);
	cout << "AVG = " << s * 1. / k << endl;
	return 0;
}