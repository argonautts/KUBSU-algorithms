#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int counter = 0, bz = 0;

vector<int> sub_items(const vector<int>& v, const int from, const int to)
{
	return vector<int>(v.begin() + from, v.begin() + to);
}

vector<int> add_trailing_zeros(const vector<int>& a, const int count)
{
	vector<int> res = a;
	for (int i = 0; i < count; ++i) res.insert(res.begin(), 0);
	return res;
}

vector<int> remove_leading_zeros(const vector<int>& a)
{
	vector<int> res = a;
	while (res.size() > 1 && res.back() == 0) res.pop_back();
	return res;
}

vector<int> big_sum(const vector<int>& a, const vector<int>& b)
{
	vector<int> res;
	int carry = 0;
	for (int i = 0; i < max(a.size(), b.size()); ++i)
	{
		if (i < a.size()) carry += a[i];
		if (i < b.size()) carry += b[i];
		res.push_back(carry % bz);
		carry /= bz;
	}
	if (carry > 0) res.push_back(carry);
	return res;
}

vector<int> big_difference(const vector<int>& a, const vector<int>& b)
{
	vector<int> res;
	int carry = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		carry += a[i] - (i < b.size() ? b[i] : 0);
		res.push_back(carry < 0 ? carry + bz : carry);
		carry = carry < 0 ? -1 : 0;
	}
	return remove_leading_zeros(res);
}

vector<int> big_product(const vector<int>& a, const int digit)
{
	vector<int> res;
	int carry = 0;
	for (const int item : a)
	{
		carry += item * digit;
		res.push_back(carry % bz);
		carry /= bz;
	}
	if (carry > 0) res.push_back(carry);
	return remove_leading_zeros(res);
}

vector<int> karats(const vector<int>& a, const vector<int>& b)
{
	if (a.size() == 1) { counter++; return big_product(b, a[0]); }
	if (b.size() == 1) { counter++; return big_product(a, b[0]); }

	const int m = min(a.size() / 2, b.size() / 2);

	const vector<int> a1 = sub_items(a, 0, m);
	const vector<int> a2 = sub_items(a, m, a.size());
	const vector<int> b1 = sub_items(b, 0, m);
	const vector<int> b2 = sub_items(b, m, b.size());

	const vector<int> z0 = karats(a1, b1);
	const vector<int> z1 = karats(big_sum(a1, a2), big_sum(b1, b2));
	const vector<int> z2 = karats(a2, b2);

	const vector<int> step1 = add_trailing_zeros(z2, m * 2);
	const vector<int> step2 = big_difference(z1, big_sum(z0, z2));
	const vector<int> step3 = add_trailing_zeros(step2, m);
	const vector<int> step4 = big_sum(step1, step3);

	return big_sum(step4, z0);
}

vector<int> getVector(int n)
{
	vector<int> res;
	for (int i = 0; i < n; i++) res.push_back(rand() % bz);
	return res;
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "RU");
	cout << "Введите bz:";
	cin >> bz;
	cout << "i " << " " << "counter" << endl;
	for (int i = 1; i <= 100; i++)
	{
		const vector<int> a = getVector(i);
		const vector<int> b = getVector(i);
		const vector<int> res = karats(a, b);
		cout << i << "  " << counter << endl;
		counter = 0;
	}
	return 0;
}
