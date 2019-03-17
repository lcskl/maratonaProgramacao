/*
  UVa507 - Jill Rides Again
  How to solve it? This is a Max 1d Range Sum. That means: Try to sum the interval as long as it is worth it (greater OR EQUAL than zero)
*/

#include <iostream>
using namespace std;

struct segment{
    int begin,end,niceness;
};

int main (){
    int b;
    cin >> b;
    for(int route = 1;route <= b; route++){
        int r;
        cin >> r;

        int niceness_entries[r+1];
        for(int i = 1;i<r;i++)
            cin >> niceness_entries[i];

        segment current, best;
        best.begin = r;
        best.niceness = -1;
        current.begin = 1;
        current.niceness = 0;
        for(int i=1;i<r;i++){
            if((current.niceness + niceness_entries[i]) >= 0){
                current.niceness += niceness_entries[i];
                current.end = i+1;
            }else if (i < r-1){
                current.begin = i+1;
                current.end = i+2;
                current.niceness = 0;
            }

            if(current.niceness > 0){
                if(current.niceness > best.niceness)
                    best = current;
                else if(current.niceness == best.niceness){
                    if(current.end - current.begin > best.end - best.begin)
                        best = current;
                    else if(current.end - current.begin == best.end - best.begin && current.begin < best.begin)
                        best = current;

                }
            }

        }
        if(current.niceness > 0){
            if(current.niceness > best.niceness)
                best = current;
            else if(current.niceness == best.niceness){
                if((current.end - current.begin) > (best.end - best.begin))
                    best = current;
                else if(current.end - current.begin == best.end - best.begin && current.begin < best.begin)
                    best = current;

            }
        }

        if(best.niceness > 0)
            cout << "The nicest part of route " << route << " is between stops " << best.begin << " and " << best.end;
        else
            cout << "Route " << route << " has no nice parts";
        cout << endl;
    }

    return 0;
}
