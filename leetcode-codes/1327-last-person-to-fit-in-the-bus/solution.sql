# Write your MySQL query statement below
with temp as(
select person_name ,weight, sum(weight) over(order by turn) as acc from queue
order by turn
)
select person_name from temp
where acc<=1000
order by acc desc
limit 1
