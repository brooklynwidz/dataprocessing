#include <stdio.h>

struct Student {

    char name[10];
    int age;
    int marks[3];

};

void percentage(struct Student user[]);
void data (struct Student user[]);



int main() {
    
    struct Student user[3] = {
        {"John",21,{87,54,89}},
        {"shawn",20,{82,78,90}},
        {"dash",20,{78,23,98}}
    };
    data(user);
    percentage(user);

}

void percentage(struct Student user[]){

    for (int i = 0;i<3;i++){
        float sum = 0;
        for (int j =0;j<3;j++){
            sum+=user[i].marks[j];
        }
        float per = (sum/300)*100;
        printf("Percentage of student %d is %f\n",i,per);

    }

}

void data(struct Student user[]){
    for (int i =0; i<3; i++){
        printf("\nName of student %d is %s\n",i,user[i].name);
        printf("Age of student %d is %d\n",i,user[i].age);
        for (int j = 0; j<3; j++){
            printf("marks of student %d in subject %d is %d\n",i,j,user[i].marks[j]);
        }
        printf("\n\n");
    }
}
