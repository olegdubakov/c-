#include <iostream>
#include <string>
#include <algorithm> 
#include <vector>
#include "Headers.h"
#include <numeric>

using namespace std;

void main()
{
	vector<int> int_vector;

	// for_each
	fill_vector<int>(int_vector, 5, rand_int);

	// generate
	print_vector<int>(int_vector);

	// all_of, any_of, none_of
	cout << endl << "Demo. all_of, any_of, none_of:" << endl;
	if (any_of(int_vector.begin(), int_vector.end(), [](int value) -> bool {
		return (value % 2 == 0); 
	})) 
	{
		cout << "There is value < 0" << endl;
	} 
	else 
	{
		cout << "All values > 0" << endl;
	}

	// find, find_if, find_if_not
	cout << endl << "Demo. find, find_if, find_if_not:" << endl;
	const auto rand_int_1 = rand_int();
	const auto result_1 = find(int_vector.begin(), int_vector.end(), rand_int_1);

	if (result_1 != int_vector.end())
	{
		cout << "int_vector has " << rand_int_1 << endl;
	}
	else
	{
		cout << "int_vector don't have " << rand_int_1 << endl;
	}

	// copy
	cout << endl << "Demo. copy:" << endl;
	vector<int> int_vector_2(int_vector.size());
	copy(int_vector.begin(), int_vector.end(), int_vector_2.begin());
	print_vector(int_vector_2);

	// replace, replace_if
	cout << endl << "Demo. replace, replace_if:" << endl;
	replace_if(int_vector_2.begin(), int_vector_2.end(), [](int value) -> bool {
		return (value % 2 == 0);
	}, 111);
	print_vector(int_vector_2);

	// sort
	cout << endl << "Demo. sort:" << endl;
	cout << "sorted? " << (is_sorted(int_vector_2.begin(), int_vector_2.end()) > 0 ? "true" : "false") << endl;
	sort(int_vector_2.begin(), int_vector_2.end(), [](int l_value, int r_value) -> bool { return l_value < r_value; });
	print_vector(int_vector_2);
	cout << "sorted? " << (is_sorted(int_vector_2.begin(), int_vector_2.end()) > 0 ? "true" : "false") << endl;


	// max_element
	cout << endl << "Demo. max_element, min_element:" << endl;
	print_vector(int_vector);
	auto result_2 = max_element(int_vector.begin(), int_vector.end());
	auto result_3 = min_element(int_vector.begin(), int_vector.end());
	cout << "max: " << *result_2 << endl;
	cout << "min: " << *result_3 << endl;

	// accumulate
	cout << endl << "Demo. accumulate:" << endl;
	auto result_4 = accumulate(int_vector.begin(), int_vector.end(), 0);
	cout << "accumulate: " << result_4 << endl;
}