#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int ram, n;
    cout << "enter ram size : \n";
    cin >> ram;
    cout << "enter the number of process : \n";
    cin >> n;
    int processes[n];
    cout << "enter the size of each process\n";
    for (int i = 0; i < n; i++)
    {
        cin >> processes[i];
    }
    cout << "Given ram size : " << ram << endl;

    vector<int> allocate(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (ram <= 0)
        {
            break;
        }
        if (ram < processes[i])
        {
            continue;
        }
        allocate[i] = 1;
        // cout << "Process no.\tProcess size\tBlock size" << endl;
        // out << "P" << i + 1 << "\t" <<processes[i]<< "\t" <<processes[i]<< endl;
        ram = ram - processes[i];
    }
    cout << "Process no.\tProcess size\tBlock size" << endl;
    for (int i = 0; i < n; i++)
    {
        if (allocate[i] == 1)
        {
            cout << "P" << i + 1 << "\t\t" << processes[i] << "\t\t" << processes[i] << "\n";
        }

        else if (allocate[i] == -1)
        {
            cout << "P" << i + 1 << "\t\t" << processes[i] << "\t\tNot allocated\n";
        }
    }

    cout << "Rest size of ram: " << ram << endl;
    return 0;
}
