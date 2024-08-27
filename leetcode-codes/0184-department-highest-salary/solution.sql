
select d1.name as department, e1.name employee ,e1.salary
from employee e1 inner join department d1 on e1.departmentid = d1.id
where (e1.salary,e1.departmentid) in (
    select max(e2.salary) salary ,e2.departmentid from employee e2
    group by e2.departmentid)

