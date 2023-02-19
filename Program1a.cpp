#include <bits/stdc++.h>
using namespace std;

class process
{
public:
    int p_id;
    int arrival;
    int burst;

    process(){};
    process(int a, int b, int c) : p_id(a), arrival(b), burst(c){};
};

bool compare(process a, process b)
{
    if(a.arrival == b.arrival)
    {
        return a.burst < b.burst;
    }
    return a.arrival < b.arrival;
}

int main()
{
    cout << "-------------FCFS CPU SCHEDULING------------\n";
    int n;
    cout << "Enter the no of processes : " << endl;
    cin >> n;
	
    cout << "Enter the Process ID, Burst Time, and Arrival Time respectively\n";
    vector<process> p;

    int j = n;
    while (j--)
    {
        process temp;
        cin >> temp.p_id;
        cin >> temp.burst;
        cin >> temp.arrival;
        p.push_back(temp);
    }

    // sorting on the basis of arrival
    sort(p.begin(), p.end(), compare);

    int wait = 0;
    int burst = p[0].burst;

    vector<int> waiting;
    waiting.push_back(0);

    for (int i = 1; i < n; i++)
    {
        int w = waiting[i - 1] + p[i - 1].burst;
        waiting.push_back(w);
        wait += w;
        burst += p[i].burst;
    }

    cout<<"\nP_ID    Arrival_Time    Burst_Time     Waiting_Time     Turnaround_Time\n";
    for (int i = 0; i < n; i++)
    {
        cout<<p[i].p_id<<"\t\t"<<p[i].arrival<<"\t    "<<p[i].burst<<"\t\t  "<<waiting[i]<<"\t\t"<<(waiting[i]+p[i].burst)<<endl;
    }

    cout << "\nTotal waiting time : " << wait << endl;
    cout << "Total tunaround time : " << burst + wait << endl;
    cout << "Average waiting time : " << (double)wait / n << endl;
    cout << "Average tunaround time : " << ((double)burst + (double)wait) / n << endl;

    return 0;
}

/* 
1 5 1
2 10 5
3 2 1
4 9 3
5 2 4
*/
