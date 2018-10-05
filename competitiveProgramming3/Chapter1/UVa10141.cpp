/*
	UVa10141 - Request for Proposal
	How to solve: Sort the RFP and choose the one which meets the biggest number of requirements

	Observations: Use a sort strategy that ensures the initial order when equal numbers of requirements exist.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

struct proposal_type{
	string name;
	int req;
	float price;
};

vector<proposal_type> proposals;

bool compare(proposal_type a, proposal_type b){
	if(a.req != b.req)
		return (a.req > b.req);
	return (a.price < b.price);
}

int main (){
	int n,p,RFP = 0;
	while(cin >> n >> p && n && p){
		string aux;

		if(RFP)cout << endl;

		RFP++;

		cin.ignore();
		for(int i=0;i<n;i++)
			getline(cin,aux);

		proposal_type x;
		for(int i=0;i<p;i++){
			getline(cin, x.name); 
			cin >> x.price >> x.req;
			proposals.push_back(x);

			cin.ignore();

			for(int j=0;j<x.req;j++)
				getline(cin,aux);
			

			//cout << "done\n";
		}

		stable_sort(proposals.begin(),proposals.end(),compare);

		cout << "RFP #" << RFP << endl;
		cout << proposals[0].name << endl;

		proposals.clear();
	}




	return 0;
}