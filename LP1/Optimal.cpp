
// Page Replacement
// Optimal

#include<bits/stdc++.h>
using namespace std;

bool search(int val, vector<int>& frame){
    for(int i=0;i<frame.size();i++){
        if(frame[i]==val){
            return true;
        }
    }
   return false; 
}

int traverse(vector<int>& pg, vector<int>& fr, int n, int fs, int nextIdx){
    int res=-1, far=nextIdx;
    for(int i=0;i<fs;i++){
        int j;
        for(j=nextIdx;j<n;j++){
            if(fr[i]==pg[j]){
                if(j>far){
                    far=j;
                    res=i;
                }
               break; 
            }
        }
        if(j==n){
            return i;
        }
    }
    return res==-1?0:res;
}

void optimal(vector<int> pg, int n, int fs)
{
    vector<int> frame;

    int pageFault=0, pageHit=0;
    for(int i=0;i<n;i++)
    {
        if(search(pg[i], frame)){
            pageHit++;
            continue;
        }

        if(frame.size()<fs){
            frame.push_back(pg[i]);
            pageFault++;
        }
        else{
            int replace = traverse(pg,frame,n,fs,i+1);
            frame[replace]=pg[i];
            pageFault++;
        }
    }
    cout<<"Page Fault - "<<pageFault<<endl;
    cout<<"Page Hit - "<<pageHit<<endl;
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
	
	optimal(pages, n, frameSize);
	return 0;
}