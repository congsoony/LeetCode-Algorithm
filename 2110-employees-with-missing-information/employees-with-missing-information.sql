# Write your MySQL query statement below
with temp as(
select e.employee_id from employees e
left join salaries s on e.employee_id = s.employee_id
where s.employee_id is null

union
select s.employee_id from employees e
right join salaries s on e.employee_id = s.employee_id
where e.employee_id is null
)
select * from temp
order by employee_id