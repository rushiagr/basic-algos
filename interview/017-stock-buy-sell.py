# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/#/description

def maxProfit(self, prices):
    max_profit = 0
    min_price = 9999999999
    for price in prices:
        if price < min_price:
            min_price = price
        elif price - min_price > max_profit:
            max_profit = price - min_price
    return max_profit
