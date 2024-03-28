#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
vector<ll> f(ll x1, ll y1, ll x2, ll y2){
	vector<ll> ret(6,0);
	if(x1>x2 || y1>y2) return ret;
	if(x2-x1>5 && y2-y1>5) return ret;
	if((x1/5+y1/5)%2){
		ret[y2-y1]+=x2-x1;
	}
	else{
		ret[x2-x1]+=y2-y1;
	}
	return ret;
}
int main(){
	ll x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;

	vector<ll> r(6,0);
	vector<ll> t(6,0);
	ll xx1,yy1,xx2,yy2; // 5,5 격자에 맞춘 값
	xx1=x1+(5-x1%5)%5;
	yy1=y1+(5-y1%5)%5;
	xx2=(x2/5)*5;
	yy2=(y2/5)*5;
	// cout << "xx1 : " << xx1 << ", yy1 : " << yy1 << ", xx2 : " << xx2 << ", yy2 : " << yy2  << '\n';
	if(xx1>xx2 && yy1>yy2){ // 같은 영역 안에 있음
		t=f(x1,y1,x2,y2);
		for(int j=1; j<=5; ++j){
			r[j]+=t[j];
		}
	}
	else if(xx1>xx2){
		if(y1%5){
			t=f(x1,y1,x2,(y1/5+1)*5);
			for(int j=1; j<=5; ++j){
				r[j]+=t[j];
			}
			y1=(y1/5+1)*5;
		}
		if(y2%5){
			t=f(x1,(y2/5)*5,x2,y2);
			for(int j=1; j<=5; ++j){
				r[j]+=t[j];
			}
			y2=(y2/5)*5;
		}
		for(int i=y1; i<y2; i+=5){
			t=f(x1,i,x2,i+5);
			for(int j=1; j<=5; ++j){
				r[j]+=t[j];
			}
		}
	}
	else if(yy1>yy2){
		if(x1%5){
			t=f(x1,y1,(x1/5+1)*5,y2);
			for(int j=1; j<=5; ++j){
				r[j]+=t[j];
			}
			x1=(x1/5+1)*5;
		}
		if(x2%5){
			t=f((x2/5)*5,y1,x2,y2);
			for(int j=1; j<=5; ++j){
				r[j]+=t[j];
			}
			x2=(x2/5)*5;
		}
		for(int i=x1; i<x2; i+=5){
			t=f(i,y1,i+5,y2);
			for(int j=1; j<=5; ++j){
				r[j]+=t[j];
			}
		}
	}
	else{
		r[5]+=(((xx2-xx1)/5)*((yy2-yy1)/5))*5;
		//구해야 할 구역은 총 8 구역
		// 1. (x1,y1) ~ (xx1,yy1)
		if(x1<xx1 && y1<yy1){
		    t=f(x1,y1,xx1,yy1);
		    for(int j=1; j<=5; ++j){
			    r[j]+=t[j];
		    }
		}
	
		// 2. (xx1,y1) ~ (xx2,yy1)
		if(xx1<xx2 && y1<yy1){
		    r[5]+=((xx2-xx1)/10)*(yy1-y1);
		    r[yy1-y1]+=((xx2-xx1)/10)*5;
		    if((xx2-xx1)%10==5){
			    t=f(xx1,y1,xx1+5,yy1);
			    for(int j=1; j<=5; ++j){
				    r[j]+=t[j];
			    }
		    }
		}
		// 3. (xx2,y1) ~ (x2,yy1)
		if(xx2<x2 && y1<yy1){
		    t=f(xx2,y1,x2,yy1);
		    for(int j=1; j<=5; ++j){
			    r[j]+=t[j];
		    }
		}
		// 4. (x1,yy1) ~ (xx1,yy2)
		if(x1<xx1 && yy1<yy2){
		    r[5]+=((yy2-yy1)/10)*(xx1-x1);
		    r[xx1-x1]+=((yy2-yy1)/10)*5;
		    if((yy2-yy1)%10==5){
			    t=f(x1,yy1,xx1,yy1+5);
			    for(int j=1; j<=5; ++j){
				    r[j]+=t[j];
			    }
		    }
		}
		
		// 5. (xx2,yy1) ~ (x2,yy2)
		if(xx2<x2 && yy1<yy2){
		    r[5]+=((yy2-yy1)/10)*(x2-xx2);
		    r[x2-xx2]+=((yy2-yy1)/10)*5;
		    if((yy2-yy1)%10==5){
			    t=f(xx2,yy1,x2,yy1+5);
			    for(int j=1; j<=5; ++j){
				    r[j]+=t[j];
			    }
		    }
		}
		// 6. (x1,yy2) ~ (xx1,y2)
		if(x1<xx1 && yy2<y2){
		    t=f(x1,yy2,xx1,y2);
		    for(int j=1; j<=5; ++j){
			    r[j]+=t[j];
		    }
		}
		// 7. (xx1,yy2) ~ (xx2,y2)
		if(xx1<xx2 && yy2<y2){
	    	r[5]+=((xx2-xx1)/10)*(y2-yy2);
		    r[y2-yy2]+=((xx2-xx1)/10)*5;
		    if((xx2-xx1)%10==5){
			    t=f(xx1,yy2,xx1+5,y2);
			    for(int j=1; j<=5; ++j){
				    r[j]+=t[j];
			    }
		    } 
		}
		// 8. (xx2,yy2) ~ (x2,y2)
		if(xx2<x2 && yy2<y2){
		    t=f(xx2,yy2,x2,y2);
		    for(int j=1; j<=5; ++j){
			    r[j]+=t[j];
		    }
		}
	}
	ll res=0;
	ll k;
	// vector<ll> spare(6,0);
	// for(int i=5; i>=1; --i){
	// 	// i를 만들어야 함.
	// 	r[i]-=spare[i];
	// 	spare[i]=0;
	// 	// r[i]로 5만들기
	// 	// r[i]로는 최대 (5/i)*i를 만들 수 있고, 그 때 나오는 spare는 5-((5/i)*i) 이다.
	// 	// (5/i)*i를 만들 때 사용하는 i의 개수는 5/i개이고, 
	// }
	
	//5
	res+=r[5];
	r[5]=0;
	k=min(r[4],r[1]);
	res+=k;
	r[4]-=k;
	r[1]-=k;
	k=min(r[3],r[2]);
	res+=k;
	r[3]-=k;
	r[2]-=k;
	k=min(r[3],r[1]/2);
	res+=k;
	r[3]-=k;
	r[1]-=k*2;
	k=min(r[2]/2,r[1]);
	res+=k;
	r[2]-=k*2;
	r[1]-=k;
	k=min(r[2],r[1]/3);
	res+=k;
	r[2]-=k;
	r[1]-=k*3;
	res+=r[1]/5;
	r[1]%=5;
	//4
	res+=r[4];
	r[4]=0;
	k=min(r[3],r[1]);
	res+=k;
	r[3]-=k;
	r[1]-=k;
	res+=r[2]/2;
	r[2]%=2;
	k=min(r[2],r[1]/2);
	res+=k;
	r[2]-=k;
	r[1]-=k*2;
	res+=r[1]/4;
	r[1]%=4;
	//3
	res+=r[3];
	r[3]=0;
	k=min(r[2],r[1]);
	res+=k;
	r[2]-=k;
	r[1]-=k;
	res+=r[1]/3;
	r[1]%=3;
	//2
	res+=r[2];
	r[2]=0;
	res+=r[1]/2;
	r[1]%=2;
	//1
	res+=r[1];
	cout << res << '\n';
	
}