# Write your MySQL query statement below

SELECT STOCK_NAME, SUM(IF(operation='sell',price,-price)) as capital_gain_loss FROM STOCKS
GROUP BY STOCK_NAME


