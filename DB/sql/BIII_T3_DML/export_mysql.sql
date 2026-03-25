-- --------------------------------------------------------
-- Host:                         192.168.0.3
-- Versión del servidor:         5.5.33a-MariaDB - mariadb.org binary distribution
-- SO del servidor:              Win32
-- HeidiSQL Versión:             11.1.0.6116
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

-- Volcando estructura para tabla esat.resumen_almacen
DROP TABLE IF EXISTS `resumen_almacen`;
CREATE TABLE IF NOT EXISTS `resumen_almacen` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `Nombre_almacen` varchar(50) DEFAULT NULL,
  `Ventas` double DEFAULT NULL,
  `Año` char(4) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Volcando datos para la tabla esat.resumen_almacen: ~0 rows (aproximadamente)
/*!40000 ALTER TABLE `resumen_almacen` DISABLE KEYS */;
/*!40000 ALTER TABLE `resumen_almacen` ENABLE KEYS */;

-- Volcando estructura para tabla esat.ventas_almacen
DROP TABLE IF EXISTS `ventas_almacen`;
CREATE TABLE IF NOT EXISTS `ventas_almacen` (
  `Id` int(11) NOT NULL AUTO_INCREMENT,
  `Nombre_Almacen` varchar(50) DEFAULT NULL,
  `Ventas` int(11) DEFAULT NULL,
  `Fecha` date DEFAULT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=latin1;

-- Volcando datos para la tabla esat.ventas_almacen: ~5 rows (aproximadamente)
/*!40000 ALTER TABLE `ventas_almacen` DISABLE KEYS */;
INSERT INTO `ventas_almacen` (`Id`, `Nombre_Almacen`, `Ventas`, `Fecha`) VALUES
	(1, 'Alicante', 1500, '2012-01-06'),
	(2, 'Valencia', 250, '2018-01-07'),
	(3, 'Sevilla', 300, '2013-01-08'),
	(4, 'Valencia', 700, '2012-01-08');
/*!40000 ALTER TABLE `ventas_almacen` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
