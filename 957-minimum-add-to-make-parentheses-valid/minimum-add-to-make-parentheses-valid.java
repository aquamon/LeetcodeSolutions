class Solution {
    public int minAddToMakeValid(String s) {
        
        char [] arr = s.toCharArray();

        Stack<Character> ST = new Stack<>();
        int count = 0;
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i] == '(')
                ST.push(arr[i]);
            else
            {
                if(!ST.empty())
                    ST.pop();
                else
                    count++;
            }
        }

        return count + ST.size();
    }
}