#include <bits/stdc++.h>

using namespace std;
int main() {
	system(
			"g++ -lm -O2 -std=c++11 -pipe -o ac.exe ./solved/uvaStreetDirectionsAC.cpp");
	system(
			"g++ -lm -O2 -std=c++11 -pipe -o wa.exe ./solved/uvaStreetDirectionsWA.cpp");
	int tc = 1;
	while (1) {
		ofstream ofs("test.in");
		int t = 2;
		//	ofs << t << endl;
		while (t--) {
			int n = rand() % 3 + 2, m = min(rand()%((n*(n-1))/2),4);
			ofs << n << " " << m << endl;
			set<pair<int, int> > edgs;
			while (m--) {
				tany:{
					int x = rand() % n + 1;
					int y = rand() % (n - 1) + 1;
					if (y >= x)
						y++;
					if(!edgs.insert({min(x,y),max(x,y)}).second)
						goto tany;
					ofs << x << " " << y << endl;
				}
			}
		}
		ofs << "0 0" << endl;
		ofs.close();
		system("ac.exe <test.in >ac.txt");
		system("wa.exe <test.in >wa.txt");
		ifstream acs("ac.txt");
		ifstream was("wa.txt");
		string ac, wa;
		getline(was, wa, (char) EOF);
		getline(acs, ac, (char) EOF);
		was.close();
		acs.close();
		cerr << tc++ << endl;
		if (ac != wa)
			break;
	}
}
