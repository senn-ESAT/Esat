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
*/
-- WHERE --
SELECT NIP, nombre FROM alumnos WHERE NIP = 15230;
SELECT calificacion FROM alumnos WHERE calificacion > 6 OR edad = 35;
SELECT nombre FROM alumnos WHERE edad > 27 AND calificacion < 27;
SELECT nombre FROM alumnos WHERE edad < 30 AND calificacion < 6 OR nombre = "ALFREDO";		-- (1 and 2) or 3 
SELECT nombre FROM alumnos WHERE edad < 30 AND (calificacion < 6 OR nombre = "ALFREDO");	-- 1 and (2 or 3)
