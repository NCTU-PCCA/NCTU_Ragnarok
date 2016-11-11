const double eps = 1e-7;

struct Point{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
};

Point Circumcenter(Point a,Point b,Point c){  
    double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1*a1 + b1*b1)/2;  
    double a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2*a2 + b2*b2)/2;  
    double d = a1 * b2 - a2 * b1;  
    return Point(a.x + (c1*b2 - c2*b1)/d,a.y + (a1*c2 - a2*c1)/d);  
} 

double Distance(Point A,Point B){
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

// Expected Complexity : O(N)
pair<Point,double> MinimumCoverCircle(vector<Point> P){
	random_shuffle(P.begin(),P.end());
    Point center = P[0];
    double R = 0.0;
    for(int i=1;i<P.size();i++) if(Distance(center,P[i])+eps > R){
		center = P[i];R = 0.0;
		for(int j=0;j<i;j++) if(Distance(center,P[j])+eps > R){
			center.x=(P[i].x+P[j].x)/2.0;
			center.y=(P[i].y+P[j].y)/2.0;
			R = Distance(center,P[j]);
			for(int k=0;k<j;k++) if(Distance(center,P[k])+eps > R){
				center = Circumcenter(P[i],P[j],P[k]);  
				R = Distance(center,P[k]);
			}
		}
    }
	return make_pair(center,R);
}
