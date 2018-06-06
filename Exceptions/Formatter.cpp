#include "MyArrayIndexOutOfRangeException.h"
#include "MyStringIndexOutOfRangeException.h"
#include "Formatter.h"

string Formatter::FormateString(
	string resultString,
	vector<int> indexes,
	vector<int> values)
{
	try
	{
		CheckCountOfCollectionElements(indexes, values);
		CheckString(resultString, indexes);
		
		if (resultString.length() == 0)
		{
			throw MyArrayException("String is empty");
		}

		if (indexes.size() == 0)
		{
			throw "";
		}
	}
	catch (MyArrayIndexOutOfRangeException exception)
	{
		cout << exception.what() << endl;
	}
	catch (MyStringIndexOutOfRangeException exception)
	{
		cout << exception.what() << endl;
	}
	catch (MyArrayException exception)
	{
		cout << exception.what() << endl;
	}
	catch (...)
	{
		cout << "Some error happened" << endl;
	}

	return string("");
}

void Formatter::CheckCountOfCollectionElements(
	vector<int> firsCollection,
	vector<int> secondCollection)
{
	try
	{
		int firsCollectionCount = firsCollection.size();
		int secondCollectionCount = secondCollection.size();

		if (firsCollectionCount != secondCollectionCount)
		{
			throw (firsCollectionCount - secondCollectionCount);
		}
	}
	catch (int differents)
	{
		char buffer[100];
		sprintf_s(buffer, "%d", differents);

		throw MyArrayIndexOutOfRangeException(string(buffer));
	}
}

void Formatter::CheckString(
	string resultString,
	vector<int> indexes)
{
	int stringLength = resultString.length();
	
	for each (int i in indexes)
	{
		if (i >= stringLength)
		{
			throw MyStringIndexOutOfRangeException(resultString);
		}
	}
}