# Write your MySQL query statement below
select ROUND(100 * (select count(*) from Delivery where order_date = customer_pref_delivery_date) / (select count(*) from Delivery), 2) as immediate_percentage