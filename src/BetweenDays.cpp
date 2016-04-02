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

struct node{
	int data;
	struct node *next;
};
int total_days(int month, int year)
{
	int count = 0, i;
	int range[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (i = 0; i<month - 1; i++)
	{
		if (i == 1)
		{
			if (year % 4 == 0)
				count += 29;
			else
				count += 28;
		}
		else
			count += range[i];
	}
	return(count);
}

int between_days(struct node *date1head, struct node *date2head){
	int i = 0, d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0,count=0;
	while (i < 8)
	{
		if (i< 2)
		{
			d1 = (d1 * 10) + date1head->data;
			d2 = (d2 * 10) + date2head->data;
			date1head = date1head->next;
			date2head = date2head->next;
		}
		else if (i < 4)
		{
			m1 = (m1 * 10) + date1head->data;
			m2 = (m2 * 10) + date2head->data;
			date1head = date1head->next;
			date2head = date2head->next;
		}
		else
		{
			y1 = (y1 * 10) + date1head->data;
			y2 = (y2 * 10) + date2head->data;
			date1head = date1head->next;
			date2head = date2head->next;
		}
		i++;
	}
	count = 0;
	
	for (i = y1; i<y2; i++)
	{
		if (i % 4 == 0)
			 count+= 366;
		else
			count += 365;
	}
	count -= total_days(m1, y1);
	count -= d1;
	count += total_days(m2, y2);
	count += d2;
	if (count<0)
		count = count*-1;

	return count;
}