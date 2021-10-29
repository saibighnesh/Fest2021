#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


//hw scores and the class participation score, maximum 50.
float compute_hw_participation(istream& infile)
{
float hw, part, hwp; float total=0;
cout << " Scores are: ";
for(int i=1; i <= 11; i++)
{
infile >> hw;
infile >> part;
hwp = hw + part;
cout << hwp << endl;
}
return total;
}

//score on the tests, maximum 50.
float compute_tests(float tests, istream& infile)
{

infile >> tests;
cout << " tests are " << tests << endl;
return 0.0;
}



float hwp, tests;
//homework and participation + tests, maximum 100.
float compute_totalscore(float totalscore)
{
totalscore = hwp + tests;
cout << " Total score is " << totalscore << endl;
return 0.0;
}



char GetGrade(float totalscore)
{
char grade;
if (totalscore >= 90)
{

grade = 'A';}
else
{

if (totalscore >= 80)
{

grade = 'B';}
else
{

if (totalscore >= 70)
{

grade = 'C';}
else
{

if (totalscore >= 60)
{

grade = 'D';}
else
{

if (totalscore < 60)
{

grade = 'F';}
}
}
}
}
return grade;
}



void printRecord (char name[20], char Id[8], float hwp, float tests, float totalscore, float grade, ostream& outfile)
{
outfile << "Name: "<< name << endl
<< "Id: "<< Id << endl
<< "Homework/Participation: " << hwp << endl
<< "Tests: " << tests << endl
<< "Total course score: " << totalscore << endl
<< "Letter Grade: " << grade << endl
<<"-------------------------------------------------"<<endl<< endl;
}

int main()
{
ofstream outfile;
ifstream infile;


char file_name[21], name[20], Id[20];

float hwp, tests, totalscore;
int deductions;

cout << "Please enter name of input file: ";
cin >> file_name;
infile.open(file_name);
if ( !infile)
{
// abandons operation with error mesg
cout << "Could not open input file \n";
return 0;
}


outfile.open("ScoreResult");
if ( !outfile)
{
cout << "Could not open output file \n";
return 0;
}


infile >> name;
while(!infile.eof())
{
infile >> Id;
cout << name << " " << Id << endl;
hwp = compute_hw_participation(infile);
tests = compute_tests(tests, infile);
totalscore = compute_totalscore(totalscore);
char grade = GetGrade(totalscore);
// grade
printRecord(name, Id, hwp, tests, totalscore, grade, outfile);
infile >> name;
}

return 0;
}
