SELECT
    time_in
FROM
    trip
    INNER JOIN Pass_in_trip ON trip.id = Pass_in_trip.trip
    INNER JOIN passenger ON Pass_in_trip.passenger = passenger.id
WHERE
    passenger.name = 'Steve Martin'
    AND town_to = 'London';