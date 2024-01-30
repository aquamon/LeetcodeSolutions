class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int>answer;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i] == "*" or tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "/" )
            {
                int second_operand = answer.top();
                answer.pop();
                int first_operand = answer.top();
                answer.pop();

                switch(tokens[i][0])
                {
                    case '+' :
                        answer.push(first_operand + second_operand);
                        break;
                     case '-' :
                        answer.push(first_operand - second_operand);
                        break;
                     case '*' :
                        answer.push(first_operand * second_operand);
                        break;
                     case '/' :
                        answer.push(first_operand / second_operand);
                        break;
                }


            }
            else
            {
                answer.push(stoi(tokens[i]));
            }
        }
        return answer.top();
    }
};