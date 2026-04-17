/*
SELECT NIP AS codigo, nombre FROM alumnos;
SELECT alumnos.Calificacion AS Nota FROM alumnos;
SELECT A.edad, A.nip AS codigo_alumno FROM alumnos AS A;
SELECT alumnos.edad "error" FROM alumnos;

SELECT ALL * FROM alumnos;
SELECT * FROM alumnos;

-- DISTINCT --
SELECT DISTINCT Calificacion, edad FROM alumnos;
SELECT Calificacion, edad FROM alumnos;

SELECT DISTINCT edad FROM alumnos;
SELECT edad FROM alumnos;


SELECT nombre, calificacion FROM alumnos ORDER BY calificacion DESC LIMIT 2;
SELECT edad FROM alumnos ORDER BY 1 LIMIT 3;

-- LIMIT --
SELECT * FROM alumnos LIMIT 3 OFFSET 2; 	-- esto busca los proximos 3 a pertir de la fila 2
SELECT * FROM alumnos LIMIT 2,3;				-- lo mismo per en otro modo de escrivirlo

-- WHERE --
SELECT NIP, nombre FROM alumnos WHERE NIP = 15230;
SELECT calificacion FROM alumnos WHERE calificacion > 6 OR edad = 35;
SELECT nombre FROM alumnos WHERE edad > 27 AND calificacion < 27;
SELECT nombre FROM alumnos WHERE edad < 30 AND calificacion < 6 OR nombre = "ALFREDO";		-- (1 and 2) or 3 
SELECT nombre FROM alumnos WHERE edad < 30 AND (calificacion < 6 OR nombre = "ALFREDO");	-- 1 and (2 or 3)


SELECT NIP, Nombre, Edad 
FROM alumnos 
ORDER BY Nombre, Edad;

SELECT NIP, Nombre, Edad 
FROM alumnos 
ORDER BY edad ASC, nombre DESC;

SELECT a.NIP, a. Nombre, A.edad as Su_Edad
FROM Alumnos AS A
ORDER BY A.Edad Desc, a.Nombre;

SELECT NIP, nombre, edad 
FROM alumnos 
ORDER BY 2 DESC;

SELECT NIP, nombre, edad AS Edad_Alumno 
FROM alumnos 
ORDER BY 1 DESC, edad;

SELECT a.nombre, AS nombre_alumno 
FROM alumnos AS a 
WHERE a.edad>27 OR a.calificacion<25
ORDER BY a.nombre DESC;

SELECT * FROM alumnos WHERE edad > 30
ORDER BY 1 DESC, 2 ASC;

SELECT alumnos.*
FROM alumnos
WHERE edad > 20
ORDER BY 3 DESC, 4 ASC;

SELECT *
FROM alumnos
WHERE calificacion IS NULL
ORDER BY 2,3,4;

SELECT * 
FROM alumnos 
WHERE calificacion IS NOT NULL
ORDER BY 2,3,4;

SELECT DISTINCT alumn.calificacion
FROM alumnos AS alumn
ORDER BY alumn. calificacion DESC
SELECT DISTINCT edad
FROM alumnos
ORDER BY 1;

SELECT DISTINCT calificacion, edad
FROM alumnos 
ORDER BY 1,2;

SELECT DISTINCT calificacion, edad
FROM alumnos
WHERE edad > 30 AND calificacion > 6
ORDER BY 1,2;


-- Operaciones --
SELECT 	SUM(importe * 1.1421) AS Total_Libras, 
			YEAR(NOW()) AS Año_Actual,
			Anyo_pedido AS Año_Pedido
FROM pedidos
WHERE Anyo_pedido = YEAR(NOW());

SELECT AVG(unidades_pedidas) AS media_uds_ped, SUM(unidades_pedidas)/COUNT(*) AS media2
FROM pedidos;

SELECT SUM(P.Unidades_Pedidas) AS uds_pedidas, P.Codigo_Articulo AS articulo
FROM pedidos P
GROUP BY P.Codigo_Articulo;
*/

