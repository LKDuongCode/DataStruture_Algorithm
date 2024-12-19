#include<stdio.h>
#include <string.h>
// cau truc sinh vien
typedef struct Student {
	char name[50];
	int score;
}Student;
void printStudents (Student students[], int size){
	for(int i = 0; i<size; i++){
		printf("student[%d] :  name = %s | score = %d \n",i, students[i].name, students[i].score);
	}
}

void findStudent(Student students[], int size){
	int found = 0;
	char nameFound[50];
	printf("nhap ten sinh vien can tim: ");
	fgets(nameFound,sizeof(nameFound),stdin);
	nameFound[strcspn(nameFound,"\n")] = 0;
	
	for(int i = 0; i< size; i++){
		if(strcmp(students[i].name, nameFound) == 0){
			//ham strcmp() nhan vao hai mang char[] => 0 neu hai mang = nhau
			// => -1 neu char[]1 < char[]2 theo tu dien
			// => neu nguoc lai			
			printf("diem cua %s la %d", students[i].name, students[i].score);
			found = 1;
			break;
		}
	}
	if(found == 0){
		printf("khong tim thay ten sinh vien!");
	}
}
int main(){
	printf("nhap so luong sinh vien: ");
	int n;
	scanf("%d",&n);
	getchar();
	Student students[n];
	
	for(int i = 0; i<n; i++){
		printf("student[%d].name = ",i);
	 	fgets(students[i].name, sizeof(students[i].name), stdin);
	 	students[i].name[strcspn(students[i].name, "\n")] = 0; // xoa ki tu newline
		printf("student[%d].score = ",i);
		scanf("%d",&students[i].score);
		getchar();
		
	}
	
	printStudents(students,n);
	findStudent(students,n);
	
	return 0;
}


