BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "ad" (
	"ID"	TEXT NOT NULL,
	"PW"	TEXT NOT NULL
);
CREATE TABLE IF NOT EXISTS "company" (
	"corank"	INTEGER NOT NULL UNIQUE,
	"coname"	TEXT NOT NULL,
	"place"	TEXT NOT NULL,
	PRIMARY KEY("corank")
);
CREATE TABLE IF NOT EXISTS "roadbike" (
	"bike_name"	TEXT NOT NULL UNIQUE,
	"price"	INTEGER NOT NULL,
	"weight"	INTEGER NOT NULL,
	"frame"	TEXT NOT NULL,
	"fork"	TEXT NOT NULL,
	"groupset"	TEXT NOT NULL,
	"wheel"	TEXT NOT NULL,
	"break"	BLOB NOT NULL,
	"CR"	INTEGER NOT NULL,
	FOREIGN KEY("CR") REFERENCES "company"("corank") on update cascade,
	PRIMARY KEY("bike_name")
);
CREATE TABLE IF NOT EXISTS "recommend" (
	"reno"	INTEGER NOT NULL UNIQUE,
	"level"	TEXT NOT NULL,
	"budget"	TEXT NOT NULL,
	"bestbike"	TEXT NOT NULL,
	FOREIGN KEY("bestbike") REFERENCES "roadbike"("bike_name") on update cascade,
	PRIMARY KEY("reno")
);
CREATE TABLE IF NOT EXISTS "belong" (
	"bike_name"	TEXT NOT NULL,
	"reno"	INTEGER NOT NULL,
	FOREIGN KEY("reno") REFERENCES "recommend"("reno"),
	FOREIGN KEY("bike_name") REFERENCES "roadbike"("bike_name"),
	PRIMARY KEY("bike_name","reno")
);
INSERT INTO "ad" VALUES ('Hwan','1234');
INSERT INTO "company" VALUES (1,'Trek','US');
INSERT INTO "company" VALUES (2,'Merida','Taiwan');
INSERT INTO "company" VALUES (3,'Cello','Korea');
INSERT INTO "roadbike" VALUES ('Reacto 9000-E',8900000,7.3,'Carbon','Carbon','Sram Red etap','Carbon','Disk',2);
INSERT INTO "roadbike" VALUES ('Reacto Force Edition',5900000,8.36,'Carbon','Carbon','Sram Force etap','Carbon','Disk',2);
INSERT INTO "roadbike" VALUES ('Reacto 8000-E',6500000,7.5,'Carbon','Carbon','Shimano Ultegra','Carbon ','Disk',2);
INSERT INTO "roadbike" VALUES ('Reacto 5000',3000000,8.88,'Carbon','Carbon','Shimano Ultegra','Alu','Disk',2);
INSERT INTO "roadbike" VALUES ('Reacto 4000',2700000,8.71,'Carbon','Carbon','Shimano 105','Alu','Disk',2);
INSERT INTO "roadbike" VALUES ('Reacto 400',1300000,9.4,'Alu','Carbon','Shimano 105','Alu','Rim',2);
INSERT INTO "roadbike" VALUES ('Scultra 9000-E',8600000,6.83,'Carbon','Carbon','Sram Red etap','Carbon','Disk',2);
INSERT INTO "roadbike" VALUES ('Scultra 8000-E',6300000,7.33,'Carbon','Carbon','Shimano Ultegra','Carbon','Disk',2);
INSERT INTO "roadbike" VALUES ('Scultra Force Edition',5800000,7.59,'Carbon','Carbon','Sram Force etap','Carbon','Disk',2);
INSERT INTO "roadbike" VALUES ('Scultra 7000-E',4600000,7.98,'Carbon','Carbon','Shimano Ultegra','Alu','Disk',2);
INSERT INTO "roadbike" VALUES ('Scultra 6000',3300000,8.33,'Carbon','Carbon','Shimano Ultegra','Alu','Disk',2);
INSERT INTO "roadbike" VALUES ('Scultra Disk 4000',2550000,8.46,'Carbon','Carbon','Shimano 105','Alu','Disk',2);
INSERT INTO "roadbike" VALUES ('Scultra Disk 400',1500000,9.05,'Alu','Carbon','Shimano 105','Alu ','Disk',2);
INSERT INTO "roadbike" VALUES ('Scultra 5000',2400000,8.39,'Carbon','Carbon','Shimano Ultegra','Alu','Rim',2);
INSERT INTO "roadbike" VALUES ('Scultra 4000',2050000,8.22,'Carbon','Carbon','Shimano 105','Alu','Rim',2);
INSERT INTO "roadbike" VALUES ('Scultra 100',760000,9.58,'Alu','Carbon','Shimano Claris','Alu','Rim',2);
INSERT INTO "roadbike" VALUES ('Emonda SLR 7',10500000,7.18,'Carbon','Carbon','Shimano Ultegra','Carbon','Disk',1);
INSERT INTO "roadbike" VALUES ('Emonda SL 7',6950000,7.74,'Carbon','Carbon','Shimano Ultegra','Carbon','Disk',1);
INSERT INTO "roadbike" VALUES ('Emonda SL 6 pro',4990000,8.03,'Carbon','Carbon','Shimano Ultegra','Carbon','Disk',1);
INSERT INTO "roadbike" VALUES ('Emonda SLR 7 etap',11500000,7.33,'Carbon','Carbon','Sram Force etap','Carbon','Disk',1);
INSERT INTO "roadbike" VALUES ('Emonda SLR 9',14500000,6.72,'Carbon','Carbon','Shimano DuraAce','Carbon','Disk',1);
INSERT INTO "roadbike" VALUES ('Emonda SLR 6',9200000,7.26,'Carbon','Carbon','Shimano Ultegra','Carbon','Disk',1);
INSERT INTO "roadbike" VALUES ('Emonda SLR 5',3390000,9.15,'Carbon','Carbon','Shimano 105','Alu','Disk',1);
INSERT INTO "roadbike" VALUES ('Emonda SLR 9 etap',14500000,6.74,'Carbon','Carbon','Sram Red etap','Carbon','Disk',1);
INSERT INTO "roadbike" VALUES ('Domani SL 6',4890000,9.3,'Carbon','Carbon','Shimano Ultegra','Alu','Disk',1);
INSERT INTO "roadbike" VALUES ('Madone SL 6',5690000,8.62,'Carbon','Carbon','Shimano Ultegra','Alu','Disk',1);
INSERT INTO "roadbike" VALUES ('Emonda ALR 5 Disk',2190000,9.04,'Alu','Carbon','Shimano 105','Alu','Disk',1);
INSERT INTO "roadbike" VALUES ('Domani SLR 7',8580000,8.47,'Carbon','Carbon','Shimano Ultegra','Carbon','Disk',1);
INSERT INTO "roadbike" VALUES ('Domani SL 5',3890000,9.89,'Carbon','Carbon','Shimano 105','Alu','Disk',1);
INSERT INTO "roadbike" VALUES ('Madone SLR 9',14800000,7.8,'Carbon','Carbon','Shimano DuraAce','Carbon','Disk',1);
INSERT INTO "roadbike" VALUES ('Madone SLR 9 etap',14800000,7.86,'Carbon','Carbon','Sram Red etap','Carbon','Disk',1);
INSERT INTO "roadbike" VALUES ('Domani SLR 9 etap',14500000,8.1,'Carbon','Carbon','Sram Red etap','Carbon','Disk',1);
INSERT INTO "roadbike" VALUES ('Domani SLR 9',14500000,7.93,'Carbon','Carbon','Shimano DuraAce','Carbon','Disk',1);
INSERT INTO "roadbike" VALUES ('Madone SLR 7 etap',11800000,8.32,'Carbon','Carbon','Sram Force etap','Carbon','Disk',1);
INSERT INTO "roadbike" VALUES ('Domani SLR 7 etap',10800000,8.61,'Carbon','Carbon','Sram Force etap','Carbon','Disk',1);
INSERT INTO "roadbike" VALUES ('Madone SLR 7',9900000,8.08,'Carbon','Carbon','Shimano Ultegra','Carbon','Disk',1);
INSERT INTO "roadbike" VALUES ('Madone SLR 6',9500000,8.26,'Carbon','Carbon','Shimano Ultegra','Carbon','Disk',1);
INSERT INTO "roadbike" VALUES ('Domani SLR 6',8900000,8.69,'Carbon','Carbon','Shimano Ultegra','Carbon','Disk',1);
INSERT INTO "roadbike" VALUES ('Domani SL 7 etap',7700000,8.9,'Carbon','Carbon','Sram Force etap','Carbon','Disk',1);
INSERT INTO "roadbike" VALUES ('Boone 6 Disk',4600000,8.23,'Carbon','Carbon','Shimano Ultegra','Alu','Disk',1);
INSERT INTO "roadbike" VALUES ('Domani AL 3 Disk',1150000,10.54,'Alu','Carbon','Shimano Sora ','Alu','Disk',1);
INSERT INTO "roadbike" VALUES ('Domani AL 2 Disk',920000,10.74,'Alu','Carbon','Shimano Claris','Alu','Disk',1);
INSERT INTO "roadbike" VALUES ('Domani AL 2',790000,9.57,'Alu','Carbon','Shimano Claris','Alu','Rim',1);
INSERT INTO "roadbike" VALUES ('Scultra400',1150000,8.78,'Alu','Carbon','Shimano 105','Temp','Rim',2);
INSERT INTO "roadbike" VALUES ('Scarlatti105',1250000,8.6,'Alu','Carbon','Shimano 105','Alu','Rim',3);
INSERT INTO "roadbike" VALUES ('Elliot etap',7500000,7.2,'Carbon','Carbon','Sram Red etap','Carbon','Rim',3);
INSERT INTO "roadbike" VALUES ('Cayin Ultegra',2090000,7.6,'Carbon','Carbon','Shimano Ultegra','Alu','Rim',3);
INSERT INTO "recommend" VALUES (1,'상급','20000000','Madone SLR 9 etap');
INSERT INTO "recommend" VALUES (2,'중급','5000000','Emonda SL 6 pro');
INSERT INTO "recommend" VALUES (3,'입문','1500000','Scultra 100');
INSERT INTO "belong" VALUES ('Domani AL 2 Disk',3);
INSERT INTO "belong" VALUES ('Reacto 9000-E',1);
INSERT INTO "belong" VALUES ('Scultra 100',3);
INSERT INTO "belong" VALUES ('Emonda SLR 9',1);
INSERT INTO "belong" VALUES ('Emonda SL 6 pro',2);
INSERT INTO "belong" VALUES ('Madone SLR 9 etap',1);
INSERT INTO "belong" VALUES ('Boone 6 Disk',2);
COMMIT;
