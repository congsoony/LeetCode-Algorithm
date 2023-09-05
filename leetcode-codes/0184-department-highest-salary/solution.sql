# Write your MySQL query statement below
select d.name as Department , e.name as Employee, e.salary
from employee e
inner join department d on d.id = e.departmentid
where (e.salary,e.departmentid) in (
    select max(e2.salary) salary,e2.departmentid from employee e2
group by e2.departmentid)

