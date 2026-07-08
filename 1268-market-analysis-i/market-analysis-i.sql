# Write your MySQL query statement below
with temp as(
    select * from orders
    where year(order_date)=2019
)
select u.user_id buyer_id, min(u.join_date) join_date,count(t.order_id) orders_in_2019 from users u
left join temp t on u.user_id = t.buyer_id
group by u.user_id
