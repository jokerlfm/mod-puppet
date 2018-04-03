DROP TABLE IF EXISTS `puppet_info`;

CREATE TABLE `puppet_info` (
  `entry` int(11) NOT NULL AUTO_INCREMENT,
  `character_guid` int(11) NOT NULL DEFAULT '0',
  `specialty` varchar(45) NOT NULL DEFAULT '',
  PRIMARY KEY (`entry`)
) ENGINE=InnoDB AUTO_INCREMENT=2616 DEFAULT CHARSET=utf8;