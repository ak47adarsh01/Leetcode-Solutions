SELECT E.name as 'Employee' 
FROM Employee E, Employee F 
WHERE E.managerId = F.id 
	AND E.salary > F.salary;