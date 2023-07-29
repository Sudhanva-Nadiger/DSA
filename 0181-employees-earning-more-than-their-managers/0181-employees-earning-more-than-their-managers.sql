# Write your MySQL query statement below

select e1.name as Employee from employee e1 where e1.salary > (select e.salary from employee e where e.id = e1.managerId)