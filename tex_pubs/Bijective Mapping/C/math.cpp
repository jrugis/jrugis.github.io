#include <fstream.h>
#include <math.h>
#include <iomanip.h>
#define NSIZE 10000002
#define ASIZE 270000000

// find smallest unused integer in array
//  unused integers are marked with a '1'
//  used integers are marked with a '0'
int smallest(int *prev_int, short int a[]){
	int i=*prev_int;
	while(i<ASIZE){
		if(a[i]!=0){
			*prev_int=i;
			return i;
		};
		i++;
	}
	return(0);
}

void main(){
	int n;
	int smallf=0;
	int smallg=0;
	int fvalue, gvalue;
	static short int f[ASIZE], g[ASIZE];

	// initialize the integer arrays
	for(n=0; n<ASIZE; n++){
		f[n]=1;
		g[n]=1;
	};

	cout << setprecision(12);

	for(n=0; n<NSIZE; n++){
		if(n==0){
			fvalue=0;
			gvalue=0;
		}
//		else if(n==1){
//			fvalue=3;
//			gvalue=-1;
//		}
		// odd
		else if(n%2!=0){
			gvalue=-1*smallest(&smallg,g);
			fvalue=(13*n)-gvalue;
		}
		// even
		else{
			fvalue=-1*smallest(&smallf,f);
			gvalue=(13*n)-fvalue;
		};
		f[abs(fvalue)]=0;
		g[abs(gvalue)]=0;

		// output complete list of f and g values
		if((n>=99)&(n<=101))
		cout << n << " " << fvalue << " " << gvalue << " " << (double)gvalue/fvalue << endl;
		if((n>=999)&(n<=1001))
		cout << n << " " << fvalue << " " << gvalue << " " << (double)gvalue/fvalue << endl;
		if((n>=9999)&(n<=10001))
		cout << n << " " << fvalue << " " << gvalue << " " << (double)gvalue/fvalue << endl;
		if((n>=99999)&((n<=100001)))
		cout << n << " " << fvalue << " " << gvalue << " " << (double)gvalue/fvalue << endl;
		if((n>=999999)&((n<=1000001)))
		cout << n << " " << fvalue << " " << gvalue << " " << (double)gvalue/fvalue << endl;
		if((n>=9999999)&((n<=10000001)))
		cout << n << " " << fvalue << " " << gvalue << " " << (double)gvalue/fvalue << endl;
	};

	// output the largest computed value of f and g
//	cout << n-1  << "   " << fvalue << "   " << gvalue << '\n';
}
