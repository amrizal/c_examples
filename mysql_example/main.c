#include <stdio.h>
#include <string.h>
#include <mysql.h>

int main()
{
	MYSQL *conn;	/* MySQL connection */
	MYSQL_RES *result;	/* result set */
	MYSQL_ROW row;	/* an instance of a row from the result */

	int x;

	/* connection details */
	const char *server	= "localhost";
	const char *user	= "root";
	const char *password	= "";
	const char *database	= "information_schema";

	/* attempt to connecto to the server */
	conn	= mysql_init(NULL);
	if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
	perror(mysql_error(conn));
	return 0 ;
	}

	char query[1000];

	printf("Query: ");
	fgets(query, 1000, stdin);
	printf("\n");

																						/* run the SQL query */
	if (mysql_query(conn, query)) {
		perror(mysql_error(conn));
		return 0;
	}

	result = mysql_use_result(conn);

	printf("+----------------------+\n");
	printf("| RESULT |\n");
	printf("+----------------------+\n");

	/* print out the results */
	while ((row = mysql_fetch_row(result)) != NULL) {
	printf("| %s", row[0]);

	/* layout */
		for(x = strlen(row[0]); x < 21; x++)
			printf(" ");

	printf("|\n");
	}

	printf("+----------------------+\n");

	/* clean up */
	mysql_free_result(result);
	mysql_close(conn);

	return 0;
}
