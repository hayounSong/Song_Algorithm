SELECT YEAR(SA.SALES_DATE),MONTH(SA.SALES_DATE), COUNT(DISTINCT SA.USER_ID) PUCHASED_USERS, ROUND((COUNT(DISTINCT SA.USER_ID)/
                                                                                            (
   SELECT COUNT(DISTINCT USER_ID)
FROM USER_INFO
WHERE JOINED LIKE "2021-%"

)),1) PUCHASED_USERS
FROM ONLINE_SALE SA LEFT JOIN USER_INFO US ON SA.USER_ID=US.USER_ID
WHERE US.JOINED LIKE "2021-%"
GROUP BY YEAR(SA.SALES_DATE),MONTH(SA.SALES_DATE)
ORDER BY YEAR(SA.SALES_DATE),MONTH(SA.SALES_DATE)
