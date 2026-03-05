# Write your MySQL query statement below
select p1.email email from person p1
group by p1.email
having count(p1.email)>1
