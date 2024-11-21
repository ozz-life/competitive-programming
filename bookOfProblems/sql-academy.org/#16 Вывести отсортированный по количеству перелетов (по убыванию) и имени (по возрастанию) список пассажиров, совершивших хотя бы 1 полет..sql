SELECT
    passenger.name,
    COUNT(passenger.name) AS count
FROM
    passenger
    INNER JOIN Pass_in_trip ON passenger.id = Pass_in_trip.passenger
GROUP BY
    passenger.name
HAVING
    count > 0
ORDER BY
    count DESC,
    passenger.name ASC;