class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> maxHeap=new PriorityQueue<>(Collections.reverseOrder());
        for(int i=0;i<stones.length;i++){
            maxHeap.add(stones[i]);
        }
        int n=stones.length;
        while(n > 1){
            int one= maxHeap.peek();
            maxHeap.remove(one);
            int two= maxHeap.peek();
             maxHeap.remove(two);
             n=n-2;
             if(one!=two){
                maxHeap.add(Math.abs(one-two));
                n++;
             }else{
                maxHeap.add(0);
                n++;
             }
         }
        if(n==1){
        return maxHeap.peek();
        }else{
        return 0;
        }
    }
}
