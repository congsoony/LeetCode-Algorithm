
select product_id,first_value(new_price) over(partition by product_id order by change_date desc) price
from products
where change_date<= '2019-08-16'
union
select product_id,10
from products
group by product_id
having min(change_date)>'2019-08-16'
