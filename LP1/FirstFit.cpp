
#include<bits/stdc++.h>
using namespace std;

void firstFit(vector<int>& block, int bs, vector<int>& process, int ps)
{
    vector<int> alloc(ps,-1);

    for(int i=0;i<ps;i++)
    {
        for(int j=0;j<bs;j++)
        {
            if(block[j]>=process[i])
            {
                alloc[i]=j;
                block[j]-=process[i];
                break;
            }
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

    firstFit(block, bs, process, ps);
    return 0;
}