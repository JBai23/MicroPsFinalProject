
#ifndef GDEF_H
#define GDEF_H 1

// bool typdef
typedef int bool;
#define true 1
#define false 0

// stringlen
#define STRSIZE 13 // 12 characters and a \0
#define BSIZE 64

#define MKDB char db_buffer[1024] // make debug buffer
#define DB(DEBUG) strcpy(db_buffer, DEBUG)

#define SPACE12 "          "
#define SPACE80 "                                                                                "

#endif