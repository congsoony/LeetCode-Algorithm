# Write your MySQL query statement below
with temp as(select product_id, new_price, change_date,
dense_rank() over(partition by product_id order by change_date desc) as 'ran'
from products
where change_date <='2019-08-16')

select p.product_id,ifnull(t.new_price,10) price from (select * from products group by product_id) p
left join temp t on p.product_id = t.product_id and t.ran = 1

