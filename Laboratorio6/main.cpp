// Laboratorio6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;

vector<double> manipulate_vector(const vector<double>& input_vector);
list<double> manipulate_list(const list<double>& input_list);

int main()
{
	vector<double> v = {0, 1, 2, 3, 4, 5, 6, 7, 11, 8, 9, 10};
	vector<double> manV = manipulate_vector(v);

	for (int i = 0; i < manV.size(); i++)
	{
		cout << manV[i] << " ";
	}

	cout << endl;

	list<double> l = { 0, 1, 2, 3, 4, 5, 6, 7, 11, 8, 9, 10 };
	list<double> manL = manipulate_list(l);

	auto cursor = manL.begin();
	while(cursor != manL.end())
	{
		cout << *(cursor++) << " ";
	}
}

/*
1.Scrivete   una   funzione   manipulate_vector   che   accetta   in   input   un
vector<double>input_vector e restituisce un vector<double> contenente la concatenazione dei seguentielementi:
*/
bool isPositive(double num) { return (num >= 0); }
bool isNegative(double num) { return (num <  0); }

vector<double> manipulate_vector(const vector<double>& input_vector)
{
	//1.input_vector ordinato con l’algoritmo STL sort;
	vector<double> sortedVector = input_vector;
	sort(sortedVector.begin(), sortedVector.end());

	//2.input_vector con gli elementi invertiti con l’algoritmo reverse;
	vector<double> reversedVector = input_vector;
	reverse(reversedVector.begin(), reversedVector.end());

	//3.la somma degli elementi di input_vector calcolata con l’algoritmo accumulate;
	double accResult = accumulate(input_vector.begin(), input_vector.end(), 0.0);
	
	//4.la somma degli elementi appartenenti alla prima metà di input_vector;
	double halfAccResult = 0;
	int maxIndex = input_vector.size() / 2;
	if (maxIndex >= 0)
	{
		for (int i = 0; i < maxIndex; i++)
		{
			halfAccResult += input_vector[i];
		}
	}
	
	//5.il numero di elementi positivi o nulli,
	//calcolati con count_if (tale numero deve essereconvertito in double per poter essere inserito nel vector ritornato).

	int negativeNumbers = count_if(input_vector.begin(), input_vector.end(), isNegative);
	int positiveNumbers = count_if(input_vector.begin(), input_vector.end(), isPositive);

	sortedVector.insert(sortedVector.end(), reversedVector.begin(), reversedVector.end());
	sortedVector.push_back(accResult);
	sortedVector.push_back(halfAccResult);
	sortedVector.push_back(negativeNumbers);
	sortedVector.push_back(positiveNumbers);

	return sortedVector;
}

list<double> manipulate_list(const list<double>& input_list)
{
	vector<double> tempVector{ input_list.begin(), input_list.end() };
	tempVector = manipulate_vector(tempVector);
	list<double> manipulatedList{ tempVector.begin(), tempVector.end() };

	return manipulatedList;
}