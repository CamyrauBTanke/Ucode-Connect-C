#include "../inc/libmx.h"

void mx_print_lnk(ls_list *print, ls_size *size) {
    int counter = 0;
    char *res_itoa_now = mx_itoa(print->info.st_nlink);
    char *res_itoa_lnk = mx_itoa(size->lnk);

    if (mx_strlen(res_itoa_now) == mx_strlen(res_itoa_lnk))
        mx_printint(print->info.st_nlink);
    else if (mx_strlen(res_itoa_now) < mx_strlen(res_itoa_lnk)) {
        counter = mx_strlen(res_itoa_now);
        while (counter != mx_strlen(res_itoa_lnk)) {
            mx_printchar(' ');
            counter++;
        }
        mx_printint(print->info.st_nlink);
    }
    mx_printchar(' ');
    free(res_itoa_now);
    free(res_itoa_lnk);
}
