# Write your MySQL query statement below
with temp as(select name, salary, departmentid, dense_rank() over(partition by departmentid order by salary desc) 'ranking' from employee)


select d.name department ,t.name employee, t.salary
from temp t
join department d on d.id = t.departmentid
where t.ranking<=3
