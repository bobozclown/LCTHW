#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};

struct Database {
	struct Address rows[MAX_ROWS];
};

struct Connection {
	FILE *file;
	struct Database *db;
}

void die(const char *message)
{
	if(errno) {
		 perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}

	exit(1);
}

void Address_print(struct Address *addr)
{
	printf("%d %s %s\n",
		addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	if(rc != 1) die("Failed to load database.");
}

struct Connection *Database_open(const char *filename, char mode)
{
	//create connection struct
	struct Connection *conn = malloc(sizeof(struct Connection));
	if(!conn) die("connection null, memory error");

	//create database struct within connection struct
	con->db = malloc(sizeof(struct Database));
	if(!conn->db) die("db null, memory error");

	//if mode=c open file
	if(mode == 'c') {
		con->file = fopen(filename, "w");
	} else {
		//??? r+ w
		conn->file = fopen(filename, "r+");
		
		if(conn->file) {
			Database_load(conn);
		}
	}

	if(!conn->file) die("failed to open the file");

	return conn;
}

void Database_close(struct Connection *conn)
{
	if(conn) {
		if(con->file) fclose(conn->file);
		if(con->db) free(conn->db);
		free(conn);
	}
}

void Database_write(struct Connection *conn)
{
	rewind(conn->file);
	int rc = fwrite(conn->db,sizeof(struct Database), 1, con->file);
	if(rc !=1) die ("Failed to write database.");

	rc = fflush(conn->file);
	if(rc == -1) die("cannot flush database.");
}

void Database_create(struct Connection *conn)
{
	int i = 0;
	
	for(i = 0; i <MAX_ROWS; i++) {
		//make a prototype to initialize it
		struct Address addr = {.id = i, .set = 0};
		//then just assign it
		conn->db->rows[i] = addr;
	}
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	struct Address *addr =&conn->db->rows[id];
	if(addr->set) die("already set, delete it first");

	addr->set = 1;
	//WARNING: bug, read the how to break it and fix this
