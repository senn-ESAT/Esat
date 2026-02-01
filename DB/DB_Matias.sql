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

-- Volcando estructura para tabla senn.1_1_asunto
CREATE TABLE IF NOT EXISTS `1_1_asunto` (
  `numexp` bigint(20) NOT NULL,
  `dnicli` char(16) NOT NULL,
  `fecha_ini` date NOT NULL,
  `fecha_fin` datetime DEFAULT NULL,
  `estado` char(1) NOT NULL,
  `observaciones` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`numexp`),
  UNIQUE KEY `fecha_ini` (`fecha_ini`) USING BTREE,
  UNIQUE KEY `dnicli` (`dnicli`),
  CONSTRAINT `FK1_1_asunto_1_1_cliente` FOREIGN KEY (`dnicli`) REFERENCES `1_1_cliente` (`dnicli`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_1_asunto_proc
CREATE TABLE IF NOT EXISTS `1_1_asunto_proc` (
  `numexp` bigint(20) NOT NULL,
  `dniproc` char(16) NOT NULL,
  PRIMARY KEY (`numexp`),
  UNIQUE KEY `dniproc` (`dniproc`),
  CONSTRAINT `FK1_1_1_asunto_proc` FOREIGN KEY (`numexp`) REFERENCES `1_1_asunto` (`numexp`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `FK2_1_1_asunto_proc` FOREIGN KEY (`dniproc`) REFERENCES `1_1_procurador` (`dniproc`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_1_cliente
CREATE TABLE IF NOT EXISTS `1_1_cliente` (
  `dnicli` char(16) NOT NULL,
  `nombre` varchar(25) NOT NULL,
  `direccion` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`dnicli`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_1_procurador
CREATE TABLE IF NOT EXISTS `1_1_procurador` (
  `dniproc` char(16) NOT NULL,
  `nombre` varchar(25) NOT NULL,
  `direccion` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`dniproc`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_2_concesionario
CREATE TABLE IF NOT EXISTS `1_2_concesionario` (
  `codigo` char(16) NOT NULL,
  `nombre` varchar(50) NOT NULL,
  `telefono` char(16) NOT NULL,
  `email` varchar(50) NOT NULL,
  `direccion` varchar(50) NOT NULL,
  PRIMARY KEY (`codigo`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_2_proprietario
CREATE TABLE IF NOT EXISTS `1_2_proprietario` (
  `dni` char(16) NOT NULL,
  `nombre` varchar(25) NOT NULL,
  `telefono` char(16) NOT NULL,
  `email` varchar(50) NOT NULL,
  `direccion` varchar(50) NOT NULL,
  PRIMARY KEY (`dni`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_2_vehiculo
CREATE TABLE IF NOT EXISTS `1_2_vehiculo` (
  `matricula` char(8) NOT NULL,
  `codigo_marca` char(16) NOT NULL,
  `nombre_marca` varchar(50) NOT NULL,
  `codigo_modelo` char(16) NOT NULL,
  `nombre_modelo` varchar(50) NOT NULL,
  `fecha_compra` date NOT NULL,
  `importe_veiculo` int(11) NOT NULL,
  `codigo_concesionario` char(16) NOT NULL,
  `dni_propietario` char(16) NOT NULL,
  `nombre_propietario` varchar(25) NOT NULL,
  `telefono_propietario` char(16) NOT NULL,
  PRIMARY KEY (`matricula`),
  KEY `FK1_1_2_vehiculo` (`codigo_concesionario`),
  CONSTRAINT `FK1_1_2_vehiculo` FOREIGN KEY (`codigo_concesionario`) REFERENCES `1_2_concesionario` (`codigo`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_3_actividad
CREATE TABLE IF NOT EXISTS `1_3_actividad` (
  `cod_act` int(11) NOT NULL,
  `nombre` varchar(50) NOT NULL,
  `descripcion` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`cod_act`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_3_cooperante
CREATE TABLE IF NOT EXISTS `1_3_cooperante` (
  `dni` char(16) NOT NULL,
  `nombre` varchar(50) NOT NULL,
  `edad` int(3) DEFAULT NULL,
  `enseña` int(1) DEFAULT NULL,
  `aprende` int(1) DEFAULT NULL,
  PRIMARY KEY (`dni`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_3_necesita
CREATE TABLE IF NOT EXISTS `1_3_necesita` (
  `cod_pais` int(3) NOT NULL,
  `cod_act` int(11) NOT NULL,
  `urgencia` varchar(50) NOT NULL,
  PRIMARY KEY (`cod_pais`,`cod_act`),
  KEY `FK2_1_3_necesita` (`cod_act`),
  CONSTRAINT `FK1_1_3_necesita` FOREIGN KEY (`cod_pais`) REFERENCES `1_3_pais` (`cod_pais`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `FK2_1_3_necesita` FOREIGN KEY (`cod_act`) REFERENCES `1_3_actividad` (`cod_act`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_3_pais
CREATE TABLE IF NOT EXISTS `1_3_pais` (
  `cod_pais` int(3) NOT NULL,
  `nombre` varchar(50) NOT NULL,
  `problemas` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`cod_pais`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_3_viajar
CREATE TABLE IF NOT EXISTS `1_3_viajar` (
  `dni` char(16) NOT NULL,
  `cod_pais` int(3) NOT NULL,
  `fecha` date NOT NULL,
  PRIMARY KEY (`dni`,`cod_pais`,`fecha`),
  KEY `FK_1_3_viajar_1_3_pais` (`cod_pais`),
  CONSTRAINT `FK_1_3_viajar_1_3_cooperante` FOREIGN KEY (`dni`) REFERENCES `1_3_cooperante` (`dni`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `FK_1_3_viajar_1_3_pais` FOREIGN KEY (`cod_pais`) REFERENCES `1_3_pais` (`cod_pais`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_4_alquilado
CREATE TABLE IF NOT EXISTS `1_4_alquilado` (
  `nif` char(9) NOT NULL,
  `moroso` char(1) NOT NULL,
  PRIMARY KEY (`nif`),
  CONSTRAINT `FK_1_4_alquilado_1_4_personas` FOREIGN KEY (`nif`) REFERENCES `1_4_personas` (`nif`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_4_inmueble
CREATE TABLE IF NOT EXISTS `1_4_inmueble` (
  `codigo` char(6) NOT NULL,
  `dir` varchar(30) NOT NULL,
  `tipo` varchar(10) NOT NULL,
  `prop` char(50) NOT NULL DEFAULT '',
  `alq` char(50) NOT NULL DEFAULT '',
  `fecha_alta` date NOT NULL,
  PRIMARY KEY (`codigo`),
  UNIQUE KEY `dir` (`dir`),
  KEY `FK_1_4_inmueble_1_4_alquilado` (`alq`),
  KEY `FK_1_4_inmueble_1_4_proprietario` (`prop`),
  CONSTRAINT `FK_1_4_inmueble_1_4_alquilado` FOREIGN KEY (`alq`) REFERENCES `1_4_alquilado` (`nif`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `FK_1_4_inmueble_1_4_proprietario` FOREIGN KEY (`prop`) REFERENCES `1_4_proprietario` (`nif`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_4_personas
CREATE TABLE IF NOT EXISTS `1_4_personas` (
  `nif` char(9) NOT NULL,
  `nombre` varchar(40) NOT NULL,
  `dir` varchar(30) NOT NULL,
  PRIMARY KEY (`nif`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_4_proprietario
CREATE TABLE IF NOT EXISTS `1_4_proprietario` (
  `nif` char(8) NOT NULL,
  `categoria` varchar(16) NOT NULL,
  PRIMARY KEY (`nif`),
  CONSTRAINT `FK_1_4_proprietario_1_4_personas` FOREIGN KEY (`nif`) REFERENCES `1_4_personas` (`nif`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_4_reserva
CREATE TABLE IF NOT EXISTS `1_4_reserva` (
  `numero` int(11) NOT NULL,
  `codigo` tinytext NOT NULL,
  `nif` char(50) NOT NULL DEFAULT '0',
  `fecha_ini` date NOT NULL,
  `fecha_fin` date DEFAULT NULL,
  PRIMARY KEY (`numero`),
  KEY `FK_1_4_reserva_1_4_personas` (`nif`),
  CONSTRAINT `FK_1_4_reserva_1_4_personas` FOREIGN KEY (`nif`) REFERENCES `1_4_personas` (`nif`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_5_barco
CREATE TABLE IF NOT EXISTS `1_5_barco` (
  `matricula` char(16) NOT NULL,
  `dnisocio` char(16) NOT NULL,
  `nombre` varchar(25) NOT NULL,
  `amarre` int(11) NOT NULL,
  `cuota` decimal(8,2) unsigned DEFAULT NULL,
  PRIMARY KEY (`matricula`),
  UNIQUE KEY `amarre` (`amarre`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_5_persona
CREATE TABLE IF NOT EXISTS `1_5_persona` (
  `dni` char(16) NOT NULL,
  `nombre` varchar(25) NOT NULL,
  `direccion` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`dni`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_5_salida
CREATE TABLE IF NOT EXISTS `1_5_salida` (
  `matricula` char(16) NOT NULL,
  `fecha_hora` datetime NOT NULL,
  `destino` varchar(50) NOT NULL,
  `dnipatron` char(16) NOT NULL,
  UNIQUE KEY `matricula` (`matricula`),
  UNIQUE KEY `fecha_hora` (`fecha_hora`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.1_5_socio
CREATE TABLE IF NOT EXISTS `1_5_socio` (
  `dnisocio` char(16) NOT NULL,
  `nombre_socio` varchar(25) NOT NULL,
  `direccion_socio` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`dnisocio`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.2_1_alumno
CREATE TABLE IF NOT EXISTS `2_1_alumno` (
  `dni` char(16) NOT NULL,
  `nombre` varchar(50) NOT NULL,
  `edad` int(2) NOT NULL,
  `espe` varchar(12) NOT NULL,
  `prof_pra` char(16) NOT NULL,
  `prof_teo` char(16) NOT NULL,
  PRIMARY KEY (`dni`),
  KEY `fprof_pra` (`prof_pra`),
  KEY `fprof_teo` (`prof_teo`),
  CONSTRAINT `fprof_pra` FOREIGN KEY (`prof_pra`) REFERENCES `2_1_profesor` (`dni`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fprof_teo` FOREIGN KEY (`prof_teo`) REFERENCES `2_1_profesor` (`dni`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.2_1_asiste
CREATE TABLE IF NOT EXISTS `2_1_asiste` (
  `dni` char(16) NOT NULL,
  `cod_tema` char(16) NOT NULL,
  `prof_teo` char(16) NOT NULL,
  `fech_asist` date NOT NULL,
  `hora_ini` time NOT NULL,
  `hora_fin` time NOT NULL,
  `total_horas` float(4,2) NOT NULL,
  PRIMARY KEY (`dni`,`cod_tema`),
  KEY `fcod_tem_asiste` (`cod_tema`),
  KEY `fprof_asiste` (`prof_teo`),
  KEY `fdni_asiste` (`dni`),
  CONSTRAINT `fcod_tem_asiste` FOREIGN KEY (`cod_tema`) REFERENCES `2_1_tema` (`cod_tema`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fdni_asiste` FOREIGN KEY (`dni`) REFERENCES `2_1_alumno` (`dni`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fprof_asiste` FOREIGN KEY (`prof_teo`) REFERENCES `2_1_profesor` (`dni`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.2_1_examen
CREATE TABLE IF NOT EXISTS `2_1_examen` (
  `dni` char(16) NOT NULL,
  `cod_tema` char(16) NOT NULL,
  `nota` float(4,2) NOT NULL,
  PRIMARY KEY (`dni`,`cod_tema`),
  KEY `fcod_tema_examen` (`cod_tema`),
  KEY `fdni_alumno` (`dni`) USING BTREE,
  CONSTRAINT `fcod_tema_examen` FOREIGN KEY (`cod_tema`) REFERENCES `2_1_tema` (`cod_tema`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fdni_alumno` FOREIGN KEY (`dni`) REFERENCES `2_1_alumno` (`dni`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.2_1_prepara
CREATE TABLE IF NOT EXISTS `2_1_prepara` (
  `dni` char(16) NOT NULL,
  `cod_tema` char(16) NOT NULL,
  PRIMARY KEY (`dni`,`cod_tema`),
  KEY `fcod_tema` (`cod_tema`),
  KEY `fdni_profe` (`dni`) USING BTREE,
  CONSTRAINT `fcod_tema` FOREIGN KEY (`cod_tema`) REFERENCES `2_1_tema` (`cod_tema`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fdni_profe` FOREIGN KEY (`dni`) REFERENCES `2_1_profesor` (`dni`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.2_1_profesor
CREATE TABLE IF NOT EXISTS `2_1_profesor` (
  `dni` char(16) NOT NULL,
  `nombre` varchar(50) NOT NULL,
  `categoria` varchar(12) NOT NULL,
  `edad` int(2) NOT NULL DEFAULT 0,
  PRIMARY KEY (`dni`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.2_1_tema
CREATE TABLE IF NOT EXISTS `2_1_tema` (
  `cod_tema` char(16) NOT NULL,
  `titulo` varchar(25) NOT NULL,
  `descripcion` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`cod_tema`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.3_1_empresas
CREATE TABLE IF NOT EXISTS `3_1_empresas` (
  `id_empresa` char(16) NOT NULL,
  `nombre` varchar(50) NOT NULL,
  PRIMARY KEY (`id_empresa`),
  UNIQUE KEY `nombre` (`nombre`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.3_1_juegos
CREATE TABLE IF NOT EXISTS `3_1_juegos` (
  `id_Juegos` char(16) NOT NULL,
  `nombre_juego` varchar(100) NOT NULL,
  `precio` int(11) NOT NULL,
  `cod_empresa` char(16) NOT NULL,
  PRIMARY KEY (`id_Juegos`),
  UNIQUE KEY `nombre_juego` (`nombre_juego`,`cod_empresa`),
  KEY `FK_3_1_juegos_3_1_empresas` (`cod_empresa`),
  CONSTRAINT `FK_3_1_juegos_3_1_empresas` FOREIGN KEY (`cod_empresa`) REFERENCES `3_1_empresas` (`id_empresa`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.3_1_usuario
CREATE TABLE IF NOT EXISTS `3_1_usuario` (
  `id_usuario` char(16) NOT NULL,
  `correo` varchar(50) NOT NULL,
  `contrasena` varchar(25) NOT NULL,
  `nick` varchar(50) NOT NULL,
  PRIMARY KEY (`id_usuario`),
  UNIQUE KEY `correo` (`correo`),
  UNIQUE KEY `nick` (`nick`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

-- Volcando estructura para tabla senn.3_1_usuarios_juegos
CREATE TABLE IF NOT EXISTS `3_1_usuarios_juegos` (
  `id_usuario` char(16) NOT NULL,
  `id_juego` char(16) NOT NULL,
  `fecha_compra` date NOT NULL,
  `precio_compra` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id_usuario`,`id_juego`),
  KEY `FK3` (`id_juego`),
  KEY `FK2` (`id_usuario`),
  CONSTRAINT `FK2` FOREIGN KEY (`id_usuario`) REFERENCES `3_1_usuario` (`id_usuario`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `FK3` FOREIGN KEY (`id_juego`) REFERENCES `3_1_juegos` (`id_Juegos`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;

-- La exportación de datos fue deseleccionada.

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
