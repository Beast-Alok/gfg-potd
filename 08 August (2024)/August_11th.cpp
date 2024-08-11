//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job &job1, Job &job2){
        return job1.profit > job2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n){ 
        sort(arr, arr+n, comp);
        int profit = 0, cnt = 0, maxtime = -1;
        
        for(int i=0; i<n; i++){
            maxtime = max(maxtime, arr[i].dead);
        }
        
        vector<int> jobs(maxtime+1, -1);
        for(int i=0; i<n; i++){
            
            for(int j = arr[i].dead; j > 0; j--){
                if(jobs[j] == -1){
                    cnt++;
                    jobs[j] = arr[i].id;
                    profit += arr[i].profit;
                    break;
                }
            }
        }
        return {cnt, profit};
    } 
    
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
