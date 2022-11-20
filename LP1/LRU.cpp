
// Page Replacement Algorithm
// LRU
#include<bits/stdc++.h>
using namespace std;
 
// Function to find page faults using indexes
void pageFaults(vector<int>& pages, int n, int frameSize)
{
    unordered_set<int> s;
    unordered_map<int, int> indexes;
 
    int page_faults = 0;
    int page_hits = 0;
    for (int i=0; i<n; i++)
    {
        if (s.size() < frameSize)
        {
            if (s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                page_faults++;
            }
            else
            {
                page_hits++;
            }
            indexes[pages[i]] = i;
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int lru = INT_MAX;
                int val;
                for (auto it=s.begin(); it!=s.end(); it++)
                {
                    // cout<<indexes[*it]<<" ";
                    // cout<<*it<<endl;
                    if (indexes[*it] < lru)
                    {
                        lru = indexes[*it];
                        val = *it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;
            }
            else
            {
                page_hits++;
            }
            indexes[pages[i]] = i;
        }
    }
 
    cout<<"Page Faults - "<<page_faults<<endl;
	cout<<"Page Hits - "<<page_hits<<endl;
}
 
// Driver code
int main()
{
    int n;
	cout<<"Enter string reference length - ";
	cin>>n;
	
	vector<int> pages(n);
	cout<<"page reference stream:\n";
    for (int i = 0; i < n; i++) 
        cin>>pages[i];
	
	int frameSize;
	cout<<"Enter frame size - ";
	cin>>frameSize;
	
	pageFaults(pages, n, frameSize);
	return 0;
}