#include <iostream>
using namespace std;
int main() {
	int p[3]={14,10,6};
	int a1,b2,c3;
    for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
            for (int k = 0; k <= 1; ++k) {
            	int a = i * 14;
                int b = j * 10;
                int c = k * 6;
                cout << i << " " << j << " " << k <<"\t"<<a<< " " <<b<< " " <<c<<endl;
            }
        }
    }
    cout<<endl; 
    int i2,j2,k2;
    for (i2 = 0; i2<3; i2++) {
    	a1=p[i2];
    	cout<<a1<<" ";
        for (j2 = 0; j2<3; j2++) {
        	b2=p[j2];
        	cout<<b2<<" ";
            for (k2 = 0; k2<3; k2++) {
            	c3=p[k2];
            	cout<<c3<<endl;
            }
        }
    }
    return 0;
}
