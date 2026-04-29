-- 1. Seleccionar nombre de usuario, país origen y el total inscripciones realizadas por
-- cada usuario en todos los campeonatos, pero solo de los usuarios desbloqueados y
-- cuya suma de puntos de ganados sea superior a 1000, ordenar por total puntos
-- ganados y por país descendentemente.


SELECT U.USR_NOMBRE, U.USR_PAIS_ORIGEN
FROM USUARIOS AS U;


-- 2.Seleccionar las partidas que están en estado de pausadas durante más de un
-- mes. Indicar el nombre de los usuarios que intervienen en cada partida, la fecha de
-- comienzo de la partida y el nombre de la configuración de la misma.


-- 3.Obtener para cada usuario que ha creado un campeonato, los puntos máximos,
-- mínimos, la media de los puntos y la suma de inscripciones de todos sus
-- campeonatos. Seleccionar solo aquellos registros cuyo valor de puntos ganador del
-- campeonato sea superior a la media de puntos de ganador de todos los
-- campeonatos.



-- 4.Indicar que jugadores se han apuntado a mas campeonatos, indicar el email del
-- usuario y el número de veces que se ha apuntado, ordenar por cantidad de veces
-- que se han apuntado.



-- 5.Indicar en que campeonatos no se ha apuntado ningún participante.

-- 6.Cuales son las configuraciones de partida menos seleccionadas y cuales las que
-- más. Mostrar Id configuración, nombre de configuración y total de veces
-- seleccionada ordenar por total de veces y por nombre.

-- 7. Indicar que jugadores han jugado como mínimo 5 campeonatos, pero no han
-- jugado ninguna partida online. Ordenar por Número de campeonatos
-- descendentemente y por nombre de usuario

-- 8.Cuales son los jugadores que más puntos han ganado y cuales los que menos de
-- los jugadores que hayan jugado como mínimo 10 partidas, que no tengan partidas
-- en suspensión y que hayan ganado algún campeonato. Mostrar Email jugador, suma
-- total de puntos obtenidos en los campeonatos, total de partidas jugadas online,
-- número total de campeonatos ganados y el número total de campeonatos jugados.

-- 9.Para cada país indicar que jugadores han ganado más partidas y cuales menos
-- partidas, mostrar los campos país origen, nombre usuario, partidas ganadas,
-- partidas jugadas.


-- 10. Insertar un registro en la tabla de campeonato.

-- 11. Modificar el registro creado en el punto 10.

-- 12. Eliminar el registro creado en el punto 11