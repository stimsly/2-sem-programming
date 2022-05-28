#include "all.h"

bool check(char a[100], char b[100], int aa, int bb) {
	
	if (aa != bb) return 0;
	for (int i = 0; i < aa; i++) if (a[i] != b[i]) return 0;
	return 1;
}

void all::progress(ofstream &fout_rep,int &res) {
	while (1) {
		char mat[100][30];
		int mat_k[100]{};
		int mat_am = 0;
		int mat_s[100];
		char req[100][30];
		int req_k[100]{};
		int req_am = 0;
		int req_s[100];
		//cout << "niccce";
		mater.calc(mat, mat_k, mat_s, mat_am);
		prod.calc(req, req_k, req_s, req_am);
		//cout << "no";
		report a;
		for (int i = 0; i < req_am; i++) {
			for (int j = i + 1; j < req_am; j++) {
				if (req_s[j] and req_s[i]) {
					if (check(req[i], req[j], req_s[i], req_s[j])) {
						req_k[i] += req_k[j];
						req_k[j] = 0;
						req_s[j] = 0;

					}
				}
			}
		}

		int rounds = 0;

		while (1) {
			//a.output_mes("This man try to bake next round#", fout_rep);
			int x = 1;
			for (int i = 0; i < mat_am; i++) {
				for (int j = 0; j < req_am; j++) {
					int d = check(mat[i], req[j], mat_s[i], req_s[j]);
					if (req_s[j] and d) {
						if (req_k[j] > mat_k[i]) x = 0;
					}
				}

			}

			if (x) {
				rounds++;
				for (int i = 0; i < mat_am; i++) {
					for (int j = 0; j < req_am; j++) {
						if (req_s[j] and check(mat[i], req[j], mat_s[i], req_s[j])) {
							mat_k[i] -= req_k[j];
						}
					}
				}
			}
			else {
				a.output_mes("This man spend all the resources#", fout_rep);

				fout_rep << "He can win " << rounds - res << endl;
				res = rounds;
				cout << "Materials left:\n";
				fout_rep << "Materials left:\n";
				for (int i = 0; i < mat_am; i++) {
					for (int j = 0; j < mat_s[i]; j++) {
						cout << mat[i][j];
						fout_rep << mat[i][j];

					}
					cout << " " << mat_k[i] << endl;
					fout_rep << " " << mat_k[i] << endl;
				}
				return;
			}
		}
	}

}
