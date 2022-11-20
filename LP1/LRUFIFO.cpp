
// Page Replacement Algorithm
// LRU
#include <bits/stdc++.h>
using namespace std;

// Function to find page faults using indexes
void LRU(vector<int> &pages, int n, int frameSize)
{
    unordered_set<int> s;
    unordered_map<int, int> indexes;

    int page_faults = 0;
    int page_hits = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.size() < frameSize)
        {
            if (s.find(pages[i]) == s.end())
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
                int lru = INT_MAX, val;
                for (auto it = s.begin(); it != s.end(); it++)
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

    cout << "Page Faults - " << page_faults << endl;
    cout << "Page Hits - " << page_hits << endl;
}

void FIFO(vector<int> &pages, int n, int frameSize)
{

    unordered_set<int> s;
    queue<int> q;
    int page_faults = 0;
    int page_hits = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.size() < frameSize)
        {
            if (s.find(pages[i]) == s.end())
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

    cout << "Page Faults - " << page_faults << endl;
    cout << "Page Hits - " << page_hits << endl;
}

// Driver code
int main()
{
    int n;
    cout << "Enter string reference length - ";
    cin >> n;

    vector<int> pages(n);
    cout << "page reference stream:\n";
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    int frameSize;
    cout << "Enter frame size - ";
    cin >> frameSize;

    int x;
    cout << "Choose  - ";
    cout << "1) LRU" << endl
         << "2) FIFO" << endl
         << "3) Exit" << endl;
    cout<<"Your choice - ";     
    cin >> x;

    switch(x){
        case 1:
        LRU(pages, n, frameSize);
        break;
        case 2:
        FIFO(pages, n, frameSize);
        break;
        case 3:
        cout<<"Thanks for using";
        break;
        default:
        break;
    }

    return 0;
}