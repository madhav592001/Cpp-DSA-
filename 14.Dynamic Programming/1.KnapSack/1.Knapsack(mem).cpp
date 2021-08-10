//!                         KnapSack Recursive

#include <bits/stdc++.h>
using namespace std;

int static t[102][1002]  ;      //?   we will see constraints of problem      n and W             

int knapsack(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
        return 0;

    if(t[n][W] != -1)
    {
        return t[n][W] ; 
    }

    if(wt[n-1] <= W)
    {
        return t[n][W] = max((val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1)), knapsack(wt, val, W, n - 1));
    }

    else if(wt[n-1] > W)
    {
        return t[n][W] = knapsack(wt,val,W,n-1) ;
    }

    //todo             Recursive
    // if (wt[n - 1] <= W)
    // {
    //     return max((val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1)), knapsack(wt, val, W, n - 1));
    // }
    // else if(wt[n-1] > W)
    // {
    //     return knapsack(wt,val,W,n-1) ; 
    // }
}

int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int W = 7;

    memset(t,-1,sizeof(t)) ;

    int maxProfit = knapsack(wt, val, W, 4);

    cout << "The max profit is : " << maxProfit;
}