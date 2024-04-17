 struct State{
        int x,y;
        State(int a,int b)
        {
            x = a;
            y=b;
        }
    };
class Solution {
public:
   
    bool canMeasureWater(int x, int y, int target) {
        
        if(x == target or y==target or x+y == target)
            return true;
        
        if(x + y < target)
            return false;
        
        unordered_map<string , int> M;

        
        queue<State>Q;
        Q.push(State(0,0));

        while(!Q.empty())
        {
            State curr = Q.front();
            Q.pop();
            int jug1 = curr.x;
            int jug2 = curr.y;

            string map_state = to_string(jug1) + to_string(jug2);
            // if(M.find(map_state) == M.end())
                M.insert({map_state , 1});
            
            if(jug1 == target or jug2 == target or jug1+jug2 == target)
                return true;
            
            int newX,newY;

            newX = jug1 - min(jug1,y-jug2);
            newY = jug2 + min(jug1,y-jug2);
            map_state = to_string(newX) + to_string(newY);
            if(M.find(map_state) == M.end())
                Q.push( State(newX,newY));
            

            newX = jug1 + min(jug2,x-jug1);
            newY = jug2 - min(jug2,x-jug1);
            map_state = to_string(newX) + to_string(newY);
            if(M.find(map_state) == M.end())
                Q.push( State(newX,newY));
                
            
            newX = 0;
            newY = jug2;
            map_state = to_string(newX) + to_string(newY);
            if(M.find(map_state) == M.end())
                Q.push( State(newX,newY));
                
            newX = jug1;
            newY = 0;
            map_state = to_string(newX) + to_string(newY);
            if(M.find(map_state) == M.end())
                 Q.push( State(newX,newY));

            newX = x;
            newY = jug2;
            map_state = to_string(newX) + to_string(newY);
            if(M.find(map_state) == M.end())
                Q.push( State(newX,newY));

            newX = jug1;
            newY = y;
            map_state = to_string(newX) + to_string(newY);
            if(M.find(map_state) == M.end())
                Q.push( State(newX,newY));

            


        }
        return false;
    }
};