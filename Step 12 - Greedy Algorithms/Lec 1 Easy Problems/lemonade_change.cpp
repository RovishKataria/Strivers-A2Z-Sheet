// https://www.naukri.com/code360/problems/lemonade-change_8224112
// https://www.geeksforgeeks.org/problems/lemonade-change/1
// https://leetcode.com/problems/lemonade-change/description/
// https://www.youtube.com/watch?v=n_tmibEhO6Q

bool lemonadeChange(vector<int> &bill) {
	int five = 0, ten = 0;
	for (int i=0; i<bill.size(); i++) {
		if (bill[i] == 5) five += 1;
		else if (bill[i] == 10) {
			if (five) {
				ten += 1;
				five -= 1;
			} else return false;
		} else {
			if (five && ten) {
				ten -= 1;
				five -= 1;
			}
			else if (five >= 3) five -= 3;
			else return false;
		}
	}
	return true;
}
