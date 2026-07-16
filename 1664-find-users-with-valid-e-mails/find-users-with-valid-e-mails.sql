# Write your MySQL query statement below


select * from users
where regexp_like (mail,'^[A-Za-z][\\w\\.\\-_]*@leetcode\\.com$','c')