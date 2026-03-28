-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Versión del servidor:         10.2.13-MariaDB - mariadb.org binary distribution
-- SO del servidor:              Win64
-- HeidiSQL Versión:             9.4.0.5125
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

-- Volcando estructura para tabla bbdd_2021_t1.estudiantes
DROP TABLE IF EXISTS `estudiantes`;
CREATE TABLE IF NOT EXISTS `estudiantes` (
  `id_estudiante` int(11) NOT NULL,
  `nombre` varchar(50) DEFAULT NULL,
  `apellidos` varchar(50) DEFAULT NULL,
  `anio_escolar` int(11) DEFAULT NULL,
  `nota_media` int(11) DEFAULT NULL,
  `estado_civil` varchar(50) DEFAULT NULL,
  `num_aprobadas` int(11) DEFAULT NULL,
  `num_suspendidas` int(11) DEFAULT NULL,
  `cod_colegio` varchar(16) DEFAULT NULL,
  PRIMARY KEY (`id_estudiante`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Volcando datos para la tabla bbdd_2021_t1.estudiantes: ~27 rows (aproximadamente)
DELETE FROM `estudiantes`;
/*!40000 ALTER TABLE `estudiantes` DISABLE KEYS */;
INSERT INTO `estudiantes` (`id_estudiante`, `nombre`, `apellidos`, `anio_escolar`, `nota_media`, `estado_civil`, `num_aprobadas`, `num_suspendidas`, `cod_colegio`) VALUES
	(2, 'ROSA', ' lopez', 2011, 6, 'c', 4, 5, '1000'),
	(3, 'MARIO', 'gomez', 2013, 7, 's', 2, 3, '1200'),
	(4, 'PEDRO', 'martinez', 2012, 7, 's', 4, 5, '1000'),
	(5, 'ROSA', ' lopez', 2012, 4, 'v', 6, 7, '1000'),
	(6, 'MARIO', 'gomez', 2014, 6, 'c', 6, 3, '2000'),
	(7, 'MANOLO', 'fernandez', 2012, 5, 's', 7, 4, '2000'),
	(8, 'CARLOS', 'garcia', 2011, 10, 'v', 9, 5, '2000'),
	(9, 'JUAN', 'martinez', 2015, 7, 'v', 6, 7, '1000'),
	(10, 'LUIS', ' lopez', 2012, 4, 'd', 3, 6, '1500'),
	(11, 'JOSE', 'gomez', 2013, 6, 'd', 4, 5, '5963'),
	(12, 'MARIA', 'fernandez', 2012, 5, 'd', 9, 6, '2000'),
	(13, 'J. CARLOS', 'garcia', 2012, 10, 'v', 6, 3, '2000'),
	(15, 'ROSA', ' lopez', 2016, 6, 'c', 4, 5, '1000'),
	(16, 'JUAN', 'gomez', 2015, 7, 's', 7, 7, '1200'),
	(17, 'FERNANDO', 'martinez', 2014, 7, 's', 3, 5, '1000'),
	(18, 'INES', ' lopez', 2013, 4, 'd', 4, 6, '1000'),
	(19, 'MARIO', 'gomez', 2017, 6, 'v', 7, 4, '2000'),
	(20, 'GUILLERMO', 'fernandez', 2012, 5, 's', 7, 4, '2000'),
	(21, 'CARLOS', 'garcia', 2015, 10, 's', 9, 5, '2000'),
	(22, 'JUAN', 'martinez', 2015, 7, 'v', 6, 7, '1000'),
	(23, 'LUIS', ' lopez', 2012, 8, 's', 3, 6, '1500'),
	(24, 'ESTHER', 'gomez', 2016, 7, 'd', 4, 5, '5963'),
	(25, 'MARIA', 'fernandez', 2014, 5, 'd', 10, 7, '2000'),
	(26, 'J. CARLOS', 'garcia', 2017, 10, 'v', 6, 4, '2000'),
	(100, 'JUAN', 'lopez', 2018, 7, 'c', 14, 11, '2000'),
	(101, 'ANTONIO', 'martinez', 2019, 8, 's', 6, 6, '2100'),
	(102, 'ANTONIO', 'martinez', 2018, 7, 'c', 8, 9, '2200');
/*!40000 ALTER TABLE `estudiantes` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
