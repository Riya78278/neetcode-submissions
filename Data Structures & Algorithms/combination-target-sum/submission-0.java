class Solution {
    public List<List<Integer>> combinationSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        backtracking(ans, nums, 0, new ArrayList<>(), target);
        return ans;
    }

    private void backtracking(List<List<Integer>> ans, int[] nums, int index, List<Integer> curr, int target) {
        // base condition
        if (target == 0) {
            ans.add(new ArrayList<>(curr));
            return;
        }
        if (target < 0 || index >= nums.length) {
            return;
        }

        // Include the current number and move forward with reduced target
        curr.add(nums[index]);
        backtracking(ans, nums, index, curr, target - nums[index]);

        // Exclude the current number and move to the next index
        curr.remove(curr.size() - 1);
        backtracking(ans, nums, index + 1, curr, target);
    }
}