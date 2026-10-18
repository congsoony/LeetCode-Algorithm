select * from users
where email regexp '^\\w+@[a-aA-Z]+\\.com$'
order by user_id