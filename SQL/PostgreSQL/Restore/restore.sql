DROP DATABASE dvdrental;
CREATE DATABASE dvdrental_restore;

-- restore:
-- sudo -u postgres pg_restore --dbname=dvdrental_restore ../Backup/dvdrental.tar
-- sudo -u postgres pg_restore -d dvdrental_restore ../Backup/dvdrental.tar

DROP DATABASE dvdrental_restore;
