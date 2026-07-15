# Write your MySQL query statement below
(select u.name results from users u
join movierating r on u.user_id  = r.user_id
group by u.user_id
order by count(*) desc ,u.name
limit 1)
union all
(
select m.title results from movies m 
join movierating r on m.movie_id = r.movie_id  and
r.created_at like '2020-02%'
group by m.movie_id
order by avg(r.rating) desc,m.title asc
limit 1
)