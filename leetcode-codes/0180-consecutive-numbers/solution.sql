with temp as(
select num, lead(num,1) over() num1,
lead(num,2) over() num2 from logs
) 
select distinct (num) ConsecutiveNums from temp where num = num1 and num1 = num2
