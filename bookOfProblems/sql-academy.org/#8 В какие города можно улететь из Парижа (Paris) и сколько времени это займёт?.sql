SELECT town_to, 
       SEC_TO_TIME(TIME_TO_SEC(time_out) - TIME_TO_SEC(time_in)) AS flight_time
FROM trip
WHERE town_from = 'Paris';
