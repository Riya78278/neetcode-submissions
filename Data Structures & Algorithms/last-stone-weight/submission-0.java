class Solution {
    private PriorityQueue<Integer> getHeavyStonesInOrder(int [] stones) {
        PriorityQueue<Integer>stoneOrder = new PriorityQueue<Integer>(Collections.reverseOrder());
        for(int curr : stones) {
            stoneOrder.offer(curr);
        }
        return stoneOrder;
    }

    private int getRemainingStoneWeight(PriorityQueue<Integer> stoneOrder) {
        while(stoneOrder.size() >= 2) {
            int firstStone = stoneOrder.poll();
            int secondStone = stoneOrder.poll();

            if(firstStone == secondStone) {
                continue;
            }
            stoneOrder.offer(firstStone - secondStone);
        }
        return stoneOrder.isEmpty() ? 0 : stoneOrder.peek();
    }

    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer>stoneOrder = getHeavyStonesInOrder(stones);
        return getRemainingStoneWeight(stoneOrder);
    }
}
