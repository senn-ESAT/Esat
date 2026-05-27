-- 1. Seleccionar nombre de usuario, país origen y el total inscripciones realizadas por
-- cada usuario en todos los campeonatos, pero solo de los usuarios desbloqueados y
-- cuya suma de puntos de ganados sea superior a 1000, ordenar por total puntos
-- ganados y por país descendentemente.


SELECT U.USR_NOMBRE, U.USR_PAIS_ORIGEN, U.USR_CAMPEONATOS_JUGADOS
FROM USUARIOS AS U
WHERE U.USR_PUNTOS_GANADOS > 1000 AND U.USR_FECHA_DESBLOQ < NOW()
ORDER BY U.USR_PUNTOS_GANADOS DESC, U.USR_PAIS_ORIGEN;


-- 2.Seleccionar las partidas que están en estado de pausadas durante más de un
-- mes. Indicar el nombre de los usuarios que intervienen en cada partida, la fecha de
-- comienzo de la partida y el nombre de la configuración de la misma.


SELECT U.USR_NOMBRE, P.PART_FECHA_HORA_FIN, CP.CP_NOMBRE_CONFIG
FROM USUARIOS AS U, PARTIDAS AS P, config_partidas AS CP, partidas_usuarios AS PU
WHERE PU.PU_USR_ID = U.USR_ID 
AND PU.PU_PART_ID = P.PART_ID 
AND P.PART_ID_CONFIG_PART = CP.CP_ID
AND P.PART_FECHA_HORA_INICIO < NOW() - INTERVAL 1 MONTH
AND P.PART_FECHA_HORA_FIN IS NULL;


-- 3.Obtener para cada usuario que ha creado un campeonato, los puntos máximos,
-- mínimos, la media de los puntos y la suma de inscripciones de todos sus
-- campeonatos. Seleccionar solo aquellos registros cuyo valor de puntos ganador del
-- campeonato sea superior a la media de puntos de ganador de todos los
-- campeonatos.


SELECT MAX(CAMP_PUNTOS_GANADOS), 
       MIN(CAMP_PUNTOS_GANADOS), 
       AVG(CAMP_PUNTOS_GANADOS),
       SUM(CAMP_TOTAL_INSCRIPTORES)
FROM CAMPEONATOS WHERE CAMP_PUNTOS_GANADOS > 
    (SELECT AVG(CAMP_PUNTOS_GANADOS) FROM CAMPEONATOS)
GROUP BY CAMP_USR_CREADOR_CAMP;


-- 4.Indicar que jugadores se han apuntado a mas campeonatos, indicar el email del
-- usuario y el número de veces que se ha apuntado, ordenar por cantidad de veces
-- que se han apuntado.


SELECT U.USR_EMAIL, COUNT(*) AS apariciones
FROM USUARIOS AS U, PARTICIPANTES_CAMPEONATOS AS P
WHERE U.USR_ID = P.PTC_USR_ID
GROUP BY U.USR_ID
ORDER BY apariciones DESC LIMIT 1;


-- esta, la 5 se tiene que hacer de 2 formas
-- 5.Indicar en que campeonatos no se ha apuntado ningún participante.

SELECT CAMP_NOMBRE_CAMPEONATO
FROM CAMPEONATOS
WHERE CAMP_TOTAL_INSCRIPTORES = 0;

SELECT C.CAMP_NOMBRE_CAMPEONATO
FROM CAMPEONATOS AS C, PARTICIPANTES_CAMPEONATOS AS P
WHERE C.CAMP_ID != P.PTC_CAMP_ID
ORDER BY C.CAMP_ID DESC LIMIT 1;


-- 6.Cuales son las configuraciones de partida menos seleccionadas y cuales las que
-- más. Mostrar Id configuración, nombre de configuración y total de veces
-- seleccionada ordenar por total de veces y por nombre.


SELECT CP.CP_ID, CP.CP_NOMBRE_CONFIG, count(*) AS veces
FROM CONFIG_PARTIDAS AS CP, PARTIDAS AS P
WHERE CP.CP_ID = P.PART_ID_CONFIG_PART
GROUP BY CP.CP_ID
ORDER BY veces DESC, CP.CP_NOMBRE_CONFIG ASC;


-- 7. Indicar que jugadores han jugado como mínimo 5 campeonatos, pero no han
-- jugado ninguna partida online. Ordenar por Número de campeonatos
-- descendentemente y por nombre de usuario


SELECT U.USR_NOMBRE
FROM USUARIOS AS U
WHERE U.USR_PARTIDAS_JUGADAS = 0
AND U.USR_CAMPEONATOS_JUGADOS > 5
ORDER BY U.USR_CAMPEONATOS_JUGADOS DESC;



-- 8.Cuales son los jugadores que más puntos han ganado y cuales los que menos de
-- los jugadores que hayan jugado como mínimo 10 partidas, que no tengan partidas
-- en suspensión y que hayan ganado algún campeonato. Mostrar Email jugador, suma
-- total de puntos obtenidos en los campeonatos, total de partidas jugadas online,
-- número total de campeonatos ganados y el número total de campeonatos jugados.

-- 9.Para cada país indicar que jugadores han ganado más partidas y cuales menos
-- partidas, mostrar los campos país origen, nombre usuario, partidas ganadas,
-- partidas jugadas.


SELECT U.USR_PAIS_ORIGEN, U.USR_NOMBRE, COUNT(*) as ganados
FROM USUARIOS AS U, PARTIDAS_USUARIOS AS PU
WHERE U.USR_ID = PU.PU_USR_ID
AND PU.PU_POSICION_FINAL_EN_PARTIDA = 1;



-- 10. Insertar un registro en la tabla de campeonato.

-- 11. Modificar el registro creado en el punto 10.

-- 12. Eliminar el registro creado en el punto 11