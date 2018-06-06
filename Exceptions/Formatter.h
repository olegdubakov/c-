#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

static class Formatter
{
public:
	static string FormateString(string resultString, vector<int> indexes, vector<int> values);

private:
	static void CheckCountOfCollectionElements(vector<int> firsCollection, vector<int> secondCollection);
	static void	CheckString(string resultString, vector<int> indexes);
};
