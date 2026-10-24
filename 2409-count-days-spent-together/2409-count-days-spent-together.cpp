class Solution {
public:
    int dateToDayOfYear(string date) {
        vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0, 2));
        int days = stoi(date.substr(3, 2));
        int totalDays = 0;
        for (int i = 0; i < month - 1; i++) {
            totalDays += daysInMonths[i];
        }
        return totalDays + days;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startA = dateToDayOfYear(arriveAlice);
        int endA = dateToDayOfYear(leaveAlice);
        int startB = dateToDayOfYear(arriveBob);
        int endB = dateToDayOfYear(leaveBob);

        int arrive = max(startA, startB);
        int leave = min(endA, endB);
        if (arrive <= leave) {
            return leave - arrive + 1;
        }
        return 0;
    }
};