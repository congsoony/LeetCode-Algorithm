WITH DailySum AS (
    -- 1단계: 날짜별로 총 매출을 하나로 합치기 (하루에 여러 명 결제한 것 묶기)
    SELECT visited_on, SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
),
MovingAvg AS (
    -- 2단계: 윈도우 함수로 최근 7일(자신 포함 과거 6일) 누적합과 평균 계산하기
    SELECT 
        visited_on,
        SUM(amount) OVER(ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS amount,
        ROUND(SUM(amount) OVER(ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) / 7, 2) AS average_amount
    FROM DailySum
)
-- 3단계: 전체 데이터 중 7일치가 채워지지 않은 첫 6일의 데이터는 버리기
SELECT visited_on, amount, average_amount
FROM MovingAvg
WHERE visited_on >= (SELECT MIN(visited_on) + INTERVAL 6 DAY FROM Customer)
ORDER BY visited_on;