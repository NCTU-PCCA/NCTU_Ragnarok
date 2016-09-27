const double eps=1E-7;
struct PT{
    double x,y;
    PT(){}
    PT(double x,double y):x(x),y(y){};
    PT operator+(const PT& p) const {return PT(x+p.x,y+p.y);
    }
    PT operator-(const PT& p) const {return PT(x-p.x,y-p.y);
    }
    PT operator*(double c) const {return PT(c*x,c*y);
    }
    PT operator/(double c) const {return PT(c*x,c*y);
    }
    double operator*(const PT& p) const {return x*p.x+y*p.y;
    }
    double operator^(const PT& p) const {return x*p.y-y*p.x;
    }
    double len2() const {return x*x+y*y;
    }
    double len() const {return sqrt(x*x+y*y);
    }
    PT Unit() const {return *this / len();
    }
    PT Verticle() const {
        return PT(-y,x);
    }
    PT Rotate(double a) const {
        return PT(cos(a)*x-sin(a)*y,sin(a)*x+cos(a)*y);
    }
};

int orientation(const PT p1,const PT& p2,const PT& p3){
    double a = (p2-p1)^(p3-p1);
    if(-eps < a && a < eps)return 0;
    return a > 0 ? 1: -1;
}

bool opposite(const PT& p1,const PT& p2,const PT& p3){
    return (p2-p1)*(p3-p1) < 0;
}

int segmentIntersection(const PT& p1,const PT& p2,const PT& p3,const PT& p4){
    int a123 = orientation(p1,p2,p3);
    int a124 = orientation(p1,p2,p4);
    int a341 = orientation(p3,p4,p1);
    int a342 = orientation(p3,p4,p2);
    if(a123 == 0 && a124 == 0)
        return opposite(p1,p3,p4)||opposite(p2,p3,p4)||opposite(p3,p1,p2)||opposite(p4,p1,p2);
    else if(a123*a124 <= 0 && a341*a342 <= 0)
        return true;
    return false;
}
