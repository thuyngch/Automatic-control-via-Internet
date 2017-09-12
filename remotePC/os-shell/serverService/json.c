#include <stdio.h>
#include <string.h>
#include <json/json.h>

int
main()
{
    FILE *fp = fopen( "json.json", "r" );
    jvalue *json = jparse( fp );                 
    fclose( fp );

    for( jvalue **j = json->u.v; *j; ++j )
        if( !strcmp( (*j)->n, "email" ))          
            printf( "address: %s\n", (*j)->u.s );

    return 0;
}