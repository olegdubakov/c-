#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

class PairBuilder
{
public:
	template <typename  T1, typename  T2>
	pair<T1, T2> operator() (T1 first, T2 second){
		return pair<T1, T2>(first, second);
	}
};

void main()
{
	// pairs
	PairBuilder pairBuilder;

	auto pair1 = pairBuilder(1, "Pair 01");
	auto pair2 = pairBuilder(2, "Pair 02");
	auto pair3 = make_pair(3, "Pair 03");

	cout << "pair2: " << pair2.first << ", " << pair2.second << endl;
	cout << "pair3: " << pair3.first << ", " << pair3.second << endl << endl;

	// swap
	swap(pair3, pair1);
	cout << "swap pair1: " << pair1.first << ", " << pair1.second << endl;
	cout << "swap pair3: " << pair3.first << ", " << pair3.second << endl << endl;


	// move
	string foo = "foo-string";
	string bar = "bar-string";
	vector<string> myvector;

	cout << "Before " << endl;
	cout << " foo: " << foo.c_str() << endl;
	cout << " bar: " << bar.c_str() << endl;

	foo = move(bar);

	cout << "After 'move' " << endl;
	cout << " foo: " << foo.c_str() << endl;
	cout << " bar: " << bar.c_str() << endl << endl;

}