SELECT
    S1.Score,
    COUNT(DISTINCT S2.Score) AS Rank
FROM
    Scores S1 INNER JOIN
    Scores S2
    ON S1.Score <= S2.Score
GROUP BY
    S1.id 
ORDER BY
    S1.Score DESC;
