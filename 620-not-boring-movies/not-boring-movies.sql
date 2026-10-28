# Write your MySQL query statement below
select id, movie, description, rating from(
    select id , movie , description ,rating , ROW_NUMBER() OVER (order by id) as rn
from Cinema
)t
where MOD(rn,2) =1 and description not in ('boring')
order by rating DESC;