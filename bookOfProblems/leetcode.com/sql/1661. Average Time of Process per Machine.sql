SELECT
    a1.machine_id,
    ROUND(AVG(a2.timestamp - a1.timestamp)::numeric, 3) AS processing_time
FROM
    Activity a1
    JOIN Activity a2
    ON a1.machine_id = a2.machine_id
    AND a1.process_id = a2.process_id
    AND a1.activity_type = 'start'
    AND a2.activity_type = 'end'
GROUP BY
    a1.machine_id;
-----
SELECT
    a.machine_id,
    ROUND(
        (
            (
                SELECT
                    AVG(a1.timestamp)
                FROM
                    Activity a1
                WHERE
                    a1.activity_type = 'end'
                    AND a1.machine_id = a.machine_id
            ) - (
                SELECT
                    AVG(a1.timestamp)
                FROM
                    Activity a1
                WHERE
                    a1.activity_type = 'start'
                    AND a1.machine_id = a.machine_id
            )
        )::numeric,
        3
    ) AS processing_time
FROM
    Activity a
GROUP BY
    a.machine_id;
--------
SELECT
    a1.machine_id,
    ROUND(AVG(a2.timestamp - a1.timestamp)::numeric, 3) as processing_time
FROM
    Activity a1
    JOIN Activity a2 
    ON a1.process_id = a2.process_id
    AND a1.machine_id = a2.machine_id
    AND a1.activity_type = 'start'
    AND a2.activity_type = 'end'
GROUP BY
    a1.machine_id;
    
    
------------
WITH ProcessTimes AS (
    SELECT 
        machine_id, 
        process_id,
        MAX(timestamp) - MIN(timestamp) AS process_time
    FROM 
        Activity
    GROUP BY 
        machine_id, process_id
)
SELECT 
    machine_id,
    ROUND(AVG(process_time)::numeric, 3) AS processing_time
FROM 
    ProcessTimes
GROUP BY 
    machine_id;

---------
SELECT 
    a.machine_id, 
    ROUND(AVG(b.timestamp - a.timestamp)::numeric, 3) AS processing_time
FROM 
    Activity a
JOIN 
    Activity b
ON 
    a.machine_id = b.machine_id
AND 
    a.process_id = b.process_id
AND 
    a.activity_type = 'start'
AND 
    b.activity_type = 'end'
GROUP BY 
    a.machine_id;