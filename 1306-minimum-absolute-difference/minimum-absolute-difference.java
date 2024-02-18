class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        
        List<List<Integer>> ans = new ArrayList();

        Arrays.sort(arr);

        int min_diff = Integer.MAX_VALUE;

        for(int i=1;i<arr.length;i++)
        {
            int curr = Math.abs(arr[i]-arr[i-1]);

            if(curr < min_diff)
            {
                min_diff = curr;
                ans.clear();
                ans.add(Arrays.asList(arr[i-1],arr[i]));
            }
            else if(curr == min_diff)
            {
                ans.add(Arrays.asList(arr[i-1],arr[i]));
            }
            
        }
        
       

        return ans;



    }
}