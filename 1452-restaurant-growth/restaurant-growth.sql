with temp as(
    select visited_on ,sum(amount) amount
    from customer
    group by visited_on
)
select c.visited_on,sum(c.amount) amount, round(sum(c.amount)/7,2) average_amount from temp t
join customer c on t.visited_on between c.visited_on and date_add(c.visited_on,interval 6 day)
group by t.visited_on
having t.visited_on >= min(c.visited_on) + interval 6 day
order by c.visited_on