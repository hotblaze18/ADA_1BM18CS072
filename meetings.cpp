#include<iostream>

using namespace std;


struct meeting {
int start;
int end;
};

void isort(meeting a[], int n) {
	for(int i=0; i<n; i++) {
		int ele = a[i+1].end;
		for(int j=i; j>=0; j--) {
			if(a[j].end > ele) {
				swap(a[j], a[j+1]);
			}
			else break;
		}
	}
}

int max_meetings(meeting m[], int n) {
	isort(m, n);
	int c = 0;
	int i = 0;
	int j = i+1;
	while(j <= n) {
        if(m[j].start < m[i].end) {
            j++;
        }
        else {
            i = j;
            j++;
            c++;
        }
	}
return c;
}

int main() {
	int n;
	cout << "Enter the no. of meetings\n";
	cin >> n;
	meeting m[n];
	for(int i=1; i<=n; i++) {
		cin >> m[i].start >> m[i].end;
	}
	cout << max_meetings(m, n);
}

