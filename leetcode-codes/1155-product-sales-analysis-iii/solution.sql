# Write your MySQL query statement below
select s1.product_id,s1.year first_year,s1.quantity,s1.price
from sales s1
where (s1.product_id,s1.year) in
(select product_id, min(year) year
from sales
group by product_id)

