#pragma once

#include <functional>

using namespace std;

template <typename  T1>
inline void print_vector(vector<T1>& vector)
{
	for_each(vector.begin(), vector.end(), [](T1 value) {
		cout << value << " ";
	});

	cout << endl;
}

template <typename  T1>
inline void fill_vector(vector<T1>& vector, int count, function<T1()> generator)
{
	vector.clear();
	vector.resize(count);

	generate(vector.begin(), vector.end(), generator);
}

inline int rand_int()
{
	return rand() % 99 - 50;
}

inline int rand_bool()
{
	return rand() % 2 == 0 ? true : false;
}