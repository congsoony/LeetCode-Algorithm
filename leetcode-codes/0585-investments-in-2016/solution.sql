# Write your MySQL query statement below
with temp as( select tiv_2016,count(*) over(partition by tiv_2015) tiv_2015,
count(*) over(partition by lat,lon) latlon from insurance)


select round(sum(tiv_2016),2) tiv_2016 from temp
where tiv_2015>1 and latlon=1
