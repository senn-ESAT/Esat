SELECT e.Nombre, e.apellidos
FROM estudiantes AS e
WHERE anio_escolar = 2022
GROUP BY nota_media;