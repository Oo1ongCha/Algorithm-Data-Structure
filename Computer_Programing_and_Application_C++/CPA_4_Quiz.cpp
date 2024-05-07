#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std ;

int main() {
	srand(static_cast<unsigned>(time(NULL)));
    const int H = 5 ;
    const int W = 5 ;
    int ncu[2][H] = {{0x4,0x1f,0x15,0x1f,0x4},
        {0x4,0x1f,0x4,0xa,0x11}} ;
    int i ,j;


    int zong_or_da[5][10];
    	for (i = 0; i < 5; i++) {
    		for (j = 0; j < 10; j++) {
    			zong_or_da[i][j] = rand() % 2;
    		}
    	}

    int m, n, x, y, a, b,c, s, t;
    for (m = 0; m < H; m++) {
        for (x = 0; x < H; x++) {
            for (n = 0; n < 1; n++) {
                for (y = 0; y < 2 ; y++) {
                    a = ncu[y][m];

                    for (s = W-1; s >= 0; s--) {
                        for (t = W-1; t >= 0; t--) {
                            if ((a>>s)%2 == 1) {
                            	c = zong_or_da[m][5 - s];
                            	b = ncu[c][x];
                                if ((b>>t)%2 == 1) {
                                    cout << "*";
                                }
                                else
                                    cout << " ";
                            }
                            else
                                cout << " ";
                        }
                        cout << " ";

                    }
                }
            }
            cout << "\n";
        }

    }



    return 0 ;
}
