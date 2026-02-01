-- --------------------------------------------------------
-- Host:                         172.16.99.14
-- Versión del servidor:         10.6.4-MariaDB - mariadb.org binary distribution
-- SO del servidor:              Win64
-- HeidiSQL Versión:             11.3.0.6295
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

-- Volcando estructura para tabla senn.3_1_usuarios_juegos
CREATE TABLE IF NOT EXISTS `3_1_usuarios_juegos` (
  `id_usuario` char(16) NOT NULL,
  `id_juego` char(16) NOT NULL,
  `fecha_compra` date NOT NULL,
  `precio_compra` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id_usuario`,`id_juego`),
  KEY `FK3` (`id_juego`),
  CONSTRAINT `FK2` FOREIGN KEY (`id_usuario`) REFERENCES `3_1_usuario` (`id_usuario`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `FK3` FOREIGN KEY (`id_juego`) REFERENCES `3_1_juegos` (`id_Juegos`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
3_1_usuario3_1_usuarios_juegos2_1_profesor