
#include <iostream>
#include <time.h>

using namespace std;

void merge(int a[], int low, int mid, int high)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}

void merge_sort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void quick_sort(int a[], int low, int high)
{
    int i, j, pivot, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            while (a[i] <= a[pivot] && i <= high)
            {
                i++;
            }
            while (a[j] > a[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[j];
        a[j] = a[pivot];
        a[pivot] = temp;
        quick_sort(a, low, j - 1);
        quick_sort(a, j + 1, high);
    }
}

void insertion_sort(int a1[], int a2[])
{
    int i, j, temp;
    for (i = 1; i < 100 / 2; i++)
    {
        temp = a1[i];
        j = i - 1;
        while ((temp < a1[j]) && (j >= 0))
        {
            a1[j + 1] = a1[j];
            j = j - 1;
        }
        a1[j + 1] = temp;
    }
    for (i = 1; i < 100 / 2; i++)
    {
        temp = a2[i];
        j = i - 1;
        while ((temp < a2[j]) && (j >= 0))
        {
            a2[j + 1] = a2[j];
            j = j - 1;
        }
        a2[j + 1] = temp;
    }
    for (int i = 0; i < 100 / 2; i++)
    {
        cout << a1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 100 / 2; i++)
    {
        cout << a2[i] << " ";
    }
}

void intsertion_sort(int a[])
{
    int i, j, temp;
    for (i = 1; i < 100; i++)
    {
        temp = a[i];
        j = i - 1;
        while ((temp < a[j]) && (j >= 0))
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
    for (int i = 0; i < 100; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
   int item = time(NULL);

    srand(item);

    int a[100];
    for (int i = 0; i < 100; i++)
    {
        a[i] = rand() % 100;
    }
    int a1[100 / 2];
    int a2[100 / 2];
    for (int i = 0; i < 100 / 2; i++)
    {
        a1[i] = a[i];
    }
    for (int i = 100 / 2; i < 100; i++)
    {
        a2[i] = a[i];
    }
    merge_sort(a1, 0, 100 / 2 - 1);
    quick_sort(a2, 0, 100 / 2 - 1);
    insertion_sort(a1, a2);

    cout << endl;

    int b[100];
    for (int i = 0; i < 100; i++)
    {
        b[i] = rand() % 96 + 4;
    }
    intsertion_sort(b);

    int b1[100];
    for (int i = 0; i < 100; i++)
    {
        b1[i] = rand() % 5 * 20;
    }

    merge_sort(b1, 0, 100 - 1);
    for (int i = 0; i < 100; i++)
    {
        cout << b1[i] << " ";
    }
    cout << endl;
    int b2[100];
    for (int i = 0; i < 100; i++)
    {
        b2[i] = rand() % 60 + 30;
    }
    quick_sort(b2, 0, 100 - 1);
    for (int i = 0; i < 100; i++)
    {
        cout << b2[i] << " ";
    }
    return 0;
}
