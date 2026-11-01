# Write your MySQL query statement below
with usercount as (select count(*) as total from Users),
contestuser as (select contest_id , count(user_id) as reguser  from Register group by contest_id)
select c.contest_id,
       round(c.reguser / u.total * 100, 2) as percentage
from contestuser c
cross join usercount u
order by percentage desc, c.contest_id asc;