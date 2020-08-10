#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define DO2 66
#define DO_2 70
#define RE2 74
#define RE_2 78
#define MI2 83
#define FA2 88
#define FA_2 93
#define SOL2 98
#define SOL_2 104
#define LA2 110
#define LA_2 117
#define SI2 124

#define DO3 131
#define DO_3 139
#define RE3 147
#define RE_3 156
#define MI3 165
#define FA3 175
#define FA_3 185
#define SOL3 196
#define SOL_3 208
#define LA3 220
#define LA_3 233
#define SI3 247

#define DO4 262
#define DO_4 277
#define RE4 294
#define RE_4 311
#define MI4 330
#define FA4 349
#define FA_4 370
#define SOL4 392
#define SOL_4 415
#define LA4 440
#define LA_4 466
#define SI4 494

#define DO5 523
#define DO_5 554
#define RE5 587
#define RE_5 622
#define MI5 659
#define FA5 698
#define FA_5 740
#define SOL5 784
#define SOL_5 831
#define LA5 880
#define LA_5 932
#define SI5 988

#define DO6 1046
#define DO_6 1109
#define RE6 1175
#define RE_6 1245
#define MI6 1319
#define FA6 1397
#define FA_6 1480
#define SOL6 1568
#define SOL_6 1661
#define LA6 1760
#define LA_6 1865
#define SI6 1976

#define DO7 2093
#define DO_7 2217
#define RE7 2349
#define RE_7 2489
#define MI7 2637
#define FA7 2794
#define FA_7 2960
#define SOL7 3316
#define SOL_7 3322
#define LA7 3520
#define LA_7 3729
#define SI7 3951

#define DO8 4186




#define PRINTF(x, y) betterPrintf(x, y)
void stringToUpper(char* stringa);
void betterPrintf(FILE* ptrFile, unsigned int valore);
int stampaNota(char* stringa, FILE* ptrFile);
void play(FILE* ptrFile);
void exportAndExit(FILE* ptrFile);

int main()
{

    char tempData[10];
    unsigned int tempInt = 0;;
    FILE* ptrFile = fopen("music.sona", "r+");
    if(ptrFile == NULL) {
        ptrFile = fopen("music.sona", "w");
        fclose(ptrFile);
        ptrFile = fopen("music.sona", "r+");
    }
    while(1){
        printf("%s", "Write note or action, -1 to exit:\n! ");
        scanf("%s", tempData);
        stringToUpper(tempData);

        if( strcmp(tempData, "0") == -1 ) {
            break;
        } else if (strcmp(tempData, "PLAY") == 0) {
            play(ptrFile);
        } else if(strcmp(tempData, "EXPORT") == 0){
            exportAndExit(ptrFile);
        } else if(strcmp(tempData, "CLEAR") == 0){
            freopen("music.sona", "w", ptrFile);
            freopen("music.sona", "r+", ptrFile);
            puts("Project cleared successfully!");
        } else {
            if(stampaNota(tempData, ptrFile)) {
                printf("%s", "Add time (1 to 4):\n? ");
                scanf("%d", &tempInt);
                while(tempInt > 4 || tempInt < 1) {
                    printf("%s","Not accepted time. Add time (1 to 4)\n? ");
                    scanf("%d", &tempInt);
                }
                PRINTF(ptrFile, tempInt*100+50);
            }
        }
    }

    return 0;
}


void exportAndExit(FILE* ptrFile){
    FILE* ptrOutput = fopen("output.c", "w");
    rewind(ptrFile);
    char line[30];
    char* token;
    int beat, time;
    fprintf(ptrOutput, "#include <windows.h>\n\nint main(){\n\t//Made with SONA, easy C beep generator.\n//Made by Samuele Pesce. https://github.com/Trontie/sona \n");
    while(fgets(line, 30, ptrFile) != NULL ){
        token = strtok(line, ",");
        beat = atoi(token);
        token = strtok(NULL, ",");
        time = atoi(token);
        fprintf(ptrOutput, "\tBeep(%d,%d);Sleep(%d);\n", beat, time, time);
        fflush(ptrOutput);
    }
    fprintf(ptrOutput, "//Made with SONA, easy C beep generator.\n\t//Made by Samuele Pesce. https://github.com/Trontie/sona\n}\n");
    fclose(ptrOutput);

    puts("Project published correctly.");
}

void play(FILE* ptrFile){
    rewind(ptrFile);
    char line[30];
    char* token;
    int beat, time;
    while(fgets(line, 30, ptrFile) != NULL ){
        token = strtok(line, ",");
        beat = atoi(token);
        token = strtok(NULL, ",");
        time = atoi(token);
        printf("%d,%d\n", beat, time);
        Beep(beat, time);
        Sleep(time);
    }

}


int stampaNota(char* tempData, FILE* ptrFile){
    if(strcmp(tempData, "DO2") == 0)
        PRINTF(ptrFile, DO2);

    else if(strcmp(tempData, "DO_2") == 0)
        PRINTF(ptrFile, DO_2);
    else if(strcmp(tempData, "RE2") == 0)
        PRINTF(ptrFile, RE2);
    else if(strcmp(tempData, "RE_2") == 0)
        PRINTF(ptrFile, RE_2);
    else if(strcmp(tempData, "MI2") == 0)
        PRINTF(ptrFile, MI2);
    else if(strcmp(tempData, "FA2") == 0)
        PRINTF(ptrFile, FA2);
    else if(strcmp(tempData, "FA_2") == 0)
        PRINTF(ptrFile, FA_2);
    else if(strcmp(tempData, "SOL2") == 0)
        PRINTF(ptrFile, SOL2);
    else if(strcmp(tempData, "SOL_2") == 0)
        PRINTF(ptrFile, SOL_2);
    else if(strcmp(tempData, "LA2") == 0)
        PRINTF(ptrFile, LA2);
    else if(strcmp(tempData, "LA_2") == 0)
        PRINTF(ptrFile, LA_2);
    else if(strcmp(tempData, "SI2") == 0)
        PRINTF(ptrFile, SI2);
    /* Altra ottava */
    else if(strcmp(tempData, "DO3") == 0)
        PRINTF(ptrFile, DO3);
    else if(strcmp(tempData, "DO_3") == 0)
        PRINTF(ptrFile, DO_3);
    else if(strcmp(tempData, "RE3") == 0)
        PRINTF(ptrFile, RE3);
    else if(strcmp(tempData, "RE_3") == 0)
        PRINTF(ptrFile, RE_3);
    else if(strcmp(tempData, "MI3") == 0)
        PRINTF(ptrFile, MI3);
    else if(strcmp(tempData, "FA3") == 0)
        PRINTF(ptrFile, FA3);
    else if(strcmp(tempData, "FA_3") == 0)
        PRINTF(ptrFile, FA_3);
    else if(strcmp(tempData, "SOL3") == 0)
        PRINTF(ptrFile, SOL3);
    else if(strcmp(tempData, "SOL_3") == 0)
        PRINTF(ptrFile, SOL_3);
    else if(strcmp(tempData, "LA3") == 0)
        PRINTF(ptrFile, LA3);
    else if(strcmp(tempData, "LA_3") == 0)
        PRINTF(ptrFile, LA_3);
    else if(strcmp(tempData, "SI3") == 0)
        PRINTF(ptrFile, SI3);
    /*Altra ottava*/
    else if(strcmp(tempData, "DO4") == 0)
        PRINTF(ptrFile, DO4);
    else if(strcmp(tempData, "DO_4") == 0)
        PRINTF(ptrFile, DO_4);
    else if(strcmp(tempData, "RE4") == 0)
        PRINTF(ptrFile, RE4);
    else if(strcmp(tempData, "RE_4") == 0)
        PRINTF(ptrFile, RE_4);
    else if(strcmp(tempData, "MI4") == 0)
        PRINTF(ptrFile, MI4);
    else if(strcmp(tempData, "FA4") == 0)
        PRINTF(ptrFile, FA4);
    else if(strcmp(tempData, "FA_4") == 0)
        PRINTF(ptrFile, FA_4);
    else if(strcmp(tempData, "SOL4") == 0)
        PRINTF(ptrFile, SOL4);
    else if(strcmp(tempData, "SOL_4") == 0)
        PRINTF(ptrFile, SOL_4);
    else if(strcmp(tempData, "LA4") == 0)
        PRINTF(ptrFile, LA4);
    else if(strcmp(tempData, "LA_4") == 0)
        PRINTF(ptrFile, LA_4);
    else if(strcmp(tempData, "SI4") == 0)
        PRINTF(ptrFile, SI4);
    /*Altra ottava*/
    else if(strcmp(tempData, "DO5") == 0)
        PRINTF(ptrFile, DO5);
    else if(strcmp(tempData, "DO_5") == 0)
        PRINTF(ptrFile, DO_5);
    else if(strcmp(tempData, "RE5") == 0)
        PRINTF(ptrFile, RE5);
    else if(strcmp(tempData, "RE_5") == 0)
        PRINTF(ptrFile, RE_5);
    else if(strcmp(tempData, "MI5") == 0)
        PRINTF(ptrFile, MI5);
    else if(strcmp(tempData, "FA5") == 0)
        PRINTF(ptrFile, FA5);
    else if(strcmp(tempData, "FA_5") == 0)
        PRINTF(ptrFile, FA_5);
    else if(strcmp(tempData, "SOL5") == 0)
        PRINTF(ptrFile, SOL5);
    else if(strcmp(tempData, "SOL_5") == 0)
        PRINTF(ptrFile, SOL_5);
    else if(strcmp(tempData, "LA5") == 0)
        PRINTF(ptrFile, LA5);
    else if(strcmp(tempData, "LA_5") == 0)
        PRINTF(ptrFile, LA_5);
    else if(strcmp(tempData, "SI5") == 0)
        PRINTF(ptrFile, SI5);
    /* Altra ottava */
    else if(strcmp(tempData, "DO6") == 0)
        PRINTF(ptrFile, DO6);
    else if(strcmp(tempData, "DO_6") == 0)
        PRINTF(ptrFile, DO_6);
    else if(strcmp(tempData, "RE6") == 0)
        PRINTF(ptrFile, RE6);
    else if(strcmp(tempData, "RE_6") == 0)
        PRINTF(ptrFile, RE_6);
    else if(strcmp(tempData, "MI6") == 0)
        PRINTF(ptrFile, MI6);
    else if(strcmp(tempData, "FA6") == 0)
        PRINTF(ptrFile, FA6);
    else if(strcmp(tempData, "FA_6") == 0)
        PRINTF(ptrFile, FA_6);
    else if(strcmp(tempData, "SOL6") == 0)
        PRINTF(ptrFile, SOL6);
    else if(strcmp(tempData, "SOL_6") == 0)
        PRINTF(ptrFile, SOL_6);
    else if(strcmp(tempData, "LA6") == 0)
        PRINTF(ptrFile, LA6);
    else if(strcmp(tempData, "LA_6") == 0)
        PRINTF(ptrFile, LA_6);
    else if(strcmp(tempData, "SI6") == 0)
        PRINTF(ptrFile, SI6);
    /*Altra ottava*/
    else if(strcmp(tempData, "DO7") == 0)
        PRINTF(ptrFile, DO7);
    else if(strcmp(tempData, "DO_7") == 0)
        PRINTF(ptrFile, DO_7);
    else if(strcmp(tempData, "RE7") == 0)
        PRINTF(ptrFile, RE7);
    else if(strcmp(tempData, "RE_7") == 0)
        PRINTF(ptrFile, RE_7);
    else if(strcmp(tempData, "MI7") == 0)
        PRINTF(ptrFile, MI7);
    else if(strcmp(tempData, "FA7") == 0)
        PRINTF(ptrFile, FA7);
    else if(strcmp(tempData, "FA_7") == 0)
        PRINTF(ptrFile, FA_7);
    else if(strcmp(tempData, "SOL7") == 0)
        PRINTF(ptrFile, SOL7);
    else if(strcmp(tempData, "SOL_7") == 0)
        PRINTF(ptrFile, SOL_7);
    else if(strcmp(tempData, "LA7") == 0)
        PRINTF(ptrFile, LA7);
    else if(strcmp(tempData, "LA_7") == 0)
        PRINTF(ptrFile, LA_7);
    else if(strcmp(tempData, "SI7") == 0)
        PRINTF(ptrFile, SI7);
    /*Altra ottava*/
     else if(strcmp(tempData, "DO8") == 0)
        PRINTF(ptrFile, DO8);
    else if(strcmp(tempData, "0") == 0)
        PRINTF(ptrFile, 0);
    else {
        printf("%s", "Questa nota o azione non esiste. ");
        return 0;
    }

    return 1;

}
void stringToUpper(char* s){
  for (int i  = 0; s[i]!='\0'; i++)
   if(s[i] >= 'a' && s[i] <= 'z')
    s[i] = s[i] - 32;
}
void betterPrintf(FILE* ptrFile, unsigned int valore){
    static int notaTempo = 0;
    fseek(ptrFile, 0, SEEK_END);
    if(notaTempo == 0 ){
        fprintf(ptrFile, "%d,", valore);
        notaTempo++;
    } else {
        fprintf(ptrFile, "%d\n", valore);
        notaTempo = 0;
    }

    fflush(ptrFile);
}



