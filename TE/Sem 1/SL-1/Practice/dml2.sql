/* ------------------- TABLE STRUCTURES -------------------------
mysql> select * from customer;
+---------+------------+------+
| cust_id | phone      | name |
+---------+------------+------+
| 0       | 2221112222 | j    |
| 11111   | 2221112222 | i    |
| 22222   | 2222222222 | a    |
| 33333   | 3333333333 | b    |
| 44444   | 4444444444 | c    |
| 55555   | 5555555555 | d    |
| 66666   | 2221112221 | e    |
| 77777   | 2221112222 | f    |
| 88888   | 2221112222 | g    |
| 99999   | 2221112222 | h    |
+---------+------------+------+
10 rows in set (0.00 sec)
mysql> select * from product;
+--------+------------+----------+----------+----------+
| price  | product_id | quantity | name     | store_id |
+--------+------------+----------+----------+----------+
| 124.97 | 0          |        7 | book     |    22222 |
| 344.22 | 11111      |        6 | pen      |    11111 |
| 664.22 | 22222      |       45 | pencil   |    22222 |
| 345.98 | 33333      |       14 | football |    22222 |
| 235.87 | 44444      |       53 | sharpner |    11111 |
| 452.75 | 55555      |        4 | eraser   |    33333 |
|  230.2 | 66666      |       12 | p2       |    33333 |
| 399.99 | 77777      |        3 | p3       |    11111 |
| 120.98 | 88888      |        6 | p1       |    33333 |
| 620.99 | 99999      |       40 | p4       |    11111 |
+--------+------------+----------+----------+----------+
10 rows in set (0.00 sec)
mysql> select * from orders;
+----------+---------+---------+------------+
| order_id | cust_id | prod_id | order_date |
+----------+---------+---------+------------+
| 1        | 22222   | 66666   | 2019-06-01 |
| 1        | 22222   | 88888   | 2019-06-01 |
| 1        | 22222   | 99999   | 2019-06-01 |
| 2        | 33333   | 66666   | 2019-06-01 |
| 2        | 33333   | 88888   | 2019-06-01 |
| 3        | 33333   | 66666   | 2019-06-01 |
| 3        | 33333   | 77777   | 2019-06-01 |
| 4        | 44444   | 66666   | 2019-07-18 |
| 4        | 44444   | 77777   | 2019-07-18 |
| 4        | 44444   | 88888   | 2019-07-18 |
| 5        | 11111   | 11111   | 2019-07-18 |
| 5        | 11111   | 22222   | 2019-07-18 |
| 5        | 11111   | 77777   | 2019-07-18 |
+----------+---------+---------+------------+
13 rows in set (0.01 sec)
*/



/*========================================================================*/
/* Get the total no of customers */
/*========================================================================*/
select count(*) as total_customers from customer;
/*
OUTPUT
+-----------------+
| total_customers |
+-----------------+
|              10 |
+-----------------+
1 row in set (0.01 sec)
*/
/*========================================================================*/





/*========================================================================*/
/*  Display average purchase amount of all the customers */
/*========================================================================*/
select cust_id, avg((	
			select price 
			from product 
			where product_id = prod_id
		)) as total 
from orders 
group by cust_id;
/*
OUTPUT
+---------+--------------------+
| cust_id | total              |
+---------+--------------------+
| 11111   |  469.4766540527344 |
| 22222   |  324.0566635131836 |
| 33333   | 245.34249687194824 |
| 44444   | 250.38999684651694 |
+---------+--------------------+
4 rows in set (0.00 sec)
*/
/*========================================================================*/




/*========================================================================*/
/*  Display total purchase amount of all the customer */
/*========================================================================*/
select cust_id, sum((	
			select price 
			from product 
			where product_id = prod_id
		)) as total 
from orders 
group by cust_id;
/*
OUTPUT
+---------+--------------------+
| cust_id | total              |
+---------+--------------------+
| 11111   | 1408.4299621582031 |
| 22222   |  972.1699905395508 |
| 33333   |   981.369987487793 |
| 44444   |  751.1699905395508 |
+---------+--------------------+
4 rows in set (0.00 sec)
*/
/*========================================================================*/




/*========================================================================*/
/* Find DAYNAME, MONTHNAME and YEAR of the purchase order made on “19-11-2016” */
/*========================================================================*/
select dayname(order_date) as dayname, monthname(order_date) as month, year(order_date) as year from orders where order_date='2019-6-1';
/*
OUTPUT
+----------+-------+------+
| dayname  | month | year |
+----------+-------+------+
| Saturday | June  | 2019 |
| Saturday | June  | 2019 |
| Saturday | June  | 2019 |
| Saturday | June  | 2019 |
| Saturday | June  | 2019 |
| Saturday | June  | 2019 |
| Saturday | June  | 2019 |
+----------+-------+------+
7 rows in set (0.00 sec)
*/

/*
Get current date & time, current time, current date
*/
select sysdate();
+---------------------+
| sysdate()           |
+---------------------+
| 2019-07-25 10:03:30 |
+---------------------+
1 row in set (0.02 sec)

select date(sysdate());
+-----------------+
| date(sysdate()) |
+-----------------+
| 2019-07-25      |
+-----------------+
1 row in set (0.00 sec)

select time(sysdate());
+-----------------+
| time(sysdate()) |
+-----------------+
| 10:03:55        |
+-----------------+

1 row in set (0.00 sec)

/*
Get 6 month future & past date using interval function based on current date and name the column accordingly.
*/
SELECT (CURDATE()-INTERVAL 6 MONTH);
+------------------------------+
| (CURDATE()-INTERVAL 6 MONTH) |
+------------------------------+
| 2019-01-25                   |
+------------------------------+
1 row in set (0.00 sec)

mysql> SELECT (CURDATE()-INTERVAL 6 MONTH) AS past_6_month,(CURDATE()+INTERVAL 6 MONTH) AS future_6_month;
+--------------+----------------+
| past_6_month | future_6_month |
+--------------+----------------+
| 2019-01-25   | 2020-01-25     |
+--------------+----------------+
1 row in set (0.00 sec)


/*
Find purchase details of the customers group by product category.
*/
 SELECT * FROM customer WHERE cust_id in (SELECT cust_id FROM orders GROUP BY prod_id);
+---------+------------+------+--------+
| cust_id | phone      | name | city   |
+---------+------------+------+--------+
| 11111   | 2221112222 | i    | Pune   |
| 22222   | 2222222222 | a    | Mumbai |
| 33333   | 3333333333 | b    | Nashik |
| 44444   | 4444444444 | c    | Nashik |
+---------+------------+------+--------+
4 rows in set (0.03 sec)


