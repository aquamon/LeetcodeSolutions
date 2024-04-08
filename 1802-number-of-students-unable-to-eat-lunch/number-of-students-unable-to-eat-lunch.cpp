class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        queue<int> student;
        stack<int> sandwich;

        for(int i=0;i<students.size();i++)
        {
            student.push(students[i]);
            sandwich.push(sandwiches[sandwiches.size()-1-i]);
        }

        int last_served = 0;

        while(last_served < student.size() and !student.empty())
        {
            if(sandwich.top() == student.front())
            {
                last_served = 0;
                sandwich.pop();
                student.pop();

            }
            else
            {
                last_served++;
                student.push(student.front());
                student.pop();
            }
        }
        return student.size();
    }
};