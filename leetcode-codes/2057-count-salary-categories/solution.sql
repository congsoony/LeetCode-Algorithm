# Write your MySQL query statement below


select 'Low Salary' category, count(*) accounts_count from accounts
where income <20000
union all
select 'Average Salary' category, count(*) accounts_count from accounts
where 20000<= income and income<= 50000
union all
select 'High Salary' category, count(*) accounts_count from accounts
where income >50000

