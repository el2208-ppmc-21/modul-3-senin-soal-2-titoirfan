#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define DELIM "."
 
/* return 1 jika hanya mengandung digit, else return 0 */
int valid_digit(char *ip_str)
{
    while (*ip_str) {
        if (*ip_str >= '0' && *ip_str <= '9')
            ++ip_str;
        else
            return 0;
    }
    return 1;
}
 
/* return 1 jika IP string-nya valid, else return 0 */
int valid_ip(char *ip_str)
{
    int num, dots = 0;
    char *ptr;
 
    if (ip_str == NULL)
        return 0;
 
    ptr = strtok(ip_str, DELIM);
 
    if (ptr == NULL)
        return 0;
 
    while (ptr) {
 
        /* setelah parsing string, harus hanya mengandung digit */
        if (!valid_digit(ptr))
            return 0;
 
        num = atoi(ptr);
 
        /* mengecek apakah IP Valid */
        if (num >= 1 && num <= 255) {
            /* parse string yang tersisa */
            ptr = strtok(NULL, DELIM);
            if (ptr != NULL)
                ++dots;
        } else
            return 0;
    }
    /* harus mengandung 3 '.' alias titik */
    if (dots != 3)
        return 0;
    return 1;
}

/* Prosedur untuk Mencetak Kelas dari IP Address */
void class_ip(char *ip_str)
{
    int num = 0;
    char *ptr;
 
    ptr = strtok(ip_str, DELIM);
 
    if (ip_str != DELIM) {
        num = atoi(ptr);
        /* Prosedur akan langsung mencetak kelas IP berdasar range angkanya */
        if (num >= 1 && num <= 127) {
			printf("Alamat IP Kelas A.\n");
		}
		else if  (num > 127 && num <= 191) {
			printf("Alamat IP Kelas B.\n"); 
		}
		else if  (num > 191 && num <= 224) {
			printf("Alamat IP Kelas C.\n");
		}
		else if  (num > 224 && num <= 239) {
			printf("Alamat IP Kelas D.\n");
		}
		else { 
			printf("Alamat IP Kelas E.\n");
		}
	}
}

int main()
{
    char ip[20]={0};
    
    printf("Masukkan Alamat IP : ");
    scanf("%s",ip);
    
    if (valid_ip(ip) ==  1) { 
		printf("Alamat IP Valid\n"); 
		class_ip(ip);
	}
	else { 
		printf("Alamat IP Tidak Valid\n"); 
	}
    return 0;
    
}
