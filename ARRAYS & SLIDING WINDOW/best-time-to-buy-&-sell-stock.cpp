/* You are given an array prices where prices[i] is the price of a given stock on the ith day.

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
Explanation: In this case, no transactions are done and the max profit = 0.

 APPROACH:
 -SO BASICALLY IN THIS QST. WE HAVE TO MAXIMISE THE PROFIT BY CHOOSING THE SMALLEST VALUE (TO BUY ON THAT DAY
  AND LARGEST VALUE (TO SELL ON THAT DAY), BUT SELL INDEX SHOULD COME AFTER BUY INDEX IN THE ARRAY.
 -SO WE WILL INITIALIZE MIN PRICE & MAX PROFIT.
 -AND WE WILL GO THROUGH THE ARAY USING LOOP.
 -WHENEVER PRICE[I] < MIN PRICE, MINPRICE WILL BE EQUAL TO PRICE[I]
   OTHERWISE (PRICE[I] > MIN PRICE) , MAX PROFIT WILL BE THE MAX OF ( MAX PROIFT , PRICE[I] - MIN PRICE )
   AS BACUASE PROFIT IS (SELL - BUY)
 -FINAL ASNWER WILL BE THE MAX PROFIT

   TIME COMPLEXITY- O(N)
   SPACE COMPLEXITY-O(1)  
                                         */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;        //INT_MAX means the largest possible value an integer data type can hold. (used for first pass i.e when i=0)
    int maxProfit = 0;

    for (int price : prices) {
        if (price < minPrice) {
            minPrice = price; // Buy
        } else {
            maxProfit = max(maxProfit, price - minPrice); // Sell
        }
    }

    return maxProfit;
}
};
