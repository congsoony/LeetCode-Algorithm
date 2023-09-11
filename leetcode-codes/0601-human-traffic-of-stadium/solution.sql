# Write your MySQL query statement below

select id, visit_date,people 
from
(select id, visit_date,people ,lead(people,1) over(order by id) nxt1 ,lead(people,2) over(order by id) nxt2,
lag(people,1) over(order by id) b1,
lag(people,2) over(order by id) b2
from stadium) as a
where (people>=100 and nxt1>=100 and nxt2>=100) || (people>=100 and b1>=100 and nxt1>=100) || (people>=100 and b1>=100 and b2>=100)
order by visit_date
