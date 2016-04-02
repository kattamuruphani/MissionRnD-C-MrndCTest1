/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int days_cal(int*, int*);
struct node{
	int data;
	struct node *next;
};


int between_days(struct node *date1head, struct node *date2head){
	int mul = 10, year1[3], year2[3],i=0;
	if (date1head==NULL||date2head==NULL)

		return -1;
	else{
		for (i = 0; i < 3; i++){
			year1[i] = 0;
			year2[i] = 0;
		}
		for (i = 0; i < 2; i++){
			year1[0] *= mul;
			year2[0] *= mul;
			year1[0] += date1head->data;
			year2[0] += date2head->data;
			date1head = date1head->next;
			date2head = date2head->next;
			mul = 10;
		}
		mul = 1;
		for (i = 0; i < 2; i++){

			year1[1] *= mul;
			year2[1] *= mul;
			year1[1] += date1head->data;
			year2[1] += date2head->data;
			date1head = date1head->next;
			date2head = date2head->next;
			mul = 10;

		}
		mul = 1;
		for (i = 0; i < 4; i++){

			year1[2] *= mul;
			year2[2] *= mul;
			year1[2] += date1head->data;
			year2[2] += date2head->data;
			date1head = date1head->next;
			date2head = date2head->next;
			mul = 10;

		}
	}
	return days_cal(year1, year2);
}


int days_cal(int *year1, int *year2){

	int years, months, days = 0, start, x, y, i, leaps = 0;
	int months_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	x = year1[2];
	y = year2[2];
	if (y - x >= 4){
		start = year1[2] % 4;
		if (start > 0){
			x += 4 - start;
		}
		for (i = x+1; i < y; i = i + 4){

		}
		leaps = i;

	}
	years =( y - x)-1;
	days += (years - leaps) * 365 + leaps * 366;
	x = year1[1];
	y = year2[1];

	for (i = year1[1]; i < 12; i++){
		if (i == 1 && year1[2] % 4 == 0){
			if (year1[2] % 100 == 0 && year1[2] % 400 != 0){
				days += months_days[i];
			}
			else{
				days += months_days[i]+1;
			}
		}
		else{
			days += months_days[i];
		}
	}
	for (i = 0; i < year1[1]-1 ; i++){
		if (i == 1 && year1[2] % 4 == 0){
			if (year2[2] % 100 == 0 && year2[2] % 400 != 0){
				days += months_days[i];
			}
			else{
				days += months_days[i] + 1;
			}
		}
		else{
			days += months_days[i];
		}
	}
	if (year1[1] == 2 && year1[2] % 4 == 0){
		if (year2[2] % 100 == 0 && year2[2] % 400 != 0){
			days += months_days[i]-year1[1]+1;
		}
		else{
			days += months_days[i] -year1[1];
		}
	}
	else{
		days += months_days[i] - year1[1];
	}
	days += year2[0];



	return days;

}