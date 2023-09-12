# Write your MySQL query statement below
(select u.name results from users u
join(select user_id ,count(user_id) as cnt from movierating
group by user_id) m on m.user_id = u.user_id
order by m.cnt desc,u.name
limit 1)
union all
(select m1.title from movies m1
join (select movie_id,avg(rating) as av from movierating
where date_format(created_at,'%Y-%m') = '2020-02'
group by movie_id) m2 on m1.movie_id = m2.movie_id
order by m2.av desc ,m1.title
limit 1)
