#pragma once
class complex
{
private:
	double re_,im_;
public:
	complex(void);
	~complex(void);
	complex(double  x,double y){re_ = x,im_ = y};
	double re()const{return re_;}
	double im()const{return im_;}
	friend complex operator+(const complex&,const complex&);
	friend complex operator+(const double&,const complex&);
	friend complex operator+(const complex&,const double&);
	friend complex operator-(const complex&,const complex&);
	friend complex operator-(const double&,const complex&);
	friend complex operator-(const complex&,const double&);
	friend complex operator*(const complex&,const complex&);
	friend complex operator*(const double&,const complex&);
	friend complex operator*(const complex&,const double&);
	friend complex operator/(const complex&,const complex&);
	friend complex operator/(const double&,const complex&);
	friend complex operator/(const complex&,const double&);

};

