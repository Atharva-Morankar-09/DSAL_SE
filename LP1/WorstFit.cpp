
#include<bits/stdc++.h>
using namespace std;

void worstFit(vector<int>& block, int bs, vector<int>& process, int ps)
{
    vector<int> alloc(ps,-1);

    for(int i=0;i<ps;i++)
    {
        int worstIdx = -1;
        for(int j=0;j<bs;j++)
        {
            if(block[j]>=process[i])
            {
                if(worstIdx==-1)
                {
                    worstIdx = j;
                }
                else if(block[worstIdx] < block[j])
                {
                    worstIdx = j;    
                }
            }
        }

        if(worstIdx!=-1)
        {
            alloc[i]=worstIdx;
            block[worstIdx]-=process[i];
        }
    }

    cout<<"\n Process No. \t Process Size \t Block Stored in"<<endl;
    for(int i=0;i<ps;i++)
    {
        cout<<i+1<<"\t\t"<<process[i]<<"\t\t";
        if(alloc[i]!=-1)
        {
            cout<<alloc[i]+1<<endl;
        }
        else
        {
            cout<<"Not Allocated"<<endl;
        }
    }
}

int main()
{
    int bs,ps;
    cout<<"Enter block size - ";
    cin>>bs;
    vector<int> block(bs);
    cout<<"Enter blocks -"<<endl;
    for(int i=0;i<bs;i++)
    {
        cin>>block[i];
    }

    cout<<"Enter Total Process - ";
    cin>>ps;
    vector<int> process(ps);
    cout<<"Enter Processes -"<<endl;
    for(int i=0;i<ps;i++)
    {
        cin>>process[i];
    }

    worstFit(block, bs, process, ps);
    return 0;
}