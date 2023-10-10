# Write your MySQL query statement below
select 'Low Salary' category, count(account_id) accounts_count from accounts
where income<20000
union
select 'Average Salary' category, count(account_id) from accounts
where income between 20000 and 50000
union
select 'High Salary' category, count(account_id) from accounts
where income>50000

