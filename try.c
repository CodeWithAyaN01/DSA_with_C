/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0
*/
#include<stdio.h>
#include<stdlib.h>2
int max = 0;
int main()
{
    int price[] = {7,1,6,6,3};
    int pricesize = sizeof(price) / sizeof(price[0]);;
    int price1[pricesize];
    // int index[10];
    int BuyIndex;
    int sellIndex;
    // make a copy of price
    for (int i = 0 ; i<pricesize;i++)
    {
        price1[i] = price[i];
    }

    for (int i = 0 ; i<pricesize-1 ; i++)
    {
        for (int j = 0 ; j<pricesize-i-1 ; j++)
        {
            if(price1[j] > price1[j+1])
            {
                int temp = price1[j];
                price1[j] = price1[j+1];
                price1[j+1] = temp;
            }
        }
    }
    for (int i = 0 ; i<pricesize ; i++)
    {
        if (price[i] == price1[0])
        {
            BuyIndex = i; // best day to buy
        }
    }
    if (price1[0] == price[pricesize-1])
    {
        printf("Dont buy Stock");
        return 0;
    }
    // foe selling day 

    for (int j = BuyIndex ;j < pricesize ; j++ ) //int price[] = {10,1,3,4,11,8};
    {
        // int max = 0;
        if ((price[j+1] > price[j+2]) && price[j+1] > max)
        {
            max = price[j+1];
        }
    }
    // for sell index;

    for (int i = 0 ; i<pricesize ; i++)
    {
        if (price[i] == max)
        {
            sellIndex = i;
        }
    }   

    printf("byu at %d at %dth day\n",price[BuyIndex],BuyIndex);
    printf("sell at %d at %dth day\n",price[sellIndex],sellIndex);




}