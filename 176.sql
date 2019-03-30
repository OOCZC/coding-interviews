SELECT max(Salary) AS SecondHighestSalary FROM Employee 
where Salary <> 
(SELECT max(Salary) FROM Employee);
