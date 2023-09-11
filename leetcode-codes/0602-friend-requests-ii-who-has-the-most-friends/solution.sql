# Write your MySQL query statement below
select a.id,count(*) as num from
(select requester_id id from requestaccepted
union all
select accepter_id from requestaccepted) a
group by a.id
order by num desc limit 1
