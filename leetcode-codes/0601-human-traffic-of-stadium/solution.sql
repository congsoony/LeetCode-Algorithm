# Write your MySQL query statement below
with temp as(select id, visit_date,lag(people) over() prev,people,lead(people) over() next ,
lag(people,2) over() prev2,lead(people,2) over() next2
from stadium)

select id,visit_date,people
from temp
where (prev>=100 and prev2 >= 100 and people>=100) or (prev>=100 and people>=100 and next>=100) or (people>=100 and next>=100 and next2>=100)
order by visit_date


