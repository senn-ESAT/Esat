-- Users
/*
INSERT INTO usuarios (USR_NOMBRE, USR_EMAIL, USR_PASSWORD, USR_PAIS_ORIGEN, USR_PARTIDAS_JUGADAS, USR_CAMPEONATOS_JUGADOS, USR_PARTIDAS_GANADAS, USR_PUNTOS_GANADOS, USR_FECHA_DESBLOQ)
VALUES 
 ('Matias', 'mattias.senn@gmail.com', '7997', 'ARG', 38, 33, 23, 1150, '2025-11-11'),
 ('Valentin', 'valentinfrl@gmail.com', '1234', 'ARG', 50, 7, 35, 100, '2024-11-11'), 
 ('Andrew', 'ANDYSANCH@gmail.com', '753159', 'ESP', 75, 38, 62, 1250, '2025-03-03'), 
 ('Lucia', 'lucy@gmail.com', '69996', 'ESP', 158, 48, 133, 10500, '2019-08-06'), 
 ('Beltran', 'cbob@gmail.com', '5333550', 'ESP', 55, 10, 35, 750, '2024-12-23'), 
 ('Pippo', 'pippolino.magico@gmail.com', '7913', 'ITA', 759, 203, 588, 31750, '2017-07-04'), 
 ('Gasly', 'gasgasgas@gmail.com', '753159', 'FRA', 20, 7, 18, 7580, '2025-11-11'), 
 ('Lawson', 'lila@gmail.com', '7997', 'AUS', 23, 20, 15, 1000, '2026-11-11'), 
 ('Franco', 'fracol@gmail.com', '4343', 'ARG', 30, 15, 20, 2075, '2025-12-12'), 
 ('Ocon', 'estybesty@gmail.com', '0033', 'FRA', 20, 7, 15, 1780, '2027-01-01'),
 ('George', 'SCMP.COMP@gmail.com', '4654', 'ENG', 0, 33, 0, 1150, '2025-11-11'),
 ('Hans', 'CMPAMA@gmail.com', '85245379', 'GER', 0, 13, 0, 1150, '2025-11-11'),
 ('Dimitry', 'AKACOMP@gmail.com', '75148', 'RUS', 0, 2, 0, 1150, '2025-11-11');
 
-- Config Partidas
INSERT INTO config_partidas (CP_TIEMPO_ESPERA, CP_NUM_PARTICIPANTES, CP_PUNTOS_GANADOR, CP_NOMBRE_CONFIG)
VALUES
(60.0, 2, 100, 'RegularVersus'),
(60.0, 3, 100, 'Regular3V'),
(60.0, 4, 100, 'Regular4V'),
(30.0, 2, 100, 'SprintVersus'),
(30.0, 3, 100, 'Sprint3V'),
(30.0, 4, 100, 'Sprint4V'),
(10.0, 2, 100, 'CaosVersus'),
(10.0, 3, 100, 'Caos3V'),
(10.0, 4, 100, 'Caos4V'),
(60.0, 2, 50, 'QuickVersus'),
(60.0, 3, 50, 'Quick3V'),
(60.0, 4, 50, 'Quick4V');



-- Partidas
INSERT INTO partidas (PART_FECHA_HORA_INICIO, PART_FECHA_HORA_FIN, PART_ID_CONFIG_PART, PART_ESTADO, PART_TURNO_USUARIO)
VALUES 
('2025-12-12 14:30:30', NULL, 2, 0, 1),							-- 1
('2025-11-12 15:10:00', '2025-11-14 17:00:00', 12, 1, 0),	-- 2
('2026-02-05 22:10:00', NULL, 1, 0, 1),							-- 3
('2026-02-05 22:10:00', NULL, 1, 1, 1),							-- 4
('2026-02-05 22:10:00', '2026-03-05', 1, 1, 1),					-- 5
('2022-11-12 15:10:00', '2023-11-14 17:00:00', 6, 1, 1),		-- 6
('2024-11-1 15:10:00', '2024-11-14 17:00:00', 11, 1, 1),		-- 7
('2026-02-05 22:10:00', '2026-02-07', 1, 1, 1),					-- 8
('2026-02-05 22:10:00', '2026-03-05', 1, 1, 1),					-- 9
('2022-11-12 15:10:00', '2023-11-14 17:00:00', 6, 1, 1),		-- 10
('2024-11-1 15:10:00', '2024-11-14 17:00:00', 11, 1, 1),		-- 11
('2026-02-05 22:10:00', '2026-02-07', 1, 1, 1),					-- 12
('2026-02-05 22:10:00', '2026-03-05', 1, 1, 1),					-- 13
('2022-11-12 15:10:00', '2023-11-14 17:00:00', 6, 1, 1),		-- 14
('2024-11-1 15:10:00', '2024-11-14 17:00:00', 11, 1, 1),		-- 15
('2026-02-05 22:10:00', '2026-02-07', 1, 1, 1),					-- 16
('2026-02-05 22:10:00', '2026-03-05', 1, 1, 1),					-- 17
('2022-11-12 15:10:00', '2023-11-14 17:00:00', 6, 1, 1),		-- 18
('2024-11-1 15:10:00', '2024-11-14 17:00:00', 11, 1, 1),		-- 19
('2026-02-05 22:10:00', '2026-02-07', 1, 1, 1),					-- 20
('2026-02-05 22:10:00', '2026-03-05', 1, 1, 1);					-- 21

-- PARTIDAS_USUARIOS
INSERT INTO partidas_usuarios(PU_PART_ID, PU_USR_ID, PU_PUNTOS_OBTENIDOS, PU_POSICION_FINAL_EN_PARTIDA, PU_POSICION_EN_TABLERO)
VALUES 
(1, 1, 50, NULL, 1),
(1, 3, 80, NULL, 2),
(1, 6, 45, NULL, 3),

(2, 1, 100, 1, 1),
(2, 5, 30, 2, 2),
(2, 8, 43,3, 3),
(2, 10, 25, 4, 4),

(3, 6, 60, NULL, 1),
(3, 9, 40, NULL, 2),

(4, 2, 90, NULL, 1),
(4, 6, 60, NULL, 2),
(4, 7, 55, NULL, 3),
(4, 10, 30, NULL, 4),

(5, 1, 0, 4, 1),
(5, 4, 60, 3, 2),
(5, 7, 80, 2, 3),
(5, 9, 100, 1, 4),

(6, 2, 50, 1, 1),
(6, 5, 35, 2, 2),
(6, 3, 30, 3, 3),

(7, 1, 0, 4, 1),
(7, 4, 60, 3, 2),
(7, 7, 80, 2, 3),
(7, 9, 100, 1, 4),

(8, 2, 50, 1, 1),
(8, 5, 35, 2, 2),
(8, 3, 30, 3, 3),

(9, 1, 0, 4, 1),
(9, 4, 60, 3, 2),
(9, 7, 80, 2, 3),
(9, 9, 100, 1, 4),

(10, 2, 50, 1, 1),
(10, 5, 35, 2, 2),
(10, 3, 30, 3, 3),

(11, 4, 0, 4, 1),
(11, 3, 60, 3, 2),
(11, 7, 80, 2, 3),
(11, 9, 100, 1, 4),

(12, 7, 50, 1, 1),
(12, 5, 35, 2, 2),
(12, 3, 30, 3, 3),

(13, 1, 0, 4, 1),
(13, 4, 60, 3, 2),
(13, 7, 80, 2, 3),
(13, 9, 100, 1, 4),

(14, 2, 50, 1, 1),
(14, 5, 35, 2, 2),
(14, 3, 30, 3, 3),

(15, 10, 0, 4, 1),
(15, 4, 60, 3, 2),
(15, 7, 80, 2, 3),
(15, 3, 100, 1, 4),

(16, 7, 50, 1, 1),
(16, 5, 35, 2, 2),
(16, 3, 30, 3, 3),

(17, 2, 0, 4, 1),
(17, 4, 60, 3, 2),
(17, 7, 80, 2, 3),
(17, 10, 100, 1, 4),

(18, 1, 50, 1, 1),
(18, 5, 35, 2, 2),
(18, 3, 30, 3, 3),

(20, 6, 0, 4, 1),
(20, 4, 60, 3, 2),
(20, 7, 80, 2, 3),
(20, 9, 100, 1, 4),

(21, 5, 50, 1, 1),
(21, 4, 35, 2, 2),
(21, 3, 30, 3, 3);


-- Cameponatos
INSERT INTO CAMPEONATOS (	CAMP_FECHA_COMIENZO ,
	CAMP_TOTAL_INSCRIPTORES,
	CAMP_PUNTOS_GANADOS,
	CAMP_NOMBRE_CAMPEONATO,
	CAMP_USR_CREADOR_CAMP,
	CAMP_FECHA_FINALIZACION,
	CAMP_NUM_USR_BLOQUEDOS)
VALUES
('2025-01-10', 8, 500, 'Winter Cup', 1, '2025-01-20', 1),
('2025-02-15', 6, 1200, 'Pro League', 1, '2025-02-28', 0),
('2025-03-01', 10, 300, 'Spring Masters', 3, '2025-03-10', 2),
('2025-04-05', 4, 900, 'Ultimate Arena', 3, '2025-04-15', 1),
('2025-05-10', 8, 1500, 'Champions Clash', 6, '2025-05-25', 0),
('2025-06-01', 6, 200, 'Quick Tournament', 6, '2025-06-05', 0),
('2025-07-07', 10, 2500, 'World Battle', 4, '2025-07-30', 3),
('2025-08-10', 7, 400, 'Summer Cup', 2, '2025-08-20', 1),
('2026-01-10', 0, 400, 'Exclusive CUP', 2, '2026-01-15', 0),
('2025-01-10', 2, 400, 'SUPER FINAL', 2, '2025-01-10', 0),
('2025-07-07', 10, 2000, 'World Battle 2', 4, '2025-07-30', 3);
*/
-- Participante campeonatos
INSERT INTO PARTICIPANTES_CAMPEONATOS (PTC_CAMP_ID, PTC_USR_ID, PTC_USER_GANADOR_SN)
VALUES
(1, 1, FALSE),
(1, 2, FALSE),
(1, 3, TRUE),
(1, 4, FALSE),
(1, 5, FALSE),
(1, 6, FALSE),
(1, 7, FALSE),
(1, 8, FALSE),
(1, 9, FALSE),

(2, 4, FALSE),
(2, 5, FALSE),
(2, 6, TRUE),
(2, 7, FALSE),
(2, 8, FALSE),
(2, 9, false),

(3, 7, FALSE),
(3, 8, FALSE),
(3, 9, TRUE),
(3, 10, FALSE),
(3, 1, FALSE),
(3, 2, FALSE),
(3, 3, FALSE),
(3, 4, FALSE),
(3, 5, FALSE),
(3, 6, FALSE),

(4, 10, FALSE),
(4, 1, FALSE),
(4, 2, TRUE),
(4, 5, FALSE),

(5, 3, FALSE),
(5, 4, FALSE),
(5, 5, TRUE),
(5, 6, FALSE),
(5, 7, FALSE),
(5, 8, FALSE),
(5, 9, FALSE),
(5, 10, FALSE),

(6, 6, FALSE),
(6, 7, FALSE),
(6, 8, TRUE),
(6, 9, FALSE),
(6, 10, FALSE),
(6, 1, FALSE),

(7, 9, FALSE),
(7, 10, FALSE),
(7, 1, TRUE),
(7, 2, FALSE),
(7, 3, FALSE),
(7, 4, FALSE),
(7, 5, FALSE),
(7, 6, FALSE),
(7, 7, FALSE),
(7, 8, FALSE),

(8, 2, FALSE),
(8, 3, FALSE),
(8, 4, TRUE),
(8, 5, FALSE),
(8, 6, FALSE),
(8, 7, FALSE),
(8, 8, FALSE),

-- 9 vacio
(NULL, NULL, NULL),

(10, 1, TRUE),
(10, 6, FALSE),

(11, 9, FALSE),
(11, 10, FALSE),
(11, 1, FALSE),
(11, 2, FALSE),
(11, 3, FALSE),
(11, 4, FALSE),
(11, 5, FALSE),
(11, 6, TRUE),
(11, 7, FALSE),
(11, 8, FALSE);
