# Write your MySQL query statement below
with temp as(
select person_name , weight, sum(weight) over(order by turn) total
from queue)

select person_name from temp
where total<=1000
order by total desc
limit 1
