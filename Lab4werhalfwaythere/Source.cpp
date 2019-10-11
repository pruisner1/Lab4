/*
Lane Pruisner
C++ Fall 2019
Due: October 10, 2019
Lab 4 Temperature output
Explanation:Design and write a C++ program that inputs a series of hourly temperature
from a file, and outputs a bar chart (using stars) of the temperatures for the day. The
temperature should be printed to the left of the corresponding bar, and there should be
a heading that gives the scale of the chart. The range of temperatures should be from
-30 to 120. Because it is hard to display 150 characters on the screen, you should have
each star represent a range of 3 degrees. That way, the bars will be at most 50
characters wide. Use meaningful variable names, proper indentation, and appropriate
comments. Thoroughly test the program using your own data sets. Make sure to vet the
values from the input file.
*/
//These are the libraries I used
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

float temp;// Numbers from input file
void stars();//void function
void line();//void function
void negatives();//void function
float negtemp;//converts temp to neg temp, easier to read

int main()
{
	string inputtempfile = "C:/Users/PRUISNER1/source/repos/Lab3woohoo/intemp.dat";
	ifstream infile;
	
	infile.open(inputtempfile);
	
	cout << "Temperatures: " << endl; //formatting for graph
	cout << setw(17) << "-30" << setw(10) << "0" << setw(11) << "30" << setw(11) << "60" << setw(11) << "90" << setw(12) << "120" << endl;
	infile >> temp;// pulls temp out of the input file
	while (infile)//repeating process
	{
		if (temp >= -30 && temp <= 120)//Checks if number is in the right range
		{
			cout << setw(8) << temp;// formatting for temps on side of graph
			stars();// runs void stars()
		}
		infile >> temp;// pulls second temp then repeats
		if (temp < -30 || temp > 120)// checks for invalid temps
		{
			cout << setw(18) << "Input is invalid" << endl;//outputs if number is invalid
		}
		if (!infile)
		{
			cout << "Input is not valid or program is done" << endl;// if a letter is input file it ends the program
			return 1;
		}
	}
	return(0);//end of program
}
void line()// spacing for positive numbers
{
	cout << "\t" << "          " << "|";
}
void negatives()//spacing for negative numbers
{
	negtemp = temp;//changing variable to make more sense
	negtemp = (-30 - negtemp);
	cout << "\t";
	while (negtemp <= -2.5)//outputs spaces before the stars to make it even with the 0
	{
		negtemp = (negtemp + 3);
		cout << " ";
	}
}
void stars()//outputs all the stars in the program
{
	if (temp < 0)// for negative numbers
	{
		negatives();//runs void negative()
		while (temp < -.5)//outputs star until temp is greater than -.5, .5 is for rounding up
		{
			temp = (temp + 3);
			cout << "*";
		}
		cout << "|";
	}
	else if (temp >= 0)// for positive numbers
	{
		line();// runs void line()
		while (temp >= .5)//outputs star until temp is less than .5, .5 for rounding up
		{
			temp = (temp - 3);
			cout << '*';
		}
	}
	cout << endl;
}
