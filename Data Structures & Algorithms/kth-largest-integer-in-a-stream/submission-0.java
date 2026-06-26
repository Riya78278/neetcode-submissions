class KthLargest {
    private int k; 
    private PriorityQueue<Integer>heap;
    public KthLargest(int k, int[] nums) {
        this.k = k;
        heap = new PriorityQueue<Integer>();
        for(int curr : nums) {
            heap.offer(curr);
            if(heap.size() > k) {
                heap.poll();
            }
        }
    }
    
    public int add(int val) {
        heap.offer(val);
        if(heap.size() > k) {
            heap.poll();
        }
        return heap.peek();
    }
}
