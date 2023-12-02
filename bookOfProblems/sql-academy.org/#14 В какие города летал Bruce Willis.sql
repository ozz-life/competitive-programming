SELECT
    town_to
FROM
    trip
    INNER JOIN Pass_in_trip ON trip.id = Pass_in_trip.trip
    INNER JOIN Passenger ON Pass_in_trip.passenger = passenger.id
WHERE
    passenger.name = 'Bruce Willis';