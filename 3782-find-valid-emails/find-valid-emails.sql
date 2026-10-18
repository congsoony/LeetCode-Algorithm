select * from users
where email regexp '^\\w+@[a-zA-Z]+\\.com$'
order by user_id