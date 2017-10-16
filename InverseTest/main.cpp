#include<iostream>

using namespace std;

uint64_t inverse(const uint64_t _value, const uint64_t _mod)
{
	uint64_t n = _value, m = _mod, a = 1, b = 0, c = 0, d = 1;

	if (n >= m)
	{
		n %= m;
	}

	bool evenStep = true;

	while ((n != 1) && (m != 1))
	{
		if (evenStep)
		{
			uint64_t k = m / n;
			m %= n;
			a += c*k;
			b += d*k;
		}
		else
		{
			uint64_t k = n / m;
			n %= m;
			c += a*k;
			d += b*k;
		}

		evenStep = !evenStep;
	}

	return (evenStep ? d : _mod - b);

}

int main()
{
	uint64_t n, m;

	cin >> m;
	cin >> n;

	uint64_t result = inverse(n, m);

	cout << result << endl;

	cout << (n * result) % m << endl;

	system("pause");
}