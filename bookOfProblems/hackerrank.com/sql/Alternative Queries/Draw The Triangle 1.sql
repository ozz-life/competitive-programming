SET
    @num = 21;

SELECT
    repeat('* ', @num := @num -1)
FROM
    information_schema.tables
LIMIT
    20;
    
--------------------------------------------------------------------------------

DELIMITER //
CREATE PROCEDURE Asterisk(n INT)
BEGIN
    DECLARE i INT DEFAULT 20;
    WHILE i > 0 DO
        SELECT REPEAT('* ', i);
        SET i = i - 1;
    END WHILE;
END //
DELIMITER ;

CALL Asterisk(20)

--------------------------------------------------------------------------------

DELIMITER //
CREATE PROCEDURE Pattern(n INT)
BEGIN
    DECLARE i INT DEFAULT n;
    WHILE i > 0 DO
        SELECT REPEAT("* ", i);
        SET i = i-1;
    END WHILE;
END //
DELIMITER ;

CALL Pattern(20);

--------------------------------------------------------------------------------

WITH RECURSIVE cte(n) AS
(
    SELECT 20
    UNION ALL
    SELECT n - 1 FROM cte WHERE n > 1
)
SELECT repeat('* ',n) FROM cte;