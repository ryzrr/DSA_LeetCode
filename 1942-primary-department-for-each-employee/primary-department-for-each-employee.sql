# Write your MySQL query statement below
select employee_id , department_id from  Employee  where primary_flag  ='Y' 
union
SELECT employee_id, department_id
FROM Employee
GROUP BY employee_id
HAVING COUNT(*) = 1