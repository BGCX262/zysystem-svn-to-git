CREATE TABLESPACE ts_zysystem DATAFILE '/home/oracle/app/oracle/oradata/zydb/df_zysystem.dbf' SIZE 2000M AUTOEXTEND OFF;

CREATE USER zysystem identified BY zysystem default tablespace ts_zysystem;

GRANT DEBUG  TO zysystem;
GRANT CREATE SESSION TO zysystem;
GRANT CONNECT SESSION TO zysystem;
GRANT RESOURCE  TO zysystem;