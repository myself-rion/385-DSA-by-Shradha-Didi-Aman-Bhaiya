class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int minPrice=INT_MAX;
        int maxProfit=0;
        int sellingPrice=0;
        //find minimum stock price
        for(int i=0;i<prices.size();i++)
        {
            if(minPrice>prices[i]){
                minPrice=prices[i];
            }
            sellingPrice=prices[i]-minPrice;
        if(maxProfit<sellingPrice){
            maxProfit=sellingPrice;
        }
        }
            return maxProfit;
    }
};