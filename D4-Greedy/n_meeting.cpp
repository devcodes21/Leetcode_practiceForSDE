/*
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.

What is the maximum number of meetings that can be accommodated in the meeting room?

Input:
The first line of input consists number of the test cases. The description of T test cases is as follows:
The first line consists of the size of the array, second line has the array containing the starting time of all the meetings each separated by a space, i.e., S [ i ]. And the third line has the array containing the finishing time of all the meetings each separated by a space, i.e., F [ i ].

Output:
In each separate line print the order in which the meetings take place separated by a space.

Constraints:
1 ≤ T ≤ 70
1 ≤ N ≤ 100
1 ≤ S[ i ], F[ i ] ≤ 100000

Example:
Input:
2
6
1 3 0 5 8 5
2 4 6 7 9 9
8
75250 50074 43659 8931 11273 27545 50879 77924
112960 114515 81825 93424 54316 35533 73383 160252  

Output:
1 2 4 5
6 7 1

Explanation:
Testcase 1: Four meetings can held with given start and end timings.
 
*/

/*Approach: Sort the struct wrt finish times*/

#include <bits/stdc++.h>
using namespace std;

struct meeting
{
    int start;
    int end;
    int index;
};

bool comparator(struct meeting meet1,struct meeting meet2)
{
    return meet1.end<meet2.end;
}

void schedule_meets(int S[],int F[],int n)
{
    struct meeting meet[n];
    for(int i=0;i<n;i++)
    {
        meet[i].start = S[i];
        meet[i].end = F[i];
        meet[i].index = i+1;
    }
    
    sort(meet,meet+n,comparator);
    vector<int> v1;
    v1.push_back(meet[0].index);
    int time_now = meet[0].end;
    for(int i=1;i<n;i++)
    {
        if(meet[i].start>time_now)
        {
            v1.push_back(meet[i].index);
            time_now = meet[i].end;
            
        }
        
    }
    
    for(auto nums:v1)
    {
        cout<<nums<<" ";
    }
    
    cout<<"\n";
}



int main() {
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    int N;
	    cin>>N;
	    int S[N];
	    for(int i=0;i<N;i++)
	    {
	        cin>>S[i];
	    }
	    int F[N];
	    for(int i=0;i<N;i++)
	    {
	        cin>>F[i];
	    }
	    
	    schedule_meets(S,F,N);
	}
	return 0;
}