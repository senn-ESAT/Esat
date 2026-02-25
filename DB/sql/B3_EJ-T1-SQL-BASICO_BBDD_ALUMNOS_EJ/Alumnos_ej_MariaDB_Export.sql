DROP TABLE IF EXISTS `alumnos_ej`;
CREATE TABLE IF NOT EXISTS `alumnos_ej` (
  `NIP` int(11) NOT NULL,
  `NOMBRE` varchar(50) DEFAULT NULL,
  `CALIFICACION` double DEFAULT NULL,
  `CODIGO_POSTAL` varchar(6) DEFAULT NULL,
  `EDAD` int(11) DEFAULT NULL,
  PRIMARY KEY (`NIP`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `alumnos_ej` (`NIP`, `NOMBRE`, `CALIFICACION`, `CODIGO_POSTAL`, `EDAD`) VALUES
	(1, 'PEDRO', 8, '46001', 26),
	(2, 'JUAN', 7, '46001', 39),
	(3, 'ANTONIO', 7, '46022', 40),
	(4, 'MARCOS', 8, '46001', 42),
	(5, 'LUIS', 5, '46198', 40),
	(6, 'MARIO', 9, '46198', 25),
	(7, 'JOSE', 4, '46198', 18),
	(8, 'MIGUEL', 7, '46198', 18),
	(9, 'ANGEL', 6, '46018', 21),
	(10, 'GUILLERMO', 8, '46018', 23),
	(11, 'ALFREDO', 2, '46022', 28),
	(12, 'MANOLO', 6, '46900', 24),
	(13, 'MARIANO', 9, '8563', NULL),
	(14, 'JOSE LUIS', 4, '3562', 34),
	(15, 'MIGUEL ANGEL', 7, '5636', 19),
	(16, 'PEDRO M', 6, '2001', NULL),
	(17, 'ALFREDO', 3, '2006', 25),
	(18, 'ANTONIO A', 9, '16204', 36),
	(19, 'MARCOS M', 6, '15635', NULL),
	(20, 'LUIalumnos_ejalumnos_ejS L', 5, '46023', 21),
	(21, 'MARIO M', 9, '3659', 25),
	(22, 'JOSE J', 4, '2463', 42),
	(23, 'MIGUEL A', 7, '46001', 45),
	(24, 'ANGEL A', 6, '46001', 26),
	(25, 'GUILLERMO G', 8, NULL, 36),
	(26, 'ALFREDO', 2, '15635', 22),
	(27, 'MANOLO M', 6, '15635', 23),
	(28, 'MARIANO M', 9, '16204', 16),
	(30, 'MIGUEL ANGEL MA', 7, '46198', 37),
	(15230, 'JOSE LUIS JL', 4, '16204', 18);
senn