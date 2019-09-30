#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define TOTAL 10

void readName(char * name);
int readTotals(char *type);
void fillArray(char * type, int array[], int total);
double calcAvg(int array[], int total);
void displayAverage(char * type, double avg);
double calcWeighted(double labAvg, double LABP, double hwAvg, double HWP, double quizAvg, double QUIZP, double examAvg, double EXAMP);
double calcGrade(double weightedAvg);
void display(double weightedAvg, double finalGrade);


const double LABP = .2, HWP = .3, QUIZP = .11, EXAMP = .39;

int main()
{
    char name[MAX];
    int hwTotal, quizTotal, labsTotal, examsTotal;
    int hw[TOTAL], quizzes[TOTAL], labs[TOTAL], exams[TOTAL];
    double labAvg, hwAvg, quizAvg, examAvg, weightedAvg, finalGrade;

    readName(name);

    labsTotal = readTotals("Labs");
    fillArray("Labs", labs, labsTotal);
    labAvg = calcAvg(labs,labsTotal);
    displayAverage("Lab", labAvg);






    hwTotal = readTotals("Homeworks");
    fillArray("Homeworks", hw, hwTotal);
    hwAvg = calcAvg(hw,hwTotal);
    displayAverage("Homework", hwAvg);





    quizTotal = readTotals("Quizzes");
    fillArray("Quizzes", quizzes, quizTotal);
    quizAvg = calcAvg(quizzes, quizTotal);
    displayAverage("Quiz", quizAvg);




    examsTotal = readTotals("Exams");
    fillArray("Exams", exams, examsTotal);
    examAvg = calcAvg(exams,examsTotal);
    displayAverage("Exam", examAvg);




    weightedAvg = calcWeighted(labAvg, LABP, hwAvg, HWP, quizAvg, QUIZP, examAvg, EXAMP);
    finalGrade = calcGrade(weightedAvg);

    display(weightedAvg, finalGrade);

    return 0;
}// end main


void readName(char * name)
{
    printf("Please enter your name: ");
    fgets(name,MAX,stdin);
}// end readName


int readTotals(char *type)
{
    int numOf = 11;

    while (numOf >  TOTAL)
    {
        printf("Please enter the number of scores you are inserting for %s \n -----> ",type);
        scanf("%d", &numOf);
    }

}// end readTotals


void fillArray(char * type, int array[], int total)
{
	int x;
	for(x = 0; x < total; x++)
	{
		printf("Enter your score for %s \n", type);
		scanf("%d",&array[x]);
	}

    //will do later.
	
}// end fillArray


double calcAvg(int array[], int total) {
    double avg;
    int totalArray;
    int x;

    for (x = 0; x < total; x++)
    {
        totalArray = totalArray + array[x];
    }

    avg = totalArray / total;

	return avg;
}// end calcAvg


void displayAverage(char * type, double avg)
{
	printf("The average for %s is: %.1lf%% \n",type,avg);
}// end displayAverage


double calcWeighted(double labAvg, double LABP, double hwAvg, double HWP, double quizAvg, double QUIZP, double examAvg, double EXAMP)
{
    double total, foo;

    foo = labAvg * LABP;
    total += foo;

    foo = hwAvg * HWP;
    total += foo;

    foo = quizAvg * QUIZP;
    total += foo;

    foo = examAvg * EXAMP;
    total += foo;

	return total;
}// end calcWeighted


double calcGrade(double weightedAvg)
{

    double total;

    total = 100 - weightedAvg;
    total = total / 12;
    total = 4.2 - total;


	return total;
}// end calcGrade


void display(double weightedAvg, double finalGrade)
{
    printf("Your weighted percentage is: %.1lf%% \n",weightedAvg);
    printf("Your final grade is: %.1lf \n", finalGrade);

}// end display

