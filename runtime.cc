// The implementation file for the functions for the Runtime class

#include "runtime.h"
#include "mytime.h"
#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;


//Constructor

Runtime::Runtime()
{
	MyTime x;
	distance = 0;
	rtime = x;
}

//Opperators

Runtime Runtime:: operator + (const Runtime& rhs)const //adds the distances and rtimes with that of another Runtime
{
	Runtime tmp;

	tmp.distance = distance + rhs.distance;
	tmp.rtime = rtime + rhs.rtime;

	return tmp;
}

Runtime Runtime::operator - (const Runtime& rhs)const  //subtracts distances and rtimes of another Runtime from the first
{
	Runtime tmp;

	tmp.distance = distance - rhs.distance;
	tmp.rtime = rtime - rhs.rtime;

	return tmp;
}

Runtime Runtime:: operator * (const double& rhs)const //multiplies the distances and rtimes by a scalar
{
	Runtime tmp;

	tmp.distance = distance * rhs;
	tmp.rtime = rtime * rhs;

	return tmp;
}

Runtime Runtime:: operator / (const double& rhs)const //divides the rtime and distances by a scalar
{
	Runtime tmp;

	tmp.distance = distance / rhs;
	tmp.rtime = rtime / rhs;

	return tmp;
}

bool Runtime:: operator == (const Runtime& rhs)const //Returns true if both the rtime and distance are identical
{
	if((fabs(distance - rhs.distance) < 0.1) && (rtime == rhs.rtime))
		return true;

	else
		return false;
}

bool Runtime:: operator !=(const Runtime& rhs)const //Returns true if either the distances or rtimes are not equal
{
	if((fabs(distance - rhs.distance) < 0.1) && (rtime == rhs.rtime))
                return false;

        else
                return true;
}


void Runtime::input(std::istream& ins)
{
	char junk;
	ins>>rtime;
	ins.get(junk);
	ins>>distance;

}

void Runtime::output(std::ostream& outs)const
{
	outs<<rtime<<"\t"<<distance;
}
/*Runtime Runtime::operator *(const double& lhs, const Runtime& rhs)
{
*/
std::ostream& operator <<(std::ostream& outs, const Runtime& rhs)
{
	rhs.output(outs);
}

std::istream& operator >>(std::istream& ins, Runtime& rhs)
{
	rhs.input(ins);
}
