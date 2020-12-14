#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;



void mergeArrays(vector<int>& arr, vector<int>& extra, const int& left, const int& right)
{
	int middle = (left + right) / 2;
	int first = left;
	int second = right;
	int fin = middle + 1;
	int k = 0;
	int j;
	for (j = left; j <= right && (!(first > middle || fin > right)); j++)
	{
		if (arr.at(first) < arr.at(fin))
		{
			extra.at(j) = arr.at(first++);
		}
		else
		{
			extra.at(j) = arr.at(fin++);
		}
	}
	for (; first <= middle; j++)
	{
		extra.at(j) = arr.at(first++);
	}
	for (; fin <= right; j++)
	{
		extra.at(j) = arr.at(fin++);
	}
	for (int j = left; j <= right; j++) arr.at(j) = extra.at(j);

}

void mergeSort2(vector<int>& arr, vector<int>& extra, const int& left, const int& right)
{

	if (left >= right) return;
	int middle = (left + right) / 2;
	mergeSort2(arr, extra, left, middle);
	mergeSort2(arr, extra, middle + 1, right);
	mergeArrays(arr, extra, left, right);
}


vector<int> mergeSort(vector<int> arr)
{
	vector<int> extra(arr.size(), 0);
	mergeSort2(arr, extra, 0, arr.size() - 1);;
	return arr;
}










