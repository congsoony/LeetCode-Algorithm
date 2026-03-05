# Write your MySQL query statement below
select d.name Department,e.name Employee,e.salary Salary
from employee e
join (select departmentid, max(salary) salary
from employee
group by departmentid) t on t.departmentid = e.departmentid and e.salary = t.salary
join department d on d.id = e.departmentid
