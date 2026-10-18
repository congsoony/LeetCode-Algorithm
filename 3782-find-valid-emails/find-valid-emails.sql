select * from users
where regexp_like (email,'^\\w+@[a-zA-Z]+\\.com$','c')
order by user_id