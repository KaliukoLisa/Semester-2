//CHECKING
//       1VARIANT
//SIZE - 8
//START ARRAY - 20 33 87 91 2 74 95 12
//ARR FROM NEXT OF KRAT MIN PO VOZR - 33 74 95
//ARR FROM NOT KRAT MIN - 33 87 91 95
//
//      2 VARIANT
//SIZE - 11
//START ARRAY -44 3 21 7 5 74 90 99 37 24 6
//ARR FROM NEXT OF KRAT MIN PO VOZR - 6 7 21 37 99
//ARR FROM NOT KRAT MIN -44 7 5 74 37
//
//      3 VARIANT
//SIZE - 6
//START ARRAY - 104 238 21 8 5 2
//ARR FROM NEXT OF KRAT MIN PO VOZR - 5 21 238
//ARR FROM NOT KRAT MIN - 21 5
#include <iostream>

using namespace std;

void clearscr();
int *InitArray(int n);
void DisplayArray(int *a, int n);
int FindKrat(int *a, int n, int *newarr, int *delarr);
void Sort (int *newarr, int t);

int t = 0;
int f = 0;

int main()
{
    cout << "Please, enter a size of your array" << endl;
    int n;
    cin >> n;
    clearscr();
    int *myarr = InitArray(n);
    clearscr();
    cout << "Your array: ";
    DisplayArray(myarr, n);
    cout << endl;
    clearscr();

    int* newarr=new int[n];
    int* delarr=new int[n];
    FindKrat(myarr, n, newarr, delarr);
    //for(int i=0; i<t; i++)
        //cout << newarr[i] << " ";
    //cout << endl;
    Sort (newarr, t);
    cout << "New Array 1: ";
    for(int i=0; i<t; i++)
        cout << newarr[i] << " ";
    cout << endl;

    cout << "New Array 2: ";
    for(int i=0; i<f; i++)
        cout << delarr[i] << " ";
    cout << endl;
    return 0;
}

void clearscr()
{
    for(int i=0; i<30; ++i)
    cout << "" << endl;
}

int *InitArray(int n)
{
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i+1 << "'s number" << endl;
        int b;
        cin >> b;
        a[i] = b;
    }
    return a;
}

void DisplayArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    cout << a[i] << " ";
}

int FindKrat(int *a, int n, int *newarr, int *delarr)
{
    int mini=a[0];
    for(int i=1; i<n; i++)
    {
        if (a[i] < mini)
        mini = a[i];
    }
for(int i=0; i < n-1; i++)
    {
        if(a[i]%mini==0)
            newarr[t++] = a[i+1];   //kratno min number - Arr 1
        else
            delarr[f++] = a[i];     //not kratno min number - Arr 2
    }
    return 0;
}

void Sort (int *newarr, int t)
{
int temp;
for (int i = 0; i < t - 1; i++)
    {
        for (int j = 0; j < t - i - 1; j++)
        {
            if (newarr[j] > newarr[j + 1])
            {
                temp = newarr[j];
                newarr[j] = newarr[j + 1];
                newarr[j + 1] = temp;
            }
        }
    }
}

