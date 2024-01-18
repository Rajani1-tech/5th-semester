// C Program for Fractional Knapsack Problem 
#include <bits/stdc++.h> 

using namespace std; 

struct Item 
{ 
	int value, weight; 
	Item(int value, int weight) : value(value), weight(weight) 
	{} 
}; 

bool cmp(struct Item a, struct Item b) 
{ 
	double r1 = (double)a.value / a.weight; 
	double r2 = (double)b.value / b.weight; 
	return r1 > r2; 
} 
double fractionalKnapsack(int W, struct Item arr[], int n) 
{ 
	sort(arr, arr + n, cmp); 

	/* For  order of Items with their ratio */
	cout<<"order of items with their ratio\n";
	for (int i = 0; i < n; i++) 
	{ 
		cout << arr[i].value << " " << arr[i].weight << " : " 
			<< ((double)arr[i].value / arr[i].weight) << endl; 
	} 
	

	int curWeight = 0;
	double finalvalue = 0.0;
	for (int i = 0; i < n; i++) 
	{ 
		if (curWeight + arr[i].weight <= W) 
		{ 
			curWeight += arr[i].weight; 
			finalvalue += arr[i].value; 
		} 
		else
		{ 
			int remain = W - curWeight; 
			finalvalue += arr[i].value * ((double) remain / arr[i].weight); 
			break; 
		} 
	} 

	return finalvalue; 
} 

int main() 
{ 
	int W = 50; 
	Item arr[] = {{70, 10}, {120, 20}, {120, 30}}; 

	int n = sizeof(arr) / sizeof(arr[0]); 
	cout<<"	\n Rajani Lamichhane, Roll no:25796\n";
	cout << "Maximum value we can obtain = "
		<< fractionalKnapsack(W, arr, n); 
	return 0; 
}
