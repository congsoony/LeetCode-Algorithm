# Write your MySQL query statement below
select * from users
where email regexp '^[\\w_]+@[a-zA-Z]+\\.com$'
order by user_id