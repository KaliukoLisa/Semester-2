#include<iostream>
#include <string.h>

using namespace std;

const int N = 30;
const int M = 30;

class Book
{
public:
	Book()
	{

	}

	void SetTitle(char* c)
	{
		strcpy(title, c);
	}

	void SetSurname(char* c)
	{
		strcpy(surname, c);
	}

	void SetPrimecost(int primecost)
	{
		this->primecost = primecost;
	}
	void SetBenefit(int benefit)
	{
		this->benefit = benefit;
	}

	void SetYearOfIssue(int yearOfIssue)
	{
		this->yearOfIssue = yearOfIssue;
	}

	void SetPrice(int price)
	{
		this->price = price;
	}

	void SetBook(char* c1, char* c2, int d1, int d2, int d3, int d5)
	{
		SetTitle(c1);
		SetSurname(c2);
		SetPrimecost(d1);
		SetBenefit(d2);
		SetYearOfIssue(d3);
		SetPrice(d5);
	}


	char* GetTitile()
	{
		return title;
	}

	char* GetSurname()
	{
		return surname;
	}

	int GetPrimecost()
	{
		return primecost;
	}

	int GetYearOfIssue()
	{
		return yearOfIssue;
	}

	int GetBenefit()
	{
		return benefit;
	}


	int GetPrice()
	{
		return price;
	}

	void DisplayBook()
	{
		cout << endl << title << ",\t" << endl;;
		cout.precision();
		cout << surname << " ,\t" << primecost << " ,\t" << yearOfIssue << " ,\t" << benefit << ",\t" <<  price << " ,\t";
	}

private:
	char title[N], surname[N];
	int primecost, benefit, yearOfIssue, price;
};

Book InitBook();
Book* InitArray(int);
void DisplayArray(Book*, int);
void EnterArray(int*, int);
void SortTitle(Book*, int);
void Swap(Book&, Book&);

int main()
{
	int n;
	cout << "Enter the title of Book:" << endl;
	cin >> n;
	//system("cls");
	Book* books = InitArray(n);
	if (!books)
	{
		cout << "Enter erray!" << endl;
		return 0;
	}

	cout << endl;
	cout << "The list of Books:";
	DisplayArray(books, n);
	cout << endl;
	cout << "The sorting list of Cars:";
	SortTitle(books, n);
	DisplayArray(books, n);
	delete[] books;
	return 0;
}

Book InitBook()
{
	char title[N] = "", surname[N] = "";
	int primecost, benefit, yearOfIssue, price;
	cout << "Enter the title: \n";
	cin.ignore();
	cin.get(title, N, '\n');
	cout << "Enter the surname:\n";
	cin.ignore();
	cin.get(surname, N, '\n');
	cout << "Enter Year Of Issue:\n";
	cin >> yearOfIssue;
	cout << "Enter price:\n";
	cin >> price;
	cout << "Enter primecost:\n";
	cin >> primecost;
	cout << "Enter benefit:\n";
	cin >> benefit;
	cout << endl;

	Book book;
	book.SetBook(title, surname, primecost, benefit, yearOfIssue, price);
	return book;
}

Book* InitArray(int n)
{
	Book* array = new Book[n];
	if (!array)
		return NULL;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the information about " << i + 1 << "'s Book\n" << endl;
		array[i] = InitBook();
	}
	return array;
}

void EnterArray(int* array, int n)
{
	for (int i = 0; i < M; i++)
	{
		cout << "enter A[" << (i + 1) << "] = ";
		cin >> array[i];
	}
}

void DisplayArray(Book* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		array[i].DisplayBook();
	}
	cout << endl;
}

void SortTitle(Book* array, int n)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (strcmp(array[j].GetTitile(), array[j - 1].GetTitile()) < 0)
			{
				Swap(array[j], array[j - 1]);
			}
		}
	}
}

void Swap(Book &a, Book  &b)
{
	Book  t = a;
	a = b;
	b = t;
}
