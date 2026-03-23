# Write your MySQL query statement below
with temp as(select visited_on from customer
group by visited_on
having visited_on >= (SELECT MIN(visited_on) + INTERVAL 6 DAY FROM customer))
select t.visited_on, sum(amount) amount, round(sum(amount)/7,2) average_amount from temp t
left join customer c
on c.visited_on >= t.visited_on - interval 6 day and c.visited_on<= t.visited_on
group by t.visited_on 
order by t.visited_on


