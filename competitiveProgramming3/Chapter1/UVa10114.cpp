/*
	UVa10114 - Lonesome Car Buyer
	How to solve: Simply simulate the process of depreciation

	Observations: Downpayment is a first-month only amount. Subsequent amounts are calculated by total loan amount divided by number of months.
				  When result is zero, use plural
*/


#include <iostream>
using namespace std;

int main (){
	int months, records;
	double downPayment, amount;
	while (cin >> months >> downPayment >> amount >> records && months > 0){

		int now = 0,month;
		double depr,carValue = amount + downPayment,monthlyPay = amount/months;

		pair<int,double> percentage[records+1];

		int resp = -1;

		for(int i=0;i<records;i++){
			cin >> month >> depr;
			percentage[i].first = month;
			percentage[i].second = depr;
		}


		for(int i=0;i<=months;i++){
			carValue -= carValue*percentage[now].second;
			
			if(i>0)
				amount -= monthlyPay;

			if(carValue > amount){
				resp = i;
				break;
			}	

			if(now < records-1 && percentage[now+1].first == i+1)
				now++;
		}


		cout << resp << " month";
		if(resp > 1 || resp == 0)cout << "s";
		cout << endl;

	}
	return 0;
}