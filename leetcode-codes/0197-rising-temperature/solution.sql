# Write your MySQL query statement below
select w2.id from weather w1
join weather w2 on w2.recorddate = date_add(w1.recorddate,interval 1 day) and w1.temperature <w2.temperature


