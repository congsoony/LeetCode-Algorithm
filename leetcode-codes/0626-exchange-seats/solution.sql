# Write your MySQL query statement below
select case when (select count(*) num from seat) %2 =1 then 
case when id =(select count(*) num from seat)  then id
when id%2=1 then id+1
else id-1
end
when id%2=1 then id+1
else id-1
 end as id,
student from seat
order by id
