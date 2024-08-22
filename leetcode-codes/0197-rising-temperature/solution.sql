SELECT W1.id
FROM Weather W1
inner JOIN Weather W2
ON W1.recordDate = DATE_ADD(W2.recordDate, INTERVAL 1 DAY) and
W1.temperature>W2.temperature
