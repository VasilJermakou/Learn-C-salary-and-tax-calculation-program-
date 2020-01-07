#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>


#define STANDARTWORKHOURS 40						// 40 hour per week payd by standart WAGESRATE; if more => multiply EXTRARATE;
#define WAGESRATE 10.0								// $10.00 per hour;
#define EXTRARATE 1.5								// extra coefficient if worker works more than 40 hours per week;
#define FIRSTTAXRATE 15								// 15%;
#define SECONDTAXRATE 20							// 20%;
#define THIRDTAXRATE 25								// 25%;
#define BASEWAGES1 300								// salary <= $ 300.00
#define BASEWAGES2 450								// salary <= $ 450.00


double taxesCounter (double salary);				//prototype of functions



/*
===========
VAERPROJECT 
===========
*/


//TASK8

int main (void){

	//***********************************************************************
	double salaryRate,
		   workedHours,
	       salary,
	       taxes;

	salaryRate = workedHours = salary = taxes = 0;
	
	double totalSalary,
		   normalHours,
		   extraHours,
		   normaltSalary,
		   extraSalary;

	totalSalary = normalHours = extraHours = normaltSalary = extraSalary = 0;
	//***********************************************************************

	int status,
		scanValue;

	status = scanValue = 0;
	
	do
	{
		printf("\n******************************************************************************");
		printf("\nEnter number of desired rate by entering MENU numbers from 1 - 4 or 5 to EXIT:");
		printf("\n\n\t\t\t\t---===MENU===---\n");
		printf("\n1)$8.75 \t2)$9.33 \t3)$10.00 \t4)$11.20 \t5)EXIT");
		printf("\n: ");
		scanValue = scanf("%d", &status);

		if (status > 0 && status < 6)
			{
				switch(status)
					{
						case 1:
							salaryRate = 8.75;
							break;
						case 2:
							salaryRate = 9.33;
							break;
						case 3:
							salaryRate = 10.00;
							break;
						case 4:
							salaryRate = 11.20;
							break;
						case 5:
							break;
					}

					if(status > 0 && status < 5)
						{
							printf("\nPlease enter number of worked hours: ");
							scanf("%lf", &workedHours);
							printf("\nSALARY RATE:  \t\t\t%.2lf", salaryRate);
							printf("\nWORKED HOURS: \t\t\t%.2lf\n", workedHours);

							//counting BRUTTO salary (before taxes)
							if(workedHours > STANDARTWORKHOURS)
								{
									extraHours = workedHours - STANDARTWORKHOURS;
									normalHours = workedHours - extraHours;
									normaltSalary = normalHours * salaryRate;
									extraSalary = (extraHours * salaryRate) * EXTRARATE;
									totalSalary = normaltSalary + extraSalary;
								}
							else if(workedHours > 0 && workedHours <= STANDARTWORKHOURS)
								{
									totalSalary = workedHours * salaryRate;
								}
							else 
								{
									printf("\nYou entered unexeptable values!");
								}	

							//counting TAXES
							taxes = taxesCounter(totalSalary);


							//printing the results
							printf("\nYour BRUTTO salary: \t\t%.2lf", totalSalary);
							printf("\nYour TOTAL TAXES of salary: \t%.2lf", taxes);
							printf("\nYour NETTO salary: \t\t%.2lf", totalSalary - taxes);
						}	//end of iner if
			}	//end of if

		else if (scanValue == 0)
			{
				printf("\n\t\t===============================================");
				printf("\n\t\t|  WARNING: YOU ENTERED UNEXEPTABLE VALUE!!!  |");
				printf("\n\t\t|      ENTER ONLY POSITIVE INTEGERS!!!        |");
				printf("\n\t\t===============================================");
				printf("\n");
				continue;
			}	//end of else if

		else
			{
				printf("\n\t\t===============================================");
				printf("\n\t\t|  WARNING: YOU ENTERED UNEXEPTABLE VALUE!!!  |");
				printf("\n\t\t===============================================");
				printf("\n\n");
				continue;
			}	//end of else



	}while (status != 5 && scanValue != 0);


	printf("\n\t\t\t---===HAVE A GOOD DAY !!!===---\n");
	printf("\n");



	return 0;
}	//end of MAIN FUNCTION


//function that count taxes of Your salary

double taxesCounter (double salary)
{
	double firstPartSalaryTax,
		   secondPartSalaryTax,
		   thirdPartSalaryTax,
		   totalTax,
		   firstPartSalary,
		   secondPartSalary,
		   thirdPartSalary;

	firstPartSalaryTax = secondPartSalaryTax = thirdPartSalaryTax = totalTax = firstPartSalary = secondPartSalary = thirdPartSalary = 0;

	if(salary > 0 && salary <= BASEWAGES1)
		{
			firstPartSalaryTax = (salary * FIRSTTAXRATE) / 100;
			totalTax = firstPartSalaryTax;
		}
	else if(salary > 0 && salary <= BASEWAGES2)
		{
			secondPartSalary = salary - BASEWAGES1;
			firstPartSalary = salary - secondPartSalary;
			firstPartSalaryTax = (firstPartSalary * FIRSTTAXRATE) / 100;
			secondPartSalaryTax = (secondPartSalary * SECONDTAXRATE) / 100;
			totalTax = firstPartSalaryTax + secondPartSalaryTax;
		}
	else if(salary > 0 && salary > BASEWAGES2)
		{
			thirdPartSalary = salary - BASEWAGES2;
			secondPartSalary = (salary - thirdPartSalary) - BASEWAGES1;
			firstPartSalary = (salary - thirdPartSalary) - secondPartSalary;
			firstPartSalaryTax = (firstPartSalary * FIRSTTAXRATE) / 100;
			secondPartSalaryTax = (secondPartSalary * SECONDTAXRATE) / 100;
			thirdPartSalaryTax = (thirdPartSalary * THIRDTAXRATE) / 100;
			totalTax = firstPartSalaryTax + secondPartSalaryTax + thirdPartSalaryTax;  
		}
	else
		{
			printf("\nYou entered unexeptable values!");
		}

	return totalTax;
}