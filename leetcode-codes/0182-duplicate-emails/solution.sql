# Write your MySQL query statement below
select p.email from person p
inner join person p2 
on p.id != p2.id and p.email = p2.email
group by p.email

