
// Page replacement algorithm
// FIFO

#include<bits/stdc++.h>
using namespace std;

void pageFaults(vector<int>& pages, int n, int frameSize)
{

	unordered_set<int> s;
    queue<int> q;
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
			q.push(pages[i]);
		}

		else
		{
			if (s.find(pages[i]) == s.end())
			{
				int val = q.front();
				q.pop();
				s.erase(val);
				s.insert(pages[i]);
				q.push(pages[i]);
				page_faults++;
			}
			else
			{
			    page_hits++;
			}
		}
	}

	cout<<"Page Faults - "<<page_faults<<endl;
	cout<<"Page Hits - "<<page_hits<<endl;
}

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