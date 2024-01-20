#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, type) { type temp; temp = x; x = y; y = temp; }

typedef struct{//학생 데이터 구조체
    int id;
    int math;
    int info;
} STUDENT;

int main()
{
    STUDENT *std, temp;
    int n, max;

    scanf("%d", &n);
    std = (STUDENT *)malloc(sizeof(STUDENT) * n);//동적 할당
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &std[i].math, &std[i].info);//수학, 정보 점수
        std[i].id = i + 1;//학생 번호
    }

    for (int i = 0; i < n - 1; i++)//선택 정렬
    {
        max = i;
        for (int j = i + 1; j < n; j++)
        {
            if (std[max].math < std[j].math)//수학 점수가 높은 학생
            {
                max = j;
            }
            else if (std[max].math == std[j].math)//수학 점수 같을 때
            {
                if (std[max].info < std[j].info)//정보 점수가 높은 학생
                {
                    max = j;
                }
                else if (std[max].info == std[j].info)//정보 점수 같을 때
                {
                    if (std[max].id > std[j].id)//학생 번호가 높은 학생
                    {
                        max = j;
                    }
                }
            }
        }
        if (i != max)//제자리가 아닌 경우
        {
            SWAP(std[i], std[max], STUDENT);//바꾸기
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", std[i].id, std[i].math, std[i].info);
    }

    free(std);

    return 0;
}