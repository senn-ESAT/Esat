-- --------------------------------------------------------
-- Host:                         192.168.0.3
-- Versión del servidor:         5.5.33a-MariaDB - mariadb.org binary distribution
-- SO del servidor:              Win32
-- HeidiSQL Versión:             10.3.0.5771
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

-- Volcando estructura para tabla esat.estudiantes
CREATE TABLE IF NOT EXISTS `estudiantes` (
  `id_estudiante` int(11) DEFAULT NULL,
  `nombre` varchar(50) DEFAULT NULL,
  `apellidos` varchar(50) DEFAULT NULL,
  `anio_escolar` int(11) DEFAULT NULL,
  `nota_media` int(11) DEFAULT NULL,
  `estado_civil` varchar(50) DEFAULT NULL,
  `num_aprobadas` int(11) DEFAULT NULL,
  `num_suspendidas` int(11) DEFAULT NULL,
  `cod_colegio` varchar(16) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Volcando datos para la tabla esat.estudiantes: ~26 rows (aproximadamente)
/*!40000 ALTER TABLE `estudiantes` DISABLE KEYS */;
INSERT INTO `estudiantes` (`id_estudiante`, `nombre`, `apellidos`, `anio_escolar`, `nota_media`, `estado_civil`, `num_aprobadas`, `num_suspendidas`, `cod_colegio`) VALUES
	(1, 'PEDRO', 'MARTINEZ', 2023, 8, 'c', 3, 0, '2330'),
	(2, 'ROSA', ' LOPEZ', 2021, 6, 'c', 4, 1, '1000'),
	(3, 'MARIO', 'GOMEZ', 2023, 7, 's', 2, 0, '1200'),
	(4, 'PEDRO', 'MARTINEZ', 2022, 7, 's', 4, 3, '1000'),
	(5, 'ROSA', ' LOPEZ', 2022, 4, 'd', 6, 4, '1000'),
	(6, 'MARIO', 'GOMEZ', 2024, 6, 'c', 2, 1, '2000'),
	(7, 'MANOLO', 'FERNANDEZ', 2022, 5, 's', 3, 2, '2000'),
	(8, 'CARLOS', 'GARCIA', 2021, 10, 'v', 5, 0, '2000'),
	(9, 'JUAN', 'MARTINEZ', 2023, 7, 'v', 6, 3, '1000'),
	(10, 'LUIS', ' LOPEZ', 2022, 4, 'd', 3, 4, '1500'),
	(11, 'JOSE', 'GOMEZ', 2023, 6, 'd', 4, 1, '5963'),
	(12, 'MARIA', 'FERNANDEZ', 2022, 5, 'd', 2, 3, '2000'),
	(13, 'J. CARLOS', 'GARCIA', 2022, 10, 'v', 2, 0, '2000'),
	(14, 'PEDRO', 'MARTINEZ', 2023, 6, 's', 3, 0, '2330'),
	(15, 'ROSA', ' LOPEZ', 2023, 6, 'c', 4, 1, '1000'),
	(16, 'JUAN', 'GOMEZ', 2024, 7, 's', 7, 0, '1200'),
	(17, 'FERNANDO', 'MARTINEZ', 2024, 7, 's', 3, 3, '1000'),
	(18, 'INES', ' LOPEZ', 2023, 4, 'd', 4, 4, '1000'),
	(19, 'MARIO', 'GOMEZ', 2023, 6, 'v', 3, 1, '2000'),
	(20, 'GUILLERMO', 'FERNANDEZ', 2022, 5, 's', 3, 2, '2000'),
	(21, 'CARLOS', 'GARCIA', 2023, 10, 'S', 5, 0, '2000'),
	(22, 'JUAN', 'MARTINEZ', 2024, 7, 'v', 6, 3, '1000'),
	(23, 'LUIS', ' LOPEZ', 2022, 8, 'S', 3, 4, '1500'),
	(24, 'ESTHER', 'GOMEZ', 2023, 7, 'd', 4, 1, '5963'),
	(25, 'MARIA', 'FERNANDEZ', 2024, 5, 'd', 6, 2, '2000'),
	(26, 'J. CARLOS', 'GARCIA', 2023, 10, 'v', 2, 4, '2000');
/*!40000 ALTER TABLE `estudiantes` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
