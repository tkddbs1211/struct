#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 90

struct employee {
    char name[100];
    int studentcode;
    int grade;
}; 

int main()
{
    FILE* fp;
    employee student[N];
    srand(time(NULL));
    int studentcode;
    int grade,avg;
    int max = student[0].grade;
    int min = student[0].grade;
    int sum = 0;

    fp = fopen("C:\\Users\\상윤\\Desktop\\name.txt", "r");

    if (fp == NULL) {

        printf("Fail to open\n");

        return 0;

    }
    
    char file_buff[50];

    for (int i = 0; i < N; i++)
    {
        if (fgets(student[i].name, sizeof(student[i].name), fp) != NULL) 
        {
            student[i].name[strcspn(student[i].name, "\n")] = '\0';
            student[i].studentcode = i;
            student[i].grade = rand() % 101;
            sum += student[i].grade;
        }
        else
        {
            break;
        }
    }
    avg = sum / N;
    int best_student_idx = 0;
    int worst_student_idx = 0;

    for (int i = 1; i < N; i++) {
        if (student[i].grade > student[best_student_idx].grade) {
            best_student_idx = i;
        }

        if (student[i].grade < student[worst_student_idx].grade) {
            worst_student_idx = i;
        }
    }

    printf("최고점 학생(학번,점수) : %s(%d, %d), 최저점 학생(학번,점수) : %s(%d, %d), 평균 : %d", student[best_student_idx].name, student[best_student_idx].studentcode, 
        student[best_student_idx].grade, student[worst_student_idx].name,student[worst_student_idx].studentcode,student[worst_student_idx].grade, avg);
    
    fclose(fp);

    return 0;
}


