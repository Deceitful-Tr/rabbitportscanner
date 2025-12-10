/*
 * Cyber Rabbit Port Scanner
 *Lütfen yasal izniniz olduðu aðlarda kullanýn
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void print_banner() {
    // Ekrani temizle
    system("cls");

    printf(RED); 
    
    // --- SENIN GONDERDIGIN OZEL TASARIM ---
    printf("        \\      /\n");
    printf("         \\    /    " CYN "       /$$$$$$$  /$$$$$$$$  /$$$$$$  /$$$$$$$$ /$$$$$$ /$$$$$$$$ /$$$$$$$$ /$$    /$$ /$$ \n" RED);
    printf("          \\  /     " CYN "      | $$__  $$| $$_____/ /$$__  $$| $$_____/|_  $$_/|__  $$__/| $$_____/| $$   | $$| $$ \n" RED);
    printf("           \\/      " CYN "      | $$  \\ $$| $$       | $$  \\__/| $$       | $$     | $$   | $$      | $$   | $$| $$\n" RED);
    printf("          /  \\     " CYN "      | $$  | $$| $$$$$    | $$      | $$$$$    | $$     | $$   | $$$$$   | $$   | $$| $$ \n" RED);
    printf("         |     |    " CYN "     | $$  | $$| $$__/    | $$      | $$__/    | $$     | $$   | $$__/   | $$   | $$| $$ \n" RED);
    printf("        |(O) (O)|  " CYN "      | $$  | $$| $$       | $$    $$| $$       | $$     | $$   | $$      | $$   | $$| $$\n" RED);
    printf("        |   *   |  " CYN "      | $$  | $$| $$       | $$    $$| $$       | $$     | $$   | $$      | $$   | $$| $$\n" RED);
    printf("        |  ___  |  " CYN "      | $$$$$$$/| $$$$$$$$|  $$$$$$/| $$$$$$$$ /$$$$$$   | $$   | $$      |  $$$$$$/| $$$$$$$$\n" RED);
    printf("       /       \\   " CYN "      |_______/ |________/ \\______/ |________/|______/   |__/   |__/        \\______/ |________/\n" RED);
    printf("      /_________\\ \n");
    // --------------------------------------

    printf("\n");
    printf(YEL "    --==[ " RESET "CYBER RABBIT SCANNER v1.0" YEL " ]==--\n");
    printf(YEL "    --==[ " RESET "GitHub: github.com/Deceitful-Tr" YEL " ]==--\n");
    printf(RESET); 
    printf("\n");
}

int main() {
    
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    char target_ip[20];
    int start_port, end_port;
    int i; 

  
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Hata: Winsock baslatilamadi. Kod: %d\n", WSAGetLastError());
        return 1;
    }
    
    print_banner();

    printf("Hedef IP: ");
    scanf("%19s", target_ip);
    printf("Baslangic Portu: ");
    scanf("%d", &start_port);
    printf("Bitis Portu: ");
    scanf("%d", &end_port);

    printf("\n" CYN "Tarama Basliyor... (%s)\n" RESET, target_ip);

    for (i = start_port; i <= end_port; i++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        
        if (sock == INVALID_SOCKET) {
            continue;
        }

        server.sin_addr.s_addr = inet_addr(target_ip);
        server.sin_family = AF_INET;
        server.sin_port = htons(i);

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf(WHT "[+] Port %d " GRN "ACIK\n" RESET, i);
        }

        closesocket(sock);
    }

    printf("\n" CYN "Tarama Bitti.\n" RESET);

    WSACleanup();
    printf("\nCikmak icin ENTER tusuna basin...");
    system("pause >nul");

    return 0;
}
