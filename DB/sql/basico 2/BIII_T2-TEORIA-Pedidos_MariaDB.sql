-- --------------------------------------------------------
-- Host:                         192.168.0.3
-- Versión del servidor:         5.5.33a-MariaDB - mariadb.org binary distribution
-- SO del servidor:              Win32
-- HeidiSQL Versión:             11.2.0.6213
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

-- Volcando estructura para tabla bbdd_esat_2021.pedidos
CREATE TABLE IF NOT EXISTS `pedidos` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `Codigo_Articulo` varchar(50) DEFAULT NULL,
  `Unidades_Pedidas` int(11) DEFAULT NULL,
  `Importe` double DEFAULT NULL,
  `Fecha_Envio` date DEFAULT NULL,
  `Anyo_pedido` char(4) DEFAULT NULL,
  `Cod_Cliente` varchar(50) DEFAULT NULL,
  `Pedido_Online` tinyint(1) DEFAULT NULL COMMENT '1--> Pedido Online',
  `Cod_Pais_Origen` varchar(50) DEFAULT NULL,
  `Cod_Pais_Destino` varchar(50) DEFAULT NULL,
  `Unidades_Devueltas` int(11) DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;

-- Volcando datos para la tabla bbdd_esat_2021.pedidos: ~11 rows (aproximadamente)
/*!40000 ALTER TABLE `pedidos` DISABLE KEYS */;
INSERT INTO `pedidos` (`ID`, `Codigo_Articulo`, `Unidades_Pedidas`, `Importe`, `Fecha_Envio`, `Anyo_pedido`, `Cod_Cliente`, `Pedido_Online`, `Cod_Pais_Origen`, `Cod_Pais_Destino`, `Unidades_Devueltas`) VALUES
	(1, 'CA1', 10, 5.3, '2021-03-04', '2018', 'CL1', 1, 'ESP', 'ESP', 1),
	(2, 'CA1', 12, 5, '2021-03-04', '2018', 'CL2', 0, 'ESP', 'FRA', 2),
	(3, 'CA2', 15, 100, '2020-03-04', '2020', 'CL1', 1, 'ESP', 'ALE', 1),
	(4, 'CA2', 13, 105, '2018-03-04', '2018', 'CL3', 1, 'FRA', NULL, 10),
	(5, 'CA2', 25, 90, '2021-03-04', '2021', 'CL4', 0, 'ESP', 'ESP', 0),
	(6, 'CA3', 6, 20, '2021-01-04', '2021', 'CL5', 1, 'ITA', 'ESP', 6),
	(7, 'CA4', 7, 12.3, '2021-03-04', '2021', 'CL5', 1, 'ESP', 'ITA', 7),
	(8, 'CA1', 21, 4.3, '2020-03-04', '2020', 'CL3', 0, 'ING', 'ALE', 3),
	(9, 'CA5', 35, 10, '2021-03-05', '2021', 'CL2', NULL, NULL, NULL, 0),
	(10, 'CA1', 15, 3.6, '2021-03-05', '2021', 'CL1', 0, 'ESP', 'ESP', 0),
	(11, 'CA5', 5, 10, '2021-03-05', '2021', 'CL2', 1, 'FRA', NULL, 3);
/*!40000 ALTER TABLE `pedidos` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
