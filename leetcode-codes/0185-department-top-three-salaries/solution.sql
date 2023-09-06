# Write your MySQL query statement below
with temp as(
select name,salary,dense_rank() over(partition by departmentid order by salary desc) grade, departmentid from employee)
select d.name Department,t.name Employee, t.salary Salary
from temp t
inner join department d on d.id = t.departmentid
where grade<=3
