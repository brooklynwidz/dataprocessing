#include <stdio.h>

void student(int row, int col, int students[row][col]);
void avg(int row, int col, int marks[row][col]);
void highest(int row, int col, int marks[row][col]);
int highestmarks(int row, int col, int marks[row][col],int a[]);
void highestPerSubject(int row, int col, int a[row][col]);


int main()
{
    int highestmarkbystudent[2];
    int studentcount, subjectcount;
    printf("enter number of student: ");
    scanf("%d", &studentcount);
    printf("enter number of subject: ");
    scanf("%d", &subjectcount);
    int students[studentcount][subjectcount];
    // calling of functions
    student(studentcount, subjectcount, students);
    avg(studentcount, subjectcount, students);
    highest(studentcount,subjectcount,students);
    highestPerSubject(studentcount,subjectcount,students);
    highestmarks(studentcount,subjectcount,students,highestmarkbystudent);
    printf("highest individual marks %d obtained by %d \n",highestmarkbystudent[0],highestmarkbystudent[1]);
}


void student(int row, int col, int students[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // printf("mark of student %d on subject %d is: ", i,j);
            printf("student %d: mark of subject %d: \t", i, j);
            scanf("%d", &students[i][j]);
        }
    }
}

void avg(int row, int col, int marks[row][col])
{
    float avg[row];
    for (int i = 0; i < row; i++)
    {
        float sum = 0;
        for (int j = 0; j < col; j++)
        {
            // printf("marks of student %d of subject %d is %d\n", i, j, *(*(marks + i) + j));
            sum += *(*(marks + i) + j);
        }
        printf("%f\n", sum);
        avg[i] = sum / col;
    }
    for (int i = 0; i < row; i++)
    {
        printf("Average marks of student %d is %f\n", i, avg[i]);
    }
}

void highest(int row, int col, int marks[row][col]){
    int highestmarks = 0;
    int higheststudent = 0;

    for (int i =0;i<row;i++){
        int total = 0;
        for (int j = 0; j<col; j++){
            total+=*(*(marks+i)+j);
        }
        if (total>highestmarks){
            highestmarks = total;
            higheststudent = i;
        }
    }

    printf("highest marks obtained by student %d is %d\n",higheststudent, highestmarks);
}

int highestmarks(int row, int col, int marks[row][col],int a[]){
    int highest = 0;
    int student = 0;
    for (int i = 0; i<row; i++ ){
        for (int j = 0; j<col; j++){
            if (*(*(marks+i)+j)>highest){
                highest=*(*(marks+i)+j);
                student = i;
            }
        }
    }
    a[0] = highest;
    a[1] = student;
}

// a[2][3] = {{34,45,56},{31,23,45}};

void highestPerSubject(int row, int col, int marks[row][col]){
    for (int i = 0; i<col; i++){
        int highest = 0;
        int subject = 0;
        for (int j = 0; j<row; j++){
            if(*(*(marks + j) + i)>highest){   //changing the row which is student first 34 then it will check for the second student by changing the row
                highest = marks[j][i];
                subject = i;
            }
        }
        printf("highest marks in subject %d is %d\n", subject,highest);
    }
}