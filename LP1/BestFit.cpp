
#include<bits/stdc++.h>
using namespace std;
// Function to allocate memory to blocks as per Best fit
// algorithm
void bestFit(vector<int>& block, int bs, vector<int>& process, int ps)
{
    vector<int> allocation(ps, -1);

    for (int i=0; i<ps; i++)
    {

        int bestIdx = -1;
        for (int j=0; j<bs; j++)
        {
            if (block[j] >= process[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if ( block[j] < block[bestIdx])
                    bestIdx = j;
            }
        }

        
        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            block[bestIdx] -= process[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < ps; i++)
    {
        cout << "   " << i+1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main()
{
    int bs, ps;

    cout<<"Enter Block size - ";
    cin>>bs;
    vector<int> block(bs);
    cout<<"Enter values -\n";
    for(int i=0;i<bs;i++){
        cin>>block[i];
    }

    cout<<"Enter Total Processes - ";
    cin>>ps;
    vector<int> process(ps);
    cout<<"Enter values -\n";
    for(int i=0;i<ps;i++){
        cin>>process[i];
    }

    bestFit(block, bs, process, ps);

    return 0 ;
}