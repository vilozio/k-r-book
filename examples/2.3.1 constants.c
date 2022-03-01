#define VTAB '\013' /* vertical tabulation in ASCII */
#define BELL '\007' /* bell in ASCII */

#define VTAB '\xb' /* vertical tabulation in ASCII */
#define BELL '\x7' /* bell in ASCII */

#define MAXLINE 1000
char line[MAXLINE + 1];

#define LEAP 1 /* in leap years */
int days[31 + 28 + LEAP + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31];
