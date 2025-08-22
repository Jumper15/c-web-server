#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* wday_itos(int wday_i) 
{
    char* wday_s;
    wday_s = malloc(3);
    switch (wday_i) {
        case 0:
            wday_s = "Sun";
            break;
        case 1:
            wday_s = "Mon";
            break;
        case 2:
            wday_s = "Tue";
            break;
        case 3:
            wday_s = "Wed";
            break;
        case 4:
            wday_s = "Thu";
            break;
        case 5:
            wday_s = "Fri";
            break;
        case 6:
            wday_s = "Sat";
            break;
    }
    return wday_s;
}

char* mon_itos(int mon_i)
{
    char* mon_s;
    mon_s = malloc(3);
    
    switch (mon_i) {
        case 0:
            mon_s = "Jan";
            break;
        case 1:
            mon_s = "Feb";
            break;
        case 2:
            mon_s = "Mar";
            break;
        case 3:
            mon_s = "Apr";
            break;
        case 4:
            mon_s = "May";
            break;
        case 5:
            mon_s = "Jun";
            break;
        case 6:
            mon_s = "Jul";
            break;
        case 7:
            mon_s = "Aug";
            break;
        case 8:
            mon_s = "Sep";
            break;
        case 9:
            mon_s = "Oct";
            break;
        case 10:
            mon_s = "Nov";
            break;
        case 11:
            mon_s = "Dec";
            break; 
    }
    return mon_s;
}

char* get_date() {
    time_t *rawtime = malloc(sizeof(time_t));
    struct tm *gmt_time = malloc(sizeof(struct tm));

    time(rawtime);
    gmt_time = gmtime(rawtime);

    int sec = gmt_time->tm_sec;
    int min = gmt_time->tm_min;
    int hour = gmt_time->tm_hour;
    int mday = gmt_time->tm_mday;
    int mon_i = gmt_time->tm_mon;
    int year = gmt_time->tm_year;
    int wday_i = gmt_time->tm_wday;

    char* wday_s = wday_itos(wday_i);
    char* mon_s = mon_itos(mon_i);
    year = year + 1900;

    char* date_buffer = malloc(27);
    snprintf(date_buffer, 27, "%s, %02d %s %d %02d:%02d:%02d", wday_s, mday, mon_s, year, hour, min, sec);
    printf("%s\n", date_buffer);
    return date_buffer;
}

// Date: <day-name>, <day> <month> <year> <hour>:<minute>:<second> GMT