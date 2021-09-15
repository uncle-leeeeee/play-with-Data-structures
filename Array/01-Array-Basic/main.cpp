#include <iostream>
using namespace std;

int main()
{
    int *arr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }

    int scores[] = {100, 99, 66};
    for (int k = 0; k < (int)(sizeof(scores) / sizeof(scores[0])); k++)
    {
        cout << scores[k] << " ";
    }
    cout << endl;

    for (int score : scores)
    {
        cout << score << " ";
    }

    return 0;
}