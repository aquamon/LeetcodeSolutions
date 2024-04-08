class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int student_count = students.size();
        int circle = 0 , square = 0;

        for(int x:students)
        {
            if(x == 0)
                circle++;
            else
                square++;
        }

        for(int x:sandwiches)
        {
            if(x == 0 )
            {
               if(circle > 0)
               {
                circle--;
                student_count--;
               }
               else
               {
                return student_count;
               }
            }
            else
            {
                if(square > 0)
                {
                    square--;
                    student_count--;
                }
                else
                {
                    return student_count;
                }
            }
        }
        return student_count;
    }
};