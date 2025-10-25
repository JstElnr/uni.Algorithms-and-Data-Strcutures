#include<bits/stdc++.h>
using namespace std;
struct Date{
    int day,month,year;
};
int main(){
    int n;
    cin>>n;
    cin.ignore();
    vector<Date> dates(n);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        replace(s.begin(),s.end(),'-',' ');
        stringstream ss(s);
        ss>>dates[i].day>>dates[i].month>>dates[i].year;
    }
    sort(dates.begin(),dates.end(),[](const Date &a, const Date &b){
        if(a.year!=b.year) return a.year<b.year;
        if(a.month!=b.month) return a.month<b.month;
        return a.day<b.day;
    });
    for(auto &d:dates){
        printf("%02d-%02d-%04d\n",d.day,d.month,d.year);
    }
    return 0;
}