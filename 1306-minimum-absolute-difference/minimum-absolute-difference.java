class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        
        List<List<Integer>> ans = new ArrayList<>();

        Arrays.sort(arr);

        int min_diff = Integer.MAX_VALUE;
        for(int i=1;i<arr.length;i++)
        {
            int curr = Math.abs(arr[i]-arr[i-1]);

            min_diff = Math.min(min_diff,curr);
        }
        
        for(int i=1;i<arr.length;i++)
        {
            int curr = Math.abs(arr[i]-arr[i-1]);

            if(curr == min_diff)
            {
                List<Integer> curr1 = new ArrayList<>();
                curr1.add(arr[i-1]);
                curr1.add(arr[i]);

                ans.add(curr1);
            }
        }

        return ans;



    }
}