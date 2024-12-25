DROP TABLE IF EXISTS `tmpstorage`;

CREATE TABLE `tmpstorage` (
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    mail VARCHAR(100) NOT NULL,
    dcrp TEXT,
    link VARCHAR(255)
);
