SELECT name FROM Passenger GROUP BY name HAVING COUNT(*) > 1;