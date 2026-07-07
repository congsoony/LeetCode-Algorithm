# Write your MySQL query statement below
select max(num) num from mynumbers
where num  = (select num from mynumbers
group by num
having count(num) = 1
order by num desc
limit 1)
