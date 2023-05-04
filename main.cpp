#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int wordcount(FILE *fp) {
    int count = 0;
    int word = 0;
    char c;
    //������ �ַ��� �ַ� 
    while ((c = fgetc(fp)) != EOF) {
        if (isspace(c) || c == ',' || c == '.') {
            if (word) {
                count++;
                word = 0;
            }
            //��,.�ض����µĵ���  ����Ϊһ������ 
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
    //ÿ��ȡһ���ַ� �ַ�����һ 
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
   //����������Ϣȷ��ѡ����ļ� 
    if (argc == 3) {
        parameter = argv[1];
        filename = argv[2];
    } else if (argc == 2) {
        parameter = "-c";
        filename = argv[1];
    } else {
        fprintf(stderr, "ʹ�����¸�ʽ: %s -c/-w [input_file_name]\n", argv[0]);
        exit(1);
    }
    fp = fopen(filename, "r");
    if (fp == NULL) {
    	//�ļ��Ҳ���������޷��� 
        fprintf(stderr, "�򲻿��ļ�: %s\n", filename);
        exit(1);
    }
    if (strcmp(parameter, "-c") == 0) {
    	//���ַ�ѡ�� 
        count = charcount(fp);
        printf("�ַ�����%d\n", count);
    } else if (strcmp(parameter, "-w") == 0) {
    	//������ѡ�� 
        count = wordcount(fp);
        printf("��������%d\n", count);
    } else {
        fprintf(stderr, "Unknown parameter: %s\n", parameter);
        exit(1);
    }
    fclose(fp);
    return 0;
}
