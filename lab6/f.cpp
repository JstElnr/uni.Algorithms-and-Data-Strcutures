#include<bits/stdc++.h>
using namespace std;
double getGPA(const string &grade){
    if(grade=="A+") return 4.0;
    if(grade=="A") return 3.75;
    if(grade=="B+") return 3.5;
    if(grade=="B") return 3.0;
    if(grade=="C+") return 2.5;
    if(grade=="C") return 2.0;
    if(grade=="D+") return 1.5;
    if(grade=="D") return 1.0;
    return 0.0;
}
struct Student{
    string lastname,firstname;
    double gpa;
};
int main(){
    int n;
    cin>>n;
    vector<Student> students(n);
    for(int i=0;i<n;i++){
        string lname,fname;
        int m;
        cin>>lname>>fname>>m;
        double total=0;
        int totalCredits=0;
        for(int j=0;j<m;j++){
            string grade;
            int credits;
            cin>>grade>>credits;
            total+=getGPA(grade)*credits;
            totalCredits+=credits;
        }
        students[i]={lname,fname,total/totalCredits};
    }
    sort(students.begin(),students.end(),[](const Student &a, const Student &b){
        if(fabs(a.gpa-b.gpa)>1e-9) return a.gpa<b.gpa;
        if(a.lastname!=b.lastname) return a.lastname<b.lastname;
        return a.firstname<b.firstname;
    });
    for(auto &s:students){
        cout<<s.lastname<<" "<<s.firstname<<" ";
        cout<<fixed<<setprecision(3)<<s.gpa<<"\n";
    }
    return 0;
}