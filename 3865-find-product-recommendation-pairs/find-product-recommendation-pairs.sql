# Write your MySQL query statement below
with temp as(
select p1.product_id pid ,p2.product_id pid2 ,count(*) cnt from productpurchases p1 
join productpurchases p2 on p1.user_id = p2.user_id and p1.product_id < p2.product_id
group by pid,pid2
having cnt >=3)

select t.pid product1_id , t.pid2 product2_id , i1.category product1_category , i2.category product2_category , t.cnt customer_count from temp t
join productinfo i1 on t.pid = i1.product_id
join productinfo i2 on t.pid2 = i2.product_id
order by customer_count desc , product1_id ,product2_id