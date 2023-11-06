# Write your MySQL query statement below

select p.product_name, sum(o.unit) unit
from orders o 
join products p on o.product_id = p.product_id
where year(order_date)=2020 and month(order_date)=2
group by o.product_id,year(order_date),month(order_date)
having unit >=100

