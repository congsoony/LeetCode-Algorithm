with temp as(select person_id, person_name, weight,sum(weight) over(order by turn) total,turn
from queue
order by total desc)
select person_name from temp
where total<=1000
limit 1
