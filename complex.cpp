#include "complex.h"
#include<iostream>
#include<math.h>

using namespace std;
complex::complex(void)
{
}


complex::~complex(void)
{
}

complex operator+(const complex& x ,const complex& y )
{
	double zre = x.re() + y.re();
	double zim = x.im() + y.im();
	complex z(zre,zim);
	return z;
}

complex operator+(const double& x ,const complex& y )
{
	double zre = x + y.re();
	double zim = y.im();
	complex z(zre,zim);
	return z;
}

complex operator+(const complex& x ,const double& y )
{
	double zre = x.re() + y;
	double zim = x.im();
	complex z(zre,zim);
	return z;
}

complex operator-(const complex& x ,const complex& y )
{
	double zre = x.re() - y.re();
	double zim = x.im() - y.im();
	complex z(zre,zim);
	return z;
}

complex operator-(const double& x ,const complex& y )
{
	double zre = x - y.re();
	double zim = -y.im();
	complex z(zre,zim);
	return z;
}

complex operator-(const complex& x ,const double& y )
{
	double zre = x.re() - y;
	double zim = x.im();
	complex z(zre,zim);
	return z;
}

complex operator*(const complex& x ,const complex& y )
{
	double zre = x.re()*y.re() - x.im()*y.im();
	double zim = x.re()*y.re() + x.im()*y.im();
	complex z(zre,zim);
	return z;
}

complex operator*(const double& x ,const complex& y )
{
	complex z(x,0);
	return z*y;
}

complex operator*(const complex& x ,const double& y )
{
	complex z(y,0);
	return x*z;
}

complex operator*(const complex& x ,const complex& y )
{
	double zre = x.re()*y.re() + x.im()*y.im();
	double zim = x.re()*y.re() - x.im()*y.im();
	double m =y.re()*y.re() + y.im()*y.im();
	if (m>0)
	{
		zre/=m;zim/=m;
	}
	complex z(zre,zim);
	return z;
}

complex operator*(const double& x ,const complex& y )
{
	complex z(x,0);
	return z/y;
}

complex operator*(const complex& x ,const double& y )
{
	complex z(y,0);
	return x/z;
}

ostream& operator<<(ostream&t,const complex&c)
{
	double a =c.re(),b=c.im();
	if (fabs(b)<DBL_EPSILON)
	{
		t<<a;return t;
	}
	if (fabs(a)<DBL_EPSILON)
	{
		if (fabs(b-1)<DBL_EPSILON)
		{
			t<<"i";
		}
		else if (fabs(1+b)<DBL_EPSILON)
		{
			t<<"-i";
		}
		else t<<b<<"i";
		return t;
	}
	if (b>0)
	{
		if (fabs(b-1)<DBL_EPSILON)
		{
			t<<a<<"+i";
		}
		else 
			t<<a<<"+"<<b<<"i";
	}
	else
	{
		if (fabs(1+b)<DBL_EPSILON)
		{
			t<<a<<"-i";
		}
		else
			t<<a<<b<<"i";
	}
	return t;
}