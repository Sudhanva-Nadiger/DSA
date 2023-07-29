# Write your MySQL query statement below

select count(*) as rich_count from (select distinct customer_id from store where amount > 500) as t
