# Write your MySQL query statement below
with temp as(
select i1.category c1,i2.category c2 from productinfo i1
join productinfo i2 on i1.category < i2.category
group by i1.category,i2.category),
temp2 as(
select p1.user_id, p1.product_id,i1.category from productpurchases p1 
join productinfo i1 on p1.product_id = i1.product_id),
temp3 as(
select t.user_id ,t.category c1,t2.category c2 from temp2 t
join temp2 t2 on t.user_id = t2.user_id and t.category<t2.category)

select t.c1 category1,t.c2 category2,count(distinct t.user_id) customer_count from temp3 t
group by t.c1,t.c2
having customer_count>=3
order by customer_count desc , category1, category2

