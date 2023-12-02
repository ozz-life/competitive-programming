class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT32_MAX;
		int max_profit = INT32_MIN;
		
		for(auto& i : prices) {
			min_price = std::min(min_price, i);
			max_profit = std::max(max_profit, i - min_price);
		}
		
		return max_profit;
    }
};