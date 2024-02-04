class Solution {
    public int minimumTimeToInitialState(String word, int k) {
        int numberOfOperations = 0;
        String currWord = word;
        while (!currWord.isEmpty()) {
            numberOfOperations++;
            if (currWord.length() < k) { // out of characters
                return (int) Math.ceil((word.length() + 0.0) / k);
            }
            currWord = currWord.substring(k);
            if (word.startsWith(currWord)) {
                return numberOfOperations;
            }
        }
        throw new IllegalStateException("finished without returning");
    }
}