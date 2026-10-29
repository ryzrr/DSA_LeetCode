# Write your MySQL query statement belo
select today.id from  Weather today  JOIN Weather yesterday ON DATEDIFF(today.recordDate ,yesterday.recordDate) =1
where today.temperature > yesterday.temperature;