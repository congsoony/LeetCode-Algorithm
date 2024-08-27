
select e1.name from employee e1
where id in (select managerid from employee e2
group by managerid
having count(managerid)>=5)
