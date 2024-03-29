-- 코드를 입력하세요
SELECT PR.PRODUCT_CODE,(SUM(SA.SALES_AMOUNT*PR.PRICE))SALES
FROM PRODUCT PR LEFT JOIN OFFLINE_SALE SA ON PR.PRODUCT_ID=SA.PRODUCT_ID
GROUP BY PRODUCT_CODE
ORDER BY (SUM(SA.SALES_AMOUNT*PR.PRICE)) DESC, PRODUCT_CODE;