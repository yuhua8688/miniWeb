#include "../httpd.h"
/**************************************
*author: Jone.Chen  <yuhua8688@tom.com>
*License:LGPL
***************************************/

/******************************************
*  name   -- file name
*  offset -- file current offset
*  length -- current data length
*  size   -- file remaining size
*  
*  offset = 0 : file start
*  size   = 0 : end of file
******************************************/
void process_upload(int sock, char *name, char *value, unsigned long offset, unsigned long length, unsigned long size)
{
	 if(offset==0)
	 {
	 	send(sock, "<p>Filename:", 12, 0);
		send(sock, name, rt_strlen(name), 0);
		send(sock, "</p> <p>Data</p> <p>", 20, 0);
	 }
	 send(sock, value, length, 0);
	 if(size==0)
	 {
	   send(sock, "</p>", 4, 0);
	 }
}


