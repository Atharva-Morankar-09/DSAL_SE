
// C++ program to implement Shortest Remaining Time First
// Shortest Remaining Time First (SRTF)

#include <bits/stdc++.h>
using namespace std;

void findWaitingTime(vector<int>& bt, vector<int>& at, int n,
								vector<int>& wt)
{
	vector<int> rt = bt;

	int complete = 0, t = 0, minm = INT_MAX;
	int shortest = 0, finish_time;
	bool check = false;

	while (complete != n) {

		for (int j = 0; j < n; j++) {
			if ((at[j] <= t) &&
			(rt[j] < minm) && rt[j] > 0) {
				minm = rt[j];
				shortest = j;
				check = true;
			}
		}

		if (check == false) {
			t++;
			continue;
		}

		rt[shortest]--;
		minm = rt[shortest];

		if (minm == 0)
			minm = INT_MAX;

		if (rt[shortest] == 0) {
			complete++;
			check = false;
			finish_time = t + 1;
			wt[shortest] = finish_time -
						bt[shortest] -
						at[shortest];

			if (wt[shortest] < 0)
				wt[shortest] = 0;
		}
		t++;
	}
}

void findTurnAroundTime(vector<int>& bt, vector<int>& at, int n,
						vector<int>& wt, vector<int>& tat)
{
	for (int i = 0; i < n; i++)
		tat[i] = bt[i] + wt[i];
}

void findavgTime(vector<int>& bt, vector<int>& at, int n)
{
	vector<int> wt(n), tat(n);
    int total_wt = 0, total_tat = 0;

	findWaitingTime(bt, at, n, wt);

	findTurnAroundTime(bt, at, n, wt, tat);

	cout << " P\t\t"
		<< "BT\t\t"
		<< "WT\t\t"
		<< "TAT\t\t\n";


	for (int i = 0; i < n; i++) {
		total_wt+= wt[i];
		total_tat+= tat[i];
		cout << " " << i + 1<< "\t\t"
			<< bt[i] << "\t\t " << wt[i]
			<< "\t\t " << tat[i] << endl;
	}

	cout << "\nAverage waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
}

// Driver code
int main()
{
	int n;
    cout<<"Enter total number of process - ";
    cin>>n;
    
    vector<int> bt{6, 2, 8, 3, 4};
    vector<int> at{2, 5, 1, 0, 4};

	findavgTime(bt, at, n);
	return 0;
}
