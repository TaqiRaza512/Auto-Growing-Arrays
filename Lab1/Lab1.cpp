#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;


template<typename T>
class AutoGrowingArray
{
private:
	int size, capacity = 1;
	T* Ds = new T[capacity];

public:
	AutoGrowingArray(int s)
	{
		size = s;

	}
	void PushBack(T value)
	{
		T* HP = new T[size + 1];

		for (int ri = 0; ri < size; ri++)
		{
			HP[ri] = Ds[ri];
		}
		HP[size] = value;
		delete[] Ds;
		Ds = HP;

		size++;
	}
	T operator[](int index)const
	{
		return Ds[index];

	}
	T& operator[](int index)
	{
		return Ds[index];

	}
	friend ostream& operator<<(ostream& out, const AutoGrowingArray& Other)
	{
		cout << "{";
		for (int ri = 0; ri < Other.size; ri++)
		{
			cout << Other.Ds[ri] << " \n ";
		}
		cout << "}";
		return out;
	}
	void GenerateData(string FName)
	{
		srand(time(0));
		ofstream Rdr(FName);
		for (int ri = 0; ri < 0.5*1024*1024; ri++)
		{
			Rdr << rand() % 100 << "\n";
		}
	}
	void LoadFromFile(string FName)
	{
		T VarRead;
		ifstream Rdr(FName);
		while (Rdr)
		{
			Rdr >> VarRead;

			if (Rdr)
			{
				PushBack(VarRead);
			}
		}
	}
	~AutoGrowingArray()
	{

	}
};

template<typename Data>
class Vector
{
private:
	Data size = 0;
	int capacity = 1;
	Data* Ds = new Data[capacity];
public:
	Vector(int s)
	{
		size = s;

	}
	void PushBack(Data Value)
	{

		if (size == capacity)
		{
			capacity *= 2;

			Data* HP = new Data[capacity];

			for (int ri = 0; ri < size; ri++)
			{
				HP[ri] = Ds[ri];
			}
			delete[] Ds;
			Ds = HP;
		}
		Ds[size] = Value;
		size++;
	}
	Data operator[](int index)const
	{
		return Ds[index];

	}
	Data& operator[](int index)
	{
		return Ds[index];

	}
	friend ostream& operator<<(ostream& out, const Vector& Other)
	{
		cout << "{";
		for (int ri = 0; ri < Other.size; ri++)
		{
			cout << Other.Ds[ri] << " \n ";
		}
		cout << "}";
		return out;
	}
	void GenerateData(string FName)
	{
		srand(time(0));
		ofstream Rdr(FName);
		for (int ri = 0; ri <0.5*1024*1024; ri++)
		{
			Rdr << rand() % 10 << "\n";
		}
	}
	void DeletingTheEmpty()
	{
		cout << "\nSize before Shortlisting  : ";

		cout << capacity;

		Data* HP = new Data[size];

		for (int ri = 0; ri < size; ri++)
		{
			HP[ri] = Ds[ri];
			capacity--;
		}
		delete[] Ds;
		Ds = HP;
		cout << "\n Size after ShortListing : ";
		cout << size;

	}
	void LoadFromFile(string FName)
	{
		Data VarRead;
		ifstream Rdr(FName);
		while (Rdr)
		{
			Rdr >> VarRead;

			if (Rdr)
			{

				PushBack(VarRead);

			}
		}

	}
};


template<typename List>
class ArrayList
{
private:
	List size = 0;
	int capacity = 2;
	List* Ds = new List[capacity];

public:
	ArrayList(int s)
	{
		size = s;

	}
	void PushBack(List Value)
	{

		if (size == capacity)
		{
			capacity *= 1.5;

			List* HP = new List[capacity];

			for (int ri = 0; ri < size; ri++)
			{
				HP[ri] = Ds[ri];
			}
			delete[] Ds;
			Ds = HP;
		}
		Ds[size]= Value;
		size++;
	}
	List operator[](int index)const
	{
		return Ds[index];
	}
	List& operator[](int index)
	{
		return Ds[index];

	}
	friend ostream& operator<<(ostream& out, const ArrayList& Other)
	{
		cout << "{";
		for (int ri = 0; ri < Other.size; ri++)
		{
			cout << Other.Ds[ri] << " \n ";
		}
		cout << "}";
		return out;
	}
	void GenerateData(string FName)
	{
		srand(time(0));
		ofstream Rdr(FName);
		for (int ri = 0; ri < 0.5*1024*1024; ri++)
		{
			Rdr << rand() % 10;
		}
	}
	void LoadFromFile(string FName)
	{
		int VarRead;
		ifstream Rdr(FName);
		while (Rdr)
		{
			Rdr >> VarRead;
			if (Rdr)
			{
				PushBack(VarRead);
			}
		}
	}
};

int main()
{
	AutoGrowingArray<int> A(0);
	ArrayList<int>B(0);
	Vector<int>V(0);

	int  opt;
	V.GenerateData("Data.txt");

	cout << "1. For Simple AutoGrowing.\n";
	cout << "2. For a Vector.\n";
	cout << "3. For ArrayList.\n";
	cin >> opt;
	int Prev_Time = time(0);

	switch (opt)
	{

	A.GenerateData("Data.txt");
	case 1:
		A.LoadFromFile("Data.txt");
		break;
	case 2:
		V.LoadFromFile("Data.txt");
		break;

	case 3:
		B.LoadFromFile("Data.txt");
		break;

	default:
		break;
	}
	int After_Time = time(0);

	cout << "\n\nHence the total time taken to compute this program  : " << (After_Time - Prev_Time)<<endl;

}
//for a vector
//1. For Simple AutoGrowing.
//2. For a Vector.
//3. For ArrayList.
//2
//
//
//Hence the total time taken to compute this program  : 4

///for an array list
//1. For Simple AutoGrowing.
//2. For a Vector.
//3. For ArrayList.
//3
//
//
//Hence the total time taken to compute this program  : 5

