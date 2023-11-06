# Write your MySQL query statement below
with temp as(
select e.employee_id id1,e.name,s.employee_id id2,s.salary from employees e
left outer join salaries s on e.employee_id = s.employee_id
union
select e.employee_id id1,e.name,s.employee_id id2,s.salary from employees e
right outer join salaries s on e.employee_id = s.employee_id)

select ifnull(id1,id2) employee_id from temp
where id1 is null or id2 is null
order by employee_id
