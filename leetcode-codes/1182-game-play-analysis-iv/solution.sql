# Write your MySQL query statement below

with temp as(select player_id, min(event_date) event_date from activity
group by player_id)

select round(
(select count(*) from activity a
join temp t on a.player_id = t.player_id and a.event_date = date_add(t.event_date, interval 1 day))/ (select count(distinct(player_id)) from activity),2) fraction


