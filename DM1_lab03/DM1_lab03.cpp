#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <Windows.h>


using std::cout; using std::cin; using std::endl;
using std::vector; using std::string; using std::bitset; using std::pair;
const int BIT_SIZE = 32;

vector<int> InputSet() {

	int size;
	cout << "Введіть розмір множини: ";
	cin >> size;

	vector<int> set(size);

	cout << "Введіть елементи множини. Приклад: 1 2 3 4 5\n";
	for (size_t i = 0; i < size; i++) {
		cin >> set[i];
	}

	return set;

}

void PrintBinarySet(const string& BinarySet) {

	cout << BinarySet << endl;

}

void PrintSet(const vector<int>& set) {

	cout << "{";

	for (size_t i = 0; i < set.size(); i++) {
		cout << set[i];
		if (i < set.size() - 1) {
			cout << ", ";
		}
	}
	cout << "}" << endl;
}

vector<int> CombineSets(const vector<int>& A, const vector<int>& B) {
	vector<int> result = A;
	for (int i : B) {
		if (find(result.begin(), result.end(), i) == result.end()) {
			result.push_back(i);
		}
	}
	return result;
}

vector<int> CrossSets(const vector<int>& A, const vector<int>& B) {

	vector<int> result;

	for (int i : A) {
		if (find(B.begin(), B.end(), i) != B.end()) {
			result.push_back(i);
		}
	}
	return result;
}

vector<int> DiffSets(const vector<int>& A, const vector<int>& B) {

	vector<int> result;

	for (int i : A) {
		if (find(B.begin(), B.end(), i) == B.end()) {
			result.push_back(i);
		}
	}
	return result;
}

vector<int> ComplementSets(const vector<int>& A, const vector<int>& U) {
	vector<int> result;
	for (const int& element : U) {
		if (find(A.begin(), A.end(), element) == A.end()) {
			result.push_back(element);
		}
	}
	return result;
}

vector<int> SymmDiff(const vector<int>& A, const vector<int>& B) {
	vector<int> result;
	vector<int> diffAB = DiffSets(A, B);
	vector<int> diffBA = DiffSets(B, A);
	result = CombineSets(diffAB, diffBA);
	return result;
}

vector<pair<int, int>> CartesianProduct(const vector<int>& A, const vector<int>& B) {
	vector<pair<int, int>> result;
	for (const int& elementA : A) {
		for (const int& elementB : B) {
			result.push_back(std::make_pair(elementA, elementB));
		}
	}
	return result;
}

string DoBinarySet(const vector<int>& set) {

	

	bitset<BIT_SIZE> BinarySet;

	for (int elem : set) {

		if (elem <= BIT_SIZE) {
			BinarySet.set(elem);
		}
		else {
			cout << "Ваш елемент більший за максимально допустиме значення: " << BIT_SIZE << endl;
		}

	}

	return BinarySet.to_string();
}

vector<int> BinaryToSet(const string& BinarySet) {

	vector<int> set;

	for (size_t i = 0; i < BinarySet.length(); i++) {
		if (BinarySet[i] == '1') {
			set.push_back(i);
		}
	}

	return set;

}

bool isSubset(const vector<int>& A, const vector<int>& B) {

	for (int i : A) {
		if (find(B.begin(), B.end(), i) == B.end()) {
			return false;
		}
	}
	return true;
}

bool isEqual(const vector<int>& A, const vector<int>& B) {
	return A == B;
}



int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	std::cout.setf(std::ios_base::boolalpha);


	vector<int> A = { 7,4,8,3,2 }; //Для довільних значень функція InputSet()
	vector<int> B = { 8,6,3,1,5,2 };
	vector<int> U = { 1,2,3,4,5,6,7,8 };

	string BinaryA = DoBinarySet(A);
	string BinaryB = DoBinarySet(B);

	//Робота усіх функцій
	CombineSets(A, B);
	CrossSets(A, B);
	DiffSets(A, B);
	ComplementSets(A, B);
	SymmDiff(A, B);
	CartesianProduct(A, B);
	isSubset(A, B);
	isEqual(A, B);

	
	PrintSet(A);
	PrintSet(B);

	PrintBinarySet(BinaryA);
	PrintBinarySet(BinaryB);


	//#4
	string CombineResult = (bitset<BIT_SIZE + 1>(BinaryA) | bitset<BIT_SIZE + 1>(BinaryB)).to_string();
	string CrossResult = (bitset<BIT_SIZE + 1>(BinaryA) & bitset<BIT_SIZE + 1>(BinaryB)).to_string();
	string DiffResult = (bitset<BIT_SIZE + 1>(BinaryA) & ~bitset<BIT_SIZE + 1>(BinaryB)).to_string();
	string SymmDiffResult = (bitset<BIT_SIZE + 1>(BinaryA) ^ bitset<BIT_SIZE + 1>(BinaryB)).to_string();
	
	vector<int> ConvertedA = BinaryToSet(BinaryA);
	vector<int> ConvertedB = BinaryToSet(BinaryB);

	cout << isEqual(ConvertedA, A) << endl;
	cout << isEqual(ConvertedB, B) << endl;

}

