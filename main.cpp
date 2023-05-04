#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int wordcount(FILE *fp) {
    int count = 0;
    int word = 0;
    char c;
    //单词数 字符数 字符 
    while ((c = fgetc(fp)) != EOF) {
        if (isspace(c) || c == ',' || c == '.') {
            if (word) {
                count++;
                word = 0;
            }
            //被,.截断算新的单词  否则为一个单词 
        } else {
            word = 1;
        }
    }
    if (word) {
        count++;
    }
    return count;
}

int charcount(FILE *fp) {
    int count = 0;
    char c;
    //每读取一个字符 字符数加一 
    while ((c = fgetc(fp)) != EOF) {
        count++;
    }
    return count;
}



int main(int argc, char *argv[]) {
    int count;
	char *filename;
    char *parameter;
    FILE *fp;
   //根据输入信息确定选项和文件 
    if (argc == 3) {
        parameter = argv[1];
        filename = argv[2];
    } else if (argc == 2) {
        parameter = "-c";
        filename = argv[1];
    } else {
        fprintf(stderr, "使用以下格式: %s -c/-w [input_file_name]\n", argv[0]);
        exit(1);
    }
    fp = fopen(filename, "r");
    if (fp == NULL) {
    	//文件找不到，输出无法打开 
        fprintf(stderr, "打不开文件: %s\n", filename);
        exit(1);
    }
    if (strcmp(parameter, "-c") == 0) {
    	//数字符选项 
        count = charcount(fp);
        printf("字符数：%d\n", count);
    } else if (strcmp(parameter, "-w") == 0) {
    	//数单词选项 
        count = wordcount(fp);
        printf("单词数：%d\n", count);
    } else {
        fprintf(stderr, "Unknown parameter: %s\n", parameter);
        exit(1);
    }
    fclose(fp);
    return 0;
}
