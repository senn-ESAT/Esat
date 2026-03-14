SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";

CREATE TABLE `anagrafica` (
  `idanagrafica` int(11) NOT NULL,
  `cognome` varchar(100) COLLATE utf8_bin NOT NULL,
  `nome` varchar(100) COLLATE utf8_bin NOT NULL,
  `eta` tinyint(3) UNSIGNED NOT NULL,
  `squadra` varchar(255) COLLATE utf8_bin NOT NULL,
  `titolare` tinyint(1) UNSIGNED NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

INSERT INTO `anagrafica` (`idanagrafica`, `cognome`, `nome`, `eta`, `squadra`, `titolare`) VALUES
(1, 'Bianchi', 'Gino', 18, 'Salernitana', 0),
(2, 'Rossi', 'Ciro', 18, 'Empoli', 0),
(3, 'Verdi', 'Ciccio', 19, 'Verona', 1),
(7, 'Viola', 'Jacopo', 21, 'Cagliari', 1);

CREATE TABLE `utenti` (
  `idutenti` int(11) UNSIGNED NOT NULL,
  `cognome` varchar(100) COLLATE utf8_bin DEFAULT NULL,
  `nome` varchar(100) COLLATE utf8_bin DEFAULT NULL,
  `mail` varchar(255) COLLATE utf8_bin DEFAULT NULL,
  `tipo` char(1) COLLATE utf8_bin DEFAULT NULL,
  `password` varchar(255) COLLATE utf8_bin DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

INSERT INTO `utenti` (`idutenti`, `cognome`, `nome`, `mail`, `tipo`, `password`) VALUES
(1, 'ciccio', 'bello', 'ciccio@mail.it', 'a', 'cicciobello');

ALTER TABLE `anagrafica`
  ADD PRIMARY KEY (`idanagrafica`);

ALTER TABLE `utenti`
  ADD PRIMARY KEY (`idutenti`);

ALTER TABLE `anagrafica`
  MODIFY `idanagrafica` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

ALTER TABLE `utenti`
  MODIFY `idutenti` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
COMMIT;